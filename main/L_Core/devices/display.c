#include "display.h"
#include  "configure.h"
#include "../server/server.h"
/*** Setup screen resolution for LVGL ***/
static const uint16_t screenWidth =  SCREEN_WIDTH;// TFT_WIDTH;
static const uint16_t screenHeight = SCREEN_HEIGHT;// TFT_HEIGHT;

static lv_disp_draw_buf_t draw_buf;

static lv_disp_t *disp;
uint8_t* dispaly_snapshot_buffer;

static LGFX lcd; // declare display variable

static TaskHandle_t g_lvgl_task_handle;

bool force_touch = 0;
bool force_touched = 0;
uint16_t force_touchx, force_touchy;

bool display_screenshot = false;
bool display_screenshot_completed = false;


esp_err_t InitLCDAndLVGL()
{
	// Setting display to landscape
	
	lcd.init();
	lcd.initDMA();
#ifdef PORTRAIT
	
#else
	//if (lcd.width() < lcd.height()) lcd.setRotation(lcd.getRotation() ^ 2);
	lcd.setRotation(3);
#endif
	lcd.setColorDepth(16);	
	lcd.setBrightness(128);
	//lcd.fillScreen(TFT_BLACK);
	lv_init();
	
	/* LVGL : Setting up buffer to use for display */
#if defined(LVGL_DOUBLE_BUFFER)
	    EXT_RAM_BSS_ATTR lv_color_t * buf1 = (lv_color_t *)malloc(screenWidth * BUFF_SIZE * sizeof(lv_color_t));
	    EXT_RAM_BSS_ATTR lv_color_t * buf2 = (lv_color_t *)malloc(screenWidth * BUFF_SIZE * sizeof(lv_color_t));

	//lv_color_t * buf1 = (lv_color_t *)heap_caps_malloc(screenWidth * BUFF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
	//lv_color_t * buf2 = (lv_color_t *)heap_caps_malloc(screenWidth * BUFF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);

	lv_disp_draw_buf_init(&draw_buf, buf1, buf2, screenWidth * BUFF_SIZE);    
#else
	// EXT_RAM_BSS_ATTR 
	//lv_color_t * buf1 = (lv_color_t *)lv_mem_alloc(screenWidth * BUFF_SIZE * sizeof(lv_color_t));
	lv_color_t * buf1 = (lv_color_t *)heap_caps_malloc(screenWidth * BUFF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
	lv_disp_draw_buf_init(&draw_buf, buf1, NULL, screenWidth * BUFF_SIZE);
#endif
	/*** LVGL : Setup & Initialize the display device driver ***/
	static lv_disp_drv_t disp_drv;
	lv_disp_drv_init(&disp_drv);
	disp_drv.hor_res = screenWidth;
	disp_drv.ver_res = screenHeight;
	disp_drv.flush_cb = display_flush;
	disp_drv.draw_buf = &draw_buf;
	disp_drv.sw_rotate = 1;
	disp = lv_disp_drv_register(&disp_drv);

	//*** LVGL : Setup & Initialize the input device driver ***
	static lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	indev_drv.read_cb = touchpad_read;
	lv_indev_drv_register(&indev_drv);

	/* Create and start a periodic timer interrupt to call lv_tick_inc */
	const esp_timer_create_args_t lv_periodic_timer_args = {
		.callback = &lv_tick_task,
		.arg = NULL,
		.dispatch_method = ESP_TIMER_TASK,
		.name = "periodic_gui",
		.skip_unhandled_events = true
	};
	esp_timer_handle_t lv_periodic_timer;
	ESP_ERROR_CHECK(esp_timer_create(&lv_periodic_timer_args, &lv_periodic_timer));
	ESP_ERROR_CHECK(esp_timer_start_periodic(lv_periodic_timer, LV_TICK_PERIOD_MS * 1000));

	int err = xTaskCreatePinnedToCore(gui_task, "lv gui", 1024 * 4, NULL, 10, &g_lvgl_task_handle, 0);
	if (!err)
	{
		//ESP_LOGE(TAG, "Create task for LVGL failed");
		if (lv_periodic_timer) esp_timer_delete(lv_periodic_timer);
		return ESP_FAIL;
	}
	
	//allocate the buf for snapshot.
	dispaly_snapshot_buffer = (uint8_t*)heap_caps_malloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);	
	return ESP_OK;
}


// Display callback to flush the buffer to screen
void display_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
	uint32_t w = (area->x2 - area->x1 + 1);
	uint32_t h = (area->y2 - area->y1 + 1);

	/* Without DMA */
	// lcd.startWrite();
	// lcd.setAddrWindow(area->x1, area->y1, w, h);
	// lcd.pushPixels((uint16_t *)&color_p->full, w * h, true);
	// lcd.endWrite();

	/* With DMA */
	// TODO: Yet to do performance test
	
	lcd.startWrite();
	lcd.setAddrWindow(area->x1, area->y1, w, h);
	lcd.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::swap565_t *)&color_p->full);
	lcd.endWrite();
	lv_disp_flush_ready(disp);
	if (display_screenshot)
	{	
		size_t len = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1); /* Number of pixels */
		len *= sizeof(lv_color_t);
		memcpy(dispaly_snapshot_buffer + area->y1 * w * sizeof(lv_color_t), color_p, len);
		
		if (area->y2 + 1 >= SCREEN_HEIGHT) display_screenshot_completed = true;
		else display_screenshot_completed = false;
	}
}

/* Setting up tick task for lvgl */
void lv_tick_task(void *arg)
{
	(void)arg;
	lv_tick_inc(LV_TICK_PERIOD_MS);
}

void gui_task(void *args)
{
	//ESP_LOGI(TAG, "Start to run LVGL");
	while (1) {
		vTaskDelay(pdMS_TO_TICKS(10));

		/* Try to take the semaphore, call lvgl related function on success */
	   // lvglLock lock;
		//if (OpcHeartBeatLabel) lv_label_set_text_fmt(OpcHeartBeatLabel, "#ff00ff %d #", (int)OpcHeartBeat);
		lv_task_handler();
		//lv_timer_handler_run_in_period(5); /* run lv_timer_handler() every 5ms */
	}
}


// Touchpad callback to read the touchpad
void touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
	uint16_t touchX = 0, touchY = 0;
	bool touched = 0;
	if (force_touch) 
	{
		// Manually issue a touch event
		touched = force_touched;
		touchX = force_touchx;
		touchY = force_touchy;
		
	}
	else
	{
		touched = lcd.getTouch(&touchX, &touchY);
	}
	
	
	if (!touched)
	{
		data->state = LV_INDEV_STATE_REL;
	}
	else
	{
		data->state = LV_INDEV_STATE_PR;

		// Set the coordinates
		data->point.x = touchX;
		data->point.y = touchY;
	}
	force_touch = false;
}

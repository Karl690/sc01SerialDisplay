#include "ui.h"
#include "ui-sdcard.h"
#include "../sd-card/sd-card.h"
lv_obj_t* ui_home_screen;

#define BUTTON_WIDTH	99
#define BUTTON_HEIGHT	72

static void ui_home_event_tranform_screen_cb(lv_event_t* e)
{
	SCREEN_TYPE type = (SCREEN_TYPE)(int)e->user_data;
	ui_transform_screen(type);
	if(type == SCREEN_SDCARD) ui_sdcard_load_directory(current_sdcard_path);
}
lv_obj_t* ui_home_create_button(lv_obj_t* parent, const lv_img_dsc_t* img, const lv_img_dsc_t* icon, char* text)
{
	lv_obj_t* btn = lv_obj_create(parent);
	lv_obj_clear_flag(btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_border_width(btn, 0, LV_PART_MAIN);
	lv_obj_set_style_pad_all(btn, 0, LV_PART_MAIN);
	
	lv_obj_t* obj = lv_img_create(btn);
	lv_img_set_src(obj, img);
	lv_obj_set_pos(obj, 0,0);
	if (icon)
	{
		obj = lv_img_create(btn);
		lv_img_set_src(obj, icon);
		lv_obj_align(obj, LV_ALIGN_TOP_RIGHT, -5, 8);	
	}
	obj = lv_label_create(btn);
	lv_label_set_text(obj, text);
	lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_align(obj, LV_ALIGN_BOTTOM_MID, 0, -5);
	lv_obj_set_size(btn, BUTTON_WIDTH, BUTTON_HEIGHT);
	return btn;
}

void ui_home_screen_init(void)
{
	
	LV_IMG_DECLARE(btnhome_01);
	// LV_IMG_DECLARE(btnhome_02);
	// LV_IMG_DECLARE(btnhome_03);
	LV_IMG_DECLARE(btnhome_04);
	LV_IMG_DECLARE(btnhome_05);
	LV_IMG_DECLARE(btnhome_06);
	LV_IMG_DECLARE(btnhome_07);
	// LV_IMG_DECLARE(btnhome_08);
	LV_IMG_DECLARE(settings);
	// LV_IMG_DECLARE(opc);
	//LV_IMG_DECLARE(variables);
	LV_IMG_DECLARE(folder);
	LV_IMG_DECLARE(controllers);
	LV_IMG_DECLARE(bluetooth);
	LV_IMG_DECLARE(pct);
	// LV_IMG_DECLARE(btn_about);
	
	ui_home_screen = lv_obj_create(NULL);
	lv_obj_clear_flag(ui_home_screen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_home_screen, lv_color_hex(UI_BACKGROUND_COLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_home_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	uint16_t x = 20, y = 60, gap_x = 10, gap_y = 30;
	lv_obj_t* obj = ui_home_create_button(ui_home_screen, &btnhome_01, &settings, "Settings");
	lv_obj_add_event_cb(obj, ui_home_event_tranform_screen_cb, LV_EVENT_CLICKED, (void*)SCREEN_SETTINGS);
	lv_obj_set_pos(obj, x, y);
	
	x += BUTTON_WIDTH + gap_x;
	obj = ui_home_create_button(ui_home_screen, &btnhome_04, &pct, "PCT");
	lv_obj_add_event_cb(obj, ui_home_event_tranform_screen_cb, LV_EVENT_CLICKED, (void*)SCREEN_PCT);
	lv_obj_set_pos(obj, x, y);
	
	x = 20;
	y += BUTTON_HEIGHT + gap_y;
	obj = ui_home_create_button(ui_home_screen, &btnhome_05, &controllers, "Controls");
	lv_obj_add_event_cb(obj, ui_home_event_tranform_screen_cb, LV_EVENT_CLICKED, (void*)SCREEN_CONTROLS);
	lv_obj_set_pos(obj, x, y);
	
	x += BUTTON_WIDTH + gap_x;
	obj = ui_home_create_button(ui_home_screen, &btnhome_06, &folder, "SD Card");
	lv_obj_add_event_cb(obj, ui_home_event_tranform_screen_cb, LV_EVENT_CLICKED, (void*)SCREEN_SDCARD);
	lv_obj_set_pos(obj, x, y);

	x += BUTTON_WIDTH + gap_x;
	obj = ui_home_create_button(ui_home_screen, &btnhome_07, &bluetooth, "Bluetooth");
	lv_obj_add_event_cb(obj, ui_home_event_tranform_screen_cb, LV_EVENT_CLICKED, (void*)SCREEN_BLUETOOTH);
	lv_obj_set_pos(obj, x, y);
	
	lv_obj_t* banner = ui_create_label(ui_home_screen, "#ffffff ©2023, PCT Systems. All rights reserved. #", &font_en_16);
	lv_obj_align(banner, LV_ALIGN_BOTTOM_MID, 0, -10);
}
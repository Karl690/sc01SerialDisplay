#include "ui.h"
#include "ui-pct01.h"
#include "main.h"
#include "L_Core/ui/ui-comm.h"
#include "K_Core/serial/serial.h"
#include "L_Core/bluetooth/ble.h"
#include "L_Core/ui/ui-bluetooth.h"
//#include "K_core/communication/communication.h"
#include "RevisionHistory.h"

lv_obj_t* ui_pct01_screen;
lv_obj_t* ui_pct01_btn_prog;
lv_obj_t* ui_pct01_keyboard[KEYBOARD_BACK + 1];
lv_obj_t* ui_pct01_label_lines[10];
bool ui_pct01_is_refresh_line = false;
char ui_pct01_lines[10][50] = { 0 };
char ui_pct01_temp[256] = { 0 };

void ui_pct01_clear_log()
{
	strcpy(ui_pct01_temp, KEYBOARD_CLEAR_STRING);
	uint8_t len = strlen(ui_pct01_temp);
	if (ble_run_mode == BLE_RUN_CLIENT) //client => server
		ble_client_write_data((uint8_t*)ui_pct01_temp, len);
	else {
		//server => client
		if (ble_run_mode == BLE_RUN_SERVER)
		{
			ble_server_send_data((uint8_t*)ui_pct01_temp, len);	
		}
		communication_tx_commandline(MasterCommPort, ui_pct01_temp);
	}
	
}
void ui_pct01_event_button_cb(lv_event_t* e)
{
	uint8_t code = (uint8_t)(int)lv_event_get_user_data(e);
	switch (code)
	{
	case KEYBOARD_BACKSPACE: strcpy(ui_pct01_temp, KEYBOARD_BACKSPACE_STRING); break;
	case KEYBOARD_CLEAR: strcpy(ui_pct01_temp, KEYBOARD_CLEAR_STRING); break;
	case KEYBOARD_POINT:   strcpy(ui_pct01_temp, KEYBOARD_POINT_STRING); break;
	case KEYBOARD_STOP:  strcpy(ui_pct01_temp, KEYBOARD_STOP_STRING); break;
	case KEYBOARD_START: strcpy(ui_pct01_temp, KEYBOARD_START_STRING); break;
	case KEYBOARD_PROG:  strcpy(ui_pct01_temp, KEYBOARD_PROG_STRING); break;
	case KEYBOARD_DIAG:  strcpy(ui_pct01_temp, KEYBOARD_DIAG_STRING); break;
	case KEYBOARD_ENTER: strcpy(ui_pct01_temp, KEYBOARD_ENTER_STRING); break;
	case KEYBOARD_COMM: {
			if (ble_run_mode == BLE_RUN_CLIENT) {
				ui_transform_screen(SCREEN_BLUETOOTH);
				ui_ble_switch_screen(1);
			}
			else {
				ui_transform_screen(SCREEN_COMM);
			}
			return;
		}
	case KEYBOARD_HOME: {
			strcpy(ui_pct01_temp, KEYBOARD_HOME_STRING); ui_transform_screen(SCREEN_HOME); return;
		}
	case KEYBOARD_BACK: strcpy(ui_pct01_temp, KEYBOARD_BACK_STRING); break;
	}
	uint8_t len = strlen(ui_pct01_temp);
	if (ble_run_mode == BLE_RUN_CLIENT) //client => server
		ble_client_write_data((uint8_t*)ui_pct01_temp, len);
	else {
		//server => client
		if (ble_run_mode == BLE_RUN_SERVER)
		{
			ble_server_send_data((uint8_t*)ui_pct01_temp, len);	
		}
		communication_tx_commandline(MasterCommPort, ui_pct01_temp);
	}
}

void ui_pct01_update_lines_timer(lv_timer_t * timer)
{
	if (!ui_pct01_is_refresh_line) return;
	for (int i = 0; i < 10; i++)
		lv_label_set_text(ui_pct01_label_lines[i], ui_pct01_lines[i]);
	ui_pct01_is_refresh_line = false;
}

void ui_pct01_screen_init(void)
{	
	const lv_font_t* font = &lv_font_montserrat_16;
	ui_pct01_screen = ui_create_screen();	
	
	
	
	ui_create_pct_title(ui_pct01_screen);
	
	lv_obj_t* obj;
	
	int button_w = 60;
	int button_large_width = 90;
	int button_h = 50;
	int gap = 5;
	
	int x = 20, y = 60;
	
	
	obj = ui_create_button(ui_pct01_screen, LV_SYMBOL_REFRESH, button_w, button_h, 2, font, ui_pct01_event_button_cb, (void*)KEYBOARD_COMM);
	lv_obj_set_pos(obj, SCREEN_WIDTH - button_w - 5, 2); ui_pct01_keyboard[KEYBOARD_COMM] = obj;
	
	x = 20; 
	obj = ui_create_button(ui_pct01_screen, "PROG", button_large_width, button_h, 2, font, ui_pct01_event_button_cb, (void*)KEYBOARD_PROG);
	ui_change_button_color(obj, UI_BUTTON_DISABLE_BG_COLOR, UI_BUTTON_DISABLE_FG_COLOR);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; ui_pct01_keyboard[KEYBOARD_PROG] = obj;
	obj = ui_create_button(ui_pct01_screen, "DIAG", button_large_width, button_h, 2, font, ui_pct01_event_button_cb, (void*)KEYBOARD_DIAG); ui_pct01_btn_prog = obj;
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct01_keyboard[KEYBOARD_DIAG] = obj;
	x = 20; y += button_h + 5;
	obj = ui_create_button(ui_pct01_screen, "STOP", button_large_width, button_h, 2, font, ui_pct01_event_button_cb, (void*)KEYBOARD_STOP);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; ui_pct01_keyboard[KEYBOARD_STOP] = obj;
	obj = ui_create_button(ui_pct01_screen, "<<", button_large_width, button_h, 2, font, ui_pct01_event_button_cb, (void*)KEYBOARD_BACK);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct01_keyboard[KEYBOARD_BACK] = obj;
	
	x = 20; y += button_h + 5;
	obj = ui_create_button(ui_pct01_screen, "START", button_large_width, button_h, 2, font, ui_pct01_event_button_cb, (void*)KEYBOARD_START);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; ui_pct01_keyboard[KEYBOARD_START] = obj;
	obj = ui_create_button(ui_pct01_screen, "ENTER", button_large_width, button_h, 2, font, ui_pct01_event_button_cb, (void*)KEYBOARD_ENTER);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct01_keyboard[KEYBOARD_ENTER] = obj;
	
	x = 220; y = 60;
	lv_obj_t* panel = lv_obj_create(ui_pct01_screen);
	lv_obj_set_size(panel, SCREEN_WIDTH - x - 2* gap, SCREEN_HEIGHT - button_h - 3 *gap);
	lv_obj_set_pos(panel, x, y);
	lv_obj_clear_flag(panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(panel, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(panel, 1, LV_PART_MAIN);
	lv_obj_set_style_border_width(panel, 0, LV_PART_MAIN);
	
	y = 0;
	x = 0;
	for (int i = 0; i < 10; i++)
	{
		obj = ui_create_label(panel, "012345678900123456789", &mono_regualr_20); lv_obj_set_pos(obj, x, y); 
		y += 23;	
		ui_pct01_label_lines[i] = obj;
	}
	lv_timer_create(ui_pct01_update_lines_timer, 500, NULL);
}
void ui_pct01_update_label_text(int index, char* value)
{

	if (index >= 10) return;
	if (!ui_pct01_label_lines[index]) return;
	
	int len = strlen(value);
	if (len > 40 && value[40] != '\n') // we need to consider the case Line 5, it should be less than 40 byte
	{
		//double line send, so split and update consecutive lines
		//secondLine = line.Substring(40); //now second line has text
		//line = line.Substring(0, 40);
		if (index + 1 < 10)
		{
			strncpy(ui_pct01_lines[index + 1], value + 40, 40);
			// lv_label_set_text(ui_pct01_label_lines[index+1], value + 40); //lineLabels[index + 1].Text = secondLine;
			value[40] = '\0'; //end the first line	
		}
	}
	strcpy(ui_pct01_lines[index], value); //lvana: we do not update ui directly because it is called in task manager 's loop
	//lv_label_set_text(ui_pct01_label_lines[index], value); //lineLabels[index + 1].Text = secondLine;
	ui_pct01_is_refresh_line = true;
}
void ui_pct01_update_label_color(int index, char* value)
{
	if (index >= 15) return;
	if (!ui_pct01_label_lines[index]) return;
	uint32_t color = atoi(value);
	lv_obj_set_style_text_color(ui_pct01_label_lines[index], lv_color_hex(color), LV_PART_MAIN);
}
void ui_pct01_update_button_text(int index, char* value)
{
	if (index >= KEYBOARD_HOME) return;
	if (!ui_pct01_keyboard[index]) return;
	lv_obj_t* label = lv_obj_get_child(ui_pct01_keyboard[index], 0);
	if (!label) return;
	lv_label_set_text(label, value);
}
void ui_pct01_update_button_color(int index, char* value)
{
	if (index >= KEYBOARD_HOME) return;
	if (!ui_pct01_keyboard[index]) return;
	uint32_t color = atoi(value);
	ui_change_button_color(ui_pct01_keyboard[index], color, UI_BUTTON_NORMAL_FG_COLOR);
}
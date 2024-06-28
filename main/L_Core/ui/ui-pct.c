#include "ui.h"
#include "ui-pct.h"
#include "main.h"
#include "L_Core/ui/ui-comm.h"
#include "K_Core/serial/serial.h"
#include "L_Core/bluetooth/ble.h"
#include "L_Core/ui/ui-bluetooth.h"
//#include "K_core/communication/communication.h"
#include "RevisionHistory.h"

lv_obj_t* ui_pct_screen;
lv_obj_t* ui_pct_line_0;
lv_obj_t* ui_pct_line_1;
lv_obj_t* ui_pct_line_2;
lv_obj_t* ui_pct_line_3;
lv_obj_t* ui_pct_line_4;
lv_obj_t* ui_pct_btn_prog;
lv_obj_t* ui_pct_keyboard[KEYBOARD_BACK+1];
lv_obj_t* ui_pct_label_lines[5];
bool ui_pct_is_refresh_line = false;
char ui_pct_lines[5][50] = { 0 };
char ui_pct_temp[256] = { 0 };

void ui_pct_clear_log()
{
	strcpy(ui_pct_temp, KEYBOARD_CLEAR_STRING);
	uint8_t len = strlen(ui_pct_temp);
	if (ble_run_mode == BLE_RUN_CLIENT) //client => server
		ble_client_write_data((uint8_t*)ui_pct_temp, len);
	else {
		//server => client
		if (ble_run_mode == BLE_RUN_SERVER)
		{
			ble_server_send_data((uint8_t*)ui_pct_temp, len);	
		}
		communication_tx_commandline(MasterCommPort, ui_pct_temp);
	}
	
}
void ui_pct_event_button_cb(lv_event_t* e)
{
	uint8_t code = (uint8_t)(int)lv_event_get_user_data(e);
	switch (code)
	{
	case KEYBOARD_0: strcpy(ui_pct_temp,KEYBOARD_0_STRING);		break;
	case KEYBOARD_1: strcpy(ui_pct_temp, KEYBOARD_1_STRING); break;
	case KEYBOARD_2: strcpy(ui_pct_temp, KEYBOARD_2_STRING); break;
	case KEYBOARD_3: strcpy(ui_pct_temp, KEYBOARD_3_STRING); break;
	case KEYBOARD_4: strcpy(ui_pct_temp, KEYBOARD_4_STRING); break;
	case KEYBOARD_5: strcpy(ui_pct_temp, KEYBOARD_5_STRING); break;
	case KEYBOARD_6: strcpy(ui_pct_temp, KEYBOARD_6_STRING); break;
	case KEYBOARD_7: strcpy(ui_pct_temp, KEYBOARD_7_STRING); break;
	case KEYBOARD_8: strcpy(ui_pct_temp, KEYBOARD_8_STRING); break;
	case KEYBOARD_9: strcpy(ui_pct_temp, KEYBOARD_9_STRING); break;
		
	case KEYBOARD_BACKSPACE: strcpy(ui_pct_temp, KEYBOARD_BACKSPACE_STRING); break;
	case KEYBOARD_CLEAR: strcpy(ui_pct_temp, KEYBOARD_CLEAR_STRING); break;
	case KEYBOARD_POINT:   strcpy(ui_pct_temp, KEYBOARD_POINT_STRING); break;
	case KEYBOARD_STOP:  strcpy(ui_pct_temp, KEYBOARD_STOP_STRING); break;
	case KEYBOARD_START: strcpy(ui_pct_temp, KEYBOARD_START_STRING); break;
	case KEYBOARD_PROG:  strcpy(ui_pct_temp, KEYBOARD_PROG_STRING); break;
	case KEYBOARD_DIAG:  strcpy(ui_pct_temp, KEYBOARD_DIAG_STRING); break;
	case KEYBOARD_ENTER: strcpy(ui_pct_temp, KEYBOARD_ENTER_STRING); break;
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
			strcpy(ui_pct_temp, KEYBOARD_HOME_STRING); ui_transform_screen(SCREEN_HOME); return;
		}
	case KEYBOARD_BACK: strcpy(ui_pct_temp, KEYBOARD_BACK_STRING); break;
	}
	uint8_t len = strlen(ui_pct_temp);
	if (ble_run_mode == BLE_RUN_CLIENT) //client => server
		ble_client_write_data((uint8_t*)ui_pct_temp, len);
	else {
		//server => client
		if (ble_run_mode == BLE_RUN_SERVER)
		{
			ble_server_send_data((uint8_t*)ui_pct_temp, len);	
		}
		communication_tx_commandline(MasterCommPort, ui_pct_temp);
	}
}

void ui_pct_update_lines_timer(lv_timer_t * timer)
{
	if (!ui_pct_is_refresh_line) return;
	for (int i = 0; i < 5; i++)
		lv_label_set_text(ui_pct_label_lines[i], ui_pct_lines[i]);
	ui_pct_is_refresh_line = false;
}

void label_event_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);
	if (code == LV_EVENT_CLICKED) 
		ui_transform_screen(SCREEN_HOME);
}

void ui_pct_screen_init(void)
{	
	const lv_font_t* font = &lv_font_montserrat_16;
	ui_pct_screen = ui_create_screen();	
	
	
	
	ui_create_pct_title(ui_pct_screen, true);
	
	lv_obj_t* obj = ui_create_label(ui_pct_screen, "0", &lv_font_montserrat_20);	
	lv_obj_set_pos(obj, 230, 115);
	ui_pct_line_4 = obj;
	//obj = ui_create_label(ui_pct_screen, SYSTEMVERSION, &mono_regualr_16);	
	//lv_obj_set_pos(obj, 100, 40);
	
	
	int button_w = 60;
	int button_large_width = 90;
	int button_h = 50;
	int gap = 5;
	
	int x = 20, y = 2;
	x = 20; 
	obj = lv_btn_create(ui_pct_screen);
	lv_obj_set_size(obj, SCREEN_WIDTH, 100);
	lv_obj_set_pos(obj, x, y);
	lv_obj_set_style_bg_color(obj, lv_color_hex(0x0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_event_cb(obj, ui_event_title_button_cb, LV_EVENT_CLICKED, (void*)UI_BTN_SWAP); 
	
	obj = ui_create_label(ui_pct_screen, "0123456789012345678901234567890123456789012345", &mono_regualr_20); lv_obj_set_pos(obj, x, y); 
	ui_pct_line_0 = obj;
	
	x = 20; y += 25;
	obj = ui_create_label(ui_pct_screen, "0123456789012345678901234567890123456789012345", &mono_regualr_20); lv_obj_set_pos(obj, x, y);
	ui_pct_line_1 = obj;
	x = 20; y += 25;
	obj = ui_create_label(ui_pct_screen, "0123456789012345678901234567890123456789012345", &mono_regualr_20); lv_obj_set_pos(obj, x, y);
	ui_pct_line_2 = obj;
	x = 20; y += 25;
	obj = ui_create_label(ui_pct_screen, "0123456789012345678901234567890123456789012345", &mono_regualr_20); lv_obj_set_pos(obj, x, y);
	ui_pct_line_3 = obj;
	y += 25 + button_h;
	
	obj = ui_create_button(ui_pct_screen, "PROG", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_PROG);
	ui_change_button_color(obj, UI_BUTTON_DISABLE_BG_COLOR, UI_BUTTON_DISABLE_FG_COLOR);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; ui_pct_keyboard[KEYBOARD_PROG] = obj;
	obj = ui_create_button(ui_pct_screen, "DIAG", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_DIAG); ui_pct_btn_prog = obj;
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct_keyboard[KEYBOARD_DIAG] = obj;
	obj = ui_create_button(ui_pct_screen, "1", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_1);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_1] = obj;
	obj = ui_create_button(ui_pct_screen, "2", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_2);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_2] = obj;
	obj = ui_create_button(ui_pct_screen, "3", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_3);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_3] = obj;
	obj = ui_create_button(ui_pct_screen, LV_SYMBOL_BACKSPACE, button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_BACKSPACE);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_BACKSPACE] = obj;
	
	x = 20; y += button_h + 5;
	obj = ui_create_button(ui_pct_screen, "STOP", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_STOP);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; ui_pct_keyboard[KEYBOARD_STOP] = obj;
	obj = ui_create_button(ui_pct_screen, "<<", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_BACK);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct_keyboard[KEYBOARD_BACK] = obj;
	obj = ui_create_button(ui_pct_screen, "4", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_4);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_4] = obj;
	obj = ui_create_button(ui_pct_screen, "5", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_5);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_5] = obj;
	obj = ui_create_button(ui_pct_screen, "6", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_6);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_6] = obj;
	obj = ui_create_button(ui_pct_screen, ".", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_POINT);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_POINT] = obj;
	
	x = 20; y += button_h + 5;
	obj = ui_create_button(ui_pct_screen, "START", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_START);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; ui_pct_keyboard[KEYBOARD_START] = obj;
	obj = ui_create_button(ui_pct_screen, "ENTER", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_ENTER);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct_keyboard[KEYBOARD_ENTER] = obj;
	obj = ui_create_button(ui_pct_screen, "7", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_7);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_7] = obj;
	obj = ui_create_button(ui_pct_screen, "8", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_8);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_8] = obj;
	obj = ui_create_button(ui_pct_screen, "9", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_9);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_9] = obj;
	obj = ui_create_button(ui_pct_screen, "0", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_0);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_0] = obj;
	
		
	
	ui_pct_label_lines[0] = ui_pct_line_0;
	ui_pct_label_lines[1] = ui_pct_line_1;
	ui_pct_label_lines[2] = ui_pct_line_2;
	ui_pct_label_lines[3] = ui_pct_line_3;
	ui_pct_label_lines[4] = ui_pct_line_4;
	lv_timer_create(ui_pct_update_lines_timer, 500, NULL);
}

void ui_pct_update_label_text(int index, char* value)
{
	//value = trim(value); //lvana: that is wrong , becasuse line sometimes includes space for example, "PWR1=     PWR2=     PWR2=     PWR4=     ",
	if (index >= 5) return;
	if (!ui_pct_label_lines[index]) return;
	int len = strlen(value);
	memset(ui_temp_string, 0, 256);
	char* temp = ui_temp_string;
	for (int i = 0; i < len; i++)
	{
		if (value[i] == '\r')
		{
			strcpy(ui_pct_lines[index], ui_temp_string);
			memset(ui_temp_string, 0, 256);
			temp = ui_temp_string;
			if (index >= 5) break;
			index++;
			continue;
		}
		*temp = value[i];
		temp++;
	}
	strcpy(ui_pct_lines[index], ui_temp_string);
	ui_pct_is_refresh_line = true;
}
void ui_pct_update_label_color(int index, char* value)
{
	if (index >= 5) return;
	if (!ui_pct_label_lines[index]) return;
	uint32_t color = atoi(value);
	lv_obj_set_style_text_color(ui_pct_label_lines[index], lv_color_hex(color), LV_PART_MAIN);
}
void ui_pct_update_button_text(int index, char* value)
{
	if (index >= KEYBOARD_HOME) return;
	if(!ui_pct_keyboard[index]) return;
	lv_obj_t* label = lv_obj_get_child(ui_pct_keyboard[index], 0);
	if (!label) return;
	lv_label_set_text(label, value);
}
void ui_pct_update_button_color(int index, char* value)
{
	if (index >= KEYBOARD_HOME) return;
	if (!ui_pct_keyboard[index]) return;
	uint32_t color = atoi(value);
	ui_change_button_color(ui_pct_keyboard[index], color, UI_BUTTON_NORMAL_FG_COLOR);
}
#include "ui.h"
#include "ui-pct.h"
#include "main.h"
#include "L_Core/ui/ui-comm.h"
#include "K_Core/serial/serial.h"
#include "K_core/communication/communication.h"
#include "RevisionHistory.h"

lv_obj_t* ui_pct_screen;
lv_obj_t* ui_pct_line_0;
lv_obj_t* ui_pct_line_1;
lv_obj_t* ui_pct_line_2;
lv_obj_t* ui_pct_line_3;
lv_obj_t* ui_pct_line_4;
lv_obj_t* ui_pct_btn_prog;
char ui_pct_temp[256] = { 0 };
void ui_pct_event_button_cb(lv_event_t* e)
{
	uint8_t code = (uint8_t)(int)lv_event_get_user_data(e);
	switch (code)
	{
	case UI_PCT_KEYBOARD_0: strcpy(ui_pct_temp,KEYBOARD_0_STRING);		break;

	case UI_PCT_KEYBOARD_1: strcpy(ui_pct_temp, KEYBOARD_1_STRING); break;
	case UI_PCT_KEYBOARD_2: strcpy(ui_pct_temp, KEYBOARD_2_STRING); break;
	case UI_PCT_KEYBOARD_3: strcpy(ui_pct_temp, KEYBOARD_3_STRING); break;
	case UI_PCT_KEYBOARD_4: strcpy(ui_pct_temp, KEYBOARD_4_STRING); break;
	case UI_PCT_KEYBOARD_5: strcpy(ui_pct_temp, KEYBOARD_5_STRING); break;
	case UI_PCT_KEYBOARD_6: strcpy(ui_pct_temp, KEYBOARD_6_STRING); break;
	case UI_PCT_KEYBOARD_7: strcpy(ui_pct_temp, KEYBOARD_7_STRING); break;
	case UI_PCT_KEYBOARD_8: strcpy(ui_pct_temp, KEYBOARD_8_STRING); break;
	case UI_PCT_KEYBOARD_9: strcpy(ui_pct_temp, KEYBOARD_9_STRING); break;

		
	case UI_PCT_KEYBOARD_BACKSPACE: strcpy(ui_pct_temp, KEYBOARD_BACKSPACE_STRING); break;
	case UI_PCT_KEYBOARD_CLEAR: strcpy(ui_pct_temp, KEYBOARD_CLEAR_STRING); break;
	case UI_PCT_KEYBOARD_POINT:   strcpy(ui_pct_temp, KEYBOARD_POINT_STRING); break;
	case UI_PCT_KEYBOARD_STOP:  strcpy(ui_pct_temp, KEYBOARD_STOP_STRING); break;
	case UI_PCT_KEYBOARD_START: strcpy(ui_pct_temp, KEYBOARD_START_STRING); break;
	case UI_PCT_KEYBOARD_PROG:  strcpy(ui_pct_temp, KEYBOARD_PROG_STRING); break;
	case UI_PCT_KEYBOARD_DIAG:  strcpy(ui_pct_temp, KEYBOARD_DIAG_STRING); break;
	case UI_PCT_KEYBOARD_ENTER: strcpy(ui_pct_temp, KEYBOARD_ENTER_STRING); break;
	case UI_PCT_KEYBOARD_COMM:	ui_transform_screen(SCREEN_COMM);		return;
	case UI_PCT_KEYBOARD_HOME:	ui_transform_screen(SCREEN_HOME);		return;
	}
	ui_comm_add_log(ui_pct_temp, UI_COMM_COLOR_SEND);
	communication_add_string_to_serial_buffer(&ComUart1.TxBuffer, ui_pct_temp);
}



void ui_pct_screen_init(void)
{	
	const lv_font_t* font = &lv_font_montserrat_20;
	ui_pct_screen = ui_create_screen();	
	
	LV_IMG_DECLARE(img_mark);
	
	lv_obj_t* logbutton = lv_btn_create(ui_pct_screen);
	lv_obj_add_flag(logbutton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_set_size(logbutton, 65, 45);
	lv_obj_set_style_bg_color(logbutton, lv_color_hex(0x0), LV_PART_MAIN | LV_STATE_DEFAULT);
	
	lv_obj_t * obj = lv_img_create(logbutton);
	lv_img_set_src(obj, &img_mark);
	lv_img_set_zoom(obj, 100);
	lv_obj_set_pos(obj, -65, -45);
	lv_obj_add_event_cb(logbutton, ui_pct_event_button_cb, LV_EVENT_CLICKED, (void*)UI_PCT_KEYBOARD_HOME);	
	
	lv_obj_set_pos(logbutton, 20, 5);
	
	
	obj = ui_create_label(ui_pct_screen, "HYPERCLEAN MEGASONIC", &mono_bold_24);	
	lv_obj_set_pos(obj, 120, 15);
	ui_pct_line_4 = obj;
	//obj = ui_create_label(ui_pct_screen, SYSTEMVERSION, &mono_regualr_16);	
	//lv_obj_set_pos(obj, 100, 40);
	
	
	int button_w = 60;
	int button_large_width = 90;
	int button_h = 50;
	int gap = 5;
	
	int x = 20, y = 60;
	
	obj = ui_create_button(ui_pct_screen, "CLEAR", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_CLEAR);
	lv_obj_set_pos(obj, SCREEN_WIDTH - button_large_width - 5, 2);
	
	obj = ui_create_button(ui_pct_screen, LV_SYMBOL_REFRESH, button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_COMM);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "PROG", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_PROG); ui_pct_btn_prog = obj;
	ui_change_button_color(obj, UI_BUTTON_DISABLE_BG_COLOR, UI_BUTTON_DISABLE_FG_COLOR);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "1", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_1);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "2", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_2);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "3", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_3);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, LV_SYMBOL_BACKSPACE, button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_BACKSPACE);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	
	x = 20; y += button_h + 5;
	obj = ui_create_button(ui_pct_screen, "STOP", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_STOP);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "Diag", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_DIAG);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "4", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_4);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "5", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_5);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "6", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_6);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, ".", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_POINT);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	
	x = 20; y += button_h + 5;
	obj = ui_create_button(ui_pct_screen, "START", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_START);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "Enter", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_ENTER);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "7", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_7);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "8", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_8);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "9", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_9);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	obj = ui_create_button(ui_pct_screen, "0", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)UI_PCT_KEYBOARD_0);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; //ui_pct_keyboard[UI_PCT_KEYBOARD_0] = obj;
	
	x = 20; y += 55;
	obj = ui_create_label(ui_pct_screen, "01234567890012345678900123456789001234567890", &mono_regualr_20); lv_obj_set_pos(obj, x, y); 
	ui_pct_line_0 = obj;
	x = 20; y += 25;
	obj = ui_create_label(ui_pct_screen, "01234567890012345678900123456789001234567890", &mono_regualr_20); lv_obj_set_pos(obj, x, y);
	ui_pct_line_1 = obj;
	x = 20; y += 25;
	obj = ui_create_label(ui_pct_screen, "01234567890012345678900123456789001234567890", &mono_regualr_20); lv_obj_set_pos(obj, x, y);
	ui_pct_line_2 = obj;
	x = 20; y += 25;
	obj = ui_create_label(ui_pct_screen, "01234567890012345678900123456789001234567890", &mono_regualr_20); lv_obj_set_pos(obj, x, y);
	ui_pct_line_3 = obj;	
}

void ui_pct_update_line(int index, const char* lineString)
{
	switch (index)
	{
	case 0: lv_label_set_text(ui_pct_line_0, lineString); break;
	case 1: lv_label_set_text(ui_pct_line_1, lineString); break;
	case 2: lv_label_set_text(ui_pct_line_2, lineString); break;
	case 3: lv_label_set_text(ui_pct_line_3, lineString); break;
	case 4: lv_label_set_text(ui_pct_line_4, lineString); break;
	default:
		break;
	}
}
void ui_pct_update_prog_mode(int value)
{
	if (value == 0) ui_change_button_color(ui_pct_btn_prog, UI_BUTTON_DISABLE_BG_COLOR, UI_BUTTON_DISABLE_FG_COLOR);	
	else ui_change_button_color(ui_pct_btn_prog, UI_BUTTON_ACTIVE_BG_COLOR, UI_BUTTON_ACTIVE_FG_COLOR);	
}
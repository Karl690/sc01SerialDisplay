#include "ui.h"
#include "ui-pct.h"
#include "main.h"
#include "L_Core/ui/ui-comm.h"
#include "K_Core/serial/serial.h"
//#include "K_core/communication/communication.h"
#include "RevisionHistory.h"

lv_obj_t* ui_pct_screen;
lv_obj_t* ui_pct_line_0;
lv_obj_t* ui_pct_line_1;
lv_obj_t* ui_pct_line_2;
lv_obj_t* ui_pct_line_3;
lv_obj_t* ui_pct_line_4;
lv_obj_t* ui_pct_btn_prog;
lv_obj_t* ui_pct_keyboard[KEYBOARD_HOME+1];
lv_obj_t* ui_pct_label_lines[5];
bool ui_pct_is_refresh_line = false;
char ui_pct_lines[5][50] = { 0 };
char ui_pct_temp[256] = { 0 };
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
	case KEYBOARD_COMM:	ui_transform_screen(SCREEN_COMM);		return;
	case KEYBOARD_HOME:	ui_transform_screen(SCREEN_HOME);		return;
	}
	communication_tx_commandline(MasterCommPort, ui_pct_temp);
}

void ui_pct_update_lines_timer(lv_timer_t * timer)
{
	if (!ui_pct_is_refresh_line) return;
	for (int i = 0; i < 5; i++)
		lv_label_set_text(ui_pct_label_lines[i], ui_pct_lines[i]);
	ui_pct_is_refresh_line = false;
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
	lv_obj_add_event_cb(logbutton, ui_pct_event_button_cb, LV_EVENT_CLICKED, (void*)KEYBOARD_HOME);	
	
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
	
	obj = ui_create_button(ui_pct_screen, "CLEAR", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_CLEAR);
	lv_obj_set_pos(obj, SCREEN_WIDTH - button_large_width - 5, 2); ui_pct_keyboard[KEYBOARD_CLEAR] = obj;
	 
	obj = ui_create_button(ui_pct_screen, LV_SYMBOL_REFRESH, button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_COMM);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap; ui_pct_keyboard[KEYBOARD_COMM] = obj;
	obj = ui_create_button(ui_pct_screen, "PROG", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_PROG); ui_pct_btn_prog = obj;
	ui_change_button_color(obj, UI_BUTTON_DISABLE_BG_COLOR, UI_BUTTON_DISABLE_FG_COLOR);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct_keyboard[KEYBOARD_PROG] = obj;
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
	obj = ui_create_button(ui_pct_screen, "Diag", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_DIAG);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct_keyboard[KEYBOARD_DIAG] = obj;
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
	obj = ui_create_button(ui_pct_screen, "Enter", button_large_width, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_ENTER);
	lv_obj_set_pos(obj, x, y); x += button_large_width + gap * 3; ui_pct_keyboard[KEYBOARD_ENTER] = obj;
	obj = ui_create_button(ui_pct_screen, "7", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_7);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_7] = obj;
	obj = ui_create_button(ui_pct_screen, "8", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_8);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_8] = obj;
	obj = ui_create_button(ui_pct_screen, "9", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_9);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_9] = obj;
	obj = ui_create_button(ui_pct_screen, "0", button_w, button_h, 2, font, ui_pct_event_button_cb, (void*)KEYBOARD_0);
	lv_obj_set_pos(obj, x, y); x += button_w + gap; ui_pct_keyboard[KEYBOARD_0] = obj;
	
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
	
	ui_pct_label_lines[0] = ui_pct_line_0;
	ui_pct_label_lines[1] = ui_pct_line_1;
	ui_pct_label_lines[2] = ui_pct_line_2;
	ui_pct_label_lines[3] = ui_pct_line_3;
	ui_pct_label_lines[4] = ui_pct_line_4;
	lv_timer_create(ui_pct_update_lines_timer, 500, NULL);
}

char *trim(char *s) {
	char *ptr;
	if (!s)
		return NULL;   // handle NULL string
	if (!*s)
		return s;      // handle empty string
	for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr) ;
	ptr[1] = '\0';
	return s;
}
void UpdateLabelText(int index, char* value)
{
	//value = trim(value); //lvana: that is wrong , becasuse line sometimes includes space for example, "PWR1=     PWR2=     PWR2=     PWR4=     ",
	if (index >= 5) return;
	if (!ui_pct_label_lines[index]) return;
	int len = strlen(value);
	if (len > 40 && value[40] != '\n') // we need to consider the case Line 5, it should be less than 40 byte
	{
		//double line send, so split and update consecutive lines
		//secondLine = line.Substring(40); //now second line has text
		//line = line.Substring(0, 40);
		strncpy(ui_pct_lines[index+1], value + 40, 40);
		// lv_label_set_text(ui_pct_label_lines[index+1], value + 40); //lineLabels[index + 1].Text = secondLine;
		value[40] = '\0'; //end the first line
	}
	strcpy(ui_pct_lines[index], value); //lvana: we do not update ui directly because it is called in task manager 's loop
	//lv_label_set_text(ui_pct_label_lines[index], value); //lineLabels[index + 1].Text = secondLine;
	ui_pct_is_refresh_line = true;
}
void UpdateLabelColor(int index, char* value)
{
	if (index >= 5) return;
	if (!ui_pct_label_lines[index]) return;
	uint32_t color = atoi(value);
	lv_obj_set_style_text_color(ui_pct_label_lines[index], lv_color_hex(color), LV_PART_MAIN);
}
void UpdateButtonText(int index, char* value)
{
	if (index >= KEYBOARD_HOME) return;
	if(!ui_pct_keyboard[index]) return;
	lv_obj_t* label = lv_obj_get_child(ui_pct_keyboard[index], 0);
	if (!label) return;
	lv_label_set_text(label, value);
}
void UpdateButtonColor(int index, char* value)
{
	if (index >= KEYBOARD_HOME) return;
	if (!ui_pct_keyboard[index]) return;
	uint32_t color = atoi(value);
	ui_change_button_color(ui_pct_keyboard[index], color, UI_BUTTON_NORMAL_FG_COLOR);
}
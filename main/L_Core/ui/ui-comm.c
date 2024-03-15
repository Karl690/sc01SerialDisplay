#include "ui.h"
#include "ui-comm.h"
#include "main.h"
#include "K_Core/serial/serial.h"
#include "K_Core/communication/communication.h"
#include "RevisionHistory.h"


lv_obj_t* ui_comm_screen;
bool ui_comm_is_xmit = true;
bool ui_comm_is_rcv = true;
bool ui_comm_is_hex = true;
lv_obj_t* ui_comm_btn_xmit;
lv_obj_t* ui_comm_btn_rcv;
lv_obj_t* ui_comm_btn_hex;
lv_obj_t* ui_comm_lbl_xmit_icon;
lv_obj_t* ui_comm_lbl_xmit_count;
lv_obj_t* ui_comm_lbl_rcv_icon;
lv_obj_t* ui_comm_lbl_rcv_count;
lv_obj_t* ui_comm_display_panel;

//char ui_comm_log_buffer[UI_COMM_LOG_MAX_LINE][UI_COMM_LOG_MAX_LINE_CHARS];
uint16_t ui_comm_log_head = 0;
uint16_t ui_comm_log_tail = 0;
void ui_comm_event_button_cb(lv_event_t* e)
{
	uint8_t code = (uint8_t)(int)lv_event_get_user_data(e);
	switch (code)
	{
	case UI_COMM_BTN_CLEAR:
		ui_comm_clear_log();
		break;
	case UI_COMM_BTN_OK:
		ui_transform_screen(SCREEN_PCT);
		break;
	case UI_COMM_BTN_PING:
		communication_add_char_to_serial_buffer(&ComUart1.TxBuffer, 0x7);
		ui_comm_add_event((const char*)"Send Ping 0x7", UI_COMM_COLOR_SEND, false);
		break;
	case UI_COMM_BTN_XMIT:
		ui_comm_is_xmit = !ui_comm_is_xmit;
		ui_change_button_color(ui_comm_btn_xmit, ui_comm_is_xmit ? UI_BUTTON_ACTIVE_BG_COLOR : UI_BUTTON_DISABLE_BG_COLOR, ui_comm_is_xmit ? UI_BUTTON_ACTIVE_FG_COLOR : UI_BUTTON_DISABLE_FG_COLOR);
		//ui_comm_add_event((const char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n", UI_COMM_COLOR_SEND, ui_comm_is_hex);
		break;
	case UI_COMM_BTN_RCV:
		ui_comm_is_rcv = !ui_comm_is_rcv;
		ui_change_button_color(ui_comm_btn_rcv, ui_comm_is_rcv ? UI_BUTTON_ACTIVE_BG_COLOR : UI_BUTTON_DISABLE_BG_COLOR, ui_comm_is_rcv ? UI_BUTTON_ACTIVE_FG_COLOR : UI_BUTTON_DISABLE_FG_COLOR);
		//ui_comm_add_event((const char*)"1234567890\n1234567890\n1234567890\n", UI_COMM_COLOR_RECEIVE, ui_comm_is_hex);
		break;
	case UI_COMM_BTN_HEX:
		ui_comm_is_hex = !ui_comm_is_hex;
		ui_change_button_color(ui_comm_btn_hex, ui_comm_is_hex? UI_BUTTON_ACTIVE_BG_COLOR : UI_BUTTON_DISABLE_BG_COLOR, ui_comm_is_hex ? UI_BUTTON_ACTIVE_FG_COLOR : UI_BUTTON_DISABLE_FG_COLOR);
		break;
	}
}
void ui_comm_screen_init(void)
{	
	const lv_font_t* font = &lv_font_montserrat_16;
	ui_comm_screen = ui_create_screen();	
	
	lv_obj_t * obj;	
	obj = ui_create_label(ui_comm_screen, (char*)"HYPERCLEAN MEGASONIC", &mono_bold_28);	
	lv_obj_set_pos(obj, 100, 2);
	
	int gap = 5;
	int x = 10, y = 40 + gap;
	int btn_width = 80;
	int btn_height = 35;
	obj = ui_create_button(ui_comm_screen, "CLEAR", btn_width, btn_height, 2, font, ui_comm_event_button_cb, (void*)UI_COMM_BTN_CLEAR);
	lv_obj_set_pos(obj, SCREEN_WIDTH - btn_width - 5, 2);
	obj = ui_create_button(ui_comm_screen, LV_SYMBOL_REFRESH, btn_width, btn_height, 2, font, ui_comm_event_button_cb, (void*)UI_COMM_BTN_OK);
	lv_obj_set_pos(obj, x, y);
	y += btn_height + gap;
	obj = ui_create_button(ui_comm_screen, "PING", btn_width, btn_height, 2, font, ui_comm_event_button_cb, (void*)UI_COMM_BTN_PING);
	lv_obj_set_pos(obj, x, y);
	y += btn_height + gap;
	
	obj = ui_create_label(ui_comm_screen, LV_SYMBOL_UP, &lv_font_montserrat_20);
	lv_obj_set_style_text_color(obj, lv_color_hex(UI_BUTTON_DISABLE_FG_COLOR), LV_PART_MAIN);	
	lv_obj_set_pos(obj, x, y);
	ui_comm_lbl_xmit_icon = obj;
	
	obj = ui_create_label(ui_comm_screen, "0", font);
	lv_obj_set_pos(obj, x + 40, y);
	ui_comm_lbl_xmit_count = obj;
	y += 25;
	
	obj = ui_create_button(ui_comm_screen, "XMIT", btn_width, btn_height, 2, font, ui_comm_event_button_cb, (void*)UI_COMM_BTN_XMIT);
	ui_change_button_color(obj, UI_BUTTON_ACTIVE_BG_COLOR, UI_BUTTON_ACTIVE_FG_COLOR);
	lv_obj_set_pos(obj, x, y);
	ui_comm_btn_xmit = obj;
	
	y += btn_height + gap;
	obj = ui_create_button(ui_comm_screen, "RCV", btn_width, btn_height, 2, font, ui_comm_event_button_cb, (void*)UI_COMM_BTN_RCV);
	ui_change_button_color(obj, UI_BUTTON_ACTIVE_BG_COLOR, UI_BUTTON_ACTIVE_FG_COLOR);
	lv_obj_set_pos(obj, x, y);
	ui_comm_btn_rcv = obj;
	
	y += btn_height +gap;
	obj = ui_create_label(ui_comm_screen, LV_SYMBOL_DOWN, &lv_font_montserrat_20);
	lv_obj_set_style_text_color(obj, lv_color_hex(UI_BUTTON_DISABLE_FG_COLOR), LV_PART_MAIN);	
	lv_obj_set_pos(obj, x, y);
	ui_comm_lbl_rcv_icon = obj;
	
	obj = ui_create_label(ui_comm_screen, "0", font);
	lv_obj_set_pos(obj, x + 40, y);
	y += 25;
	
	obj = ui_create_button(ui_comm_screen, "HEX", btn_width, btn_height, 2, font, ui_comm_event_button_cb, (void*)UI_COMM_BTN_HEX);
	ui_change_button_color(obj, UI_BUTTON_ACTIVE_BG_COLOR, UI_BUTTON_ACTIVE_FG_COLOR);
	lv_obj_set_pos(obj, x, y);
	ui_comm_btn_hex = obj;
	
	y += btn_height + gap;
	obj = ui_create_label(ui_comm_screen, "v" MajorStep, &mono_regualr_16);	
	lv_obj_set_pos(obj, x, y);
	
	
	obj = lv_obj_create(ui_comm_screen);
	lv_obj_set_size(obj, SCREEN_WIDTH - btn_width - gap * 3, SCREEN_HEIGHT - 50);
	lv_obj_set_pos(obj, btn_width + gap*3, 40+ gap); 
	lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
	lv_obj_set_style_bg_color(obj, lv_color_hex(UI_PANEL_BACGROUND_COLOR), LV_PART_MAIN);
	ui_comm_display_panel = obj;
	uint8_t width = lv_obj_get_width(obj) - 10;
	
	for (uint8_t i = 0; i < UI_COMM_LOG_MAX_LINE; i++)
	{
		obj = lv_label_create(ui_comm_display_panel);
		lv_label_set_long_mode(obj, LV_LABEL_LONG_WRAP); /*Automatically break long lines*/
		lv_obj_set_style_border_color(obj, lv_color_hex(0x550055), LV_PART_MAIN);
		lv_obj_set_style_text_font(obj, &mono_regualr_20, LV_PART_MAIN);
		lv_obj_set_width(obj, lv_pct(95)); 
		lv_obj_set_x(obj, 5); 
		lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
		//lv_obj_scroll_to_y(ui_comm_display_panel, y, LV_ANIM_OFF);
	}
}

char ui_comm_temp_string1[1024] = { 0 };
char ui_comm_temp_string2[256] = { 0 };

void ui_comm_add_event(const char* log, uint32_t color, bool ishex)
{
	if (!log) return;
	uint16_t index = ui_comm_log_head % UI_COMM_LOG_MAX_LINE;
	memset(ui_comm_temp_string1, 0, 1024);
	memset(ui_comm_temp_string2, 0, 256);
	lv_obj_t* obj = lv_obj_get_child(ui_comm_display_panel, index);
	lv_obj_set_height(obj, LV_SIZE_CONTENT);
	lv_obj_set_style_text_color(obj, lv_color_hex(color), LV_PART_MAIN);
	if (ishex)
	{
		uint16_t numberofcharcterstoadd = 16;
		uint16_t len =  strlen(log);
		if (numberofcharcterstoadd > len) numberofcharcterstoadd = len;
		int count = 0;
		int hexIdx = 0;
		int asciiIdx = 0;
		char* hexString = ui_comm_temp_string1;
		char* asciiString = ui_comm_temp_string2;
		
		while (count < len)
		{
			sprintf(hexString, "%02X ", log[count]); hexString += 3;
			
			if ((log[count] >= ' ') & (log[count] <= 127))
			{
				*asciiString = (char)(log[count]);
			}
			else
			{
				*asciiString = '.';
			}
			asciiString++;
			count++;
			if ((count & 7) == 0)//we just got to 8 characters so display them and go to next line
			{
				*hexString = ' '; hexString++;
				strcpy(hexString, ui_comm_temp_string2);
				hexString += strlen(ui_comm_temp_string2);
				ui_comm_temp_string2[0] = '\0';
				*hexString = '\n';
				hexString++; 
				asciiString = ui_comm_temp_string2;
			}
		}
		int fill = (3 * (8 - (count & 7))); //lets see how many characters we need
		for (count = 0; count < fill - 1; count++)
		{ 
			*hexString = '-';
			hexString++;
		}
		*hexString = ' '; hexString++;
		*hexString = ' '; hexString++;
		strcpy(hexString, ui_comm_temp_string2);
		lv_label_set_text(obj, ui_comm_temp_string1);	
	}
	else
	{
		lv_label_set_text(obj, log);	
	}
	//lv_obj_set_style_bg_color(obj, lv_color_hex(0x550055), LV_PART_MAIN);
	
	ui_comm_log_head++;
	ui_comm_log_tail = ui_comm_log_head < UI_COMM_LOG_MAX_LINE ? 0 : ui_comm_log_head - UI_COMM_LOG_MAX_LINE;
	
	uint16_t gap = 2;
	uint16_t ypos = 5;
	uint16_t idx = 0;
	uint16_t height = 0;
	for (index = ui_comm_log_tail; index < ui_comm_log_head; index++)
	{
		idx = index % UI_COMM_LOG_MAX_LINE;
		obj = lv_obj_get_child(ui_comm_display_panel, idx);
		lv_obj_set_y(obj, ypos);
		lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
		height = lv_obj_get_height(obj);
		ypos += height + gap;
	}
	lv_obj_scroll_to_y(ui_comm_display_panel, ypos, LV_ANIM_OFF);
}

void ui_comm_add_log(const char* log, uint32_t color)
{	
	if ((color == UI_COMM_COLOR_RECEIVE && ui_comm_is_rcv) || //incomming data
		(color == UI_COMM_COLOR_SEND && ui_comm_is_xmit)) 
		ui_comm_add_event(log, color, ui_comm_is_hex);
}

void ui_comm_clear_log()
{
	ui_comm_log_head = 0;
	ui_comm_log_tail = 0;
	lv_obj_t* obj;
	int count = lv_obj_get_child_cnt(ui_comm_display_panel);
	for (uint8_t i = 0; i < count; i++)
	{
		obj = lv_obj_get_child(ui_comm_display_panel, i);
		lv_label_set_text(obj, "");
		lv_obj_set_x(obj, 5); 
		lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
	}
}
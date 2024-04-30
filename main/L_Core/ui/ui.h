#pragma once
#include "lvgl.h"
#include "font/font.h"

#define SCREEN_WIDTH				480
#define SCREEN_HEIGHT				320
#define SCREEN_PIXEL_SIZE			2
#define SCREEN_LINE_PIXCELS			SCREEN_WIDTH * SCREEN_PIXEL_SIZE

#define UI_BACKGROUND_COLOR			0x0

#define MENU_BACKGROUND_COLOR		0xffffff

#define TITLEBAR_BACKGROUND_COLOR	0x0B72AB
#define TITLEBAR_FORE_COLOR			0xFFFFFF
#define TITLEBAR_HEIGHT				30
#define PAGE_BACKGROUND_COLOR		0x222222
#define BUTTON_BACKGROUND_COLOR		0x0B72AB

#define INFO_COLOR					0x477E00
#define WARNING_COLOR				0xEEBA34
#define ERROR_COLOR					0xEE3455

#define UI_PANEL_BACGROUND_COLOR		0x111111
#define UI_BUTTON_NORMAL_BG_COLOR		0x0A1F00
#define UI_BUTTON_NORMAL_FG_COLOR		0xFFFFFF
#define UI_BUTTON_ACTIVE_BG_COLOR		0x406F03
#define UI_BUTTON_ACTIVE_FG_COLOR		0x6DFF13
#define UI_BUTTON_DISABLE_BG_COLOR		0x383838
#define UI_BUTTON_DISABLE_FG_COLOR		0x878787
#define UI_MENU_ACTIVE_ITEM_COLOR	0xF30505
#define UI_MENU_NORMAL_ITEM_COLOR	0x494949
#define UI_TEXTAREA_BORDER_COLOR	0x5DA105

#define UI_CHECK_ACTIVE_COLOR		0xF30505
#define UI_CHECK_NONACTIVE_COLOR	0x494949	

#define SETTINGS_LINE_SPACE 45

typedef enum
{
	MESSAGEBOX_WARNING,
	MESSAGEBOX_INFO,
	MESSAGEBOX_ERROR,
}MESSAGEBOX_TYPE;


typedef enum
{
	UI_BTN_HOME,
	UI_BTN_CLEAR,
	UI_BTN_SWAP,
}UI_BUTTON_TYPE;
typedef enum
{
	SCREEN_HOME,
	SCREEN_SETTINGS,
	SCREEN_CONTROLS,
	SCREEN_QUALITY,
	SCREEN_SDCARD,
	SCREEN_PCT,
	SCREEN_COMM,
	SCREEN_BLUETOOTH,
}SCREEN_TYPE;

extern char ui_temp_string[];
extern uint8_t ui_initialized;
extern lv_obj_t * keyboard;
void InitUI(void);

lv_obj_t* ui_create_screen();
lv_obj_t* ui_create_titlebar(lv_obj_t* screen, uint32_t color);
lv_obj_t* ui_create_label(lv_obj_t* parent, const char* text, const lv_font_t* font);
lv_obj_t* ui_create_button(lv_obj_t* parent,
	const char* text,
	uint16_t w,
	uint16_t h, 
	uint16_t radius,
	const lv_font_t* font,
	lv_event_cb_t event_button_handler,
	void* event_data);
void ui_change_button_color(lv_obj_t* button, uint32_t bg, uint32_t fg);
void ui_transform_screen(SCREEN_TYPE screen);
void ui_show_messagebox(MESSAGEBOX_TYPE type, const char* msg, uint16_t delay);
void ui_event_go_home_cb(lv_event_t* e);
void ui_event_edit_cb(lv_event_t* e);
void ui_create_pct_title(lv_obj_t* parent);

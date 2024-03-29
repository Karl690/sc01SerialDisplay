#pragma once
#include "lvgl.h"


#define UI_PCT_PANEL_BG_COLOR			0x0A1F00
#define UI_PCT_PANEL_BORDER_COLOR		0x194C01
#define UI_PCT_PANEL_FG_COLOR			0x6DFF13
#define UI_PCT_PANEL_DIAG_BORDER_COLOR	0x621801
#define UI_PCT_PANEL_DIAG_BG_COLOR		0x300000
#define UI_PCT_PANEL_DIAG_FG_COLOR		0xFF0000

#define UI_PCT_BTN_BG_NORMAL_COLOR				0x0A1F00
#define UI_PCT_BTN_BG_ACTIVE_COLOR				0x164102
#define UI_PCT_BTN_FG_NORMAL_COLOR				0x6DFF13
#define UI_PCT_BTN_FG_DISALBE_COLOR				0x717171
#define KEYBOARD_0_STRING "G6 B0\n"
#define KEYBOARD_1_STRING "G6 B1\n"
#define KEYBOARD_2_STRING "G6 B2\n"
#define KEYBOARD_3_STRING "G6 B3\n"
#define KEYBOARD_4_STRING "G6 B4\n"
#define KEYBOARD_5_STRING "G6 B5\n"
#define KEYBOARD_6_STRING "G6 B6\n"
#define KEYBOARD_7_STRING "G6 B7\n"
#define KEYBOARD_8_STRING "G6 B8\n"
#define KEYBOARD_9_STRING "G6 B9\n"
#define KEYBOARD_CLEAR_STRING "G6 B10\n"
#define KEYBOARD_BACKSPACE_STRING "G6 B11\n"
#define KEYBOARD_POINT_STRING "G6 B12\n"
#define KEYBOARD_PROG_STRING "G6 B13\n"
#define KEYBOARD_ENTER_STRING "G6 B14\n"
#define KEYBOARD_START_STRING "G6 B15\n"
#define KEYBOARD_STOP_STRING "G6 B16\n"
#define KEYBOARD_DIAG_STRING "G6 B17\n"
#define KEYBOARD_COMM_STRING "G6 B18\n"
#define KEYBOARD_HOME_STRING "G6 B19\n"
#define KEYBOARD_BACK_STRING "G6 B20\n"

enum KEYCODE
{
	KEYBOARD_0 = 0,
	KEYBOARD_1,
	KEYBOARD_2,
	KEYBOARD_3,
	KEYBOARD_4,
	KEYBOARD_5,
	KEYBOARD_6,
	KEYBOARD_7,
	KEYBOARD_8,
	KEYBOARD_9,
	KEYBOARD_CLEAR,
	KEYBOARD_BACKSPACE,
	KEYBOARD_POINT,
	KEYBOARD_PROG,
	KEYBOARD_ENTER,
	KEYBOARD_START,
	KEYBOARD_STOP,
	KEYBOARD_DIAG,
	KEYBOARD_COMM,
	KEYBOARD_HOME,
	KEYBOARD_BACK
};

extern lv_obj_t* ui_pct_screen;

void ui_pct_screen_init(void);

void UpdateLabelText(int index, char* value);
void UpdateLabelColor(int index, char* value);
void UpdateButtonText(int index, char* value);
void UpdateButtonColor(int index, char* value);
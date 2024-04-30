#pragma once
#include "ui.h"
typedef enum
{
	
	CONTROLS_FAN_MINUS,
	CONTROLS_FAN_PLUS,
	CONTROLS_HEAT_MINUS,
	CONTROLS_HEAT_PLUS,
	CONTROLS_MTR_MINUS,
	CONTROLS_MTR_PLUS,
}CONTROLS_SUBMENU_TYPE;

extern lv_obj_t* ui_control_screen;
void ui_control_screen_init();


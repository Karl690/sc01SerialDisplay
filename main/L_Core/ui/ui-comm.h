#pragma once
#include "lvgl.h"

enum
{	
	UI_COMM_BTN_CLEAR,
	UI_COMM_BTN_OK,
	UI_COMM_BTN_SSD,
	UI_COMM_BTN_PING,
	UI_COMM_BTN_XMIT,
	UI_COMM_BTN_RCV,
	UI_COMM_BTN_HEX,
	UI_COMM_BTN_ACK,
};

#define UI_COMM_LOG_MAX_LINE 40
#define UI_COMM_LOG_MAX_LINE_CHARS 80

#define UI_COMM_COLOR_SEND		0xFF0000
#define UI_COMM_COLOR_RECEIVE	0xFFFFFF
extern lv_obj_t* ui_comm_screen;

extern uint8_t ui_comm_tx_indicator;
extern uint8_t ui_comm_rx_indicator;

extern uint32_t ui_comm_tx_chars;
extern uint32_t ui_comm_rx_chars;
extern uint32_t ui_comm_tx_acks;
extern uint32_t ui_comm_rx_acks;

extern bool ui_comm_is_ack;
extern bool ui_comm_is_hex;
void ui_comm_screen_init(void);
void ui_comm_add_event(const char* log, uint32_t color, bool ishex);
void ui_comm_add_log(const char* log, uint32_t color);
void ui_comm_clear_log();
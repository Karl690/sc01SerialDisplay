#include "main.h"
#include "ui.h"
#include "ui-settings.h"
#include "L_Core/sd-card/sd-card.h"
#include "L_Core/bluetooth/ble.h"
#include "K_Core/serial/serial.h"
#include "K_Core/communication/communication.h"
#include "RevisionHistory.h"
lv_obj_t* ui_settings_screen;
lv_obj_t* ui_settings_bluetooth_page;
lv_obj_t* ui_settings_wifi_page;
lv_obj_t* ui_settings_opc_page;
lv_obj_t* ui_settings_sdcard_page;
lv_obj_t* ui_settings_serial_page;
lv_obj_t* ui_settings_system_page;
lv_obj_t* settings_active_menu = NULL;
lv_obj_t* settings_active_page = NULL;

lv_obj_t* ui_settings_serial_performance_value = NULL;
bool ui_settings_initialized = false;


UI_SETTINGS ui_settings;

int get_value_from_index(int index)
{
	int p = index + 10;
	if (p == 15) p = 21;
	return p;
}
int get_index_from_value(int value)
{
	int i = value - 10;
	if (i > 4) i = 5;
	return i;
}
int get_index_from_baud(int baud)
{
	int index = 0;
	switch (baud)
	{
	case 9600: index = 0; break;
	case 14400: index = 1; break;
	case 19200: index = 2; break;
	case 38400: index = 3; break;
	case 57600: index = 4; break;
	case 115200: index = 5; break;
	}
	return index;
}

int get_baud_from_index(int index)
{
	int baud = 115200;
	switch (index)
	{
	case 0: baud = 9600; break;
	case 1: baud = 14400; break;
	case 2: baud = 19200; break;
	case 3: baud = 38400; break;
	case 4: baud = 57600; break;
	case 5: baud = 115200; break;
	}
	return baud;
}

void ui_settings_event_submenu_cb(lv_event_t* e)
{
	if (!ui_settings_initialized) return;
	lv_obj_t * target = lv_event_get_target(e);	
	SETTINGS_SUBMENU_TYPE type = (SETTINGS_SUBMENU_TYPE)(int) e->user_data;
	if (settings_active_menu  == target) return;
	if (settings_active_menu) lv_obj_set_style_bg_color(settings_active_menu, lv_color_hex(UI_BUTTON_NORMAL_BG_COLOR), LV_PART_MAIN);
	lv_obj_set_style_bg_color(target, lv_color_hex(UI_BUTTON_ACTIVE_BG_COLOR), LV_PART_MAIN);
	
	if (settings_active_page) lv_obj_add_flag(settings_active_page, LV_OBJ_FLAG_HIDDEN);
	switch (type)
	{
	case SETTINGS_SUBMENU_BLUETOOTH:
		settings_active_page = ui_settings_bluetooth_page;
		lv_obj_clear_flag(ui_settings_bluetooth_page, LV_OBJ_FLAG_HIDDEN);
		break;
	case SETTINGS_SUBMENU_WIFI:
		settings_active_page = ui_settings_wifi_page;
		lv_obj_clear_flag(ui_settings_wifi_page, LV_OBJ_FLAG_HIDDEN);
		break;
	case SETTINGS_SUBMENU_OPC:
		settings_active_page = ui_settings_opc_page;
		lv_obj_clear_flag(ui_settings_opc_page, LV_OBJ_FLAG_HIDDEN);
		break;
	case SETTINGS_SUBMENU_SERIAL:
		settings_active_page = ui_settings_serial_page;
		lv_obj_clear_flag(ui_settings_serial_page, LV_OBJ_FLAG_HIDDEN);
		break;
	case SETTINGS_SUBMENU_SDCARD:
		settings_active_page = ui_settings_sdcard_page;
		lv_obj_clear_flag(ui_settings_sdcard_page, LV_OBJ_FLAG_HIDDEN);
		break;
	case SETTINGS_SUBMENU_SYSTEM:
		settings_active_page = ui_settings_system_page;
		lv_obj_clear_flag(ui_settings_system_page, LV_OBJ_FLAG_HIDDEN);
		break;
	default:
		break;
	}
	settings_active_menu = target;
}

void ui_settings_serial_load_event_cb(lv_event_t* e)
{
	uint8_t* data = (uint8_t*)lv_event_get_user_data(e);
	if (data == 0)
	{
		lv_dropdown_set_selected(ui_settings.ui_serial.ui_tx_pin, get_index_from_value(GPIO_NUM_12));
		lv_dropdown_set_selected(ui_settings.ui_serial.ui_rx_pin, get_index_from_value(GPIO_NUM_14));
		lv_dropdown_set_selected(ui_settings.ui_serial.ui_baud, get_index_from_baud(115200));
	}
	else
	{
		lv_dropdown_set_selected(ui_settings.ui_serial.ui_tx_pin, get_index_from_value(GPIO_NUM_21));
		lv_dropdown_set_selected(ui_settings.ui_serial.ui_rx_pin, get_index_from_value(GPIO_NUM_14));
		lv_dropdown_set_selected(ui_settings.ui_serial.ui_baud, get_index_from_baud(115200));
	}
	
}

void ui_settings_serial_performance_event_cb(lv_event_t* e)
{
	serial_performance_timer = xTaskGetTickCount();
	for (int i = 0; i < 1000; i++)
	{
		communication_tx_commandline(MasterCommPort, "012345678900123456789001234567890012345678900123456789001234567890\n");
	}
	
}
void ui_settings_event_switch_cb(lv_event_t* e)
{
	lv_obj_t * obj = lv_event_get_target(e);
	uint8_t* data = (uint8_t*)lv_event_get_user_data(e);
	bool state = lv_obj_has_state(obj, LV_STATE_CHECKED);
	
	if (data == &systemconfig.bluetooth.server_enabled)
	{
		if (state) {
			ble_enable();
		}
		else ble_disable();
		
		if (systemconfig.bluetooth.server_enabled) lv_obj_add_state(ui_settings.ui_bluetooth.status, LV_STATE_CHECKED);
		else lv_obj_clear_state(ui_settings.ui_bluetooth.status, LV_STATE_CHECKED);
	}
	else if (data == &systemconfig.opc.status)
	{
		
	}
	else if (data == &systemconfig.sdcard.status)
	{
		if (state)
		{
			if (!systemconfig.sdcard.status) systemconfig.sdcard.status = sdcard_mount();
			if (!systemconfig.sdcard.status) ui_show_messagebox(MESSAGEBOX_ERROR, (const char*)"Falied mount sdcard.", 3000);
		}
		else
		{
			if (systemconfig.sdcard.status) sdcard_umount();
			systemconfig.sdcard.status = false;
		}
		if (systemconfig.sdcard.status)		lv_obj_add_state(obj, LV_STATE_CHECKED);
		else lv_obj_clear_state(obj, LV_STATE_CHECKED);
	}
	else
	{
		*data = state;
	}
}

void ui_settings_event_load_cb(lv_event_t* e)
{
	if (!load_configuration())
	{
		ui_show_messagebox(MESSAGEBOX_ERROR, "Can't load configuration from sd card.", 3000);
	}
	else
	{
		ui_show_messagebox(MESSAGEBOX_INFO, "Successful load configuration", 3000);
		ui_settings_update_configuratiion();
	}
}
void ui_settings_reboot_timer_cb(lv_timer_t * timer)
{
	esp_restart();
}

void ui_settings_event_save_cb(lv_event_t* e)
{
	systemconfig.serial.rx_pin  = get_value_from_index(lv_dropdown_get_selected(ui_settings.ui_serial.ui_rx_pin));
	systemconfig.serial.tx_pin  = get_value_from_index(lv_dropdown_get_selected(ui_settings.ui_serial.ui_tx_pin));
	systemconfig.serial.baud  = get_baud_from_index(lv_dropdown_get_selected(ui_settings.ui_serial.ui_baud));
	
	if (!save_configuration())
	{
		ui_show_messagebox(MESSAGEBOX_ERROR, "Can't save configuration.", 3000);
	}
	else
	{
		ui_show_messagebox(MESSAGEBOX_INFO,
			"Settings Saved Succesfully, Rebooting NOW.", 5000);
		
		//serial_uart_update_config(UART_NUM_1, systemconfig.serial.tx_pin, systemconfig.serial.rx_pin, systemconfig.serial.baud);
		lv_timer_create(ui_settings_reboot_timer_cb, 5000, NULL);
	}
}

char tempString[256] = { 0 };
void ui_settings_update_data_timer_cb(lv_timer_t * timer)
{
	//sprintf(tempString, "0x%02X 0x%02X 0x%02X 0x%02X", serial_uart_last_read_buffer[0], serial_uart_last_read_buffer[1], serial_uart_last_read_buffer[2], serial_uart_last_read_buffer[3]);
	//lv_label_set_text(ui_settings.ui_serial.uart1_latest_received_text, (char*)serial_uart1_last_read_buffer);
	//sprintf(tempString, "0x%02X 0x%02X 0x%02X 0x%02X", serial_rs485_last_read_buffer[0], serial_rs485_last_read_buffer[1], serial_rs485_last_read_buffer[2], serial_rs485_last_read_buffer[3]);
	//lv_label_set_text(ui_settings.ui_serial.uart2_latest_received_text, (char*)serial_uart2_last_read_buffer);
	
}

void ui_settings_serial_performance_update()
{
	if (serial_performance_timer == 0) return;
	uint32_t end = xTaskGetTickCount();
	uint32_t timeout = end - serial_performance_timer;
	sprintf(ui_temp_string, "%d ms", (int)timeout);
	lv_label_set_text(ui_settings_serial_performance_value, ui_temp_string); 
}
void ui_settings_bluetooth_page_init()
{
	ui_settings_bluetooth_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_bluetooth_page, 375, 235);//480-105
	lv_obj_set_pos(ui_settings_bluetooth_page, 102, 45); 
	lv_obj_set_style_pad_all(ui_settings_bluetooth_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_bluetooth_page, "Bluetooth", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t y = 40;
	obj = ui_create_label(ui_settings_bluetooth_page, "Status: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y+10);
	obj = lv_switch_create(ui_settings_bluetooth_page);
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.bluetooth.server_enabled) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.bluetooth.server_enabled);
	ui_settings.ui_bluetooth.status = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_bluetooth_page, "Autostart: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y+10);
	obj = lv_switch_create(ui_settings_bluetooth_page);
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.bluetooth.autostart) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.bluetooth.autostart);
	ui_settings.ui_bluetooth.autostart = obj;

}

void ui_settings_wifi_page_init()
{
	ui_settings_wifi_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_wifi_page, 375, 235); //480-105
	lv_obj_set_pos(ui_settings_wifi_page, 102, 45); 
	lv_obj_set_style_pad_all(ui_settings_wifi_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_wifi_page, "WIFI", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t y = 40;
	obj = ui_create_label(ui_settings_wifi_page, "WIFI SSID: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	
	obj = lv_textarea_create(ui_settings_wifi_page);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_BACKGROUND_COLOR), LV_PART_MAIN);
	lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);
	lv_textarea_set_one_line(obj, true);
	lv_obj_set_width(obj, 150);
	lv_obj_set_pos(obj, 160, y);
	lv_obj_add_event_cb(obj, ui_event_edit_cb, LV_EVENT_ALL, &systemconfig.wifi.ssid);
	lv_textarea_set_text(obj, (const char*)systemconfig.wifi.ssid);
	lv_obj_set_user_data(obj, systemconfig.wifi.ssid);
	ui_settings.ui_wifi.ssid = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_wifi_page, "WIFI PASSWORD: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_textarea_create(ui_settings_wifi_page);	
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_BACKGROUND_COLOR), LV_PART_MAIN);
	lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);
	lv_textarea_set_one_line(obj, true);
	lv_textarea_set_password_mode(obj, true);
	lv_obj_set_width(obj, 150);
	lv_obj_set_pos(obj, 160, y);
	lv_obj_add_event_cb(obj, ui_event_edit_cb, LV_EVENT_ALL, &systemconfig.wifi.password);
	lv_textarea_set_text(obj, (const char*)systemconfig.wifi.password);
	lv_obj_set_user_data(obj, systemconfig.wifi.password);
	ui_settings.ui_wifi.password = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_wifi_page, "Auto connect: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 5);
	obj = lv_switch_create(ui_settings_wifi_page);
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.wifi.autoconnect) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.wifi.autoconnect);
	ui_settings.ui_wifi.autoconnect = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_wifi_page, "Status: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_switch_create(ui_settings_wifi_page);	
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.wifi.autoconnect) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);	
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.wifi.status);
	ui_settings.ui_wifi.status = obj;
	
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_wifi_page, "IP: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 5);
	obj = lv_label_create(ui_settings_wifi_page);
	lv_obj_set_pos(obj, 160, y);
	lv_label_set_text(obj, (const char*)systemconfig.wifi.ip);
	
	ui_settings.ui_wifi.ip= obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_wifi_page, "SUBNET: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 5);
	obj = lv_label_create(ui_settings_wifi_page);
	lv_obj_set_pos(obj, 160, y);
	lv_label_set_text(obj, (const char*)systemconfig.wifi.subnet);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.wifi.autoconnect);
	ui_settings.ui_wifi.subnet= obj;
}

void ui_settings_opc_page_init()
{
	ui_settings_opc_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_opc_page, 375, 235); //480-105
	lv_obj_set_pos(ui_settings_opc_page, 102, 45); 
	lv_obj_set_style_pad_all(ui_settings_opc_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_opc_page, "OPC", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t y = 40;
	obj = ui_create_label(ui_settings_opc_page, "User name: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_textarea_create(ui_settings_opc_page);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_BACKGROUND_COLOR), LV_PART_MAIN);
	lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);
	lv_textarea_set_one_line(obj, true);
	lv_obj_set_width(obj, 150);
	lv_obj_set_pos(obj, 160, y);
	lv_obj_add_event_cb(obj, ui_event_edit_cb, LV_EVENT_ALL, &systemconfig.opc.username);
	lv_textarea_set_text(obj, (const char*)systemconfig.opc.username);
	ui_settings.ui_opc.name = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_opc_page, "User password: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_textarea_create(ui_settings_opc_page);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_BACKGROUND_COLOR), LV_PART_MAIN);
	lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);
	lv_textarea_set_one_line(obj, true);
	lv_textarea_set_password_mode(obj, true);
	lv_obj_set_width(obj, 150);
	lv_obj_set_pos(obj, 160, y);
	lv_obj_add_event_cb(obj, ui_event_edit_cb, LV_EVENT_ALL, &systemconfig.opc.userpassword);
	lv_textarea_set_text(obj, (const char*)systemconfig.opc.userpassword);
	ui_settings.ui_opc.password = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_opc_page, "Status: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_switch_create(ui_settings_opc_page);
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.opc.status) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.opc.status);
	ui_settings.ui_opc.status = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_opc_page, "Autostart: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_switch_create(ui_settings_opc_page);
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.opc.autostart) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.opc.autostart);
	ui_settings.ui_opc.autostart = obj;
}

void ui_settings_sdcard_page_init()
{
	ui_settings_sdcard_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_sdcard_page, 375, 235); //480-105
	lv_obj_set_pos(ui_settings_sdcard_page, 102, 45); 
	lv_obj_set_style_pad_all(ui_settings_sdcard_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_sdcard_page, "SD Card", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t y = 40;
	obj = ui_create_label(ui_settings_sdcard_page, "Status: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_switch_create(ui_settings_sdcard_page);	
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.sdcard.status) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.sdcard.status);
	ui_settings.ui_sdcard.status = obj;
	
	y += SETTINGS_LINE_SPACE;
	obj = ui_create_label(ui_settings_sdcard_page, "Automount: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y + 10);
	obj = lv_switch_create(ui_settings_sdcard_page);
	lv_obj_set_pos(obj, 160, y);
	if (systemconfig.sdcard.automount) lv_obj_add_state(obj, LV_STATE_CHECKED);
	else lv_obj_add_state(obj, LV_STATE_CHECKED);
	lv_obj_add_event_cb(obj, ui_settings_event_switch_cb, LV_EVENT_VALUE_CHANGED, &systemconfig.sdcard.automount);
	ui_settings.ui_sdcard.automount = obj;
}


void ui_settings_serial_page_init()
{
	char szpins[100] = "GPIO_10\nGPIO_11\nGPIO_12\nGPIO_13\nGPIO_14\nGPIO_21";
	ui_settings_serial_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_serial_page, 375, 235); //480-105
	lv_obj_set_pos(ui_settings_serial_page, 102, 45);
	lv_obj_set_style_pad_all(ui_settings_serial_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_serial_page, "Serial", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t x = 0, y = 30;	
	obj = ui_create_label(ui_settings_serial_page, "RX_PIN#: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	obj = lv_dropdown_create(ui_settings_serial_page);
	lv_dropdown_set_options(obj, szpins);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_TEXTAREA_BORDER_COLOR), LV_PART_MAIN);
	lv_obj_set_style_pad_all(obj, 2, LV_PART_MAIN);
	lv_obj_set_width(obj, 110);
	lv_obj_set_pos(obj, 100, y);
	lv_dropdown_set_selected(obj, get_index_from_value(systemconfig.serial.rx_pin));
	ui_settings.ui_serial.ui_rx_pin = obj;
	
	y += 35;
	obj = ui_create_label(ui_settings_serial_page, "TX_PIN#: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, x, y);
	obj = lv_dropdown_create(ui_settings_serial_page);
	lv_dropdown_set_options(obj, szpins);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_TEXTAREA_BORDER_COLOR), LV_PART_MAIN);
	lv_obj_set_style_pad_all(obj, 3, LV_PART_MAIN);
	lv_obj_set_width(obj, 110);
	lv_obj_set_pos(obj, 100, y);
	ui_settings.ui_serial.ui_tx_pin = obj;
	lv_dropdown_set_selected(obj, get_index_from_value(systemconfig.serial.tx_pin));
	
	y += 35;
	obj = ui_create_label(ui_settings_serial_page, "Baud rate: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	obj = lv_dropdown_create(ui_settings_serial_page);
	lv_dropdown_set_options(obj, "9600\n14400\n19200\n38400\n57600\n115200");
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_TEXTAREA_BORDER_COLOR), LV_PART_MAIN);
	lv_obj_set_style_pad_all(obj, 3, LV_PART_MAIN);
	lv_obj_set_pos(obj, 100, y);
	
	lv_dropdown_set_selected(obj, get_index_from_baud(systemconfig.serial.baud));
	ui_settings.ui_serial.ui_baud = obj;
	
	obj = ui_create_button(ui_settings_serial_page, "Preset K", 100, 30, 3, &lv_font_montserrat_14, ui_settings_serial_load_event_cb, (void*)0);
	lv_obj_set_pos(obj, 240, 60);
	obj = ui_create_button(ui_settings_serial_page, "Preset L", 100, 30, 3, &lv_font_montserrat_14, ui_settings_serial_load_event_cb, (void*)1);
	lv_obj_set_pos(obj, 240, 95);
	
	y += 40;
	obj = ui_create_button(ui_settings_serial_page, "Performence", 133, 30, 3, &lv_font_montserrat_14, ui_settings_serial_performance_event_cb, (void*)0);
	lv_obj_set_pos(obj, 2, y);
	
	obj = ui_create_label(ui_settings_serial_page, "Timeout: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 200, y);
	
	obj = ui_create_label(ui_settings_serial_page, "0", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 270, y); ui_settings_serial_performance_value = obj;
}

void ui_settings_system_page_init()
{
	ui_settings_system_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_system_page, 375, 235); //480-105
	lv_obj_set_pos(ui_settings_system_page, 102, 45); 
	lv_obj_set_style_pad_all(ui_settings_system_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_system_page, "SYSTEM", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t y = 40, step = SETTINGS_LINE_SPACE -10;

	obj = ui_create_label(ui_settings_system_page, "Revision: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	obj = ui_create_label(ui_settings_system_page, MajorStep, &lv_font_montserrat_14);	
	lv_obj_set_pos(obj, 160, y);
	
	y += step;
	obj = ui_create_label(ui_settings_system_page, "Release date: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	obj = ui_create_label(ui_settings_system_page, RevisionDate, &lv_font_montserrat_14);	
	lv_obj_set_pos(obj, 160, y);
	
	y += step;
	obj = ui_create_label(ui_settings_system_page, "CPU: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	
	esp_chip_info_t chip_info;
	esp_chip_info(&chip_info);
	
	// CPU Speed - 80Mhz / 160 Mhz / 240Mhz
	rtc_cpu_freq_config_t conf;
	rtc_clk_cpu_freq_get_config(&conf);

	
	char info[1024] = { 0 };
	sprintf(info,
		"%s Rev. %d\n%s %dMHz",
		CONFIG_IDF_TARGET,
		(int)chip_info.revision, 
		chip_info.cores == 2 ? "Dual Core" : "Single Core",
		(int)conf.freq_mhz);
	obj = ui_create_label(ui_settings_system_page, info, &lv_font_montserrat_14);	
	lv_obj_set_pos(obj, 160, y);
	
	
	y += step + 10;
	obj = ui_create_label(ui_settings_system_page, "Flash: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	uint32_t flash_size;
	if (esp_flash_get_size(NULL, &flash_size) == ESP_OK)
	{
		sprintf(info,
			"%dMB %s", 
			(int)flash_size / (1024 * 1024),
			(chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "[embedded]" : "[external]");
	}
	else
	{
		strcpy(info, "");
	}
	obj = ui_create_label(ui_settings_system_page, info, &lv_font_montserrat_14);	
	lv_obj_set_pos(obj, 160, y);
	
	y += step;
	obj = ui_create_label(ui_settings_system_page, "Wifi: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	obj = ui_create_label(ui_settings_system_page, (char*)((chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "2.4GHz WIFI" : "NA"), &lv_font_montserrat_14);	
	lv_obj_set_pos(obj, 160, y);
	
	y += step;
	obj = ui_create_label(ui_settings_system_page, "Bluetooth: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	sprintf(info, "%s%s", (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "", (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
	obj = ui_create_label(ui_settings_system_page, info, &lv_font_montserrat_14);	
	lv_obj_set_pos(obj, 160, y);
}


void ui_settings_screen_init()
{
	ui_settings_screen = ui_create_screen();	
	lv_obj_t* titlebar = ui_create_titlebar(ui_settings_screen, TITLEBAR_BACKGROUND_COLOR);
	
	lv_obj_t* title_label = lv_label_create(titlebar);	
	lv_obj_set_width(title_label, LV_SIZE_CONTENT);
	lv_obj_set_height(title_label, LV_SIZE_CONTENT);
	lv_label_set_recolor(title_label, true);
	lv_obj_set_style_text_color(title_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
	lv_label_set_text(title_label, "SETTINGS");
	lv_obj_set_style_text_font(title_label, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);	
	lv_obj_align(title_label, LV_ALIGN_CENTER, 0, 0);
	
	lv_obj_t* submenu = lv_obj_create(ui_settings_screen);
	lv_obj_clear_flag(submenu, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_size(submenu, 100, 275);
	lv_obj_set_pos(submenu, 0, 45);
	lv_obj_set_style_radius(submenu, 0, LV_PART_MAIN);
	lv_obj_set_style_pad_all(submenu, 2, LV_PART_MAIN);
	
	int y = 2, step = 35;
	lv_obj_t* obj = ui_create_button(submenu, "Bluetooth", LV_PCT(100), 30, 3, &lv_font_montserrat_14, ui_settings_event_submenu_cb, (void*)SETTINGS_SUBMENU_BLUETOOTH);
	lv_obj_set_user_data(obj, (void*)SETTINGS_SUBMENU_BLUETOOTH);
	lv_obj_set_style_bg_color(obj, lv_color_hex(UI_BUTTON_ACTIVE_BG_COLOR), LV_PART_MAIN);
	lv_obj_set_pos(obj, 0, y);
	settings_active_menu = obj;
	obj = ui_create_button(submenu, "WIFI", LV_PCT(100), 30, 3, &lv_font_montserrat_14, ui_settings_event_submenu_cb, (void*)SETTINGS_SUBMENU_WIFI);
	lv_obj_set_user_data(obj, (void*)SETTINGS_SUBMENU_BLUETOOTH);
	y += step; 	lv_obj_set_pos(obj, 0, y);
	obj = ui_create_button(submenu, "OPC", LV_PCT(100), 30, 3, &lv_font_montserrat_14, ui_settings_event_submenu_cb, (void*)SETTINGS_SUBMENU_OPC);
	lv_obj_set_user_data(obj, (void*)SETTINGS_SUBMENU_OPC);
	y += step; lv_obj_set_pos(obj, 0, y);
	obj = ui_create_button(submenu, "SERIAL", LV_PCT(100), 30, 3, &lv_font_montserrat_14, ui_settings_event_submenu_cb, (void*)SETTINGS_SUBMENU_SERIAL);
	lv_obj_set_user_data(obj, (void*)SETTINGS_SUBMENU_SERIAL);
	y += step; lv_obj_set_pos(obj, 0, y);
	
	obj = ui_create_button(submenu, "SD CARD", LV_PCT(100), 30, 3, &lv_font_montserrat_14, ui_settings_event_submenu_cb, (void*)SETTINGS_SUBMENU_SDCARD);
	lv_obj_set_user_data(obj, (void*)SETTINGS_SUBMENU_SDCARD);
	y += step; lv_obj_set_pos(obj, 0, y);
	
	obj = ui_create_button(submenu, "SYSTEM", LV_PCT(100), 30, 3, &lv_font_montserrat_14, ui_settings_event_submenu_cb, (void*)SETTINGS_SUBMENU_SYSTEM);
	lv_obj_set_user_data(obj, (void*)SETTINGS_SUBMENU_SYSTEM);
	y += step; lv_obj_set_pos(obj, 0, y);

	ui_settings_bluetooth_page_init();
	settings_active_page = ui_settings_bluetooth_page;
	ui_settings_wifi_page_init();
	lv_obj_add_flag(ui_settings_wifi_page, LV_OBJ_FLAG_HIDDEN);
	ui_settings_opc_page_init();
	lv_obj_add_flag(ui_settings_opc_page, LV_OBJ_FLAG_HIDDEN);
	ui_settings_sdcard_page_init();
	lv_obj_add_flag(ui_settings_sdcard_page, LV_OBJ_FLAG_HIDDEN);
	ui_settings_serial_page_init();
	lv_obj_add_flag(ui_settings_serial_page, LV_OBJ_FLAG_HIDDEN);
	ui_settings_system_page_init();
	lv_obj_add_flag(ui_settings_system_page, LV_OBJ_FLAG_HIDDEN);
	
	obj = ui_create_button(ui_settings_screen, "Save & Reboot", 133, 35, 3, &lv_font_montserrat_14, ui_settings_event_save_cb, NULL);
	lv_obj_set_pos(obj, 102, 285);
	obj = ui_create_button(ui_settings_screen, "Load", 239, 35, 3, &lv_font_montserrat_14, ui_settings_event_load_cb, NULL);
	lv_obj_set_pos(obj, 238, 285);
	
	ui_settings_update_configuratiion();
	ui_settings_initialized = true;
	
	lv_timer_create(ui_settings_update_data_timer_cb, 500, NULL);
}

void ui_settings_update_configuratiion()
{
	if (systemconfig.bluetooth.autostart)	lv_obj_add_state(ui_settings.ui_bluetooth.autostart, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_bluetooth.autostart, LV_STATE_CHECKED);
	if (systemconfig.bluetooth.server_enabled)	lv_obj_add_state(ui_settings.ui_bluetooth.status, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_bluetooth.status, LV_STATE_CHECKED);
	
	
	if (systemconfig.wifi.autoconnect)	lv_obj_add_state(ui_settings.ui_wifi.autoconnect, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_wifi.autoconnect, LV_STATE_CHECKED);
	if (systemconfig.wifi.status)	lv_obj_add_state(ui_settings.ui_wifi.status, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_wifi.status, LV_STATE_CHECKED);
	lv_textarea_set_text(ui_settings.ui_wifi.ssid, (const char*)systemconfig.wifi.ssid);
	lv_textarea_set_text(ui_settings.ui_wifi.password, (const char*)systemconfig.wifi.password);	
	lv_label_set_text(ui_settings.ui_wifi.ip, (const char*)systemconfig.wifi.ip);
	lv_label_set_text(ui_settings.ui_wifi.subnet, (const char*)systemconfig.wifi.subnet);

	
	if (systemconfig.opc.autostart)	lv_obj_add_state(ui_settings.ui_opc.autostart, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_opc.autostart, LV_STATE_CHECKED);
	if (systemconfig.opc.status)	lv_obj_add_state(ui_settings.ui_opc.status, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_opc.status, LV_STATE_CHECKED);
	lv_textarea_set_text(ui_settings.ui_opc.name, (const char*)systemconfig.opc.username);
	lv_textarea_set_text(ui_settings.ui_opc.password, (const char*)systemconfig.opc.userpassword);
	
	
	if (systemconfig.sdcard.automount)	lv_obj_add_state(ui_settings.ui_sdcard.automount, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_sdcard.automount, LV_STATE_CHECKED);
	if (systemconfig.sdcard.status)	lv_obj_add_state(ui_settings.ui_sdcard.status, LV_STATE_CHECKED);
	else lv_obj_clear_state(ui_settings.ui_sdcard.status, LV_STATE_CHECKED);
}

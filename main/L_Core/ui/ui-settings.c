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
bool ui_settings_initialized = false;


UI_SETTINGS ui_settings;
void ui_settings_serial_event_cb(lv_event_t* e)
{
	int type = (int) e->user_data;
	char* text = (char*)lv_textarea_get_text(ui_settings.ui_serial.send_text);
	if (strlen(text) == 0) return;
	switch (type)
	{
	case 1:
		communication_add_string_to_serial_buffer(&ComUart1.TxBuffer, text);
		break;
	case 2:
		communication_add_string_to_serial_buffer(&ComUart2.TxBuffer, text);
		break;
	}
}

void ui_settings_event_submenu_cb(lv_event_t* e)
{
	if (!ui_settings_initialized) return;
	lv_obj_t * target = lv_event_get_target(e);	
	SETTINGS_SUBMENU_TYPE type = (SETTINGS_SUBMENU_TYPE)(int) e->user_data;
	if (settings_active_menu  == target) return;
	if (settings_active_menu) lv_obj_set_style_bg_color(settings_active_menu, lv_color_hex(UI_MENU_NORMAL_ITEM_COLOR), LV_PART_MAIN);
	lv_obj_set_style_bg_color(target, lv_color_hex(UI_MENU_ACTIVE_ITEM_COLOR), LV_PART_MAIN);
	
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
		ui_show_messagebox(MESSAGEBOX_INFO, "Successful load configuration.", 3000);
		ui_settings_update_configuratiion();
	}
}

void ui_settings_event_save_cb(lv_event_t* e)
{
	if (!save_configuration())
	{
		ui_show_messagebox(MESSAGEBOX_ERROR, "Can't save configuration from sd card.", 3000);
	}
	else
	{
		ui_show_messagebox(MESSAGEBOX_INFO, "Successful save configuration to sd card.", 3000);
	}
}

char tempString[256] = { 0 };
void ui_settings_update_data_timer_cb(lv_timer_t * timer)
{
	//sprintf(tempString, "0x%02X 0x%02X 0x%02X 0x%02X", serial_uart_last_read_buffer[0], serial_uart_last_read_buffer[1], serial_uart_last_read_buffer[2], serial_uart_last_read_buffer[3]);
	lv_label_set_text(ui_settings.ui_serial.uart1_latest_received_text, (char*)serial_uart1_last_read_buffer);
	//sprintf(tempString, "0x%02X 0x%02X 0x%02X 0x%02X", serial_rs485_last_read_buffer[0], serial_rs485_last_read_buffer[1], serial_rs485_last_read_buffer[2], serial_rs485_last_read_buffer[3]);
	lv_label_set_text(ui_settings.ui_serial.uart2_latest_received_text, (char*)serial_uart2_last_read_buffer);
	
}
void ui_settings_bluetooth_page_init()
{
	ui_settings_bluetooth_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_bluetooth_page, 375, 256);//480-105
	lv_obj_set_pos(ui_settings_bluetooth_page, 102, 32); 
	lv_obj_set_style_pad_all(ui_settings_bluetooth_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_bluetooth_page, "Bluetooth", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t x = 0, y = 40;
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
	lv_obj_set_size(ui_settings_wifi_page, 375, 256); //480-105
	lv_obj_set_pos(ui_settings_wifi_page, 102, 32); 
	lv_obj_set_style_pad_all(ui_settings_wifi_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_wifi_page, "WIFI", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t x = 0, y = 40;
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
	lv_obj_set_size(ui_settings_opc_page, 375, 256); //480-105
	lv_obj_set_pos(ui_settings_opc_page, 102, 32); 
	lv_obj_set_style_pad_all(ui_settings_opc_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_opc_page, "OPC", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t x = 0, y = 40;
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
	lv_obj_set_size(ui_settings_sdcard_page, 375, 256); //480-105
	lv_obj_set_pos(ui_settings_sdcard_page, 102, 32); 
	lv_obj_set_style_pad_all(ui_settings_sdcard_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_sdcard_page, "SD Card", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t x = 0, y = 40;
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
	ui_settings_serial_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_serial_page, 375, 256); //480-105
	lv_obj_set_pos(ui_settings_serial_page, 102, 32); 
	lv_obj_set_style_pad_all(ui_settings_serial_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_serial_page, "Serial", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t x = 0, y = 40;
	
	obj = ui_create_label(ui_settings_serial_page, "UART1 BUF: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	obj = ui_create_label(ui_settings_serial_page, "", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 160, y); ui_settings.ui_serial.uart1_latest_received_text= obj;
	
	y += 40;
	obj = ui_create_label(ui_settings_serial_page, "UART2 BUF: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 0, y);
	obj = ui_create_label(ui_settings_serial_page, "", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 160, y); ui_settings.ui_serial.uart2_latest_received_text = obj;
	
	y += 30;
	obj = lv_textarea_create(ui_settings_serial_page);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_TEXTAREA_BORDER_COLOR), LV_PART_MAIN);
	lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);
	lv_textarea_set_one_line(obj, true);
	lv_obj_set_width(obj, 250);
	lv_obj_set_pos(obj, 0, y);
	lv_obj_add_event_cb(obj, ui_event_edit_cb, LV_EVENT_ALL, NULL);	
	ui_settings.ui_serial.send_text  = obj;
	
	y += 45;
	obj = ui_create_button(ui_settings_serial_page, "UART1 SEND", 100, 30, 3, &lv_font_montserrat_14, ui_settings_serial_event_cb, (void*)1);	
	lv_obj_set_pos(obj, 0, y);
	obj = ui_create_button(ui_settings_serial_page, "UART2 SEND", 100, 30, 3, &lv_font_montserrat_14, ui_settings_serial_event_cb, (void*)2);	
	lv_obj_set_pos(obj, 200, y);
}

void ui_settings_system_page_init()
{
	ui_settings_system_page = lv_obj_create(ui_settings_screen);
	lv_obj_set_size(ui_settings_system_page, 375, 256); //480-105
	lv_obj_set_pos(ui_settings_system_page, 102, 32); 
	lv_obj_set_style_pad_all(ui_settings_system_page, 10, LV_PART_MAIN);
	lv_obj_t* obj = ui_create_label(ui_settings_system_page, "SYSTEM", &lv_font_montserrat_20);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	uint16_t x = 0, y = 40, step = SETTINGS_LINE_SPACE -10;

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
	lv_obj_set_size(submenu, 100, 290);
	lv_obj_set_pos(submenu, 0, 30);
	lv_obj_set_style_radius(submenu, 0, LV_PART_MAIN);
	lv_obj_set_style_pad_all(submenu, 2, LV_PART_MAIN);
	
	int y = 2, step = 35;
	lv_obj_t* obj = ui_create_button(submenu, "Bluetooth", LV_PCT(100), 30, 3, &lv_font_montserrat_14, ui_settings_event_submenu_cb, (void*)SETTINGS_SUBMENU_BLUETOOTH);
	lv_obj_set_user_data(obj, (void*)SETTINGS_SUBMENU_BLUETOOTH);
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
	
	obj = ui_create_button(ui_settings_screen, "Save Config", 133, 24, 3, &lv_font_montserrat_14, ui_settings_event_save_cb, NULL);
	lv_obj_set_pos(obj, 102, 292);
	obj = ui_create_button(ui_settings_screen, "Load default config", 239, 24, 3, &lv_font_montserrat_14, ui_settings_event_load_cb, NULL);
	lv_obj_set_pos(obj, 238, 292);
	
	ui_settings_update_configuratiion();
	ui_settings_initialized = true;
	
	lv_timer_t * timer = lv_timer_create(ui_settings_update_data_timer_cb, 500, NULL);
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

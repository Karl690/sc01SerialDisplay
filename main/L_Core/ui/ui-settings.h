#pragma once


typedef enum
{
	SETTINGS_SUBMENU_BLUETOOTH,
	SETTINGS_SUBMENU_WIFI,
	SETTINGS_SUBMENU_OPC,
	SETTINGS_SUBMENU_SERIAL,
	SETTINGS_SUBMENU_SDCARD,
	SETTINGS_SUBMENU_SYSTEM,
}SETTINGS_SUBMENU_TYPE;

typedef struct
{
	lv_obj_t* ssid;
	lv_obj_t* password;
	lv_obj_t* status;
	lv_obj_t* autoconnect;
	lv_obj_t* ip;
	lv_obj_t* subnet;
} UI_WIFI;

typedef struct
{
	lv_obj_t* status;
	lv_obj_t* autostart;
} UI_BLUETOOTH;

typedef struct
{
	lv_obj_t* status;
	lv_obj_t* autostart;
	lv_obj_t* name;
	lv_obj_t* password;	
} UI_OPC;

typedef struct
{
	lv_obj_t* status;
	lv_obj_t* automount;	
} UI_SDCARD;

typedef struct
{
	lv_obj_t* uart1_latest_received_text;
	lv_obj_t* uart2_latest_received_text;
	lv_obj_t* send_text;
} UI_SERIAL;

typedef struct
{
	UI_WIFI ui_wifi;
	UI_BLUETOOTH ui_bluetooth;
	UI_OPC ui_opc;
	UI_SDCARD ui_sdcard;
	UI_SERIAL ui_serial;
}UI_SETTINGS;

extern lv_obj_t* ui_settings_screen;
extern UI_SETTINGS ui_settings;

void ui_settings_screen_init();
void ui_settings_update_configuratiion();
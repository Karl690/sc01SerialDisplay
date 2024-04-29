#pragma once
#include "ui.h"
#include "../bluetooth/ble.h"
extern lv_obj_t* ui_ble_screen;
extern lv_obj_t* ui_ble_server_send_text;
extern lv_obj_t* ui_ble_server_sent_total;
extern lv_obj_t* ui_ble_server_receive_total;
extern lv_obj_t* ui_ble_server_sent_status;
extern lv_obj_t* ui_ble_server_receive_status;

void ui_ble_screen_init();
void ui_ble_changed_ble_status(uint8_t status);
void ui_ble_add_device(void* dev);
void ui_ble_refresh_devices();
lv_obj_t* ui_ble_get_item_by_device(BleRemoteDevice* dev);
void ui_ble_set_device_status(BleRemoteDevice* dev);
void ui_ble_set_received_data(BleRemoteDevice* dev);
void ui_ble_set_headindex(uint8_t index);
void ui_ble_set_servername(char* name);
void ui_ble_switch_screen(uint8_t screen);
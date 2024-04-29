#include "main.h"
#include "L_Core/bluetooth/ble.h"
#include "K_Core/tools/tools.h"
#include "L_Core/storage/nvs.h"
#include "ui-bluetooth.h"

lv_obj_t* ui_ble_screen;
lv_obj_t* ui_ble_btn_scan;
lv_obj_t* ui_ble_spinner_scan;
lv_obj_t* ui_ble_device_list;
lv_obj_t* ui_ble_device_detail;
lv_obj_t* ui_ble_pair_button;
lv_obj_t* ui_ble_device_name;
lv_obj_t* ui_ble_device_address;
lv_obj_t* ui_ble_send;
lv_obj_t* ui_ble_receive;
lv_obj_t* ui_ble_total_received;
lv_obj_t* ui_ble_server_button;
lv_obj_t* ui_ble_client_button;
lv_obj_t* ui_ble_server_panel;
lv_obj_t* ui_ble_client_panel;
lv_obj_t* ui_ble_server_send_text;
lv_obj_t* ui_ble_server_sent_total;
lv_obj_t* ui_ble_server_receive_total;
lv_obj_t* ui_ble_server_sent_status;
lv_obj_t* ui_ble_server_receive_status;

BleRemoteDevice* selected_device = NULL;
ble_server_status_t  prev_ble_server_status = BLE_SERVER_LISTENING;
// screen: 0: server screen
//			1: client screen
void ui_ble_switch_screen(uint8_t screen)
{
	if (screen == 0)
	{
		lv_obj_clear_flag(ui_ble_server_panel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_ble_client_panel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_bg_color(ui_ble_server_button, lv_color_hex(UI_CHECK_ACTIVE_COLOR), LV_PART_MAIN);
		lv_obj_set_style_bg_color(ui_ble_client_button, lv_color_hex(UI_CHECK_NONACTIVE_COLOR), LV_PART_MAIN);
	}
	else
	{
		lv_obj_add_flag(ui_ble_server_panel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_ble_client_panel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_bg_color(ui_ble_server_button, lv_color_hex(UI_CHECK_NONACTIVE_COLOR), LV_PART_MAIN);
		lv_obj_set_style_bg_color(ui_ble_client_button, lv_color_hex(UI_CHECK_ACTIVE_COLOR), LV_PART_MAIN);
	}
}

void ui_ble_server_send_event_cb(lv_event_t* e) 
{
	char* text = (char*)lv_textarea_get_text(ui_ble_server_send_text);
	uint8_t len = strlen(text);
	if (len == 0) return;
	ble_server_send_data((uint8_t*)text, len);
}
void ui_ble_disconnect_event_cb(lv_event_t* e)
{
	ble_server_disconnect();
}

void ui_ble_server_updatename_event_cb(lv_event_t* e)
{
	ble_update_name(0);
}
void ui_ble_scan_event_cb(lv_event_t* e) 
{
	//lv_obj_t * label = lv_obj_get_child(target, 0);
	switch (ble_scan_status)
	{
	case BLE_CLIENT_SCAN_READY: ble_scan_start();break;
	case BLE_CLIENT_SCANNING: ble_scan_stop();break;
	default: break;
	}
}

void ui_ble_timer_handler(lv_timer_t* timer)
{
	if (ble_server_send_blink_count > 0)
	{
		sprintf(ui_temp_string, "%d", (int)ble_server_total_sent);
		lv_label_set_text(ui_ble_server_sent_total, ui_temp_string);
		lv_obj_set_style_text_color(ui_ble_server_sent_status, lv_color_hex(ble_server_send_blink_count % 2 ? UI_BUTTON_NORMAL_BG_COLOR : UI_BUTTON_DISABLE_BG_COLOR), LV_PART_MAIN);
		ble_server_send_blink_count--;
	}
	else {
		lv_obj_set_style_text_color(ui_ble_server_sent_status, lv_color_hex(UI_BUTTON_DISABLE_BG_COLOR), LV_PART_MAIN);
	}
	if (ble_server_receive_blink_count > 0)
	{
		sprintf(ui_temp_string, "%d", (int)ble_server_total_received);
		lv_label_set_text(ui_ble_server_receive_total, ui_temp_string);
		lv_obj_set_style_text_color(ui_ble_server_receive_status, lv_color_hex(ble_server_receive_blink_count % 2 ? UI_BUTTON_NORMAL_BG_COLOR : UI_BUTTON_DISABLE_BG_COLOR), LV_PART_MAIN);
		ble_server_receive_blink_count--;
	}
	else
	{
		lv_obj_set_style_text_color(ui_ble_server_receive_status, lv_color_hex(UI_BUTTON_DISABLE_BG_COLOR), LV_PART_MAIN);
	}
}
void ui_ble_event_device_item_cb(lv_event_t* e) 
{
	//lv_obj_t * target = lv_event_get_target(e);
	BleRemoteDevice* device = (BleRemoteDevice*)lv_event_get_user_data(e);
	lv_label_set_text(ui_ble_device_name, device->device_name);
	lv_label_set_text(ui_ble_device_address, device->address);
	selected_device = device;
	ui_ble_set_device_status(selected_device);
}

void ui_ble_send_event_cb(lv_event_t* e)
{
	lv_obj_t* textobj = (lv_obj_t*)lv_event_get_user_data(e);
	char* text = (char*)lv_textarea_get_text(textobj);
	uint8_t len = strlen(text);
	if (!len) return;
	ble_client_write_data((uint8_t*)text, len);
}
void ui_ble_switch_event_cb(lv_event_t* e)
{
	uint8_t screen = (uint8_t)(int) e->user_data;	
	ui_ble_switch_screen(screen);
}

void ui_ble_pair_event_cb(lv_event_t* e)
{
	if(!selected_device) return;
	if(!selected_device->is_connected)
		ble_client_connect_device(selected_device);
	else
		ble_client_disconnect_device(selected_device);
}


void ui_ble_set_device_status(BleRemoteDevice* dev)
{
	lv_obj_t* item = ui_ble_get_item_by_device(dev);
	lv_obj_t* label = lv_obj_get_child(item, 0);
	if(dev->is_connected) {
		lv_label_set_text_fmt(label, "#66d800 " LV_SYMBOL_BLUETOOTH " %s #", dev->device_name);
		if(selected_device == dev) {
			lv_obj_set_style_bg_color(ui_ble_pair_button, lv_color_hex(0x3e8300), LV_PART_MAIN);
			label = lv_obj_get_child(ui_ble_pair_button, 0);
			lv_label_set_text(label, "Unpaire device");
		}
	}else {
		lv_label_set_text_fmt(label, "#c4c4c4 " LV_SYMBOL_BLUETOOTH " %s #", dev->device_name);
		if(selected_device == dev) {
			lv_obj_set_style_bg_color(ui_ble_pair_button, lv_color_hex(0x4b4b4b), LV_PART_MAIN);
			label = lv_obj_get_child(ui_ble_pair_button, 0);
			lv_label_set_text(label, "Paire device");
		}
	}
}

void ui_ble_screen_init()
{
	lv_obj_t* obj;
	uint16_t x, y;
	ui_ble_screen = ui_create_screen();	
	lv_obj_t* titlebar = ui_create_titlebar(ui_ble_screen, TITLEBAR_BACKGROUND_COLOR);
	
	lv_obj_t* title_label = lv_label_create(titlebar);	
	lv_obj_set_width(title_label, LV_SIZE_CONTENT);
	lv_obj_set_height(title_label, LV_SIZE_CONTENT);
	lv_label_set_recolor(title_label, true);
	lv_obj_set_style_text_color(title_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
	lv_label_set_text(title_label, "BLUETOOTH");
	lv_obj_set_style_text_font(title_label, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);	
	lv_obj_align(title_label, LV_ALIGN_CENTER, 0, 0);
	y = 42;
	obj = ui_create_button(ui_ble_screen, "SERVER", SCREEN_WIDTH / 2 - 1, 30, 3, &lv_font_montserrat_14, ui_ble_switch_event_cb, (void*)0);	
	lv_obj_set_pos(obj, 0, y);
	ui_ble_server_button = obj;
	obj = ui_create_button(ui_ble_screen, "CLIENT", SCREEN_WIDTH / 2 - 1, 30, 3, &lv_font_montserrat_14, ui_ble_switch_event_cb, (void*)1);	
	lv_obj_set_pos(obj, SCREEN_WIDTH/2, y);
	ui_ble_client_button = obj;
	// panel
	x = 5; y +=30;
	obj = lv_obj_create(ui_ble_screen);
	lv_obj_set_size(obj, SCREEN_WIDTH-2, SCREEN_HEIGHT-65);
	lv_obj_set_pos(obj, 1, y); 
	lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
	ui_ble_server_panel = obj;
	
	obj = lv_obj_create(ui_ble_screen);
	lv_obj_set_size(obj, SCREEN_WIDTH - 2, SCREEN_HEIGHT - 65);
	lv_obj_set_pos(obj, 1, y); 
	lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
	ui_ble_client_panel = obj;
	
	// server
	
	x = 10; y = 45;
	obj = ui_create_button(ui_ble_server_panel, "Update name", 200, 30, 2, &lv_font_montserrat_14, ui_ble_server_updatename_event_cb, NULL);
	lv_obj_set_pos(obj, x, y);
	
	y += 45;
	obj = lv_textarea_create(ui_ble_server_panel);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_TEXTAREA_BORDER_COLOR), LV_PART_MAIN);
	lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);
	lv_textarea_set_one_line(obj, true);
	lv_obj_set_size(obj, 250, 30);
	lv_obj_set_pos(obj, x, y);
	lv_obj_add_event_cb(obj, ui_event_edit_cb, LV_EVENT_ALL, NULL);	
	ui_ble_server_send_text = obj;
	
	obj = ui_create_button(ui_ble_server_panel, "SEND", 100, 30, 3, &lv_font_montserrat_14, ui_ble_server_send_event_cb, NULL);	
	lv_obj_set_pos(obj, 280, y);
	
	
	
	y += 45;
	obj = ui_create_label(ui_ble_server_panel, "XMIT: ", &lv_font_montserrat_20);
	lv_obj_set_pos(obj, x, y);
	obj = ui_create_label(ui_ble_server_panel, LV_SYMBOL_UP, &lv_font_montserrat_24);
	lv_obj_set_style_text_color(obj, lv_color_hex(UI_BUTTON_DISABLE_BG_COLOR), LV_PART_MAIN);	
	lv_obj_set_pos(obj, x+60, y);
	ui_ble_server_sent_status = obj;
	obj = ui_create_label(ui_ble_server_panel, "0", &lv_font_montserrat_20);
	lv_obj_set_pos(obj, x + 90, y);
	ui_ble_server_sent_total = obj;
	
	x = 200;
	obj = ui_create_label(ui_ble_server_panel, "RCV: ", &lv_font_montserrat_20);
	lv_obj_set_pos(obj, x, y);
	obj = ui_create_label(ui_ble_server_panel, LV_SYMBOL_DOWN, &lv_font_montserrat_24);	
	lv_obj_set_style_text_color(obj, lv_color_hex(UI_BUTTON_DISABLE_BG_COLOR), LV_PART_MAIN);
	lv_obj_set_pos(obj, x + 60, y);
	ui_ble_server_receive_status = obj;
	obj = ui_create_label(ui_ble_server_panel, "0", &lv_font_montserrat_20);
	lv_obj_set_pos(obj, x + 90, y);
	ui_ble_server_receive_total = obj;
	
	
	y += 45;
	obj = ui_create_button(ui_ble_server_panel, "DICONNECT", SCREEN_WIDTH - 20, 30, 3, &lv_font_montserrat_14, ui_ble_disconnect_event_cb, NULL);	
	lv_obj_set_pos(obj, 5, y);
	
	// client 
	x = 0; y = 0;
	obj = ui_create_button(ui_ble_client_panel, "SCAN", 100, 30, 3, &lv_font_montserrat_14, ui_ble_scan_event_cb, NULL);	
	lv_obj_set_pos(obj, x, y);	ui_ble_btn_scan = obj;
	
	obj = ui_create_button(ui_ble_client_panel, "PARING DEVICE", 280, 30, 3, &lv_font_montserrat_14, ui_ble_pair_event_cb, NULL);
	lv_obj_set_pos(obj, 190, y); ui_ble_pair_button = obj;
	
	x = 120; 
	obj = lv_spinner_create(ui_ble_client_panel, 1000, 60);
	lv_obj_set_size(obj, 30, 30);	
	lv_obj_set_pos(obj, x, y); ui_ble_spinner_scan = obj;
	lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
	
	x = 0; y += 40;
	ui_ble_device_list = lv_obj_create(ui_ble_client_panel);
	lv_obj_set_size(ui_ble_device_list, 170, 200);
	lv_obj_set_pos(ui_ble_device_list, x, y); 
	lv_obj_set_style_pad_all(ui_ble_device_list, 2, LV_PART_MAIN);
	
	x = 190;
	ui_ble_device_detail = lv_obj_create(ui_ble_client_panel);
	lv_obj_set_size(ui_ble_device_detail, 280, 200);
	lv_obj_set_pos(ui_ble_device_detail, x, y); 
	lv_obj_set_style_pad_all(ui_ble_device_detail, 2, LV_PART_MAIN);
	
	x = 10; y = 10;	
	obj = ui_create_label(ui_ble_device_detail, "NAME: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, x, y); 
	obj = ui_create_label(ui_ble_device_detail, "", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 100, y); ui_ble_device_name = obj;
	
	
	x = 10; y += 30;	
	obj = ui_create_label(ui_ble_device_detail, "ADDRESS: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, x, y); 
	obj = ui_create_label(ui_ble_device_detail, "", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 100, y); ui_ble_device_address = obj;
	
	y += 30;
	obj = lv_textarea_create(ui_ble_device_detail);
	lv_obj_set_style_border_color(obj, lv_color_hex(UI_TEXTAREA_BORDER_COLOR), LV_PART_MAIN);
	lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);
	lv_textarea_set_one_line(obj, true);
	lv_obj_set_size(obj, 150, 30);
	lv_obj_set_pos(obj, x, y);
	lv_obj_add_event_cb(obj, ui_event_edit_cb, LV_EVENT_ALL, NULL);	
	
	obj = ui_create_button(ui_ble_device_detail, "SEND", 100, 30, 3, &lv_font_montserrat_14, ui_ble_send_event_cb, obj);	
	lv_obj_set_pos(obj, 160, y);
	y += 45;
	obj = ui_create_label(ui_ble_device_detail, "RECEIVED: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, x, y); 
	obj = ui_create_label(ui_ble_device_detail, "", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 100, y);  ui_ble_receive = obj;
	
	y += 30;
	obj = ui_create_label(ui_ble_device_detail, "TOTAL: ", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, x, y);
	obj = ui_create_label(ui_ble_device_detail, "", &lv_font_montserrat_14);
	lv_obj_set_pos(obj, 100, y); ui_ble_total_received = obj;
	ui_ble_switch_screen(0);
	
	lv_timer_create(ui_ble_timer_handler, 100, NULL);
}

void ui_ble_changed_ble_status(uint8_t status)
{
	if(!ui_initialized) return; // Do nothing util UI is initialized.
	lv_obj_t * label = lv_obj_get_child(ui_ble_btn_scan, 0);
	if (status == BLE_CLIENT_SCANNING)
	{
		lv_obj_clean(ui_ble_device_list);
		selected_device = NULL;
		lv_obj_clear_flag(ui_ble_spinner_scan, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(label, "Stop");
	}
	else
	{
		lv_obj_add_flag(ui_ble_spinner_scan, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(label, "Scan");
	}
}

void ui_ble_add_device(void* dev) {
	if(!ui_initialized) return; // Do nothing util UI is initialized.
	BleRemoteDevice* device = (BleRemoteDevice*)dev;
	lv_obj_t* obj = lv_obj_create(ui_ble_device_list);
	lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
	lv_obj_set_style_pad_all(obj, 2, LV_PART_MAIN);
	lv_obj_set_size(obj, LV_PCT(100), 30);
	lv_obj_set_pos(obj, 5, (30 + 5) * device->id);
	
	lv_obj_t* label = lv_label_create(obj);
	lv_label_set_recolor(label, true);
	lv_label_set_text_fmt(label, "#c4c4c4 " LV_SYMBOL_BLUETOOTH " %s #", device->device_name);
	lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
	obj->user_data = (void*)device;
	lv_obj_add_event_cb(obj, ui_ble_event_device_item_cb, LV_EVENT_CLICKED, device);
}

lv_obj_t* ui_ble_get_item_by_device(BleRemoteDevice* dev)
{
	for (uint8_t i = 0; i < lv_obj_get_child_cnt(ui_ble_device_list); i++) {
		lv_obj_t* child = lv_obj_get_child(ui_ble_device_list, i);
		if(child->user_data == dev) {
			return child;
		}
	}
	return NULL;
}

void ui_ble_refresh_devices()
{
	lv_obj_clean(ui_ble_device_list); //remove all device items
	for(uint8_t i = 0; i < ble_client_scaned_device_num; i ++) 
	{
		ui_ble_add_device(&ble_client_remote_device[i]);
	}
}

void ui_ble_set_received_data(BleRemoteDevice* dev)
{
	if(selected_device != dev) return;
	lv_label_set_text(ui_ble_receive, (const char*)dev->last_received_buffer);
	sprintf(ui_temp_string, "%d", (int)dev->total_received);
	lv_label_set_text(ui_ble_total_received, ui_temp_string);
}

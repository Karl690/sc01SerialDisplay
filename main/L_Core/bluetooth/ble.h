#pragma once

#pragma once

#include "esp_bt.h"

#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_gattc_api.h"
#include "esp_bt_defs.h"
#include "esp_gatt_common_api.h"
#include "esp_bt_main.h"
#include "K_Core/serial/serial.h"

#define BLE_TAG "HYREL_BLE"
#define BLE_PORT_ID				0x80
#define BLE_SERVER_DEVICE_NAME "ESP32_S3_SC01"

#define spp_sprintf(s,...)         sprintf((char*)(s), ##__VA_ARGS__)
#define SPP_DATA_MAX_LEN           (1024)
#define SPP_CMD_MAX_LEN            (20)
#define SPP_STATUS_MAX_LEN         (20)
#define SPP_DATA_BUFF_MAX_LEN      (2*1024)

#define BLE_SERVER_APP_ID              0x56
#define BLE_SERVER_PROFILE_NUM 		1


#define SPP_SERVICE_UUID		0xABF0
#define ESP_GATT_UUID_SPP_DATA_RECEIVE      0xABF1 // it should use in Writting
#define ESP_GATT_UUID_SPP_DATA_NOTIFY       0xABF2 // it should use in Reading
#define ESP_GATT_UUID_SPP_COMMAND_RECEIVE   0xABF3
#define ESP_GATT_UUID_SPP_COMMAND_NOTIFY    0xABF4

#define BLE_CLIENT_PROFILE_NUM                 1
#define BLE_CLIENT_PROFILE_APP_ID              0
#define SCAN_ALL_THE_TIME           0
#define BLE_CLIENT_SCAN_DURATION 	10  // the unit of the duration is second, 0xFFFF means that is unlimited.
#define BLE_CLIENT_MAX_CONNECT_NUM 	1
///Attributes State Machine
enum {
	SPP_IDX_SVC,

	SPP_IDX_SPP_DATA_RECV_CHAR,
	SPP_IDX_SPP_DATA_RECV_VAL,

	SPP_IDX_SPP_DATA_NOTIFY_CHAR,
	SPP_IDX_SPP_DATA_NTY_VAL,
	SPP_IDX_SPP_DATA_NTF_CFG,

	SPP_IDX_SPP_COMMAND_CHAR,
	SPP_IDX_SPP_COMMAND_VAL,

	SPP_IDX_SPP_STATUS_CHAR,
	SPP_IDX_SPP_STATUS_VAL,
	SPP_IDX_SPP_STATUS_CFG,

	SPP_IDX_NB,
};

enum {
	BLE_CLIENT_SCAN_NOT_READY,
	BLE_CLIENT_SCAN_READY,
	BLE_CLIENT_SCANNING,
};

typedef enum
{
	BLE_SERVER_LISTENING = 0,
	BLE_SERVER_PAIRED    = 1,
	BLE_SERVER_CONNECTED = 2,
	BLE_SERVER_HEADSET   = 3,
}ble_server_status_t;


typedef struct _tagBLEDevice {
	uint8_t id;
	esp_ble_gap_cb_param_t scan_result;
	char device_name[30];
	char address[60];
	uint8_t is_connected;
	uint8_t is_scaned;

	esp_gattc_cb_t gattc_cb;
	uint16_t gattc_if;
	uint16_t app_id;
	uint16_t conn_id;
	uint16_t service_start_handle;
	uint16_t service_end_handle;
	uint16_t write_handle;
	uint16_t notify_handle;
	esp_bd_addr_t remote_bda;
	uint8_t get_server;
	uint32_t total_received;
	uint32_t total_sent;
	uint8_t last_received_buffer[100];
	uint8_t last_send_buffer[100];
	uint8_t receive_buffer[256];
	uint8_t send_buffer[256];
}BleRemoteDevice;


extern BleDevice bleServerDevice;
extern ble_server_status_t ble_server_status;
extern uint8_t ble_client_scaned_device_num;
extern BleRemoteDevice ble_client_remote_device[BLE_CLIENT_MAX_CONNECT_NUM];
extern esp_ble_adv_params_t spp_adv_params;

extern uint8_t ble_server_send_blink_count;
extern uint8_t ble_server_receive_blink_count;
extern uint8_t ble_server_pairing_countdown;

extern uint8_t is_client_connected;
extern uint8_t is_server_connected;

extern uint64_t ble_server_total_sent;
extern uint64_t ble_server_total_received;
extern uint16_t spp_client_conn_id;
extern uint16_t spp_client_mtu_size;

extern uint8_t ble_scan_status; 
extern esp_ble_gap_cb_param_t ble_client_scan_rst;


void ble_init();

uint8_t ble_enable();
void ble_disable();

void ble_scan_start();
void ble_scan_stop();

uint8_t ble_server_enable();
void ble_server_disable();
uint8_t ble_server_send_data(uint8_t* data, uint16_t size);
void ble_server_received_data(uint8_t* data, uint16_t size);


uint8_t ble_add_scan_device(esp_ble_gap_cb_param_t* scan_result);

uint8_t ble_client_enable();
void ble_client_disable();
void ble_server_disconnect();
uint8_t ble_client_connect_device(BleRemoteDevice*);
void ble_client_disconnect_device(BleRemoteDevice*);

BleRemoteDevice* ble_get_device(uint8_t id);
BleRemoteDevice* ble_client_get_device_by_address(uint8_t* address);
BleRemoteDevice* ble_client_get_device_by_conn_id(uint16_t);
void ble_client_write_data(BleRemoteDevice* dev, uint8_t* data, uint16_t len);
void ble_client_read_data(BleRemoteDevice* dev, uint8_t* data, uint16_t len);
#include "main.h"
#include "ble.h"
#include "driver/uart.h"
#include "L_Core/ui/ui.h"
#include "L_Core/ui/ui-bluetooth.h"
#include "K_Core/communication/communication.h"
#include "K_Core/tools/tools.h";
#define ESP_SERVER_PROFILE_APP_IDX         0
#define SAMPLE_DEVICE_NAME          "ESP32_S3_SC"    //The Device Name Characteristics in GAP
#define SPP_SVC_INST_ID	            0


uint8_t ble_server_rx_buffer[RX_BUF_SIZE];
uint8_t ble_server_rx_urgent_buffer[RX_BUF_SIZE];
uint8_t ble_server_tx_buffer[TX_BUF_SIZE];
BleDevice bleServerDevice;
ble_server_status_t ble_server_status = BLE_SERVER_LISTENING;
uint8_t ble_server_send_blink_count = 0;
uint8_t ble_server_receive_blink_count = 0;
char ble_tmp[256] = { 0 };
/// SPP Service
const uint16_t spp_service_uuid = SPP_SERVICE_UUID;
/// Characteristic UUID

static const uint8_t spp_adv_data[] = {
	/* Flags */
	0x02,0x01,0x06,
	/* Complete List of 16-bit Service Class UUIDs */
	0x03,0x03,0xF0,0xAB,
	
	};

/* Complete Local Name in advertising */
// Data Type 9 (Complete Local Name), Data 1 
uint8_t raw_scan_rsp_data[BLE_RAW_RSP_DATA_SIZE] = {
	//SC01_MEG_##
        12, 0x09,   //12 : length
		'S','C','0','1','_','M', 'E', 'G', '_', '0', '0'
};

static uint16_t spp_server_mtu_size = 23;
static uint16_t spp_server_conn_id = 0xffff;
static esp_gatt_if_t spp_gatts_if = 0xff;
static bool enable_data_ntf = false;
uint8_t is_server_connected = 0;

uint64_t ble_server_total_sent = 0;
uint64_t ble_server_total_received = 0;
static esp_bd_addr_t spp_remote_bda = { 0x0, };
uint8_t ble_server_pairing_countdown = 0;
static uint16_t spp_handle_table[SPP_IDX_NB];

struct gatts_profile_inst {
	esp_gatts_cb_t gatts_cb;
	uint16_t gatts_if;
	uint16_t app_id;
	uint16_t conn_id;
	uint16_t service_handle;
	esp_gatt_srvc_id_t service_id;
	uint16_t char_handle;
	esp_bt_uuid_t char_uuid;
	esp_gatt_perm_t perm;
	esp_gatt_char_prop_t property;
	uint16_t descr_handle;
	esp_bt_uuid_t descr_uuid;
};

typedef struct spp_receive_data_node {
	int32_t len;
	uint8_t * node_buff;
	struct spp_receive_data_node * next_node;
}spp_receive_data_node_t;


typedef struct spp_receive_data_buff {
	int32_t node_num;
	int32_t buff_size;
	spp_receive_data_node_t * first_node;
}spp_receive_data_buff_t;



static void gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

/* One gatt-based profile one app_id and one gatts_if, this array will store the gatts_if returned by ESP_GATTS_REG_EVT */
static struct gatts_profile_inst spp_profile_tab[BLE_SERVER_PROFILE_NUM] = {
	[ESP_SERVER_PROFILE_APP_IDX] = {
	.gatts_cb = gatts_profile_event_handler,
	.gatts_if = ESP_GATT_IF_NONE, /* Not get the gatt_if, so initial is ESP_GATT_IF_NONE */
},
};

/*
 *  SPP PROFILE ATTRIBUTES
 ****************************************************************************************
 */

#define CHAR_DECLARATION_SIZE   (sizeof(uint8_t))
static const uint16_t primary_service_uuid = ESP_GATT_UUID_PRI_SERVICE;
static const uint16_t character_declaration_uuid = ESP_GATT_UUID_CHAR_DECLARE;
static const uint16_t character_client_config_uuid = ESP_GATT_UUID_CHAR_CLIENT_CONFIG;

static const uint8_t char_prop_read_notify = ESP_GATT_CHAR_PROP_BIT_READ | ESP_GATT_CHAR_PROP_BIT_NOTIFY;
static const uint8_t char_prop_read_write = ESP_GATT_CHAR_PROP_BIT_WRITE_NR | ESP_GATT_CHAR_PROP_BIT_READ;

#ifdef SUPPORT_HEARTBEAT
static const uint8_t char_prop_read_write_notify = ESP_GATT_CHAR_PROP_BIT_READ | ESP_GATT_CHAR_PROP_BIT_WRITE_NR | ESP_GATT_CHAR_PROP_BIT_NOTIFY;
#endif

///SPP Service - data receive characteristic, read&write without response
static const uint16_t spp_data_receive_uuid = ESP_GATT_UUID_SPP_DATA_RECEIVE;
static const uint8_t  spp_data_receive_val[SPP_DATA_MAX_LEN] = { 0x00 };

///SPP Service - data notify characteristic, notify&read
static const uint16_t spp_data_notify_uuid = ESP_GATT_UUID_SPP_DATA_NOTIFY;
static const uint8_t  spp_data_notify_val[SPP_DATA_MAX_LEN] = { 0x00 };
static const uint8_t  spp_data_notify_ccc[2] = { 0x00, 0x00 };

///SPP Service - command characteristic, read&write without response
static const uint16_t spp_command_uuid = ESP_GATT_UUID_SPP_COMMAND_RECEIVE;
static const uint8_t  spp_command_val[10] = { 0x00 };

///SPP Service - status characteristic, notify&read
static const uint16_t spp_status_uuid = ESP_GATT_UUID_SPP_COMMAND_NOTIFY;
static const uint8_t  spp_status_val[10] = { 0x00 };
static const uint8_t  spp_status_ccc[2] = { 0x00, 0x00 };

///Full HRS Database Description - Used to add attributes into the database
static const esp_gatts_attr_db_t spp_gatt_db[SPP_IDX_NB] =
{
	//SPP -  Service Declaration
	[SPP_IDX_SVC] = {
	 { ESP_GATT_AUTO_RSP },
	{
	 ESP_UUID_LEN_16,
	(uint8_t *)&primary_service_uuid,
	ESP_GATT_PERM_READ,
	sizeof(spp_service_uuid),
	sizeof(spp_service_uuid),
	(uint8_t *)&spp_service_uuid 
}
 },

	//SPP -  data receive characteristic Declaration
	[SPP_IDX_SPP_DATA_RECV_CHAR] = { 
	{ ESP_GATT_AUTO_RSP },
	{
	 ESP_UUID_LEN_16,
	(uint8_t *)&character_declaration_uuid,
	ESP_GATT_PERM_READ,
	CHAR_DECLARATION_SIZE, 
	CHAR_DECLARATION_SIZE,
	(uint8_t *)&char_prop_read_write
 }
 },

	//SPP -  data receive characteristic Value
	[SPP_IDX_SPP_DATA_RECV_VAL] = {
	 { ESP_GATT_AUTO_RSP },
	{
	 ESP_UUID_LEN_16,
	(uint8_t *)&spp_data_receive_uuid,
	ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
	SPP_DATA_MAX_LEN,
	 sizeof(spp_data_receive_val),
	(uint8_t *)spp_data_receive_val 
} 
},

	//SPP -  data notify characteristic Declaration
	[SPP_IDX_SPP_DATA_NOTIFY_CHAR] = {
	 { ESP_GATT_AUTO_RSP },
	{
	 ESP_UUID_LEN_16,
	(uint8_t *)&character_declaration_uuid,
	ESP_GATT_PERM_READ,
	CHAR_DECLARATION_SIZE, 
	CHAR_DECLARATION_SIZE,
	(uint8_t *)&char_prop_read_notify
 }
 },

	//SPP -  data notify characteristic Value
	[SPP_IDX_SPP_DATA_NTY_VAL] = {
	 { ESP_GATT_AUTO_RSP },
	{ 
	ESP_UUID_LEN_16,
	(uint8_t *)&spp_data_notify_uuid,
	ESP_GATT_PERM_READ,
	SPP_DATA_MAX_LEN,
	sizeof(spp_data_notify_val),
	(uint8_t *)spp_data_notify_val
 }
 },

	//SPP -  data notify characteristic - Client Characteristic Configuration Descriptor
	[SPP_IDX_SPP_DATA_NTF_CFG] = { 
	{ ESP_GATT_AUTO_RSP },
	{
	 ESP_UUID_LEN_16,
	(uint8_t *)&character_client_config_uuid,
	ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
	sizeof(uint16_t), 
	sizeof(spp_data_notify_ccc),
	(uint8_t *)spp_data_notify_ccc
 } 
},

	//SPP -  command characteristic Declaration
	[SPP_IDX_SPP_COMMAND_CHAR] = { 
	{ ESP_GATT_AUTO_RSP },
	{ 
	ESP_UUID_LEN_16,
	(uint8_t *)&character_declaration_uuid,
	ESP_GATT_PERM_READ,
	CHAR_DECLARATION_SIZE, 
	CHAR_DECLARATION_SIZE,
	(uint8_t *)&char_prop_read_write 
} 
},

	//SPP -  command characteristic Value
	[SPP_IDX_SPP_COMMAND_VAL] = {
	 { ESP_GATT_AUTO_RSP },
	{ 
	ESP_UUID_LEN_16,
	(uint8_t *)&spp_command_uuid,
	ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
	SPP_CMD_MAX_LEN,
	 sizeof(spp_command_val),
	(uint8_t *)spp_command_val 
} 
},

	//SPP -  status characteristic Declaration
	[SPP_IDX_SPP_STATUS_CHAR] = {
	 { ESP_GATT_AUTO_RSP },
	{
	 ESP_UUID_LEN_16,
	(uint8_t *)&character_declaration_uuid,
	ESP_GATT_PERM_READ,
	CHAR_DECLARATION_SIZE, 
	CHAR_DECLARATION_SIZE,
	(uint8_t *)&char_prop_read_notify 
}
 },

	//SPP -  status characteristic Value
	[SPP_IDX_SPP_STATUS_VAL] = { 
	{ ESP_GATT_AUTO_RSP },
	{ 
	ESP_UUID_LEN_16,
	(uint8_t *)&spp_status_uuid,
	ESP_GATT_PERM_READ,
	SPP_STATUS_MAX_LEN,
	 sizeof(spp_status_val),
	(uint8_t *)spp_status_val 
} 
},

	//SPP -  status characteristic - Client Characteristic Configuration Descriptor
	[SPP_IDX_SPP_STATUS_CFG] = {
	 { ESP_GATT_AUTO_RSP },
	{
	 ESP_UUID_LEN_16,
	(uint8_t *)&character_client_config_uuid,
	ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
	sizeof(uint16_t), 
	sizeof(spp_status_ccc),
	(uint8_t *)spp_status_ccc
 }
 },
};

static uint8_t find_char_and_desr_index(uint16_t handle)
{
	uint8_t error = 0xff;

	for (int i = 0; i < SPP_IDX_NB; i++) {
		if (handle == spp_handle_table[i]) {
			return i;
		}
	}

	return error;
}

char ble_last_received_data[20] = { 0 };

static void gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param)
{
	esp_ble_gatts_cb_param_t *p_data = (esp_ble_gatts_cb_param_t *) param;
	uint8_t res = 0xff;

	ESP_LOGI(BLE_TAG, "event = %x\n", event);
	switch (event) {
	case ESP_GATTS_REG_EVT:
		ESP_LOGI(BLE_TAG, "%s %d\n", __func__, __LINE__);
		esp_ble_gap_set_device_name(SAMPLE_DEVICE_NAME);

		ESP_LOGI(BLE_TAG, "%s %d\n", __func__, __LINE__);
		esp_ble_gap_config_adv_data_raw((uint8_t *)spp_adv_data, sizeof(spp_adv_data));

		esp_ble_gap_config_scan_rsp_data_raw(raw_scan_rsp_data, sizeof(raw_scan_rsp_data));
		
		ESP_LOGI(BLE_TAG, "%s %d\n", __func__, __LINE__);
		esp_ble_gatts_create_attr_tab(spp_gatt_db, gatts_if, SPP_IDX_NB, SPP_SVC_INST_ID);
		break;
	case ESP_GATTS_READ_EVT:
		res = find_char_and_desr_index(p_data->read.handle);
		if (res == SPP_IDX_SPP_STATUS_VAL) {
			//TODO:client read the status characteristic
		}
		break;
	case ESP_GATTS_WRITE_EVT: {
		res = find_char_and_desr_index(p_data->write.handle);
		if (p_data->write.is_prep == false) {
			ESP_LOGI(BLE_TAG, "ESP_GATTS_WRITE_EVT : handle = %d\n", res);
			if (res == SPP_IDX_SPP_COMMAND_VAL) {
				uint8_t * spp_cmd_buff = NULL;
				spp_cmd_buff = (uint8_t *)malloc((spp_server_mtu_size - 3) * sizeof(uint8_t));
				if (spp_cmd_buff == NULL) {
					ESP_LOGE(BLE_TAG, "%s malloc failed\n", __func__);
					break;
				}
				memset(spp_cmd_buff, 0x0, (spp_server_mtu_size - 3));
				memcpy(spp_cmd_buff, p_data->write.value, p_data->write.len);
				//xQueueSend(cmd_cmd_queue, &spp_cmd_buff, 10 / portTICK_PERIOD_MS);
			}
			else if (res == SPP_IDX_SPP_DATA_NTF_CFG) {
				if ((p_data->write.len == 2)&&(p_data->write.value[0] == 0x01)&&(p_data->write.value[1] == 0x00)) {
					enable_data_ntf = true;
				}
				else if ((p_data->write.len == 2)&&(p_data->write.value[0] == 0x00)&&(p_data->write.value[1] == 0x00)) {
					enable_data_ntf = false;
				}
			}
			else if (res == SPP_IDX_SPP_DATA_RECV_VAL) {
				ble_server_received_data(p_data->write.value, p_data->write.len);
				if (p_data->write.len >= 20) strncpy(ble_last_received_data, (char*)p_data->write.value, 20);
				else strcpy(ble_last_received_data, (char*)p_data->write.value);				
					
			}
			else {
				//TODO:
			}
		}
		else if ((p_data->write.is_prep == true)&&(res == SPP_IDX_SPP_DATA_RECV_VAL)) {
			ESP_LOGI(BLE_TAG, "ESP_GATTS_PREP_WRITE_EVT : handle = %d\n", res);
			//store_wr_buffer(p_data);
		}
		break;
	}
	case ESP_GATTS_EXEC_WRITE_EVT: {
		ESP_LOGI(BLE_TAG, "ESP_GATTS_EXEC_WRITE_EVT\n");
			if (p_data->exec_write.exec_write_flag) {
				//print_write_buffer();
				//free_write_buffer();
			}
			break;
		}
	case ESP_GATTS_MTU_EVT:
		spp_server_mtu_size = p_data->mtu.mtu;
		break;
	case ESP_GATTS_CONF_EVT:
		break;
	case ESP_GATTS_UNREG_EVT:
		break;
	case ESP_GATTS_DELETE_EVT:
		break;
	case ESP_GATTS_START_EVT:
		break;
	case ESP_GATTS_STOP_EVT:
		break;
	case ESP_GATTS_CONNECT_EVT:
		spp_server_conn_id = p_data->connect.conn_id;
		spp_gatts_if = gatts_if;
		ble_run_mode = BLE_RUN_SERVER;
		is_server_connected = 1;
		ble_server_total_received = 0;
		ble_server_total_sent = 0;
		memcpy(&spp_remote_bda, &p_data->connect.remote_bda, sizeof(esp_bd_addr_t));
		ble_server_status = BLE_SERVER_PAIRED;
		ble_server_pairing_countdown = 10; // if the client does not send data util this value become 0, close the pairing. 
		break;
	case ESP_GATTS_DISCONNECT_EVT:
		ble_run_mode = BLE_RUN_NONE;
		is_server_connected = 0;
		enable_data_ntf = false;
		esp_ble_gap_start_advertising(&spp_adv_params);		
		ble_server_status = BLE_SERVER_LISTENING;
		break;
	case ESP_GATTS_OPEN_EVT:
		break;
	case ESP_GATTS_CANCEL_OPEN_EVT:
		break;
	case ESP_GATTS_CLOSE_EVT:
		break;
	case ESP_GATTS_LISTEN_EVT:
		break;
	case ESP_GATTS_CONGEST_EVT:
		break;
	case ESP_GATTS_CREAT_ATTR_TAB_EVT: {
		ESP_LOGI(BLE_TAG, "The number handle =%x\n", param->add_attr_tab.num_handle);
			if (param->add_attr_tab.status != ESP_GATT_OK) {
				ESP_LOGE(BLE_TAG, "Create attribute table failed, error code=0x%x", param->add_attr_tab.status);
			}
			else if (param->add_attr_tab.num_handle != SPP_IDX_NB) {
				ESP_LOGE(BLE_TAG, "Create attribute table abnormally, num_handle (%d) doesn't equal to HRS_IDX_NB(%d)", param->add_attr_tab.num_handle, SPP_IDX_NB);
			}
			else {
				memcpy(spp_handle_table, param->add_attr_tab.handles, sizeof(spp_handle_table));
				esp_ble_gatts_start_service(spp_handle_table[SPP_IDX_SVC]);
			}
			break;
		}
	default:
		break;
	}
}


static void gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param)
{
	ESP_LOGI(BLE_TAG, "EVT %d, gatts if %d\n", event, gatts_if);

	/* If event is register event, store the gatts_if for each profile */
	if (event == ESP_GATTS_REG_EVT) {
		if (param->reg.status == ESP_GATT_OK) {
			spp_profile_tab[ESP_SERVER_PROFILE_APP_IDX].gatts_if = gatts_if;
		}
		else {
			ESP_LOGI(BLE_TAG, "Reg app failed, app_id %04x, status %d\n", param->reg.app_id, param->reg.status);
			return;
		}
	}

	do {
		int idx;
		for (idx = 0; idx < BLE_SERVER_PROFILE_NUM; idx++) {
			if (gatts_if == ESP_GATT_IF_NONE || /* ESP_GATT_IF_NONE, not specify a certain gatt_if, need to call every profile cb function */
			        gatts_if == spp_profile_tab[idx].gatts_if) {
				if (spp_profile_tab[idx].gatts_cb) {
					spp_profile_tab[idx].gatts_cb(event, gatts_if, param);
				}
			}
		}
	} while (0);
}

//enabled bluetooth device
uint8_t ble_server_enable()
{	
	esp_ble_gatts_register_callback(gatts_event_handler);
	esp_ble_gatts_app_register(BLE_SERVER_APP_ID);
	
	systemconfig.bluetooth.server_enabled = 1;
	ble_server_total_received = 0;
	// initialize the buffer(Rx, Tx, Urgent Rx)
	communication_buffers_ble_init(BLE_PORT_ID, &bleServerDevice, ble_rx_buffer, ble_tx_buffer);
	return 1;
}

//disable bluetooth device
void ble_server_disable()
{
	//esp_bluedroid_disable();
	esp_ble_gatts_app_unregister(BLE_SERVER_APP_ID);
	systemconfig.bluetooth.server_enabled = 0;
}

// disconnect client
void ble_server_disconnect()
{
	if (!is_server_connected) return;
	esp_ble_gatts_close(spp_gatts_if, spp_server_conn_id);
}

//////////////////////////////////////////////////////////////////////////////
uint8_t ble_server_send_data(uint8_t* data, uint16_t size)
{
	if (!is_server_connected) return 0;
	ble_server_send_blink_count = 5;	
	ble_server_total_sent += size;
	esp_err_t err = esp_ble_gatts_send_indicate(spp_gatts_if, spp_server_conn_id, spp_handle_table[SPP_IDX_SPP_DATA_NTY_VAL], size, data, false);	
	if (err != ESP_OK) return 0;
	return 1;
}

void ble_server_received_data(uint8_t* data, uint16_t size)
{
	ble_server_receive_blink_count = 5;
	ble_server_total_received += size;
	//communication_process_rx_ble_characters(&bleServerDevice, data, size);	
	communication_add_buffer_to_ble_buffer(&bleServerDevice.RxBuffer, data, size);	
}
//////////////////////////////////////////////////////////////////////////////

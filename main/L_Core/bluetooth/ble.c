#include "main.h"
#include "ble.h"
#include "../ui/ui-bluetooth.h"

BLE_RUN_MODE ble_run_mode = BLE_RUN_NONE;
BleRemoteDevice ble_client_remote_device[BLE_CLIENT_MAX_CONNECT_NUM];
uint8_t ble_rx_buffer[RX_BUF_SIZE];
uint8_t ble_tx_buffer[TX_BUF_SIZE];
uint8_t connection_count = 0;
uint8_t ble_client_scaned_device_num = 0;
esp_ble_adv_params_t spp_adv_params = {
	.adv_int_min = 0x20,
	.adv_int_max = 0x40,
	.adv_type = ADV_TYPE_IND,
	.own_addr_type = BLE_ADDR_TYPE_PUBLIC,
	.channel_map = ADV_CHNL_ALL,
	.adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

static esp_ble_scan_params_t ble_scan_params = {
	.scan_type = BLE_SCAN_TYPE_PASSIVE,
	// change scan type to passive
	.own_addr_type = BLE_ADDR_TYPE_PUBLIC,
	.scan_filter_policy = BLE_SCAN_FILTER_ALLOW_ALL,
	//.scan_interval = 0xA,
	//.scan_window = 0x08,
    .scan_duplicate = BLE_SCAN_DUPLICATE_DISABLE
};
uint8_t ble_scan_status = BLE_CLIENT_SCAN_NOT_READY; 

static void gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param)
{	
	esp_err_t err;
	
	switch (event) {
		
	case ESP_GAP_BLE_ADV_DATA_RAW_SET_COMPLETE_EVT:
		esp_ble_gap_start_advertising(&spp_adv_params);
		break;
	case ESP_GAP_BLE_ADV_START_COMPLETE_EVT:
		//advertising start complete event to indicate advertising start successfully or failed
		if ((err = param->adv_start_cmpl.status) != ESP_BT_STATUS_SUCCESS) {
			//ESP_LOGE(BLE_TAG, "Advertising start failed: %s\n", esp_err_to_name(err));
		}
		break;
		// client side
	case ESP_GAP_BLE_SCAN_PARAM_SET_COMPLETE_EVT: {
        if((err = param->scan_param_cmpl.status) != ESP_BT_STATUS_SUCCESS){
	        //ESP_LOGE(BLE_TAG, "Scan param set failed: %s", esp_err_to_name(err));
            break;
        }
		//esp_ble_gap_set_scan_params(&ble_scan_params); // reset parameters
		
		ble_scan_status = BLE_CLIENT_SCAN_READY;
		ui_ble_changed_ble_status(ble_scan_status);
        //the unit of the duration is second
        //uint32_t duration = 0xFFFF;
		//ESP_LOGI(BLE_TAG, "Enable Ble Scan:during time %04" PRIx32 " minutes.", duration);
		//esp_ble_gap_start_scanning(BLE_CLIENT_SCAN_DURATION);
        break;
    }
    case ESP_GAP_BLE_SCAN_START_COMPLETE_EVT:
        //scan start complete event to indicate scan start successfully or failed
        if ((err = param->scan_start_cmpl.status) != ESP_BT_STATUS_SUCCESS) {
	        //ESP_LOGE(BLE_TAG, "Scan start failed: %s", esp_err_to_name(err));
            break;
        }
		// reset the remote device list information
		ble_client_scaned_device_num = 0;
		//memset(ble_client_remote_device, 0, sizeof(BleRemoteDevice) * BLE_CLIENT_MAX_CONNECT_NUM);
		ble_scan_status = BLE_CLIENT_SCANNING;
		ESP_LOGI(BLE_TAG, "Scan start successed");
		ui_ble_changed_ble_status(ble_scan_status);
        break;
    case ESP_GAP_BLE_SCAN_STOP_COMPLETE_EVT:
		ESP_LOGI(BLE_TAG, "Scan stop successed");
		ble_scan_status = BLE_CLIENT_SCAN_READY;
		ui_ble_changed_ble_status(ble_scan_status);
        break;
    case ESP_GAP_BLE_SCAN_RESULT_EVT: {
        esp_ble_gap_cb_param_t *scan_result = (esp_ble_gap_cb_param_t *)param;
        switch (scan_result->scan_rst.search_evt) {
        case ESP_GAP_SEARCH_INQ_RES_EVT:
	        ble_add_scan_device(scan_result);
            break;
        case ESP_GAP_SEARCH_INQ_CMPL_EVT:
            break;
        default:
            break;
        }
        break;
    }
    case ESP_GAP_BLE_ADV_STOP_COMPLETE_EVT:
        if ((err = param->adv_stop_cmpl.status) != ESP_BT_STATUS_SUCCESS){
	        ESP_LOGE(BLE_TAG, "Adv stop failed: %s", esp_err_to_name(err));
        }else {
	        ESP_LOGI(BLE_TAG, "Stop adv successfully");
        }
        break;
	default:
		break;
	}
}
uint8_t ble_add_scan_device(esp_ble_gap_cb_param_t* scan_result) {
	if (ble_client_scaned_device_num >= BLE_CLIENT_MAX_CONNECT_NUM) return 0;
	uint8_t *adv_name = NULL;
	uint8_t adv_name_len = 0;
	adv_name = esp_ble_resolve_adv_data(scan_result->scan_rst.ble_adv, ESP_BLE_AD_TYPE_NAME_CMPL, &adv_name_len);
	if(!adv_name) return 0;
	if(!strstr((char*)adv_name, BLE_SERVER_DEVICE_NAME)) return 0; // that is not the device what we want.
	
	BleRemoteDevice* device;
	for(uint8_t i = 0; i < ble_client_scaned_device_num; i ++) 
	{
		device = &ble_client_remote_device[i];
		if(!memcmp(device->scan_result.scan_rst.bda, scan_result->scan_rst.bda, 6))
		{
			// that is same device
			return 0;
		}
	}
	strcpy(ble_client_remote_device[ble_client_scaned_device_num].device_name, (const char*)adv_name);
	sprintf(ble_client_remote_device[ble_client_scaned_device_num].address, "%02x-%02x-%02x-%02x-%02x-%02x", 
							scan_result->scan_rst.bda[0], scan_result->scan_rst.bda[1],scan_result->scan_rst.bda[2],
							scan_result->scan_rst.bda[3], scan_result->scan_rst.bda[4],scan_result->scan_rst.bda[5]);
	memcpy(&(ble_client_remote_device[ble_client_scaned_device_num].scan_result), scan_result, sizeof(esp_ble_gap_cb_param_t));
	ble_client_remote_device[ble_client_scaned_device_num].id = ble_client_scaned_device_num;
	ble_client_remote_device[ble_client_scaned_device_num].is_scaned = 1;
	ble_client_remote_device[ble_client_scaned_device_num].total_sent = 0;
	ble_client_remote_device[ble_client_scaned_device_num].total_received = 0;
	ui_ble_add_device(&ble_client_remote_device[ble_client_scaned_device_num]);	
	ble_client_scaned_device_num++;
	return 1;
}
void ble_init()
{
	esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
	
	ESP_ERROR_CHECK(esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT));
	esp_bt_controller_init(&bt_cfg);
	esp_bt_controller_enable(ESP_BT_MODE_BLE);
	
	esp_bluedroid_init();	
	
	ble_enable();
}

void ble_update_name(int address)
{
	// set the device name with channel index
	char a = address / 10;
	char b = address % 10;
	raw_scan_rsp_data[11] = '0' + a; //the second place from last point
	raw_scan_rsp_data[12] = '0' + b; // the last point
	esp_ble_gap_config_scan_rsp_data_raw(raw_scan_rsp_data, BLE_RAW_RSP_DATA_SIZE);
	
	ui_ble_set_servername((char*)(raw_scan_rsp_data + 2)); //it should start from 2 byte.
}
	
//enabled bluetooth device
uint8_t ble_enable()
{
	esp_err_t ret;
	
	
	ret = esp_bluedroid_enable();
	if (ret) {
		ESP_LOGE(TAG, "%s enable bluetooth failed: %s\n", __func__, esp_err_to_name(ret));
		return 0;
	}
	ble_scan_status	= BLE_CLIENT_SCAN_NOT_READY;
	esp_ble_gap_register_callback(gap_event_handler);
	esp_ble_gap_set_scan_params(&ble_scan_params);
	
	ble_server_enable();
	ble_client_enable();
	ble_scan_status = BLE_CLIENT_SCAN_READY;
	systemconfig.bluetooth.status = 1;
	
	return 1;
}

//disable bluetooth device
void ble_disable()
{
	esp_bluedroid_disable();
	ble_server_disable();
	ble_client_disable();
	systemconfig.bluetooth.status = 0;
}


void ble_scan_start() {
	if (ble_scan_status != BLE_CLIENT_SCAN_READY) return; // Do nothing because it is not ready for scaning device
	esp_ble_gap_start_scanning(BLE_CLIENT_SCAN_DURATION);
}

void ble_scan_stop() {
	esp_ble_gap_stop_scanning();
}

BleRemoteDevice* ble_client_get_device_by_address(uint8_t* address) {
    BleRemoteDevice* dev = NULL;
    for(uint8_t i = 0; i < ble_client_scaned_device_num; i ++) {
        dev = &ble_client_remote_device[i];
        if(!memcmp(dev->scan_result.scan_rst.bda, address, 6)) {
            return dev;
        }
    }
    return NULL;
}

BleRemoteDevice* ble_client_get_device_by_conn_id(uint16_t conn_id) {
	BleRemoteDevice* dev = NULL;
	for (uint8_t i = 0; i < ble_client_scaned_device_num; i++) {
		dev = &ble_client_remote_device[i];
		if (dev->conn_id == conn_id) {
			return dev;
		}
	}
	return NULL;
}

	

BleRemoteDevice* ble_get_device(uint8_t id)
{
	return &ble_client_remote_device[id];
}


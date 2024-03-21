#include "L_Core/ui/ui.h"
#include "L_Core/ui/ui-bluetooth.h"
#include "tools.h"
#include "L_Core/storage/nvs.h"
#include "L_Core/bluetooth/ble.h"
#include "K_Core/communication/communication.h"

ToolInfo toolInfo = { 0 };
char tempstring[256] = { 0 };

void tools_init()
{
	//storage_partition_read(STORAGE_ADDRESS_TOOLINFO, (uint8_t*)&toolInfo, sizeof(ToolInfo));
	storage_nvs_get_blob(NVS_KEY_TOOLINFO, &toolInfo);
}

void tools_report_information()
{
	if (ble_server_status < BLE_SERVER_CONNECTED) return;
	memset(tempstring, 0, 256);
	sprintf(tempstring, ">RT:T%d %d %d %d %d\n", toolInfo.Address, toolInfo.ActualTemperature, toolInfo.ActualHeaterDutyCycle, toolInfo.ActualFanDutyCycle, toolInfo.ActualAux);
	communication_add_string_to_ble_buffer(&bleServerDevice.TxBuffer, tempstring);
}

void tools_report_register()
{
	if (ble_server_status != BLE_SERVER_HEADSET)	ble_server_status = BLE_SERVER_CONNECTED;
	memset(tempstring, 0, 256);
	sprintf(tempstring, ">RG:%d\n", toolInfo.Address);
	communication_add_string_to_ble_buffer(&bleServerDevice.TxBuffer, tempstring);
}

void tools_report_unregister()
{
	if (ble_server_status < BLE_SERVER_CONNECTED) return;
	memset(tempstring, 0, 256);
	sprintf(tempstring, ">RM:%d\n", toolInfo.Address);
	communication_add_string_to_ble_buffer(&bleServerDevice.TxBuffer, tempstring);
}


#include "main.h"
#include "K_Core/K_Core.h"
#include "L_Core/bluetooth/ble.h"
#include "L_Core/storage/partition.h"
#include "L_Core/storage/nvs.h"
#include "L_Core/sd-card/sd-card.h"
#include "L_Core/server/server.h"
#ifdef USE_OPC
#include "L_Core/open62541/opc.h"
#endif
#include "L_Core/devices/display.h"
#include "L_Core/ui/ui.h"
#include "K_Core/display/DisplayList.h"
const char *TAG = "L_Core";
bool IsInitialized = false;
SYSTEMCONFIG systemconfig;
extern "C" void app_main(void)
{
	//esp_log_level_set(TAG, ESP_LOG_DEBUG); // enable DEBUG logs for this App
    //Initialize NVS
	esp_err_t ret = nvs_flash_init();
//	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
//		ESP_ERROR_CHECK(nvs_flash_erase());
//		ret = nvs_flash_init();
//	}
//	ESP_ERROR_CHECK(ret);
	
	IsInitialized = false;
	
	// storage_partition_init();
	storage_nvs_init();
	load_configuration();
	if (sdcard_init())
	{	
		if (systemconfig.sdcard.automount)
		{	
			systemconfig.sdcard.status = sdcard_mount();		
		}
	}
	
	ble_init();
	
	InitLCDAndLVGL();
	InitUI();
	K_Core_Main();
	
	IsInitialized = true;
}

char* parseValue(char* line)
{
	char* p = strstr(line, "=");
	if (!p) return NULL;
	return p + 1;
}
bool load_configuration()
{
	storage_nvs_get_blob(NVS_KEY_CONFIG, &systemconfig);
	if (!systemconfig.serial.baud) systemconfig.serial.baud = SERIAL_BAUD_RATE;
	if (!systemconfig.serial.rx_pin) systemconfig.serial.rx_pin = SERIAL_UART1_RXD_PIN;
	if (!systemconfig.serial.tx_pin) systemconfig.serial.tx_pin = SERIAL_UART1_TXD_PIN;
	return true;
}
bool load_configu_from_ssd() {
	if (!systemconfig.sdcard.status)	return false;
	FILE* fp = fopen(SYSTEM_CONFIG_FILE, "rt");
	if (!fp) return false;
	char line[256] = { 0 };
	char* value;
	uint8_t session = 0;
	enum
	{
		SESSION_SDCARD    = 1,
		SESSION_WIFI,
		SESSION_BLUETOOTH,
		SESSION_OPC,
	};
	while (fgets(line, 256, fp))
	{
		if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = 0;
		if (!strcmp(line, "[sdcard]")) session = SESSION_SDCARD;
		else if (!strcmp(line, "[wifi]")) session = SESSION_WIFI;
		else if (!strcmp(line, "[bluetooth]")) session = SESSION_BLUETOOTH;
		else if (!strcmp(line, "[opc]")) session = SESSION_OPC;
		else
		{
			switch (session)
			{
			case SESSION_SDCARD:
				if (strstr(line, "automount"))
				{
					value = parseValue(line); if (value) systemconfig.sdcard.automount = atoi(value);
				}
				break;
			case SESSION_WIFI:
				if (strstr(line, "autoconnect"))
				{
					value = parseValue(line); if (value) systemconfig.wifi.autoconnect = atoi(value);
				}
				else if (strstr(line, "ssid"))
				{
					value = parseValue(line); if (value) strcpy((char*)systemconfig.wifi.ssid, value);
				}
				else if (strstr(line, "password"))
				{
					value = parseValue(line); if (value) strcpy((char*)systemconfig.wifi.password, value);
				}				
				break;
			case SESSION_BLUETOOTH:
				if (strstr(line, "autostart"))
				{
					value = parseValue(line); if (value) systemconfig.bluetooth.autostart = atoi(value);
				}
				break;
			case SESSION_OPC:
				if (strstr(line, "autostart"))
				{
					value = parseValue(line); if (value) systemconfig.opc.autostart = atoi(value);
				}
				else if (strstr(line, "username"))
				{
					value = parseValue(line); if (value) strcpy((char*)systemconfig.opc.username, value);
				}
				else if (strstr(line, "userpassword"))
				{
					value = parseValue(line); if (value) strcpy((char*)systemconfig.opc.userpassword, value);
				}
				break;
			default:
				break;
			}
		}
	}
	fclose(fp);
	return true;
}
bool save_configuration()
{
	systemconfig.initialized = 1;
	return storage_nvs_set_blob(NVS_KEY_CONFIG, &systemconfig, sizeof(SYSTEMCONFIG));
	//return storage_partition_write(STORAGE_ADDRESS_SETTINGS, &systemconfig, sizeof(SYSTEMCONFIG));
}
bool save_configu_to_ssd() {
	if (!systemconfig.sdcard.status)	return false;
	FILE* fp = fopen(SYSTEM_CONFIG_FILE, "wt");
	if (!fp) return false;
	
	char line[256] = { 0 };
	// sd-card
	strcpy(line, "[sdcard]\n"); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "automount=%d\n", systemconfig.sdcard.automount); fwrite(line, 1, strlen(line), fp);
	
	strcpy(line, "[wifi]\n"); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "autoconnect=%d\n", systemconfig.wifi.autoconnect); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "ssid=%s\n", systemconfig.wifi.ssid); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "password=%s\n", systemconfig.wifi.password); fwrite(line, 1, strlen(line), fp);
	
	strcpy(line, "[bluetooth]\n"); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "autostart=%d\n", systemconfig.bluetooth.autostart); fwrite(line, 1, strlen(line), fp);
	
	strcpy(line, "[opc]\n"); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "autostart=%d\n", systemconfig.opc.autostart); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "username=%s\n", systemconfig.opc.username); fwrite(line, 1, strlen(line), fp);
	sprintf(line, "userpassword=%s\n", systemconfig.opc.userpassword); fwrite(line, 1, strlen(line), fp);
	fclose(fp);
	return true;
}



char *trim(char *s) {
	char *ptr;
	if (!s)
		return NULL;   // handle NULL string
	if (!*s)
		return s;      // handle empty string
	for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr) ;
	ptr[1] = '\0';
	return s;
}

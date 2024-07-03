#pragma  once
#include "main.h"


#define NVS_KEY_CONFIG		"config"
#define NVS_KEY_TOOLINFO	"toolinfo"
#define NVS_KEY_SOAPSTRING	"soapstring"

bool storage_nvs_init();
size_t storage_nvs_get_blob(char* key, void* data);
bool storage_nvs_set_blob(char* key, void* data, size_t len);
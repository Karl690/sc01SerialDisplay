#include "nvs.h"
#include "esp_partition.h"

nvs_handle_t storage_nvs_handle;
esp_partition_mmap_handle_t map_handle;
	
bool storage_nvs_init()
{
	esp_err_t err = nvs_open("storage", NVS_READWRITE, &storage_nvs_handle);
	return err == ESP_OK ? true : false;
}

size_t storage_nvs_get_blob(char* key, void* data)
{
	size_t size = 0;
	
	esp_err_t err = nvs_get_blob(storage_nvs_handle, key, NULL, &size);
	
	err = nvs_get_blob(storage_nvs_handle, key, data, &size);
	return err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND ? 0: size;
}

bool storage_nvs_set_blob(char* key, void* data, size_t len)
{
	esp_err_t err = nvs_set_blob(storage_nvs_handle, key, data, len);
	if (err != ESP_OK) return false;
	return nvs_commit(storage_nvs_handle) == ESP_OK ? true : false;
}
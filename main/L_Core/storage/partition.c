#include "partition.h"
#include "esp_partition.h"

const esp_partition_t *partition;
void storage_partition_init()
{
	partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, "storage");	
}

bool storage_partition_erase()
{
	return esp_partition_erase_range(partition, 0, partition->size) == ESP_OK?true: false;
}

bool storage_partition_read(uint32_t address, void* data, size_t len)
{
	return esp_partition_read(partition, address, data, len) == ESP_OK ? true : false;
}

bool storage_partition_write(uint32_t address, void* data, size_t len)
{
	/*Before writing data to flash, corresponding region of flash needs to be erased. This can be done using esp_partition_erase_range function.	all write offsets and lengths must be multiples of 16 bytes.
	*/
	uint32_t erase_size = len % partition->erase_size == 0 ? len : (len / partition->erase_size + 1) * partition->erase_size;
	esp_partition_erase_range(partition, address, erase_size); 
	return esp_partition_write(partition, address, data, len) == ESP_OK ? true : false;
}



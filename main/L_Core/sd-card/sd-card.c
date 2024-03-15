#include "sd-card.h"

esp_vfs_fat_sdmmc_mount_config_t mount_config = {
#ifdef CONFIG_EXAMPLE_FORMAT_IF_MOUNT_FAILED
	.format_if_mount_failed = true,
#else
	.format_if_mount_failed = false,
#endif // EXAMPLE_FORMAT_IF_MOUNT_FAILED
	.max_files = 5,
	.allocation_unit_size = 16 * 1024
};
sdmmc_host_t host = SDSPI_HOST_DEFAULT();
bool sdcard_init()
{
	ESP_LOGI(TAG, "Initializing SD card");

	// Use settings defined above to initialize SD card and mount FAT filesystem.
	// Note: esp_vfs_fat_sdmmc/sdspi_mount is all-in-one convenience functions.
	// Please check its source code and implement error recovery when developing
	// production applications.
	ESP_LOGI(TAG, "Using SPI peripheral");

	
	spi_bus_config_t bus_cfg = {
		.mosi_io_num = PIN_NUM_MOSI,
		.miso_io_num = PIN_NUM_MISO,
		.sclk_io_num = PIN_NUM_CLK,
		.quadwp_io_num = -1,
		.quadhd_io_num = -1,
		.max_transfer_sz = 4000,
	};
	if (spi_bus_initialize((spi_host_device_t)host.slot, &bus_cfg, SDSPI_DEFAULT_DMA) != ESP_OK) {
		ESP_LOGE(TAG, "Failed to initialize bus.");
		return false;
	}
	return true;
}
bool sdcard_mount()
{
	esp_err_t ret;
	sdmmc_card_t *card;
	// Options for mounting the filesystem.
	// If format_if_mount_failed is set to true, SD card will be partitioned and
	// formatted in case when mounting fails.
	
	// This initializes the slot without card detect (CD) and write protect (WP) signals.
	// Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
	sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
	slot_config.gpio_cs = PIN_NUM_CS;
	slot_config.host_id = (spi_host_device_t)host.slot;

	ESP_LOGI(TAG, "Mounting filesystem");
	ret = esp_vfs_fat_sdspi_mount(SDCARD_MOUNT_POINT, &host, &slot_config, &mount_config, &card);

	if (ret != ESP_OK) {
		if (ret == ESP_FAIL) {
			ESP_LOGE(TAG,
				"Failed to mount filesystem. "
			         "If you want the card to be formatted, set the CONFIG_EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
		}
		else {
			ESP_LOGE(TAG,
				"Failed to initialize the card (%s). "
			         "Make sure SD card lines have pull-up resistors in place.",
				esp_err_to_name(ret));
		}
		return false;
	}
	ESP_LOGI(TAG, "Filesystem mounted");
	return true;
}

void sdcard_umount()
{
	esp_vfs_fat_sdmmc_unmount();
}

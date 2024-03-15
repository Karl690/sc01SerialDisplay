#pragma once
#include "main.h"
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"

#define PIN_NUM_MISO   GPIO_NUM_38//CONFIG_EXAMPLE_PIN_MISO
#define PIN_NUM_MOSI   GPIO_NUM_40//CONFIG_EXAMPLE_PIN_MOSI
#define PIN_NUM_CLK   GPIO_NUM_39//CONFIG_EXAMPLE_PIN_CLK
#define PIN_NUM_CS    GPIO_NUM_41//CONFIG_EXAMPLE_PIN_CS

bool sdcard_init();
bool sdcard_mount();
void sdcard_umount();
#pragma once
#include "ui.h"

#define UP_DIRECTORY ".."
extern char current_sdcard_path[];
extern lv_obj_t* ui_sdcard_screen;

void ui_sdcard_screen_init(void);
void ui_sdcard_load_directory(const char*);
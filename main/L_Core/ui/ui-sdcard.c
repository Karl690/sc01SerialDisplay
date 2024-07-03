#include "ui.h"
#include "ui-sdcard.h"
#include <dirent.h> 
#include <stdio.h>

#include "../sd-card/sd-card.h"

lv_obj_t* ui_sdcard_screen;
lv_obj_t* ui_sdcard_folders_panel;
lv_obj_t* ui_sdcard_files_panel;
lv_obj_t* title_label;
char current_sdcard_path[MAXNAMLEN + 1] = SDCARD_MOUNT_POINT;
void event_goto_directory_cb(lv_event_t* e)
{
	char* dir_name = (char*)lv_event_get_user_data(e);
	//(char*)obj->user_data;
	if (!dir_name) return;
	char new_path[MAXNAMLEN + MAXNAMLEN] = { 0 };
	if (!strcmp(dir_name, UP_DIRECTORY))
	{	
		uint16_t i = 0;
		for (i = strlen(current_sdcard_path); i >= 0; i--)
		{
			if (current_sdcard_path[i] == '/') break;			
		}
		if (i > 0) {
			strncpy(new_path, current_sdcard_path, i);
			ui_sdcard_load_directory(new_path);
		}
	}
	else
	{
		sprintf(new_path, "%s/%s", current_sdcard_path, dir_name);
		ui_sdcard_load_directory(new_path);
	}
}
void ui_sdcard_screen_init(void)
{
	ui_sdcard_screen = ui_create_screen();	
	lv_obj_t* titlebar = ui_create_titlebar(ui_sdcard_screen, TITLEBAR_BACKGROUND_COLOR);
	
	title_label = lv_label_create(titlebar);	
	lv_obj_set_width(title_label, LV_SIZE_CONTENT);
	lv_obj_set_height(title_label, LV_SIZE_CONTENT);
	lv_label_set_recolor(title_label, true);
	lv_obj_set_style_text_color(title_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
	lv_label_set_text(title_label, "SD Card [" SDCARD_MOUNT_POINT "]");
	lv_obj_set_style_text_font(title_label, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);	
	lv_obj_align(title_label, LV_ALIGN_CENTER, 0, 0);
	
	ui_sdcard_folders_panel = lv_obj_create(ui_sdcard_screen);
	lv_obj_set_style_pad_all(ui_sdcard_folders_panel, 2, LV_PART_MAIN);
	lv_obj_set_size(ui_sdcard_folders_panel, 210, 275);
	lv_obj_set_pos(ui_sdcard_folders_panel, 3, 45);
	
	ui_sdcard_files_panel = lv_obj_create(ui_sdcard_screen);
	lv_obj_set_style_pad_all(ui_sdcard_files_panel, 2, LV_PART_MAIN);
	lv_obj_set_size(ui_sdcard_files_panel, 261, 275);
	lv_obj_set_pos(ui_sdcard_files_panel, 216, 45);
}

void ui_sdcard_add_directory(const char* path, uint16_t index)
{
	lv_obj_t* obj = lv_obj_create(ui_sdcard_folders_panel);
	lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
	lv_obj_set_style_pad_all(obj, 2, LV_PART_MAIN);
	lv_obj_set_size(obj, LV_PCT(100), 30);
	lv_obj_set_pos(obj, 5, (30 + 5) * index);
	
	lv_obj_t* label = lv_label_create(obj);
	lv_label_set_text_fmt(label, LV_SYMBOL_DIRECTORY " %s", path);
	lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
	char* dir_path = (char*)malloc(MAXNAMLEN);
	strcpy(dir_path, path);
	obj->user_data = (void*)dir_path;
	lv_obj_add_event_cb(obj, event_goto_directory_cb, LV_EVENT_CLICKED, (void*)dir_path);
}


void ui_sdcard_add_file(const char* path, uint16_t index)
{
	lv_obj_t* obj = lv_obj_create(ui_sdcard_files_panel);
	lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
	lv_obj_set_style_pad_all(obj, 2, LV_PART_MAIN);
	lv_obj_set_size(obj, LV_PCT(100), 30);
	lv_obj_set_pos(obj, 5, (30 + 5) * index);
	
	lv_obj_t* label = lv_label_create(obj);
	lv_label_set_text_fmt(label, LV_SYMBOL_FILE " %s", path);
	lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
	obj->user_data = (void*)path;
}

void ui_sdcard_load_directory(const char* path)
{
	strcpy(current_sdcard_path, path);
	lv_label_set_text_fmt(title_label, "SD Card [%s]", current_sdcard_path);
	lv_obj_clean(ui_sdcard_folders_panel);
	lv_obj_clean(ui_sdcard_files_panel);
			
	DIR * d = opendir(path); // open the path
	if (d == NULL) return; // if was not able, return
	struct dirent * dir; // for the directory entries
	uint16_t cnt_folder = 0;
	uint16_t cnt_file = 0;
	ui_sdcard_add_directory("..", cnt_folder);
	cnt_folder++;
	while ((dir = readdir(d)) != NULL) // if we were able to read somehting from the directory
	{
		if (dir->d_type != DT_DIR) // if the type is not directory just print it with blue color
		{
			ui_sdcard_add_file(dir->d_name, cnt_file);
			cnt_file++;
		}
		else if(dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) // if it is a directory 
		{	
			ui_sdcard_add_directory(dir->d_name, cnt_folder);
			cnt_folder++;
		}
	}
	closedir(d); // finally close the directory
}


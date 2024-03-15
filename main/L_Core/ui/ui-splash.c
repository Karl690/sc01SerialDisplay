#include "ui.h"
#include "ui-splash.h"
lv_obj_t* ui_splash_screen;


LV_IMG_DECLARE(img_mark);
///////////////////// SCREENS ////////////////////
void ui_splash_screen_init(void)
{
	ui_splash_screen = lv_obj_create(NULL);
	lv_obj_clear_flag(ui_splash_screen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_splash_screen, lv_color_hex(UI_BACKGROUND_COLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_splash_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	
	lv_obj_t * img = lv_img_create(ui_splash_screen);
	lv_img_set_src(img, &img_mark);
	lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);	

	lv_obj_t* banner = ui_create_label(ui_splash_screen, "#ffffff ©2023, PCT Systems. All rights reserved. #", &mono_regualr_16);
	lv_obj_align(banner, LV_ALIGN_BOTTOM_MID, 0, -10);
}

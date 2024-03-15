#include "ui.h"
#include "ui-control.h"
lv_obj_t* ui_control_screen;

void ui_control_button_handler(lv_event_t * e) {
	lv_event_code_t event_code = lv_event_get_code(e); 
	lv_obj_t * target = lv_event_get_target(e);	
}

void ui_control_screen_init()
{
	ui_control_screen = ui_create_screen();	
	lv_obj_t* titlebar = ui_create_titlebar(ui_control_screen, TITLEBAR_BACKGROUND_COLOR);
	
	lv_obj_t* title_label = lv_label_create(titlebar);	
	lv_obj_set_width(title_label, LV_SIZE_CONTENT);
	lv_obj_set_height(title_label, LV_SIZE_CONTENT);
	lv_label_set_recolor(title_label, true);
	lv_obj_set_style_text_color(title_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
	lv_label_set_text(title_label, "CONTROL");
	lv_obj_set_style_text_font(title_label, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);	
	lv_obj_align(title_label, LV_ALIGN_CENTER, 0, 0);
	
	LV_IMG_DECLARE(heater);
	LV_IMG_DECLARE(fan);
	LV_IMG_DECLARE(mtr);
	
	lv_obj_t* obj = lv_img_create(ui_control_screen);
	lv_img_set_src(obj, &fan);
	lv_img_set_zoom(obj, 350);
	lv_obj_align(obj, LV_ALIGN_CENTER, -160, 0);
	
	obj = lv_img_create(ui_control_screen);
	lv_img_set_src(obj, &heater);
	lv_img_set_zoom(obj, 395);
	lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
	
	obj = lv_img_create(ui_control_screen);
	lv_img_set_src(obj, &mtr);
	lv_img_set_zoom(obj, 450);
	lv_obj_align(obj, LV_ALIGN_CENTER, 170, 0);
	
	obj = ui_create_button(ui_control_screen, "+", 100, 40, 5, &lv_font_montserrat_30, ui_control_button_handler, (void*)CONTROLS_FAN_PLUS);
	lv_obj_align(obj, LV_ALIGN_CENTER, -160, -100);
	obj = ui_create_label(ui_control_screen, "5%", &lv_font_montserrat_24);
	lv_obj_align(obj, LV_ALIGN_CENTER, -160, -60);
	
	obj = ui_create_label(ui_control_screen, "FAN", &lv_font_montserrat_16);
	lv_obj_align(obj, LV_ALIGN_CENTER, -160, 60);
	
	obj = ui_create_label(ui_control_screen, "35%", &lv_font_montserrat_24);
	lv_obj_align(obj, LV_ALIGN_CENTER, -160, 90);
	obj = ui_create_button(ui_control_screen, "-", 100, 40, 5, &lv_font_montserrat_30, ui_control_button_handler, (void*)CONTROLS_FAN_MINUS);	
	lv_obj_align(obj, LV_ALIGN_CENTER, -160, 130);
	
	
	obj = ui_create_button(ui_control_screen, "+", 100, 40, 5, &lv_font_montserrat_30, ui_control_button_handler, (void*)CONTROLS_HEAT_MINUS);
	lv_obj_align(obj, LV_ALIGN_CENTER, 0, -100);
	obj = ui_create_label(ui_control_screen, "0`C", &lv_font_montserrat_24);
	lv_obj_align(obj, LV_ALIGN_CENTER, 0, -60);
	
	obj = ui_create_label(ui_control_screen, "HEAT", &lv_font_montserrat_16);
	lv_obj_align(obj, LV_ALIGN_CENTER, 0, 60);
	
	obj = ui_create_label(ui_control_screen, "234`C", &lv_font_montserrat_24);
	lv_obj_align(obj, LV_ALIGN_CENTER, 0, 90);
	obj = ui_create_button(ui_control_screen, "-", 100, 40, 5, &lv_font_montserrat_30, ui_control_button_handler, (void*)CONTROLS_HEAT_MINUS);	
	lv_obj_align(obj, LV_ALIGN_CENTER, 0, 130);
	
	obj = ui_create_button(ui_control_screen, "+", 100, 40, 5, &lv_font_montserrat_30, ui_control_button_handler, (void*)CONTROLS_HEAT_PLUS);
	lv_obj_align(obj, LV_ALIGN_CENTER, 160, -100);
	obj = ui_create_label(ui_control_screen, "0", &lv_font_montserrat_24);
	lv_obj_align(obj, LV_ALIGN_CENTER, 160, -60);
	
	obj = ui_create_label(ui_control_screen, "MTR", &lv_font_montserrat_16);
	lv_obj_align(obj, LV_ALIGN_CENTER, 160, 60);
	
	obj = ui_create_label(ui_control_screen, "1000", &lv_font_montserrat_24);
	lv_obj_align(obj, LV_ALIGN_CENTER, 160, 90);
	obj = ui_create_button(ui_control_screen, "-", 100, 40, 5, &lv_font_montserrat_30, ui_control_button_handler, (void*)CONTROLS_MTR_MINUS);	
	lv_obj_align(obj, LV_ALIGN_CENTER, 160, 130);
}
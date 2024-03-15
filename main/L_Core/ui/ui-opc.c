#ifdef USE_OPC
#include "ui.h"
#include "ui-opc.h"
#include <stdio.h>
#include "L_Core/open62541/opc.h"
#include "K_Core/display/DisplayList.h"

lv_obj_t *ui_opc_screen;

lv_obj_t * variableContainer;

uint8_t DisplayIndex = 0;
DisplayVariableInfo* activeVarialbeInfo = NULL;

void ui_event_start_button_handler(lv_event_t * e) {
	lv_event_code_t event_code = lv_event_get_code(e); 
	lv_obj_t * target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED) {
		OpcRunning = true;
	}
}

void ui_event_stop_button_handler(lv_event_t * e) {
	lv_event_code_t event_code = lv_event_get_code(e); 
	lv_obj_t * target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED) {
		OpcRunning = false;
	}
}

void ui_event_display_prev_button_handler(lv_event_t * e)
{
	lv_event_code_t event_code = lv_event_get_code(e); 
	lv_obj_t * target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED) {
		ui_opc_display_prev();
	}
}
void ui_event_display_next_button_handler(lv_event_t * e)
{
	lv_event_code_t event_code = lv_event_get_code(e); 
	lv_obj_t * target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED) {
		ui_opc_display_next();
	}
}

static void draw_table_part_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);
	lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
	/*If the cells are drawn...*/
	if (dsc->part == LV_PART_ITEMS) {
		uint32_t row = dsc->id /  lv_table_get_col_cnt(obj);
		uint32_t col = dsc->id - row * lv_table_get_col_cnt(obj);

		/*Make the texts in the first cell center aligned*/
//		if (row == 0) {
//			dsc->label_dsc->align = LV_TEXT_ALIGN_CENTER;
//			dsc->rect_dsc->bg_color = lv_color_mix(lv_palette_main(LV_PALETTE_BLUE), dsc->rect_dsc->bg_color, LV_OPA_20);
//			dsc->rect_dsc->bg_opa = LV_OPA_COVER;
//		}
		/*In the first column align the texts to the right*/
//		else if(col == 0) {
//			dsc->label_dsc->align = LV_TEXT_ALIGN_RIGHT;
//		}

		/*MAke every 2nd row grayish*/
		if ((row != 0 && row % 2) == 0) {
			dsc->rect_dsc->bg_color = lv_color_mix(lv_palette_main(LV_PALETTE_GREY), dsc->rect_dsc->bg_color, LV_OPA_10);
			dsc->rect_dsc->bg_opa = LV_OPA_COVER;
		}
	}
}

void ui_opc_screen_init(void) 
{
	ui_opc_screen = lv_obj_create(NULL);	
	lv_style_t style_label;
	lv_style_init(&style_label);	
	
	lv_obj_clear_flag(ui_opc_screen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	
	lv_obj_set_style_bg_color(ui_opc_screen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_opc_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	
	
	lv_obj_t* obj = ui_create_label(ui_opc_screen, "#ffff00 OPC #",  &lv_font_montserrat_38);
	lv_obj_set_align(obj, LV_ALIGN_TOP_MID);
	
	
	lv_obj_t* button = ui_create_button(ui_opc_screen, "<<", 40, 30, 6, 0x00A3FF, &lv_font_montserrat_20, ui_event_display_prev_button_handler);
	lv_obj_set_pos(button, 10, 5);
	button = ui_create_button(ui_opc_screen, ">>", 40, 30, 6, 0x00A3FF, &lv_font_montserrat_20, ui_event_display_next_button_handler);
	lv_obj_set_pos(button, 320-40-10, 5);
	
	
	button = ui_create_button(ui_opc_screen, "START", 150, 30, 6, 0x00A3FF, &lv_font_montserrat_20, ui_event_start_button_handler);
	lv_obj_set_pos(button, 10, 430);
	button = ui_create_button(ui_opc_screen, "STOP", 150, 30, 6, 0x565656, &lv_font_montserrat_20, ui_event_stop_button_handler);
	lv_obj_set_pos(button, 165, 430);
	
	
	variableContainer = lv_table_create(ui_opc_screen);
	lv_obj_set_size(variableContainer, 310, 370);
//	lv_obj_set_style_pad_all(variableContainer, 0, LV_PART_MAIN);
//	lv_obj_set_align(variableContainer, LV_ALIGN_TOP_MID);
	lv_obj_set_y(variableContainer, 50);
	
	//lv_obj_add_event_cb(variableContainer, draw_table_part_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
	
	
	ui_opc_set_display_variable(LcdVarsTable);
}

lv_list_item* ui_listitem_create(lv_obj_t* parent, char* label, DISPLAYFUNCTYPE type, const lv_font_t* font, uint16_t w, uint16_t h, lv_color_t bgColor)
{
	lv_list_item * listitem = (lv_list_item*)lv_mem_alloc(sizeof(lv_list_item));
	lv_obj_t* item = lv_obj_create(parent);
	lv_obj_set_size(item, w, h);
	lv_obj_clear_flag(item, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_style_pad_all(item, 0, LV_PART_MAIN);
	lv_obj_set_style_border_width(item, 0, LV_PART_MAIN);
	lv_obj_set_style_bg_color(item, bgColor, LV_PART_MAIN);
	
	lv_obj_t* lbl = ui_create_label(item, label, font);
	lv_obj_set_size(lbl, w / 2, h);
	
	lv_obj_set_pos(lbl, 5, 10);
	lv_obj_t* value;
	switch (type)
	{
	case FUNC_BOOLEAN:
		value = lv_led_create(item);		
		break;
	default:
		value = lv_label_create(item);
		lv_label_set_recolor(value, true);
		lv_label_set_text(value, "");
		lv_obj_set_size(value, w / 2, h);
		break;
	}
	if (value)
	{
		lv_obj_set_pos(value, w/2+10, 10);	
	}
	listitem->obj = item;
	listitem->label = lbl;
	listitem->value = value;
	return listitem;
}

void ui_opc_add_varialbeList(lv_obj_t* parent, DisplayVariableInfo* variableList)
{
	uint16_t w = lv_obj_get_width(parent) - 20;
	uint16_t h = 40;
	uint16_t i = 0;
	while (variableList[i].VariablePointer)
	{	
		lv_list_item* item = ui_listitem_create(parent, variableList[i].Label, variableList[i].FuncType, &lv_font_montserrat_16, w, h, i % 2 ? lv_color_hex(0x232323) : lv_color_hex(0x161616));
		lv_obj_set_pos(item->obj, 0, i * 40);
		variableList[i].lv_object = item;
		i++;	
	}
}
char szprintf[100] = { 0 };
void ui_opc_update_variableList()
{
	if (!activeVarialbeInfo) return;
	
	uint16_t i = 0;
	int rows = lv_table_get_row_cnt(variableContainer);
	while (activeVarialbeInfo[i].VariablePointer)
	{	
		
		if (i >= rows) break;
		switch (activeVarialbeInfo[i].FuncType)
		{
		case FUNC_INT:
		case FUNC_INT16:
		case FUNC_INT32:
			lv_table_set_cell_value_fmt(variableContainer, i, 1, "%d", (*(int*)activeVarialbeInfo[i].VariablePointer));
			break;
		case FUNC_FLOAT:
			sprintf(szprintf, "%.3f", (*(float*)activeVarialbeInfo[i].VariablePointer));
			lv_table_set_cell_value_fmt(variableContainer, i, 1, "%s", szprintf);			
			break;
		case FUNC_BOOLEAN:
			lv_table_set_cell_value_fmt(variableContainer, i, 1, "%s", *(bool*)activeVarialbeInfo[i].VariablePointer? "True": "False");			
			break;
		case FUNC_ASCII:
			lv_table_set_cell_value_fmt(variableContainer, i, 1, "%s", (char*)activeVarialbeInfo[i].VariablePointer);			
			break;
		default:
			break;
		}
		i++;	
	}
}

int GetDisplayVariableSize(DisplayVariableInfo* variableInfo)
{
	int i = 0;
	while (1)
	{
		if (variableInfo[i].VariablePointer == 0) break;
		i++;
	}
	return i;
}


void ui_opc_set_display_variable(DisplayVariableInfo* variableInfo)
{
	activeVarialbeInfo = variableInfo;
	int rows = GetDisplayVariableSize(variableInfo);
	lv_table_set_row_cnt(variableContainer, rows);
	lv_table_set_col_cnt(variableContainer, 2);
	//int w = lv_obj_get_width(variableContainer);
	//lv_table_set_col_width(variableContainer, 0, w / 2 - 2);
	//lv_table_set_col_width(variableContainer, 1, (w / 2) - 2);
	for (uint8_t i = 0; i < rows; i++)
	{
		lv_table_set_cell_value_fmt(variableContainer, i, 0, variableInfo[i].Label);
		lv_table_set_cell_value_fmt(variableContainer, i, 1, "");
	}
}
void SwitchDisplayVariableList()
{
	switch (DisplayIndex)
	{
	case 0:
		ui_opc_set_display_variable(LcdVarsTable);
		break;
	case 1:
		ui_opc_set_display_variable(Lcd1VarsTable);
		break;
	case 2:
		ui_opc_set_display_variable(Lcd2VarsTable);
		break;
	case 3:
		ui_opc_set_display_variable(Lcd3VarsTable);
		break;
	default:
		break;
	}
}
void ui_opc_display_next()
{
	DisplayIndex++; if (DisplayIndex >= NUMBER_OF_DISPLAY_LISTS) DisplayIndex = 0;
	SwitchDisplayVariableList();
}

void ui_opc_display_prev()
{
	DisplayIndex--; if (DisplayIndex < 0) DisplayIndex = NUMBER_OF_DISPLAY_LISTS;
	SwitchDisplayVariableList();
}

#endif
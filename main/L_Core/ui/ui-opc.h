#ifdef USE_OPC
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "K_Core/display/DisplayList.h"

typedef struct
{
	lv_obj_t* obj;
	lv_obj_t* label;
	lv_obj_t* value;
} lv_list_item;
extern lv_obj_t *ui_opc_screen;
extern lv_obj_t * variableContainer;

void ui_opc_screen_init(void);
void ui_opc_add_varialbeList(lv_obj_t* parent, DisplayVariableInfo* variableList);
void ui_opc_set_display_variable(DisplayVariableInfo* variableInfo);
void ui_opc_update_variableList();
	void ui_opc_display_next();
	void ui_opc_display_prev();
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
#include "DisplayList.h"
#include "K_Core/taskmanager.h"
#include "K_Core/K_Core.h"
#include "L_Core/ui/ui.h"
#include "L_Core/ui/ui-opc.h"
#include "K_Core/adc/adc.h"
#include "RevisionHistory.h"

DisplayVariableInfo LcdVarsTable[] = {
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &ADC_Channel[0].convAvg, "ADC CH0", FUNC_FLOAT, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &ADC_Channel[0].adcAvg, "ADC CH0-Raw", FUNC_INT16, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &ADC_Channel[1].convAvg, "ADC CH1", FUNC_FLOAT, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &ADC_Channel[1].adcAvg, "ADC CH1-Raw", FUNC_INT16, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &ADC_Channel[2].convAvg, "ADC CH2", FUNC_FLOAT, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &ADC_Channel[2].adcAvg, "ADC CH2-Raw", FUNC_INT16, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &ADC_Channel[3].convAvg, "ADC CH3", FUNC_FLOAT, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &ADC_Channel[3].adcAvg, "ADC CH3-Raw", FUNC_INT16, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &ADC_Channel[4].convAvg, "ADC CH4", FUNC_FLOAT, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &ADC_Channel[4].adcAvg, "ADC CH4-Raw", FUNC_INT16, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
};


DisplayVariableInfo Lcd1VarsTable[] = {
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
//	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },	
};

DisplayVariableInfo Lcd2VarsTable[] = {
	{ &HeartBeat, "TITLE2", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },	
};
DisplayVariableInfo Lcd3VarsTable[] = {
	{ &HeartBeat, "TITLE3", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },
	{ &HeartBeat, "HB      ", FUNC_INT32, COLOR_WHITE, COLOR_RED, 0, 0, NULL },	
};


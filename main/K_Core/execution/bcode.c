
#include "bcode.h"
#include "L_Core/storage/nvs.h"
#include "K_Core/tools/tools.h"
#include "L_Core/bluetooth/ble.h"
#include "L_Core/ui/ui-bluetooth.h"
#include "cmdprocessor.h"

/* BCODE 0: disconnect ble-client
	format: B0 
	response: NO
**/
void BCODE_0(GMBCOMMAND* cmd)
{
	ble_server_disconnect();
}
/* BCODE 10: Reqeust the head position
	format: B10 
	response: >RG:[Head position]
**/
void BCODE_10(GMBCOMMAND* cmd)
{
	tools_report_register();
}

/* BCODE 11: Set the head position
	format: B11 T11  
	response: >RG:[Head position]
**/
void BCODE_11(GMBCOMMAND* cmd)
{
	if (!ARG_PRESENT(cmd->T)) return;
	toolInfo.Address = cmd->T;
	ble_server_status = BLE_SERVER_HEADSET;
	storage_nvs_set_blob(NVS_KEY_TOOLINFO, &toolInfo, sizeof(ToolInfo));	
	tools_report_register();
	ui_ble_set_headindex(toolInfo.Address);
}
/* BCODE 100: Set the tool params
	format: B100 T# P# Q# R# S#	
		   T: Head address
		   P: Desired Temperature
		   Q: Desired Heater Duty cycle
		   R: Desired Fan Duty cycle
		   S: Aux analog
**/
void BCODE_100(GMBCOMMAND* cmd)
{
	if (!ARG_PRESENT(cmd->T)) return;
	if (ARG_PRESENT(cmd->P)) toolInfo.DesiredTemperature = cmd->P;
	if (ARG_PRESENT(cmd->Q)) toolInfo.DesiredHeaterDutyCycle = cmd->Q;
	if (ARG_PRESENT(cmd->R)) toolInfo.DesiredFanDutyCycle = cmd->R;
	if (ARG_PRESENT(cmd->S)) toolInfo.ActualAux = cmd->S;
	
	/* this is for testing.*/
	toolInfo.ActualTemperature = toolInfo.DesiredTemperature;
	toolInfo.ActualHeaterDutyCycle = toolInfo.DesiredHeaterDutyCycle;
	toolInfo.ActualFanDutyCycle = toolInfo.DesiredFanDutyCycle;
	
}
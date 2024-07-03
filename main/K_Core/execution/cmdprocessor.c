
#include "cmdprocessor.h"
#include "bcode.h"
#include "L_Core/bluetooth/ble.h"
#include "L_Core/ui/ui.h"
#include "L_Core/ui/ui-comm.h"
#include "L_Core/ui/ui-pct.h"
#include "L_Core/ui/ui-pct01.h"
#include "L_Core/ui/ui-bluetooth.h"
#include "L_Core/bluetooth/ble.h"

uint32_t cmd_NextCommandInsertionPointer = 1;
uint32_t cmd_CurrentPointer = 1;
uint32_t cmd_CommandsInQue = 0;
char cmd_CommandsInQueBuffer[SIZE_OF_COMMAND_QUEUE][MAX_COMMAND_LEN];

GMBCOMMAND cmd_Command;
char lineIndexBuffer[5];
void cmd_sequener()
{
    if(!cmd_CommandsInQue) return;						//no commands to proces, so return
    char* cmd = &cmd_CommandsInQueBuffer[cmd_CurrentPointer][0];
	int len = strlen(cmd);
	char* g6_cmd = strstr(cmd, "G6"); // it only come from BLE Client
	if (ble_run_mode == BLE_RUN_SERVER)
	{
		//if the device is running as Server , it sends the raw data to client.
		//communication_add_buffer_to_ble_buffer(&bleServerDevice.TxBuffer, (uint8_t*)&bleServerDevice.CommandLineBuffer, strlen(workingComport->CommandLineBuffer));
		//communication_add_char_to_ble_buffer(&bleServerDevice.TxBuffer, '\n');
		if (!g6_cmd) ble_server_send_data((uint8_t*)cmd, len); //send data if the command is not from client
	}
	if (g6_cmd)
	{
		parseG6Command(g6_cmd); // this is only command from client
	}
	else {
		if (cmd[len - 1] == '\n') cmd[len - 1] = '\0'; //remove  '\n'
		parseLineCommandData(cmd);
	}
	ui_comm_add_log(cmd, UI_COMM_COLOR_RECEIVE);
    cmd_CurrentPointer ++;
    if(cmd_CurrentPointer >= SIZE_OF_COMMAND_QUEUE) cmd_CurrentPointer = 1;
	cmd_CommandsInQue--;
}
void parseLineCommandData(char* cmd)
{
	int index = -1;
	char* temp = strstr(cmd, "*");// cmd.IndexOf("*");
	if (!temp) return;
	index = temp - cmd;
	if (index < 2) return;
	int firstPos = -1;
	char command = ' '; 
	for (int i = index - 1; i >= 0; i--)
	{
		if (cmd[i] == 'L' || cmd[i] == 'l' || cmd[i] == 'B' || cmd[i] == 'b' || cmd[i] == 'S')
		{
			command = cmd[i];
			firstPos = i;
			break;
		}
	}
	if (firstPos == -1) return;
	memset(lineIndexBuffer, 0, 5); //it need to reset because it can has old data in case that string's length is less than old data's 
	strncpy(lineIndexBuffer, cmd + firstPos + 1, index - firstPos - 1); // string s = cmd.Substring(firstPos + 1, index - firstPos - 1);
	index++; //increase to remove = in cmd
	if (index >= 0)
	{
		int idx = atoi(lineIndexBuffer); // Convert.ToInt32(s);
		char* value = cmd + index; // cmd.Substring(index);
		switch (command)
		{
		case 'L': //L#=string
			if (idx < 10) ui_pct_update_label_text(idx, value);
			else ui_pct01_update_label_text(idx-10, value);
			break;
		case 'l': //l#=color
			if (idx < 10) ui_pct_update_label_color(idx, value);
			else ui_pct01_update_label_color(idx-10, value);
			break;
		case 'B': //B#=string
			ui_pct_update_button_text(idx, value);
			ui_pct01_update_button_text(idx, value);
			break;
		case 'b': //b#=color
			ui_pct_update_button_color(idx, value);
			ui_pct01_update_button_color(idx, value);
			break;
		case 'S': //update the BLE device address
			if (idx != 99) break;
			UpdateBleAddress(value);
			break;
		default:
			break;
		}
	}
}

void parseG6Command(char* cmd)
{
	//G6 B#\n
	//char code = cmd[3];
	int value = atoi(cmd + 4); //go to place of Number
	switch (value)
	{
	case 18: //transform comm  screen
		ui_transform_screen(SCREEN_COMM);	
		break;
	case 19: //transform home screen
		ui_transform_screen(SCREEN_HOME);
		break;
	case 99: //G6 S99 ; this is a request to update the ble name from 407		
		break;
	default:
		communication_tx_commandline(MasterCommPort, cmd);
		break;
	}
}

void UpdateBleAddress(char* value)
{
	int address = atoi(value);
	ble_update_name(address);
}


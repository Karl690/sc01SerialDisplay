
#include "cmdprocessor.h"
#include "bcode.h"
#include "L_Core/ui/ui-comm.h"
#include "L_Core/ui/ui-pct.h"
uint32_t cmd_NextCommandInsertionPointer = 1;
uint32_t cmd_CurrentPointer = 1;
uint32_t cmd_CommandsInQue = 0;
char cmd_CommandsInQueBuffer[SIZE_OF_COMMAND_QUEUE][MAX_COMMAND_LEN];

GMBCOMMAND cmd_Command;
void cmd_sequener()
{
    if(!cmd_CommandsInQue) return;						//no commands to proces, so return
    char* cmd = &cmd_CommandsInQueBuffer[cmd_CurrentPointer][0];
	ui_comm_add_log(cmd, UI_COMM_COLOR_RECEIVE);
	parseLineCommandData(cmd);
    cmd_CurrentPointer ++;
    if(cmd_CurrentPointer >= SIZE_OF_COMMAND_QUEUE) cmd_CurrentPointer = 1;
	cmd_CommandsInQue--;
}
void parseLineCommandData(char* cmd)
{
	int len = strlen(cmd);
	int index = -1;
	int mode = -1;
	for (int i = 0; i <= len-3; i++)
	{	
		if (cmd[i] == 'L' && 
			(cmd[i + 1] >= '0' || cmd[i + 1] <= '9') && 
			cmd[i + 2] == '=')
		{
			index = i;
			mode = 0; // L# mode
			break; //that is wrong format
		}
		else if(cmd[i] == 'M' && cmd[i + 1] == '=')
		{
			index = i;
			mode = 1; // M= mode
		}
	}
	if (index >= 0)
	{
		uint8_t value = 0;
		switch (mode)
		{
		case 0: //L#=string
			value = (uint8_t)(cmd[index + 1] - '0');
			ui_pct_update_line(value, cmd + index + 3);	
			break;	
		case 1: //M=#
			value = (uint8_t)(cmd[index + 2] - '0');
			ui_pct_update_prog_mode(value);
			break;
		default:
			break;
		}
		
	}
}


uint8_t convertCommandData(char* cmd)
{
	if (!cmd) return 0;
	char *ch = strtok(cmd, " "); // split command with space
	uint8_t idx = 0;
	memset(&cmd_Command, 0xFF, sizeof(GMBCOMMAND));	//Reset command buffer
	
	while (ch != NULL) {
		if (idx == 0)
		{
			switch (ch[0])
			{	
			case 'B': cmd_Command.type = BLE; break;
			case 'G': cmd_Command.type = GCODE; break;
			case 'M': cmd_Command.type = MCODE; break;
			}
		}
		
		if (ch[1] != 0) 
		{
			char cmd = ch[0];
			ch++;
			switch (cmd)
			{
			case 'A': cmd_Command.A = atof(ch); break;
			case 'B': cmd_Command.B = atof(ch); break;
			case 'C': cmd_Command.C = atof(ch); break;
			case 'D': cmd_Command.D = atof(ch); break;
			case 'E': cmd_Command.E = atof(ch); break;
			case 'F': cmd_Command.F = atof(ch); break;
			case 'G': cmd_Command.G = atof(ch); break;
			case 'H': cmd_Command.H = atof(ch); break;
			case 'I': cmd_Command.I = atof(ch); break;
			case 'J': cmd_Command.J = atof(ch); break;
			case 'K': cmd_Command.K = atof(ch); break;
			case 'L': cmd_Command.L = atof(ch); break;
			case 'M': cmd_Command.M = atof(ch); break;
			case 'N': cmd_Command.N = atof(ch); break;
			case 'O': cmd_Command.O = atof(ch); break;
			case 'P': cmd_Command.P = atof(ch); break;
			case 'Q': cmd_Command.Q = atof(ch); break;
			case 'R': cmd_Command.R = atof(ch); break;
			case 'S': cmd_Command.S = atof(ch); break;
			case 'T': cmd_Command.T = atof(ch); break;
			case 'V': cmd_Command.V = atof(ch); break;
			case 'W': cmd_Command.W = atof(ch); break;
			case 'X': cmd_Command.X = atof(ch); break;
			case 'Y': cmd_Command.T = atof(ch); break;
			case 'Z': cmd_Command.Z = atof(ch); break;
			}	
		}
		ch = strtok(NULL, " "); // split command with space
		idx++;
	}
	if (idx == 0) return 0; // invalid command
	if (cmd_Command.type == UNKNOWN) return 0; //invalid command
	return 1;
}
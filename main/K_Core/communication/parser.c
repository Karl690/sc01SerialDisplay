#include "parser.h"
#include "RevisionHistory.h"
#include "L_Core/bluetooth/ble.h"
#include "L_Core/ui/ui-comm.h"
#include "K_Core/execution/cmdprocessor.h"
#include "K_Core/communication/communication.h"

uint32_t ProcessingError = 0;

char parse_buffer[256] = { 0 };
void parser_add_line_to_commandbuffer(COMPORT* workingComport)
{
	if (workingComport->UrgentFlag)
	{
		strcpy(cmd_CommandsInQueBuffer[0], workingComport->CommandLineBuffer); // copy the command string to Que buffer
	}
	else
	{
		strcpy(cmd_CommandsInQueBuffer[cmd_NextCommandInsertionPointer], workingComport->CommandLineBuffer); // copy the command string to Que buffer
		
		cmd_NextCommandInsertionPointer++;
		
		if (cmd_NextCommandInsertionPointer >= SIZE_OF_COMMAND_QUEUE) cmd_NextCommandInsertionPointer = 1;
		memset(workingComport->CommandLineBuffer, 0, 255);
	}
	workingComport->RxBuffer.ReadyForAtof = 1;
	workingComport->RxAcknowledgeCounter++;
	ui_comm_rx_acks = workingComport->RxAcknowledgeCounter;
	memset(workingComport->CommandLineBuffer, 0, 256); //reset commandlinebuffer
	cmd_CommandsInQue++;
}

void parser_add_line_to_blebuffer(BleDevice* workingComport)
{
	if (workingComport->UrgentFlag)
	{
		strcpy(cmd_CommandsInQueBuffer[0], workingComport->CommandLineBuffer); // copy the command string to Que buffer
	}
	else
	{
		strcpy(cmd_CommandsInQueBuffer[cmd_NextCommandInsertionPointer], workingComport->CommandLineBuffer); // copy the command string to Que buffer
		cmd_NextCommandInsertionPointer++;
		if (cmd_NextCommandInsertionPointer >= SIZE_OF_COMMAND_QUEUE) cmd_NextCommandInsertionPointer = 1;
		memset(workingComport->CommandLineBuffer, 0, 255);
	}
	workingComport->RxBuffer.ReadyForAtof = 1;
	//workingComport->RxAcknowledgeCounter++;
	memset(workingComport->CommandLineBuffer, 0, 256); //reset commandlinebuffer
	cmd_CommandsInQue++;
}

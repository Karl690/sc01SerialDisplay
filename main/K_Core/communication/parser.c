#include "parser.h"
#include "RevisionHistory.h"
#include "L_Core/bluetooth/ble.h"
#include "K_Core/execution/cmdprocessor.h"
#include "K_Core/communication/communication.h"
uint32_t ProcessingError = 0;


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
	memset(workingComport->CommandLineBuffer, 0, 256); //reset commandlinebuffer
	cmd_CommandsInQue++;
}
void parser_ble_data(BleDevice* device, uint8_t urgent)
{
	BleBuffer* WorkBuff = urgent == 0 ? &device->RxBuffer : &device->RxUrgentBuffer;
	uint8_t RawRxChar;
	uint16_t commandLen = 0;
	while (WorkBuff->Head != WorkBuff->Tail)
	{
		RawRxChar = WorkBuff->buffer[WorkBuff->Tail]; //update the work character
		WorkBuff->Tail++;
		WorkBuff->Tail &= (WorkBuff->Buffer_Size - 1);
		if (RawRxChar == CMD_END_CHAR)
		{
			//purge till we see a cr, eol
			WorkBuff->ReadyForAtof = 1;
			*WorkBuff->commandPtr++ = 0;
			//device->AcksWaiting++;
			
			strcpy(cmd_CommandsInQueBuffer[cmd_NextCommandInsertionPointer], WorkBuff->command); // copy the command string to Que buffer
			WorkBuff->commandPtr = WorkBuff->command; //reset the command buffer
			cmd_NextCommandInsertionPointer++;
			if (cmd_NextCommandInsertionPointer >= SIZE_OF_COMMAND_QUEUE) cmd_NextCommandInsertionPointer = 1;
			cmd_CommandsInQue ++;
			return;
		}
		else 
		{
			if (commandLen >= MAX_COMMAND_LEN) {
				ProcessingError ++;
				break;
			}
			*WorkBuff->commandPtr ++= RawRxChar;
		}
		commandLen++;
	}
}

void parser_incomming_ble_process()
{
	if (bleServerDevice.RxBuffer.Head != bleServerDevice.RxBuffer.Tail)
	{
		parser_ble_data(&bleServerDevice, 0);
		return;
	}
	if (bleServerDevice.RxUrgentBuffer.Head != bleServerDevice.RxUrgentBuffer.Tail)
	{
		parser_ble_data(&bleServerDevice, 1);
		return;
	}
	
}



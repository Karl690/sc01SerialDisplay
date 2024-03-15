#include "parser.h"
#include "RevisionHistory.h"
#include "L_Core/bluetooth/ble.h"
#include "K_Core/execution/cmdprocessor.h"
#include "K_Core/communication/communication.h"
uint32_t ProcessingError = 0;


void parser_rx_data(ComBuffer* WorkBuff)
{
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
			cmd_CommandsInQue++;
			return;
		}
		else 
		{
			if (commandLen >= MAX_COMMAND_LEN) {
				ProcessingError++;
				break;
			}
			*WorkBuff->commandPtr ++= RawRxChar;
		}
		commandLen++;
	}
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

void parser_incomming_process()
{
	//lvana use MasterCommPort when we can figure out the correct pointer instead of &COMUSB
	//check to see if there is room for another cmdline in the que
	//later we will make logic to use a urgentcommand que...

	//if(ForegroundTaskFlag != FORETASK_IDLE ) return; // Nothing while runing foreground task.
	
	if (cmd_CommandsInQue < (SIZE_OF_COMMAND_QUEUE - 3))
	{
//		if (RawRxComBuffer.ReadyForAtof == 1)
//		{
//			
//			//ExecutionPtr = &cmd_CommandsInQueBuffer[cmd_NextCommandInsertionPointer];
//			//			ConvertArgs2Float(&RawRxComBuffer);
//						//MasterCommPort->AcksWaiting++; //release one line of buffer
//			return;
//		}//only 1 conversion per slice
		if (RawRxComBuffer.Head != RawRxComBuffer.Tail)
		{
			parser_rx_data(&RawRxComBuffer);
			return;
		}
		//first check to see if we have full line to convert to floats and add to cmdque
//		if (RawRxUrgentComBuffer.ReadyForAtof == 1)
//		{
//			ExecutionPtr = &cmdQue[0];
//			ConvertArgs2Float(&RawRxUrgentComBuffer);
//			//			MasterCommPort->AcksWaiting++;//release one line of buffer
//			return;
//		}//only 1 conversion per slice
		if (RawRxUrgentComBuffer.Head != RawRxUrgentComBuffer.Tail)
		{
			parser_rx_data(&RawRxUrgentComBuffer);
			return;
		}
		//now we can check the normal buffer
	}
}

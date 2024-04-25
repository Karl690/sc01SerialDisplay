#pragma once
#include "main.h"

#define SIZE_OF_COMMAND_QUEUE 30
#define MAX_COMMAND_LEN 90

#define COMMENT_STRING_LENGTH   	(256+3)	//+3 for leading and trailing delim + NULL_CHAR
#define ARG_PRESENT(arg)   ((uint16_t)arg != 0xffff)
typedef enum
{
	BLE_FUNC_UNKNOWN = 0,
	BLE_FUNC_PING = 1,
	BLE_FUNC_READ_SOAPSTRING = 2,
}BLE_FUNC_T;

typedef enum {
	//NOTE: items 2 and 3 behave the same, but commands should be defined as one or the other for possible future enhancements.
	UNDEFINED,
	SINGLE_STEP,  // single step .... wait for empty queue, set ForceQToEmpty, process, reset ForceQToEmpty
	ADD_TO_MQ,  // add to Q or process in order with Q (tag as processed if not added to Q, ie G90)
	IMPACTS_DESTINATION_CALC,  // ONLY affects position (ie, change of offsets) or has no impact on position/motion and does not need to be synced
	SYNCS_WITH_MOTION,   // skip, but tag, until prior motion complete...unless Q is empty, the just process
	
} command_t;

typedef enum
{
	UNKNOWN = 0x0,
	BLE,
	MCODE,
	GCODE,
}CMD_TYPE;
typedef struct {
	float A;    //0 motor A, 4th axis
	float B;    //1 motor B, 4th axis
	float C;    //2 motor C, 4th axis
	float D;    //3 tool working diameter offset
	float E;    //4 used for extrusion value
	float F;	//5
	float G;    //6 gcode
	float H;    //7 Tool working length offset
	float I;    //8 used for circular arc commands, defines offset to center of circles
	float J;    //9 used for circular arc commands, defines offset to center of circle
	float K;	//10
	float L;	//11
	float M;    //12 mcode
	float N;	//13
	float O;	//14
	float P;	//15
	float Q;	//16
	float R;	//17
	float S;	//18
	float T;    // tool number
	float U;	//19
	float V;	//20
	float W;	//21
	float X;    //22 motor X, 1st axis
	float Y;    //23 motor Y, 2nd axis
	float Z;    //24 motor Z, 3rd axis
	float CS;	//25
	uint8_t Comment[COMMENT_STRING_LENGTH];
	//union {
	//   flag_t flag;
	//   unsigned int flags;
	//} valid;
	command_t cmdType;  // defined type indicating how this type of command interracts with the motionQ command_t
	CMD_TYPE type;
	int cmdLink;        // index to parent command (link to motionQ from deferredQ) toolNumber	
} GMBCOMMAND;   // Gcode / Mcode / Ble Code

extern GMBCOMMAND *ExecutionPtr;
extern uint32_t cmd_NextCommandInsertionPointer;
extern uint32_t cmd_CommandsInQue;
extern char cmd_CommandsInQueBuffer[SIZE_OF_COMMAND_QUEUE][MAX_COMMAND_LEN];

void cmd_sequener();
void parseLineCommandData(char* cmd);
uint8_t convertCommandData(char*);
void parseG6Command(char* cmd);
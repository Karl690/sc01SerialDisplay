#pragma once
#include "main.h"

#define  PROCESS_MAX_CHARS_TO_READ_ON_ONE_SLICE 50
#define NULL_CHAR                  '\0'    // 0
#define TERMINATE_WAIT_CHAR          1
#define PAUSE_AT_END_OF_MOVE_CHAR    2
#define PAUSE_AT_END_OF_LAYER_CHAR   3
#define AVAILABLE_4                  4  // can be harvested for Repetrel to Hydra comm
#define HELLO_WORLD_CHAR             4  // char to send to Repetrel to get repetrel to talk to Hydra over the master comm port with a PING
#define SEND_STATUS_CHAR             5
#define ASCII_ACK                    6
#define PING_REPLY                    6
#define PING_CHAR                    7  // (bell)
#define ABORT_CHAR                   8  // abort all processes, and stop all motion (backspace)
#define URGENT_911_CMD_CHAR          9  //hot inject flag
#define CATASTROPHIC_ERROR_ALERT_CHAR 9
#define CMD_END_CHAR                 10 // '\n' -  used to terminate every gcode line (linefeet)
#define SENDSTRING_TERM_CHAR         10
#define LF_CHAR                      10 // '\n'
#define JOG_Z_TABLE_UP               11
#define JOG_Z_TABLE_DOWN             12
#define CR_CHAR                      13 // '\r' (carriage return)
#define REPETREL_COMM_WATCHDOG_CHAR  14
#define JOG_DISPLAYplus  			 15
#define JOG_DISPLAYminus             16
#define VARIABLE_RESET               17


#define MAX_CHARS_FOR_PARAMETER 	20
#define COMMENT_STRING_LENGTH   	(256+3)	//+3 for leading and trailing delim + NULL_CHAR
#define GCODE_STRING_ARG_LENGTH 	(256+3)	//+3 for leading and trailing delim + NULL_CHAR

typedef struct {
	char GCodeArgA[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgB[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgC[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgD[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgE[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgF[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgG[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgH[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgI[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgJ[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgK[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgL[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgM[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgN[MAX_CHARS_FOR_PARAMETER]; //line number
	char GCodeArgO[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgP[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgQ[MAX_CHARS_FOR_PARAMETER]; //checksum -- using 'Q'
	char GCodeArgR[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgS[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgT[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgU[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgV[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgW[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgX[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgY[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgZ[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgSplat[MAX_CHARS_FOR_PARAMETER];
	char GCodeArgComment[COMMENT_STRING_LENGTH]; //buffer mismatch, working buffer is only 1024 long
	char GcodeArgStringParam[GCODE_STRING_ARG_LENGTH];
}AsciArgs;


typedef enum {
	COMTYPE_MAIN   = 0,
	COMTYPE_AUX    = 1,
	COMTYPE_EQUIP  = 2,
	COMTYPE_CUSTOM = 3
} ComPortType;


typedef struct {
	uint8_t*  	buffer; //receive buffer pointer
	uint32_t    Buffer_Size;
	uint16_t 	Head; // index of where to store the next char
	uint16_t 	Tail; // index of where to pull the next char
	uint16_t  	RxLineCount; // if there is a valid command waiting
	uint16_t  	HeadRoom; // if more characters in the buffer than this number, do not allow more incoming commands
	uint16_t  	ReadyForAtof; //when we have encountered a full line "\n"  flip up the flag to convert to Float.
	uint16_t  	ArgumentLength; //how many charcters the incoming argument is so far
	char *GCodeArgPtr; //how many charcters the incoming argument is so far
	AsciArgs  AsciiArgs; //ascii buffers for each key character and their values in ascii, will convert to floats
	char command[CMD_MAX_SIZE]; //how many charcters the incoming argument is so far
	char* commandPtr;
} ComBuffer;

typedef struct {
	int				uart_id; //esp32s3 support UART_0, 1, 2, 
	ComBuffer       RxBuffer; //standard incoming receive buffer, circular
	ComBuffer RxUrgentBuffer; //Priority Gocode rx buffer, bypasses big input que to execute in front of qued commands
	ComBuffer       TxBuffer; //outgoing characters in que
	uint32_t      UrgentFlag; //set when 911 character is received, signifying the beginning of a priority gcode line
	uint32_t     AcksWaiting; //acknowledge waiting to implement Handshake
	ComPortType      ComType; // Main com, aux com, machine interface
} COMPORT;


typedef struct {
	uint8_t  	buffer[RX_BUF_SIZE]; //receive buffer pointer
	uint16_t 	Head; // index of where to store the next char
	uint16_t 	Tail; // index of where to pull the next char
	uint32_t    Buffer_Size;
	uint16_t  	ReadyForAtof; //when we have encountered a full line "\n"  flip up the flag to convert to Float.
	char command[CMD_MAX_SIZE]; //how many charcters the incoming argument is so far
	char* commandPtr;
} BleBuffer;


typedef struct {
	int				ble_id; //device id
	BleBuffer       RxBuffer; //standard incoming receive buffer, circular
	BleBuffer RxUrgentBuffer; //Priority Gocode rx buffer, bypasses big input que to execute in front of qued commands
	BleBuffer       TxBuffer; //outgoing characters in que
	uint32_t      UrgentFlag; //set when 911 character is received, signifying the beginning of a priority gcode line
	uint32_t     AcksWaiting; //acknowledge waiting to implement Handshake	
} BleDevice;

extern ComBuffer RawRxComBuffer;
extern ComBuffer RawRxUrgentComBuffer;
extern COMPORT* MasterCommPort;
void communication_buffers_serial_init(uint8_t UartIndex, COMPORT* ComPort, uint8_t* RxBuffer, uint8_t* RxUgrentBuffer, uint8_t* TxBuffer);
void communication_buffers_ble_init(uint8_t id, BleDevice* device);
void communication_process_rx_serial_characters(COMPORT* comport);
void communication_process_rx_ble_characters(BleDevice* device, uint8_t* buf, uint16_t len);


void communication_add_buffer_to_serial_buffer(ComBuffer *targetBuffer, uint8_t* buf, uint16_t len);
void communication_add_string_to_serial_buffer(ComBuffer *targetBuffer, char* SourceString);
void communication_add_char_to_serial_buffer(ComBuffer *targetBuffer, uint8_t RawChar);

void communication_add_buffer_to_ble_buffer(BleBuffer *targetBuffer, uint8_t* buf, uint16_t len);
void communication_add_string_to_ble_buffer(BleBuffer *targetBuffer, char* SourceString);
void communication_check_tx();
void communication_check_rx();
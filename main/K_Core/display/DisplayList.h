#pragma once
#include <stdint.h>
typedef enum {
	FUNC_INT,
	FUNC_INT16,
	FUNC_INT32,
	FUNC_FLOAT,
	FUNC_FLOAT_QUEVAR,
	FUNC_HEX8,
	FUNC_HEX16,
	FUNC_HEX32,
	FUNC_ASCII,
	FUNC_BOOLEAN,
	FUNC_BAR_STATUS,
	FUNC_BAR_DUTTY,
	FUNC_BAR_FLOAT,
	FUNC_MEMHEX_64,
	FUNC_MEMHEX_128,
	FUNC_MEMHEX_256,
	FUNC_MEMDUMPASCII,
	FUNC_MEMDUMPHEX,
	FUNC_MEMDISPASCII,
	FUNC_MEMDISPASCIIHEX,
	FUNC_ASCI_SOAP
}DISPLAYFUNCTYPE;

typedef enum
{
	COLOR_WHITE = 0xffffff,
	COLOR_BLACK = 0x000000,
	COLOR_RED   = 0xff0000,
	COLOR_GREEN = 0x00ff00,
	COLOR_BLUE  = 0x0000ff,
}COLORTYPE;

enum
{
	READONLY	= 0,
	EDIALBE		= 1,
};
enum
{
	OPC_FALSE = 0,
	OPC_TRUE = 1,
};
typedef struct {
	void* 		VariablePointer; //points to the variable that holds the data we want to display
	char 			Label[20];
	DISPLAYFUNCTYPE FuncType; //function type how we show the data, i.e. hex, int, float
	uint32_t		Color_1; // this is for Label or background in Bar.
	uint32_t			Color_2; // this is for Value or progress bar in Bar.
	uint32_t 		Offset; //for FUNC_MEMDUMPASCII if string is array variable(char a[]), it would be 1 otherwise 0. it is only for memory ascii function
							//for FUNC_MEMDUMPHEX it means offset.	
	uint8_t			Editable;  //enabled editing by user
	//uint8_t			ExposedOpc;  //expose this value to OPC
	//uint32_t		OpcNodeId; // Opc Node id,
	void*		lv_object;
} DisplayVariableInfo; //__attribute__((packed)) 


#define DISPLAYVARIABEINFO_SIZE sizeof(DisplayVariableInfo)

#define NUMBER_OF_DISPLAY_LISTS 4

extern DisplayVariableInfo LcdVarsTable[];
extern DisplayVariableInfo Lcd1VarsTable[];
extern DisplayVariableInfo Lcd2VarsTable[];
extern DisplayVariableInfo Lcd3VarsTable[];


#pragma once
#include "main.h"
#include "communication.h"


//void parser_serial_data(COMPORT* comport, uint8_t urgent);
//void parser_ble_data(BleDevice* device, uint8_t urgent);
//void parser_parse_ble_data(char* data);
void parser_add_line_to_commandbuffer(COMPORT*);
void parser_add_line_to_blebuffer(BleDevice*);
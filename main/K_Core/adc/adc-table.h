#pragma once
#include <stdint.h>

#define MAX_ADC12 						4096
#define TEMP_FRAC_BITS                  0
#define TEMP_SCALE                      32
#define TEMP_SCALEF                     32.0f

#define BOGUS_TEMPERATURE               (temp_t)0x8000  // max negative
#define MIN_TEMP                        (temp_t)0x8001  // max negative
#define MAX_TEMP                        (temp_t)0x7fff  // max positive
#define MAX_AMBIENT_TEMPERATURE         (500 << TEMP_FRAC_BITS)
#define PELTIER_COOLING_MODE_RELAY_DUTY 100   // relay ON to enable cooling mode
#define PELTIER_HEATING_MODE_RELAY_DUTY 0


#define HH_POSITION_UNPLUGGED           0xFE	//254
typedef int16_t temp_t; // temperature (s10.5 format - 1/32 degree resolution)

typedef struct {
	uint16_t    adcRaw; // expected adcValue for specified temp
	temp_t      value; // if temperature (s10.5 format - 1/32 degree) at specified adcValue; position, just value, etc
} AdcTableStruct;

extern AdcTableStruct const HeadPositionTable[] __attribute__((aligned(4)));
extern AdcTableStruct const RtdTable_1M[] __attribute__((aligned(4)));
extern AdcTableStruct const RtdTable_50K[] __attribute__((aligned(4)));
extern AdcTableStruct const RtdTable_1K[] __attribute__((aligned(4)));
extern AdcTableStruct const RtdTable_100[] __attribute__((aligned(4)));

int16_t adc_convert_rtddata_from_rawvalue(const AdcTableStruct* adcTable, uint16_t raw);
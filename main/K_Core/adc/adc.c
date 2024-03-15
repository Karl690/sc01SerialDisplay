#include "adc.h"
#include "driver/adc.h"
#include "adc-table.h"


ADC_ChannelDef AdcChannelTable[ADC_CHANNEL_NUM] = {
	{ADC_UNIT_1, ADC1_CHANNEL_9, GPIO_NUM_10, HeadPositionTable},
	{ADC_UNIT_2, ADC2_CHANNEL_0, GPIO_NUM_11, RtdTable_1M},
	//{ADC_UNIT_2, ADC2_CHANNEL_1, GPIO_NUM_12, RtdTable_50K},
	//{ADC_UNIT_2, ADC2_CHANNEL_2, GPIO_NUM_13, RtdTable_1K},
	//{ADC_UNIT_2, ADC2_CHANNEL_3, GPIO_NUM_14, RtdTable_100},
};

adcStruct ADC_Channel[ADC_CHANNEL_NUM];

// calibration values for the adc

//static esp_adc_cal_characteristics_t adc1_chars;
//static esp_adc_cal_characteristics_t adc2_chars;
uint16_t ADC_Work_Channel_Index = 0; //used to walk thru the channels and update the working variables.

uint16_t adc_raw_value = 0;
uint16_t adc_voltage = 0;
void adc_init()
{
	adc1_config_width(ADC_WIDTH_BIT_12);
	for (int i = 0; i < ADC_CHANNEL_NUM; i++)
	{
		if (AdcChannelTable[i].Unit == ADC_UNIT_1) {		
			adc1_config_channel_atten((adc1_channel_t)AdcChannelTable[i].Channel, ADC_ATTEN_DB_11);	
		}
		else
		{
			adc2_config_channel_atten((adc2_channel_t)AdcChannelTable[i].Channel, ADC_ATTEN_DB_11);	
		}
	}
}

void adc_get_process_rawdata()
{
	ADC_ChannelDef *adcChannelDef = &AdcChannelTable[ADC_Work_Channel_Index];
	adcStruct *ADC_Work_Channel = &ADC_Channel[ADC_Work_Channel_Index];
	if (adcChannelDef->Unit == ADC_UNIT_1)
	{
		ADC_Work_Channel->adcRaw = adc1_get_raw((adc1_channel_t)adcChannelDef->Channel);
	}
	else
	{
		adc2_get_raw((adc2_channel_t)adcChannelDef->Channel, ADC_WIDTH_BIT_12, (int*)&ADC_Work_Channel->adcRaw);
	}
	adc_smoothDataUsing_olympic_votingaverage();
	
	ADC_Work_Channel->convAvg = adc_convert_rtddata_from_rawvalue(adcChannelDef->ConvertionTable, ADC_Work_Channel->adcAvg);
	
	ADC_Work_Channel_Index++;
	if (ADC_Work_Channel_Index >= ADC_CHANNEL_NUM) ADC_Work_Channel_Index = 0; //keep in range
}


void adc_smoothDataUsing_olympic_votingaverage(void)
{
	adcStruct* ADC_Work_Channel = &ADC_Channel[ADC_Work_Channel_Index];
	//ADC_Work_Channel->adcRaw = RawADCDataBuffer[ADC_Work_Channel_Index]; //update last reading
	//now we need to plug into the 10 reading buffer for smoothing.
	ADC_Work_Channel->sampleIndex++; //point to next place to enter the data in smoothing array
	if (ADC_Work_Channel->sampleIndex > 9) ADC_Work_Channel->sampleIndex = 0; //limit to 10 entries
	ADC_Work_Channel->sampleHistory[ADC_Work_Channel->sampleIndex] = ADC_Work_Channel->adcRaw; //plug in the latest reading.
	//at this point, channel.sampleHistory has the raw data to be smoothed.

	{
		// history buffer is full, so enough good adc values to proceed

		// this code does olympic voting (toss high and low and then average the rest)
		// the ADC_NUM_SAMPLES must be equal to (2^n) + 2 and ADC_SHIFT_FOR_AVG
		// must equal "n", as the code will shift to get the average instead of divide. set temporary
		// variables to record highest and lowest values as each of the ADC_NUM_SAMPLES is inspected
		// at the same time, record the sum of all ADC_NUM_SAMPLES samples.  when done looking at all values,
		// subtract the high and low from the sum and then calculate the average of the remaining sum.
		int32_t sum, raw, low, high, i;
		low = 0x7fffffff; // MAXINT
		high = 0x80000000; // MININT
		sum = 0;
		for (i = 0; i < ADC_NUM_SAMPLES; i++)
		{
			raw = ADC_Work_Channel->sampleHistory[i];
			sum += raw; // keep running total
			if (raw < low) low = raw; // update the lowest reading
			if (raw > high)high = raw; // update the highest reading
		}
		sum -= (low + high); // sum is now the total of the middle N values

		//next we will shift by n to effect a divide by 2^n to get the average of the 2^n remaining samples
		ADC_Work_Channel->adcAvg = (sum >> ADC_SHIFT_FOR_AVG); // update the RAW average
		ADC_Work_Channel->convAvg = (float)(((float)ADC_Work_Channel->adcAvg * 3.3) / 4095);
	}
	// setup next conversion so data will be ready for the next call in ~10ms
	
}
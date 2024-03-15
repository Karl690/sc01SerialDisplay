#pragma once
typedef void(*PFUNC)(void);

#define NUM_1000HZ              8
#define NUM_100HZ               8      // must remain 10 otherwise loop timing will not be correct
#define NUM_10HZ                8      // must remain 10 otherwise loop timing will not be correct
#define NUM_1HZ                 8     // must remain 10 otherwise loop timing will not be correct
#define ADC_CHANNELS			3

typedef enum {
	HZ_1000 = 0,
	HZ_100  = 1,
	HZ_10   = 2,
	HZ_1    = 3
} indexType;


extern uint32_t HeartBeat;

void func_SystickCallback(void* arg);
void Spare(void);
void BlinkHeartBeat(void);
void ReportToolInfo();
void CheckBluetoothConnection(void);
void Init_TaskManager();

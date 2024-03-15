#include "main.h"

typedef struct {
	float               PulsesPerUnit; //number of pulses per microliter or mm, used to calculate actual flow rate in pulses per second
	float               NozzleDiameter; // check your slicer, but this is usually close to the nozzle hole diameter
	float               LayerHeight; //used for flow calcualtions, this value is passed from the slicer via Mcode and used to
	float				UnitVolume; // like PulsesPerULiter * ExtrusionWidthInMn * SliceHeightInMm
	float               ExtrusionRateOverridePct; //used to adjust flow in real time
	uint16_t            ExtrudeFeedRate; //extrusion rate in pulses per second, no multiply, all mulitplication is done on the 407 or repetrel
	uint16_t            ExtrudeSteps; //number of steps to extrude during normal extrusion print move, 0xffff means run continous

	uint16_t            PrimeFeedRate; //speed in pulses per second to spin the motor during the prime
	uint16_t            PrimeSteps; //number of pulses to spin at this rate before starting the normal extrusion
	int16_t             PrimeTimeMs; //how long in ms to wait after issuing the prime before starting the move

	uint16_t            UnPrimeFeedRate; //speed in pulses per second to spin the motor during the Unprime
	uint16_t            UnPrimeSteps; //number of pulses to spin during Unprime, extrusion stops after this many pulses
	int16_t             UnPrimeTimeMs; //When to Fire the unprime sequence in ms relative to the end of the move (neg means before)
	uint8_t             isManuallyExtruding;
} ToolExtrusionControlStruct;
typedef struct {
	uint8_t Address;
	uint8_t Registered;
	uint8_t LiveTicker;
	uint8_t* SoapStringAddress;
	uint16_t ActualTemperature;
	uint16_t DesiredTemperature;
	uint16_t ActualHeaterDutyCycle;
	uint16_t DesiredHeaterDutyCycle;
	uint16_t ActualFanDutyCycle;
	uint16_t DesiredFanDutyCycle;
	uint16_t ActualAux;
	ToolExtrusionControlStruct ExtrusionControl;
}ToolInfo;

extern ToolInfo toolInfo;
void tools_init();
void tools_report_information();
void tools_report_register();
void tools_report_unregister();
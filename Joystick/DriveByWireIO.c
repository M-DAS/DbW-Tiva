#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Joystick.h"

#include "Switches_PORTF.h"
#include "CAN_comm.h"

int steerCount = 0;
uint64_t steerAvg = 0;
/********************************************************************
 *
 * ADC_Values[]: 0- Steering | 1 - Throttle | 2 - Brake act
 * 
 ********************************************************************/
void DriveByWireIO(void)                                         
{
	uint32_t ADC_values[3];
	
	get_contrlr_inputs(ADC_values);
	
	if(steerCount < 100)
	{
	steerAvg+=ADC_values[0];
	steerCount++;
	}else
	{
	steerAvg=steerAvg/100;	
	sendSteeringData(steerAvg);
	steerCount = 0;
	steerAvg = 0;
	sendThrottleData(ADC_values[1]);
	sendBrakeData(ADC_values[1]);
	}
	
	
	
	

}


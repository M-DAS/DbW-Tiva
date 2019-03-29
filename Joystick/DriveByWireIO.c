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
void DriveByWireIO(uint32_t x,uint32_t y)                                         
{
	//uint32_t ADC_values[3];
	
	//get_contrlr_inputs(ADC_values);
	
	sendSteeringData(x);//0
	sendThrottleData(y);//1
	sendBrakeData(y);//1
	
	
	

}


#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "Pressure_ADC.h"
#include "Linear_Actuator.h"

uint32_t eBrakeVals[5] = {10,30,50,70,100};
int32_t brake_pressure_setpt = 640;//645

void emergencyBrake(void)
{
	
}
void updateSetPoint2(uint8_t dataMSB, uint8_t dataLSB)
{
	int32_t inputData = (dataMSB<<8) + dataLSB;//add 2048 to data, 4095 ->2048 instead of 2048 ->0
	
	uint32_t scaleOut = (2*inputData)+ 640; //scale 645
	
	brake_pressure_setpt = scaleOut;
}

int32_t PIDUpdate(void)
{
	int32_t currentPIDout;
	int32_t e0, u0;
	int32_t brake_pressure = get_brake_pressure();
	static int32_t e1, u1;//we want to keep these values everytime the function is called, rather than clearing
	e0 = brake_pressure_setpt - brake_pressure;
	
	//Scaled PID difference equation.  Only P and I terms are used.
	if (e0 < 150 && e0 > -150){ //dead band, if its close enough, dont change it
		u0 = u1;								//U0 is the current value, U1 is the previous value
		e0 = 0;									//Error set to 0
	}
	else 
		u0 = u1 + 254677*e0 - 79656*e1; //calculated using slew rate
	
	//Limit the scaled output to be between {65536000 = 1000*2^16} and {16777216 = 256*2^16}
	if (u0 > 629145600)
		u0 = 629145600;
	else if (u0 < 262144000)
		u0 = 262144000;

	//Save the current output and error into the old output and error
	u1 = u0; //shift to previous
	e1 = e0;
	currentPIDout = u0>>18;//S^N scaling is 18 bit (could have done 20, but not needed)
	return currentPIDout;
	//moveto_lin_act(currentPIDout);
}

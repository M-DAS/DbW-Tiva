#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"
#include "DAC.h"


//Throttle scaling
uint32_t scale_CAN_throttle_pos(uint32_t input)
{
	uint32_t digital_pot1;
	if (input < 2000)
			digital_pot1 = 75;
	else
	{
		digital_pot1 = 4777*input - 4164982;
		digital_pot1 = digital_pot1>>16;
	}
	return (digital_pot1);
}
void Drive_by_Wire(void)
{
	uint32_t throttle_pos;
	
	throttle_pos = scale_CAN_throttle_pos(g_CAN_throttle_pos);
	
	//send out throttle position to SPI digital potentiometer
	update_dac1(throttle_pos);
	update_dac2(throttle_pos>>1);
}

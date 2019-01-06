#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Pedal_ADC.h"
#include "Digital_pot.h"


//Throttle scaling
uint32_t scale_pedal_throttle_pos(uint32_t input)
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



void Drive_by_Pedal(void)
{
	uint32_t ADC_value;
	uint32_t throttle_pos;
	
	//ADC_value = get_throttle_input();
	ADC_value = 2000;
	
	throttle_pos = scale_pedal_throttle_pos(ADC_value);
	
	//send out throttle position to SPI digital potentiometer
	update_digital_pot1(throttle_pos);
	update_digital_pot2(throttle_pos>>1);
}




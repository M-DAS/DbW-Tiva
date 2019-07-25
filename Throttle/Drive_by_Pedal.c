#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Pedal_ADC.h"


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







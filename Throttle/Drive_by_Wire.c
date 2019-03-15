#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"
#include "DAC.h"

//0->100 scaled for DAC
uint16_t DAC_Scale(uint16_t input)
{
	uint16_t DAC;
	uint16_t tempIn = input;
	if(tempIn > 100)//anything greater than 100% throttle is now 0.
		tempIn = 0;

	DAC = ((26854167*tempIn) + 937791848)>>20;


	return DAC;
}
void Drive_by_Wire(void)
{
	uint16_t throttle = DAC_Scale(Throttle_Command);
	//DAC out using I2C
	update_dac1(throttle);
	update_dac2((throttle>>1)&0x07FF);//same as dividing by 2 and masking for roll over
}

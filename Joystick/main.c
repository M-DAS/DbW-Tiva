#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Switches_PORTF.h"

#include "DriveByWireIO.h"

#include "CAN_comm.h"
#include "Joystick.h"

static uint32_t Tout0=0, Tout1=0, Tin0=0, Tin1=0;
static uint32_t ToutA0=0, ToutA1=0, TinA0=0, TinA1=0;
uint32_t joystick_x,joystick_y;
uint32_t ADC_values[3];
int main()
{
	initialization();
	while(1)
	{
		if(filter_flag == true) //Timer ISR @ 1KHz for filtering
		{
			get_contrlr_inputs(ADC_values);
			
			Tin0 = ADC_values[0];
			Tout0 = (63511*Tout1 + 1016*Tin0 + 1016*Tin1)>>16;
			Tout1 = Tout0;
			Tin1 = Tin0;
			joystick_x = Tout1;
	
			TinA0 = ADC_values[1];
			ToutA0 = (63511*ToutA1 + 1016*TinA0 + 1016*TinA1)>>16;
			ToutA1 = ToutA0;
			TinA1 = TinA0;
			joystick_y = ToutA1;
		}
		if (g_tick_flag == true) 											//Timer ISR @ 10 Hz
		{
			g_tick_flag = false;   											//clear tick_flag
			DriveByWireIO(joystick_x,joystick_y);       //read inputs and output to actuators
			PF3 ^= 0x08;
		} 
	}
}


	
	
	
	



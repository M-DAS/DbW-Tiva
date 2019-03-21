#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Drive_by_Pedal.h"
#include "Drive_by_Wire.h"
#include "Linear_Actuator.h"
#include "PID_Cntrl.h"
#include "CAN_comm.h"

int main()
{
	initialization();
	en_clutch_lin_act();
	g_tick_flag = false;
	
	while(1)
	{
		if (g_tick_flag == true)   //Check if tick happened
		{
			g_tick_flag = false;     //clear tick_flag
			PF2 ^= 0x04;
			PIDUpdate();
			send_brake_pressure_percentage();			
		}// end tick			
	}//end while loop
}//end main


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
uint32_t Tout0=0, Tout1=0, Tin0=0, Tin1=0;
int32_t currentPIDout;
int main()
{
	
	initialization();
	en_clutch_lin_act();
	g_tick_flag = false;

	while(1)
	{
		if(PID_Update_flag == true)
		{
		PID_Update_flag = false;
		Tin0 = PIDUpdate();
		Tout0 = (63511*Tout1 + 1016*Tin0 + 1016*Tin1)>>16;
    Tout1 = Tout0;
		Tin1 = Tin0;
		currentPIDout = Tout1;
//		currentPIDout = PIDUpdate();
		}
		if (g_tick_flag == true)   //Check if tick happened
		{
			g_tick_flag = false;     //clear tick_flag
			PF2 ^= 0x04;
			moveto_lin_act(currentPIDout);
			send_brake_pressure_percentage();			
		}// end tick			
	}//end while loop
}//end main


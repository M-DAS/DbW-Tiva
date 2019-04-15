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
#include "Pressure_ADC.h"

uint32_t Tout0=0, Tout1=0, Tin0=0, Tin1=0;

uint32_t aTout0=0, aTout1=0, aTin0=0, aTin1=0;
uint32_t canMiss = 0;
uint32_t eStop = 1000;
int main()
{
	
	initialization();
	en_clutch_lin_act();
	g_tick_flag = false;

	while(1)
	{
		if(BPS_Update_flag == true) //BW filter BPS input @ 5KHz
		{														//https://en.wikipedia.org/wiki/Butterworth_filter
			BPS_Update_flag = false;
			Tin0 = get_brake_pressure(0);
			Tout0 = (63511*Tout1 + 1016*Tin0 + 1016*Tin1)>>16;
			Tout1 = Tout0;
			Tin1 = Tin0;
			brakePressure = Tout1;
			
			aTin0 = get_brake_pressure(1);
			aTout0 = (63511*aTout1 + 1016*aTin0 + 1016*aTin1)>>16;
			aTout1 = aTout0;
			aTin1 = aTin0;
			eStop = aTout1;
		}
		if (g_tick_flag == true)   //Check if tick happened
		{
			g_tick_flag = false;     //clear tick_flag
			
			send_brake_pressure_percentage();
			
			if(eStop > 4095)
				eStop = 0;
			
			if(eStop < 100)
			{
				enableDbW = false;
				PF2 = 0x00;
				PF1 = 0x02;
			  send_Estop();
			}
			else{
				enableDbW = true;
				PF1 = 0x00;
			}
			
			if(g_new_CAN_data == false)
					canMiss++;
			else
			{
				canMiss = 0;
				g_new_CAN_data = false;
			}
			
			if(canMiss >= 3)
			{
				enableDbW = false;
			}
			
			if(enableDbW == true)
			{
				PF2 ^= 0x04;
				
				if(dsrc == false)
				{
					PIDUpdate();// if theres no new control message, dont update the pi loop.
				}else if(dsrc == true)
				{
					updateSetPoint2(0x00,0x64);	//set point to 100% for emergency mode
					PIDUpdate();// if theres no new control message, dont update the pi loop.	
				}
			}
			else
			{			
				updateSetPoint2(0x00,0x64);	//set point to 100% for emergency mode
				PIDUpdate();// if theres no new control message, dont update the pi loop.	
			}// end tick
		}
	}//end while loop
}//end main


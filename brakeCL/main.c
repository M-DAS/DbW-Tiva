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
	uint32_t tick_count = 0;
	bool act_state = false;
	uint32_t position;
	
	initialization();
	en_clutch_lin_act();
	g_tick_flag = false;
	
	while(1)
	{
		if (g_tick_flag == true)   //Check if tick happened
		{
			g_tick_flag = false;     //clear tick_flag
			PF2 ^= 0x04;
			//moveto_lin_act(position);
			PIDUpdate();
			send_brake_pressure_percentage();
			
			
			
//			if (tick_count == 50){
//				PF2 ^= 0x04;
//				tick_count = 0;
//				if (act_state == true){
//					position = 1900;
//					//moveto_lin_act(1700);
//					act_state = false;
//					}
//				else{
//					position = 1700;
//					//moveto_lin_act(1500);
//					act_state =  true;
//				}
//			}
//			else {
//				tick_count++;
//			}

			
		}// end tick
				
	}//end while loop

}//end main


#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Drive_by_Pedal.h"
#include "Drive_by_Wire.h"
#include "CAN_comm.h"



int main()
{
	uint32_t state = 0;
	uint32_t missed_CAN_data_cnt = 0;
	
	initialization();
	
	while(1)
	{
		if (g_tick_flag == true)   //Check if tick happened
		{
			g_tick_flag = false;     //clear tick_flag
			
			state = 1;
			PF2 ^= 0x04;
			switch(state)
			{
				
		
				
				//Normal drive mode
				//Throttle position is determined by pedal
				case 0:
				{
					//PF3 = 0x08;
					//PF2 = 0x00;
	
					g_tick_flag = false;   //clear tick_flag
					//Drive_by_Pedal();
					
					
					if (g_throttle_mode == true)
					{
						state = 1;
						//PF3 = 0x00;
					}
					break;
				}
				
				
				
				//Drive by wire throttle
				//Throttle position is received over CAN
				case 1:
				{
					//Check throttle mode flag
					if (g_throttle_mode == false)
						state = 0;
					
						
					//Update missing CAN data counter
					if (g_new_CAN_data == true)
					{
						
						missed_CAN_data_cnt = 0;
						g_new_CAN_data = false;   //clear new CAN data flag 
					}
					else
					{
						missed_CAN_data_cnt++;
						
					}
					
					//Too many missing CAN data frames reset to drive by pedal mode
					//if (missed_CAN_data_cnt >= 2)
					//{
					//	g_throttle_mode = false;
					//	state = 0;
					//}
					
					//Send throttle postion from CAN to motor controller
					Drive_by_Wire();
					Send_Throttle_Voltage();
					//PF2 ^= 0x04;                // toggle PF2
					
					break;
				}
				
				
			}//end case state machine
		}// end tick
				
	}//end while loop

}//end main


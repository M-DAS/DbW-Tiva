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
	uint32_t missed_CAN_data_cnt = 0;
	initialization();
	DAC_Init();
	while(1)
	{
		if (g_tick_flag == true)   //Check if tick happened
		{
				PF2 ^= 0x04;						 //Flash blue LED
				g_tick_flag = false;     //clear tick_flag
				Send_Throttle_Voltage(); //send throttle voltage on CAN bus regardless of state.
			
				//Check throttle mode flag
				if (DbW_Activated == true)
				{
					//Update missing CAN data counter
					if (g_new_CAN_data == true)
					{
						missed_CAN_data_cnt = 0;
						g_new_CAN_data = false;   //clear new CAN data flag 
					}
					else
						missed_CAN_data_cnt++;
					
					//Too many missing CAN data frames reset to drive by pedal mode
					if (missed_CAN_data_cnt >= 3)
					{
						DbW_Activated = false;
						//TODO: SEND DBW END MESSAGE HERE TO OTHER MODULES
					}
				 else
						Drive_by_Wire();
			}
		}// end tick			
	}//end while loop
}//end main

#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>
#include "Globals_and_Defines.h"
#include "initialization.h"
#include "Drive_by_Wire.h"
#include "CAN_comm.h"
#include "Pedal_ADC.h"

	
uint32_t missed_CAN_data_cnt = 0;
uint32_t Tout0=0, Tout1=0, Tin0=0, Tin1=0;
uint32_t eStop = 1000;
	
int main()
{
	initialization();
	
	while(1)
	{
		if (BW_Update_flag == true)
		{
			BW_Update_flag = false;
			
			Tin0 = get_throttle_input(0);
			Tout0 = (63511*Tout1 + 1016*Tin0 + 1016*Tin1)>>16;
			Tout1 = Tout0;
			Tin1 = Tin0;
			eStop = Tout1;	
		}
		
		if (g_tick_flag == true)   //Check if tick happened
		{
				g_tick_flag = false;     //clear tick_flag		
				Send_Throttle_Voltage(); //send throttle voltage on CAN bus regardless of state.
			
					if(eStop > 4095)
						eStop = 0;
				
					if(eStop < 25)
					{
						enableDbW = false;
						PF2 = 0x00;
						PF1 = 0x02;
						send_Estop();
					}

					if (g_new_CAN_data == true)
					{
						missed_CAN_data_cnt = 0;
						g_new_CAN_data = false;   
					}
					else
						missed_CAN_data_cnt++;
						
					if (missed_CAN_data_cnt >= 3)
					{
						enableDbW = false;
						PF2 = 0x00;
						PF1 = 0x02;
						send_Estop();
						DAC_Init();
					}

					if (enableDbW == true && dsrc == false)
					{
						 Drive_by_Wire();
						 PF1 = 0x00;
						 PF2 ^= 0x04;		
						 
					}
					else
					{
						DAC_Init();
						PF2 = 0x00;
						PF1 = 0x02;						
					}
	
		}// end tick			
	}//end while loop
}//end main

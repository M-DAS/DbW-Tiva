#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>
#include "Globals_and_Defines.h"
#include "initialization.h"
#include "Switches_PORTF.h"
#include "Steering_Actuator.h"
#include "DriveByWireIO.h"
#include "CAN_comm.h"



int main()
{
	initialization();
	
	while(driveENABLE)
	{
		if (g_tick_flag == true) //check tick happened
		{
			g_tick_flag = false;   //clear tick_flag
			
			
			
			if(px2Data == true)
			{
				px2Data = false;
				passThrough(CAN_Position,CAN_Speed);
			}
			else if(joyData == true)
			{
			//	PF3 ^= 0x08;
				joyData = false;
				DriveByWireIO(CAN_Position);
			}	
		}
	} 
}


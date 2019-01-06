#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Switches_PORTF.h"

#include "DriveByWireIO.h"

#include "CAN_comm.h"



int main()
{
	initialization();
	while(1)
	{
		if (g_tick_flag == true) //check tick happened
		{
			g_tick_flag = false;   //clear tick_flag
						DriveByWireIO();       //read inputs and output to actuators
						PF3 ^= 0x08;
		} 
	}
}


	
	
	
	



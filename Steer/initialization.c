#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"

#include "Globals_and_Defines.h"

#include "Switches_PORTF.h"
#include "Tick_Timer.h"
#include "Joystick.h"
#include "CAN_comm.h"
#include "inc/tm4c123gh6pm.h"


void initialization(void)
{

	/***********************
	* Bus Clock            *
	***********************/
	//Set system clock to 40MHz
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	


	

	
	
	/***************************
	* IO Peripherals           *
	***************************/	
	PORTD_Setup();
	PORTF_Setup();
	Tick_Timer_Setup();
	//ADC0_Setup();
	CAN_Setup();
	
	
	
	/*************************
	* Master Interrupt Enable*
	*************************/	
	IntMasterEnable();
}






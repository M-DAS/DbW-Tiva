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
#include "Pedal_ADC.h"
#include "CAN_comm.h"
#include "DAC.h"
#include "Drive_by_Wire.h"

void initialization(void)
{
	//Set system clock to 40MHz
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	PORTF_Setup();
	Tick_Timer_Setup();
	ADC0_Setup();
  CAN_Setup();
	I2C_DAC_Setup();
	DAC_Init();
	IntMasterEnable();
}

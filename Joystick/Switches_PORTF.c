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




void PORTF_Setup(void)
{
	/***********************
	* PortF                *
	***********************/
	//Enable PORTF
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);  //Enable clock on GPIO PORTF
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
	{}
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);  //Sets pins 1,2,3 as outputs
	
	//Configure PORTF switches
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;  //unlock PF0
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
	GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	
	//GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_FALLING_EDGE);

	//Enable PORTF interrupt in the PORT and the NVIC
	//GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_0|GPIO_INT_PIN_4);   
	//IntEnable(INT_GPIOF);  //Enable PORTF interrupt in the NVIC
}

void PORTD_Setup(void)
{
	/***********************
	* PortD                *
	***********************/
	//Enable PORTD
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);  //Enable clock on GPIO PORTD
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD))
	{}
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;  //unlock PD7
	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;


	
	//Configure PORTD switches
	GPIODirModeSet(GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7, GPIO_DIR_MODE_IN);
	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	
	//GPIOIntTypeSet(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7, GPIO_FALLING_EDGE);
		
	//Enable PORTD interrupt in the PORT and the NVIC
	//GPIOIntEnable(GPIO_PORTD_BASE, GPIO_INT_PIN_6|GPIO_INT_PIN_7);     
	//IntEnable(INT_GPIOD);  //Enable PORTF interrupt in the NVIC
}

//void GPIOPortD_Handler(void)
//{
//	uint32_t status;

//	status = GPIOIntStatus(GPIO_PORTD_BASE, true);
//	
//	if (status & GPIO_PIN_7)
//	{
//		deadWoman = true;
//		
//	}else
//		deadWoman = false;

//	
//	//if (status & GPIO_PIN_6)
//	//{
//	//	g_stop_flag = true;

//	//}
//	
//	GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_6|GPIO_INT_PIN_7);


//}


//void enable_start(void)
//{
//	GPIOIntEnable(GPIO_PORTD_BASE, GPIO_INT_PIN_6);
//}

//void disable_start(void)
//{
//	GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_7);
//}


//void enable_stop(void)
//{
//	GPIOIntEnable(GPIO_PORTD_BASE, GPIO_INT_PIN_7);
//}

//void disable_stop(void)
//{
//	GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_7);
//}


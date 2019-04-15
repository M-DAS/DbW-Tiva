#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"


#include "Globals_and_Defines.h"

void Timer0A_Handler(void)
{
	// Clear the timer interrupt
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	g_tick_flag = true;
}

void Timer1A_Handler(void)
{
	// Clear the timer interrupt
	TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
	BW_Update_flag = true;
}

void Tick_Timer_Setup(void)
{
	uint32_t ui32Period;  

	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);  
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0))
	{}
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); 
		
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);  
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1))
	{}
	TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);  	

	ui32Period = (SysCtlClockGet()/Update_Rate);
	TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period - 1);
		
	ui32Period = (SysCtlClockGet()/5000);
	TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period - 1);

	IntPrioritySet(INT_TIMER0A, 0x00);
	IntPrioritySet(INT_TIMER1A, 0x40);

	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);  
	IntEnable(INT_TIMER0A);  
	
	TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);  
	IntEnable(INT_TIMER1A); 

	TimerEnable(TIMER0_BASE, TIMER_A);
	TimerEnable(TIMER1_BASE, TIMER_A);
}

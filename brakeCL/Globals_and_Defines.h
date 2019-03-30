
#ifndef _GLOBALSANDDEFINES_H_
#define _GLOBALSANDDEFINES_H_

#include <stdint.h>
#include <stdbool.h>


//PORTF LED pins
#define PF2  (*((volatile uint32_t *)0x40025010))
#define PF3  (*((volatile uint32_t *)0x40025020))
#define PF4  (*((volatile uint32_t *)0x40025040))
		
//Drive by wire update rate in Hz
#define Update_Rate 10

//Flag for tick timer.   
extern bool g_tick_flag;

//Flag for new CAN data received.   
extern bool g_new_CAN_data;


#define brake_board_address 0x18DB0000

extern bool isServiced;

extern bool BPS_Update_flag;

extern uint32_t brakePressure;


#endif /* _GLOBALSANDDEFINES_H_ */


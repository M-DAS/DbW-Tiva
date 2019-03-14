
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

//Flag for stopping drive by wire.   
extern bool g_throttle_mode;

//CAN throttle command 0-256
extern uint32_t g_CAN_throttle_pos;

extern bool g_new_CAN_data;

#define brake_board_address 0x013EEEEE

extern bool isServiced;


#endif /* _GLOBALSANDDEFINES_H_ */


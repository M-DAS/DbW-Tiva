
#ifndef _GLOBALSANDDEFINES_H_
#define _GLOBALSANDDEFINES_H_


#include <stdint.h>
#include <stdbool.h>


//PORTF LED pins
#define PF2  (*((volatile uint32_t *)0x40025010))
#define PF3  (*((volatile uint32_t *)0x40025020))
#define PF4  (*((volatile uint32_t *)0x40025040))
	
#define PD7  (*((volatile uint32_t *)0x400070100))
	
	
//Drive by wire update rate in Hz
#define Update_Rate 10

//Throttle board CAN address
#define throttle_board_address 0x1ADB0000
//0x011EEEEE
#define steering_board_address 0x19DB0000

#define brake_board_address 0x18DB0000

extern bool driveENABLE;

//Flag for tick timer.   
extern bool g_tick_flag;

//Flag for starting drive by wire.   
extern bool g_start_flag;

//Flag for stopping drive by wire.   
extern bool g_stop_flag;

extern bool g_new_CAN_data;

extern bool filter_flag;

#endif /* _GLOBALSANDDEFINES_H_ */


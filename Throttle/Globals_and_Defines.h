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

//Throttle board CAN address
#define throttle_board_address 0x1ADB0000

//Define brake board address
#define brake_board_address 0x18DB0000

//Steering board address
#define steering_board_address 0x19DB0000//0x011EEEEE

//Torque Sensor address
#define TorqueInOut_Address 0x18FF0313

//Define DSRC radio address
#define dsrc_address 0x1BDB0000

extern bool g_tick_flag;

extern bool g_new_CAN_data;

extern bool DbW_Activated;

extern bool enableDbW;

//Global CAN buffer
extern uint16_t Throttle_Command;


#endif /* _GLOBALSANDDEFINES_H_ */


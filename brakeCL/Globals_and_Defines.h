
#ifndef _GLOBALSANDDEFINES_H_
#define _GLOBALSANDDEFINES_H_

#include <stdint.h>
#include <stdbool.h>

//PORTF LED pins
#define PF1  (*((volatile uint32_t *)0x40025008))
#define PF2  (*((volatile uint32_t *)0x40025010))
#define PF3  (*((volatile uint32_t *)0x40025020))
#define PF4  (*((volatile uint32_t *)0x40025040))
		
//Drive by wire update rate in Hz
#define Update_Rate 10

//Define brake board address
#define brake_board_address 0x18DB0000

//Throttle board CAN address
#define throttle_board_address 0x1ADB0000
//0x011EEEEE
#define steering_board_address 0x19DB0000

//Define DSRC radio address
#define dsrc_address 0x1BDB0000

//Define Feedback message ID
#define feedback_address 0x1CDBFFFF

//Define E-stop Address ID
#define estop_address 0x00EEEEEE

//Flag for tick timer.   
extern bool g_tick_flag;

//Flag for new CAN data received.   
extern bool g_new_CAN_data;

//Flag for new control message via controller/px2
extern bool newControlMsg;

//Flag for enableDbW
extern bool enableDbW;

//Flag for disable/enable DbW
extern bool dsrc;

//Flag for servicing new data
extern bool isServiced;

//Flag for brake pressure Timer loop flag for 5KHz loop
extern bool BPS_Update_flag;

//Global val for brakePressure
extern uint32_t brakePressure;

//Global val for eStop
extern uint32_t eStopVal;

#endif


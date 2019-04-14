
#ifndef _GLOBALSANDDEFINES_H_
#define _GLOBALSANDDEFINES_H_

#include <stdint.h>
#include <stdbool.h>

//PORTF LED pins
#define PF1  (*((volatile uint32_t *)0x40025008))
#define PF2  (*((volatile uint32_t *)0x40025010))
#define PF3  (*((volatile uint32_t *)0x40025020))
#define PF4  (*((volatile uint32_t *)0x40025040))	
#define PD7  (*((volatile uint32_t *)0x400070100))
	
//Drive by wire update rate in Hz
#define Update_Rate 10

//Throttle board CAN address
#define throttle_board_address 0x1ADB0000

//Define brake board address
#define brake_board_address 0x18DB0000

//Steering board address
#define steering_board_address 0x19DB0000

//Torque Sensor address
#define TorqueInOut_Address 0x18FF0313

//Define DSRC radio address
#define dsrc_address 0x1BDB0000

//Define Feedback message ID
#define feedback_address 0x1CDBFFFF

//Define E-stop Address ID
#define estop_address 0x00EEEEEE

extern bool enableDbW;
  
extern bool g_tick_flag;

extern bool g_new_CAN_data;

extern uint32_t CAN_Position;

extern uint8_t CAN_Speed;

extern bool px2Data;

extern bool joyData;

extern bool dsrc;

extern bool BW_Update_flag;

#endif


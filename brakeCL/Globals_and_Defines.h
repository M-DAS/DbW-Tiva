
#ifndef _GLOBALSANDDEFINES_H_
#define _GLOBALSANDDEFINES_H_

/***********************
* Includes             *
***********************/
#include <stdint.h>
#include <stdbool.h>
/***********************
* Public Types         *
***********************/

/***********************
* Public Macros        *
***********************/


/***********************
* Public Defines       *
***********************/

//PORTF LED pins
#define PF2  (*((volatile uint32_t *)0x40025010))
#define PF3  (*((volatile uint32_t *)0x40025020))
#define PF4  (*((volatile uint32_t *)0x40025040))
	
	
//Drive by wire update rate in Hz
#define Update_Rate 10

//Throttle board CAN addfress
#define throttle_board_address 0x012EEEEE


/***********************
* Public Constants     *
***********************/


/***********************
* Public Variables     *
***********************/

//Flag for tick timer.   
//Timer ISR sets to true.
//Scheduler sets to false 
extern bool g_tick_flag;

//Flag for new CAN data received.   
//CAN ISR sets new data flag to true.
//Scheduler clears new data flag to false 
//true = new data
extern bool g_new_CAN_data;

//Flag for stopping drive by wire.   
//CAN ISR sets mode flag to true or false.
//Scheduler clears flag when CAN is not received
//true = drive by wire mode
//false = normal throttle pedal mode
extern bool g_throttle_mode;

//CAN throttle command 0-256
extern uint32_t g_CAN_throttle_pos;

extern bool g_new_CAN_data;

#define brake_board_address 0x013EEEEE

extern bool isServiced;

/***********************
* Public Functions     *
***********************/


#endif /* _GLOBALSANDDEFINES_H_ */


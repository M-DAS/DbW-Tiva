
/***********************
* Includes             *
***********************/
#include <stdint.h>
#include <stdbool.h>


/***********************
* Type Definitions     *
***********************/

/***********************
* Macros               *
***********************/
   
/***********************
* Defines              *
***********************/

/***********************
* Constants            *
***********************/

/***********************
* Calibrations         *
***********************/

/***********************
* Global Variables     *
***********************/

//Flag for tick timer.   
//Timer ISR sets to true.
//Scheduler sets to false 
bool g_tick_flag = false;

//Flag for new CAN data received.   
//CAN ISR sets new data flag to true.
//Scheduler clears new data flag to false 
//true = new data
bool g_new_CAN_data = false;

//Flag for stopping drive by wire.   
//CAN ISR sets mode flag to true or false.
//Scheduler clears flag when CAN is not received
//true = drive by wire mode
//false = normal throttle pedal mode
bool g_throttle_mode = false;

//CAN throttle command 0-256
uint32_t g_CAN_throttle_pos = 0;


/***********************
* File Scope Variables *
***********************/

/***********************
* Function Prototypes  *
***********************/


/***********************
* Function Definitions *
***********************/

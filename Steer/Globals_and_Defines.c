
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

bool driveENABLE = true;

//Flag for starting drive by wire.   
//GPIO PORTF ISR sets to true.
//Scheduler sets to false 
bool g_start_flag = false;

//Flag for stopping drive by wire.   
//GPIO PORTF ISR sets to true.
//Scheduler sets to false 
bool g_stop_flag = false;

//Flag for new CAN data received.   
//CAN ISR sets new data flag to true.
//Scheduler clears new data flag to false 
//true = new data
bool g_new_CAN_data = false;

/***********************
* File Scope Variables *
***********************/

/***********************
* Function Prototypes  *
***********************/


/***********************
* Function Definitions *
***********************/

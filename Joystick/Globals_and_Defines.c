
/***********************
* Includes             *
***********************/
#include <stdint.h>
#include <stdbool.h>
//Flag for tick timer.   
bool g_tick_flag = false;

bool driveENABLE = true;

//Flag for starting drive by wire.   
bool g_start_flag = false;

//Flag for stopping drive by wire.   
bool g_stop_flag = false;

//Flag for new CAN data received.   
bool g_new_CAN_data = false;



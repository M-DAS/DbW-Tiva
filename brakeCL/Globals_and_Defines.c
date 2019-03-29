#include <stdint.h>
#include <stdbool.h>

//Flag for tick timer.   
bool g_tick_flag = false;

//Flag for new CAN data received.   
bool g_new_CAN_data = false;

bool isServiced = true;

bool PID_Update_flag = false;

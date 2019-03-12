#include <stdint.h>
#include <stdbool.h>

//Flag for tick timer.   
bool g_tick_flag = false;

//true = new CAN data ISR
bool g_new_CAN_data = false;

//Disable/Enable DBW with this bool   
bool DbW_Activated = true;

//CAN throttle command 0-256
uint32_t g_CAN_throttle_pos = 0;

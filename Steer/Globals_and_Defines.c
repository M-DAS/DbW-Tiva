
/***********************
* Includes             *
***********************/
#include <stdint.h>
#include <stdbool.h>

//Flag for tick timer.   
bool g_tick_flag = false;

bool enableDbW = true;

//Flag for new CAN data received.   
bool g_new_CAN_data = false;

uint32_t CAN_Position;

uint8_t CAN_Speed;

bool px2Data = false;

bool joyData = false;

bool dsrc = false;

bool BW_Update_flag = false;

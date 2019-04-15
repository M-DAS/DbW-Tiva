#include <stdint.h>
#include <stdbool.h>
  
bool g_tick_flag = false;

bool enableDbW = true;
 
bool g_new_CAN_data = false;

uint32_t CAN_Position;

uint8_t CAN_Speed;

bool px2Data = false;

bool joyData = false;

bool dsrc = false;

bool BW_Update_flag = false;

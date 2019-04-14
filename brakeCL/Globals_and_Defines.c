#include <stdint.h>
#include <stdbool.h>
  
bool g_tick_flag = false;
  
bool g_new_CAN_data = false;

bool enableDbW = true;

bool isServiced = true;

bool newControlMsg = false;

bool BPS_Update_flag = false;

bool dsrc = false;

uint32_t brakePressure = 0;

uint32_t eStopVal = 0;


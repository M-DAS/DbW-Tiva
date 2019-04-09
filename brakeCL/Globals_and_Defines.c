#include <stdint.h>
#include <stdbool.h>

//Flag for tick timer.   
bool g_tick_flag = false;

//Flag for new CAN data received.   
bool g_new_CAN_data = false;

bool enableDbW = true;

bool isServiced = true;

bool newControlMsg = false;

bool BPS_Update_flag = false;

bool dsrc = false;

uint32_t brakePressure = 0;

uint32_t eStopVal = 0;


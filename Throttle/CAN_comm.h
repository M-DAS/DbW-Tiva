#ifndef _CANCOMM_H_
#define _CANCOMM_H_

#include <stdint.h>
#include <stdbool.h>

void CAN_Setup(void);
void Send_Throttle_Voltage(void);
void send_Estop(void);

#endif 


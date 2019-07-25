
#ifndef _CANCOMM_H_
#define _CANCOMM_H_

#include <stdint.h>
#include <stdbool.h>

void CAN_Setup(void);
void send_brake_pressure_percentage(void);
void send_Estop(void);

#endif 


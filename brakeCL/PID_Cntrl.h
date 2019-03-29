
#ifndef _PID_H_
#define _PID_H_

#include <stdint.h>
#include <stdbool.h>

int32_t PIDUpdate(void);
void updateSetPoint2(uint8_t dataMSB, uint8_t dataLSB);

#endif 


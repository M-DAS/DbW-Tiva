
#ifndef _PID_H_
#define _PID_H_

#include <stdint.h>
#include <stdbool.h>

void PIDUpdate(void);
void updateSetPoint2(uint8_t dataMSB, uint8_t dataLSB);

#endif 


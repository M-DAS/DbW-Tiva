
#ifndef _STEERINGACTUATOR_H_
#define _STEERINGACTUATOR_H_

#include <stdint.h>
#include <stdbool.h>

void zero_steering_act(void);

void moveto_steering_act(int32_t position);

void passThrough(int32_t position,uint8_t speed);

bool TorqueOveride(void);

#endif


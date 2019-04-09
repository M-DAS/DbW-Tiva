
#ifndef _PRESSUREADC_H_
#define _PRESSUREADC_H_

#include <stdint.h>
#include <stdbool.h>

uint32_t get_brake_pressure(int select);
void ADC0_Setup(void);

#endif 


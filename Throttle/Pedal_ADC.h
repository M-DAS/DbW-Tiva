
#ifndef _PEDALADC_H_
#define _PEDALADC_H_

/***********************
* Includes             *
***********************/
#include <stdint.h>
#include <stdbool.h>

uint32_t get_throttle_input(int select);
void ADC0_Setup(void);

#endif 



#ifndef _DAC_H_
#define _DAC_H_

#include <stdint.h>
#include <stdbool.h>

void I2C_DAC_Setup(void);
void update_dac1(uint16_t digital_pot_position1);
void update_dac2(uint16_t digital_pot_position2);


#endif 


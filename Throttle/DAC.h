
#ifndef _DIGITALPOT_H_
#define _DIGITALPOT_H_

/***********************
* Includes             *
***********************/
#include <stdint.h>
#include <stdbool.h>


/***********************
* Public Types         *
***********************/

/***********************
* Public Macros        *
***********************/


/***********************
* Public Defines       *
***********************/


/***********************
* Public Constants     *
***********************/


/***********************
* Public Variables     *
***********************/


/***********************
* Public Functions     *
***********************/
void update_digital_pot1(uint8_t throttle_position);
void update_digital_pot2(uint8_t throttle_position2);
void Digital_Pot_Setup(void);
void I2C_DAC_Setup(void);
void update_dac1(uint8_t digital_pot_position1);
void update_dac2(uint8_t digital_pot_position2);

#endif /* _DIGITALPOT_H_ */


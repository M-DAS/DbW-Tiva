
#ifndef _PEDALADC_H_
#define _PEDALADC_H_

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
uint32_t get_brake_pressure(void);
void ADC0_Setup(void);

#endif /* _PEDALADC_H_ */


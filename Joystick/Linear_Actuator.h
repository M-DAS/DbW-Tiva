
#ifndef _LINEARACTUATOR_H_
#define _LINEARACTUATOR_H_

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
void zero_lin_act(void);
void en_clutch_lin_act(void);
void disable_clutch_lin_act(void);
void en_motor_lin_act(void);
void disable_motor_lin_act(void);
void moveto_lin_act(uint32_t position);



#endif /* _LINEARACTUATOR_H_ */


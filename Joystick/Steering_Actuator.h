
#ifndef _STEERINGACTUATOR_H_
#define _STEERINGACTUATOR_H_

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
void zero_steering_act(void);

void moveto_steering_act(int32_t position);

bool TorqueOveride(void);

#endif /* _STEERINGACTUATOR_H_ */


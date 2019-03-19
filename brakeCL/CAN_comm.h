
#ifndef _CANCOMM_H_
#define _CANCOMM_H_

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
void CAN_Setup(void);
void send_brake_pressure_percentage();

#endif /* _CANCOMM_H_ */


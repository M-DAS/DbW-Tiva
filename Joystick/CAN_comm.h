
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
void sendSteeringData(uint32_t steering);
void sendThrottleData(uint32_t throttle);
void sendBrakeData(uint32_t brake);
#endif /* _CANCOMM_H_ */



#ifndef _PID_H_
#define _PID_H_

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
void PIDUpdate(void);
void updateSetPoint(uint8_t dataMSB, uint8_t dataLSB);
void updateSetPoint2(uint8_t dataMSB, uint8_t dataLSB);

#endif /* _PID_H_ */


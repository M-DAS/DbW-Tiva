
#ifndef _SWITCHESPORTF_H_
#define _SWITCHESPORTF_H_

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
void PORTF_Setup(void);
void PORTD_Setup(void);

void enable_start(void);
void disable_start(void);

void enable_stop(void);
void disable_stop(void);


#endif /* _SWITCHESPORTF_H_ */


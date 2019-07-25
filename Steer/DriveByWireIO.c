#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>

#include "Globals_and_Defines.h"
#include "initialization.h"

#include "Joystick.h"

#include "Switches_PORTF.h"
#include "Linear_Actuator.h"
#include "Steering_Actuator.h"
#include "Throttle.h"


int32_t calc_steering_pos(uint32_t position)
{
	int32_t	scaled_position = (((position + 2048)&0x00000FFF)<<20); 
    scaled_position = (scaled_position/131072)*100;               
    scaled_position += 360000;                                 
  return scaled_position;
}

uint64_t avg;

static uint64_t movingAverage = 0;
static uint64_t i = 0;
static uint32_t movingAvg[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int n = 20;
int occurances = 0;
	
void DriveByWireIO(uint32_t position)                                         
{
	int32_t steering_pos;

	steering_pos = calc_steering_pos(position);
	movingAverage =movingAverage +position-movingAvg[i%n];
	movingAvg[i%n] = position;
	
	i++;
	
	avg = movingAverage/n;

	if(avg>= 2010 && avg <= 2210)	//1.698V = 2100 via ADC
		occurances++;
	else
		occurances =0;

	if(occurances > 18)
		zero_steering_act();
	else
		moveto_steering_act(steering_pos);
	
}


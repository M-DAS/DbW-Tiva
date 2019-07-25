#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/can.h"

#include "driverlib/uart.h"
#include "utils/uartstdio.h"

void zero_steering_act(void)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID =  0x18FF00F9 ;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 1, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void moveto_steering_act(int32_t position)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x00};
	pui8BufferOut[2] = (position&0x000000FF);
	pui8BufferOut[3] = (position&0x0000FF00)>>8;
	pui8BufferOut[4] = (position&0x00FF0000)>>16;
	pui8BufferOut[5] = (position&0xFF000000)>>24;
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID =  0x18FF00F9 ;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 1, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}


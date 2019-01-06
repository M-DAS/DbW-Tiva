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

# include "Globals_and_Defines.h"

void zero_throttle(void)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID =  throttle_board_address ;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 1, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void moveto_throttle(uint32_t position)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	pui8BufferOut[1] = position & 0x000000FF;
	pui8BufferOut[2] = (position & 0x00000F00)>>8;

		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID =  throttle_board_address ;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 2, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

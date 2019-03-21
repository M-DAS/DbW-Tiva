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


void zero_lin_act(void)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x7E, 0x02, 0x12, 0x34, 0x56, 0xAB, 0xCD, 0xEF};
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID = 0xFF0000;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 3, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void en_clutch_lin_act(void)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x0F, 0x4A, 0xF4, 0x81, 0x00, 0x00, 0x00, 0x00};
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID = 0xFF0000;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 3, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void disable_clutch_lin_act(void)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x0F, 0x4A, 0xF4, 0x01, 0x00, 0x00, 0x00, 0x00};
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID = 0xFF0000;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 3, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void en_motor_lin_act(void)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x0F, 0x4A, 0xF4, 0xC1, 0x00, 0x00, 0x00, 0x00};
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID = 0xFF0000;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 3, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void disable_motor_lin_act(void)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x0F, 0x4A, 0xF4, 0x81, 0x00, 0x00, 0x00, 0x00};
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID = 0xFF0000;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 3, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void moveto_lin_act(uint32_t position)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8] = {0x0F, 0x4A, 0xF4, 0xC1, 0x00, 0x00, 0x00, 0x00};
	pui8BufferOut[2] = position & 0xFF;
	pui8BufferOut[3] = ((position &0x00000F00)>>8)|0xC0;
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID = 0xFF0000;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;
	
	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 3, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}


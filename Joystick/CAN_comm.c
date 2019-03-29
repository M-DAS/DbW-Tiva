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

#include "Globals_and_Defines.h"


void CAN_Setup(void)
{
	//Enable PORTE
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE))
	{}

	// Configure the GPIO pin muxing to select CAN0 functions for these pins.
	// This step selects which alternate function is available for these pins.
	GPIOPinConfigure(GPIO_PE4_CAN0RX);
	GPIOPinConfigure(GPIO_PE5_CAN0TX);

	//Configure the pins for CAN
	GPIOPinTypeCAN(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);


	// Enable the CAN0 module.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_CAN0))
	{}
	CANInit(CAN0_BASE);

	// 250Kbit CAN speed
	CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 250000);

		//Set CAN0 to looback test mode
//	CAN0_CTL_R |= CAN_CTL_TEST;
//	CAN0_TST_R |= CAN_TST_LBACK;  //REMOVE FOR REAL IMPLEMENT

	CANEnable(CAN0_BASE);

}


void sendSteeringData(uint32_t steering) // will have to add ,modes here
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8];
  //pui8BufferOut[0] = MODES
	pui8BufferOut[1] = (steering&0x000000FF);
	pui8BufferOut[2] = (steering&0x0000FF00)>>8;
	pui8BufferOut[3] = (steering&0x00FF0000)>>16;
	pui8BufferOut[4] = (steering&0xFF000000)>>24;

	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID =  steering_board_address;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 8;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;

	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 1, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void sendThrottleData(uint32_t throttle)
{
	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[8];
	uint16_t throttleInput = throttle;
	uint16_t ScaledThrottle;
	
	if(throttleInput < 2048)
		throttleInput = 2048;
	if(throttleInput > 4085)
		throttleInput = 4096;

	ScaledThrottle = (((51170*throttleInput)-104685633)>>20);

  pui8BufferOut[0] =  0x01;																						//SRC ID
	pui8BufferOut[1] =  0x00;																						//Event type
	pui8BufferOut[2] = (ScaledThrottle&0xFF00)>>8;											//MSB data
	pui8BufferOut[3] = (ScaledThrottle&0x00FF);													//LSB data

	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID =  throttle_board_address;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 4;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;

	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 2, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

void sendBrakeData(uint32_t brake)
{

	tCANMsgObject sMsgObjectTx;
	uint8_t pui8BufferOut[4] = {0x00,0x00,0x00,0x00};
	uint16_t brakeInput = brake;
	int32_t scaleOut;
	if(brakeInput > 2048)
		brakeInput = 2048;
 
	scaleOut = (-1*brakeInput*12797 +26214400)>>18;
	
  pui8BufferOut[0] =  0x01;																						//SRC ID
	pui8BufferOut[1] =  0x00;																						//Event type
	pui8BufferOut[2] = ((scaleOut>>8)&0x00FF);//msb
	pui8BufferOut[3] = (scaleOut&0x00FF);//lsb
		
	//Configure transmit of message object.
	sMsgObjectTx.ui32MsgID =  brake_board_address;
	sMsgObjectTx.ui32Flags = 0;
	sMsgObjectTx.ui32MsgLen = 4;
	sMsgObjectTx.pui8MsgData = pui8BufferOut;//testATOM

	//Send out data on CAN
	CANMessageSet(CAN0_BASE, 4, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

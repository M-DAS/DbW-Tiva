#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"


void I2C_DAC_Setup(void)
{	
	//Turn on clock to GPIOB and I2C0
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C0))
	{}
		
	//Configure GPIOB pins to be used by I2C0
	GPIOPinConfigure(GPIO_PB2_I2C0SCL);
	GPIOPinConfigure(GPIO_PB3_I2C0SDA);
	GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
	GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
		
	//Set the Launcpad as the I2C master with the slow clock 100 Kbps	
	I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false);
}

void update_dac1(uint16_t digital_pot_position1)
{
	uint8_t temp;
	temp = (digital_pot_position1>>8)&0x0F;   //4 MSB's of the triangle wave value
  //sets the top 4, 0 0 PD1 PD0, bits of the second byte to 0 as required 
	I2CMasterSlaveAddrSet(I2C0_BASE, 0x60, false);
	I2CMasterDataPut(I2C0_BASE, temp); //second byte sent from the I2C module  
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START); //Outputs first byte(address) and second byte
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
	
	temp = (digital_pot_position1&0x00FF);   //8 LSB's triangle wave value		
	I2CMasterDataPut(I2C0_BASE, temp);  //third data byte sent 
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);   //Outputs bottom 8 MSB's
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
}

void update_dac2(uint16_t digital_pot_position2)
{
	uint8_t temp2;
	temp2 = (digital_pot_position2>>8)&0x0F;   //4 MSB's of the triangle wave value
  //sets the top 4, 0 0 PD1 PD0, bits of the second byte to 0 as required 
	I2CMasterSlaveAddrSet(I2C0_BASE, 0x61, false);
	I2CMasterDataPut(I2C0_BASE, temp2); //second byte sent from the I2C module  
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START); //Outputs first byte(address) and second byte
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
	
	temp2 = (digital_pot_position2&0x00FF);   //8 LSB's triangle wave value		
	I2CMasterDataPut(I2C0_BASE, temp2);  //third data byte sent 
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);   //Outputs bottom 8 MSB's
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
}

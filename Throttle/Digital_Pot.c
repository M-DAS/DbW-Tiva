#define PART_TM4C123GH6PM 1;

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ssi.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"



void update_digital_pot1(uint8_t digital_pot_position1)
{
	SSIDataPut(SSI0_BASE, digital_pot_position1);
}

void update_digital_pot2(uint8_t digital_pot_position2)
{
	SSIDataPut(SSI1_BASE, digital_pot_position2);
}



void Digital_Pot_Setup(void)
{
	//Enable SSIO and GPIOA
	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	//Configure GPIOA pins for SSI0
	GPIOPinConfigure(GPIO_PA2_SSI0CLK);
	GPIOPinConfigure(GPIO_PA3_SSI0FSS);
	GPIOPinConfigure(GPIO_PA5_SSI0TX);
	GPIOPinTypeSSI(GPIO_PORTA_BASE,GPIO_PIN_5|GPIO_PIN_3|GPIO_PIN_2);

	//Configure and enable SSI0 
	SSIConfigSetExpClk(SSI0_BASE,SysCtlClockGet(),SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER,100000,8);
	SSIEnable(SSI0_BASE);
//	
//	
//	//Enable SSI2 and GPIOB
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
//  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

//	//Configure GPIOB pins for SSI2
//	GPIOPinConfigure(GPIO_PB4_SSI2CLK);
//	GPIOPinConfigure(GPIO_PB5_SSI2FSS);
//	GPIOPinConfigure(GPIO_PB7_SSI2TX);
//	GPIOPinTypeSSI(GPIO_PORTB_BASE,GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_7);

//	//Configure and enable SSI2 
//	SSIConfigSetExpClk(SSI2_BASE,SysCtlClockGet(),SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER,100000,8);
//	SSIEnable(SSI2_BASE);
	
	//Enable SSI1 and GPIOB
	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI1);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	//Configure GPIOB pins for SSI2
	GPIOPinConfigure(GPIO_PF2_SSI1CLK);
	GPIOPinConfigure(GPIO_PF3_SSI1FSS);
	GPIOPinConfigure(GPIO_PF1_SSI1TX);
	GPIOPinTypeSSI(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

	//Configure and enable SSI1 
	SSIConfigSetExpClk(SSI1_BASE,SysCtlClockGet(),SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER,100000,8);
	SSIEnable(SSI1_BASE);
}


void I2C_DAC_Setup(void)
{	
	/***********************
	* I2C0                 *
	***********************/
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
		
	//Set the address to the MCP4725 DAC. First byte sent for each traingle wave value.
	//I2CMasterSlaveAddrSet(I2C0_BASE, 0x61, false);
}

void update_dac1(uint8_t digital_pot_position1)
{
	uint8_t temp;
	uint16_t value;
	value = digital_pot_position1;
	temp = (value&0x0F0) >> 4;   //4 MSB's of the triangle wave value
	temp = temp & 0x0F;  //sets the top 4, 0 0 PD1 PD0, bits of the second byte to 0 as required 
	I2CMasterSlaveAddrSet(I2C0_BASE, 0x60, false);
	I2CMasterDataPut(I2C0_BASE, temp); //second byte sent from the I2C module  
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START); //Outputs first byte(address) and second byte
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
	
	temp = (value&0x000F);   //8 LSB's triangle wave value		
	I2CMasterDataPut(I2C0_BASE, temp);  //third data byte sent 
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);   //Outputs bottom 8 MSB's
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
}

void update_dac2(uint8_t digital_pot_position2)
{
	uint8_t temp;
	uint16_t value;
	value = digital_pot_position2;
	temp = (value&0x0F0) >> 4;   //4 MSB's of the triangle wave value
	temp = temp & 0x0F;  //sets the top 4, 0 0 PD1 PD0, bits of the second byte to 0 as required
  I2CMasterSlaveAddrSet(I2C0_BASE, 0x61, false);	
	I2CMasterDataPut(I2C0_BASE, temp); //second byte sent from the I2C module  
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START); //Outputs first byte(address) and second byte
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
	
	temp = (value&0x000F);   //8 LSB's triangle wave value		
	I2CMasterDataPut(I2C0_BASE, temp);  //third data byte sent 
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);   //Outputs bottom 8 MSB's
	while(I2CMasterBusy(I2C0_BASE))  //Wait for I2CO master to finish transmission
	{}
}

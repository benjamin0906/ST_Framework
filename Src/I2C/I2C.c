/*
 * I2C.c
 *
 *  Created on: 2020. okt. 16.
 *      Author: BodnarB
 */

#include "I2C_Types.h"
#include "I2C.h"
#include "NVIC.h"

static dtI2C *I2C[2] = {(dtI2C*)0x40005400,
						(dtI2C*)0x40005800};

static uint8 SlaveAddress;
static uint8 *RegisterAdd;
static uint8 RegLen;
static uint8 *Data;
static uint8 DataLen;

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config);
void I2C_Start(dtI2cSessionType SessionType, uint8 SlaveAdd, uint8* RegisterAddress, uint8 RegisterLength, uint8* Data, uint8 DataLength);

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config)
{
	dtCR1 temp = {.Word = 0};
	I2C[Instance]->CR1.Fields.PE = 0;
	temp.Fields.ANFOFF = !config.AnalogFilter;
	temp.Fields.PE = 1;
	I2C[Instance]->TIMINGR.Word = config.TimingReg;

	I2C[Instance]->CR1 = temp;

	NVIC_EnableIRQ(IRQ_I2C2);
}

void I2C_Start(dtI2cSessionType SessionType, uint8 SlaveAdd, uint8* RegisterAddress, uint8 RegisterLength, uint8* Data, uint8 DataLength)
{
	SlaveAddress = SlaveAdd;
	RegisterAdd = RegisterAddress;
	RegLen = RegisterLength;
	Data = Data;
	DataLen = DataLength;

	SET_SLAVE_ADDRESS(SlaveAdd);
	I2C[1]->CR2.Fields.RD_WRN = 0;
	I2C[1]->CR2.Fields.AUTOEND = 0;
	I2C[1]->CR2.Fields.HEAD10R = 1;
	if(SessionType == I2C_Read) I2C[1]->CR2.Fields.RELOAD = 0;
	else I2C[1]->CR2.Fields.RELOAD = 1;
	I2C[1]->CR2.Fields.NBYTES = RegLen;
	I2C[1]->CR2.Fields.START = 1;
}

void I2C2_IRQHandler(void)
{

	{
		I2C[1]->TXDR.Fields.TXDATA = *RegisterAdd++;
	}
}

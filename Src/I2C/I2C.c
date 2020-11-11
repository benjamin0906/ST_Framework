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

static uint8 *RegisterAdd;
static uint8 RegLen;
static uint8 *Data;
static uint8 DataLen;
static uint8 SecondStart;
static dtI2cSessionResult Result;
dtI2cSessionType Session;

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config);
void I2C_Start(dtI2cSessionType SessionType, uint8 SlaveAdd, uint8* RegisterAddress, uint8 RegisterLength, uint8* Data, uint8 DataLength);
dtI2cSessionResult I2C_Result(void);

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config)
{
	dtCR1 temp = {.Word = 0};
	I2C[Instance]->CR1.Fields.PE = 0;
	temp.Fields.ANFOFF = !config.AnalogFilter;
	temp.Fields.PE = 1;
	temp.Fields.TXIE = 1;
	temp.Fields.RXIE = 1;
	temp.Fields.STOPIE = 1;
	temp.Fields.TCIE = 1;
	I2C[Instance]->TIMINGR.Word = config.TimingReg;
	I2C[Instance]->CR1 = temp;
	if(Instance == I2C1)
	{
#if defined(MCU_G071) || defined(MCU_G070)
		NVIC_EnableIRQ(IRQ_I2C1);
#elif defined(MCU_L433)
		NVIC_EnableIRQ(IRQ_I2C1_EV);
#endif
	}
	else if(Instance == I2C2)
	{
#if defined(MCU_G071) || defined(MCU_G070)
		NVIC_EnableIRQ(IRQ_I2C2);
#elif defined(MCU_L433)
		NVIC_EnableIRQ(IRQ_I2C2_EV);
#endif
	}
}

void I2C_Start(dtI2cSessionType SessionType, uint8 SlaveAdd, uint8* RegisterAddress, uint8 RegisterLength, uint8* DataPointer, uint8 DataLength)
{
	/* Copy the necessary infos into the own variables of the module */
	RegisterAdd = RegisterAddress;
	RegLen = RegisterLength;
	Data = DataPointer;
	DataLen = DataLength;
	Session = SessionType;

	/* Set the status sign variable to busy */
	Result = Busy;
	SecondStart = 0;

	/* Initiate the communication session */
	/*SET_WRITE_TRANSFER_REQ(I2C1);
	CLEAR_AUTO_ENABLE(I2C1);
	SET_7BIT_ADDRESS_MODE(I2C1);
	if(Session == I2C_Read)
	{
		DISABLE_RELOAD(I2C1);
	}
	else ENABLE_RELOAD(I2C1);
	SET_SLAVE_ADDRESS(I2C1,SlaveAdd);
	SET_TRANSFER_SIZE(I2C1, RegLen);
	GENERATE_START(I2C1);*/

	/* Initiate the communication session */
		SET_WRITE_TRANSFER_REQ(I2C2);
		CLEAR_AUTO_ENABLE(I2C2);
		SET_7BIT_ADDRESS_MODE(I2C2);
		if(Session == I2C_Read)
		{
			DISABLE_RELOAD(I2C2);
		}
		else ENABLE_RELOAD(I2C2);
		SET_SLAVE_ADDRESS(I2C2,SlaveAdd);
		SET_TRANSFER_SIZE(I2C2, RegLen);
		GENERATE_START(I2C2);

}

dtI2cSessionResult I2C_Result(void)
{
	return Result;
}

#if defined(MCU_G071) || defined(MCU_G070)
void I2C1_IRQHandler(void)
#elif defined(MCU_L433)
void I2C1_EV_IRQHandler(void)
#endif
{
	if(I2C[0]->ISR.Fields.TXIS != 0)
	{
		if(SecondStart == 0) I2C[0]->TXDR.Fields.TXDATA = *RegisterAdd++;
		else I2C[0]->TXDR.Fields.TXDATA = *Data++;
	}
	else if(I2C[0]->ISR.Fields.RXNE != 0)
	{
		*Data++ = I2C[0]->RXDR.Fields.RXDATA;
		DataLen--;
	}
	else if(I2C[0]->ISR.Fields.TC != 0)
	{
		if(Session == I2C_Read && (DataLen > 0))
		{
			if(DataLen > 255)
			{
				/* Set NBYTES to 255 */
				SET_TRANSFER_SIZE(I2C1, 255);
			}
			else
			{
				/* Set NBYYTES to the left amount */
				SET_TRANSFER_SIZE(I2C1, DataLen);
			}
			/* Set a read transfer request */
			SET_READ_TRANSFER_REQ(I2C1);

			/* Generate a start condition */
			GENERATE_START(I2C1);
		}
		else
		{
			/* Generate a stop condition */
			GENERATE_STOP(I2C1);
		}
	}
	else if(I2C[0]->ISR.Fields.TCR != 0)
	{
		if(Session == I2C_Read)
		{

		}
		else
		{
			if(DataLen > 255)
			{
				/* Set to NBYTES 255 */
				SET_TRANSFER_SIZE(I2C1, 255);
			}
			else
			{
				/* Set to NBYTES the left amount */
				SET_TRANSFER_SIZE(I2C1, DataLen);

				/* Disable reload mode */
				DISABLE_RELOAD(I2C1);

				/* Enable auto end mode */
				SET_AUTO_ENABLE(I2C1);
			}
			SecondStart = 1;
		}
	}
	else if(I2C[0]->ISR.Fields.STOPF != 0)
	{
		CLEAR_STOP_FLAG(I2C1);
		Result = Done;
		if(I2C[0]->ISR.Fields.NACKF != 0)
		{
			CLEAR_NACK_FLAG(I2C1);
			Result = Error;
		}
	}
}

#if defined(MCU_G071) || defined(MCU_G070)
void I2C2_IRQHandler(void)
#elif defined(MCU_L433)
void I2C2_EV_IRQHandler(void)
#endif
{
	if(I2C[1]->ISR.Fields.TXIS != 0)
		{
			if(SecondStart == 0) I2C[1]->TXDR.Fields.TXDATA = *RegisterAdd++;
			else I2C[1]->TXDR.Fields.TXDATA = *Data++;
		}
		else if(I2C[1]->ISR.Fields.RXNE != 0)
		{
			*Data++ = I2C[1]->RXDR.Fields.RXDATA;
			DataLen--;
		}
		else if(I2C[1]->ISR.Fields.TC != 0)
		{
			if(Session == I2C_Read && (DataLen > 0))
			{
				if(DataLen > 255)
				{
					/* Set NBYTES to 255 */
					SET_TRANSFER_SIZE(I2C2, 255);
				}
				else
				{
					/* Set NBYYTES to the left amount */
					SET_TRANSFER_SIZE(I2C2, DataLen);
				}
				/* Set a read transfer request */
				SET_READ_TRANSFER_REQ(I2C2);

				/* Generate a start condition */
				GENERATE_START(I2C2);
			}
			else
			{
				/* Generate a stop condition */
				GENERATE_STOP(I2C2);
			}
		}
		else if(I2C[1]->ISR.Fields.TCR != 0)
		{
			if(Session == I2C_Read)
			{

			}
			else
			{
				if(DataLen > 255)
				{
					/* Set to NBYTES 255 */
					SET_TRANSFER_SIZE(I2C2, 255);
				}
				else
				{
					/* Set to NBYTES the left amount */
					SET_TRANSFER_SIZE(I2C2, DataLen);

					/* Disable reload mode */
					DISABLE_RELOAD(I2C2);

					/* Enable auto end mode */
					SET_AUTO_ENABLE(I2C2);
				}
				SecondStart = 1;
			}
		}
		else if(I2C[1]->ISR.Fields.STOPF != 0)
		{
			CLEAR_STOP_FLAG(I2C2);
			Result = Done;
			if(I2C[1]->ISR.Fields.NACKF != 0)
			{
				CLEAR_NACK_FLAG(I2C2);
				Result = Error;
			}
		}
}

/*
 * I2C.c
 *
 *  Created on: 2020. okt. 16.
 *      Author: BodnarB
 */

#include "I2C_Types.h"
#include "I2C.h"
#include "NVIC.h"
#include "GPIO.h"
#include "RCC.h"
#include "config.h"

static dtI2C *const I2C[2] = {(dtI2C*)0x40005400,
						(dtI2C*)0x40005800};

static uint8 *RegisterAdd;
static uint8 RegLen;
static uint8 *Data[2];
static uint8 DataLen[2];
static dtI2cSessionResult Result[2];
static uint8 SecondStart[2];
dtI2cSessionType Session[2];

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config);
void I2C_Start(dtI2CInstance Instance, dtI2cSessionType SessionType, uint8 SlaveAdd, uint8* RegisterAddress, uint8 RegisterLength, uint8* Data, uint8 DataLength);
dtI2cSessionResult I2C_Result(dtI2CInstance Instance);

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config)
{
	if(I2C[Instance]->CR1.Fields.PE == 0)
	{
		if(Instance == I2C1)
		{
#if defined(I2C1_SDA_PIN) && defined(I2C1_SDA_ALTER) && defined(I2C1_SCL_PIN) && defined(I2C1_SCL_ALTER)
			GPIO_PinInit(I2C1_SDA_PIN,(dtGPIOConfig){.Mode = I2C1_SDA_ALTER, .PUPD = PullUp, .Speed = Medium, .Type = OpenDrain});
			GPIO_PinInit(I2C1_SCL_PIN,(dtGPIOConfig){.Mode = I2C1_SCL_ALTER, .PUPD = PullUp, .Speed = Medium, .Type = OpenDrain});
			RCC_ClockEnable(RCC_I2C1,Enable);
#if defined(MCU_G071) || defined(MCU_G070)
			NVIC_EnableIRQ(IRQ_I2C1);
#elif defined(MCU_L433)
			NVIC_EnableIRQ(IRQ_I2C1_EV);
#endif
#endif
		}
		else if(Instance == I2C2)
		{
#if defined(I2C2_SDA_PIN) && defined(I2C2_SDA_ALTER) && defined(I2C2_SCL_PIN) && defined(I2C2_SCL_ALTER)
			GPIO_PinInit(I2C2_SDA_PIN,(dtGPIOConfig){.Mode = I2C2_SDA_ALTER, .PUPD = PullUp, .Speed = Medium, .Type = OpenDrain});
			GPIO_PinInit(I2C2_SCL_PIN,(dtGPIOConfig){.Mode = I2C2_SCL_ALTER, .PUPD = PullUp, .Speed = Medium, .Type = OpenDrain});
			RCC_ClockEnable(RCC_I2C2,Enable);
#if defined(MCU_G071) || defined(MCU_G070)
			NVIC_EnableIRQ(IRQ_I2C2);
#elif defined(MCU_L433)
			NVIC_EnableIRQ(IRQ_I2C2_EV);
#endif
#endif
		}
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
	}
}

void I2C_Start(dtI2CInstance Instance, dtI2cSessionType SessionType, uint8 SlaveAdd, uint8* RegisterAddress, uint8 RegisterLength, uint8* DataPointer, uint8 DataLength)
{
	/* Copy the necessary infos into the own variables of the module */
	RegisterAdd = RegisterAddress;
	RegLen = RegisterLength;
	Data[Instance] = DataPointer;
	DataLen[Instance] = DataLength;
	Session[Instance] = SessionType;

	/* Set the status sign variable to busy */
	Result[Instance] = Busy;
	SecondStart[Instance] = 0;

	/* Initiate the communication session */
	SET_WRITE_TRANSFER_REQ(Instance);
	CLEAR_AUTO_ENABLE(Instance);
	SET_7BIT_ADDRESS_MODE(Instance);
	if(Session[Instance] == I2C_Read)
	{
		DISABLE_RELOAD(Instance);
	}
	else ENABLE_RELOAD(Instance);
	SET_SLAVE_ADDRESS(Instance,SlaveAdd);
	SET_TRANSFER_SIZE(Instance, RegLen);
	GENERATE_START(Instance);

}

dtI2cSessionResult I2C_Result(dtI2CInstance Instance)
{
	return Result[Instance];
}

#if defined(MCU_G071) || defined(MCU_G070)
void I2C1_IRQHandler(void)
#elif defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
void I2C1_EV_IRQHandler(void)
#endif
{
	if(I2C[I2C1]->ISR.Fields.TXIS != 0)
	{
		if(SecondStart[I2C1] == 0) I2C[I2C1]->TXDR.Fields.TXDATA = *RegisterAdd++;
		else I2C[I2C1]->TXDR.Fields.TXDATA = *Data[I2C1]++;
	}
	else if(I2C[I2C1]->ISR.Fields.RXNE != 0)
	{
		*Data[I2C1]++ = I2C[I2C1]->RXDR.Fields.RXDATA;
		DataLen[I2C1]--;
	}
	else if(I2C[I2C1]->ISR.Fields.TC != 0)
	{
		if(Session[I2C1] == I2C_Read && (DataLen[I2C1] > 0))
		{
			if(DataLen[I2C1] > 255)
			{
				/* Set NBYTES to 255 */
				SET_TRANSFER_SIZE(I2C1, 255);
			}
			else
			{
				/* Set NBYYTES to the left amount */
				SET_TRANSFER_SIZE(I2C1, DataLen[I2C1]);
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
	else if(I2C[I2C1]->ISR.Fields.TCR != 0)
	{
		if(Session[I2C1] == I2C_Read)
		{

		}
		else
		{
			if(DataLen[I2C1] > 255)
			{
				/* Set to NBYTES 255 */
				SET_TRANSFER_SIZE(I2C1, 255);
			}
			else
			{
				/* Set to NBYTES the left amount */
				SET_TRANSFER_SIZE(I2C1, DataLen[I2C1]);

				/* Disable reload mode */
				DISABLE_RELOAD(I2C1);

				/* Enable auto end mode */
				SET_AUTO_ENABLE(I2C1);
			}
			SecondStart[I2C1] = 1;
		}
	}
	else if(I2C[I2C1]->ISR.Fields.STOPF != 0)
	{
		CLEAR_STOP_FLAG(I2C1);
		Result[I2C1] = Done;
		if(I2C[I2C1]->ISR.Fields.NACKF != 0)
		{
			CLEAR_NACK_FLAG(I2C1);
			Result[I2C1] = Error;
		}
	}
}

#if defined(MCU_G071) || defined(MCU_G070)
void I2C2_IRQHandler(void)
#elif defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
void I2C2_EV_IRQHandler(void)
#endif
{
	if(I2C[I2C2]->ISR.Fields.TXIS != 0)
		{
			if(SecondStart[I2C2] == 0) I2C[I2C2]->TXDR.Fields.TXDATA = *RegisterAdd++;
			else I2C[I2C2]->TXDR.Fields.TXDATA = *Data[I2C2]++;
		}
		else if(I2C[I2C2]->ISR.Fields.RXNE != 0)
		{
			*Data[I2C2]++ = I2C[I2C2]->RXDR.Fields.RXDATA;
			DataLen[I2C2]--;
		}
		else if(I2C[I2C2]->ISR.Fields.TC != 0)
		{
			if(Session[I2C2] == I2C_Read && (DataLen[I2C2] > 0))
			{
				if(DataLen[I2C2] > 255)
				{
					/* Set NBYTES to 255 */
					SET_TRANSFER_SIZE(I2C2, 255);
				}
				else
				{
					/* Set NBYYTES to the left amount */
					SET_TRANSFER_SIZE(I2C2, DataLen[I2C2]);
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
			if(Session[1] == I2C_Read)
			{

			}
			else
			{
				if(DataLen[I2C2] > 255)
				{
					/* Set to NBYTES 255 */
					SET_TRANSFER_SIZE(I2C2, 255);
				}
				else
				{
					/* Set to NBYTES the left amount */
					SET_TRANSFER_SIZE(I2C2, DataLen[I2C2]);

					/* Disable reload mode */
					DISABLE_RELOAD(I2C2);

					/* Enable auto end mode */
					SET_AUTO_ENABLE(I2C2);
				}
				SecondStart[I2C2] = 1;
			}
		}
		else if(I2C[I2C2]->ISR.Fields.STOPF != 0)
		{
			CLEAR_STOP_FLAG(I2C2);
			Result[I2C2] = Done;
			if(I2C[I2C2]->ISR.Fields.NACKF != 0)
			{
				CLEAR_NACK_FLAG(I2C2);
				Result[I2C2] = Error;
			}
		}
}

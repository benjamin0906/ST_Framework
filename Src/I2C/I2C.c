/*
 * I2C.c
 *
 *  Created on: 2020. okt. 16.
 *      Author: BodnarB
 */


#include "I2C.h"
#include "NVIC.h"
#include "GPIO.h"
#include "RCC.h"
#include "config.h"

#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
#include "I2C_Types.h"
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
void I2C_StopPeripheral(dtI2CInstance Instance);
void I2C_StartPeripheral(dtI2CInstance Instance);
void I2C_Start(dtI2CInstance Instance, dtI2cSessionType SessionType, const uint8 SlaveAdd, const uint8* const RegisterAddress, uint8 RegisterLength, uint8* Data, uint8 DataLength);
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
#if defined(MCU_G071) || defined(MCU_G070)
			NVIC_EnableIRQ(IRQ_I2C2);
#elif defined(MCU_L433)
			NVIC_EnableIRQ(IRQ_I2C2_EV);
#endif
#endif
		}
		I2C_StartPeripheral(Instance);
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

void I2C_StopPeripheral(dtI2CInstance Instance)
{
	dtRCCClock peripheral;
	switch(Instance)
	{
	case I2C1:
		peripheral = RCC_I2C1;
		break;
	case I2C2:
		peripheral = RCC_I2C2;
		break;
	}
	RCC_ClockEnable(peripheral,Disable);
}

void I2C_StartPeripheral(dtI2CInstance Instance)
{
	dtRCCClock peripheral;
	switch(Instance)
	{
	case I2C1:
		peripheral = RCC_I2C1;
		break;
	case I2C2:
		peripheral = RCC_I2C2;
		break;
	}
	RCC_ClockEnable(peripheral,Enable);
}

void I2C_Start(dtI2CInstance Instance, dtI2cSessionType SessionType, const uint8 SlaveAdd, const uint8*const RegisterAddress, uint8 RegisterLength, uint8* DataPointer, uint8 DataLength)
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
#elif defined(STM32U0)
#include "RegDefs/I2C_reg.h"

#define SET_WRITE_TRANSFER_REQ(Instance)    \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.RD_WRN = 0;\
    I2C[Instance]->CR2 = tCr2; \
}

#define CLEAR_AUTO_ENABLE(Instance) \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.AUTOEND = 0;\
    I2C[Instance]->CR2 = tCr2; \
}

#define SET_7BIT_ADDRESS_MODE(Instance) \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.HEAD10R = 1;\
    I2C[Instance]->CR2 = tCr2; \
}

#define DISABLE_RELOAD(Instance)    \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.RELOAD = 0;\
    I2C[Instance]->CR2 = tCr2; \
}

#define ENABLE_RELOAD(Instance) \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.RELOAD = 1;\
    I2C[Instance]->CR2 = tCr2; \
}

#define SET_SLAVE_ADDRESS(Instance, x)  \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.SADD = x<<1;\
    I2C[Instance]->CR2 = tCr2; \
}

#define SET_TRANSFER_SIZE(Instance, Size)   \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.NBYTES = Size;\
    I2C[Instance]->CR2 = tCr2; \
}

#define GENERATE_START(Instance)    \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.START = 1;\
    I2C[Instance]->CR2 = tCr2; \
}

#define SET_READ_TRANSFER_REQ(Instance) \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.RD_WRN = 1;\
    I2C[Instance]->CR2 = tCr2; \
}

#define CLEAR_STOP_FLAG(Instance)   \
{\
    dtI2C_ICR tIcr = I2C[Instance]->ICR;\
    tIcr.B.STOPCF = 1;\
    I2C[Instance]->ICR = tIcr; \
}

#define GENERATE_STOP(Instance) \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.STOP = 1;\
    I2C[Instance]->CR2 = tCr2; \
}

#define SET_AUTO_ENABLE(Instance)   \
{\
    dtI2C_CR2 tCr2 = I2C[Instance]->CR2;\
    tCr2.B.AUTOEND = 1;\
    I2C[Instance]->CR2 = tCr2; \
}

#define CLEAR_NACK_FLAG(Instance)   \
{\
    dtI2C_ICR tIcr = I2C[Instance]->ICR;\
    tIcr.B.NACKCF = 1;\
    I2C[Instance]->ICR = tIcr; \
}


static dtI2C *const I2C[3] = {MODULE_I2C_1, MODULE_I2C_2, MODULE_I2C_3};

static const uint8 *RegisterAdd;
static uint8 RegLen;
static uint8 *Data[3];
static uint8 DataLen[3];
static dtI2cSessionResult Result[3];
static uint8 SecondStart[3];
dtI2cSessionType Session[3];

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config);
void I2C_StartPeripheral(dtI2CInstance Instance);
void I2C_StopPeripheral(dtI2CInstance Instance);
void I2C_Start(dtI2CInstance Instance, dtI2cSessionType SessionType, const uint8 SlaveAdd, const uint8*const RegisterAddress, uint8 RegisterLength, uint8* DataPointer, uint8 DataLength);
dtI2cSessionResult I2C_Result(dtI2CInstance Instance);

void I2C_Init(dtI2CInstance Instance, dtI2cConfig config)
{
    dtIRQs irq = IRQ_I2C1;
    if(I2C[Instance]->CR1.B.PE == 0)
    {
        dtI2C_CR1 tCr = {.U = 0};
        volatile uint8 delay = 5;
        I2C_StartPeripheral(Instance);
        I2C[Instance]->CR1.U = 0;
        while(delay > 0) delay--;
        tCr.B.ANFOFF = !config.AnalogFilter;
        tCr.B.PE = 1;
        tCr.B.TXIE = 1;
        tCr.B.RXIE = 1;
        tCr.B.STOPIE = 1;
        tCr.B.TCIE = 1;
        I2C[Instance]->TIMINGR.U = config.TimingReg;
        I2C[Instance]->CR1 = tCr;
    }
    if(Instance != I2C1)
    {
        irq = IRQ_I2C2_3_4;
    }
    NVIC_EnableIRQ(irq);
}

void I2C_StartPeripheral(dtI2CInstance Instance)
{
    dtRCCClock peripheral;
    switch(Instance)
    {
    case I2C1:
        peripheral = RCC_I2C1;
        break;
    case I2C2:
        peripheral = RCC_I2C2;
        break;
    case I2C3:
        peripheral = RCC_I2C3;
    }
    RCC_ClockEnable(peripheral, Enable);
}

void I2C_StopPeripheral(dtI2CInstance Instance)
{
    dtRCCClock peripheral;
    switch(Instance)
    {
    case I2C1:
        peripheral = RCC_I2C1;
        break;
    case I2C2:
        peripheral = RCC_I2C2;
        break;
    case I2C3:
        peripheral = RCC_I2C3;
    }
    RCC_ClockEnable(peripheral,Disable);
}

void I2C_Start(dtI2CInstance Instance, dtI2cSessionType SessionType, const uint8 SlaveAdd, const uint8 *const RegisterAddress, uint8 RegisterLength, uint8* DataPointer, uint8 DataLength)
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
    dtI2C_CR2 tCr2 = {.U = 0};
    tCr2.B.RD_WRN = 0;
    tCr2.B.AUTOEND = 0;
    tCr2.B.HEAD10R = 1;
    //SET_WRITE_TRANSFER_REQ(Instance);
    //CLEAR_AUTO_ENABLE(Instance);
    //SET_7BIT_ADDRESS_MODE(Instance);
    if(Session[Instance] != I2C_Read)
    {
        //DISABLE_RELOAD(Instance);
        tCr2.B.RELOAD = 1;
    }
    //else ENABLE_RELOAD(Instance);
    //SET_SLAVE_ADDRESS(Instance,SlaveAdd);
    tCr2.B.SADD = SlaveAdd<<1;
    tCr2.B.NBYTES = RegLen;
    tCr2.B.START = 1;
    //SET_TRANSFER_SIZE(Instance, RegLen);
    //GENERATE_START(Instance);
    I2C[Instance]->CR2 = tCr2;
}

dtI2cSessionResult I2C_Result(dtI2CInstance Instance)
{
    return Result[Instance];
}

void I2C1_IRQHandler(void)
{
    dtI2C_ISR tISR = I2C[I2C1]->ISR;
    if(tISR.B.TXIS != 0)
    {
        dtI2C_TXDR tTx = {.U = 0};
        if(SecondStart[I2C1] == 0)
        {
            tTx.B.TXDATA = *RegisterAdd++;
        }
        else
        {
            tTx.B.TXDATA = *Data[I2C1]++;
        }
        I2C[I2C1]->TXDR = tTx;
    }
    else if(tISR.B.RXNE != 0)
    {
        dtI2C_RXDR tRx = I2C[I2C1]->RXDR;
        *Data[I2C1]++ = tRx.B.RXDATA;
        DataLen[I2C1]--;
    }
    else if(tISR.B.TC != 0)
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
    else if(tISR.B.TCR != 0)
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
    else if(tISR.B.STOPF != 0)
    {
        CLEAR_STOP_FLAG(I2C1);
        Result[I2C1] = Done;
        if(tISR.B.NACKF != 0)
        {
            CLEAR_NACK_FLAG(I2C1);
            Result[I2C1] = Error;
        }
    }
}

void I2C2_I2C3_IRQHandler(void)
{

}

#else
#warning "NO CPU IS DEFINED"
#endif

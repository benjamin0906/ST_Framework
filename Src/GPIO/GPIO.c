/*
 * GPIO.c
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#include "GPIO_Types.h"
#include "GPIO.h"

/* ----------Register definition section---------- */
#ifndef MODULE_TEST
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070)
static dtGPIO *GPIOA = (dtGPIO*) 0x40020000;
#elif defined(MCU_L433)
static dtGPIO *GPIOA = (dtGPIO*) 0x48000000;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070)
static dtGPIO *GPIOB = (dtGPIO*) 0x40020400;
#elif defined(MCU_L433)
static dtGPIO *GPIOB = (dtGPIO*) 0x48000400;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070)
static dtGPIO *GPIOC = (dtGPIO*) 0x40020800;
#elif defined(MCU_L433)
static dtGPIO *GPIOC = (dtGPIO*) 0x48000800;
#endif
#if defined(MCU_F446) || defined(MCU_G070)
static dtGPIO *GPIOD = (dtGPIO*) 0x40020C00;
#elif defined(MCU_L433)
static dtGPIO *GPIOD = (dtGPIO*) 0x48000C00;
#endif
#if defined(MCU_F446)
static dtGPIO *GPIOE = (dtGPIO*) 0x40021000;
#elif defined(MCU_L433)
static dtGPIO *GPIOE = (dtGPIO*) 0x48001000;
#endif
#if defined(MCU_F446) || defined(MCU_G070)
static dtGPIO *GPIOF = (dtGPIO*) 0x40021400;
#endif
#if defined(MCU_F446)
static dtGPIO *GPIOG = (dtGPIO*) 0x40021800;
#endif
#if defined(MCU_F446) || defined(MCU_F410)
static dtGPIO *GPIOH = (dtGPIO*) 0x40021C00;
#elif defined(MCU_L433)
static dtGPIO *GPIOH = (dtGPIO*) 0x48001C00;
#endif
#else
#include "TestEnv.h"
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433)
static dtGPIO *GPIOA = (dtGPIO*) &TestGPIOA;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433)
static dtGPIO *GPIOB = (dtGPIO*) &TestGPIOB;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433)
static dtGPIO *GPIOC = (dtGPIO*) &TestGPIOC;
#endif
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_L433)
static dtGPIO *GPIOD = (dtGPIO*) &TestGPIOD;
#endif
#if defined(MCU_F446) || defined(MCU_L433)
static dtGPIO *GPIOE = (dtGPIO*) &TestGPIOE;
#endif
#if defined(MCU_F446) || defined(MCU_G070)
static dtGPIO *GPIOF = (dtGPIO*) &TestGPIOF;
#endif
#if defined(MCU_F446)
static dtGPIO *GPIOG = (dtGPIO*) &TestGPIOG;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
static dtGPIO *GPIOH = (dtGPIO*) &TestGPIOH;
#endif
#endif
/* ----------End of register definition section---------- */

void GPIO_PinInit(dtGPIOs Gpio, dtGPIOConfig Config);
void GPIO_Set(dtGPIOs Gpio, dtPortValue Value);
static inline dtGPIO* GetPort(dtGPIOs Gpio);

void GPIO_PinInit(dtGPIOs Gpio, dtGPIOConfig Config)
{
	uint32 FieldId = (Gpio & 0xF)<<1;
	uint32 ClearMask = ~(3 << FieldId);
	dtGPIO *Temp = GetPort(Gpio);
	if(Temp != 0)
	{
		/* Setting the mode and the alternate function. */
		Temp->MODER.Word &= ClearMask;
		if(Config.Mode == Input)
		{
			/* Nothing to do */
		}
		else if(Config.Mode == Output) Temp->MODER.Word |= 1 << FieldId;
		else if(Config.Mode == Analog) Temp->MODER.Word |= 3 << FieldId;
		else
		{
			Temp->MODER.Word |= 2 << FieldId;
			if(FieldId >= 16)
			{
				uint8 shifter = (FieldId-16)<<1;
				uint32 AltFieldClearMask = ~(0xF << shifter);
				Temp->AFR.AFRH.Word &= AltFieldClearMask;
				Temp->AFR.AFRH.Word |= (Config.Mode-3) << shifter;
			}
			else
			{
				uint8 shifter = (FieldId)<<1;
				uint32 AltFieldClearMask = ~(0xF << shifter);
				Temp->AFR.AFRL.Word &= AltFieldClearMask;
				Temp->AFR.AFRL.Word |= (Config.Mode-3) << shifter;
			}
		}

		/* Setting the type of the pin (push-pull or open-drain) */
		Temp->OTYPER.Word &= ~(1 << (FieldId>>1));
		if(Config.Type == OpenDrain) Temp->OTYPER.Word |= (1 << (FieldId>>1));

		/* Setting the speed of the pin */
		Temp->OSPEEDER.Word &= ClearMask;
		Temp->OSPEEDER.Word |= Config.Speed << (FieldId);

		Temp->PUPDR.Word &= ClearMask;
		Temp->PUPDR.Word |= Config.PUPD << (FieldId);
	}
}

void GPIO_Set(dtGPIOs Gpio, dtPortValue Value)
{
	uint32 Pin = 1 << (Gpio & 0xF);
	dtGPIO *Temp = GetPort(Gpio);

	if((Value == Clear) || ((Value == Toggle) && ((Temp->ODR.Word & Pin) != 0))) Pin <<= 16;

	Temp->BSRR.Word |= Pin;
}

static inline dtGPIO* GetPort(dtGPIOs Gpio)
{
	dtGPIO *Temp = 0;
	if(Gpio >= PortH_0)
	{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
		Temp = GPIOH;
#endif
	}
	else if(Gpio >= PortG_0)
	{
#if defined(MCU_F446)
		Temp = GPIOG;
#endif
	}
	else if(Gpio >= PortF_0)
	{
#if defined(MCU_F446) || defined(MCU_G070)
		Temp = GPIOF;
#endif
	}
	else if(Gpio >= PortE_0)
	{
#if defined(MCU_F446) || defined(MCU_L433)
		Temp = GPIOE;
#endif
	}
	else if(Gpio >= PortD_0)
	{
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_L433)
		Temp = GPIOD;
#endif
	}
	else if(Gpio >= PortC_0)
	{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433)
		Temp = GPIOC;
#endif
	}
	else if(Gpio >= PortB_0)
	{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433)
		Temp = GPIOB;
#endif
	}
	else if(Gpio >= PortA_0)
	{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433)
		Temp = GPIOA;
#endif
	}
	return Temp;
}

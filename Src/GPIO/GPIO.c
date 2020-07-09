/*
 * GPIO.c
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#include "GPIO_Types.h"
#include "GPIO.h"

static dtGPIO *GPIOA = (dtGPIO*) 0x40020000;
static dtGPIO *GPIOB = (dtGPIO*) 0x40020400;
static dtGPIO *GPIOC = (dtGPIO*) 0x40020800;
static dtGPIO *GPIOD = (dtGPIO*) 0x40020C00;
static dtGPIO *GPIOE = (dtGPIO*) 0x40021000;
static dtGPIO *GPIOF = (dtGPIO*) 0x40021400;
static dtGPIO *GPIOG = (dtGPIO*) 0x40021800;
static dtGPIO *GPIOH = (dtGPIO*) 0x40021C00;

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
		Temp->OTYPER.Word &= ~(1 << FieldId);
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
	if(Gpio >= PortH_0) Temp = GPIOH;
#ifdef MCU_F446
	else if(Gpio >= PortG_0) Temp = GPIOG;
	else if(Gpio >= PortF_0) Temp = GPIOF;
	else if(Gpio >= PortE_0) Temp = GPIOE;
	else if(Gpio >= PortD_0) Temp = GPIOD;
#endif
	else if(Gpio >= PortC_0) Temp = GPIOC;
	else if(Gpio >= PortB_0) Temp = GPIOB;
	else if(Gpio >= PortA_0) Temp = GPIOA;
	return Temp;
}

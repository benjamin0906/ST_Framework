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
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *GPIOA = (dtGPIO*) 0x40020000;
#elif defined(MCU_L433)
static dtGPIO *GPIOA = (dtGPIO*) 0x48000000;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *GPIOA = (dtGPIO*) 0x50000000;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *GPIOB = (dtGPIO*) 0x40020400;
#elif defined(MCU_L433)
static dtGPIO *GPIOB = (dtGPIO*) 0x48000400;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *GPIOB = (dtGPIO*) 0x50000400;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *GPIOC = (dtGPIO*) 0x40020800;
#elif defined(MCU_L433)
static dtGPIO *GPIOC = (dtGPIO*) 0x48000800;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *GPIOC = (dtGPIO*) 0x50000800;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *GPIOD = (dtGPIO*) 0x40020C00;
#elif defined(MCU_L433)
static dtGPIO *GPIOD = (dtGPIO*) 0x48000C00;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *GPIOD = (dtGPIO*) 0x50000C00;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *GPIOE = (dtGPIO*) 0x40021000;
#elif defined(MCU_L433)
static dtGPIO *GPIOE = (dtGPIO*) 0x48001000;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *GPIOF = (dtGPIO*) 0x40021400;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *GPIOF = (dtGPIO*) 0x50001400;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *GPIOG = (dtGPIO*) 0x40021800;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *GPIOH = (dtGPIO*) 0x40021C00;
#elif defined(MCU_L433)
static dtGPIO *GPIOH = (dtGPIO*) 0x48001C00;
#endif
#if defined(MCU_F415)
static dtGPIO *GPIOI = (dtGPIO*) 0x40022000;
#endif
#if defined(MCU_F415)
static dtGPIO *GPIOJ = (dtGPIO*) 0x40022400;
#endif
#if defined(MCU_F415)
static dtGPIO *GPIOK = (dtGPIO*) 0x40022800;
#endif
#else
#include "TestEnv.h"
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *GPIOA = (dtGPIO*) &TestGPIOA;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *GPIOB = (dtGPIO*) &TestGPIOB;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *GPIOC = (dtGPIO*) &TestGPIOC;
#endif
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *GPIOD = (dtGPIO*) &TestGPIOD;
#endif
#if defined(MCU_F446) || defined(MCU_L433)
static dtGPIO *GPIOE = (dtGPIO*) &TestGPIOE;
#endif
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071)
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
uint8 GPIO_Get(dtGPIOs Gpio);
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

uint8 GPIO_Get(dtGPIOs Gpio)
{
	uint8 ret = 0;
	uint32 Pin = (Gpio & 0xF);
	dtGPIO *Temp = GetPort(Gpio);
	ret = Temp->IDR.Word>>Pin & 1;
	return ret;
}

static inline dtGPIO* GetPort(dtGPIOs Gpio)
{
	dtGPIO *Temp = 0;

#if defined(MCU_F415)
	if(Gpio >= PortK_0)
	{
		Temp = GPIOK;
	}
	else
#endif
	{
#if defined(MCU_F415)
		if(Gpio >= PortJ_0)
		{
			Temp = GPIOJ;
		}
		else
#endif
		{
#if defined(MCU_F415)
			if(Gpio >= PortI_0)
			{
				Temp = GPIOI;
			}
			else
#endif
			{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_F415)
				if(Gpio >= PortH_0)
				{
					Temp = GPIOH;
				}
				else
#endif
				{
#if defined(MCU_F446) || defined(MCU_F415)
					if(Gpio >= PortG_0)
					{
					Temp = GPIOG;
					}
					else
#endif
					{
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F415)
						if(Gpio >= PortF_0)
						{
							Temp = GPIOF;
						}
						else
#endif
						{
#if defined(MCU_F446) || defined(MCU_L433) || defined(MCU_F415)
							if(Gpio >= PortE_0)
							{
								Temp = GPIOE;
							}
							else
#endif
							{
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415)
								if(Gpio >= PortD_0)
								{
									Temp = GPIOD;
								}
								else
#endif
								{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415)
									if(Gpio >= PortC_0)
									{
										Temp = GPIOC;
									}
									else
#endif
									{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415)
										if(Gpio >= PortB_0)
										{
											Temp = GPIOB;
										}
										else
#endif
										{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415)
											if(Gpio >= PortA_0)
											{
												Temp = GPIOA;
											}
#endif
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return Temp;
}

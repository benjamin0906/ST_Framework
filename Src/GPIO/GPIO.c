/*
 * GPIO.c
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
#include "GPIO_Types.h"
#elif defined(STM32U0)
#include "RegDefs/GPIO_regdef.h"
#endif
#include "GPIO.h"

/* ----------Register definition section---------- */
#ifndef MODULE_TEST
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *const GPIOA = (dtGPIO*) 0x40020000;
#elif defined(MCU_L433) || defined(MCU_L476)
static dtGPIO *const GPIOA = (dtGPIO*) 0x48000000;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *const GPIOA = (dtGPIO*) 0x50000000;
#elif defined(STM32U0)
static volatile dtGPIO *const GPIO = (dtGPIO*) 0x50000000;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *const GPIOB = (dtGPIO*) 0x40020400;
#elif defined(MCU_L433) || defined(MCU_L476)
static dtGPIO *const GPIOB = (dtGPIO*) 0x48000400;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *const GPIOB = (dtGPIO*) 0x50000400;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *const GPIOC = (dtGPIO*) 0x40020800;
#elif defined(MCU_L433) || defined(MCU_L476)
static dtGPIO *const GPIOC = (dtGPIO*) 0x48000800;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *const GPIOC = (dtGPIO*) 0x50000800;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *const GPIOD = (dtGPIO*) 0x40020C00;
#elif defined(MCU_L433) || defined(MCU_L476)
static dtGPIO *const GPIOD = (dtGPIO*) 0x48000C00;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *const GPIOD = (dtGPIO*) 0x50000C00;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *const GPIOE = (dtGPIO*) 0x40021000;
#elif defined(MCU_L433) || defined(MCU_L476)
static dtGPIO *const GPIOE = (dtGPIO*) 0x48001000;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *const GPIOF = (dtGPIO*) 0x40021400;
#elif defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *const GPIOF = (dtGPIO*) 0x50001400;
#elif defined(MCU_L476)
static dtGPIO *const GPIOF = (dtGPIO*) 0x48001400;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtGPIO *const GPIOG = (dtGPIO*) 0x40021800;
#elif defined(MCU_L476)
static dtGPIO *const GPIOG = (dtGPIO*) 0x48001800;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtGPIO *const GPIOH = (dtGPIO*) 0x40021C00;
#elif defined(MCU_L433) || defined(MCU_L476)
static dtGPIO *const GPIOH = (dtGPIO*) 0x48001C00;
#endif
#if defined(MCU_F415)
static dtGPIO *const GPIOI = (dtGPIO*) 0x40022000;
#elif defined(MCU_L476)
static dtGPIO *const GPIOI = (dtGPIO*) 0x48002000;
#endif
#if defined(MCU_F415)
static dtGPIO *const GPIOJ = (dtGPIO*) 0x40022400;
#endif
#if defined(MCU_F415)
static dtGPIO *const GPIOK = (dtGPIO*) 0x40022800;
#endif
#else
#include "TestEnv.h"
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *const GPIOA = (dtGPIO*) &TestGPIOA;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *const GPIOB = (dtGPIO*) &TestGPIOB;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *const GPIOC = (dtGPIO*) &TestGPIOC;
#endif
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433)
static dtGPIO *const GPIOD = (dtGPIO*) &TestGPIOD;
#endif
#if defined(MCU_F446) || defined(MCU_L433)
static dtGPIO *const GPIOE = (dtGPIO*) &TestGPIOE;
#endif
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071)
static dtGPIO *const GPIOF = (dtGPIO*) &TestGPIOF;
#endif
#if defined(MCU_F446)
static dtGPIO *const GPIOG = (dtGPIO*) &TestGPIOG;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
static dtGPIO *const GPIOH = (dtGPIO*) &TestGPIOH;dtGPIO *
#endif
#endif
/* ----------End of register definition section---------- */

void GPIO_PinInit(dtGPIOs Gpio, const dtGPIOConfig Config);
void GPIO_PinDeinit(dtGPIOs Gpio);
void GPIO_Set(dtGPIOs Gpio, dtPortValue Value);
uint8 GPIO_Get(dtGPIOs Gpio);
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
static inline dtGPIO* GetPort(dtGPIOs Gpio);
#elif defined(STM32U0)
static inline dtGPIOx* GetPort(dtGPIOs Gpio);
#endif

void GPIO_PinInit(dtGPIOs Gpio, const dtGPIOConfig Config)
{
	uint32 FieldId = (Gpio & 0xF)<<1;
	uint32 ClearMask = ~(3 << FieldId);
	dtGPIOx *Temp = GetPort(Gpio);
	if(Temp != 0)
	{
		/* Setting the mode and the alternate function. */
		Temp->MODER.U &= ClearMask;
		if(Config.Mode == Input)
		{
			/* Nothing to do */
		}
		else if(Config.Mode == Output)
		{
	        if(Config.DefState == 0)
	        {
	            Temp->ODR.U &= ~(1<<(Gpio & 0xF));
	        }
	        else
	        {
	            Temp->ODR.U |= (1<<(Gpio & 0xF));
	        }
		    Temp->MODER.U |= 1 << FieldId;
		}
		else if(Config.Mode == Analog) Temp->MODER.U |= 3 << FieldId;
		else
		{
			Temp->MODER.U |= 2 << FieldId;
			if(FieldId >= 16)
			{
				uint8 shifter = (FieldId-16)<<1;
				uint32 AltFieldClearMask = ~(0xF << shifter);
				Temp->AFRH.U &= AltFieldClearMask;
				Temp->AFRH.U |= (Config.Mode-3) << shifter;
			}
			else
			{
				uint8 shifter = (FieldId)<<1;
				uint32 AltFieldClearMask = ~(0xF << shifter);
				Temp->AFRL.U &= AltFieldClearMask;
				Temp->AFRL.U |= (Config.Mode-3) << shifter;
			}
		}

		/* Setting the type of the pin (push-pull or open-drain) */
		Temp->OTYPER.U &= ~(1 << (FieldId>>1));
		if(Config.Type == OpenDrain) Temp->OTYPER.U |= (1 << (FieldId>>1));

		/* Setting the speed of the pin */
		Temp->OSPEEDR.U &= ClearMask;
		Temp->OSPEEDR.U |= Config.Speed << (FieldId);

		Temp->PUPDR.U &= ClearMask;
		Temp->PUPDR.U |= Config.PUPD << (FieldId);
	}
}

void GPIO_Set(dtGPIOs Gpio, dtPortValue Value)
{
	uint32 Pin = 1 << (Gpio & 0xF);
	dtGPIOx *Temp = GetPort(Gpio);

	if((Value == Clear) || ((Value == Toggle) && ((Temp->ODR.U & Pin) != 0))) Pin <<= 16;

	Temp->BSRR.U |= Pin;
}

uint8 GPIO_Get(dtGPIOs Gpio)
{
	uint8 ret = 0;
	uint32 Pin = (Gpio & 0xF);
	ret = GetPort(Gpio)->IDR.U>>Pin & 1;
	return ret;
}
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
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
			if(Gpio >= PortI_0) || defined(MCU_L476)
			{
				Temp = GPIOI;
			}
			else
#endif
			{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
				if(Gpio >= PortH_0)
				{
					Temp = GPIOH;
				}
				else
#endif
				{
#if defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
					if(Gpio >= PortG_0)
					{
					Temp = GPIOG;
					}
					else
#endif
					{
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
						if(Gpio >= PortF_0)
						{
							Temp = GPIOF;
						}
						else
#endif
						{
#if defined(MCU_F446) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
							if(Gpio >= PortE_0)
							{
								Temp = GPIOE;
							}
							else
#endif
							{
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
								if(Gpio >= PortD_0)
								{
									Temp = GPIOD;
								}
								else
#endif
								{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
									if(Gpio >= PortC_0)
									{
										Temp = GPIOC;
									}
									else
#endif
									{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
										if(Gpio >= PortB_0)
										{
											Temp = GPIOB;
										}
										else
#endif
										{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
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
#elif defined(STM32U0)
static inline dtGPIOx* GetPort(dtGPIOs Gpio)
{
    return &GPIO->GPIOs[Gpio>>4];
}
#endif

void GPIO_PinDeinit(dtGPIOs Gpio)
{
    uint32 FieldId = (Gpio & 0xF)<<1;
    uint32 ClearMask = ~(3 << FieldId);
    uint8 shifter = (FieldId-16)<<1;
    uint32 AltFieldClearMask = ~(0xF << shifter);
    dtGPIOx *Temp = GetPort(Gpio);

    Temp->MODER.U |= ~ClearMask;
    if(FieldId >= 16) Temp->AFRH.U &= AltFieldClearMask;
    else Temp->AFRL.U &= AltFieldClearMask;
    Temp->PUPDR.U &= ClearMask;
    Temp->OTYPER.U &= ~(1 << (FieldId>>1));
    Temp->OSPEEDR.U &= ClearMask;
}

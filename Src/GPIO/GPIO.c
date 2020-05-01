/*
 * GPIO.c
 *
 *  Created on: May 1, 2020
 *      Author: Bodnár Benjamin
 */

#include "GPIO.h"
#include "GPIO_Types.h"

static GPIOx *const Ports[8] = {(GPIOx*)(0x48000000),
								(GPIOx*)(0x48000400),
								(GPIOx*)(0x48000800),
								(GPIOx*)(0x48000C00),
								(GPIOx*)(0x48001000),
								(GPIOx*)(0x48001400),
								(GPIOx*)(0x48001800),
								(GPIOx*)(0x48001C00)};

void GPIO_Set(uint8 port, uint8 pin, uint32 settings)
{
	uint32 temp = 0;
	uint32 RegisterTemporary;

	RegisterTemporary = Ports[port]->MODER;
	RegisterTemporary &= ~((uint32)(3<<(pin<<1)));
	temp = settings & 0x1F;
	if(temp == GPIO_ANALOG)
	{
		Ports[port]->ASCR = 1<<pin;
		RegisterTemporary |= ((uint32)(3<<(pin<<1)));
	}
	else if(temp == GPIO_OUTPUT) RegisterTemporary |= ((uint32)(1<<(pin<<1)));
	else if(temp >= GPIO_ALT0)
	{
		if(pin <= 7)
		{
			uint32 AltTemp = Ports[port]->AFRL;
			AltTemp &= ~((uint32)(0xF<<(pin<<4)));
			AltTemp |= temp - GPIO_ALT0;
			Ports[port]->AFRL = AltTemp;
		}
		else
		{
			uint32 AltTemp = Ports[port]->AFRH;
			AltTemp &= ~((uint32)(0xF<<((pin-8)<<4)));
			AltTemp |= temp - GPIO_ALT0;
			Ports[port]->AFRH = AltTemp;
		}
		RegisterTemporary |= ((uint32)(2<<(pin<<1)));
	}
	Ports[port]->MODER = RegisterTemporary;

	/* Set the pin type option */
	temp = settings & 0x60;
	if(temp == GPIO_OTYPE_OD) Ports[port]->OTYPER |= 1<<pin;
	else Ports[port]->OTYPER &= ~((uint32)(1<<pin));

	/* Set the speed options */
	temp = settings & 0x380;
	RegisterTemporary = Ports[port]->OSPEEDR;
	RegisterTemporary &= ~((uint32)(3<<(pin<<1)));
	switch(temp)
	{
	case GPIO_OSPEED_VHS:
		RegisterTemporary |= ((uint32)(3<<(pin<<1)));
		break;
	case GPIO_OSPEED_HS:
		RegisterTemporary |= ((uint32)(2<<(pin<<1)));
		break;
	case GPIO_OSPEED_MS:
		RegisterTemporary |= ((uint32)(1<<(pin<<1)));
		break;
	case GPIO_OSPEED_LS:
		break;
	}
	Ports[port]->OSPEEDR = RegisterTemporary;

	/* Set the pulling options */
	temp = settings & 0xC00;
	RegisterTemporary = Ports[port]->PUPDR;
	RegisterTemporary &= ~((uint32)(3<<(pin<<1)));
	switch(temp)
	{
	case GPIO_PULL_U:
		RegisterTemporary |= ((uint32)(1<<(pin<<1)));
		break;
	case GPIO_PULL_D:
		RegisterTemporary |= ((uint32)(2<<(pin<<1)));
		break;
	case GPIO_PULL_NO:
		break;
	}
	Ports[port]->PUPDR = RegisterTemporary;
}

void GPIO_Write(uint8 port, uint8 pin, uint8 value)
{
	if(value != 0) Ports[port]->BSRR = 1<<pin;
	else Ports[port]->BRR = 1<<pin;
}

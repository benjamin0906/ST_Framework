/*
 * GPIO.c
 *
 *  Created on: May 1, 2020
 *      Author: Bodnár Benjamin
 */

#include "GPIO.h"
#include "GPIO_Types.h"

static GPIOx *const Ports[8] = {(GPIOx*)(0x48000000),//GPIO_A
								(GPIOx*)(0x48000400),//GPIO_B
								(GPIOx*)(0x48000800),//GPIO_C
								(GPIOx*)(0x48000C00),//GPIO_D
								(GPIOx*)(0x48001000),//GPIO_E
								(GPIOx*)(0x48001400),//GPIO_F
								(GPIOx*)(0x48001800),//GPIO_G
								(GPIOx*)(0x48001C00) //GPIO_H
};

void GPIO_Set(uint8 port, uint8 pin, uint32 options);
void GPIO_Write(uint8 port, uint8 pin, uint8 value);
uint8 GPIO_Read(uint8 port, uint8 pin);
void GPIO_Toggle(uint8 port, uint8 pin);

void GPIO_Set(uint8 port, uint8 pin, uint32 options)
{
	uint32 temp = 0;
	uint32 RegisterTemporary;

	/* Save temporarily the value of the register */
	RegisterTemporary = Ports[port]->MODER;

	/* Clear the bitfield specified by the pin */
	RegisterTemporary &= ~((uint32)(3<<(pin<<1)));

	/* Get the proper bitfield from the compressed options parameter */
	temp = options & 0x1F;
	if(temp == GPIO_ANALOG)
	{
		/* TODO: Not every case should tie the analog pin to the ADC eg.: OPAMP usage */
		Ports[port]->ASCR = 1<<pin;

		/* Set the pin mode bitfield to analog according to the pin. */
		RegisterTemporary |= ((uint32)(3<<(pin<<1)));
	}
	/* Set the pin mode bitfield to output according to the pin. */
	else if(temp == GPIO_OUTPUT) RegisterTemporary |= ((uint32)(1<<(pin<<1)));
	else if(temp >= GPIO_ALT0)
	{
		/* In case of an alternate function, the function will be set with the pin mode setting. */
		if(pin <= 7)
		{
			uint32 AltTemp = Ports[port]->AFRL;

			/*Zeroing the specified bitfield defined by the pin*/
			AltTemp &= ~((uint32)(0xF<<(pin<<2)));

			/* Give value to the specified bitfield defined by the pin */
			AltTemp |= (temp - GPIO_ALT0)<<(pin<<2);
			Ports[port]->AFRL = AltTemp;
		}
		else
		{
			uint32 AltTemp = Ports[port]->AFRH;
			AltTemp &= ~((uint32)(0xF<<((pin-8)<<2)));
			AltTemp |= (temp - GPIO_ALT0)<<((pin-8)<<2);
			Ports[port]->AFRH = AltTemp;
		}
		RegisterTemporary |= ((uint32)(2<<(pin<<1)));
	}
	Ports[port]->MODER = RegisterTemporary;

	/* Set the pin type option */
	temp = options & 0x60;
	if(temp == GPIO_OTYPE_OD) Ports[port]->OTYPER |= 1<<pin;
	else Ports[port]->OTYPER &= ~((uint32)(1<<pin));

	/* Set the speed options */
	temp = options & 0x380;
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
	temp = options & 0xC00;
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

uint8 GPIO_Read(uint8 port, uint8 pin)
{
	return (Ports[port]->IDR & 1<<pin) != 0;
}

void GPIO_Toggle(uint8 port, uint8 pin)
{
	if((Ports[port]->ODR & (1<<pin)) != 0) Ports[port]->BRR = (1<<pin);
	else Ports[port]->BSRR = (1<<pin);
}

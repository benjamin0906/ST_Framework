/*
 * GPIO_Types.h
 *
 *  Created on: May 1, 2020
 *      Author: Bodnár Benjamin
 */

#ifndef GPIO_GPIO_TYPES_H_
#define GPIO_GPIO_TYPES_H_

typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
	uint32 BRR;
	uint32 ASCR;
	uint8 Reserved[0x3D4];
} GPIOx;

typedef struct
{
	GPIOx GPIO[8];
} GPIOs;

#endif /* GPIO_GPIO_TYPES_H_ */

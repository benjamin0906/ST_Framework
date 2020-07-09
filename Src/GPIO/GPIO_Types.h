/*
 * GPIO_Types.h
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#ifndef GPIO_GPIO_TYPES_H_
#define GPIO_GPIO_TYPES_H_

#include "types.h"

typedef struct
{
	uint32	PIN0	:2;
	uint32	PIN1	:2;
	uint32	PIN2	:2;
	uint32	PIN3	:2;
	uint32	PIN4	:2;
	uint32	PIN5	:2;
	uint32	PIN6	:2;
	uint32	PIN7	:2;
	uint32	PIN8	:2;
	uint32	PIN9	:2;
	uint32	PIN10	:2;
	uint32	PIN11	:2;
	uint32	PIN12	:2;
	uint32	PIN13	:2;
	uint32	PIN14	:2;
	uint32	PIN15	:2;
} dtTwoBitPins;

typedef struct
{
	uint32	PIN0	:1;
	uint32	PIN1	:1;
	uint32	PIN2	:1;
	uint32	PIN3	:1;
	uint32	PIN4	:1;
	uint32	PIN5	:1;
	uint32	PIN6	:1;
	uint32	PIN7	:1;
	uint32	PIN8	:1;
	uint32	PIN9	:1;
	uint32	PIN10	:1;
	uint32	PIN11	:1;
	uint32	PIN12	:1;
	uint32	PIN13	:1;
	uint32	PIN14	:1;
	uint32	PIN15	:1;
} dtOneBitPins;

typedef union
{
	dtTwoBitPins	Fields;
	uint32 Word;
} dtMODER;

typedef union
{
	dtOneBitPins Fields;
	uint32 Word;
} dtOTYPER;

typedef union
{
	dtTwoBitPins Fields;
	uint32 Word;
} dtOSPEEDER;

typedef union
{
	dtTwoBitPins Fields;
	uint32 Word;
} dtPUPDR;

typedef union
{
	dtOneBitPins Fields;
	uint32 Word;
} dtIDR;

typedef union
{
	dtOneBitPins Fields;
	uint32 Word;
} dtODR;

typedef union
{
	dtOneBitPins BS;
	dtOneBitPins BR;
	uint32 Word;
} dtBSRR;

typedef union
{
	dtOneBitPins Fields;
	uint32		LCKK	:1;
	uint32 Word;
} dtLCKR;

typedef struct
{
	union
	{
		struct
		{
			uint32 AFR0	:4;
			uint32 AFR1	:4;
			uint32 AFR2	:4;
			uint32 AFR3	:4;
			uint32 AFR4	:4;
			uint32 AFR5	:4;
			uint32 AFR6	:4;
			uint32 AFR7	:4;
		} Fields;
		uint32 Word;
	} AFRL;

	union
	{
		struct
		{
			uint32 AFR8		:4;
			uint32 AFR9		:4;
			uint32 AFR10	:4;
			uint32 AFR11	:4;
			uint32 AFR12	:4;
			uint32 AFR13	:4;
			uint32 AFR14	:4;
			uint32 AFR15	:4;
		} Fields;
		uint32 Word;
	} AFRH;
} dtAFR;


typedef struct
{
	dtMODER 	MODER;		//0x00
	dtOTYPER	OTYPER;		//0x04
	dtOSPEEDER	OSPEEDER;	//0x08
	dtPUPDR		PUPDR;		//0x0C
	dtIDR		IDR;		//0x10
	dtODR		ODR;		//0x14
	dtBSRR		BSRR;		//0x18
	dtLCKR		LCKR;		//0x1C
	dtAFR		AFR;		//0x20
} dtGPIO;

#endif /* GPIO_GPIO_TYPES_H_ */

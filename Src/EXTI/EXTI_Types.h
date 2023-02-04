/*
 * EXTI_Types.h
 *
 *  Created on: 2021. ápr. 3.
 *      Author: Benjamin
 */

#ifndef SRC_EXTI_EXTI_TYPES_H_
#define SRC_EXTI_EXTI_TYPES_H_

#include "types.h"

#if defined(MCU_G070)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 Lines	:19;
	} Fields;
} dtLines;

typedef struct
{
	dtLines RSTR;	//0x00
	dtLines FTSR;	//0x04
	dtLines SWIER;	//0x08
	dtLines RPR;	//0x0C
	dtLines FPR;	//0x10
	uint8	Padding[76];	//91 bytes padding
} dtGenConfEvents;

typedef enum
{
	PortA = 0x0,
	PortB,
	PortC,
	PortD,
	PortF = 0x5,
} dtEXTISelect;

typedef struct
{
	dtGenConfEvents GenConfEvents;
	uint8 ExtiCr[16];
	uint8 Padding[16];
	uint32 IMR1;
	uint32 EMR1;
	uint8 Padding2[8];
	uint32 IMR2;
	uint32 EMR2;
} dtEXTI;
#endif

#endif /* SRC_EXTI_EXTI_TYPES_H_ */

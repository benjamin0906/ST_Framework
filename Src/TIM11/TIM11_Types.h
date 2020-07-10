/*
 * TIM11_Types.h
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#ifndef TIM11_TIM11_TYPES_H_
#define TIM11_TIM11_TYPES_H_

#include "types.h"

typedef union
{
	struct
	{
		uint32 CEN	:1;
		uint32 UDIS	:1;
		uint32 URS	:1;
		uint32 		:4;
		uint32 ARPE	:1;
		uint32 CKD	:2;
		uint32 		:22;
	} Fields;
	uint32 Word;
} dtCR;

typedef union
{
	struct
	{
		uint32 UIE	:1;
		uint32 CC1IE:1;
		uint32 		:30;
	} Fields;
	uint32 Word;
} dtDIER;

typedef union
{
	struct
	{
		uint32 UIF	:1;
		uint32 CC1IF:1;
		uint32		:7;
		uint32 CC1OF:1;
		uint32 		:22;
	} Fields;
	uint32 Word;
} dtSR;

typedef union
{
	struct
	{
		uint32 UG	:1;
		uint32 CC1G	:1;
		uint32 		:30;
	} Fields;
	uint32 Word;
} dtEGR;

typedef union
{
	struct
	{
		uint32 CC1S	:2;
		uint32 OC1FE:1;
		uint32 OC1PE:1;
		uint32 OC1M	:3;
		uint32		:25;
	} OutFields;

	struct
	{
		uint32 CC1S	:2;
		uint32 IC1PSC:2;
		uint32 IC1F	:4;
		uint32		:24;
	} InFields;

	uint32 Word;
} dtCCMR1;

typedef union
{
	struct
	{
		uint32 CC1E	:1;
		uint32 CC1P	:1;
		uint32		:1;
		uint32 CC1NP:1;
	} Fields;
	uint32 Word;
} dtCCER;

typedef union
{
	struct
	{
		uint32 TI1_RMP	:2;
		uint32			:30;
	} Fields;
	uint32 Word;
} dtOR;


typedef struct
{
	dtCR 	CR;		//0x00
	uint32	:32;	//0x04
	uint32	SMCR;	//0x08
	dtDIER 	DIER;	//0x0C
	dtSR 	SR;		//0x10
	dtEGR	EGR;	//0x14
	dtCCMR1	CCMR1;	//0x18
	uint32	:32;	//0x1C
	dtCCER	CCER;	//0x20
	uint32	CNT:16;	//0x24
	uint32	:16;	//0x26
	uint32	PSC:16;	//0x28
	uint32	:16;	//0x2A
	uint32	ARR:16;	//0x2C
	uint32	:16;	//0x2E
	uint32	:32;	//0x30
	uint32	CCR1:16;//0x34
	uint32	:16;	//0x36
	uint32	:32;	//0x38
	uint32	:32;	//0x3C
	uint32	:32;	//0x40
	uint32	:32;	//0x44
	uint32	:32;	//0x48
	uint32	:32;	//0x4C
	dtOR	OR;		//0x50
} dtTIM11;

#endif /* TIM11_TIM11_TYPES_H_ */

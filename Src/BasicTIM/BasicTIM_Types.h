/*
 * BasicTIM_Types.h
 *
 *  Created on: 3 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef BASICTIM_BASICTIM_TYPES_H_
#define BASICTIM_BASICTIM_TYPES_H_

#include "types.h"

typedef union
{
	struct
	{
		uint32 CEN		:1;
		uint32 UDIS		:1;
		uint32 URS		:1;
		uint32 OPM		:1;
		uint32			:3;
		uint32 ARPE		:1;
		uint32 			:3;
		uint32 UIFREMA	:1;
		uint32 			:20;
	} Fields;
	uint32 Word;
} dtCR1;

typedef union
{
	struct
	{
		uint32		:4;
		uint32 MMS	:3;
		uint32		:25;
	} Fields;
	uint32 Word;
} dtCR2;

typedef union
{
	struct
	{
		uint32 UIE	:1;
		uint32		:7;
		uint32 UDE	:1;
		uint32		:23;
	} Fields;
	uint32 Word;
} dtDIER;

typedef union
{
	struct
	{
		uint32 UIF	:1;
		uint32		:31;
	} Fields;
	uint32 Word;
} dtBasicTIMSR;

typedef union
{
	struct
	{
		uint32 UG	:1;
		uint32		:31;
	} Fields;
	uint32 Word;
} dtEGR;

typedef union
{
	struct
	{
		uint32 CNT		:16;
		uint32			:15;
		uint32 UIFCPY	:1;
	} Fields;
	uint32 Word;
} dtCNT;

typedef union
{
	struct
	{
		uint32 PSC	:16;
		uint32		:16;
	} Fields;
	uint32 Word;
} dtPSC;

typedef union
{
	struct
	{
		uint32 ARR	:16;
		uint32		:16;
	} Fields;
	uint32 Word;
} dtARR;

typedef struct
{
	dtCR1 CR1;
	dtCR2 CR2;
	uint32 :32;
	dtDIER DIER;
	dtBasicTIMSR SR;
	dtEGR EGR;
	uint32 :32;
	uint32 :32;
	uint32 :32;
	dtCNT CNT;
	dtPSC PSC;
	dtARR ARR;
} dtBasicTIM;

#endif /* BASICTIM_BASICTIM_TYPES_H_ */

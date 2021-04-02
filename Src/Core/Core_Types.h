/*
 * Core_Types.h
 *
 *  Created on: 2021. márc. 25.
 *      Author: Benjamin
 */

#ifndef SRC_CORE_CORE_TYPES_H_
#define SRC_CORE_CORE_TYPES_H_

#include "types.h"

typedef union
{
	uint32 Word;
	struct
	{
		uint32 			:31;
		uint32 PRIMASK	:1;
	} Fields;
} dtPRIMASK;

typedef union
{
	uint32 Word;
	struct
	{
		uint32				:1;
		uint32 SLEEPONEXIT	:1;
		uint32 SLEEPDEEP	:1;
		uint32 				:1;
		uint32 SEVONPEND	:1;
		uint32 				:27;
	} Fields;
} dtSCR;

typedef struct
{
	uint32	CPUID;	//0x00
	uint32	ICSR;	//0x04
	uint32 :32;		//0x08
	uint32	AIRCR;	//0x0C
	dtSCR	SCR;	//0x10
	uint32	CCR;
	uint32	SHPR2;
	uint32	SHPR3;
} dtSCB;

#endif /* SRC_CORE_CORE_TYPES_H_ */

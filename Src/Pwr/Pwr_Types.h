/*
 * Pwr_Types.h
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef PWR_PWR_TYPES_H_
#define PWR_PWR_TYPES_H_

#include "types.h"

typedef struct
{
	struct
	{
		uint32 LPMS		:3;
		uint32			:5;
		uint32 DBP		:1;
		uint32 VOS		:2;
		uint32			:3;
		uint32 LPR		:1;
		uint32			:17;
	}Field;
	uint32 Word;
} dtCR1;

typedef union
{
	struct
	{
		uint32			:8;
		uint32 REGLPS	:1;
		uint32 REGLPF	:1;
		uint32 VOSF		:1;
		uint32 PVDO		:1;
		uint32 PVMO1	:1;
		uint32 PVMO2	:1;
		uint32 PVMO3	:1;
		uint32 PVMO4	:1;
		uint32 			:16;
	}Field;
	uint32 Word;
} dtSR2;

typedef struct
{
	dtCR1 CR1;
	uint32 CR2;
	uint32 CR3;
	uint32 CR4;
	uint32 SR1;
	dtSR2 SR2;
	uint32 SCR;
	uint32 PUCRA;
	uint32 PDCRA;
	uint32 PUCRB;
	uint32 PDCRB;
	uint32 PUCRC;
	uint32 PDCRC;
	uint32 PUCRD;
	uint32 PDCRD;
	uint32 PUCRE;
	uint32 PDCRE;
	uint32 PUCRF;
	uint32 PDCRF;
	uint32 PUCRG;
	uint32 PDCRG;
	uint32 PUCRH;
	uint32 PDCRH;
	uint32 PUCRI;
	uint32 PDCRI;
} dtPwr;

#endif /* PWR_PWR_TYPES_H_ */

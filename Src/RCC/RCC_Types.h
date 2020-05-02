/*
 * RCC_Types.h
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef RCC_RCC_TYPES_H_
#define RCC_RCC_TYPES_H_

#include "types.h"

typedef struct
{
	uint32 AHB1;
	uint32 AHB2;
	uint32 AHB3;
	uint32 :32;
	uint32 APB11;
	uint32 APB12;
	uint32 APB2;
} dtPClock;

typedef struct
{
	uint32 CR;
	uint32 ICSCR;
	uint32 CFGR;
	uint32 PLL_CFGR;
	uint32 PLLSAI1_CFGR;
	uint32 PLLSAI2_CFGR;
	uint32 CIER;
	uint32 CIFR;
	uint32 CICR;
	uint32 :32;
	dtPClock RSTR;
	uint32 :32;
	dtPClock ENR;
	uint32 :32;
	dtPClock SMENR;
	uint32 :32;
	uint32 CCIPR;
	uint32 BDCR;
	uint32 CSR;
	uint32 CRRCR;
	uint32 CCIPR2;
} dtRCC;

#endif /* RCC_RCC_TYPES_H_ */

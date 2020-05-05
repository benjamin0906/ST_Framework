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
	uint32 MSION		:1;
	uint32 MSIRDY		:1;
	uint32 MSIPLLEN		:1;
	uint32 MSIRGSEL		:1;
	uint32 MSIRANGE		:4;
	uint32 HSION		:1;
	uint32 HSIKERON		:1;
	uint32 HSIRDY		:1;
	uint32 HSIASFS		:1;
	uint32 				:4;
	uint32 HSEON		:1;
	uint32 HSERDY		:1;
	uint32 HSEBYP		:1;
	uint32 CSSON		:1;
	uint32 				:4;
	uint32 PLLON		:1;
	uint32 PLLRDY		:1;
	uint32 PLLSAI1ON	:1;
	uint32 PLLSAI1RDY	:1;
	uint32 PLLSAI2ON	:1;
	uint32 PLLSAI2RDY	:1;
	uint32 				:2;
} dtCR;

typedef struct
{
	uint32 MSICAL	:8;
	uint32 MSITRIM	:8;
	uint32 HSICAL	:8;
	uint32 HSITRIM	:7;
	uint32 			:1;
} dtICSCR;

typedef struct
{
	uint32 SW		:2;
	uint32 SWS		:2;
	uint32 HPRE		:4;
	uint32 PPRE		:3;
	uint32 PPRE2	:3;
	uint32 			:1;
	uint32 STOPWUCK	:1;
	uint32 			:8;
	uint32 MCOSEL	:4;
	uint32 MCOPRE	:3;
	uint32 			:1;
} dtCFGR;

typedef struct
{
	uint32 PLLSRC	:2;
	uint32 			:2;
	uint32 PLLM		:3;
	uint32 			:1;
	uint32 PLLN		:7;
	uint32 			:1;
	uint32 PLLPEN	:1;
	uint32 PLLP		:1;
	uint32 			:2;
	uint32 PLLQEN	:1;
	uint32 PLLQ		:2;
	uint32 			:1;
	uint32 PLLREN	:1;
	uint32 PLLR		:2;
	uint32 PLLDIV	:5;
} dtPLLCFGR;

typedef struct
{
	dtCR CR;
	dtICSCR ICSCR;
	dtCFGR CFGR;
	dtPLLCFGR PLL_CFGR;
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

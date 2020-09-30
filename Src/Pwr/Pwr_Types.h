/*
 * Pwr_Types.h
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#ifndef PWR_PWR_TYPES_H_
#define PWR_PWR_TYPES_H_

#include "types.h"

#ifdef MCU_F410
typedef union
{
	struct
	{
		uint32 LPDS		:1;
		uint32 PDDS		:1;
		uint32 CWUF		:1;
		uint32 CSBF		:1;
		uint32 PVDE		:1;
		uint32 PLS		:3;
		uint32 DBP		:1;
		uint32 FPDS		:1;
		uint32 LPLVDS	:1;
		uint32 MRLVDS	:1;
		uint32 			:1;
		uint32 ADCDC1	:1;
		uint32 VOS		:2;
		uint32 			:4;
		uint32 FMSSR	:1;
		uint32 FISSR	:1;
		uint32 			:10;
	} Fields;
	uint32 Word;
} dtCR;
#elif defined(MCU_F446)
typedef union
{
	struct
	{
		uint32 LPDS		:1;
		uint32 PDDS		:1;
		uint32 CWUF		:1;
		uint32 CSBF		:1;
		uint32 PVDE		:1;
		uint32 PLS		:3;
		uint32 DBP		:1;
		uint32 FPDS		:1;
		uint32 LPUDS	:1;
		uint32 MRUDS	:1;
		uint32 			:1;
		uint32 ADCDC1	:1;
		uint32 VOS		:2;
		uint32 ODEN		:1;
		uint32 ODSWEN	:1;
		uint32 UDEN		:2;
		uint32 FMSSR	:1;
		uint32 FISSR	:1;
		uint32 			:10;
	} Fields;
	uint32 Word;
} dtCR;
#endif

#ifdef MCU_F410
typedef union
{
	struct
	{

		uint32 WUF		:1;
		uint32 SBF		:1;
		uint32 PVDO		:1;
		uint32 BRR		:1;
		uint32 			:2;
		uint32 EWUP		:3;
		uint32 BRE		:1;
		uint32 			:4;
		uint32 VOSRDY	:1;
		uint32 			:17;
	} Fields;
	uint32 Word;
} dtCSR;
#elif defined(MCU_F446)
typedef union
{
	struct
	{
		uint32 WUF		:1;
		uint32 SBF		:1;
		uint32 PVDO		:1;
		uint32 BRR		:1;
		uint32 			:3;
		uint32 EWUP		:2;
		uint32 BRE		:1;
		uint32 			:4;
		uint32 VOSRDY	:1;
		uint32 			:1;
		uint32 ODRDY	:1;
		uint32 ODSWRDY	:1;
		uint32 UDRDY	:2;
		uint32 			:12;
	} Fields;
	uint32 Word;
} dtCSR;
#endif

typedef struct
{
#if defined(MCU_F410) || defined(MCU_F446)
	dtCR CR;
	dtCSR CSR;
#elif defined(MCU_G070)

#endif
} dtPwr;

#endif /* PWR_PWR_TYPES_H_ */

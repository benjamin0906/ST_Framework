/*
 * Pwr_Types.h
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#ifndef PWR_PWR_TYPES_H_
#define PWR_PWR_TYPES_H_

#include "types.h"

#if defined(MCU_F410)
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
} dtPwrCR;
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
#if defined(MCU_G070) || defined(MCU_G071)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 LPMS			:3;
		uint32 FPD_STOP		:1;
		uint32 FPD_LPRUN	:1;
		uint32 FPD_LPSLP	:1;
		uint32 				:2;
		uint32 DBP			:1;
		uint32 VOS			:2;
		uint32 				:3;
		uint32 LPR			:1;
	} Fields;
} dtPwrCR;

#if defined(MCU_G071)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 PVDE			:1;
		uint32 PVDFT		:3;
		uint32 PVDRT		:3;
	} Fields;
} dtCR2;
#endif

typedef union
{
	uint32 Word;
	struct
	{
		uint32 EWUP1		:1;
		uint32 EWUP2		:1;
		uint32 				:1;
		uint32 EWUP4		:1;
		uint32 EWUP5		:1;
		uint32 EWUP6		:1;
#if defined(MCU_G070)
		uint32 				:4;
#elif defined(MCU_G071)
		uint32				:2;
		uint32 RRS			:1;
		uint32 ULPEN		:1;
#endif
		uint32 APC			:1;
		uint32 				:4;
		uint32 EIWUL		:1;
	} Fields;
} dtCR3;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 WP1			:1;
		uint32 WP2			:1;
		uint32 				:1;
		uint32 WP4			:1;
		uint32 WP5			:1;
		uint32 WP6			:1;
		uint32 				:2;
		uint32 VBE			:1;
		uint32 VBRS			:1;
	} Fields;
} dtCR4;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 WUF1			:1;
		uint32 WUF2			:1;
		uint32 				:1;
		uint32 WUF4			:1;
		uint32 WUF5			:1;
		uint32 WUF6			:1;
		uint32 				:2;
		uint32 SBF			:1;
		uint32 				:6;
		uint32 WUFI			:1;
	} Fields;
} dtSR1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 				:7;
		uint32 FLASH_RDY	:1;
		uint32 REGLPS		:1;
		uint32 REGLPF		:1;
		uint32 VOSF			:1;
#if defined(MCU_G071)
		uint32 PVDO			:1;
#endif
	} Fields;
} dtSR2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CWUF1		:1;
		uint32 CWUF2		:1;
		uint32 				:1;
		uint32 CWUF4		:1;
		uint32 CWUF5		:1;
		uint32 CWUF6		:1;
		uint32 				:2;
		uint32 CSBF			:1;
	} Fields;
} dtSCR;

/*typedef union
{
	uint32 Word;
	struct
	{
		uint32 :;
	} Fields;
} dt; */

#endif

typedef struct
{
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_G070) || defined(MCU_G071)
	dtPwrCR 	CR;
#endif
#if defined(MCU_G070)
	uint32	:32;
#elif defined(MCU_G071)
	dtCR2	CR2;
#endif
#if defined(MCU_G070) || defined(MCU_G071)
	dtCR3	CR3;
#endif
#if defined(MCU_G070) || defined(MCU_G071)
	dtCR4	CR4;
#endif
#if defined(MCU_G070) || defined(MCU_G071)
	dtSR1	SR1;
#endif
#if defined(MCU_G070) || defined(MCU_G071)
	dtSR2	SR2;
#endif
#if defined(MCU_G070) || defined(MCU_G071)
	dtSCR	SCR;
#endif
#if defined(MCU_F410) || defined(MCU_F446)
	dtCSR CSR;
#endif
} dtPwr;

#endif /* PWR_PWR_TYPES_H_ */

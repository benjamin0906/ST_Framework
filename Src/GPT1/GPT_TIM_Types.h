/*
 * TIM3_Types.h
 *
 *  Created on: 2020. júl. 15.
 *      Author: BodnarB
 */

#ifndef ST_FRAMEWORK_SRC_GPT1_GPT_TIM_TYPES_H_
#define ST_FRAMEWORK_SRC_GPT1_GPT_TIM_TYPES_H_

#include "types.h"

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CEN	:1;
		uint32 UDIS	:1;
		uint32 URS	:1;
		uint32 OPM	:1;
		uint32 DIR	:1;
		uint32 CMS	:2;
		uint32 ARPE	:1;
		uint32 CKD	:2;
	} Fields;
} dtCR1;

typedef union
{
	uint32 Word;
	struct
	{

		uint32 		:3;
		uint32 CCDS	:1;
		uint32 MMS	:3;
		uint32 TI1S	:1;
	} Fields;
} dtCR2;

typedef union
{
	uint32 Word;
	struct
	{

		uint32 SMS	:3;
		uint32 		:1;
		uint32 TS	:3;
		uint32 MSM	:1;
		uint32 ETF	:4;
		uint32 ETPS	:2;
		uint32 ECE	:1;
		uint32 ETP	:1;
	} Fields;
} dtSMCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 UIE		:1;
		uint32 CC1IE	:1;
		uint32 CC2IE	:1;
		uint32 CC3IE	:1;
		uint32 CC4IE	:1;
		uint32 			:1;
		uint32 TIE		:1;
		uint32 			:1;
		uint32 UDE		:1;
		uint32 CC1DE	:1;
		uint32 CC2DE	:1;
		uint32 CC3DE	:1;
		uint32 CC4DE	:1;
		uint32 COMDE	:1;
		uint32 TDE		:1;
	} Fields;
} dtDIER;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 UIF		:1;
		uint32 CC1IF	:1;
		uint32 CC2IF	:1;
		uint32 CC3IF	:1;
		uint32 CC4IF	:1;
		uint32 			:1;
		uint32 TIF		:1;
		uint32 			:2;
		uint32 CC1OF	:1;
		uint32 CC2OF	:1;
		uint32 CC3OF	:1;
		uint32 CC4OF	:1;
	} Fields;
} dtSR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 UG	:1;
		uint32 CC1G	:1;
		uint32 CC2G	:1;
		uint32 CC3G	:1;
		uint32 CC4G	:1;
		uint32 		:1;
		uint32 TG	:1;
	} Fields;
} dtEGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CC1S		:2;
		uint32 OC1FE	:1;
		uint32 OC1PE	:1;
		uint32 OC1M		:3;
		uint32 OC1CE	:1;
		uint32 CC2S		:2;
		uint32 OC2FE	:1;
		uint32 OC2PE	:1;
		uint32 OC2M		:3;
		uint32 OC2CE	:1;
	} Out_Fields;
	struct
	{
		uint32 CC1S		:2;
		uint32 IC1PSC	:2;
		uint32 IC1F		:4;
		uint32 CC2S		:2;
		uint32 IC2PSC	:2;
		uint32 IC2F		:4;
	} In_Fields;
} dtCCMR1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CC3S		:2;
		uint32 OC3FE	:1;
		uint32 OC3PE	:1;
		uint32 OC3M		:3;
		uint32 OC3CE	:1;
		uint32 CC4S		:2;
		uint32 OC4FE	:1;
		uint32 OC4PE	:1;
		uint32 OC4M		:3;
		uint32 OC4CE	:1;
	} Out_Fields;
	struct
	{
		uint32 CC3S		:2;
		uint32 IC3PSC	:2;
		uint32 IC3F		:4;
		uint32 CC4S		:2;
		uint32 IC4PSC	:2;
		uint32 IC4F		:4;
	} In_Fields;
} dtCCMR2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CC1E		:1;
		uint32 CC1P		:1;
		uint32 			:1;
		uint32 CC1NP	:1;
		uint32 CC2E		:1;
		uint32 CC2P		:1;
		uint32 			:1;
		uint32 CC2NP	:1;
		uint32 CC3E		:1;
		uint32 CC3P		:1;
		uint32 			:1;
		uint32 CC3NP	:1;
		uint32 CC4E		:1;
		uint32 CC4P		:1;
		uint32 			:1;
		uint32 CC4NP	:1;
	} Fields;
} dtCCER;

typedef union
{
	uint32 Word;
	struct
	{
#if defined(TIM5) || defined(TIM2)
		uint32 CNT;
#else
		uint32 CNT	:16;
#endif
	} Fields;
} dtCNT;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 PSC	:16;
	} Fields;
} dtPSC;

typedef union
{
	uint32 Word;
	struct
	{
#if defined(TIM5) || defined(TIM2)
		uint32 ARR;
#else
		uint32 ARR	:16;
#endif
	} Fields;
} dtARR;

typedef union
{
	uint32 Word;
	struct
	{
#if defined(TIM5) || defined(TIM2)
		uint32 CCR1;
#else
		uint32 CCR1	:16;
#endif
	} Fields;
} dtCCRx;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 DBA	:5;
		uint32 		:3;
		uint32 DBL	:5;
	} Fields;
} dtDCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 DMAB	:16;
	} Fields;
} dtDMAR;

#if defined(TIM2)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 			:10;
		uint32 ITR1_RMP	:2;
	} Fields;
} dtOR;
#endif

#if defined(TIM5)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 			:6;
		uint32 IT4_RMP	:2;
	} Fields;
} dtOR;
#endif

typedef struct
{
	dtCR1	CR1;	//0x00
	dtCR2	CR2;	//0x04
	dtSMCR	SMCR;	//0x08
	dtDIER	DIER;	//0x0C
	dtSR	SR;		//0x10
	dtEGR	EGR;	//0x14
	dtCCMR1	CCMR1;	//0x18
	dtCCMR2	CCMR2;	//0x1C
	dtCCER	CCER;	//0x20
	dtCNT	CNT;	//0x24
	dtPSC	PSC;	//0x28
	dtARR	ARR;	//0x2C
	uint32	:32;	//0x30
	dtCCRx	CCR1;	//0x34
	dtCCRx	CCR2;	//0x38
	dtCCRx	CCR3;	//0x3C
	dtCCRx	CCR4;	//0x40
	uint32	:32;	//0x44
	dtDCR	DCR;	//0x48
	dtDMAR	DMAR;	//0x4C
#if defined(TIM5) | defined(TIM2)
	dtOR	OR;		//0x50
#endif
} dtGPT1;

#endif /* ST_FRAMEWORK_SRC_GPT1_GPT_TIM_TYPES_H_ */

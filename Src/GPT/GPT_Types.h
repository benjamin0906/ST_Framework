/*
 * GPT_Types.h
 *
 *  Created on: 2021. febr. 25.
 *      Author: Benjamin
 */

#ifndef SRC_GPT_GPT_TYPES_H_
#define SRC_GPT_GPT_TYPES_H_

#include "types.h"

typedef union
{
	struct
	{
		uint32 CEN		:1;
		uint32 UDIS		:1;
		uint32 URS		:1;
		uint32 OPM		:1;
		uint32 			:3;
		uint32 ARPE		:1;
		uint32 CKD		:2;
		uint32 			:1;
		uint32 UIFREMAP	:1;
		uint32 			:4;
		uint32 			:16;
	} Field;
	uint32 Word;
} dtCR1;

typedef union
{
	struct
	{
		uint32 CCPC		:1;
		uint32 			:1;
		uint32 CCUS		:1;
		uint32 CCDS		:1;
		uint32 MMS		:3;
		uint32 TI1S		:1;
		uint32 OIS1		:1;
		uint32 OIS1N	:1;
		uint32 OIS2		:1;
		uint32 			:21;
	} Field;
	uint32 Word;
} dtCR2;

typedef union
{
	struct
	{
		uint32 SMS1		:3;
		uint32 			:1;
		uint32 TS		:3;
		uint32 MSM		:1;
		uint32 			:8;
		uint32 SMS2		:1;
		uint32 			:15;
	} Field;
	uint32 Word;
} dtSMCR;

typedef union
{
	struct
	{
		uint32 UIE		:1;
		uint32 OC1IE	:1;
		uint32 OC2IE	:1;
		uint32 			:2;
		uint32 COMIE	:1;
		uint32 TIE		:1;
		uint32 BIE		:1;
		uint32 UDE		:1;
		uint32 CC1DE	:1;
		uint32 CC2DE	:1;
		uint32 			:2;
		uint32 COMDE	:1;
		uint32 TDE		:1;
		uint32 			:17;
	} Field;
	uint32 Word;
} dtDIER;

typedef union
{
	struct
	{
		uint32 UIF		:1;
		uint32 CC1IF	:1;
		uint32 CC2IF	:1;
		uint32 			:2;
		uint32 COMIF	:1;
		uint32 TIF		:1;
		uint32 BIF		:1;
		uint32 			:1;
		uint32 CC1OF	:1;
		uint32 CC2OF	:1;
		uint32 			:21;
	} Field;
	uint32 Word;
} dtSR;

typedef union
{
	struct
	{
		uint32 UG		:1;
		uint32 CC1G		:1;
		uint32 CC2G		:1;
		uint32 			:2;
		uint32 COMG		:1;
		uint32 TG		:1;
		uint32 BG		:1;
		uint32 			:24;
	} Field;
	uint32 Word;
} dtEGR;

typedef union
{
	struct
	{
		uint32 CC1S		:2;
		uint32 OC1FE	:1;
		uint32 OC1PE	:1;
		uint32 OC1M_1	:3;
		uint32 			:1;
		uint32 CC2S		:2;
		uint32 OC2FE	:1;
		uint32 OC2PE	:1;
		uint32 OC2M_1	:3;
		uint32 			:1;
		uint32 OC1M_2	:1;
		uint32 			:7;
		uint32 OC2M_2	:1;
		uint32 			:7;
	} OC_mode_Field;
	struct
	{
		uint32 CC1S		:2;
		uint32 IC1PSC	:2;
		uint32 IC1F		:4;
		uint32 CC2S		:2;
		uint32 IC2PSC	:2;
		uint32 IC2F		:4;
		uint32 			:16;
	}IC_mode_Field;
	uint32 Word;
} dtCCMR1;

typedef union
{
	struct
	{
		uint32 CC1E		:1;
		uint32 CC1P		:1;
		uint32 CC1NE	:1;
		uint32 CC1NP	:1;
		uint32 CC2E		:1;
		uint32 CC2P		:1;
		uint32 			:1;
		uint32 CC2NP	:1;
		uint32 			:24;
	} Field;
	uint32 Word;
} dtCCER;

typedef union
{
	struct
	{
		uint32 CNT		:16;
		uint32 			:15;
		uint32 UIFCPY	:1;
	} Field;
	uint32 Word;
} dtCNT;

typedef union
{
	struct
	{
		uint32 PSC		:16;
		uint32			:16;
	} Field;
	uint32 Word;
} dtPSC;

typedef union
{
	struct
	{
		uint32 ARR		:16;
		uint32			:16;
	} Field;
	uint32 Word;
} dtARR;

typedef union
{
	struct
	{
		uint32 REP		:8;
		uint32			:24;
	} Field;
	uint32 Word;
} dtRCR;

typedef union
{
	struct
	{
		uint32 CCR1		:16;
		uint32			:16;
	} Field;
	uint32 Word;
} dtCCR1;

typedef union
{
	struct
	{
		uint32 CCR2		:16;
		uint32			:16;
	} Field;
	uint32 Word;
} dtCCR2;

typedef union
{
	struct
	{
		uint32 DTG		:8;
		uint32 LOCK		:2;
		uint32 OSSI		:1;
		uint32 OSSR		:1;
		uint32 BKE		:1;
		uint32 BKP		:1;
		uint32 AOE		:1;
		uint32 MOE		:1;
		uint32 			:16;
	} Field;
	uint32 Word;
} dtBDTR;

typedef union
{
	struct
	{
		uint32 DBA		:5;
		uint32 			:3;
		uint32 DBL		:5;
		uint32 			:19;
	} Field;
	uint32 Word;
} dtDCR;

typedef union
{
	struct
	{
		uint32 DMAB		:16;
		uint32 			:16;
	} Field;
	uint32 Word;
} dtDMAR;

typedef union
{
	struct
	{
		uint32 TI1_RMP		:1;
		uint32 ENCODER_MODE	:2;
		uint32 				:29;
	} Field;
	uint32 Word;
} dtOR1;

typedef union
{
	struct
	{
		uint32 BKINE		:1;
		uint32 BKCMP1E		:1;
		uint32 BKCMP2E		:1;
		uint32 				:5;
		uint32 BKDF1BK0E	:1;
		uint32 BKINP		:1;
		uint32 BKCMP1P		:1;
		uint32 BKCMP2P		:1;
		uint32 				:20;
	} Field;
	uint32 Word;
} dtOR2;

typedef struct
{
	dtCR1 CR1;		//0x00
	dtCR2 CR2;		//0x04
	dtSMCR SMCR;	//0x08
	dtDIER DIER;	//0x0C
	dtSR SR;		//0x10
	dtEGR EGR;		//0x14
	dtCCMR1 CCMR1;	//0x18
	uint32	:32;	//0x1C
	dtCCER CCER;	//0x20
	dtCNT CNT;		//0x24
	dtPSC PSC;		//0x28
	dtARR ARR;		//0x2C
	dtRCR RCR;		//0x30
	dtCCR1 CCR1;	//0x34
	dtCCR2 CCR2;	//0x38
	uint32	:32;	//0x3C
	uint32	:32;	//0x40
	dtBDTR BDTR;	//0x44
	dtDCR DCR;		//0x48
	dtDMAR DMAR;	//0x4C
	dtOR1 OR1;		//0x50
	uint32	:32;	//0x54
	uint32	:32;	//0x58
	uint32	:32;	//0x5C
	dtOR2 OR2;		//0x60
} dtGPT;

#endif /* SRC_GPT_GPT_TYPES_H_ */

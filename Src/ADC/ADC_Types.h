/*
 * ADC_Types.h
 *
 *  Created on: 2021. febr. 14.
 *      Author: Benjamin
 */

#ifndef SRC_ADC_ADC_TYPES_H_
#define SRC_ADC_ADC_TYPES_H_

#include "types.h"

typedef union
{
	uint32 Word;
	struct
	{
		uint32 ADRDY	:1;
		uint32 EOSMP	:1;
		uint32 EOC		:1;
		uint32 EOS		:1;
		uint32 OVR		:1;
		uint32 			:2;
		uint32 AWD1		:1;
		uint32 AWD2		:1;
		uint32 AWD3		:1;
		uint32 			:1;
		uint32 EOCAL	:1;
		uint32 			:1;
		uint32 CCRDY	:1;
	} Fields;
} dtADC_ISR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 ADRDYIE	:1;
		uint32 EOSMPIE	:1;
		uint32 EOCIE	:1;
		uint32 EOSIE	:1;
		uint32 OVRIE	:1;
		uint32 			:2;
		uint32 AWD1IE	:1;
		uint32 AWD2IE	:1;
		uint32 AWD3IE	:1;
		uint32 			:1;
		uint32 EOCALIE	:1;
		uint32 			:1;
		uint32 CCRDYIE	:1;
	} Fields;
} dtADC_IER;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 ADEN		:1;
		uint32 ADDIS	:1;
		uint32 ADSTART	:1;
		uint32 			:1;
		uint32 ADSTP	:1;
		uint32 			:23;
		uint32 ADVREGEN	:1;
		uint32 			:2;
		uint32 ADCAL	:1;
	} Fields;
} dtADC_CR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 DMAEN	:1;
		uint32 DMACFG	:1;
		uint32 SCANDIR	:1;
		uint32 RES		:2;
		uint32 ALIGN	:1;
		uint32 EXTSEL	:3;
		uint32 			:1;
		uint32 EXTEN	:2;
		uint32 OVRMOD	:1;
		uint32 CONT		:1;
		uint32 WAIT		:1;
		uint32 AUTOFF	:1;
		uint32 DISCEN	:1;
		uint32 			:4;
		uint32 CHSELRMOD:1;
		uint32 AWD1SGL	:1;
		uint32 AWD1EN	:1;
		uint32 			:2;
		uint32 AWDCH	:5;
	} Fields;
} dtADC_CFGR1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 OVSE		:1;
		uint32 			:1;
		uint32 OVSR		:3;
		uint32 OVSS		:4;
		uint32 TOVS		:1;
		uint32 			:19;
		uint32 LFTRIG	:1;
		uint32 CKMODE	:2;
	} Fields;
} dtADC_CFGR2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 SMP1		:3;
		uint32 			:1;
		uint32 SMP2		:3;
		uint32 			:1;
		uint32 SMPSEL	:19;
	} Fields;
} dtADC_SMPR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 LT1	:12;
		uint32 		:4;
		uint32 HT1	:12;
	} Fields;
} dtADC_AWD1TR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 LT2	:12;
		uint32 		:4;
		uint32 HT2	:12;
	} Fields;
} dtADC_AWD2TR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CHSEL	:19;
	} ModeZero_Fields;
	struct
	{
		uint32 SQ1	:4;
		uint32 SQ2	:4;
		uint32 SQ3	:4;
		uint32 SQ4	:4;
		uint32 SQ5	:4;
		uint32 SQ6	:4;
		uint32 SQ7	:4;
		uint32 SQ8	:4;
	} ModeOne_Fields;
} dtADC_CHSELR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 LT3	:12;
		uint32 		:4;
		uint32 HT3	:12;
	} Fields;
} dtADC_AWD3TR;

typedef union
{
	uint32 Word;
	struct
	{
		uint16 Data;
	} Fields;
} dtADC_DR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 AWD2CH	:19;
	} Fields;
} dtADC_AWD2CR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 AWD3CH	:19;
	} Fields;
} dtADC_AWD3CR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CALFACT	:7;
	} Fields;
} dtADC_CALFACT;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 			:18;
		uint32 PRESC	:4;
		uint32 VREFEN	:1;
		uint32 TSEN		:1;
		uint32 VBATEN	:1;
	} Fields;
} dtADC_CCR;

typedef struct
{
	dtADC_ISR		ISR;	//0x00
	dtADC_IER		IER;	//0x04
	dtADC_CR		CR;		//0x08
	dtADC_CFGR1		CFGR1;	//0xC0
	dtADC_CFGR2		CFGR2;	//0x10
	dtADC_SMPR		SMPR;	//0x14
	uint32			:32;	//0x18
	uint32			:32;	//0x1C
	dtADC_AWD1TR	AWD1TR;	//0x20
	dtADC_AWD2TR	AWD2TD;	//0x24
	dtADC_CHSELR	CHSELR;	//0x28
	dtADC_AWD3TR	AWD3TR;	//0x2C
	uint32			:32;	//0x30
	uint32			:32;	//0x34
	uint32			:32;	//0x38
	uint32			:32;	//0x3C
	dtADC_DR		DR;		//0x40
	uint32			:32;	//0x44
	uint32			:32;	//0x48
	uint32			:32;	//0x4C
	uint32			:32;	//0x50
	uint32			:32;	//0x54
	uint32			:32;	//0x58
	uint32			:32;	//0x5C
	uint32			:32;	//0x60
	uint32			:32;	//0x64
	uint32			:32;	//0x68
	uint32			:32;	//0x6C
	uint32			:32;	//0x70
	uint32			:32;	//0x74
	uint32			:32;	//0x78
	uint32			:32;	//0x7C
	uint32			:32;	//0x80
	uint32			:32;	//0x84
	uint32			:32;	//0x88
	uint32			:32;	//0x8C
	uint32			:32;	//0x90
	uint32			:32;	//0x94
	uint32			:32;	//0x98
	uint32			:32;	//0x9C
	dtADC_AWD2CR	AWD2CR;	//0xA0
	dtADC_AWD3CR	AWD3CR;	//0xA4
	uint32			:32;	//0xA8
	uint32			:32;	//0xAC
	uint32			:32;	//0xB0
	dtADC_CALFACT	CALFACT;//0xB4
	uint8			Padding[592];	//0xB5
	dtADC_CCR		CCR;	//0x308

} dtADC;

#endif /* SRC_ADC_ADC_TYPES_H_ */

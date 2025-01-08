/*
 * DMAMUX_Types.h
 *
 *  Created on: Jan 7, 2025
 *      Author: Benjamin
 */

#ifndef SRC_DMAMUX_DMAMUX_TYPES_H_
#define SRC_DMAMUX_DMAMUX_TYPES_H_

#include "types.h"

#if defined(MCU_G070)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 DMAREQ_ID    :7;
		uint32              :1;
		uint32 SOIE         :1;
		uint32 EGE          :1;
		uint32              :6;
		uint32 SE           :1;
		uint32 SPOL         :2;
		uint32 NBREQ        :5;
		uint32 SYNC_ID      :5;
		uint32              :3;
	} Fields;
} dtDMAMUX_CxCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 SOF0 :1;
		uint32 SOF1 :1;
		uint32 SOF2 :1;
		uint32 SOF3 :1;
		uint32 SOF4 :1;
		uint32 SOF5 :1;
		uint32 SOF6 :1;
		uint32 SOF7 :1;
		uint32 SOF8 :1;
		uint32 SOF9 :1;
		uint32 SOF10 :1;
		uint32 SOF11 :1;
	} Fields;
} dtDMAMUX_CSR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 CSOF0 :1;
		uint32 CSOF1 :1;
		uint32 CSOF2 :1;
		uint32 CSOF3 :1;
		uint32 CSOF4 :1;
		uint32 CSOF5 :1;
		uint32 CSOF6 :1;
		uint32 CSOF7 :1;
		uint32 CSOF8 :1;
		uint32 CSOF9 :1;
		uint32 CSOF10 :1;
		uint32 CSOF11 :1;
	} Fields;
} dtDMAMUX_CFR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 SIG_ID :5;
		uint32        :3;
		uint32 OIE    :1;
		uint32        :7;
		uint32 GE     :1;
		uint32 GPOL   :2;
		uint32 GNBREQ :5;
		uint32        :8;
	} Fields;
} dtDMAMUX_RGxCR;

typedef struct
{
	dtDMAMUX_CxCR CxCR[12];
	uint32 :32;//0x30
	uint32 :32;//0x34
	uint32 :32;//0x38
	uint32 :32;//0x3C
	uint32 :32;//0x40
	uint32 :32;//0x44
	uint32 :32;//0x48
	uint32 :32;//0x4C
	uint32 :32;//0x50
	uint32 :32;//0x54
	uint32 :32;//0x58
	uint32 :32;//0x5C
	uint32 :32;//0x60
	uint32 :32;//0x64
	uint32 :32;//0x68
	uint32 :32;//0x6C
	uint32 :32;//0x70
	uint32 :32;//0x74
	uint32 :32;//0x78
	uint32 :32;//0x7C
	dtDMAMUX_CSR CSR; //0x80
	dtDMAMUX_CFR CFR; //0x84
	uint32 :32;       //0x88
	uint32 :32;       //0x8C
	uint32 :32;       //0x90
	uint32 :32;       //0x94
	uint32 :32;       //0x98
	uint32 :32;       //0x9C
	uint32 :32;       //0xA0
	uint32 :32;       //0xA4
	uint32 :32;       //0xA8
	uint32 :32;       //0xAC
	uint32 :32;       //0xB0
	uint32 :32;       //0xB4
	uint32 :32;       //0xB8
	uint32 :32;       //0xBC
	uint32 :32;       //0xC0
	uint32 :32;       //0xC4
	uint32 :32;       //0xC8
	uint32 :32;       //0xCC
	uint32 :32;       //0xD0
	uint32 :32;       //0xD4
	uint32 :32;       //0xD8
	uint32 :32;       //0xDC
	uint32 :32;       //0xE0
	uint32 :32;       //0xE4
	uint32 :32;       //0xE8
	uint32 :32;       //0xEC
	uint32 :32;       //0xF0
	uint32 :32;       //0xF4
	uint32 :32;       //0xF8
	uint32 :32;       //0xFC
	dtDMAMUX_RGxCR RGxCR[4];//0x100
	uint32 :32;       //0x110
	uint32 :32;       //0x114
	uint32 :32;       //0x118
	uint32 :32;       //0x11C
	uint32 :32;       //0x120
	uint32 :32;       //0x124
	uint32 :32;       //0x128
	uint32 :32;       //0x12C
	uint32 :32;       //0x130
	uint32 :32;       //0x134
	uint32 :32;       //0x138
	uint32 :32;       //0x13C
	uint32 RGSR;
	uint32 RGCFR;
} dtDMA_MUX;

#endif

#endif /* SRC_DMAMUX_DMAMUX_TYPES_H_ */

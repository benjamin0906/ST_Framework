/*
 * DMA_Types.h
 *
 *  Created on: 10 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef ST_FRAMEWORK_SRC_DMA_DMA_TYPES_H_
#define ST_FRAMEWORK_SRC_DMA_DMA_TYPES_H_

#include "types.h"

typedef union
{
	struct
	{
		uint32 GIF1		:1;
		uint32 TCIF1	:1;
		uint32 HTIF1	:1;
		uint32 TEIF1	:1;

		uint32 GIF2		:1;
		uint32 TCIF2	:1;
		uint32 HTIF2	:1;
		uint32 TEIF2	:1;

		uint32 GIF3		:1;
		uint32 TCIF3	:1;
		uint32 HTIF3	:1;
		uint32 TEIF3	:1;

		uint32 GIF4		:1;
		uint32 TCIF4	:1;
		uint32 HTIF4	:1;
		uint32 TEIF4	:1;

		uint32 GIF5		:1;
		uint32 TCIF5	:1;
		uint32 HTIF5	:1;
		uint32 TEIF5	:1;

		uint32 GIF6		:1;
		uint32 TCIF6	:1;
		uint32 HTIF6	:1;
		uint32 TEIF6	:1;

		uint32 GIF7		:1;
		uint32 TCIF7	:1;
		uint32 HTIF7	:1;
		uint32 TEIF7	:1;
		uint32			:4;
	} Field;
	uint32 Word;
} dtISR;

typedef union
{
	struct
	{
		uint32 CGIF1	:1;
		uint32 CTCIF1	:1;
		uint32 CHTIF1	:1;
		uint32 CTEIF1	:1;

		uint32 CGIF2	:1;
		uint32 CTCIF2	:1;
		uint32 CHTIF2	:1;
		uint32 CTEIF2	:1;

		uint32 CGIF3	:1;
		uint32 CTCIF3	:1;
		uint32 CHTIF3	:1;
		uint32 CTEIF3	:1;

		uint32 CGIF4	:1;
		uint32 CTCIF4	:1;
		uint32 CHTIF4	:1;
		uint32 CTEIF4	:1;

		uint32 CGIF5	:1;
		uint32 CTCIF5	:1;
		uint32 CHTIF5	:1;
		uint32 CTEIF5	:1;

		uint32 CGIF6	:1;
		uint32 CTCIF6	:1;
		uint32 CHTIF6	:1;
		uint32 CTEIF6	:1;

		uint32 CGIF7	:1;
		uint32 CTCIF7	:1;
		uint32 CHTIF7	:1;
		uint32 CTEIF7	:1;
		uint32			:4;
	} Field;
	uint32 Word;
} dtIFCR;

typedef union
{
	struct
	{
		uint32 EN		:1;
		uint32 TCIE		:1;
		uint32 HTIE		:1;
		uint32 TEIE		:1;
		uint32 DIR		:1;
		uint32 CIRC		:1;
		uint32 PINC		:1;
		uint32 MINC		:1;
		uint32 PSIZE	:2;
		uint32 MSIZE	:2;
		uint32 PL		:2;
		uint32 MEM2MEM	:1;
		uint32 			:17;
	} Field;
	uint32 Word;
} dtDMA_CCRx;

typedef union
{
	struct
	{
		uint32 NDT:16;
		uint32 :16;
	} Field;
	uint32 Word;
} dtCNDTRx;

typedef union
{
	struct
	{
		uint32 C1S		:4;
		uint32 C2S		:4;
		uint32 C3S		:4;
		uint32 C4S		:4;
		uint32 C5S		:4;
		uint32 C6S		:4;
		uint32 C7S		:4;
		uint32			:4;
	} Field;
	uint32 Word;
} dtCSELR;

typedef struct
{
	dtDMA_CCRx CCR;
	dtCNDTRx CNDTR;
	uint32 CPAR;
	uint32 CMAR;
	uint32 :32;
} dtDesc;

typedef struct
{
	dtISR ISR;
	dtIFCR ICFR;
	dtDesc CH[7];
	uint32 :32;//0x94
	uint32 :32;//0x98
	uint32 :32;//0x9C
	uint32 :32;//0xA0
	uint32 :32;//0xA4
	dtCSELR CSELR;
} dtDMAx;

#endif /* ST_FRAMEWORK_SRC_DMA_DMA_TYPES_H_ */

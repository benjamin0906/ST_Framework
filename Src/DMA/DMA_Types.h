/*
 * DMA_Types.h
 *
 *  Created on: 10 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef ST_FRAMEWORK_SRC_DMA_DMA_TYPES_H_
#define ST_FRAMEWORK_SRC_DMA_DMA_TYPES_H_

#include "types.h"
#include "DMA_ExtTypes.h"
#if defined(MCU_F446)

typedef union
{
    struct
    {
        uint32 FEIF0    :1;
        uint32          :1;
        uint32 DMEIF0   :1;
        uint32 TEIF0    :1;
        uint32 HTIF0    :1;
        uint32 TCIF0    :1;
        uint32 FEIF1    :1;
        uint32          :1;
        uint32 DMEIF1   :1;
        uint32 TEIF1    :1;
        uint32 HTIF1    :1;
        uint32 TCIF1    :1;
        uint32          :4;
        uint32 FEIF2    :1;
        uint32          :1;
        uint32 DMEIF2   :1;
        uint32 TEIF2    :1;
        uint32 HTIF2    :1;
        uint32 TCIF2    :1;
        uint32 FEIF3    :1;
        uint32          :1;
        uint32 DMEIF3   :1;
        uint32 TEIF3    :1;
        uint32 HTIF3    :1;
        uint32 TCIF3    :1;
        uint32          :4;
    } Field;
    uint32 Word;
} dtDMA_LISR;

typedef union
{
    struct
    {
        uint32 FEIF4    :1;
        uint32          :1;
        uint32 DMEIF4   :1;
        uint32 TEIF4    :1;
        uint32 HTIF4    :1;
        uint32 TCIF4    :1;
        uint32 FEIF5    :1;
        uint32          :1;
        uint32 DMEIF5   :1;
        uint32 TEIF5    :1;
        uint32 HTIF5    :1;
        uint32 TCIF5    :1;
        uint32          :4;
        uint32 FEIF6    :1;
        uint32          :1;
        uint32 DMEIF6   :1;
        uint32 TEIF6    :1;
        uint32 HTIF6    :1;
        uint32 TCIF6    :1;
        uint32 FEIF7    :1;
        uint32          :1;
        uint32 DMEIF7   :1;
        uint32 TEIF7    :1;
        uint32 HTIF7    :1;
        uint32 TCIF7    :1;
        uint32          :4;
    } Field;
    uint32 Word;
} dtDMA_HISR;

typedef union
{
    struct
    {
        uint32 CFEIF0    :1;
        uint32          :1;
        uint32 CDMEIF0   :1;
        uint32 CTEIF0    :1;
        uint32 CHTIF0    :1;
        uint32 CTCIF0    :1;
        uint32 CFEIF1    :1;
        uint32          :1;
        uint32 CDMEIF1   :1;
        uint32 CTEIF1    :1;
        uint32 CHTIF1    :1;
        uint32 CTCIF1    :1;
        uint32          :4;
        uint32 CFEIF2    :1;
        uint32          :1;
        uint32 CDMEIF2   :1;
        uint32 CTEIF2    :1;
        uint32 CHTIF2    :1;
        uint32 CTCIF2    :1;
        uint32 CFEIF3    :1;
        uint32          :1;
        uint32 CDMEIF3   :1;
        uint32 CTEIF3    :1;
        uint32 CHTIF3    :1;
        uint32 CTCIF3    :1;
        uint32          :4;
    } Field;
    uint32 Word;
} dtDMA_LIFCR;

typedef union
{
    struct
    {
        uint32 CFEIF4    :1;
        uint32          :1;
        uint32 CDMEIF4   :1;
        uint32 CTEIF4    :1;
        uint32 CHTIF4    :1;
        uint32 CTCIF4    :1;
        uint32 CFEIF5    :1;
        uint32          :1;
        uint32 CDMEIF5   :1;
        uint32 CTEIF5    :1;
        uint32 CHTIF5    :1;
        uint32 CTCIF5    :1;
        uint32          :4;
        uint32 CFEIF6    :1;
        uint32          :1;
        uint32 CDMEIF6   :1;
        uint32 CTEIF6    :1;
        uint32 CHTIF6    :1;
        uint32 CTCIF6    :1;
        uint32 CFEIF7    :1;
        uint32          :1;
        uint32 CDMEIF7   :1;
        uint32 CTEIF7    :1;
        uint32 CHTIF7    :1;
        uint32 CTCIF7    :1;
        uint32          :4;
    } Field;
    uint32 Word;
} dtDMA_HIFCR;

typedef union
{
    struct
    {
        uint16      NDT;
    } Field;
    uint32 Word;
} dtDMA_S0NDTR;

typedef union
{
    struct
    {
        uint32 FTH  :2;
        uint32 DMDIS:1;
        uint32 FS   :3;
        uint32      :1;
        uint32 FEIE :1;
    } Field;
    uint32 Word;
} dtDMA_S0FCR;

typedef struct
{
    dtDMA_S0CR      S0CR;
    dtDMA_S0NDTR    S0NDTR;
    uint32          PAR;
    uint32          MAR0;
    uint32          MAR1;
    dtDMA_S0FCR     S0FCR;
} dtDMA_Channelx;

typedef struct
{
    dtDMA_LISR      LISR;
    dtDMA_HISR      HISR;
    dtDMA_LIFCR     LIFCR;
    dtDMA_HIFCR     HIFCR;
    dtDMA_Channelx  CH[8];
} dtDMAx;

#elif defined(MCU_L476)
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
} dtDMA_ChannelDesc;

typedef struct
{
	dtISR ISR;
	dtIFCR ICFR;
	dtDMA_ChannelDesc CH[7];
	uint32 :32;//0x94
	uint32 :32;//0x98
	uint32 :32;//0x9C
	uint32 :32;//0xA0
	uint32 :32;//0xA4
	dtCSELR CSELR;
} dtDMAx;
#endif

#endif /* ST_FRAMEWORK_SRC_DMA_DMA_TYPES_H_ */

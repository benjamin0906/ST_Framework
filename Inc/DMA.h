/*
 * DMA.h
 *
 *  Created on: 11 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef ST_FRAMEWORK_SRC_DMA_DMA_H_
#define ST_FRAMEWORK_SRC_DMA_DMA_H_

#include "types.h"
#include "DMA_ExtTypes.h"

typedef enum
{
	DMA_1,
	DMA_2,
} dtDMAInstance;

typedef enum
{
	Ch1,
	Ch2,
	Ch3,
	Ch4,
	Ch5,
	Ch6,
	Ch7,
} dtChannel;

#define DMA_PER2MEM         0
#define DMA_MEM2PER         1
#define DMA_MEM2MEM         2

#define DMA_CIRC            (1)

#define DMA_PER_INC         (1)

#define DMA_MEM_INC         (1)

#define DMA_PER_8           (0)
#define DMA_PER_16          (1)
#define DMA_PER_32          (2)

#define DMA_MEM_8           0
#define DMA_MEM_16          1
#define DMA_MEM_32          2

#define DMA_PRIO_L          0
#define DMA_PRIO_M          1
#define DMA_PRIO_H          2
#define DMA_PRIO_VH         3

#define DMA_CS0		0
#define DMA_CS1		1
#define DMA_CS2		2
#define DMA_CS3		3
#define DMA_CS4		4
#define DMA_CS5		5
#define DMA_CS6		6
#define DMA_CS7		7
#define DMA_CS8		8
#define DMA_CS9		9
#define DMA_CS10	10
#define DMA_CS11	11
#define DMA_CS12	12
#define DMA_CS13	13
#define DMA_CS14	14
#define DMA_CS15	15

extern void DMA_Set(dtDMAInstance Instance, dtChannel Ch, uint32* MemAddr, uint32* PeripheralAddr, dtDMA_S0CR Config, uint8 IntPrio, void(IntFunc)(void));
extern void DMA_Start(dtDMAInstance Instance, dtChannel Ch, uint16 Amount);
extern void DMA_Stop(dtDMAInstance Instance, dtChannel Ch);

#endif /* ST_FRAMEWORK_SRC_DMA_DMA_H_ */

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
	DmaStream_0,
	DmaStream_1,
	DmaStream_2,
	DmaStream_3,
	DmaStream_4,
	DmaStream_5,
	DmaStream_6,
    DmaStream_7,
} dtDmaStream;

typedef struct
{
    dtDMAInstance   Instance;
    dtDmaStream     Stream;
    void*           Mem0Ptr;
    void*           Mem1Ptr;
    void*           PerPtr;
    uint8           RequestChannel      :3;
    uint8           Priority            :2;

    /* 0b00: byte; 0b01: half-word; 0b10: word */
    uint8           MemoryDataSize      :2;

    /* 0b00: byte; 0b01: half-word; 0b10: word */
    uint8           PeripheralDataSize  :2;

    /* 0b0: Address is fixed; 0b1: Address is incremented after transfer */
    uint8           MemAddrInc          :1;

    /* 0b0: Address is fixed; 0b1: Address is incremented after transfer */
    uint8           PerAddrInc          :1;
    uint8           CircularMode        :1;

    /* 0b00: pripheral-to-memory; 0b01: memory-to-peripheral; 0b10: memory-to-memory */
    uint8           TransferDirection   :2;
} dtDmaConfig;

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

extern void IDMA_Config(const dtDmaConfig *const Config, void (*IrqHandler)(uint8 Flags, uint32 NumOfData));
extern void DMA_Start(dtDMAInstance Instance, dtDmaStream DmaChannel, uint16 Amount);
extern void DMA_Stop(dtDMAInstance Instance, dtDmaStream DmaChannel);

#endif /* ST_FRAMEWORK_SRC_DMA_DMA_H_ */

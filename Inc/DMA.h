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

#define DMA1                        0
#define DMA2                        1

#define DmaStream_0                 0
#define DmaStream_1                 1
#define DmaStream_2                 2
#define DmaStream_3                 3
#define DmaStream_4                 4
#define DmaStream_5                 5
#define DmaStream_6                 6
#define DmaStream_7                 7

#define Stream0                 0
#define Stream1                 1
#define Stream2                 2
#define Stream3                 3
#define Stream4                 4
#define Stream5                 5
#define Stream6                 6
#define Stream7                 7

#if defined(MCU_F446)
#define MEMPTR_COUNT 2
#elif defined(MCU_L476)
#define MEMPTR_COUNT 1
#define MEM2MEM_OPTION (STD_ON)
#endif

typedef enum
{
	DMA_Instance_1 = 0,
	DMA_Instance_2 = 1,
} dtDMAInstance;

typedef enum
{
	DmaStream_0_,
	DmaStream_1_,
	DmaStream_2_,
	DmaStream_3_,
	DmaStream_4_,
	DmaStream_5_,
	DmaStream_6_,
    DmaStream_7_,
} dtDmaStream;

typedef struct
{
    dtDMAInstance   Instance;
    dtDmaStream     Stream;
#if MEMPTR_COUNT == 1
    void*           MemPtr;
#elif MEMPTR_COUNT == 2
    void*           Mem0Ptr;
    void*           Mem1Ptr;
#endif
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

typedef struct
{
	uint32 *perPtr;
	uint32 *memPtr;

	/* 0b0: disabled
	 * 0b1: enabled
	 *  */
	uint32 CircularMode :1;

	/* 0b0: reading from the peripheral ptr
	 * 0b1: reading from the memory ptr
	 *  */
	uint32 Direcion  :1;

	/* 0b0: DMA increments the peripheral pointer after a read/write
	 * 0b1: DMA doesn't increment the peripheral pointer after a read/write
	 * */
	uint32 PeripheralIncrement :1;

	/* 0b0: DMA increments the memory pointer after a read/write
	 * 0b1: DMA doesn't increment the memory pointer after a read/write
	 * */
	uint32 MemIncrement :1;

	/* 0b00: 8 bits
	 * 0b01: 16 bits
	 * 0b10: 32 bits
	 * 0b11: reserved
	 * */
	uint32 PeripheralWidth : 2;

	/* 0b00: 8 bits
	 * 0b01: 16 bits
	 * 0b10: 32 bits
	 * 0b11: reserved
	 * */
	uint32 MemoryWidth : 2;

	/* 0b00: low
	 * 0b01: medium
	 * 0b10: high
	 * 0b11: very high
	 * */
	uint32 PriorityLevel: 2;

	/* This mode ensures that the transfer is triggered by SW. In this mode the circular mode shall be disabled!!!
	 * 0b0: disabled
	 * 0b1: enabled */
	uint32 Mem2Mem :1;
} dtDmaCfg;

extern void IDMA_Config(const dtDmaConfig *const Config, void (*IrqHandler)(uint8 Flags, uint32 NumOfData));
extern void DMA_Start(dtDMAInstance Instance, dtDmaStream DmaChannel, uint16 Amount);
extern void DMA_StartWithNew(dtDMAInstance Instance, dtDmaStream DmaChannel, uint16 Amount, void *Peripheral_Src, void *Memory_Dst);
extern uint8 IDMA_IsFree(dtDMAInstance Instance, dtDmaStream DmaChannel);
extern void DMA_Stop(dtDMAInstance Instance, dtDmaStream DmaChannel);

#endif /* ST_FRAMEWORK_SRC_DMA_DMA_H_ */

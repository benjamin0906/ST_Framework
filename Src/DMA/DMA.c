/*
 * DMA.c
 *
 *  Created on: 10 May 2020
 *      Author: Bodnár Benjamin
 */

#include "DMA_Types.h"
#include "DMA.h"
#include "NVIC.h"

static dtDMAx *const DMA[2] = {(dtDMAx*)(0x40020000),(dtDMAx*)(0x40020400)};
static void (*DMA_IntFunc[2][7])(void);

void DMA_Set(dtDMAInstance Instance, dtChannel Ch, uint32* MemAddr, uint32* PeripheralAddr, uint32 options, void(IntFunc)(void));
void DMA_Start(dtDMAInstance Instance, dtChannel Ch, uint16 Amount);
void DMA_Stop(dtDMAInstance Instance, dtChannel Ch);
uint8 DMA_GetStatus(dtChannel Ch);

void DMA_Set(dtDMAInstance Instance, dtChannel Ch, uint32* MemAddr, uint32* PeripheralAddr, uint32 options, void(IntFunc)(void))
{
	DMA[Instance]->CH[Ch].CCR.Word = 0;

	DMA[Instance]->CH[Ch].CPAR = (uint32)PeripheralAddr;
	DMA[Instance]->CH[Ch].CMAR = (uint32)MemAddr;

	dtDMA_CCRx Tccr = {.Word = 0};

	/* Set the interrupts according to the options */
	if(options & 0x10) Tccr.Field.TCIE = 1;
	else Tccr.Field.TCIE = 0;
	if(options & 0x20) Tccr.Field.HTIE = 1;
	else Tccr.Field.HTIE = 0;
	if(options & 0x40) Tccr.Field.TEIE = 1;
	else Tccr.Field.TEIE = 0;

	if(options & 0x70)
	{
		if(IntFunc != 0)
		{
			DMA_IntFunc[Instance][Ch] = IntFunc;
			uint8 IntPriority = options >> DMA_INT_PRIO_FIELD;
			IRQn_Type IRQ = 0;
			if(Instance == DMA_1)
			{
				switch(Ch)
				{
				case Ch1:
					IRQ = DMA1_Channel1_IRQn;
					break;
				case Ch2:
					IRQ = DMA1_Channel2_IRQn;
					break;
				case Ch3:
					IRQ = DMA1_Channel3_IRQn;
					break;
				case Ch4:
					IRQ = DMA1_Channel4_IRQn;
					break;
				case Ch5:
					IRQ = DMA1_Channel5_IRQn;
					break;
				case Ch6:
					IRQ = DMA1_Channel6_IRQn;
					break;
				case Ch7:
					IRQ = DMA1_Channel1_IRQn;
					break;
				}
			}
			else
			{
				switch(Ch)
				{
				case Ch1:
					IRQ = DMA2_Channel1_IRQn;
					break;
				case Ch2:
					IRQ = DMA2_Channel2_IRQn;
					break;
				case Ch3:
					IRQ = DMA2_Channel3_IRQn;
					break;
				case Ch4:
					IRQ = DMA2_Channel4_IRQn;
					break;
				case Ch5:
					IRQ = DMA2_Channel5_IRQn;
					break;
				case Ch6:
					IRQ = DMA2_Channel6_IRQn;
					break;
				case Ch7:
					IRQ = DMA2_Channel1_IRQn;
					break;
				}
			}
			NVIC_SetPriority(IRQ, IntPriority);
			NVIC_EnableIRQ(IRQ);
		}
	}

	/* set the direction */
	if((options & 0x80) == DMA_PERREAD) Tccr.Field.DIR = 0;
	else Tccr.Field.DIR = 1;

	/* Set the circulation option of the DMA */
	if(options & DMA_CIRC) Tccr.Field.CIRC = 1;
	else Tccr.Field.CIRC = 0;

	/* Set the incrementing of the peripheral address */
	if(options & DMA_PER_INC) Tccr.Field.PINC = 1;
	else Tccr.Field.PINC = 0;

	/* Set the incrementing of the memory address */
	if(options & DMA_MEM_INC) Tccr.Field.MINC = 1;
	else Tccr.Field.MINC = 0;

	/* Set the peripheral size */
	switch(options & 0x1800)
	{
	case DMA_PER_8:
		Tccr.Field.PSIZE = 0;
		break;
	case DMA_PER_16:
		Tccr.Field.PSIZE = 1;
		break;
	case DMA_PER_32:
		Tccr.Field.PSIZE = 2;
		break;
	default:
		Tccr.Field.PSIZE = 0;
	}

	/* Set the memory size */
	switch(options & 0x6000)
	{
	case DMA_MEM_8:
		Tccr.Field.MSIZE = 0;
		break;
	case DMA_MEM_16:
		Tccr.Field.MSIZE = 1;
		break;
	case DMA_MEM_32:
		Tccr.Field.MSIZE = 2;
		break;
	default:
		Tccr.Field.MSIZE = 0;
	}

	/* Set the priority level */
	switch(options & 0x18000)
	{
	case DMA_PRIO_L:
		Tccr.Field.PL = 0;
		break;
	case DMA_PRIO_M:
		Tccr.Field.PL = 1;
		break;
	case DMA_PRIO_H:
		Tccr.Field.PL = 2;
		break;
	case DMA_PRIO_VH:
		Tccr.Field.PL = 3;
		break;
	}

	/* set the mem2mem bit */
	if(options & DMA_MEM2MEM) Tccr.Field.MEM2MEM = 1;
	else Tccr.Field.MEM2MEM = 0;

	DMA[Instance]->CH[Ch].CCR = Tccr;

	DMA[Instance]->CSELR.Word &= ~(0xF<<(Ch<<2));
	DMA[Instance]->CSELR.Word |= (options & 0xF)<<(Ch<<2);
}

void DMA_Start(dtDMAInstance Instance, dtChannel Ch, uint16 Amount)
{
	dtDMA_CCRx Tccr = DMA[Instance]->CH[Ch].CCR;
	DMA[Instance]->CH[Ch].CNDTR.Word = Amount;
	Tccr.Field.EN = 1;
	DMA[Instance]->CH[Ch].CCR = Tccr;
}

void DMA_Stop(dtDMAInstance Instance, dtChannel Ch)
{
	dtDMA_CCRx Tccr = DMA[Instance]->CH[Ch].CCR;
	Tccr.Field.EN = 0;
	DMA[Instance]->CH[Ch].CCR = Tccr;
}

void DMA1_CH1_IRQHandler(void)
{
	if(DMA_IntFunc[0][0] != 0) (*DMA_IntFunc[0][0])();
}

void DMA1_CH2_IRQHandler(void)
{
	if(DMA_IntFunc[0][1] != 0) (*DMA_IntFunc[0][1])();
}

void DMA1_CH3_IRQHandler(void)
{
	if(DMA_IntFunc[0][2] != 0) (*DMA_IntFunc[0][2])();
}

void DMA1_CH4_IRQHandler(void)
{
	if(DMA_IntFunc[0][3] != 0) (*DMA_IntFunc[0][3])();
}

void DMA1_CH5_IRQHandler(void)
{
	if(DMA_IntFunc[0][4] != 0) (*DMA_IntFunc[0][4])();
}

void DMA1_CH6_IRQHandler(void)
{
	if(DMA_IntFunc[0][5] != 0) (*DMA_IntFunc[0][5])();
}

void DMA1_CH7_IRQHandler(void)
{
	if(DMA_IntFunc[0][6] != 0) (*DMA_IntFunc[0][6])();
}

void DMA2_CH1_IRQHandler(void)
{
	if(DMA_IntFunc[1][0] != 0) (*DMA_IntFunc[1][0])();
}

void DMA2_CH2_IRQHandler(void)
{
	if(DMA_IntFunc[1][1] != 0) (*DMA_IntFunc[1][1])();
}

void DMA2_CH3_IRQHandler(void)
{
	if(DMA_IntFunc[1][2] != 0) (*DMA_IntFunc[1][2])();
}

void DMA2_CH4_IRQHandler(void)
{
	if(DMA_IntFunc[1][3] != 0) (*DMA_IntFunc[1][3])();
}

void DMA2_CH5_IRQHandler(void)
{
	if(DMA_IntFunc[1][4] != 0) (*DMA_IntFunc[1][4])();
}

void DMA2_CH6_IRQHandler(void)
{
	if(DMA_IntFunc[1][5] != 0) (*DMA_IntFunc[1][5])();
}

void DMA2_CH7_IRQHandler(void)
{
	if(DMA_IntFunc[1][6] != 0) (*DMA_IntFunc[1][6])();
}

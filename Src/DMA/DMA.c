/*
 * DMA.c
 *
 *  Created on: 10 May 2020
 *      Author: Bodnár Benjamin
 */

#include "DMA_Types.h"
#include "DMA.h"
#include "NVIC.h"
#if defined(MCU_F446)
static dtDMAx *const DMA[2] = {(dtDMAx*)(0x40020000),(dtDMAx*)(0x40020400)};
static void (*DMA_IntFunc[2][7])(uint8 Flags, uint32 Cntr);

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
			dtIRQs IRQ = 0;
			if(Instance == DMA_1)
			{
				switch(Ch)
				{
				case Ch1:
					IRQ = IRQ_DMA1_Stream0;
					break;
				case Ch2:
					IRQ = IRQ_DMA1_Stream1;
					break;
				case Ch3:
					IRQ = IRQ_DMA1_Stream2;
					break;
				case Ch4:
					IRQ = IRQ_DMA1_Stream3;
					break;
				case Ch5:
					IRQ = IRQ_DMA1_Stream4;
					break;
				case Ch6:
					IRQ = IRQ_DMA1_Stream5;
					break;
				case Ch7:
					IRQ = IRQ_DMA1_Stream6;
					break;
				}
			}
			else
			{
				switch(Ch)
				{
				case Ch1:
					IRQ = IRQ_DMA2_Stream0;
					break;
				case Ch2:
					IRQ = IRQ_DMA2_Stream1;
					break;
				case Ch3:
					IRQ = IRQ_DMA2_Stream2;
					break;
				case Ch4:
					IRQ = IRQ_DMA2_Stream3;
					break;
				case Ch5:
					IRQ = IRQ_DMA2_Stream4;
					break;
				case Ch6:
					IRQ = IRQ_DMA2_Stream5;
					break;
				case Ch7:
					IRQ = IRQ_DMA2_Stream6;
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
	if(DMA_IntFunc[0][0] != 0) (*DMA_IntFunc[0][0])(DMA[0]->ISR.Word&0xF, DMA[0]->CH[0].CNDTR.Word);
}

void DMA1_CH2_IRQHandler(void)
{
	if(DMA_IntFunc[0][1] != 0) (*DMA_IntFunc[0][1])((DMA[0]->ISR.Word>>4) & 0xF, DMA[0]->CH[1].CNDTR.Word);
}

void DMA1_CH3_IRQHandler(void)
{
	if(DMA_IntFunc[0][2] != 0) (*DMA_IntFunc[0][2])((DMA[0]->ISR.Word>>8) & 0xF, DMA[0]->CH[2].CNDTR.Word);
}

void DMA1_CH4_IRQHandler(void)
{
	if(DMA_IntFunc[0][3] != 0) (*DMA_IntFunc[0][3])((DMA[0]->ISR.Word>>12) & 0xF, DMA[0]->CH[3].CNDTR.Word);
}

void DMA1_CH5_IRQHandler(void)
{
	if(DMA_IntFunc[0][4] != 0) (*DMA_IntFunc[0][4])((DMA[0]->ISR.Word>>16) & 0xF, DMA[0]->CH[4].CNDTR.Word);
	DMA[0]->ICFR.Word = 0xF0000;
}

void DMA1_CH6_IRQHandler(void)
{
	if(DMA_IntFunc[0][5] != 0) (*DMA_IntFunc[0][5])((DMA[0]->ISR.Word>>20) & 0xF, DMA[0]->CH[5].CNDTR.Word);
}

void DMA1_CH7_IRQHandler(void)
{
	if(DMA_IntFunc[0][6] != 0) (*DMA_IntFunc[0][6])((DMA[0]->ISR.Word>>24) & 0xF, DMA[0]->CH[6].CNDTR.Word);
}

void DMA2_CH1_IRQHandler(void)
{
	if(DMA_IntFunc[1][0] != 0) (*DMA_IntFunc[1][0])((DMA[0]->ISR.Word>>0) & 0xF, DMA[1]->CH[0].CNDTR.Word);
}

void DMA2_CH2_IRQHandler(void)
{
	if(DMA_IntFunc[1][1] != 0) (*DMA_IntFunc[1][1])((DMA[0]->ISR.Word>>4) & 0xF, DMA[1]->CH[1].CNDTR.Word);
}

void DMA2_CH3_IRQHandler(void)
{
	if(DMA_IntFunc[1][2] != 0) (*DMA_IntFunc[1][2])((DMA[0]->ISR.Word>>8) & 0xF, DMA[1]->CH[2].CNDTR.Word);
}

void DMA2_CH4_IRQHandler(void)
{
	if(DMA_IntFunc[1][3] != 0) (*DMA_IntFunc[1][3])((DMA[0]->ISR.Word>>12) & 0xF, DMA[1]->CH[3].CNDTR.Word);
}

void DMA2_CH5_IRQHandler(void)
{
	if(DMA_IntFunc[1][4] != 0) (*DMA_IntFunc[1][4])((DMA[0]->ISR.Word>>16) & 0xF, DMA[1]->CH[4].CNDTR.Word);
}

void DMA2_CH6_IRQHandler(void)
{
	if(DMA_IntFunc[1][5] != 0) (*DMA_IntFunc[1][5])((DMA[0]->ISR.Word>>20) & 0xF, DMA[1]->CH[5].CNDTR.Word);
}

void DMA2_CH7_IRQHandler(void)
{
	if(DMA_IntFunc[1][6] != 0) (*DMA_IntFunc[1][6])((DMA[0]->ISR.Word>>24) & 0xF, DMA[1]->CH[6].CNDTR.Word);
}
#endif

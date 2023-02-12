/*
 * DMA.c
 *
 *  Created on: 10 May 2020
 *      Author: Bodnár Benjamin
 */

#include "DMA_Types.h"
#include "DMA.h"
#include "NVIC.h"
#if defined(MCU_L476)
static dtDMAx *const DMA[2] = {(dtDMAx*)(0x40020000),(dtDMAx*)(0x40020400)};
#elif defined(MCU_F446)
static dtDMAx *const DMA[2] = {(dtDMAx*)(0x40026000),(dtDMAx*)(0x40026400)};
#endif

#define DISABLE()   do                                                  \
                    {                                                   \
                        dtDMA_S0CR Temp = DMA[Instance]->CH[DmaChannel].S0CR;   \
                        Temp.Field.EN = 0;                              \
                        DMA[Instance]->CH[DmaChannel].S0CR = Temp;              \
                    }                                                   \
                    while(0)

#define ENABLE()    do                                                  \
                    {                                                   \
                        dtDMA_S0CR Temp = DMA[Instance]->CH[DmaChannel].S0CR;   \
                        Temp.Field.EN = 1;                              \
                        DMA[Instance]->CH[DmaChannel].S0CR = Temp;              \
                    }                                                   \
                    while(0)
#define DMA_GET_OPTION(optionVar, option)   ((optionVar&DMA_##option##_MASK)>>DMA_##option##_PLACE)

#if defined(MCU_F446) || defined(MCU_L476)
static void (*DMA_IntFunc[2][8])(uint8 Flags, uint32 Cntr);

void IDMA_Config(const dtDmaConfig *const Config, void (*IrqHandler)(uint8 Flags, uint32 NumOfData));
void DMA_Set(dtDMAInstance Instance, dtDmaStream DmaChannel, uint32* MemAddr, uint32* PeripheralAddr, dtDMA_S0CR Config, uint8 IntPrio, void(IntFunc)(void));
void DMA_Start(dtDMAInstance Instance, dtDmaStream DmaChannel, uint16 Amount);
void DMA_Stop(dtDMAInstance Instance, dtDmaStream DmaChannel);
uint8 DMA_GetStatus(dtDmaStream Ch);
#endif

#if defined(MCU_L476)

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
			if(Instance == DMA1)
			{
				switch(Ch)
				{
				case DmaStream_1:
#if defined(MCU_F446)
					IRQ = IRQ_DMA1_Stream0;
#elif defined(MCU_L476)
					IRQ = IRQ_DMA_CH1;
#endif
					break;
				case DmaStream_2:
#if defined(MCU_F446)
					IRQ = IRQ_DMA1_Stream1;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA_CH2;
#endif
					break;
				case DmaStream_3:
#if defined(MCU_F446)
					IRQ = IRQ_DMA1_Stream2;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA_CH3;
#endif
					break;
				case DmaStream_4:
#if defined(MCU_F446)
					IRQ = IRQ_DMA1_Stream3;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA_CH4;
#endif
					break;
				case DmaStream_5:
#if defined(MCU_F446)
					IRQ = IRQ_DMA1_Stream4;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA_CH5;
#endif
					break;
				case DmaStream_6:
#if defined(MCU_F446)
					IRQ = IRQ_DMA1_Stream5;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA_CH6;
#endif
					break;
				case DmaStream_7:
#if defined(MCU_F446)
					IRQ = IRQ_DMA1_Stream6;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA_CH7;
#endif
					break;
				}
			}
			else
			{
				switch(Ch)
				{
				case DmaStream_1:
#if defined(MCU_F446)
					IRQ = IRQ_DMA2_Stream0;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA2_CH1;
#endif
					break;
				case DmaStream_2:
#if defined(MCU_F446)
					IRQ = IRQ_DMA2_Stream1;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA2_CH2;
#endif
					break;
				case DmaStream_3:
#if defined(MCU_F446)
					IRQ = IRQ_DMA2_Stream2;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA2_CH3;
#endif
					break;
				case DmaStream_4:
#if defined(MCU_F446)
					IRQ = IRQ_DMA2_Stream3;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA2_CH4;
#endif
					break;
				case DmaStream_5:
#if defined(MCU_F446)
					IRQ = IRQ_DMA2_Stream4;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA2_CH5;
#endif
					break;
				case DmaStream_6:
#if defined(MCU_F446)
					IRQ = IRQ_DMA2_Stream5;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA2_CH6;
#endif
					break;
				case DmaStream_7:
#if defined(MCU_F446)
					IRQ = IRQ_DMA2_Stream6;
#elif defined(MCU_L476)
                    IRQ = IRQ_DMA2_CH7;
#endif
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

#elif defined(MCU_F446)
void IDMA_Config(const dtDmaConfig *const Config, void (*IrqHandler)(uint8 Flags, uint32 NumOfData))
{
    dtDMA_Channelx *streamPtr = &DMA[Config->Instance]->CH[Config->Stream];
    dtDMA_S0CR      tCr = streamPtr->S0CR;
    if(tCr.Field.EN == 0)
    {
        dtDMA_S0CR tStreamConfReg = {.Word = 0};

        /* Setting the memory addresses */
        streamPtr->PAR = Config->PerPtr;
        streamPtr->MAR0 = Config->Mem0Ptr;
        streamPtr->MAR1 = Config->Mem1Ptr;

        /* If both of the memory pointer is valid it means double buffer mode is needed */
        tStreamConfReg.Field.DBM = (Config->Mem0Ptr != 0) && (Config->Mem1Ptr != 0);

        tStreamConfReg.Field.CHSEL  = Config->RequestChannel;
        tStreamConfReg.Field.PL     = Config->Priority;
        tStreamConfReg.Field.MSIZE  = Config->MemoryDataSize;
        tStreamConfReg.Field.PSIZE  = Config->PeripheralDataSize;
        tStreamConfReg.Field.MINC   = Config->MemAddrInc;
        tStreamConfReg.Field.PINC   = Config->PerAddrInc;
        tStreamConfReg.Field.CIRC   = Config->CircularMode;
        tStreamConfReg.Field.DIR    = Config->TransferDirection;

        /* If there is an IRQ handler the IRQ shall be enabled */
        if(IrqHandler != 0)
        {
            tStreamConfReg.Field.TCIE = 1;
            DMA_IntFunc[Config->Instance][Config->Stream] = IrqHandler;
        }

        streamPtr->S0CR = tStreamConfReg;
    }
}
#endif

#if defined(MCU_L476)
void DMA_Start(dtDMAInstance Instance, dtChannel Ch, uint16 Amount)
{
	dtDMA_CCRx Tccr = DMA[Instance]->CH[Ch].CCR;
	DMA[Instance]->CH[Ch].CNDTR.Word = Amount;
	Tccr.Field.EN = 1;
	DMA[Instance]->CH[Ch].CCR = Tccr;
}
#elif defined(MCU_F446)
void DMA_Start(dtDMAInstance Instance, dtDmaStream DmaChannel, uint16 Amount)
{
    DISABLE();
    switch(DmaChannel)
    {
        case DmaStream_0:
            DMA[Instance]->LIFCR.Word = (0x3D << 0);
            break;
        case DmaStream_1:
            DMA[Instance]->LIFCR.Word = (0x3D << 6);
            break;
        case DmaStream_2:
            DMA[Instance]->LIFCR.Word = (0x3D << 16);
            break;
        case DmaStream_3:
            DMA[Instance]->LIFCR.Word = (0x3D << 22);
            break;
        case DmaStream_4:
            DMA[Instance]->HIFCR.Word = (0x3D << 0);
            break;
        case DmaStream_5:
            DMA[Instance]->HIFCR.Word = (0x3D << 6);
            break;
        case DmaStream_6:
            DMA[Instance]->HIFCR.Word = (0x3D << 16);
            break;
        case DmaStream_7:
            DMA[Instance]->HIFCR.Word = (0x3D << 22);
            break;
    }
    DMA[Instance]->CH[DmaChannel].S0NDTR.Word = Amount;
    ENABLE();
}
#endif

#if defined(MCU_L476)
void DMA_Stop(dtDMAInstance Instance, dtChannel Ch)
{
	dtDMA_CCRx Tccr = DMA[Instance]->CH[Ch].CCR;
	Tccr.Field.EN = 0;
	DMA[Instance]->CH[Ch].CCR = Tccr;
}
#elif defined(MCU_F446)
void DMA_Stop(dtDMAInstance Instance, dtDmaStream DmaChannel)
{
    DISABLE();
}
#endif


#if defined(MCU_L476)
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

#elif defined(MCU_F446)
void DMA1_Stream0_IRQHandler(void)
{
    if(DMA_IntFunc[0][0] != 0) (*DMA_IntFunc[0][0])((DMA[0]->LISR.Word >> 0) & 0x3F, DMA[0]->CH[0].S0NDTR.Word);
    DMA[0]->LIFCR.Word = (0x3D << 0);
}

void DMA1_Stream1_IRQHandler(void)
{
    if(DMA_IntFunc[0][1] != 0) (*DMA_IntFunc[0][1])((DMA[0]->LISR.Word >> 6) & 0x3F, DMA[0]->CH[1].S0NDTR.Word);
    DMA[0]->LIFCR.Word = (0x3D << 6);
}

void DMA1_Stream2_IRQHandler(void)
{
    if(DMA_IntFunc[0][2] != 0) (*DMA_IntFunc[0][2])((DMA[0]->LISR.Word >> 16) & 0x3F, DMA[0]->CH[2].S0NDTR.Word);
    DMA[0]->LIFCR.Word = (0x3D << 16);
}

void DMA1_Stream3_IRQHandler(void)
{
    if(DMA_IntFunc[0][3] != 0) (*DMA_IntFunc[0][3])((DMA[0]->LISR.Word >> 22) & 0x3F, DMA[0]->CH[3].S0NDTR.Word);
    DMA[0]->LIFCR.Word = (0x3D << 22);
}

void DMA1_Stream4_IRQHandler(void)
{
    if(DMA_IntFunc[0][4] != 0) (*DMA_IntFunc[0][4])((DMA[0]->HISR.Word >> 0) & 0x3F, DMA[0]->CH[4].S0NDTR.Word);
    DMA[0]->HIFCR.Word = (0x3D << 0);
}

void DMA1_Stream5_IRQHandler(void)
{
    if(DMA_IntFunc[0][5] != 0) (*DMA_IntFunc[0][5])((DMA[0]->HISR.Word >> 6) & 0x3F, DMA[0]->CH[5].S0NDTR.Word);
    DMA[0]->HIFCR.Word = (0x3D << 6);
}

void DMA1_Stream6_IRQHandler(void)
{
    if(DMA_IntFunc[0][6] != 0) (*DMA_IntFunc[0][6])((DMA[0]->HISR.Word >> 16) & 0x3F, DMA[0]->CH[6].S0NDTR.Word);
    DMA[0]->HIFCR.Word = (0x3D << 16);
}

void DMA1_Stream7_IRQHandler(void)
{
    if(DMA_IntFunc[0][7] != 0) (*DMA_IntFunc[0][7])((DMA[0]->HISR.Word >> 22) & 0x3F, DMA[0]->CH[7].S0NDTR.Word);
    DMA[0]->HIFCR.Word = (0x3D << 22);
}

void DMA2_Stream0_IRQHandler(void)
{
    if(DMA_IntFunc[1][0] != 0) (*DMA_IntFunc[1][0])((DMA[0]->LISR.Word >> 0) & 0x3F, DMA[0]->CH[0].S0NDTR.Word);
    DMA[1]->LIFCR.Word = (0x3D << 0);
}

void DMA2_Stream1_IRQHandler(void)
{
    if(DMA_IntFunc[1][1] != 0) (*DMA_IntFunc[1][1])((DMA[0]->LISR.Word >> 6) & 0x3F, DMA[0]->CH[1].S0NDTR.Word);
    DMA[1]->LIFCR.Word = (0x3D << 6);
}

void DMA2_Stream2_IRQHandler(void)
{
    if(DMA_IntFunc[1][2] != 0) (*DMA_IntFunc[1][2])((DMA[0]->LISR.Word >> 16) & 0x3F, DMA[0]->CH[2].S0NDTR.Word);
    DMA[1]->LIFCR.Word = (0x3D << 16);
}

void DMA2_Stream3_IRQHandler(void)
{
    if(DMA_IntFunc[1][3] != 0) (*DMA_IntFunc[1][3])((DMA[0]->LISR.Word >> 22) & 0x3F, DMA[0]->CH[3].S0NDTR.Word);
    DMA[1]->LIFCR.Word = (0x3D << 22);
}

void DMA2_Stream4_IRQHandler(void)
{
    if(DMA_IntFunc[1][4] != 0) (*DMA_IntFunc[1][4])((DMA[0]->HISR.Word >> 0) & 0x3F, DMA[0]->CH[4].S0NDTR.Word);
    DMA[1]->HIFCR.Word = (0x3D << 0);
}

void DMA2_Stream5_IRQHandler(void)
{
    if(DMA_IntFunc[1][5] != 0) (*DMA_IntFunc[1][5])((DMA[0]->HISR.Word >> 6) & 0x3F, DMA[0]->CH[5].S0NDTR.Word);
    DMA[1]->HIFCR.Word = (0x3D << 6);
}

void DMA2_Stream6_IRQHandler(void)
{
    if(DMA_IntFunc[1][6] != 0) (*DMA_IntFunc[1][6])((DMA[0]->HISR.Word >> 16) & 0x3F, DMA[0]->CH[6].S0NDTR.Word);
    DMA[1]->HIFCR.Word = (0x3D << 16);
}

void DMA2_Stream7_IRQHandler(void)
{
    if(DMA_IntFunc[1][7] != 0) (*DMA_IntFunc[1][7])((DMA[0]->HISR.Word >> 22) & 0x3F, DMA[0]->CH[7].S0NDTR.Word);
    DMA[1]->HIFCR.Word = (0x3D << 22);
}
#endif

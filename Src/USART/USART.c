/*
 * USART.c
 *
 *  Created on: Nov 5, 2020
 *      Author: BodnarB
 */

#include "USART.h"
#include "RCC.h"
#include "NVIC.h"
#include "config.h"

#if defined(STM32U0)
#include "RegDefs/USART_reg.h"
#include "USART_Types.h"
#else
#endif

#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(STM32U0)
#if defined(MCU_G070) || defined(MCU_G071) || defined(STM32U0)
/* Not every USART instances has the same features. USART1 and 2 have full functionality but USART 3 and 4 have only basic functionality */
/* The registers of the module can only be accessed 32 bit operations */
static volatile dtUSARTx *const USART[4] = { (dtUSARTx*)MODULE_USART1,
							        (dtUSARTx*)MODULE_USART2,
							        (dtUSARTx*)MODULE_USART3,
							        (dtUSARTx*)MODULE_USART4};
#elif defined(MCU_F415)
static dtUSART *const USART[8] = {  (dtUSART*)0x40011000,
							        (dtUSART*)0x40004400,
							        (dtUSART*)0x40004800,
							        (dtUSART*)0x40004C00,
							        (dtUSART*)0x40005000,
							        (dtUSART*)0x40011400,
							        (dtUSART*)0x40007800,
							        (dtUSART*)0x40007C00};
#elif defined(MCU_L476)
static dtUSART *const USART[5] = {  (dtUSART*)0x40013800,
							        (dtUSART*)0x40004400,
							        (dtUSART*)0x40004800,
							        (dtUSART*)0x40004C00,
							        (dtUSART*)0x40005000};
#elif defined(MCU_F446)
static dtUSART *const USART[6] = {  (dtUSART*)0x40011000,
                                    (dtUSART*)0x40004400,
                                    (dtUSART*)0x40004800,
                                    (dtUSART*)0x40004C00,
                                    (dtUSART*)0x40005000,
                                    (dtUSART*)0x40011400};
#endif
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
uint8 TxFiFoUsart1[USART1_TX_FIFO_SIZE+1];
uint8 RxFiFoUsart1[USART1_RX_FIFO_SIZE+1];
static dtUSARTxData USART1Data = {.rxFifo = RxFiFoUsart1, .txFifo = TxFiFoUsart1};
#endif
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
uint8 TxFiFoUsart2[USART2_TX_FIFO_SIZE+1];
uint8 RxFiFoUsart2[USART2_RX_FIFO_SIZE+1];
static dtUSARTxData USART2Data = {.rxFifo = RxFiFoUsart2, .txFifo = TxFiFoUsart2};
#endif
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
uint8 TxFiFoUsart3[USART3_TX_FIFO_SIZE+1];
uint8 RxFiFoUsart3[USART3_RX_FIFO_SIZE+1];
static dtUSARTxData USART3Data = {.rxFifo = RxFiFoUsart3, .txFifo = TxFiFoUsart3};
#endif
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
uint8 TxFiFoUsart4[USART4_TX_FIFO_SIZE+1];
uint8 RxFiFoUsart4[USART4_RX_FIFO_SIZE+1];
static dtUSARTxData USART4Data = {.rxFifo = RxFiFoUsart4, .txFifo = TxFiFoUsart4};
#endif

void USART_Init(dtUSARTInstance Instance, dtUSARTConfig Config);
void USART_Send(dtUSARTInstance Instance, const uint8 *Data, uint8 DataSize);
uint8 USART_GetTxFifoFreeSize(dtUSARTInstance Instance);
uint8 USART_GetRxFifoFilledSize(dtUSARTInstance Instance);
uint8 USART_GetRxData(dtUSARTInstance Instance, uint8 *const outPtr);
void USART_Disable(dtUSARTInstance Instance);
uint8 USART_Transmitting(dtUSARTInstance Instance);

static inline uint8 ReadRxData(dtUSARTInstance instance);
static inline void WriteTxData(dtUSARTInstance instance, uint8 data);

void USART_Init(dtUSARTInstance Instance, dtUSARTConfig Config)
{
#if defined(MCU_G070) || defined(MCU_G071) || defined(STM32U0)
    dtUSART_CR1 TempCR1 = USART[Instance]->CR1;
    if(TempCR1.B.UE != 0)
    {
        TempCR1.B.UE = 0;
        USART[Instance]->CR1 = TempCR1;
    }
	if(TempCR1.B.UE == 0)
	{
	    TempCR1.U = 0;
	    dtUSART_PRESC tPresc = {.U = 0};
	    dtUSART_BRR tBrr = {.U = 0};
	    dtUSART_CR2 tCr2 = {.U = 0};

        /* Set 8 databits */
        TempCR1.B.M0 = 0;
        TempCR1.B.M1 = 0;

        /* Set parity */
        if(Config.Parity != None)
        {
            TempCR1.B.PCE = 1;
            if(Config.Parity == Odd) TempCR1.B.PS = 1;
        }

        /* Set stopbits */
        tCr2.B.STOP = Config.StopBits;

        tCr2.B.SWAP = Config.Swap;

	uint32 USARTClock = RCC_GetClock(ApbClock);
	int32 BaudDiff = 0x7FFFFFFF;
	uint8 SamplingLooper;
	for(SamplingLooper = 0; SamplingLooper < 2; SamplingLooper++)
	{
		uint8 PrescLooper = 12;
		if((Instance == USART3) || (Instance == USART4)) PrescLooper = 1;
		do
		{
			PrescLooper--;
			uint32 CalcBaseClock = USARTClock;

			/* In case of a 8-sampling the clock shall be doubled */
			if(SamplingLooper == 1) CalcBaseClock <<= 1;

			if(PrescLooper > 0)
			{
				if((PrescLooper <= 6)) CalcBaseClock /= (PrescLooper*2);
				else CalcBaseClock >>= ((PrescLooper-3));
			}
			uint32 CalculatedDiv = (CalcBaseClock<<1) / Config.Baud;

			/* Rounding */
			if(CalculatedDiv & 0x1) CalculatedDiv = (CalculatedDiv>>1) + 1;
			else CalculatedDiv = CalculatedDiv>>1;

			/* Calculate the abs difference between the calculated baud and the desired baud */
			int32 NewBaudDiff = Config.Baud-CalcBaseClock/CalculatedDiv;
			if(NewBaudDiff < 0) NewBaudDiff *= (-1);


			/* Save the parameter if it is better approximation than the previous */
			if(NewBaudDiff < BaudDiff)
			{
				BaudDiff = NewBaudDiff;
				TempCR1.B.OVER8 = SamplingLooper;

				tPresc.B.PRESCALER = PrescLooper;
				tBrr.B.BRR = CalculatedDiv;
			}
		}
		while(PrescLooper != 0);
	}

	/* Enable transmitter */
	TempCR1.B.TE = 1;

	/* Enable receiver */
	TempCR1.B.RE = 1;

	/* Enable USART */
	TempCR1.B.UE = 1;

	TempCR1.B.TXFNFIE = 0;
	TempCR1.B.RXFNEIE = 1;

	USART[Instance]->PRESC = tPresc;
	USART[Instance]->BRR = tBrr;
	USART[Instance]->CR2 = tCr2;
	USART[Instance]->CR1 = TempCR1;

	volatile dtUSART_RDR tRDR = USART[Instance]->RDR;

	switch(Instance)
	{
	case USART1:
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
		NVIC_SetPriority(IRQ_USART1,0);
		NVIC_EnableIRQ(IRQ_USART1);
#endif
		break;
	case USART2:
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
		NVIC_SetPriority(IRQ_USART2,0);
		NVIC_EnableIRQ(IRQ_USART2);
#endif
		break;
	case USART3:
	case USART4:
#if defined(MCU_G070) || defined(MCU_G0701)
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
		NVIC_SetPriority(IRQ_USART3_4,2);
		NVIC_EnableIRQ(IRQ_USART3_4);
#endif
#elif defined(STM32U0)
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
        //NVIC_SetPriority(IRQ_USART4_LPUART3,0);
        NVIC_EnableIRQ(IRQ_USART4_LPUART3);
#endif
#endif
		break;
	}
	}
#endif
}

void USART_Send(dtUSARTInstance Instance, const uint8 *Data, uint8 DataSize)
{
#if defined(MCU_G070) || defined(MCU_G071) || defined(STM32U0)
		dtUSARTxData *tBuff;
		uint8 mask;

		switch(Instance)
		{
		case USART1:
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
		    tBuff = &USART1Data;
            mask = USART1_TX_FIFO_SIZE;
#endif
			break;
		case USART2:
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
		    tBuff = &USART2Data;
		    mask = USART2_TX_FIFO_SIZE;
#endif
			break;
		case USART3:
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
		    tBuff = &USART3Data;
            mask = USART3_TX_FIFO_SIZE;
#endif
			break;
		case USART4:
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
			tBuff = &USART4Data;
            mask = USART4_TX_FIFO_SIZE;
#endif
			break;
		}
		while(DataSize > 0)
        {
		    tBuff->txFifo[tBuff->TxWriteIndex++] = *Data++;
		    tBuff->TxWriteIndex &= mask;
		    DataSize--;
        }
		USART_CR1_SET_BIT(Instance, CR1_BIT_TXFNFIE);
#endif
}

uint8 USART_GetRxData(dtUSARTInstance Instance, uint8 *const outPtr)
{
	uint8 ret = 0;
    dtUSARTxData *tBuff = 0;
    uint8 mask;
#if defined(MCU_G070) || defined(MCU_G071) || defined(STM32U0)
	switch(Instance)
	{
	case USART1:
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
        tBuff = &USART1Data;
        mask = USART1_RX_FIFO_SIZE;
#endif
		break;
	case USART2:
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
        tBuff = &USART2Data;
        mask = USART2_RX_FIFO_SIZE;
#endif
		break;
	case USART3:
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
        tBuff = &USART3Data;
        mask = USART3_RX_FIFO_SIZE;
#endif
		break;
	case USART4:
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
        tBuff = &USART4Data;
        mask = USART4_RX_FIFO_SIZE;
#endif
		break;
	}
	if(tBuff->RxReadIndex != tBuff->RxWriteIndex)
	{
	    ret = 1;
	    if(outPtr != 0)
	    {
	        *outPtr = tBuff->rxFifo[tBuff->RxReadIndex++];
	        tBuff->RxReadIndex &= mask;
	    }
	}
#endif
	return ret;
}

uint8 USART_GetTxFifoFreeSize(dtUSARTInstance Instance)
{
	uint8 ret = 0;
#if defined(MCU_G070) || defined(MCU_G071) || defined(STM32U0)
	switch(Instance)
	{
	case USART1:
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
		if(USART1Data.TxReadIndex > USART1Data.TxWriteIndex) ret += USART1Data.TxReadIndex - USART1Data.TxWriteIndex-1;
		else ret += USART1_TX_FIFO_SIZE - (USART1Data.TxWriteIndex - USART1Data.TxReadIndex);
#endif
		break;
	case USART2:
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
		if(USART2Data.TxReadIndex > USART2Data.TxWriteIndex) ret += USART2Data.TxReadIndex - USART2Data.TxWriteIndex-1;
		else ret += USART2_TX_FIFO_SIZE - (USART2Data.TxWriteIndex - USART2Data.TxReadIndex);
#endif
		break;
	case USART3:
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
		if(USART3Data.TxReadIndex > USART3Data.TxWriteIndex) ret += USART3Data.TxReadIndex - USART3Data.TxWriteIndex-1;
		else ret += USART3_TX_FIFO_SIZE - (USART3Data.TxWriteIndex - USART3Data.TxReadIndex);
#endif
		break;
	case USART4:
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
		if(USART4Data.TxReadIndex > USART4Data.TxWriteIndex) ret += USART4Data.TxReadIndex - USART4Data.TxWriteIndex-1;
		else ret += USART4_TX_FIFO_SIZE - (USART4Data.TxWriteIndex - USART4Data.TxReadIndex);
#endif
		break;
	}
#endif
	return ret;
}

uint8 USART_GetRxFifoFilledSize(dtUSARTInstance Instance)
{
	uint8 ret = 0;
#if defined(MCU_G070) || defined(MCU_G071)
	switch(Instance)
	{
	case USART1:
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
		if(USART1Data.RxWriteIndex >= USART1Data.RxReadIndex) ret = USART1Data.RxWriteIndex - USART1Data.RxReadIndex;
		else ret = USART1Data.RxReadIndex - USART1Data.RxWriteIndex;
#endif
		break;
	case USART2:
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
		if(USART2Data.RxWriteIndex >= USART2Data.RxReadIndex) ret = USART2Data.RxWriteIndex - USART2Data.RxReadIndex;
		else ret = USART2Data.RxReadIndex - USART2Data.RxWriteIndex;
#endif
		break;
	case USART3:
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
		if(USART3Data.RxWriteIndex >= USART3Data.RxReadIndex) ret = USART3Data.RxWriteIndex - USART3Data.RxReadIndex;
		else ret = USART3Data.RxReadIndex - USART3Data.RxWriteIndex;
#endif
		break;
	case USART4:
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
		if(USART4Data.RxWriteIndex >= USART4Data.RxReadIndex) ret = USART4Data.RxWriteIndex - USART4Data.RxReadIndex;
		else ret = USART4Data.RxReadIndex - USART4Data.RxWriteIndex;
#endif
		break;
	}
#endif
	return ret;
}

void USART_Disable(dtUSARTInstance Instance)
{
	dtUSART_CR1 TempCr1 = USART[Instance]->CR1;
	TempCr1.B.UE = 0;
	TempCr1.B.TE = 0;
	TempCr1.B.RE = 0;
	USART[Instance]->CR1 = TempCr1;
}

uint8 USART_Transmitting(dtUSARTInstance Instance)
{
	/* If TCFNFIE is set the module is transmitting */
#if defined(MCU_G070) || defined(MCU_G071) || defined(STM32U0)
    dtUSART_CR1 tCR1 = USART[Instance]->CR1;
    dtUSART_ISR tISR = USART[Instance]->ISR;
	return (tCR1.B.TXFNFIE != 0) || (tISR.B.TC == 0);
#elif defined(MCU_F446) || defined(MCU_F415)
	return (USART[Instance]->CR1.Fields.TXEIE != 0) || (USART[Instance]->SR.Fields.TC == 0);
#endif
}

#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
#if defined(MCU_G070) || defined(MCU_G071)
void USART2_IRQHandler(void)
#elif defined(STM32U0)
void USART2_LPUART2_IRQHandler(void)
#endif
{
    dtUSART_CR1 tCR1 = USART[USART2]->CR1;
    dtUSART_ISR tISR = USART[USART2]->ISR;
	if((tCR1.B.TXFNFIE != 0) && (tISR.B.TXFNF != 0))
	{
	    WriteTxData(USART2, USART2Data.txFifo[USART2Data.TxReadIndex++]);
	    USART2Data.TxReadIndex &= USART2_TX_FIFO_SIZE;

		/* If there is no more data to send disable the tx-empty interrupt */
		if(USART2Data.TxReadIndex == USART2Data.TxWriteIndex)
		{
			USART_CR1_CLEAR_BIT(USART2, CR1_BIT_TXFNFIE);
		}
	}
	if(tISR.B.RXFNE != 0)
	{
		USART2Data.rxFifo[USART2Data.RxWriteIndex++] = ReadRxData(USART2);
		USART2Data.RxWriteIndex &= USART2_RX_FIFO_SIZE;
	}
	if(tISR.B.ORE != 0)
    {
	    dtUSART_ICR tICR = {.U = 0};
	    tICR.B.ORECF = 1;
	    USART[USART2]->ICR = tICR;
    }
}

#endif

#if defined(MCU_G070) || defined(MCU_G071)
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
void USART3_USART4_LPUART1_IRQHandler(void)
{
	if((USART[2]->CR1.Fields.TXFNFIE != 0) && (USART[2]->ISR.Fields.TXFNF != 0))
	{
		USART[2]->TDR.TDR = USART3Data.TxFiFo[USART3Data.TxReadIndex++];
		USART3Data.TxReadIndex &= USART3_TX_FIFO_SIZE;

		/* If there is no more data to send disable the tx-empty interrupt */
		if(USART3Data.TxReadIndex == USART3Data.TxWriteIndex)
		{
			USART_CR1_CLEAR_BIT(USART3, CR1_BIT_TXFNFIE);
		}
	}
	if(USART[2]->ISR.Fields.RXFNE != 0)
	{
		USART3Data.RxFiFo[USART3Data.RxWriteIndex++] = USART[2]->RDR.Fields.RDR;
		USART3Data.RxWriteIndex &= USART3_RX_FIFO_SIZE;
	}
	if(USART[2]->ISR.Fields.ORE != 0) USART[2]->ICR.Fields.ORECF = 1;
}
#endif
#endif
#if defined(STM32U0)
#if defined(USART4_TX_FIFO_SIZE)  && defined(USART4_RX_FIFO_SIZE)
void USART4_IRQHandler(void)
{
    dtUSART_CR1 tCR1 = USART[USART4]->CR1;
    dtUSART_ISR tISR = USART[USART4]->ISR;
    if((tCR1.B.TXFNFIE != 0) && (tISR.B.TXFNF != 0))
    {
        WriteTxData(USART4, USART4Data.txFifo[USART4Data.TxReadIndex++]);
        USART4Data.TxReadIndex &= USART4_TX_FIFO_SIZE;

        /* If there is no more data to send disable the tx-empty interrupt */
        if(USART4Data.TxReadIndex == USART4Data.TxWriteIndex)
        {
            USART_CR1_CLEAR_BIT(USART4, CR1_BIT_TXFNFIE);
        }
    }
    if(tISR.B.RXFNE != 0)
    {
        USART4Data.rxFifo[USART4Data.RxWriteIndex++] = ReadRxData(USART4);
        USART4Data.RxWriteIndex &= USART4_RX_FIFO_SIZE;
    }
    if(tISR.B.ORE != 0)
    {
        dtUSART_ICR tICR = {.U = 0};
        tICR.B.ORECF = 1;
        USART[USART4]->ICR = tICR;
    }

}

static inline uint8 ReadRxData(dtUSARTInstance instance)
{
    dtUSART_RDR tRDR = USART[instance]->RDR;
    return tRDR.B.RDR;
}

static inline void WriteTxData(dtUSARTInstance instance, uint8 data)
{
    dtUSART_TDR tTDR = {.U = 0};
    tTDR.B.TDR = data;
    USART[instance]->TDR = tTDR;
}

#endif
#endif
#else
#warning "NO CPU IS DEFINED"
#endif

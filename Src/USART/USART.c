/*
 * USART.c
 *
 *  Created on: Nov 5, 2020
 *      Author: BodnarB
 */

#include "USART_Types.h"
#include "USART.h"
#include "RCC.h"
#include "NVIC.h"

#if defined(MCU_G070) || defined(MCU_G071)
/* Not every USART instances has the same features. USART1 and 2 have full functionality but USART 3 and 4 have only basic functionality */
static dtUSART *USART[4] = {(dtUSART*)0x40013800,
							(dtUSART*)0x40004400,
							(dtUSART*)0x40004800,
							(dtUSART*)0x40004C00};
#endif
#if defined(USART1_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
static dtUSART1Data USART1Data;
#endif
#if defined(USART2_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
static dtUSART2Data USART2Data;
#endif
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
static dtUSART3Data USART3Data;
#endif
#if defined(USART4_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
static dtUSART4Data USART4Data;
#endif

void USART_Init(dtUSARTInstance Instance, dtUSARTConfig Config);
void USART_Send(dtUSARTInstance Instance, uint8 *Data, uint8 DataSize);
uint8 USART_GetTxFifoFreeSize(dtUSARTInstance Instance);
uint8 USART_GetRxFifoFilledSize(dtUSARTInstance Instance);
uint8 USART_GetRxData(dtUSARTInstance Instance);

void USART_Init(dtUSARTInstance Instance, dtUSARTConfig Config)
{
#if defined(MCU_G070) || defined(MCU_G071)
	dtCR1 TempCR1 = {.Word = 0};

	/* Set 8 databits */
	TempCR1.Fields.M0 = 0;
	TempCR1.Fields.M1 = 0;

	/* Set parity */
	TempCR1.Fields.PCE = 0;
	if(Config.Parity != None)
	{
		TempCR1.Fields.PCE = 1;
		TempCR1.Fields.PS = 0;
		if(Config.Parity == Odd) TempCR1.Fields.PS = 1;
	}

	/* Set stopbits */
	USART[Instance]->CR2.Fields.STOP = Config.StopBits;

	uint32 USARTClock = RCC_GetClock(APB1_Peripheral);
	int32 ClockDiff = 0x7FFFFFFF;
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

			/* Calculate the difference between the original clock and the rounded divider*baud */
			int32 NewClockDiff = CalcBaseClock - CalculatedDiv*Config.Baud;
			if(NewClockDiff < 0) NewClockDiff *= (-1);

			/* Save the parameter if it is better approximation than the previous */
			if(NewClockDiff < ClockDiff)
			{
				ClockDiff = NewClockDiff;
				TempCR1.Fields.OVER8 = SamplingLooper;
				USART[Instance]->PRESC.PRESCALER = PrescLooper;
				USART[Instance]->BRR.BRR = CalculatedDiv;
			}
		}
		while(PrescLooper != 0);
	}

	/* Enable transmitter */
	TempCR1.Fields.TE = 1;

	/* Enable receiver */
	TempCR1.Fields.RE = 1;

	/* Enable USART */
	TempCR1.Fields.UE = 1;

	TempCR1.Fields.TXFNFIE = 0;
	TempCR1.Fields.RXFNEIE = 1;

	USART[Instance]->CR1 = TempCR1;

	uint8 dummy = USART[Instance]->RDR.Fields.RDR;

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
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
		NVIC_SetPriority(IRQ_USART3_4,0);
		NVIC_EnableIRQ(IRQ_USART3_4);
#endif
		break;
	}
#endif
}

void USART_Send(dtUSARTInstance Instance, uint8 *Data, uint8 DataSize)
{
#if defined(MCU_G070) || defined(MCU_G071)
	if(DataSize > 0)
	{
		/* Calculate the end of index of the TxClearIndex */
		uint8 *EndIndex = Data + DataSize;

		switch(Instance)
		{
		case USART1:
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
		{
			/* Fill the buffer with the data */
			while(Data < EndIndex)
			{
				USART3Data.TxFiFo[USART3Data.TxWriteIndex++] = *Data++;
				USART3Data.TxWriteIndex &= USART3_TX_FIFO_SIZE;
			}
			USART[Instance]->CR1.Fields.TXFNFIE = 1;
		}
#endif
			break;
		case USART2:
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
		{
			/* Fill the buffer with the data */
			while(Data < EndIndex)
			{
				USART3Data.TxFiFo[USART3Data.TxWriteIndex++] = *Data++;
				USART3Data.TxWriteIndex &= USART3_TX_FIFO_SIZE;
			}
			USART[Instance]->CR1.Fields.TXFNFIE = 1;
		}
#endif
			break;
		case USART3:
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
		{
			/* Fill the buffer with the data */
			while(Data < EndIndex)
			{
				USART3Data.TxFiFo[USART3Data.TxWriteIndex++] = *Data++;
				USART3Data.TxWriteIndex &= USART3_TX_FIFO_SIZE;
			}
			USART[Instance]->CR1.Fields.TXFNFIE = 1;
		}
#endif
			break;
		case USART4:
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
		{
			/* Fill the buffer with the data */
			while(Data < EndIndex)
			{
				USART3Data.TxFiFo[USART3Data.TxWriteIndex++] = *Data++;
				USART3Data.TxWriteIndex &= USART3_TX_FIFO_SIZE;
			}
			USART[Instance]->CR1.Fields.TXFNFIE = 1;
		}
#endif
			break;
		}
	}
#endif
}

uint8 USART_GetRxData(dtUSARTInstance Instance)
{
	uint8 ret = 0;
#if defined(MCU_G070) || defined(MCU_G071)
	switch(Instance)
	{
	case USART1:
#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
		if(USART1Data.RxReadIndex != USART1Data.RxWriteIndex)
		{
			ret = USART1Data.RxFiFo[USART1Data.RxReadIndex++];
			USART1Data.RxReadIndex &= USART1_RX_FIFO_SIZE;
		}
#endif
		break;
	case USART2:
#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
		if(USART2Data.RxReadIndex != USART2Data.RxWriteIndex)
		{
			ret = USART2Data.RxFiFo[USART2Data.RxReadIndex++];
			USART2Data.RxReadIndex &= USART2_RX_FIFO_SIZE;
		}
#endif
		break;
	case USART3:
#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
		if(USART3Data.RxReadIndex != USART3Data.RxWriteIndex)
		{
			ret = USART3Data.RxFiFo[USART3Data.RxReadIndex++];
			USART3Data.RxReadIndex &= USART3_RX_FIFO_SIZE;
		}
#endif
		break;
	case USART4:
#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
		if(USART4Data.RxReadIndex != USART4Data.RxWriteIndex)
		{
			ret = USART4Data.RxFiFo[USART4Data.RxReadIndex++];
			USART4Data.RxReadIndex &= USART4_RX_FIFO_SIZE;
		}
#endif
		break;
	}
#endif
	return ret;
}

uint8 USART_GetTxFifoFreeSize(dtUSARTInstance Instance)
{
	uint8 ret = 0;
#if defined(MCU_G070) || defined(MCU_G071)
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

#if defined(MCU_G070) || defined(MCU_G071)
void USART3_USART4_LPUART1_IRQHandler(void)
{
	if((USART[2]->CR1.Fields.TXFNFIE != 0) && (USART[2]->ISR.Fields.TXFNF != 0))
	{
		USART[2]->TDR.TDR = USART3Data.TxFiFo[USART3Data.TxReadIndex++];
		USART3Data.TxReadIndex &= USART3_TX_FIFO_SIZE;

		/* If there is no more data to send disable the tx-empty interrupt */
		if(USART3Data.TxReadIndex == USART3Data.TxWriteIndex) USART[2]->CR1.Fields.TXFNFIE = 0;
	}
	if(USART[2]->ISR.Fields.RXFNE != 0)
	{
		USART3Data.RxFiFo[USART3Data.RxWriteIndex++] = USART[2]->RDR.Fields.RDR;
		USART3Data.RxWriteIndex &= USART3_RX_FIFO_SIZE;
	}
}
#endif

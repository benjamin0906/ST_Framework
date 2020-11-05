/*
 * USART.c
 *
 *  Created on: Nov 5, 2020
 *      Author: BodnarB
 */

#include "USART_Types.h"
#include "USART.h"
#include "RCC.h"

static dtUSART *USART[4] = {(dtUSART*)0x40013800,
							(dtUSART*)0x40004400,
							(dtUSART*)0x40004800,
							(dtUSART*)0x40004C00};



void USART_Init(dtUSARTInstance Instance, dtUSARTConfig Config)
{
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

	USART[Instance]->CR1 = TempCR1;

	uint8 asd = 0;
	while(1)
	{
		while(USART[Instance]->ISR.TXFNF == 0);
		uint16 i;
		for(i = 0; i< 10000; i++);
		USART[Instance]->TDR.TDR = asd++;
	}

}

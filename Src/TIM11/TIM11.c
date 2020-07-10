/*
 * TIM11.c
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#include "TIM11_Types.h"

static dtTIM11 *const TIM11 = (dtTIM11*)(0x40014800);

static void (*IntHandler)(void);

void TIM11_Init(uint16 Prescaler, uint16 Ar, void (*handler)(void));

void TIM11_Init(uint16 Prescaler, uint16 Ar, void (*handler)(void))
{
	TIM11->CR.Word = 0;

	if(handler != 0)
	{
		IntHandler = handler;
		TIM11->DIER.Fields.UIE = 1;
	}

	TIM11->ARR = Ar;
	TIM11->PSC = Prescaler;
	TIM11->CR.Fields.ARPE = 1;
	TIM11->CR.Fields.CEN = 1;
}

void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
	TIM11->SR.Fields.UIF = 0;
	if(IntHandler != 0) IntHandler();
}

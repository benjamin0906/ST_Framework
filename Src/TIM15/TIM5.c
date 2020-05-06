/*
 * TIM5.c
 *
 *  Created on: 5 May 2020
 *      Author: Bodnár Benjamin
 */

#include "TIM15_Types.h"
#include "NVIC.h"

static dtTIM15 *const TIM15 = (dtTIM15*)(0x40014000);

void TIM15_Init(void)
{
	TIM15->CR1.Field.ARPE = 1;
	TIM15->CR1.Field.URS = 1;
	TIM15->CR1.Field.UDIS = 0;
	TIM15->CR1.Field.OPM = 0;

	TIM15->DIER.Field.UIE = 1;


	TIM15->PSC.Field.PSC = 9999;

	TIM15->ARR.Field.ARR = 1000;

	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn,2);
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);

	TIM15->CCMR1.OC_mode_Field.CC2S = 0;
	//TIM15->CCMR1.OC_mode_Field.OC1M_1 =

	TIM15->CR1.Field.CEN = 1;
}

void TIM1_BRK_TIM15_IRQHandler(void)
{
	TIM15->SR.Field.UIF = 0;
	Blink();
}

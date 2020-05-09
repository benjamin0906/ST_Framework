/*
 * TIM5.c
 *
 *  Created on: 5 May 2020
 *      Author: Bodnár Benjamin
 */

#include "TIM15_Types.h"
#include "TIM15.h"
#include "NVIC.h"

static dtTIM15 *const TIM15 = (dtTIM15*)(0x40014000);

void TIM15_Init(void)
{
	TIM15->CR1.Field.ARPE = 1;
	TIM15->CR1.Field.URS = 1;
	TIM15->CR1.Field.UDIS = 0;
	TIM15->CR1.Field.OPM = 0;

	TIM15->DIER.Field.UIE = 1;


	TIM15->PSC.Field.PSC = 0;

	TIM15->ARR.Field.ARR = 64;

	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn,2);
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);

	TIM15->CCMR1.OC_mode_Field.CC2S = 0;
	TIM15->CCMR1.OC_mode_Field.OC1M_2 = 0;
	TIM15->CCMR1.OC_mode_Field.OC1M_1 = 6;

	TIM15->CCMR1.OC_mode_Field.OC2M_2 = 0;
	TIM15->CCMR1.OC_mode_Field.OC2M_1 = 6;

	TIM15->CCMR1.OC_mode_Field.OC1PE = 1;
	TIM15->CCMR1.OC_mode_Field.OC2PE = 1;
	TIM15->CCMR1.OC_mode_Field.CC1S = 0;

	TIM15->BDTR.Field.MOE = 1;

	TIM15->CCER.Field.CC2E = 1;
	TIM15->CCER.Field.CC1E = 1;

	TIM15->CCR1.Field.CCR1 = 200;
	TIM15->CCR2.Field.CCR2 = 600;

	TIM15->CR1.Field.CEN = 1;
}

//void TIM15_SetPeriod(dtTIM15_Ch Ch, );

void TIM1_BRK_TIM15_IRQHandler(void)
{
	TIM15->SR.Field.UIF = 0;

}

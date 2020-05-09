/*
 * TIM2.c
 *
 *  Created on: May 6, 2020
 *      Author: Bodnár Benjamin
 */

#include "TIM2_Types.h"
#include "NVIC.h"
#include "RCC.h"

static dtTIM2 *const TIM2 = (dtTIM2*)(0x40000000);
static void (*InterruptFunction)(void);

void TIM2_Init(void (*PeriodFunction)(void));
uint32 TIM2_SetPeriod(uint32 Freq);
void TIM2_SetDuty(uint32 duty, uint8 Ch);

void TIM2_Init(void (*PeriodFunction)(void))
{
	TIM2->CR1.Field.UIFREMAP = 0;
	TIM2->CR1.Field.CMS = 0;
	TIM2->CR1.Field.ARPE = 1;
	TIM2->CR1.Field.DIR = 0;
	TIM2->CR1.Field.OPM = 0;
	TIM2->CR1.Field.URS = 1;
	TIM2->CR1.Field.UDIS = 0;

	TIM2->DIER.Field.UIE = 1;
	NVIC_SetPriority(TIM2_IRQn,2);
	NVIC_EnableIRQ(TIM2_IRQn);

	TIM2->PSC.Field.PSC = 0;

	TIM2->ARR.Field.ARR = 100000;

	TIM2->CNT.Field.CNT = 0;

	dtCCMR1 temp = {.Word = 0};

	temp.OC_mode_Field.CC2S = 0;
		temp.OC_mode_Field.CC1S = 0;

		temp.OC_mode_Field.OC1M_1 = 6;
		temp.OC_mode_Field.OC1M_2 = 0;

		temp.OC_mode_Field.OC2M_1 = 6;
		temp.OC_mode_Field.OC2M_2 = 0;

		temp.OC_mode_Field.OC1PE = 1;
		temp.OC_mode_Field.OC2PE = 1;

	TIM2->CCMR1.OC_mode_Field.CC2S = 0;
	TIM2->CCMR1.OC_mode_Field.CC1S = 0;

	TIM2->CCMR1.OC_mode_Field.OC1M_1 = 6;
	TIM2->CCMR1.OC_mode_Field.OC1M_2 = 0;

	TIM2->CCMR1.OC_mode_Field.OC2M_1 = 6;
	TIM2->CCMR1.OC_mode_Field.OC2M_2 = 0;

	TIM2->CCMR1.OC_mode_Field.OC1PE = 1;
	TIM2->CCMR1.OC_mode_Field.OC2PE = 1;

	TIM2->CCMR1 = temp;

	TIM2->CCER.Field.CC1E = 1;
	TIM2->CCER.Field.CC2E = 1;

	TIM2->CCR1.Field.CCRx = 1000;
	TIM2->CCR2.Field.CCRx = 5000;

	//TIM2->


	TIM2->CR1.Field.CEN = 1;

	//if(PeriodFunction != 0) InterruptFunction = PeriodFunction;

	TIM2->EGR.Field.UG = 1;
}

uint32 TIM2_SetPeriod(uint32 Freq)
{
	float32 ArrReg = (float32) ClockFreq/Freq;
	TIM2->ARR.Field.ARR = (uint32)ArrReg;
	ArrReg -= (uint32)ArrReg;
	if(ArrReg >= 0.5) TIM2->ARR.Field.ARR ++;
	TIM2->CR1.Field.CEN = 1;
	TIM2->EGR.Field.UG = 1;

	return TIM2->ARR.Field.ARR;
}

void TIM2_GetSampeNum(void)
{
	return TIM2->ARR.Field.ARR;
}

void TIM2_SetDuty(uint32 duty, uint8 Ch)
{
	if(Ch != 0)
	{
		TIM2->CCR1.Field.CCRx = duty;
	}
	else
	{
		TIM2->CCR2.Field.CCRx = duty;
	}
}

void TIM2_IRQHandler(void)
{
	TIM2->SR.Field.UIF = 0;
	Blink();
	//InterruptFunction();
}

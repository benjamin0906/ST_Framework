/*
 * TIM3.c
 *
 *  Created on: 2020. júl. 15.
 *      Author: BodnarB
 */

#include "../GPT_TIM_Types.h"
#include "TIM3.h"

static dtGPT1 *const TIM3 = (dtGPT1*)(0x40000400);

void TIM3_Init(dtGPT1Config Config);
void TIM3_SetValue(dtGPT1SetTypes Type, uint32 Value);

void TIM3_Init(dtGPT1Config Config)
{
	TIM3->CR1.Word = 0;
	TIM3->CR1.Fields.CMS = 0;
	TIM3->CR1.Fields.ARPE = 1;
	TIM3->CR1.Fields.DIR = Config.Direction;

	TIM3->ARR.Word = Config.ARR;
	TIM3->PSC.Word = Config.Presc;

	switch(Config.Mode)
	{
	case Timer:
		break;
	case Oc1:
		TIM3->CCMR1.Out_Fields.CC1S = 0;
		TIM3->CCMR1.Out_Fields.OC1PE = 1;
		TIM3->CCMR1.Out_Fields.OC1M = Config.OCMode;
		TIM3->CCER.Fields.CC1P = Config.OcPolarity;
		TIM3->CCER.Fields.CC1E = 1;
		break;
	case Oc2:
		TIM3->CCMR1.Out_Fields.CC2S = 0;
		TIM3->CCMR1.Out_Fields.OC2PE = 1;
		TIM3->CCMR1.Out_Fields.OC2M = Config.OCMode;
		TIM3->CCER.Fields.CC2P = Config.OcPolarity;
		TIM3->CCER.Fields.CC2E = 1;
		break;
	case Oc3:
		TIM3->CCMR2.Out_Fields.CC3S = 0;
		TIM3->CCMR2.Out_Fields.OC3PE = 1;
		TIM3->CCMR2.Out_Fields.OC3M = Config.OCMode;
		TIM3->CCER.Fields.CC3P = Config.OcPolarity;
		TIM3->CCER.Fields.CC3E = 1;
		break;
	case Oc4:
		TIM3->CCMR2.Out_Fields.CC4S = 0;
		TIM3->CCMR2.Out_Fields.OC4PE = 1;
		TIM3->CCMR2.Out_Fields.OC4M = Config.OCMode;
		TIM3->CCER.Fields.CC4P = Config.OcPolarity;
		TIM3->CCER.Fields.CC4E = 1;
		break;
	}
	TIM3->CR1.Fields.CEN = 1;
}

void TIM3_SetValue(dtGPT1SetTypes Type, uint32 Value)
{
	switch(Type)
	{
	case GPT1_Prescaler:
		TIM3->PSC.Word = Value;
		break;
	case GPT1_AutoReload:
		TIM3->ARR.Word = Value;
		break;
	case GPT1_Oc1:
		TIM3->CCR1.Word = Value;
		break;
	case GPT1_Oc2:
		TIM3->CCR2.Word = Value;
		break;
	case GPT1_Oc3:
		TIM3->CCR3.Word = Value;
		break;
	case GPT1_Oc4:
		TIM3->CCR4.Word = Value;
		break;
	}
}

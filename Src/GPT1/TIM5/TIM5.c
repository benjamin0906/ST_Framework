/*
 * TIM5.c
 *
 *  Created on: 2020. júl. 15.
 *      Author: BodnarB
 */

#include "../GPT_TIM_Types.h"
#include "TIM5.h"

static dtGPT1 *const TIM5 = (dtGPT1*)(0x40000C00);

void TIM5_Init(dtGPT1Config Config)
{
	TIM5->CR1.Word = 0;
	TIM5->CR1.Fields.CMS = 0;
	TIM5->CR1.Fields.ARPE = 1;
	TIM5->CR1.Fields.DIR = Config.Direction;

	TIM5->ARR.Word = Config.ARR;
	TIM5->PSC.Word = Config.Presc;

	switch(Config.Mode)
	{
	case Timer:
		break;
	case Oc1:
		TIM5->CCMR1.Out_Fields.CC1S = 0;
		TIM5->CCMR1.Out_Fields.OC1PE = 1;
		TIM5->CCMR1.Out_Fields.OC1M = Config.OCMode;
		TIM5->CCER.Fields.CC1P = Config.OcPolarity;
		TIM5->CCER.Fields.CC1E = 1;
		break;
	case Oc2:
		TIM5->CCMR1.Out_Fields.CC2S = 0;
		TIM5->CCMR1.Out_Fields.OC2PE = 1;
		TIM5->CCMR1.Out_Fields.OC2M = Config.OCMode;
		TIM5->CCER.Fields.CC2P = Config.OcPolarity;
		TIM5->CCER.Fields.CC2E = 1;
		break;
	case Oc3:
		TIM5->CCMR2.Out_Fields.CC3S = 0;
		TIM5->CCMR2.Out_Fields.OC3PE = 1;
		TIM5->CCMR2.Out_Fields.OC3M = Config.OCMode;
		TIM5->CCER.Fields.CC3P = Config.OcPolarity;
		TIM5->CCER.Fields.CC3E = 1;
		break;
	case Oc4:
		TIM5->CCMR2.Out_Fields.CC4S = 0;
		TIM5->CCMR2.Out_Fields.OC4PE = 1;
		TIM5->CCMR2.Out_Fields.OC4M = Config.OCMode;
		TIM5->CCER.Fields.CC4P = Config.OcPolarity;
		TIM5->CCER.Fields.CC4E = 1;
		break;
	}
	TIM5->CR1.Fields.CEN = 1;
}

void TIM5_SetValue(dtGPT1SetTypes Type, uint32 Value)
{
	switch(Type)
	{
	case GPT1_Prescaler:
		TIM5->PSC.Word = Value;
		break;
	case GPT1_AutoReload:
		TIM5->ARR.Word = Value;
		break;
	case GPT1_Oc1:
		TIM5->CCR1.Word = Value;
		break;
	case GPT1_Oc2:
		TIM5->CCR2.Word = Value;
		break;
	case GPT1_Oc3:
		TIM5->CCR3.Word = Value;
		break;
	case GPT1_Oc4:
		TIM5->CCR4.Word = Value;
		break;
	}
}

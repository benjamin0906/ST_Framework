/*
 * TIM2_MEM.c
 *
 *  Created on: 2020. júl. 15.
 *      Author: BodnarB
 */
#define TIM2
#include "../GPT_TIM_Types.h"
#include "TIM2.h"

static dtGPT1 *const TIM2_MEM = (dtGPT1*)(0x40000000);

void TIM2_Init(dtGPT1Config Config);
void TIM2_MEM_SetValue(dtGPT1SetTypes Type, uint32 Value);

void TIM2_Init(dtGPT1Config Config)
{
	TIM2_MEM->CR1.Word = 0;
	TIM2_MEM->CR1.Fields.CMS = 0;
	TIM2_MEM->CR1.Fields.ARPE = 1;
	TIM2_MEM->CR1.Fields.DIR = Config.Direction;

	TIM2_MEM->ARR.Word = Config.ARR;
	TIM2_MEM->PSC.Word = Config.Presc;

	switch(Config.Mode)
	{
	case Timer:
		break;
	case Oc1:
		TIM2_MEM->CCMR1.Out_Fields.CC1S = 0;
		TIM2_MEM->CCMR1.Out_Fields.OC1PE = 1;
		TIM2_MEM->CCMR1.Out_Fields.OC1M = Config.OCMode;
		TIM2_MEM->CCER.Fields.CC1P = Config.OcPolarity;
		TIM2_MEM->CCER.Fields.CC1E = 1;
		break;
	case Oc2:
		TIM2_MEM->CCMR1.Out_Fields.CC2S = 0;
		TIM2_MEM->CCMR1.Out_Fields.OC2PE = 1;
		TIM2_MEM->CCMR1.Out_Fields.OC2M = Config.OCMode;
		TIM2_MEM->CCER.Fields.CC2P = Config.OcPolarity;
		TIM2_MEM->CCER.Fields.CC2E = 1;
		break;
	case Oc3:
		TIM2_MEM->CCMR2.Out_Fields.CC3S = 0;
		TIM2_MEM->CCMR2.Out_Fields.OC3PE = 1;
		TIM2_MEM->CCMR2.Out_Fields.OC3M = Config.OCMode;
		TIM2_MEM->CCER.Fields.CC3P = Config.OcPolarity;
		TIM2_MEM->CCER.Fields.CC3E = 1;
		break;
	case Oc4:
		TIM2_MEM->CCMR2.Out_Fields.CC4S = 0;
		TIM2_MEM->CCMR2.Out_Fields.OC4PE = 1;
		TIM2_MEM->CCMR2.Out_Fields.OC4M = Config.OCMode;
		TIM2_MEM->CCER.Fields.CC4P = Config.OcPolarity;
		TIM2_MEM->CCER.Fields.CC4E = 1;
		break;
	}
	TIM2_MEM->CR1.Fields.CEN = 1;
}

void TIM2_MEM_SetValue(dtGPT1SetTypes Type, uint32 Value)
{
	switch(Type)
	{
	case GPT1_Prescaler:
		TIM2_MEM->PSC.Word = Value;
		break;
	case GPT1_AutoReload:
		TIM2_MEM->ARR.Word = Value;
		break;
	case GPT1_Oc1:
		TIM2_MEM->CCR1.Word = Value;
		break;
	case GPT1_Oc2:
		TIM2_MEM->CCR2.Word = Value;
		break;
	case GPT1_Oc3:
		TIM2_MEM->CCR3.Word = Value;
		break;
	case GPT1_Oc4:
		TIM2_MEM->CCR4.Word = Value;
		break;
	}
}

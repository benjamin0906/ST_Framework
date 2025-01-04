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
	dtCR1 tCR1 = {.Word = 0};
	dtARR tARR = {.Word = 0};
	dtPSC tPSC = {.Word = 0};
	TIM3->CR1.Word = 0;

	tCR1.Word = 0;
	tCR1.Fields.CMS = 0;
	tCR1.Fields.ARPE = 1;
	tCR1.Fields.DIR = Config.Direction;
	tCR1.Fields.CEN = 1;

	tARR.Word = Config.ARR;
	tPSC.Word = Config.Presc;

	switch(Config.Mode)
	{
	case Timer:
		break;
	case Oc1:
	{
		dtCCMR1 tCCMR1 = {.Word = 0};
		dtCCER tCCER = {.Word = 0};
		tCCMR1.Out_Fields.CC1S = 0;
		tCCMR1.Out_Fields.OC1PE = 1;
		tCCMR1.Out_Fields.OC1M = Config.OCMode;
		tCCER.Fields.CC1P = Config.OcPolarity;
		tCCER.Fields.CC1E = 1;
		TIM3->CCMR1 = tCCMR1;
		TIM3->CCER = tCCER;
	}

		break;
	case Oc2:
	{
		dtCCMR1 tCCMR1 = {.Word = 0};
		dtCCER tCCER = {.Word = 0};
		tCCMR1.Out_Fields.CC2S = 0;
		tCCMR1.Out_Fields.OC2PE = 1;
		tCCMR1.Out_Fields.OC2M = Config.OCMode;
		tCCER.Fields.CC2P = Config.OcPolarity;
		tCCER.Fields.CC2E = 1;
		TIM3->CCMR1 = tCCMR1;
		TIM3->CCER = tCCER;
	}
		break;
	case Oc3:
	{
		dtCCMR2 tCCMR2 = {.Word = 0};
		dtCCER tCCER = {.Word = 0};
		tCCMR2.Out_Fields.CC3S = 0;
		tCCMR2.Out_Fields.OC3PE = 1;
		tCCMR2.Out_Fields.OC3M = Config.OCMode;
		tCCER.Fields.CC3P = Config.OcPolarity;
		tCCER.Fields.CC3E = 1;
		TIM3->CCMR2 = tCCMR2;
		TIM3->CCER = tCCER;
		break;
	}
	case Oc4:
	{
		dtCCMR2 tCCMR2 = {.Word = 0};
		dtCCER tCCER = {.Word = 0};
		tCCMR2.Out_Fields.CC4S = 0;
		tCCMR2.Out_Fields.OC4PE = 1;
		tCCMR2.Out_Fields.OC4M = Config.OCMode;
		tCCER.Fields.CC4P = Config.OcPolarity;
		tCCER.Fields.CC4E = 1;
		TIM3->CCMR2 = tCCMR2;
		TIM3->CCER = tCCER;
		break;
	}
	}
	TIM3->ARR = tARR;
	TIM3->PSC = tPSC;
	TIM3->CR1 = tCR1;
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

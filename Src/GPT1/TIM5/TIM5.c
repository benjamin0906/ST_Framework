/*
 * TIM5.c
 *
 *  Created on: 2020. júl. 15.
 *      Author: BodnarB
 */

#include "../GPT_TIM_Types.h"
#include "../GPT_TIM_Ext_Types.h"

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
		break;
	case Oc2:
		TIM5->CCMR1.Out_Fields.CC2S = 0;
		TIM5->CCMR1.Out_Fields.OC2PE = 1;
		TIM5->CCMR1.Out_Fields.OC2M = Config.OCMode;
		break;
	case Oc3:
		TIM5->CCMR2.Out_Fields.CC3S = 0;
		TIM5->CCMR2.Out_Fields.OC3PE = 1;
		TIM5->CCMR2.Out_Fields.OC3M = Config.OCMode;
		break;
	case Oc4:
		TIM5->CCMR2.Out_Fields.CC4S = 0;
		TIM5->CCMR2.Out_Fields.OC4PE = 1;
		TIM5->CCMR2.Out_Fields.OC4M = Config.OCMode;
		break;
	}
}

void TIM5_SetCompare(uint8 Channel, uint32 Value)
{
	switch(Channel)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}

/*
 * TIM3.c
 *
 *  Created on: 2020. júl. 15.
 *      Author: BodnarB
 */

#include "../GPT_TIM_Types.h"
#include "../GPT_TIM_Ext_Types.h"

static dtGPT1 *const TIM3 = (dtGPT1*)(0x40000400);

void TIM3_Init(dtGPT1Config Config)
{
	TIM3->CR1.Word = 0;
	TIM3->CR1.Fields.CMS = 0;
	TIM3->CR1.Fields.ARPE = 1;
	TIM3->CR1.Fields.DIR = Config.Direction;

	TIM3->ARR = Config.ARR;
	TIM3->PSC = Config.Presc;

	switch(Config.Mode)
	{
	case Timer:
		break;
	case Oc1:
		TIM3->CCMR1.Out_Fields.CC1S = 0;
		break;
	case Oc2:
		TIM3->CCMR1.Out_Fields.CC2S = 0;
		break;
	case Oc3:
		TIM3->CCMR2.Out_Fields.CC3S = 0;
		break;
	case Oc4:
		TIM3->CCMR2.Out_Fields.CC4S = 0;
		break;
	}
}

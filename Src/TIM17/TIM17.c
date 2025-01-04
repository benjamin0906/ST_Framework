/*
 * TIM5.c
 *
 *  Created on: 5 May 2020
 *      Author: Bodnár Benjamin
 */

#include "TIM17.h"
#include "NVIC.h"
#include "TIM17_Types.h"

static dtTIM17 *const TIM17 = (dtTIM17*)(0x40014800);

void TIM17_Init(const dtTim17Cfg *const cfg);
void TIM17_SetValue(dtTIM17SetTypes Type, uint16 Value);

void TIM17_Init(const dtTim17Cfg *const cfg)
{
	dtCR1 tCR1 = {.Word = 0};
	dtCCMR1 tCCMR1 = {.Word = 0};
	dtPSC tPSC = {.Word = 0};
	dtARR tARR = {.Word = 0};
	dtCCER tCCER = {.Word = 0};
	dtBDTR tBDTR = {.Word = 0};

	tCR1.Field.ARPE = 1;
	tCR1.Field.URS = 0;
	tCR1.Field.UDIS = 0;
	tCR1.Field.OPM = 0;
	tCR1.Field.CEN = 1;

	tPSC.Field.PSC = cfg->Presc;
	tARR.Field.ARR = cfg->ARR;

	tCCMR1.OC_mode_Field.CC1S = 0;
	tCCMR1.OC_mode_Field.OC1M_1 = cfg->OCMode;
	tCCER.Field.CC1E = cfg->CC1PEnable;
	tCCER.Field.CC1NE = cfg->CC1NEnable;
	tCCER.Field.CC1NP = cfg->CC1NActiveLow;
	tCCER.Field.CC1P = cfg->CC1PActiveLow;

	tBDTR.Field.MOE = 1;

	TIM17->CR1.Word = 0;
	TIM17->BDTR = tBDTR;
	TIM17->CCER = tCCER;
	TIM17->CCMR1 = tCCMR1;
	TIM17->PSC = tPSC;
	TIM17->ARR = tARR;
	TIM17->CR1 = tCR1;
}

void TIM17_SetValue(dtTIM17SetTypes Type, uint16 Value)
{
    switch(Type)
    {
    case TIM17_Prescaler:
    {
    	dtARR tARR = {.Word = 0};
    	tARR.Field.ARR = Value;
    	TIM17->ARR = tARR;
    }
    	break;
    case TIM17_AutoReload:
    {
    	dtPSC tPSC = {.Word = 0};
    	tPSC.Field.PSC = Value;
    	TIM17->PSC = tPSC;
    }
    	break;
    case TIM17_Cmp:
    {
    	dtCCR1 tCCR = {.Word = 0};
    	tCCR.Field.CCR1 = Value;
    	TIM17->CCR1 = tCCR;
    }
    	break;
    }
}

void TIM17_IRQHandler(void)
{
	TIM17->SR.Field.UIF = 0;

}

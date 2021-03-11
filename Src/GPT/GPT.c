/*
 * GPT.h
 *
 *  Created on: 2021. febr. 25.
 *      Author: Benjamin
 */

#include "GPT_Types.h"
#include "GPT.h"

static dtGPT *const TIM15 = (dtGPT*)(0x40014000);
static dtGPT *const TIM16 = (dtGPT*)(0x40014400);
static dtGPT *const TIM17 = (dtGPT*)(0x40014800);

void GPT_Init(dtGPTInstance Instance, dtGPTConfig);
void GPT_Start(dtGPTInstance Instance);
void GPT_Stop(dtGPTInstance Instance);
void GPT_SetCompare(dtGPTInstance Instance, uint16 CompareValue);
uint16 GPT_GetCntr(dtGPTInstance Instance);

void GPT_Init(dtGPTInstance Instance, dtGPTConfig Config)
{
	dtGPT	*GPT = 0;
	dtCR1 	TempCR1 = {.Word = 0};
	dtCR2 	TempCR2 = {.Word = 0};
	dtCCMR1	TempCCMR1 = {.Word = 0};
	dtCCER	TempCCER = {.Word = 0};
	dtBDTR	TempBDTR = {.Word = 0};

	switch(Instance)
	{
	case Instance_TIM15:
		GPT = TIM15;
		break;
	case Instance_TIM16:
		GPT = TIM16;
		break;
	case Instance_TIM17:
		GPT = TIM17;
		break;
	}

	GPT->CR1.Word = 0;

	GPT->PSC.Field.PSC = Config.PrescalerValue;
	GPT->ARR.Field.ARR = Config.AutoReloadValue;

	TempCR1.Field.ARPE = Config.AutoRealoadPre;
	TempCR1.Field.CKD = Config.ClockDiv;

	TempCCMR1.OC_mode_Field.OC1M_1 = Config.OutputCompareMode&0x7;
	TempCCMR1.OC_mode_Field.OC1M_2 = Config.OutputCompareMode>>3;
	TempCCMR1.OC_mode_Field.OC1PE = 1;
	TempCCMR1.OC_mode_Field.CC1S = 0;

	TempCCER.Field.CC1E = Config.Ch1Enable;
	TempCCER.Field.CC1P = Config.Ch1ActiveState;
	TempCCER.Field.CC1NE = Config.Ch1NEnable;
	TempCCER.Field.CC1NP = Config.Ch1NActiveState;

	TempBDTR.Field.MOE = 1;

	GPT->BDTR = TempBDTR;
	GPT->CCER = TempCCER;
	GPT->CCMR1 = TempCCMR1;
	GPT->CR2 = TempCR2;
	GPT->CR1 = TempCR1;
}

void GPT_Start(dtGPTInstance Instance)
{
	switch(Instance)
	{
	case Instance_TIM15:
		TIM15->CNT.Field.CNT = 0;
		TIM15->CR1.Word |= 1;
		break;
	case Instance_TIM16:
		TIM16->CNT.Field.CNT = 0;
		TIM16->CR1.Word |= 1;
		break;
	case Instance_TIM17:
		TIM17->CNT.Field.CNT = 0;
		TIM17->CR1.Word |= 1;
		break;
	}
}

void GPT_Stop(dtGPTInstance Instance)
{
	switch(Instance)
	{
	case Instance_TIM15:
		TIM15->CR1.Word &= 0xFFFFFFFE;
		break;
	case Instance_TIM16:
		TIM16->CR1.Word &= 0xFFFFFFFE;
		break;
	case Instance_TIM17:
		TIM17->CR1.Word &= 0xFFFFFFFE;
		break;
	}
}

void GPT_SetCompare(dtGPTInstance Instance, uint16 CompareValue)
{
	switch(Instance)
	{
	case Instance_TIM15:
		TIM15->CCR1.Field.CCR1 = CompareValue;
		break;
	case Instance_TIM16:
		TIM16->CCR1.Field.CCR1 = CompareValue;
		break;
	case Instance_TIM17:
		TIM17->CCR1.Field.CCR1 = CompareValue;
		break;
	}
}

uint16 GPT_GetCntr(dtGPTInstance Instance)
{
	uint16 ret = 0;
	switch(Instance)
	{
	case Instance_TIM15:
		ret = TIM15->CNT.Field.CNT;
		break;
	case Instance_TIM16:
		ret = TIM16->CNT.Field.CNT;
		break;
	case Instance_TIM17:
		ret = TIM17->CNT.Field.CNT;
		break;
	}
	return ret;
}

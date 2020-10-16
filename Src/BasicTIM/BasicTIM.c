/*
 * BasicTIM.c
 *
 *  Created on: 3 May 2020
 *      Author: Bodnár Benjamin
 */

#include "BasicTIM_Types.h"
#include "BasicTIM.h"
#include "NVIC.h"

#if defined(MCU_F410)
#ifndef MODULE_TEST
static dtBasicTIM *const BTIMs[1] = {	(dtBasicTIM*)(0x40001000)};//TIM6
#else
#include "TestEnv.h"
static dtBasicTIM *const BTIMs[1] = {	(dtBasicTIM*)(&TestBasicTIM6)};//TIM6
#endif
static void (*IrqPtrs[1])(void);
#elif defined(MCU_G070) || defined(MCU_L433)
#ifndef MODULE_TEST
static dtBasicTIM *const BTIMs[2] = {	(dtBasicTIM*)(0x40001000),//TIM6
									(dtBasicTIM*)(0x40001400),//TIM7
};
#else
#include "TestEnv.h"
static dtBasicTIM *const BTIMs[2] = {	(dtBasicTIM*)(&TestBasicTIM6), (dtBasicTIM*)(&TestBasicTIM7)};//TIM6
#endif
static void (*IrqPtrs[2])(void);
#endif

void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void));

void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void))
{
	BTIMs[Id]->CR1.Fields.ARPE = Config.ARPreload;
	BTIMs[Id]->CR1.Fields.OPM = Config.OnePulse;
	BTIMs[Id]->CR1.Fields.URS = Config.UpdateSource;
	BTIMs[Id]->CR1.Fields.UDIS = Config.UpdateDisable;
	BTIMs[Id]->PSC.Fields.PSC = Config.Prescaler;
	BTIMs[Id]->ARR.Fields.ARR = Config.AutoReload;

	if(IrqPtr != 0)
	{
		BTIMs[Id]->DIER.Fields.UIE = 1;
		IrqPtrs[Id] = IrqPtr;
#if  defined(MCU_F446) || defined(MCU_F410)
	NVIC_SetPriority(IRQ_TIM6_DAC,1);
	NVIC_EnableIRQ(IRQ_TIM6_DAC);
#elif defined(MCU_G070) || defined(MCU_L433)
	if(Id == TIM6)
	{
#if defined(MCU_L433)
		NVIC_SetPriority(IRQ_TIM6_DACUNDER, 1);
		NVIC_EnableIRQ(IRQ_TIM6_DACUNDER);
#else
		NVIC_SetPriority(IRQ_TIM6,1);
		NVIC_EnableIRQ(IRQ_TIM6);
#endif

	}
	else
	{
		NVIC_SetPriority(IRQ_TIM7,1);
		NVIC_EnableIRQ(IRQ_TIM7);
	}
#endif
	}
	else BTIMs[Id]->DIER.Fields.UIE = 0;

	BTIMs[Id]->CR1.Fields.CEN = Config.Enable;
}

#if defined(MCU_F446) || defined(MCU_L433)
void TIM6_DAC_IRQHandler(void)
#elif defined(MCU_F410)
void TIM6_DAC1_IRQHandler(void)
#elif defined(MCU_G070)
void TIM6_DAC_LPTIM1_IRQHandler(void)
#else
#error undefined BasicTIM interrupt;
#endif
{
	BTIMs[0]->SR.Fields.UIF = 0;
	if(IrqPtrs[0] != 0) IrqPtrs[0]();
}

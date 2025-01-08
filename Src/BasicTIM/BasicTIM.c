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
#elif defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
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
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void));
void BasicTIM_Stop(dtBTimId id);
void BasicTIM_Start(dtBTimId id);

void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void))
{
    dtDIER TempDIER;
	BTIMs[Id]->CR1.Fields.ARPE = Config.ARPreload;
	BTIMs[Id]->CR1.Fields.OPM = Config.OnePulse;
	BTIMs[Id]->CR1.Fields.URS = Config.UpdateSource;
	BTIMs[Id]->CR1.Fields.UDIS = Config.UpdateDisable;
	BTIMs[Id]->CR2.Fields.MMS = Config.MasterMode;
	BTIMs[Id]->PSC.Fields.PSC = Config.Prescaler;
	BTIMs[Id]->ARR.Fields.ARR = Config.AutoReload;

	TempDIER.Fields.UDE = Config.DmaTrig;

	if(IrqPtr != 0)
	{
	    TempDIER.Fields.UIE = 1;
		IrqPtrs[Id] = IrqPtr;
#if defined(MCU_F410)
	NVIC_SetPriority(IRQ_TIM6_DAC,1);
	NVIC_EnableIRQ(IRQ_TIM6_DAC);
#elif defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_L476)
	if(Id == TIM6)
	{
#if defined(MCU_L433) || defined(MCU_L476)
		NVIC_SetPriority(IRQ_TIM6_DACUNDER, 1);
		NVIC_EnableIRQ(IRQ_TIM6_DACUNDER);
#elif  defined(MCU_F446)
		NVIC_SetPriority(IRQ_TIM6_DAC, 1);
		NVIC_EnableIRQ(IRQ_TIM6_DAC);
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
#elif defined(MCU_F415)
	if(Id == TIM6)
	{
		NVIC_SetPriority(IRQ_TIM6_DAC,1);
		NVIC_EnableIRQ(IRQ_TIM6_DAC);
	}
	else
	{
		NVIC_SetPriority(IRQ_TIM7,1);
		NVIC_EnableIRQ(IRQ_TIM7);
	}
#endif
	}
	else TempDIER.Fields.UIE = 0;

	BTIMs[Id]->DIER = TempDIER;

	BTIMs[Id]->CR1.Fields.CEN = Config.Enable;
}

void BasicTIM_Stop(dtBTimId id)
{
	dtCR1 tCR = BTIMs[id]->CR1;
	tCR.Fields.CEN = 0;
	BTIMs[id]->CR1 = tCR;
}

void BasicTIM_Start(dtBTimId id)
{
	dtCR1 tCR = BTIMs[id]->CR1;
	tCR.Fields.CEN = 1;
	BTIMs[id]->CNT.Word = 0;
	BTIMs[id]->CR1 = tCR;
}

void BasicTIM_SetAR(dtBTimId Id, uint16 Value)
{
    dtARR T = {.Fields.ARR = Value};
    BTIMs[Id]->ARR = T;
}

void BasicTIM_SetPS(dtBTimId Id, uint16 Value)
{
    dtPSC T = {.Fields.PSC = Value};
    BTIMs[Id]->PSC = T;
}

void BasicTIM_Update(dtBTimId Id)
{
    BTIMs[Id]->EGR.Word = 0xFFFF;
}

#if defined(MCU_F446) || defined(MCU_L433) || defined(MCU_F415)
void TIM6_DAC_IRQHandler(void)
#elif defined(MCU_F410)
void TIM6_DAC1_IRQHandler(void)
#elif defined(MCU_G070) || defined(MCU_G071)
void TIM6_DAC_LPTIM1_IRQHandler(void)
#elif defined(MCU_L476)
void TIM6_DACUNDER_IRQHandler(void)
#else
#error undefined BasicTIM interrupt;
#endif
{
	BTIMs[TIM6]->SR.Fields.UIF = 0;
	if(IrqPtrs[TIM6] != 0) IrqPtrs[TIM6]();
}
#if defined(MCU_G070) || defined(MCU_G071)
void TIM7_LPTIM2_IRQHandler(void)
#elif defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
void TIM7_IRQHandler(void)
#else
#error undefined BasicTIM interrupt;
#endif
{
	BTIMs[TIM7]->SR.Fields.UIF = 0;
	if(IrqPtrs[TIM7] != 0) IrqPtrs[TIM7]();
}
#else
#warning "NO CPU IS DEFINED"
#endif

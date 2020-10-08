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
static dtBTIM *const BTIMs[1] = {	(dtBTIM*)(0x40001000)};//TIM6
static void (*IrqPtrs[1])(void);
#elif defined(MCU_G070)
static dtBTIM *const BTIMs[2] = {	(dtBTIM*)(0x40001000),//TIM6
									(dtBTIM*)(0x40001400),//TIM7
};
static void (*IrqPtrs[2])(void);
#endif

void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void));

void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void))
{
	BTIMs[Id]->CR1.Field.ARPE = Config.ARPreload;
	BTIMs[Id]->CR1.Field.OPM = Config.OnePulse;
	BTIMs[Id]->CR1.Field.URS = Config.UpdateSource;
	BTIMs[Id]->CR1.Field.UDIS = Config.UpdateDisable;
	BTIMs[Id]->PSC.Field.PSC = Config.Prescaler;
	BTIMs[Id]->ARR.Field.ARR = Config.AutoReload;

	if(IrqPtr != 0)
	{
		BTIMs[Id]->DIER.Field.UIE = 1;
		IrqPtrs[Id] = IrqPtr;
#if  defined(MCU_F446)
	NVIC_SetPriority(IRQ_TIM6_DAC,1);
	NVIC_EnableIRQ(IRQ_TIM6_DAC);
#elif defined(MCU_G070)
	NVIC_SetPriority(IRQ_TIM6,1);
	NVIC_EnableIRQ(IRQ_TIM6);
#endif
	}
	else BTIMs[Id]->DIER.Field.UIE = 0;

	BTIMs[Id]->CR1.Field.CEN = Config.Enable;
}

#if defined(MCU_F446)
void TIM6_DAC_IRQHandler(void)
#elif defined(MCU_F410)
void TIM6_DAC1_IRQHandler(void)
#elif defined(MCU_G070)
void TIM6_DAC_LPTIM1_IRQHandler(void)
#else
#error undefined BasicTIM interrupt;
#endif
{
	BTIMs[0]->SR.Field.UIF = 0;
	if(IrqPtrs[0] != 0) IrqPtrs[0]();
}

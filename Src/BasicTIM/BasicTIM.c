/*
 * BasicTIM.c
 *
 *  Created on: 3 May 2020
 *      Author: Bodnár Benjamin
 */

#include "BasicTIM_Types.h"
#include "BasicTIM.h"
#include "NVIC.h"

static dtBTIM *const BTIMs[2] = {	(dtBTIM*)(0x40001000),//TIM6
									(dtBTIM*)(0x40001000),//TIM7
};
static void (*IrqPtrs[2])(void);

void BasicTIM_Set(dtBTimId Id, void (*IrqPtr)(void));

void BasicTIM_Set(dtBTimId Id, void (*IrqPtr)(void))
{
	BTIMs[Id]->CR1.Field.ARPE = 1;
	BTIMs[Id]->CR1.Field.OPM = 0;
	BTIMs[Id]->CR1.Field.URS =1;
	BTIMs[Id]->CR1.Field.UDIS = 0;

	BTIMs[Id]->DIER.Field.UIE = 1;
	BTIMs[Id]->PSC.Field.PSC = 7999;
	BTIMs[Id]->ARR.Field.ARR = 10;

	if(IrqPtr != 0) IrqPtrs[Id] = IrqPtr;

	BTIMs[Id]->CR1.Field.CEN = 1;

	NVIC_SetPriority(TIM6_DAC_IRQn,1);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);

}

void TIM6_DACUNDER_IRQHandler(void)
{
	BTIMs[0]->SR.Field.UIF = 0;
	if(IrqPtrs[0] != 0) IrqPtrs[0]();
}

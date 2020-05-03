/*
 * NVIC.c
 *
 *  Created on: May 3, 2020
 *      Author: Bodnár Benjamin
 */

#include "NVIC_Types.h"
#include "NVIC.h"

static dtNVIC *const NVIC = (dtNVIC*)(0xE000E100);

void NVIC_SetPriority(IRQn_Type Irq, uint32 Priority);
void NVIC_EnableIRQ(IRQn_Type Irq);

void NVIC_SetPriority(IRQn_Type Irq, uint32 Priority)
{
	if((int32)Irq >= 0)
	{
		NVIC->IPR[Irq] = (uint8)(Priority<<4);
	}
}

void NVIC_EnableIRQ(IRQn_Type Irq)
{
	if((int32) Irq >= 0)
	{
		NVIC->ISER[Irq>>5] = 1<<(Irq & 0x1F);
	}
}

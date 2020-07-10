/*
 * NVIC.c
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#include "NVIC_Types.h"
#include "NVIC.h"

static dtISER *const ISER = (dtISER*)0xE000E100;
static dtICER *const ICER = (dtICER*)0xE000E180;
static dtISPR *const ISPR = (dtISPR*)0xE000E200;
static dtICPR *const ICPR = (dtICPR*)0xE000E280;
static dtIABR *const IABR = (dtIABR*)0xE000E300;
static dtIPR *const IPR = (dtIPR*)0xE000E400;

void NVIC_EnableIRQ(dtIRQs IRQ);
void NVIC_SetPriority(dtIRQs IRQ, uint8 IrqLevel);

void NVIC_EnableIRQ(dtIRQs IRQ)
{
	uint8 IserIndex = IRQ>>3;
	uint32 IserBit = IRQ - (IserIndex << 3);
	ISER->ISER[IserIndex] |= 1<<IserBit;
}

void NVIC_SetPriority(dtIRQs IRQ, uint8 IrqLevel)
{
	IPR->ISER[IRQ] = IrqLevel;
}

/*
 * NVIC.c
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#include "NVIC_Types.h"
#include "NVIC.h"
#include "MemMap.h"

void NVIC_EnableIRQ(dtIRQs IRQ);
void NVIC_DisableIRQ(dtIRQs IRQ);
void NVIC_SetPriority(dtIRQs IRQ, uint8 IrqLevel);

void NVIC_EnableIRQ(dtIRQs IRQ)
{
	uint8 IserIndex = IRQ >> 5;
	uint32 IserBit = IRQ - (IserIndex << 5);
	ISER->ISER[IserIndex] |= 1<<IserBit;
}

void NVIC_DisableIRQ(dtIRQs IRQ)
{
    uint8 IserIndex = IRQ >> 5;
    uint32 IserBit = IRQ - (IserIndex << 5);
    ICER->ICER[IserIndex] |= 1<<IserBit;
}

void NVIC_SetPriority(dtIRQs IRQ, uint8 IrqLevel)
{
    if(IRQ < 0)
    {
        switch(IRQ)
        {
            case EXC_SysTick:
                SCB->SHPR3 &= 0x00FFFFFF;
                SCB->SHPR3 |= (IrqLevel << 24);
                break;
            case EXC_PendSV:
                SCB->SHPR3 &= 0xFF00FFFF;
                SCB->SHPR3 |= (IrqLevel << 16);
                break;
            case EXC_SVCall:
                break;
        }
    }
    else IPR->PRI[IRQ] = IrqLevel;
}

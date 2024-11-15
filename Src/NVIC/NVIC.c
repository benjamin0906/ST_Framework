/*
 * NVIC.c
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#include "NVIC_Types.h"
#include "NVIC.h"
#include "MemMap.h"

#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
void NVIC_EnableIRQ(dtIRQs IRQ);
void NVIC_DisableIRQ(dtIRQs IRQ);
void NVIC_SetPriority(dtIRQs IRQ, uint8 Priority);

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

void NVIC_SetPriority(dtIRQs IRQ, uint8 Priority)
{
    if(IRQ < 0)
    {
        IRQ += 16;
        /* Zeroing the section before write,
         * the index shall have one less value because the first 4 exception
         * cannot be modified */
        SCB->SHPR[(IRQ>>2) -1] &= (uint32)~(0xFF <<  (8 * (IRQ & 0x3)));
        SCB->SHPR[(IRQ>>2) -1] |= (uint32)( ( ( Priority << (8 - NVIC_PRIO_BITS) ) & 0xFF) <<  (8 * (IRQ & 0x3)));
    }
    else
    {
        IPR->PRI[IRQ] = (uint8)( ( ( Priority << (8 - NVIC_PRIO_BITS) ) & 0xFF) <<  (8 * (IRQ & 0x3)));
    }
}
#else
#warning "NO CPU IS DEFINED"
#endif

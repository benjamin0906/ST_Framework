/*
 * NVIC.c
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#include "NVIC_Types.h"
#include "NVIC.h"
#include "MemMap.h"

#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(STM32U0)
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

#if defined(STM32U0)

#include "RegDefs/TIM6_7_reg.h"

typedef struct sSharedIsrHanler
{
    void (**isrHandler)(void);
    uint8 MaxIsr;
    uint8 IsrId;
} dtSharedIsrHandler;

static void (*Isr17Handlers[3])(void);
static void (*Isr18Handlers[2])(void);

static const dtSharedIsrHandler SharedIsrHandlerTable[] = {
        {.IsrId = 17, .MaxIsr = 3, .isrHandler = Isr17Handlers},
        {.IsrId = 18, .MaxIsr = 2, .isrHandler = Isr18Handlers},
};

void NCIV_SetSharedIsrHandler(dtIRQs isrNum, uint8 handlerNum, void (*handler)(void));

void NCIV_SetSharedIsrHandler(dtIRQs isrNum, uint8 handlerNum, void (*handler)(void))
{
    uint8 looper = 0;
    while((looper < (sizeof(SharedIsrHandlerTable)/sizeof(dtSharedIsrHandler))) && (isrNum != SharedIsrHandlerTable[looper].IsrId))
    {
        looper++;
    }
    if(looper < (sizeof(SharedIsrHandlerTable)/sizeof(dtSharedIsrHandler)))
    {
        if(handlerNum < SharedIsrHandlerTable[looper].MaxIsr)
        {
            SharedIsrHandlerTable[looper].isrHandler[handlerNum] = handler;
        }
    }
}

void TIM6_DAC_LPTIM1_IRQHandler(void)
{
    if(MODULE_TIM6_7->TIM6_7[0].SR.B.UIF != 0)
    {
        if(Isr17Handlers[0] != 0)
        {
            Isr17Handlers[0]();
        }
        MODULE_TIM6_7->TIM6_7[0].SR.B.UIF = 0;
    }
}

void TIM7_LPTIM2_IRQHandler(void)
{
    if(MODULE_TIM6_7->TIM6_7[1].SR.B.UIF != 0)
    {
        if(Isr18Handlers[0] != 0)
        {
            Isr18Handlers[0]();
        }
        MODULE_TIM6_7->TIM6_7[1].SR.B.UIF = 0;
    }
}

#endif

#else
#warning "NO CPU IS DEFINED"
#endif

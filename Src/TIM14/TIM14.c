/*
 * TIM14.c
 *
 *  Created on: 2026. okt. 20.
 *      Author: Benjamin
 */

#include "STM32C0_MemMap.h"
#include "NVIC.h"

static dtTIM14_C0 *const TIM14 = (dtTIM14_C0*)0x40002000;
static void (*IntHandler)(void);

void TIM14_Init(uint16 Prescaler, uint16 Ar, void (*handler)(void))
{
    dtTIM14_C0_CR1 tCR = {.U = 0};
    dtTIM14_C0_ARR tArr = {.U = 0};
    dtTIM14_C0_DIER tDier = {.U = 0};
    dtTIM14_C0_PSC tPsc = {.U = 0};
    dtTIM14_C0_CCMR1_OC tCCMr1 = {.U = 0};
    dtTIM14_C0_CCER tCcer = {.U = 0};

    TIM14->CR1.U = 0;

    tCR.B.ARPE = 1;
    tCR.B.URS = 1;
    tCR.B.UDIS = 0;
    tCR.B.OPM = 0;


    tPsc.B.PSC = Prescaler;

    tArr.B.ARR = Ar;

    if(handler != 0)
    {
        IntHandler = handler;
        tDier.B.UIE = 1;
        NVIC_EnableIRQ(IRQ_TIM14);
    }

    tCR.B.CEN = 1;

    TIM14->CCER = tCcer;
    TIM14->CCMR1.CCMR1_OC = tCCMr1;
    TIM14->PSC = tPsc;
    TIM14->DIER = tDier;
    TIM14->ARR = tArr;
    TIM14->CR1 = tCR;
}

void TIM14_IRQHandler(void)
{
    if(IntHandler != 0)
    {
        IntHandler();
    }
    dtTIM14_C0_SR tSr = TIM14->SR;
    tSr.B.UIF = 0;
    TIM14->SR = tSr;
}


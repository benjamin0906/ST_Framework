/*
 * SysTick.c
 *
 *  Created on: 2021. okt. 20.
 *      Author: Benjamin
 */

#include "SysTick_Types.h"
#include "NVIC.h"

static dtSysTick *const SysTick = 0xE000E010;
static uint32 Tick;

void    SysTick_Init(uint32 ReloadValue);
uint32  SysTick_GetTicks(void);
void    SysTick_Handler(void);

void SysTick_Init(uint32 ReloadValue)
{
    SysTick->CSR.Word = 0;
    SysTick->RVR = ReloadValue;
    SysTick->CVR = 0;
    SysTick->CSR.Fields.Tickinit = 1;
    SysTick->CSR.Fields.ClkSource = 1;
    SysTick->CSR.Fields.Enable = 1;
}

uint32 SysTick_GetTicks(void)
{
    return Tick;
}

void SysTick_Handler(void)
{
    Tick++;
}

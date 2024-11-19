/*
 * SysTick.c
 *
 *  Created on: 2021. okt. 20.
 *      Author: Benjamin
 */

#include "SysTick_Types.h"
#include "NVIC.h"
#include "config.h"

static dtSysTick *const SysTick = (dtSysTick*)0xE000E010;
static uint32 Tick;

void    SysTick_Init(uint32 ReloadValue);
#if (OS_IS_USED == STD_OFF)
uint32  SysTick_GetTicks(void);
#endif
#if (OS_IS_USED == STD_OFF)
void    SysTick_Handler(void);
#endif

/** @brief initializes the SysTick module
 *
 * This function initializes and enables the SysTick.
 * The SysTick is a 24 bit count down timer built into
 * the ARM core. When the timer overflows a SysTick
 * exception will be generated. The reload value is
 * is loaded into the counter register at 0 at the
 * counting starts from there down
 *
 * @param ReloadValue the reload value from which the
 * counting starts
 */
void SysTick_Init(uint32 ReloadValue)
{
	dtSYST_CSR tCSR = {.Word = 0};

    SysTick->RVR = ReloadValue;
    SysTick->CVR = 0;
    tCSR.Fields.Tickinit = 1;
    tCSR.Fields.ClkSource = 1;
    tCSR.Fields.Enable = 1;

    SysTick->CSR = tCSR;
}

#if (OS_IS_USED == STD_OFF)
/** @brief return the value of 'Tick' variable
 *
 * Tick variable is increased by the exception handler
 * of SysTick. This function can be used to access for
 * read that variable.
 *
 * @return value of 'Tick'
 */
uint32 SysTick_GetTicks(void)
{
    return Tick;
}
#endif

#if (OS_IS_USED == STD_OFF)
/** @brief Exception handler of SysTick
 *
 * Increases the 'Tick' variable so that that can be used
 * to measure time
 */
void SysTick_Handler(void)
{
    Tick++;
}
#endif

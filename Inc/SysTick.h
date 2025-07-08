/*
 * SysTick.h
 *
 *  Created on: 2021. okt. 20.
 *      Author: Benjamin
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "types.h"
#include "config.h"

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
extern void SysTick_Init(uint32 ReloadValue);


/** @brief  This function stops the SysTick
 *  @param  none
 *  @retval none
 */
extern void SysTick_Stop(void);

#if (OS_IS_USED == STD_OFF)
/** @brief return the value of 'Tick' variable
 *
 * Tick variable is increased by the exception handler
 * of SysTick. This function can be used to access for
 * read that variable.
 *
 * @return value of 'Tick'
 */
extern uint32 SysTick_GetTicks(void);
#endif

#endif /* INC_SYSTICK_H_ */

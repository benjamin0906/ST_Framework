/*
 * SysTick.h
 *
 *  Created on: 2021. okt. 20.
 *      Author: Benjamin
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "types.h"

extern void    SysTick_Init(uint32 ReloadValue);
extern uint32  SysTick_GetTicks(void);

#endif /* INC_SYSTICK_H_ */

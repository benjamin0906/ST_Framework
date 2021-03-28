/*
 * Core.c
 *
 *  Created on: 2021. márc. 25.
 *      Author: Benjamin
 */

#include "Core_Types.h"

dtSCB *const SCB = (dtSCB*)0xE000ED00;

inline void Core_SleepDeepSet(void);
inline void Core_SleepDeepClear(void);

void Core_SleepDeepSet(void)
{
	dtSCR TempSCR = SCB->SCR;
	TempSCR.Fields.SLEEPDEEP = 1;
	SCB->SCR = TempSCR;
}

void Core_SleepDeepClear(void)
{
	SCB->SCR.Fields.SLEEPDEEP = 0;
}

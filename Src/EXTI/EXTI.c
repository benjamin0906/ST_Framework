/*
 * EXTI.c
 *
 *  Created on: 2021. ápr. 3.
 *      Author: Benjamin
 */

#include "EXTI_Types.h"

static dtEXTI *const EXTI = (dtEXTI*)0x40021800;

void EXTI_Set(void)
{
	EXTI->ExtiCr[4] = 0;
	EXTI->GenConfEvents.RSTR.Fields.Lines = 0x10;
	EXTI->IMR1 = 0x10;
	EXTI->EMR1 = 0x10;
}

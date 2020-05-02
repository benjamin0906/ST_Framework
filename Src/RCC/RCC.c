/*
 * RCC.c
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#include "RCC_Types.h"
#include "RCC.h"

static dtRCC *const RCC = (dtRCC*) 0x40021000;

void RCC_ClockEnable(uint32 Peripheral);

void RCC_ClockEnable(uint32 Peripheral)
{
	uint32 *ClockRegister = &RCC->ENR.AHB1 + (Peripheral>>16);
	*ClockRegister |= (1<<(Peripheral & 0xFF));
}

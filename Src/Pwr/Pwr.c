/*
 * Pwr.c
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#include "Pwr_Types.h"

static dtPwr *const Pwr = (dtPwr*)(0x40007000);

void Pwr_SetVos(uint8 mode);
uint8 Prw_GetVos(uint8 mode);

void Pwr_SetVos(uint8 mode)
{
#if defined(MCU_F446) || defined(MCU_F410)
	Pwr->CR.Fields.VOS = mode & 0x3;
	while(Pwr->CSR.Fields.VOSRDY != 1);
#endif
}

uint8 Prw_GetVos(uint8 mode)
{
#if defined(MCU_F446) || defined(MCU_F410)
	return Pwr->CR.Fields.VOS;
#endif
}

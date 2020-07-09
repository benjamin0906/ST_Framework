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
	Pwr->CR.Fields.VOS = mode & 0x3;
	while(Pwr->CSR.Fields.VOSRDY != 1);
}

uint8 Prw_GetVos(uint8 mode)
{
	return Pwr->CR.Fields.VOS;
}

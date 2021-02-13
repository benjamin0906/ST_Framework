/*
 * Pwr.c
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#include "Pwr_Types.h"

#ifndef MODULE_TEST
static dtPwr *const Pwr = (dtPwr*)(0x40007000);
#else
#include "TestEnv.h"
static dtPwr *const Pwr = (dtPwr*)&TestPwr;
#endif

void Pwr_SetVos(uint8 mode);
uint8 Pwr_GetVos(void);

void Pwr_SetVos(uint8 mode)
{
#if defined(MCU_F446) || defined(MCU_F410)
	Pwr->CR.Fields.VOS = mode & 0x3;
#ifdef MODULE_TEST
	Pwr->CSR.Fields.VOSRDY = 1;
#endif
	while(Pwr->CSR.Fields.VOSRDY != 1);
#elif defined(MCU_G070) || defined(MCU_G071)
	Pwr->CR.Fields.VOS = mode & 0x3;
#ifdef MODULE_TEST
	Pwr->SR2.Fields.VOSF = 0;
#endif
	while(Pwr->SR2.Fields.VOSF != 0);
#endif
}

uint8 Pwr_GetVos(void)
{
#if defined(MCU_F446) || defined(MCU_F410)
	return Pwr->CR.Fields.VOS;
#elif defined(MCU_G070) || defined(MCU_G071)
	return Pwr->CR.Fields.VOS;
#endif
}

void Pwr_RtcWp(void)
{
	dtPwrCR temp = Pwr->CR;
	temp.Fields.DBP = 1;
	Pwr->CR = temp;
}

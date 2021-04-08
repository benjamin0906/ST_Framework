/*
 * Pwr.c
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#include "Pwr_Types.h"
#include "Pwr.h"

/* The registers of the module can only be accessed by 16 or 32 bit operations */
#ifndef MODULE_TEST
static dtPwr *const Pwr = (dtPwr*)(0x40007000);
#else
#include "TestEnv.h"
static dtPwr *const Pwr = (dtPwr*)&TestPwr;
#endif

void Pwr_SetVos(uint8 mode);
uint8 Pwr_GetVos(void);
void Pwr_LowPowerMode(dtLowPwrModes Mode);

void Pwr_SetVos(uint8 mode)
{
	dtPwrCR TempCr = Pwr->CR;
#if defined(MCU_F446) || defined(MCU_F410)
	TempCr.Fields.VOS = mode & 0x3;
#ifdef MODULE_TEST
	Pwr->CSR.Fields.VOSRDY = 1;
#endif
	while(Pwr->CSR.Fields.VOSRDY != 1);
#elif defined(MCU_G070) || defined(MCU_G071)
	TempCr.Fields.VOS = mode & 0x3;
#ifdef MODULE_TEST
	Pwr->SR2.Fields.VOSF = 0;
#endif
	Pwr->CR = TempCr;
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

/* This function is an interface to set the mode of low-power operation */
void Pwr_LowPowerMode(dtLowPwrModes Mode)
{
	dtPwrCR TempCr = Pwr->CR;
	TempCr.Fields.LPMS = Mode;
	Pwr->CR = TempCr;
}

/*
 * Pwr.c
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#include "Pwr_Types.h"
#include "Pwr.h"

#if defined(STM32U0)
#include "RegDefs/Pwr_regdef.h"
#endif
/* The registers of the module can only be accessed by 16 or 32 bit operations */
#if defined(STM32U0)
static volatile dtPWR *const PWR = (dtPWR*)(0x40007000);
#endif

#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(STM32U0)
void Pwr_SetVos(uint8 mode);
uint8 Pwr_GetVos(void);
void Pwr_LowPowerMode(dtLowPwrModes Mode);

void Pwr_SetVos(uint8 mode)
{
#if defined(MCU_F446) || defined(MCU_F410)
	dtPwrCR TempCr = Pwr->CR;
	TempCr.Fields.VOS = mode & 0x3;
	while(Pwr->CSR.Fields.VOSRDY != 1);
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
	dtPwrCR TempCr = Pwr->CR;
	TempCr.Fields.VOS = mode & 0x3;
	Pwr->CR = TempCr;
	while(Pwr->SR2.Fields.VOSF != 0);
#elif defined(MCU_F415)
	TempCr.Fields.VOS = mode & 0x1;
	Pwr->CR = TempCr;
	while(Pwr->CSR.Fields.VOSRDY != 1);
#elif defined(STM32U0)
	if(mode < 3)
	{
		dtPWR_CR1 tCR1 = PWR->CR1;
		tCR1.B.VOS = mode;
		PWR->CR1 = tCR1;
		while(PWR->SR2.B.VOSF != 0);
	}
#endif
}

uint8 Pwr_GetVos(void)
{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071)  || defined(MCU_F415) || defined(MCU_L476)
	return Pwr->CR.Fields.VOS;
#elif defined(STM32U0)
	return PWR->CR1.B.VOS;
#endif
}

void Pwr_RtcWp(void)
{
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071)  || defined(MCU_F415) || defined(MCU_L476)
	dtPwrCR temp = Pwr->CR;
	temp.Fields.DBP = 1;
	Pwr->CR = temp;
#elif defined(STM32U0)
	dtPWR_CR1 tCR1 = PWR->CR1;
	tCR1.B.DBP = 1;
	PWR->CR1 = tCR1;
#endif
}

/* This function is an interface to set the mode of low-power operation */
void Pwr_LowPowerMode(dtLowPwrModes Mode)
{
#if defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
	dtPwrCR TempCr = Pwr->CR;
	TempCr.Fields.LPMS = Mode;
	Pwr->CR = TempCr;
#elif defined(STM32U0)
	dtPWR_CR1 tCR1 = PWR->CR1;
    tCR1.B.LPMS = Mode;
	PWR->CR1 = tCR1;
#endif
}
#else
#warning "NO CPU IS DEFINED"
#endif

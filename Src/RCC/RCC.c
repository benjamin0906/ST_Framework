/*
 * RCC.c
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#include "RCC_Types.h"
#include "RCC.h"
#include "Pwr.h"
#include "Flash.h"

volatile static dtRCC *const RCC = (dtRCC*) 0x40021000;

uint32 ClockFreq = 2000000;
uint32 CrystalFreq = 0;

void RCC_ClockEnable(uint32 Peripheral);
void RCC_ClockSet(uint32 Clock);

void RCC_ClockEnable(uint32 Peripheral)
{
	uint32 *ClockRegister = &RCC->ENR.AHB1 + (Peripheral>>16);
	*ClockRegister |= (1<<(Peripheral & 0xFF));
}

void RCC_ClockSet(uint32 Clock)
{
	uint32 PrevClock = ClockFreq;
	ClockFreq = Clock;
	if(Clock > 26000000)
	{
		if(Pwr_GetVoltageRange() == Range_2) Pwr_SetVoltageRange(Range_1);
	}
	Flash_SetLatency();

	/* Select MSI clock as PLL source */
	RCC->PLL_CFGR.PLLSRC = 1;

	/* We use the MSI clock, being by default 4MHz, for the PLL so it not need to divide. */
	RCC->PLL_CFGR.PLLM = 0;

	/* 4MHz * 40 = 160 MHz for VCO frequency */
	RCC->PLL_CFGR.PLLN = 40;

	RCC->PLL_CFGR.PLLQEN = 0;
	RCC->PLL_CFGR.PLLPEN = 0;

	RCC->PLL_CFGR.PLLREN = 1;
	RCC->PLL_CFGR.PLLR = 0;

	RCC->CR.PLLON = 1;
	while(RCC->CR.PLLRDY == 0);

	RCC->CFGR.SW = 3;
	while(RCC->CFGR.SWS != 3);

}

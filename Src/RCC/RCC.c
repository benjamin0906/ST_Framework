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

#if defined(MCU_L476)
static dtRCC *const RCC = (dtRCC*) (0x40021000);
#elif defined(MCU_F446) || defined(MCU_F410)
static dtRCC *const RCC = (dtRCC*) (0x40023800);
#endif

uint32 ClockFreq = 2000000;
uint32 CrystalFreq = 0;

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
void RCC_ClockInit(void);
uint32 RCC_GetClock(dtBus Bus);

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value)
{
	uint32 BusId = Clock & 0xFFFFFFE0;
	uint32 ClockMask = 1 << (Clock & 0x1F);
	dtSetOrClear SetOrClear = Set;
	dtBusGroup *GroupPtr;

	if((Value == Enable) || (Value == Disable)) GroupPtr = &RCC->ENR;
	else if((Value == LpEnable) || (Value == LpDisable)) GroupPtr = &RCC->LPENR;
	else GroupPtr = &RCC->RSTR;

	if((Value == Disable) || (Value == LpDisable))
	{
		SetOrClear = Clear;
		ClockMask = ~ClockMask;
	}

	switch(BusId)
	{
		case 0<<5:
				if(SetOrClear == Set) GroupPtr->AHB1.Word |= ClockMask;
				else GroupPtr->AHB1.Word &= ClockMask;
			break;
		case 1<<5:
				if(SetOrClear == Set) GroupPtr->APB1.Word |= ClockMask;
				else GroupPtr->APB1.Word &= ClockMask;
			break;
		case 2<<5:
				if(SetOrClear == Set) GroupPtr->APB2.Word |= ClockMask;
				else GroupPtr->APB2.Word &= ClockMask;
			break;
	}
}

void RCC_ClockSet(uint32 Clock)
{
	uint32 PrevClock = ClockFreq;
	ClockFreq = Clock;

	Flash_SetLatency(Clock,33);

	RCC->CR.Fields.HSEON = 1;
	while(RCC->CR.Fields.HSERDY == 0);

	/* Select HSE clock as PLL source */
	RCC->PLLCFGR.Fields.PLLSRC = 1;

	/* We use the MSI clock, being by default 4MHz, for the PLL so it not need to divide. */
	RCC->PLLCFGR.Fields.PLLM = 8;

	/* 4MHz * 40 = 160 MHz for VCO frequency */
	RCC->PLLCFGR.Fields.PLLN = 50;


	RCC->CR.Fields.PLLON = 1;
	while(RCC->CR.Fields.PLLRDY == 0);

	RCC->CFGR.Fields.SW = 3;
	while(RCC->CFGR.Fields.SWS != 3);
}

uint32 RCC_GetClock(dtBus Bus)
{
	/*uint32 ret = 0;
	uint16 AHBPresc = 1;
	uint8 APB1Presc = 1;
	uint8 APB2Presc = 1;
	uint32 AHBClock;
	uint32 APB1Clock;
	uint32 APB2Clock;

	if(RCC->CFGR.Fields.HRPE >= 0x8)
	{
		AHBPresc = 1 << ((RCC->CFGR.Fields.HRPE & 0x7) + 1);
		if(RCC->CFGR.Fields.HRPE >= 0xC) AHBPresc <<= 1;
	}
	if(RCC->CFGR.Fields.PPRE2 >= 0x4) APB2Presc = 1 << ((RCC->CFGR.Fields.PPRE2 & 0x3) + 1);
	if(RCC->CFGR.Fields.PPRE1 >= 0x4) APB1Presc = 1 << ((RCC->CFGR.Fields.PPRE1 & 0x3) + 1);

	AHBClock = SYS/AHBPresc;
	APB1Clock = AHBClock/APB1Presc;
	APB2Clock = AHBClock/APB2Presc;

	if(Bus == APB1_Timer)
	{
		ret = APB1Clock;
		if(RCC->CFGR.Fields.PPRE1 != 1) ret *= 2;
	}
	else if(Bus == APB2_Timer)
	{
		ret = APB2Clock;
		if(RCC->CFGR.Fields.PPRE2 != 1) ret *= 2;
	}
	else if(Bus == APB1_Peripheral) ret = APB1Clock;
	else if(Bus == APB2_Peripheral) ret = APB2Clock;
	else if(Bus == Core) ret = SYS;
	return ret;*/
}

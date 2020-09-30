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

#if defined(MCU_L476) || defined(MCU_G070)
static dtRCC *const RCC = (dtRCC*) (0x40021000);
#elif defined(MCU_F446) || defined(MCU_F410)
static dtRCC *const RCC = (dtRCC*) (0x40023800);
#endif

#define DIVIDER_M_MIN	2
#define DIVIDER_M_MAX	63
#define DIVIDER_P_MIN	0
#define DIVIDER_P_MAX	3
#define MULT_N_MIN		50
#define MULT_N_MAX		432

uint32 ClockFreq = 2000000;
uint32 CrystalFreq = 16000000;

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
void RCC_ClockInit(void);
uint32 RCC_GetClock(dtBus Bus);

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value)
{
	uint32 BusId = Clock>>5;
	uint32 ClockMask = 1 << (Clock - (BusId<<5));
	dtSetOrClear SetOrClear = Set;
	dtBusGroup *GroupPtr;

	if((Value == Enable) || (Value == Disable)) GroupPtr = &RCC->ENR;
	else if((Value == LpEnable) || (Value == LpDisable)) GroupPtr = &RCC->SMENR;
	else GroupPtr = &RCC->RSTR;

	if((Value == Disable) || (Value == LpDisable))
	{
		SetOrClear = Clear;
		ClockMask = ~ClockMask;
	}
#if defined(MCU_G070)
	uint32 *Pointer = &GroupPtr->IOP.Word + BusId;
#elif defined(MCU_F446)
	uint32 *Pointer = &GroupPtr->AHB1.Word + BusId;
#endif
	if(SetOrClear == Set) *Pointer |= ClockMask;
	else *Pointer &= ClockMask;

	/*switch(BusId)
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
	}*/
}

void RCC_ClockSet(dtRccInitConfig Config)
{
	ClockFreq = Config.Clock;

	Flash_SetLatency(Config.Clock,33);

	uint8 Result = 0;
	uint16 DividerM;
	uint16 MultiplierN;
	uint16 DividerP;
	uint32 CalculatedClock;

	for(DividerM = DIVIDER_M_MIN; (DividerM <= DIVIDER_M_MAX) && (Result == 0); DividerM++)
	{
		uint32 PllInClock = CrystalFreq/DividerM;
		if((PllInClock >= 1000000) && (PllInClock <= 2000000))
		{
			for(MultiplierN = MULT_N_MIN; (MultiplierN <= MULT_N_MAX) && (Result == 0); MultiplierN++)
			{
				uint32 PllClock = PllInClock*MultiplierN;
				if((PllClock >= 100000000) && (PllClock <= 432000000))
				{
					for(DividerP = DIVIDER_P_MIN; (DividerP <= DIVIDER_P_MAX) && (Result == 0); DividerP++)
					{
						CalculatedClock = PllClock / ((DividerP+1)*2);
						if(CalculatedClock == Config.Clock) Result = 1;
					}
				}
			}
		}
	}

	if(Config.CrystalOrInternal == Crystal)
	{
		RCC->CR.Fields.HSEON = 1;
		while(RCC->CR.Fields.HSERDY == 0);
#if defined(MCU_F446) || defined(MCU_F410)
		RCC->PLLCFGR.Fields.PLLSRC = 1;
#endif
	}
	else
	{
		RCC->CR.Fields.HSION = 1;
		while(RCC->CR.Fields.HSIRDY == 0);
#if defined(MCU_F446) || defined(MCU_F410)
		RCC->PLLCFGR.Fields.PLLSRC = 0;
#endif
	}


	/* We use the MSI clock, being by default 4MHz, for the PLL so it not need to divide. */
	RCC->PLLCFGR.Fields.PLLM = DividerM-1;

	/* 4MHz * 40 = 160 MHz for VCO frequency */
	RCC->PLLCFGR.Fields.PLLN = MultiplierN-1;

	RCC->PLLCFGR.Fields.PLLP = DividerP-1;

	RCC->CR.Fields.PLLON = 1;
	while(RCC->CR.Fields.PLLRDY == 0);

#if defined(MCU_F446) || defined(MCU_F410)
	if(Config.APB2_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE2 = 0;
	else RCC->CFGR.Fields.PPRE2 = 0x4 | (Config.APB2_Presc-1);

	if(Config.APB1_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE1 = 0;
	else RCC->CFGR.Fields.PPRE1 = 0x4 | (Config.APB1_Presc-1);
#endif
	if(Config.AHB_Presc == AHB_Presc1) RCC->CFGR.Fields.HRPE = 0;
	else RCC->CFGR.Fields.HRPE = 0x8 | (Config.AHB_Presc-1);

	RCC->CFGR.Fields.SW = 2;
	while(RCC->CFGR.Fields.SWS != 2);
}

uint32 RCC_GetClock(dtBus Bus)
{
	uint32 ret = 0;
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
#if defined(MCU_F446) || defined(MCU_F410)
	if(RCC->CFGR.Fields.PPRE2 >= 0x4) APB2Presc = 1 << ((RCC->CFGR.Fields.PPRE2 & 0x3) + 1);
	if(RCC->CFGR.Fields.PPRE1 >= 0x4) APB1Presc = 1 << ((RCC->CFGR.Fields.PPRE1 & 0x3) + 1);
#endif
	AHBClock = ClockFreq/AHBPresc;
	APB1Clock = AHBClock/APB1Presc;
	APB2Clock = AHBClock/APB2Presc;

	if(Bus == APB1_Timer)
	{
		ret = APB1Clock;
#if defined(MCU_F446) || defined(MCU_F410)
		if(RCC->CFGR.Fields.PPRE1 != 1) ret *= 2;
#endif
	}
	else if(Bus == APB2_Timer)
	{
		ret = APB2Clock;
#if defined(MCU_F446) || defined(MCU_F410)
		if(RCC->CFGR.Fields.PPRE2 != 1) ret *= 2;
#endif
	}
	else if(Bus == APB1_Peripheral) ret = APB1Clock;
	else if(Bus == APB2_Peripheral) ret = APB2Clock;
	else if(Bus == AHB) ret = AHBClock;
	else if(Bus == Core) ret = ClockFreq;
	return ret;
}

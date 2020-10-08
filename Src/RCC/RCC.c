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
#include "config.h"

#ifndef MODULE_TEST
#if defined(MCU_L476) || defined(MCU_G070)
static dtRCC *const RCC = (dtRCC*) (0x40021000);
#elif defined(MCU_F446) || defined(MCU_F410)
static dtRCC *const RCC = (dtRCC*) (0x40023800);
#endif
#else
static dtRCC *const RCC = (dtRCC*)&TestRCC;
#endif

#if defined(MCU_F446) || defined(MCU_F410)
#define DIVIDER_M_MIN	2
#define DIVIDER_M_MAX	63
#define DIVIDER_P_MIN	0
#define DIVIDER_P_MAX	3
#define MULT_N_MIN		50
#define MULT_N_MAX		432
#define PLL_INPUT_FREQ_MIN	1000000
#define PLL_INPUT_FREQ_MAX	2000000
#define PLL_VCO_FREQ_MIN	100000000
#define PLL_VCO_FREQ_MAX	432000000
#define INTERNAL_CLOCK_FREQ	16000000

#elif defined(MCU_G070)
#define DIVIDER_M_MIN	1
#define DIVIDER_M_MAX	8
#define DIVIDER_R_MIN	2
#define DIVIDER_R_MAX	8
#define MULT_N_MIN		8
#define MULT_N_MAX		86
#define PLL_INPUT_FREQ_MIN	4000000
#define PLL_INPUT_FREQ_MAX	16000000
#define PLL_VCO_FREQ_MIN	64000000
#define PLL_VCO_FREQ_MAX	344000000
#define INTERNAL_CLOCK_FREQ	16000000
#endif

uint32 ClockFreq = 2000000;

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
void RCC_ClockInit(void);
uint32 RCC_GetClock(dtBus Bus);

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value)
{
	uint32 BusId = Clock>>5;
	uint32 ClockMask = 1 << (Clock&0x1F);
	dtSetOrClear SetOrClear = Set;
	dtBusGroup *GroupPtr;

	if((Value == Enable) || (Value == Disable)) GroupPtr = &RCC->ENR;
#if defined(MCU_G070)
	else if((Value == LpEnable) || (Value == LpDisable)) GroupPtr = &RCC->SMENR;
#elif defined(MCU_F410)
	else if((Value == LpEnable) || (Value == LpDisable)) GroupPtr = &RCC->LPENR;
#endif
	else GroupPtr = &RCC->RSTR;

	if((Value == Disable) || (Value == LpDisable))
	{
		SetOrClear = Clear;
		ClockMask = ~ClockMask;
	}
#if defined(MCU_G070)
	uint32 *Pointer = &GroupPtr->IOP.Word + BusId;
#elif defined(MCU_F446) || defined(MCU_F410)
	uint32 *Pointer = &GroupPtr->AHB1.Word + BusId;
#endif
	if(SetOrClear == Set) *Pointer |= ClockMask;
	else *Pointer &= ClockMask;
}

void RCC_ClockSet(dtRccInitConfig Config)
{
	uint8 Result = 0;
	uint16 DividerM;
	uint16 MultiplierN;
#if defined(MCU_F446) || defined(MCU_F410)
	uint16 DividerP;
#elif defined(MCU_G070)
	uint16 DividerR;
#endif
	uint32 CalculatedClock;
	uint32 BaseFreq = INTERNAL_CLOCK_FREQ;
	if(Config.CrystalOrInternal == Crystal) BaseFreq = Config.CrystalClockFreq;

	for(DividerM = DIVIDER_M_MIN; (DividerM <= DIVIDER_M_MAX) && (Result == 0); DividerM++)
	{
		uint32 PllInClock = BaseFreq/DividerM;
		if((PllInClock >= PLL_INPUT_FREQ_MIN) && (PllInClock <= PLL_INPUT_FREQ_MAX))
		{
			for(MultiplierN = MULT_N_MIN; (MultiplierN <= MULT_N_MAX) && (Result == 0); MultiplierN++)
			{
				uint32 PllClock = PllInClock*MultiplierN;
				if((PllClock >= PLL_VCO_FREQ_MIN) && (PllClock <= PLL_VCO_FREQ_MAX))
				{
#if defined(MCU_F446) || defined(MCU_F410)
					for(DividerP = DIVIDER_P_MIN; (DividerP <= DIVIDER_P_MAX) && (Result == 0); DividerP++)
					{
						CalculatedClock = PllClock / ((DividerP+1)*2);
						if(CalculatedClock == Config.Clock) Result = 1;
					}
#elif defined(MCU_G070)
					for(DividerR = DIVIDER_R_MIN; (DividerR <= DIVIDER_R_MAX) && (Result == 0); DividerR++)
					{
						CalculatedClock = PllClock / (DividerR+1);
						if(CalculatedClock == Config.Clock) Result = 1;
					}
#endif
				}
			}
		}
	}

	if(Result == 1)
	{
		ClockFreq = Config.Clock;
		if(Config.CrystalOrInternal == Crystal)
		{
			RCC->CR.Fields.HSEON = 1;
#ifdef MODULE_TEST
			RCC->CR.Fields.HSERDY = 1;
#endif
			while(RCC->CR.Fields.HSERDY == 0);
#if defined(MCU_F446) || defined(MCU_F410)
			RCC->PLLCFGR.Fields.PLLSRC = 1;
#elif defined(MCU_G070)
			RCC->PLLCFGR.Fields.PLLSRC = 3;
#endif
		}
		else
		{
			RCC->CR.Fields.HSION = 1;
#ifdef MODULE_TEST
			RCC->CR.Fields.HSIRDY = 1;
#endif
			while(RCC->CR.Fields.HSIRDY == 0);
#if defined(MCU_F446) || defined(MCU_F410)
			RCC->PLLCFGR.Fields.PLLSRC = 0;
#elif defined(MCU_G070)
			RCC->PLLCFGR.Fields.PLLSRC = 2;
#endif
		}

#if defined(MCU_F446) || defined(MCU_F410)
		/* We use the MSI clock, being by default 4MHz, for the PLL so it not need to divide. */
		RCC->PLLCFGR.Fields.PLLM = DividerM-1;
#elif defined(MCU_G070)
		RCC->PLLCFGR.Fields.PLLM = DividerM-2;
#endif

		/* 4MHz * 40 = 160 MHz for VCO frequency */
		RCC->PLLCFGR.Fields.PLLN = MultiplierN-1;
#if defined(MCU_F446) || defined(MCU_F410)
		RCC->PLLCFGR.Fields.PLLP = DividerP-1;
#elif defined(MCU_G070)
		RCC->PLLCFGR.Fields.PLLR = DividerR-1;
#endif
		RCC->CR.Fields.PLLON = 1;
#ifdef MODULE_TEST
		RCC->CR.Fields.PLLRDY = 1;
#endif
		while(RCC->CR.Fields.PLLRDY == 0);

#if defined(MCU_G070)
		if(ClockFreq <= 16000000) Pwr_SetVos(2);
		else Pwr_SetVos(1);
		Flash_SetLatency(ClockFreq);
#elif defined(MCU_F410)
		if(ClockFreq <= 64000000) Pwr_SetVos(1);
		else if(ClockFreq <= 84000000) Pwr_SetVos(2);
		else Pwr_SetVos(3);
		Flash_SetLatency(ClockFreq, SUPPLY_VOLTAGE);
#endif

#if defined(MCU_F446) || defined(MCU_F410)
		if(Config.APB2_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE2 = 0;
		else RCC->CFGR.Fields.PPRE2 = 0x4 | (Config.APB2_Presc-1);

		if(Config.APB1_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE1 = 0;
		else RCC->CFGR.Fields.PPRE1 = 0x4 | (Config.APB1_Presc-1);
#elif defined(MCU_G070)
		if(Config.APB1_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE = 0;
		else RCC->CFGR.Fields.PPRE = 0x4 | (Config.APB1_Presc-1);
#endif
		if(Config.AHB_Presc == AHB_Presc1) RCC->CFGR.Fields.HPRE = 0;
		else RCC->CFGR.Fields.HPRE = 0x8 | (Config.AHB_Presc-1);

#if defined(MCU_G070)
		RCC->PLLCFGR.Fields.PLLREN = 1;
#endif

		RCC->CFGR.Fields.SW = 2;
#ifdef MODULE_TEST
		RCC->CFGR.Fields.SWS = 2;
#endif
		while(RCC->CFGR.Fields.SWS != 2);
	}
}

uint32 RCC_GetClock(dtBus Bus)
{
	uint32 ret = 0;
	uint16 AHBPresc = 1;
	uint8 APB1Presc = 1;
#if defined(MCU_F446) || defined(MCU_F410)
	uint8 APB2Presc = 1;
#endif
	uint32 AHBClock;
	uint32 APB1Clock;
#if defined(MCU_F446) || defined(MCU_F410)
	uint32 APB2Clock;
#endif

	if(RCC->CFGR.Fields.HPRE >= 0x8)
	{
		AHBPresc = 1 << ((RCC->CFGR.Fields.HPRE & 0x7) + 1);
		if(RCC->CFGR.Fields.HPRE >= 0xC) AHBPresc <<= 1;
	}
#if defined(MCU_F446) || defined(MCU_F410)
	if(RCC->CFGR.Fields.PPRE2 >= 0x4) APB2Presc = 1 << ((RCC->CFGR.Fields.PPRE2 & 0x3) + 1);
	if(RCC->CFGR.Fields.PPRE1 >= 0x4) APB1Presc = 1 << ((RCC->CFGR.Fields.PPRE1 & 0x3) + 1);
#elif defined(MCU_G070)
	if(RCC->CFGR.Fields.PPRE >= 0x4) APB1Presc = 1 << ((RCC->CFGR.Fields.PPRE & 0x3) + 1);
#endif
	AHBClock = ClockFreq/AHBPresc;
	APB1Clock = AHBClock/APB1Presc;
#if defined(MCU_F446) || defined(MCU_F410)
	APB2Clock = AHBClock/APB2Presc;
#endif

	if(Bus == APB1_Timer)
	{
		ret = APB1Clock;
		if(APB1Presc != 1) ret *= 2;
	}
#if defined(MCU_F446) || defined(MCU_F410)
	else if(Bus == APB2_Timer)
	{
		ret = APB2Clock;
		if(APB2Presc != 1) ret *= 2;
	}
#endif
	else if(Bus == APB1_Peripheral) ret = APB1Clock;
#if defined(MCU_F446) || defined(MCU_F410)
	else if(Bus == APB2_Peripheral) ret = APB2Clock;
#endif
	else if(Bus == AHB) ret = AHBClock;
	else if(Bus == Core) ret = ClockFreq;
	return ret;
}

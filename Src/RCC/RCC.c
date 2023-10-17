/*
 * RCC.c
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#include "RCC_Types.h"
#include "RCC.h"
#include "RCC_RTC.h"
#include "Pwr.h"
#include "Flash.h"
#include "config.h"

#ifndef MODULE_TEST
#if defined(MCU_L476) || defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071)
static dtRCC *const RCC = (dtRCC*) (0x40021000);
#elif defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
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
#define HSI_CLOCK_FREQUENCY	16000000

#elif defined(MCU_F415)
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

#elif defined(MCU_L476)
#define DIVIDER_M_MIN	1
#define DIVIDER_M_MAX	8
#define DIVIDER_R_MIN	0	//this is the divider R but handled the same way az a divider P
#define DIVIDER_R_MAX	3
#define MULT_N_MIN		8
#define MULT_N_MAX		86
#define PLL_INPUT_FREQ_MIN	4000000
#define PLL_INPUT_FREQ_MAX	16000000
#define PLL_VCO_FREQ_MIN	64000000
#define PLL_VCO_FREQ_MAX	344000000
#define HSI_CLOCK_FREQUENCY	16000000

#elif defined(MCU_G070) || defined(MCU_G071)
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
#elif defined(MCU_L433)
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

#ifndef EXTERNAL_OSC_FREQUENCY
#define EXTERNAL_OSC_FREQUENCY 0
#endif

#if defined(MCU_L476)
const uint16 MsiFrequencies100kHz[12] = {1, 2, 4, 8, 10, 20, 40, 80, 160, 240, 320, 480};
const uint8 AhbPrescalerShiftingValue[8] = {1, 2, 3, 4, 6, 7, 8, 9};
const uint8 Apb1PrescalerShiftValues[4] = {1, 2, 3, 4};
const uint8 Apb2PrescalerShiftValues[4] = {1, 2, 3, 4};
#endif

uint32 ClockFreq = 2000000;

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
void RCC_ClockInit(void);
uint32 RCC_GetClock(dtBus Bus);
void RCC_RTCDomainConfig(dtRCCRtcConfig Config);
static inline uint32 RCC_PllFreq(void);

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value)
{
	uint32 BusId = Clock>>5;
	uint32 ClockMask = 1 << (Clock&0x1F);
	dtClockSetOrClear SetOrClear = Clock_Set;
	dtBusGroup *GroupPtr;

	if((Value == Enable) || (Value == Disable)) GroupPtr = &RCC->ENR;
#if defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_L476)
	else if((Value == LpEnable) || (Value == LpDisable)) GroupPtr = &RCC->SMENR;
#elif defined(MCU_F410) || defined(MCU_F415)
	else if((Value == LpEnable) || (Value == LpDisable)) GroupPtr = &RCC->LPENR;
#endif
	else GroupPtr = &RCC->RSTR;

	if((Value == Disable) || (Value == LpDisable))
	{
		SetOrClear = Clock_Clear;
		ClockMask = ~ClockMask;
	}
#if defined(MCU_G070) || defined(MCU_G071)
	uint32 *Pointer = &GroupPtr->IOP.Word + BusId;
#elif defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
	uint32 *Pointer = &GroupPtr->AHB1.Word + BusId;
#endif
	if(SetOrClear == Clock_Set) *Pointer |= ClockMask;
	else *Pointer &= ClockMask;
}

void RCC_ClockSet(dtRccInitConfig Config)
{
	uint8 Result = 0;
	uint16 DividerM;
	uint16 MultiplierN;
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
	uint16 DividerP;
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
	uint16 DividerR;
#endif
	uint32 CalculatedClock;
	uint32 BaseFreq = HSI_CLOCK_FREQUENCY;
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
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
					for(DividerP = DIVIDER_P_MIN; (DividerP <= DIVIDER_P_MAX) && (Result == 0); DividerP++)
					{
						CalculatedClock = PllClock / ((DividerP+1)*2);
						if(CalculatedClock == Config.Clock) Result = 1;
					}
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
					for(DividerR = DIVIDER_R_MIN; (DividerR <= DIVIDER_R_MAX) && (Result == 0); DividerR++)
					{
#if defined(MCU_L476)
						CalculatedClock = PllClock / ((DividerR+1)*2);
						if(CalculatedClock == Config.Clock) Result = 1;
#else
						CalculatedClock = PllClock / (DividerR+1);
						if(CalculatedClock == Config.Clock) Result = 1;
#endif
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
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
			RCC->PLLCFGR.Fields.PLLSRC = 1;
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
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
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
			RCC->PLLCFGR.Fields.PLLSRC = 0;
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
			RCC->PLLCFGR.Fields.PLLSRC = 2;
#endif
		}

#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
		/* We use the MSI clock, being by default 4MHz, for the PLL so it not need to divide. */
		RCC->PLLCFGR.Fields.PLLM = DividerM-1;
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
		RCC->PLLCFGR.Fields.PLLM = DividerM-2;
#endif

		/* 4MHz * 40 = 160 MHz for VCO frequency */
		RCC->PLLCFGR.Fields.PLLN = MultiplierN-1;
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
		RCC->PLLCFGR.Fields.PLLP = DividerP-1;
		RCC->PLLCFGR.Fields.PLLQ = Config.PLL_QDiv;
#elif defined(MCU_G070) || defined(MCU_G071)
		RCC->PLLCFGR.Fields.PLLR = DividerR-1;
#elif defined(MCU_L476)
		RCC->PLLCFGR.Fields.PLLR = DividerR-1;
		RCC->PLLCFGR.Fields.PLLQ = Config.PLL_QDiv;
		RCC->PLLCFGR.Fields.PLLREN = 1;
#endif
		RCC->CR.Fields.PLLON = 1;
#ifdef MODULE_TEST
		RCC->CR.Fields.PLLRDY = 1;
#endif
		while(RCC->CR.Fields.PLLRDY == 0);

#if defined(MCU_G070) || defined(MCU_G071)
		if(ClockFreq <= 16000000) Pwr_SetVos(2);
		else Pwr_SetVos(1);
		Flash_SetLatency(ClockFreq);
#elif defined(MCU_F410)
		if(ClockFreq <= 64000000) Pwr_SetVos(1);
		else if(ClockFreq <= 84000000) Pwr_SetVos(2);
		else Pwr_SetVos(3);
		Flash_SetLatency(ClockFreq, SUPPLY_VOLTAGE);
#elif defined(MCU_F415)
		if(ClockFreq <= 144000000) Pwr_SetVos(0);
		else Pwr_SetVos(1);
		Flash_SetLatency(ClockFreq, SUPPLY_VOLTAGE);
#elif defined(MCU_L476)
		if(ClockFreq <= 26000000) Pwr_SetVos(2);
		else Pwr_SetVos(1);
		Flash_SetLatency(ClockFreq);
#elif defined(MCU_F446)
		if(ClockFreq <= 120000000) Pwr_SetVos(1);
		else if(ClockFreq <= 144000000) Pwr_SetVos(2);
		else Pwr_SetVos(3);
        Flash_SetLatency(ClockFreq, SUPPLY_VOLTAGE);
#endif

#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
		if(Config.APB2_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE2 = 0;
		else RCC->CFGR.Fields.PPRE2 = 0x4 | (Config.APB2_Presc-1);

		if(Config.APB1_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE1 = 0;
		else RCC->CFGR.Fields.PPRE1 = 0x4 | (Config.APB1_Presc-1);
#elif defined(MCU_G070) || defined(MCU_G071)
		if(Config.APB1_Presc == APB_Presc1) RCC->CFGR.Fields.PPRE = 0;
		else RCC->CFGR.Fields.PPRE = 0x4 | (Config.APB1_Presc-1);
#endif
		if(Config.AHB_Presc == AHB_Presc1) RCC->CFGR.Fields.HPRE = 0;
		else RCC->CFGR.Fields.HPRE = 0x8 | (Config.AHB_Presc-1);

#if defined(MCU_G070) || defined(MCU_G071)
		RCC->PLLCFGR.Fields.PLLREN = 1;
#endif

#if defined(MCU_L476)
		RCC->CFGR.Fields.SW = 3;
		while(RCC->CFGR.Fields.SWS != 3);
#else
		RCC->CFGR.Fields.SW = 2;
#ifdef MODULE_TEST
		RCC->CFGR.Fields.SWS = 2;
#endif
		while(RCC->CFGR.Fields.SWS != 2);
		if(Config.PLL_SAI_EN != 0)
        {
            RCC->PLLSAI1CFGR.Word = Config.PLL_SAI_Conf;
            RCC->CR.Fields.PLLSAI1ON = 1;
            while(RCC->CR.Fields.PLLSAI1RDY == 0);
            RCC->DCKCFGR2 = 0x08000000;
        }
#endif
	}
}

static inline uint32 RCC_PllFreq(void)
{
    uint32 PllOutput = 0;
    switch(RCC->PLLCFGR.Fields.PLLSRC)
    {
        case 0x0:
            /* No clock */
            break;
        case 0x1:
            PllOutput = MsiFrequencies100kHz[RCC->CR.Fields.MSIRANGE]*100000;
            break;
        case 0x2:
            PllOutput = HSI_CLOCK_FREQUENCY;
            break;
        case 0x3:
            PllOutput = EXTERNAL_OSC_FREQUENCY;
            break;
    }
    PllOutput*=RCC->PLLCFGR.Fields.PLLN;
    PllOutput /= RCC->PLLCFGR.Fields.PLLM+1;
    PllOutput /= 2+ (RCC->PLLCFGR.Fields.PLLR << 2);
    return PllOutput;
}

uint32 RCC_GetClock(dtBus Bus)
{
	uint32 SysClock;
	uint32 AhbClock;
	uint32 Apb1Clock;
	uint32 Apb2Clock;
	switch(RCC->CFGR.Fields.SWS)
	{
	    case 0x0:
#if defined(MCU_L476)
	        /* MSI is selected */
	        SysClock = MsiFrequencies100kHz[RCC->CR.Fields.MSIRANGE]*100000;
#endif
	        break;
	    case 0x1:
#if defined(MCU_L476)
	        /* HSI16 is selected */
	        SysClock = HSI_CLOCK_FREQUENCY;
#endif
	        break;
	    case 0x2:
#if defined(MCU_L476)
	        /* HSE is selected */
	        SysClock = EXTERNAL_OSC_FREQUENCY;
#endif
	        break;
	    case 0x3:
	    {
#if defined(MCU_L476)
	        /* PLL is selected */
	        SysClock = RCC_PllFreq();
#endif
	    }
	        break;
	}

	if((RCC->CFGR.Fields.HPRE & 0x8) == 0) AhbClock = SysClock;
	else AhbClock = SysClock >> AhbPrescalerShiftingValue[RCC->CFGR.Fields.HPRE & 0x8];
	if((RCC->CFGR.Fields.PPRE1 & 0x4) == 0) Apb1Clock = AhbClock;
	else Apb1Clock = AhbClock >> Apb1PrescalerShiftValues[RCC->CFGR.Fields.PPRE1 & 0x4];
    if((RCC->CFGR.Fields.PPRE2 & 0x4) == 0) Apb2Clock = AhbClock;
    else Apb2Clock = AhbClock >> Apb1PrescalerShiftValues[RCC->CFGR.Fields.PPRE2 & 0x4];

	switch(Bus)
	{
	    case Core:
	    case AHB:
	        return AhbClock;
	        break;
	    case APB1_Peripheral:
	        return Apb1Clock;
	        break;
	    case APB1_Timer:
	        return (AhbClock == Apb1Clock) ? Apb1Clock : Apb1Clock*2;
	        break;
	    case APB2_Peripheral:
            return Apb2Clock;
	        break;
	    case APB2_Timer:
	        return (AhbClock == Apb2Clock) ? Apb2Clock : Apb2Clock*2;
	        break;
	    default:
	        return 0xffffffff;
	}
}

void RCC_RTCDomainConfig(dtRCCRtcConfig Config)
{
	RCC->BDCR.Fields.RTC_SEL = Config.RTCClock;
	RCC->BDCR.Fields.RTCEN = Config.RTCClockEnable;
}

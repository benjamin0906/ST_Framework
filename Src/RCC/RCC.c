/*
 * RCC.c
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */


#include "RCC.h"
#include "RCC_RTC.h"
#include "Pwr.h"
#include "Flash.h"
#include "config.h"

#if defined(STM32U0)
#include "RegDefs/RCC_regdef.h"
#elif
#include "RCC_Types.h"
#endif

#if defined(MCU_G070) || defined(STM32U0)
#define HSI_CLOCK_FREQUENCY 16000000
#endif

#ifndef MODULE_TEST
#if defined(MCU_L476) || defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071) || defined(STM32U0)
static dtRCC *const RCC = (dtRCC*) (0x40021000);
#elif defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
static dtRCC *const RCC = (dtRCC*) (0x40023800);
#endif
#else
static dtRCC *const RCC = (dtRCC*)&TestRCC;
#endif

#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(STM32U0)
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

#elif defined(STM32U0)
#define DIVIDER_M_MIN 1
#define DIVIDER_M_MAX 8
#define DIVIDER_R_MIN 2
#define DIVIDER_R_MAX 8
#define MULT_N_MIN 4
#define MULT_N_MAX 127
#define PLL_INPUT_FREQ_MIN	2660000
#define PLL_INPUT_FREQ_MAX	16000000
#define PLL_VCO_FREQ_MIN	96000000
#define PLL_VCO_FREQ_MAX	344000000

/* This table defines the VCore range and Latency of the Flash according to the system frequency */
static const uint8 VCoreLatencyFreqTable[2][3] = {
													{24, 48, 56},
													{8,  16, 18},
};

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

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
uint32 RCC_GetClock(dtBus Bus);
void RCC_RTCDomainConfig(dtRCCRtcConfig Config);
static inline uint32 RCC_PllFreq(void);
void RCC_ClockSet(dtRccInitConfig Config);
void RCC_ClockTreeInit(const dtRccClockTreeCfg config);

static inline void HseOn(void)
{
    dtRCC_CR tCr = RCC->CR;
    tCr.B.HSEON = 1;
    RCC->CR = tCr;
    do
    {
        tCr = RCC->CR;
    }while(tCr.B.HSERDY == 0);
}

static inline void HsiOn(void)
{
    dtRCC_CR tCr = RCC->CR;
    tCr.B.HSION = 1;
    RCC->CR = tCr;
    do
    {
        tCr = RCC->CR;
    }while(tCr.B.HSIRDY == 0);
}

static inline void MsiOn(void)
{
    dtRCC_CR tCr = RCC->CR;
    tCr.B.MSION = 1;
    RCC->CR = tCr;
    do
    {
        tCr = RCC->CR;
    }while(tCr.B.MSIRDY == 0);
}

static inline void LsiOn(void)
{
    dtRCC_CSR tCsr = RCC->CSR;
    tCsr.B.LSION = 1;
    RCC->CSR = tCsr;
    do
    {
        tCsr = RCC->CSR;
    }while(tCsr.B.LSIRDY == 0);
}

static inline void PllOn(uint32 pllCfgr)
{
    dtRCC_CR tCr = RCC->CR;

    /* Disabling PLL before changing settings */
    tCr.B.PLLON = 0;
    RCC->CR = tCr;

    /* Waiting for PLL to be stopped */
    do
    {
        tCr = RCC->CR;
    } while(tCr.B.PLLRDY == 1);

    /* Changing the configuration */
    RCC->PLLCFGR.U = pllCfgr;

    /* Enabling PLL after changing settings */
    tCr.B.PLLON = 1;
    RCC->CR = tCr;

    /* Waiting for PLL to be started */
    do
    {
        tCr = RCC->CR;
    } while(tCr.B.PLLRDY == 0);
}

void RCC_ClockTreeInit(const dtRccClockTreeCfg config)
{
	uint32 sysClock = 0;


	/* Clock Init */
	if(     (config.SysClockCfg == SysClock_HSE)            //if system clock is from external
        ||  (config.PllCfg.B.PLLSRC == PLL_SRC_HSE)         //if pll is from external
		||  (config.RtcClockSel == RTC_SRC_HSE32)           //if RTC is from external
		||  (config.UsbClockSel == USB_SRC_HSE)             //if USB is from external
		)
	{
	    HseOn();
	}
	else
	{
	    if((config.SysClockCfg == SysClock_HSI) || (config.PllCfg.B.PLLSRC == PLL_SRC_HSI))
	    {
	        HsiOn();
	    }
	    else
	    {
	        if((config.SysClockCfg == SysClock_MSI) || (config.PllCfg.B.PLLSRC == PLL_SRC_MSI))
	        {
	            MsiOn();
	        }
	    }
	}

	if(config.LsiClock != 0)
	{
	    LsiOn();
	}

	/* PLL init */
	if(     (config.SysClockCfg == SysClock_PLL)
        ||  (config.UsbClockSel == USB_SRC_PLLQ)
		||  (config.AdcClockSel == ADC_SRC_PLL)
#if defined(STM32G071)
		||  (config.I2SClockSel == I2S_SRC_PLL)
#endif
		)
	{
	    PllOn(config.PllCfg.U);
	}

	switch(config.SysClockCfg)
	{
	case SysClock_HSI:
		sysClock = HSI_CLOCK_FREQUENCY;
		break;
	case SysClock_HSE:
#if defined(HSE_CLOCK_FREQUENCY)
		sysClock = HSE_CLOCK_FREQUENCY
#else
		sysClock = 0;//TODO
#endif
		break;
	case SysClock_PLL:
		sysClock = RCC_GetClock(PllRClock);
		break;
	case SysClock_LSI:
		break;
	case SysClock_LSE:
		break;
#if defined(STM32U0)
	case SysClock_MSI:
	    break;
#endif
	}

#if defined(MCU_G070) || defined(MCU_G071)
		if(sysClock <= 16000000) Pwr_SetVos(2);
		else Pwr_SetVos(1);
		Flash_SetLatency(sysClock);
#elif defined(STM32U0)
		{
			uint8 lLatency = 0;
			uint8 lRange = sizeof(VCoreLatencyFreqTable)/sizeof(VCoreLatencyFreqTable[0]);
			do
			{
				lRange--;
				for(lLatency = 0; (lLatency < sizeof(VCoreLatencyFreqTable[0])) && (sysClock > ((uint32)VCoreLatencyFreqTable[lRange][lLatency]*1000000)); lLatency++);
			}
			while((sysClock > ((uint32)VCoreLatencyFreqTable[lRange][lLatency]*1000000)) && (lRange > 0));
			Pwr_SetVos(lRange+1);
			while(FLASH_SetLatency(lLatency) != E_OK);
		}
#endif
	/* AHB init */
    dtRCC_CFGR tCfgr = {.U = 0};
    dtRCC_CCIPR tCcipr = {.U = 0};

    tCfgr.B.HPRE = config.AhbPrescaler;
    tCfgr.B.PPRE = config.ApbPrescaler;

    tCfgr.B.SW = config.SysClockCfg;
	RCC->CFGR = tCfgr;
	while(RCC->CFGR.B.SWS != config.SysClockCfg);

	tCcipr.B.ADCSEL = config.AdcClockSel;
	tCcipr.B.USART1SEL = config.UsartClockSel;
	tCcipr.B.USART2SEL = config.UsartClockSel;
	RCC->CCIPR = tCcipr;
}

void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value)
{
	uint32 BusId = Clock>>5;
	uint32 ClockMask = 1 << (Clock&0x1F);
	dtClockSetOrClear SetOrClear = Clock_Set;
	dtBusGroup *GroupPtr;

	if((Value == Enable) || (Value == Disable)) GroupPtr = &RCC->ENR;
#if defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_L476) || defined(STM32U0)
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
#elif defined(STM32U0)
    uint32 *Pointer = &GroupPtr->AHB.U + BusId;
#endif
	if(SetOrClear == Clock_Set) *Pointer |= ClockMask;
	else *Pointer &= ClockMask;
}

void RCC_ClockSet(dtRccInitConfig Config)
{
	uint8 Result = 0;
	uint16 DividerM;
	uint16 MultiplierN;
	uint32 ClockFreq;
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
			RCC->CR.B.HSEON = 1;
#ifdef MODULE_TEST
			RCC->CR.B.HSERDY = 1;
#endif
			while(RCC->CR.B.HSERDY == 0);
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
			RCC->PLLCFGR.B.PLLSRC = 1;
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
			RCC->PLLCFGR.B.PLLSRC = 3;
#endif
		}
		else
		{
			RCC->CR.B.HSION = 1;
#ifdef MODULE_TEST
			RCC->CR.B.HSIRDY = 1;
#endif
			while(RCC->CR.B.HSIRDY == 0);
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
			RCC->PLLCFGR.B.PLLSRC = 0;
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
			RCC->PLLCFGR.B.PLLSRC = 2;
#endif
		}

#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
		/* We use the MSI clock, being by default 4MHz, for the PLL so it not need to divide. */
		RCC->PLLCFGR.B.PLLM = DividerM-1;
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
		RCC->PLLCFGR.B.PLLM = DividerM-2;
#endif

		/* 4MHz * 40 = 160 MHz for VCO frequency */
		RCC->PLLCFGR.B.PLLN = MultiplierN-1;
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
		RCC->PLLCFGR.B.PLLP = DividerP-1;
		RCC->PLLCFGR.B.PLLQ = Config.PLL_QDiv;
#elif defined(MCU_G070) || defined(MCU_G071)
		RCC->PLLCFGR.B.PLLR = DividerR-1;
#elif defined(MCU_L476)
		RCC->PLLCFGR.B.PLLR = DividerR-1;
		RCC->PLLCFGR.B.PLLQ = Config.PLL_QDiv;
		RCC->PLLCFGR.B.PLLREN = 1;
#endif
		RCC->CR.B.PLLON = 1;
#ifdef MODULE_TEST
		RCC->CR.B.PLLRDY = 1;
#endif
		while(RCC->CR.B.PLLRDY == 0);

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
		if(Config.APB2_Presc == APB_Presc1) RCC->CFGR.B.PPRE2 = 0;
		else RCC->CFGR.B.PPRE2 = 0x4 | (Config.APB2_Presc-1);

		if(Config.APB1_Presc == APB_Presc1) RCC->CFGR.B.PPRE1 = 0;
		else RCC->CFGR.B.PPRE1 = 0x4 | (Config.APB1_Presc-1);
#elif defined(MCU_G070) || defined(MCU_G071)
		if(Config.APB1_Presc == APB_Presc1) RCC->CFGR.B.PPRE = 0;
		else RCC->CFGR.B.PPRE = 0x4 | (Config.APB1_Presc-1);
#endif
		if(Config.AHB_Presc == AHB_Presc1) RCC->CFGR.B.HPRE = 0;
		else RCC->CFGR.B.HPRE = 0x8 | (Config.AHB_Presc-1);

#if defined(MCU_G070) || defined(MCU_G071)
		RCC->PLLCFGR.B.PLLREN = 1;
#endif

#if defined(MCU_L476)
		RCC->CFGR.B.SW = 3;
		while(RCC->CFGR.B.SWS != 3);
#else
		RCC->CFGR.B.SW = 2;
#ifdef MODULE_TEST
		RCC->CFGR.B.SWS = 2;
#endif
		while(RCC->CFGR.B.SWS != 2);
#if defined(MCU_L433) || defined(MCU_L476)
		if(Config.PLL_SAI_EN != 0)
        {
            RCC->PLLSAI1CFGR.Word = Config.PLL_SAI_Conf;
            RCC->CR.B.PLLSAI1ON = 1;
            while(RCC->CR.B.PLLSAI1RDY == 0);
            RCC->DCKCFGR2 = 0x08000000;
        }
#endif
#endif
	}
}

static inline uint32 RCC_PllFreq(void)
{
    uint32 PllOutput = 0;
    switch(RCC->PLLCFGR.B.PLLSRC)
    {
        case 0x0:
            /* No clock */
            break;
        case 0x1:
#if defined(MCU_L476) || defined(MCU_L433)
            PllOutput = MsiFrequencies100kHz[RCC->CR.B.MSIRANGE]*100000;
#endif
            break;
        case 0x2:
            PllOutput = HSI_CLOCK_FREQUENCY;
            break;
        case 0x3:
            PllOutput = EXTERNAL_OSC_FREQUENCY;
            break;
    }
    PllOutput*=RCC->PLLCFGR.B.PLLN;
    PllOutput /= RCC->PLLCFGR.B.PLLM+1;
    PllOutput /= 2+ (RCC->PLLCFGR.B.PLLR << 2);
    return PllOutput;
}

uint32 RCC_GetClock(dtBus bus)
{
	uint32 ret = 0;
	switch(bus)
	{
	case HsiClock:
		ret = HSI_CLOCK_FREQUENCY;
		break;
	case HseClock:
#if defined (HSE_CLOCK_FREQUENCY)
		ret = HSE_CLOCK_FREQUENCY;
#endif
		break;
	case PllRClock:
		if(RCC->PLLCFGR.B.PLLSRC == PLL_SRC_HSI)
		{
			ret = HSI_CLOCK_FREQUENCY;
		}
		else if(RCC->PLLCFGR.B.PLLSRC == PLL_SRC_HSE)
		{
#if defined (HSE_CLOCK_FREQUENCY)
			ret = HSE_CLOCK_FREQUENCY;
#endif
		}
		ret *= RCC->PLLCFGR.B.PLLN;
		ret /= (RCC->PLLCFGR.B.PLLM + 1);
		ret /= (RCC->PLLCFGR.B.PLLR + 1);
		break;
	case AhbClock:
		ret = RCC_GetClock(SysClock);
		if((RCC->CFGR.B.HPRE & 0x8) != 0)
		{
			ret >>= (RCC->CFGR.B.HPRE & 0x7);
			ret >>= 1;
			if((RCC->CFGR.B.HPRE & 0x4) != 0)
			{
				ret >>= 1;
			}
		}
		break;
	case ApbClock:
		ret = RCC_GetClock(AhbClock);
		if((RCC->CFGR.B.PPRE & 0x4) != 0)
		{
			ret >>= 1;
			ret >>= (RCC->CFGR.B.PPRE & 0x3);
		}
		break;
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
	case ApbTimClock:
		ret = RCC_GetClock(ApbClock);
		if((RCC->CFGR.B.PPRE & 0x4) != 0)
		{
			ret <<= 1;
		}
		break;
#endif
	case SysClock:
		switch(RCC->CFGR.B.SWS)
		{
#if defined(STM32U0)
		case SysClock_MSI:
		    const uint8 rangeTable[] = {1, 2, 4, 8, 16, 24, 32, 48};
		    ret = rangeTable[RCC->CR.B.MSIRANGE];
		    if(RCC->CR.B.MSIRANGE <= 3)
		    {
		        ret *= 100000;
		    }
		    else
		    {
		        ret *= 1000000;
		    }
		    break;
#endif
		case SysClock_HSI: //HSI selected as system clock
			ret = HSI_CLOCK_FREQUENCY;
			break;
		case SysClock_HSE: //HSE selected as system clock
#if defined (HSE_CLOCK_FREQUENCY)
		    ret = HSE_CLOCK_FREQUENCY;
#endif
			break;
		case SysClock_PLL: //PLL selected as system clock
			ret = RCC_GetClock(PllRClock);
			break;
		case SysClock_LSI: //LSI selected as system clock
			break;
		case SysClock_LSE: //LSE selected as system clock
			break;
		}
		break;
	case SysTickClock:
		ret = RCC_GetClock(AhbClock);
		ret >>= 3;
		break;
	}
	return ret;
}

void RCC_RTCDomainConfig(dtRCCRtcConfig Config)
{
	RCC->BDCR.B.RTC_SEL = Config.RTCClock;
	RCC->BDCR.B.RTCEN = Config.RTCClockEnable;
}
#else
#warning "NO CPU IS DEFINED"
#endif

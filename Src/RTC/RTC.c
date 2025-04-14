/*
 * RCC.c
 *
 *  Created on: 2021. febr. 10.
 *      Author: Benjamin
 */

#include "RTC_Types.h"
#include "RTC.h"
#include "RCC_RTC.h"
#include "Pwr_RTC.h"

#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_G070)
static dtRTC *const RTC = (dtRTC*)0x40002800;

void RTC_Init(dtRTCConfig Config);
void RTC_WPUnlock(void);
void RTC_Lock(void);
dtDate RTC_GetDate(void);
dtTime RTC_GetTime(void);
uint8 RTC_SetTime(dtTime Time);
uint8 RTC_SetDate(dtDate Date);
uint8 RTC_SetPeriodicWake(dtRTCWuckSel CkSel, uint16 Value);
void RTC_StopWakeUpTimer(void);
void RTC_ClearInt(dtRTCIntMask Mask);
uint8 RTC_IsIntPending(dtRTCIntMask Mask);

void RTC_Init(dtRTCConfig Config)
{
	/* Allow write the RTC registers */
	Pwr_RtcWp();

	/* Unlock RTC registers */
	RTC_WPUnlock();

	/* Write the RTC clock domain config */
	{
		dtRCCRtcConfig Conf = {.RTCClock = Config.RTCClock, .RTCClockEnable = Config.RTCClockEnable};
		RCC_RTCDomainConfig(Conf);
	}

	/* Start initialization */
#if defined(MCU_G071) || defined(MCU_G070)
	RTC->ICSR.Fields.INIT = 1;
	while(RTC->ICSR.Fields.INITF == 0);
#endif

	dtRTC_PRER PrerTemp;
	PrerTemp.Fields.PREDIV_A = Config.Presc_A;
	PrerTemp.Fields.PREDIV_S = Config.Presc_S;
	RTC->PRER = PrerTemp;

	dtRTC_DR DateTemp = {.Word = 0};
	dtRTC_TR TimeTemp = {.Word = 0};

	DateTemp.Fields.YT = Config.Date.YearTens;
	DateTemp.Fields.YU = Config.Date.YearUnit;
	DateTemp.Fields.MT = Config.Date.MountTens;
	DateTemp.Fields.MU = Config.Date.MountUnits;
	DateTemp.Fields.DT = Config.Date.DayTens;
	DateTemp.Fields.DU = Config.Date.DayUnits;

	TimeTemp.Fields.HT = Config.Time.HourTens;
	TimeTemp.Fields.HU = Config.Time.HourUnits;
	TimeTemp.Fields.MNT = Config.Time.MinTens;
	TimeTemp.Fields.MNU = Config.Time.MinUnits;
	TimeTemp.Fields.ST = Config.Time.SecTens;
	TimeTemp.Fields.SU = Config.Time.SecUnits;

	RTC->DR = DateTemp;
	RTC->TR = TimeTemp;

	RTC->CR.Fields.FMT = Config.Format;
#if defined(MCU_G071) || defined(MCU_G070)
	RTC->ICSR.Fields.INIT = 0;
#endif
	RTC_ClearInt(0x3f);
	RTC_Lock();
}

dtTime RTC_GetTime(void)
{
	dtTime ret;
	ret.HourTens = RTC->TR.Fields.HT;
	ret.HourUnits = RTC->TR.Fields.HU;
	ret.MinTens = RTC->TR.Fields.MNT;
	ret.MinUnits = RTC->TR.Fields.MNU;
	ret.SecTens = RTC->TR.Fields.ST;
	ret.SecUnits = RTC->TR.Fields.SU;
	return ret;
}

dtDate RTC_GetDate(void)
{
	dtDate ret;
	ret.YearTens = RTC->DR.Fields.YT;
	ret.YearUnit = RTC->DR.Fields.YU;
	ret.MountTens = RTC->DR.Fields.MT;
	ret.MountUnits = RTC->DR.Fields.MU;
	ret.DayTens = RTC->DR.Fields.DT;
	ret.DayUnits = RTC->DR.Fields.DU;
	return ret;
}

void RTC_WPUnlock(void)
{
	RTC->WPR.Fields.KEY = 0xCA;
	RTC->WPR.Fields.KEY = 0x53;
}

void RTC_Lock(void)
{
	RTC->WPR.Fields.KEY = 0;
}

uint8 RTC_SetTime(dtTime Time)
{
	uint8 ret = 0;
#if defined(MCU_G071) || defined(MCU_G070)
	if(RTC->ICSR.Fields.INIT == 0)
	{
		/* Unlock RTC registers */
		RTC_WPUnlock();
		RTC->ICSR.Fields.INIT = 1;
	}
	else if(RTC->ICSR.Fields.INITF == 1)
	{
		dtRTC_TR TimeTemp = {.Word = 0};
		TimeTemp.Fields.HT = Time.HourTens;
		TimeTemp.Fields.HU = Time.HourUnits;
		TimeTemp.Fields.MNT = Time.MinTens;
		TimeTemp.Fields.MNU = Time.MinUnits;
		TimeTemp.Fields.ST = Time.SecTens;
		TimeTemp.Fields.SU = Time.SecUnits;
		RTC->TR = TimeTemp;

		RTC->ICSR.Fields.INIT = 0;

		RTC_Lock();
		ret = 1;
	}
#endif
	return ret;
}
uint8 RTC_SetDate(dtDate Date)
{
	uint8 ret = 0;
#if defined(MCU_G071) || defined(MCU_G070)
	if(RTC->ICSR.Fields.INIT == 0)
	{
		/* Unlock RTC registers */
		RTC_WPUnlock();
		RTC->ICSR.Fields.INIT = 1;
	}
	else if(RTC->ICSR.Fields.INITF == 1)
	{
		dtRTC_DR DateTemp = {.Word = 0};
		DateTemp.Fields.YT = Date.YearTens;
		DateTemp.Fields.YU = Date.YearUnit;
		DateTemp.Fields.MT = Date.MountTens;
		DateTemp.Fields.MU = Date.MountUnits;
		DateTemp.Fields.DT = Date.DayTens;
		DateTemp.Fields.DU = Date.DayUnits;
		RTC->DR = DateTemp;

		RTC->ICSR.Fields.INIT = 0;

		RTC_Lock();
		ret = 1;
	}
#endif
	return ret;
}

uint8 RTC_SetPeriodicWake(dtRTCWuckSel CkSel, uint16 Value)
{
	uint8 ret = 0;
#if defined(MCU_G071) || defined(MCU_G070)
	RTC_WPUnlock();
	if(RTC->CR.Fields.WUTE != 0)
	{
		dtRTC_CR TempCR = RTC->CR;
		TempCR.Fields.WUTE = 0;
		RTC->CR = TempCR;
		RTC_Lock();
	}
	else if(RTC->ICSR.Fields.WUTWF != 0)
	{
		dtRTC_SCR tSCR = RTC->SCR;
		dtRTC_CR TempCR = RTC->CR;
		dtRTC_WUTR TempWUTR;

		/* clearing wutf flag */
		tSCR.Fields.CWUTF = 1;
		RTC->SCR = tSCR;

		/* Setting the countdown value */
		TempWUTR.Fields.WUT = Value;
		RTC->WUTR = TempWUTR;

		/* enabling wake up timer, setting its clock and enabling its interrupt */
		TempCR.Fields.WUTIE = 1;
		TempCR.Fields.WUTE = 1;
		TempCR.Fields.WUCKSEL = CkSel;
		RTC->CR = TempCR;

		RTC_Lock();
		ret = 1;
	}
#endif
	return ret;
}

void RTC_StopWakeUpTimer(void)
{
	RTC_WPUnlock();
	dtRTC_CR TempCR = RTC->CR;
	TempCR.Fields.WUTE = 0;
	RTC->CR = TempCR;
	RTC_Lock();
}

void RTC_ClearInt(dtRTCIntMask Mask)
{
#if defined(MCU_G071) || defined(MCU_G070)
	dtRTC_SCR TempScr = {.Word = Mask};
	RTC->SCR = TempScr;
#endif
}

uint8 RTC_IsIntPending(dtRTCIntMask Mask)
{
#if defined(MCU_G071) || defined(MCU_G070)
	return (RTC->SR.Word & Mask) != 0;
#else
	return 0;
#endif
}

void RTC_STAMP_IRQHandler(void)
{
    dtRTC_MISR tMISR = RTC->MISR;
    dtRTC_SCR tSCR = RTC->SCR;
    if(tMISR.Fields.WUTMF)
    {
        tSCR.Fields.CWUTF = 1;
    }
    RTC->SCR = tSCR;
}

#elif defined(STM32U0)
#include "RegDefs/RTC_reg.h"

static dtRTC *const RTC = MODULE_RTC;

void RTC_WPUnlock(void);
void RTC_Lock(void);
void RTC_ClearInt(dtRTCIntMask Mask);

void RTC_Init(dtRTCConfig Config)
{
    /* Allow write the RTC registers */
    Pwr_RtcWp();

    /* Unlock RTC registers */
    RTC_WPUnlock();

    /* Write the RTC clock domain config */
    {
        dtRCCRtcConfig Conf = {.RTCClock = Config.RTCClock, .RTCClockEnable = Config.RTCClockEnable};
        RCC_RTCDomainConfig(Conf);
    }

    /* Start initialization */
    RTC->ICSR.B.INIT = 1;
    while(RTC->ICSR.B.INITF == 0);

    RTC->CALR.B.LPCAL = Config.LpMode;

    dtRTC_PRER PrerTemp = {.U = 0};
    PrerTemp.B.PREDIV_A = Config.Presc_A;
    PrerTemp.B.PREDIV_S = Config.Presc_S;
    RTC->PRER = PrerTemp;

    dtRTC_DR DateTemp = {.U = 0};
    dtRTC_TR TimeTemp = {.U = 0};

    DateTemp.B.YT = Config.Date.YearTens;
    DateTemp.B.YU = Config.Date.YearUnit;
    DateTemp.B.MT = Config.Date.MountTens;
    DateTemp.B.MU = Config.Date.MountUnits;
    DateTemp.B.DT = Config.Date.DayTens;
    DateTemp.B.DU = Config.Date.DayUnits;

    TimeTemp.B.HT = Config.Time.HourTens;
    TimeTemp.B.HU = Config.Time.HourUnits;
    TimeTemp.B.MNT = Config.Time.MinTens;
    TimeTemp.B.MNU = Config.Time.MinUnits;
    TimeTemp.B.ST = Config.Time.SecTens;
    TimeTemp.B.SU = Config.Time.SecUnits;

    RTC->DR = DateTemp;
    RTC->TR = TimeTemp;

    RTC->CR.B.FMT = Config.Format;
    RTC->ICSR.B.BIN = Config.RtcMode;
    RTC->ICSR.B.INIT = 0;
    RTC_ClearInt(0x3f);
    RTC_Lock();
}

/**
 * @brief   Removes the write protection from the RTC registers
 * @details This function writes the WPR register with the correct
 *          values in the proper sequence so that the RTC registers
 *          get unlocked
 * @param   none
 * @retval  none
 * */
void RTC_WPUnlock(void)
{
    RTC->WPR.B.KEY = 0xCA;
    RTC->WPR.B.KEY = 0x53;
}

/**
 * @brief   Activates the write protection of the RTC registers
 * @details This function writes the WPR register with an incorrect
 *          value so that the RTC registers get locked
 * @param   none
 * @retval  none
 * */
void RTC_Lock(void)
{
    RTC->WPR.B.KEY = 0x0;
}

uint8 RTC_SetPeriodicWake(dtRTCWuckSel CkSel, uint16 Value)
{
    uint8 ret = 0;
    RTC_WPUnlock();
    if(RTC->CR.B.WUTE != 0)
    {
        dtRTC_CR TempCR = RTC->CR;
        TempCR.B.WUTE = 0;
        RTC->CR = TempCR;
        RTC_Lock();
    }
    else if(RTC->ICSR.B.WUTWF != 0)
    {
        dtRTC_SCR tSCR = RTC->SCR;
        dtRTC_CR TempCR = RTC->CR;
        dtRTC_WUTR TempWUTR = {.U = 0};

        /* clearing wutf flag */
        tSCR.B.CWUTF = 1;
        RTC->SCR = tSCR;

        /* Setting the countdown value */
        TempWUTR.B.WUT = Value;
        RTC->WUTR = TempWUTR;

        /* enabling wake up timer, setting its clock and enabling its interrupt */
        TempCR.B.WUTIE = 1;
        TempCR.B.WUTE = 1;
        TempCR.B.WUCKSEL = CkSel;
        RTC->CR = TempCR;

        RTC_Lock();
        ret = 1;
    }
    return ret;
}

void RTC_ClearInt(dtRTCIntMask Mask)
{
    dtRTC_SCR TempScr = {.U = Mask};
    RTC->SCR = TempScr;
}

void RTC_StopWakeUpTimer(void)
{
    RTC_WPUnlock();
    dtRTC_CR TempCR = RTC->CR;
    TempCR.B.WUTE = 0;
    RTC->CR = TempCR;
    RTC_Lock();
}

/**
 * @retval  0: the given ISR is not pending
 *          1: the given ISR is pending
 */
uint8 RTC_IsIntPending(dtRTCIntMask Mask)
{
    return (RTC->SR.U & Mask) != 0;
}

#else
#warning "NO CPU IS DEFINED"
#endif

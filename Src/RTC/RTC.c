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

static dtRTC* RTC = (dtRTC*)0x40002800;

void RTC_Init(dtRTCConfig Config);
void RTC_WPUnlock(void);
void RTC_Lock(void);
dtDate RTC_GetDate(void);
dtTime RTC_GetTime(void);
uint8 RTC_SetTime(dtTime Time);
uint8 RTC_SetDate(dtDate Date);
uint8 RTC_SetPeriodicWake(dtRTCWuckSel CkSel, uint16 Value);
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
#if defined(MCU_G071)
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
#if defined(MCU_G071)
	RTC->ICSR.Fields.INIT = 0;
#endif

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
#if defined(MCU_G071)
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
#if defined(MCU_G071)
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
#if defined(MCU_G071)
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
		dtRTC_CR TempCR = RTC->CR;
		dtRTC_WUTR TempWUTR;
		TempWUTR.Fields.WUT = Value;
		RTC->WUTR = TempWUTR;
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

void RTC_ClearInt(dtRTCIntMask Mask)
{
#if defined(MCU_G071)
	dtRTC_SCR TempScr = {.Word = Mask};
	RTC->SCR = TempScr;
#endif
}

uint8 RTC_IsIntPending(dtRTCIntMask Mask)
{
#if defined(MCU_G071)
	return (RTC->SR.Word & Mask) != 0;
#endif
}

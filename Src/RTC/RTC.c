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
dtRTCDate RTC_GetDate(void);
dtRTCTime RTC_GetTime(void);
uint8 RTC_SetTime(dtRTCTime Time);

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
	RTC->ICSR.Fields.INIT = 1;
	while(RTC->ICSR.Fields.INITF == 0);

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

	RTC->ICSR.Fields.INIT = 0;

	RTC_Lock();
}

dtRTCTime RTC_GetTime(void)
{
	dtRTCTime ret;
	ret.HourTens = RTC->TR.Fields.HT;
	ret.HourUnits = RTC->TR.Fields.HU;
	ret.MinTens = RTC->TR.Fields.MNT;
	ret.MinUnits = RTC->TR.Fields.MNU;
	ret.SecTens = RTC->TR.Fields.ST;
	ret.SecUnits = RTC->TR.Fields.SU;
	return ret;
}

dtRTCDate RTC_GetDate(void)
{
	dtRTCDate ret;
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

uint8 RTC_SetTime(dtRTCTime Time)
{
	uint8 ret = 0;
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
	return ret;
}

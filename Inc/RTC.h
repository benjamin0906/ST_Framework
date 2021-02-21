/*
 * RTC.h
 *
 *  Created on: 2021. febr. 12.
 *      Author: Benjamin
 */

#ifndef RTC_H_
#define RTC_H_

#include "types.h"
#include "RCC_RTC.h"

/* This structure stores the members of a data in BCD */
typedef struct
{
	uint32 YearTens		:4;
	uint32 YearUnit		:4;
	uint32 MountTens	:4;
	uint32 MountUnits	:4;
	uint32 DayTens		:4;
	uint32 DayUnits		:4;
} dtRTCDate;

typedef struct
{
	uint32		Format	:1;	//0: 24 hurs; 1: AM-PM
	dtRTCDate	Date;
	dtTime		Time;
	uint32 Presc_A		:7;
	uint32 Presc_S		:15;
	uint32 RTCClock			:2;
	uint32 RTCClockEnable	:1;
} dtRTCConfig;

extern void RTC_Init(dtRTCConfig Config);
extern dtRTCDate RTC_GetDate(void);
extern dtTime RTC_GetTime(void);
extern uint8 RTC_SetTime(dtTime Time);

#endif /* RTC_H_ */

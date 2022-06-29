/*
 * RCC_RTC.h
 *
 *  Created on: 2021. febr. 12.
 *      Author: Benjamin
 */

#ifndef RCC_RTC_H_
#define RCC_RTC_H_

#include "types.h"

enum eRTCClock
{
	RTCClock_No_clock = 0x0,	//No clock
	RTCClock_LSE,
	RTCClock_LSI,
	RTCClock_HSE_div32,
};

typedef struct
{
	uint32 RTCClock			:2;
	uint32 RTCClockEnable	:1;
} dtRCCRtcConfig;

extern void RCC_RTCDomainConfig(dtRCCRtcConfig Config);

#endif /* RCC_RTC_H_ */

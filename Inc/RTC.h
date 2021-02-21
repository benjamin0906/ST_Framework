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

typedef struct
{
	uint32		Format	:1;	//0: 24 hurs; 1: AM-PM
	dtDate		Date;
	dtTime		Time;
	uint32 Presc_A		:7;
	uint32 Presc_S		:15;
	uint32 RTCClock			:2;
	uint32 RTCClockEnable	:1;
} dtRTCConfig;

extern void RTC_Init(dtRTCConfig Config);
extern dtDate RTC_GetDate(void);
extern dtTime RTC_GetTime(void);
extern uint8 RTC_SetTime(dtTime Time);

#endif /* RTC_H_ */

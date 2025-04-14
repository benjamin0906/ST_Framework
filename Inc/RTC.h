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
	/* Mode of the RTC:
	 * 00: BCD mode
	 * 01: Binary mode
	 * 10: Mixed mode */
	uint32 RtcMode          :2;
	uint32 LpMode           :1;
} dtRTCConfig;

typedef enum
{
	RTC_WuckSel_RtcCkDiv16,
	RTC_WuckSel_RtcCkDiv8,
	RTC_WuckSel_RtcCkDiv4,
	RTC_WuckSel_RtcCkDiv2,
	RTC_WuckSel_CkSpreDiv1,
	RTC_WuckSel_CkSpreDiv1Extended = 0x6,
} dtRTCWuckSel;

typedef enum
{
	RTC_IntMask_AlarmA		= 0x01,
	RTC_IntMask_AlarmB		= 0x02,
	RTC_IntMask_WakeUp		= 0x04,
	RTC_IntMask_TmStmp		= 0x08,
	RTC_IntMask_TmStmpOF	= 0x10,
	RTC_IntMask_IntTmStmp	= 0x20,
} dtRTCIntMask;

extern void RTC_Init(dtRTCConfig Config);
extern dtDate RTC_GetDate(void);
extern dtTime RTC_GetTime(void);
extern uint8 RTC_SetTime(dtTime Time);
extern uint8 RTC_SetDate(dtDate Date);
extern uint8 RTC_SetPeriodicWake(dtRTCWuckSel CkSel, uint16 Value);
extern void RTC_StopWakeUpTimer(void);
extern void RTC_ClearInt(dtRTCIntMask Mask);
extern uint8 RTC_IsIntPending(dtRTCIntMask Mask);

#endif /* RTC_H_ */

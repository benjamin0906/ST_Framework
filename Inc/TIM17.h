/*
 * TIM17.h
 *
 *  Created on: 02 01 2025
 *      Author: Bodnár Benjamin
 */

#ifndef TIM17_TIM17_H_
#define TIM17_TIM17_H_

#include "types.h"

typedef enum
{
	Channel_1,
	Channel_2,
} dtTIM17_Ch;

typedef enum eOCMode
{
    Frozen,
    ActiveOnMatch,
    InactiveOnMatch,
    OcToggle,
    ForceInactive,
    ForceActive,
    Pwm1,
    Pwm2,
} dtOutputCompareMode;

typedef enum
{
    TIM17_Prescaler,
	TIM17_AutoReload,
	TIM17_Cmp
} dtTIM17SetTypes;

typedef struct
{
	/* Actual prescaler value is 1+this */
	uint16 Presc;

	/* The counter counts to this value */
	uint16 ARR;

	dtOutputCompareMode OCMode;
	uint32 CC1NEnable :1;
	uint32 CC1NActiveLow :1;
	uint32 CC1PEnable :1;
	uint32 CC1PActiveLow :1;

} dtTim17Cfg;

extern void TIM17_Init(const dtTim17Cfg *const cfg);

#endif /* TIM17_TIM17_H_ */

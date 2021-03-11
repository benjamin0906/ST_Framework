/*
 * GPT.h
 *
 *  Created on: 2021. febr. 25.
 *      Author: Benjamin
 */

#ifndef GPT_H_
#define GPT_H_

#include "types.h"

typedef enum
{
	Instance_TIM15 = 0,
	Instance_TIM16 = 1,
	Instance_TIM17 = 2,
} dtGPTInstance;

typedef struct
{
	uint16 AutoReloadValue;
	uint16 PrescalerValue;
	uint32 AutoRealoadPre :1;
	uint32 OutputCompareMode :4;
	uint32 Ch1NActiveState :1;
	uint32 Ch1NEnable:1;
	uint32 Ch1ActiveState:1;
	uint32 Ch1Enable:1;
	uint32 ClockDiv:2;
} dtGPTConfig;

extern void GPT_Init(dtGPTInstance Instance, dtGPTConfig);
extern void GPT_Start(dtGPTInstance Instance);
extern void GPT_SetCompare(dtGPTInstance Instance, uint16 CompareValue);
extern void GPT_Stop(dtGPTInstance Instance);
extern uint16 GPT_GetCntr(dtGPTInstance Instance);

#endif /* GPT_H_ */

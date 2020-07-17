/*
 * GPT_TIM_Ext_Types.h
 *
 *  Created on: 16 Jul 2020
 *      Author: Bodnár Benjamin
 */

#ifndef ST_FRAMEWORK_SRC_GPT1_GPT_TIM_EXT_TYPES_H_
#define ST_FRAMEWORK_SRC_GPT1_GPT_TIM_EXT_TYPES_H_

#include "types.h"

enum eMode
{
	Timer,
	Oc1,
	Oc2,
	Oc3,
	Oc4,
};

enum eOCMode
{
	Frozen,
	ActiveOnMatch,
	InactiveOnMatch,
	Toggle,
	ForceInactive,
	ForceActive,
	Pwm1,
	Pwm2,
};

typedef struct
{
	uint32 ARR;
	uint32 Presc;
	uint32 Direction	:1;
	uint32 Mode			:3;
	uint32 OCMode		:3;
} dtGPT1Config;

#endif /* ST_FRAMEWORK_SRC_GPT1_GPT_TIM_EXT_TYPES_H_ */

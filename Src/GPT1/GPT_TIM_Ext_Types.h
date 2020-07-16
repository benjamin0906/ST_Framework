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
	OC4,
};

typedef struct
{
	uint32 ARR;
	uint32 Presc;
	uint32 Direction	:1;
	uint32 Mode			:3;
} dtGPT1Config;

#endif /* ST_FRAMEWORK_SRC_GPT1_GPT_TIM_EXT_TYPES_H_ */

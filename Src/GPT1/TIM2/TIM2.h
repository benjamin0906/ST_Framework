/*
 * TIM2.h
 *
 *  Created on: 18 Jul 2020
 *      Author: Bodnár Benjamin
 */

#ifndef ST_FRAMEWORK_SRC_GPT1_TIM2_TIM2_H_
#define ST_FRAMEWORK_SRC_GPT1_TIM2_TIM2_H_

#include "../GPT_TIM_Ext_Types.h"

extern void TIM2_Init(dtGPT1Config Config);
extern void TIM2_MEM_SetValue(dtGPT1SetTypes Type, uint32 Value);

#endif /* ST_FRAMEWORK_SRC_GPT1_TIM2_TIM2_H_ */

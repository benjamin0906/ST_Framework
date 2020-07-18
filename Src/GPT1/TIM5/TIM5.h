/*
 * TIM5.h
 *
 *  Created on: 18 Jul 2020
 *      Author: Bodnár Benjamin
 */

#ifndef ST_FRAMEWORK_SRC_GPT1_TIM5_TIM5_H_
#define ST_FRAMEWORK_SRC_GPT1_TIM5_TIM5_H_

#include "../GPT_TIM_Ext_Types.h"

extern void TIM5_Init(dtGPT1Config Config);
extern void TIM5_SetValue(dtGPT1SetTypes Type, uint32 Value);

#endif /* ST_FRAMEWORK_SRC_GPT1_TIM5_TIM5_H_ */

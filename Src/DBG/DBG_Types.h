/*
 * DBG_Types.h
 *
 *  Created on: 2021. ápr. 8.
 *      Author: Benjamin
 */

#ifndef SRC_DBG_DBG_TYPES_H_
#define SRC_DBG_DBG_TYPES_H_

#include "types.h"

typedef union
{
	uint32 Word;
	struct
	{
		uint32 DEV_ID	:12;
		uint32 			:4;
		uint32 REV_ID	:16;
	} Fields;
} dtDBG_IDCODE;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 				:1;
		uint32 DBG_STOP		:1;
		uint32 DBG_STANDBY	:1;
	} Fields;
} dtDBG_CR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 DBG_TIM2_STOP			:1;
		uint32 DBG_TIM3_STOP			:1;
		uint32 							:2;
		uint32 DBG_TIM6_STOP			:1;
		uint32 DBG_TIM7_STOP			:1;
		uint32 							:4;
		uint32 DBG_RTC_STOP				:1;
		uint32 DBG_WWDG_STOP			:1;
		uint32 DBG_IWDG_STOP			:1;
		uint32 							:8;
		uint32 DBG_I2C1_SMBUS_TIMEOUT	:1;
		uint32 							:8;
		uint32 DBG_LPTIM2_STOP			:1;
		uint32 DBG_LPTIM1_STOP			:1;
	} Fields;
} dtDBG_APB_FZ1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 					:11;
		uint32 DBG_TIM1_STOP	:1;
		uint32 					:3;
		uint32 DBG_TIM14_STOP	:1;
		uint32 DBG_TIM15_STOP	:1;
		uint32 DBG_TIM16_STOP	:1;
		uint32 DBG_TIM17_STOP	:1;
	} Fields;
} dtDBG_APB_FZ2;

typedef struct
{
	dtDBG_IDCODE 	IDCODE;
	dtDBG_CR		DBG_CR;
	dtDBG_APB_FZ1	APB_FZ1;
	dtDBG_APB_FZ2	APB_FZ2;
} dtDBG;

#endif /* SRC_DBG_DBG_TYPES_H_ */

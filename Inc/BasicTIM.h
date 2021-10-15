/*
 * BasicTIM.h
 *
 *  Created on: 3 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef BASICTIM_BASICTIM_H_
#define BASICTIM_BASICTIM_H_

#include "types.h"

typedef enum
{
#if defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
	TIM6 = 0,
#endif
#if defined(MCU_G070) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
	TIM7 = 1,
#endif
} dtBTimId;

typedef struct
{
	uint16 	AutoReload;
	uint16 	Prescaler;
	uint8	UpdateDisable	:1;
	uint8	UpdateSource	:1;
	uint8	OnePulse		:1;
	uint8	ARPreload		:1;
	uint8	Enable			:1;
	uint8	MasterMode		:2;
	uint8   DmaTrig         :1;
} dtBasicTimConfig;

extern void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void));
extern void BasicTIM_SetPS(dtBTimId Id, uint16 Value);
extern void BasicTIM_SetAR(dtBTimId Id, uint16 Value);
extern void BasicTIM_Update(dtBTimId Id);

#endif /* BASICTIM_BASICTIM_H_ */

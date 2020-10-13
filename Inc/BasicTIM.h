/*
 * BasicTIM.h
 *
 *  Created on: 3 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef BASICTIM_BASICTIM_H_
#define BASICTIM_BASICTIM_H_

typedef enum
{
#if defined(MCU_F410) || defined(MCU_G070) || defined(MCU_L433)
	TIM6 = 0,
#endif
#if defined(MCU_G070) || defined(MCU_L433)
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
} dtBasicTimConfig;

extern void BasicTIM_Set(dtBTimId Id, dtBasicTimConfig Config, void (*IrqPtr)(void));

#endif /* BASICTIM_BASICTIM_H_ */

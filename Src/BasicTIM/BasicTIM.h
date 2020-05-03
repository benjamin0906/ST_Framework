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
	TIM6 = 0,
	TIM7 = 1,
} dtBTimId;

extern void BasicTIM_Set(dtBTimId Id, void (*IrqPtr)(void));

#endif /* BASICTIM_BASICTIM_H_ */

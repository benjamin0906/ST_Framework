/*
 * TIM2.h
 *
 *  Created on: May 6, 2020
 *      Author: Bodnár Benjamin
 */

#ifndef TIM2_TIM2_H_
#define TIM2_TIM2_H_

extern void TIM2_Init(void (*PeriodFunction)(void));
extern uint32 TIM2_SetPeriod(uint32 Freq);
extern void TIM2_SetDuty(uint32 duty, uint8 Ch);

#endif /* TIM2_TIM2_H_ */

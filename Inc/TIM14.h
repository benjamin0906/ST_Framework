/*
 * TIM14.h
 *
 *  Created on: 2026. okt. 20.
 *      Author: Benjamin
 */

#ifndef INC_TIM14_H_
#define INC_TIM14_H_

#include "TIM14.h"
#include "NVIC.h"

/*
 * @Precaler    applied prescaler value is this parameter+1
 * @Ar          Compare register, actual period comes from this value + 1
 * @handler     Function called upon ISR event
 * */
void TIM14_Init(uint16 Prescaler, uint16 Ar, void (*handler)(void));

#endif /* INC_TIM14_H_ */

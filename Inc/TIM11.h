/*
 * TIM11.h
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#ifndef TIM11_TIM11_H_
#define TIM11_TIM11_H_

#include "types.h"

extern void TIM11_Init(uint16 Prescaler, uint16 Ar, void (*handler)(void));

#endif /* TIM11_TIM11_H_ */

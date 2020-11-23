/*
 * Utilities.h
 *
 *  Created on: May 9, 2020
 *      Author: Bodnár Benjamin
 */

#ifndef UTILITIES_UTILITIES_H_
#define UTILITIES_UTILITIES_H_

#include "types.h"

extern float32 Power(uint8 Power, float32 Number);
extern uint32 IsPassed(uint32 TimeStamp, uint32 Limit);
extern uint8 StrEq(const uint8 *str1,const uint8 *str2);

#if defined(MCU_F446)
extern float32 sqrt(float32 Number);
#endif

#endif /* UTILITIES_UTILITIES_H_ */

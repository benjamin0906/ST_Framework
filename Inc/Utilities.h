/*
 * Utilities.h
 *
 *  Created on: May 9, 2020
 *      Author: Bodnár Benjamin
 */

#ifndef UTILITIES_UTILITIES_H_
#define UTILITIES_UTILITIES_H_

#include "types.h"
#include "main.h"

extern float32 Power(uint8 Power, float32 Number);
extern uint32 IsPassed(uint32 TimeStamp, uint32 Limit);
extern uint8 StrEq(const uint8 *str1,const uint8 *str2);
extern uint8 StrLen(const uint8 *const str);
extern void Dabler8Bit(uint8 value, uint8 *Digits);
extern uint8 DecStrToNum(uint8 *str, uint8 *num);

#if defined(MCU_F446)
extern float32 sqrt(float32 Number);
#endif

#endif /* UTILITIES_UTILITIES_H_ */

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
#include "Dabler.h"

extern float32 Power(uint8 Power, float32 Number);
extern uint32 IsPassed(uint32 TimeStamp, uint32 Limit);
extern uint8 StrEq(const uint8 *str1,const uint8 *str2);
extern uint8 StrLen(const uint8 *const str);
extern uint8 DecStrToNum(uint8 *str, uint8 *num);
extern uint8 DecStrToNum32(uint8 *str, uint32 *Num);
extern uint32 FloatToQ(uint8 *str, uint8 Q);
extern uint8 NumToHexStr(uint32 Num, uint8 *str);
extern void MemCpyRigth(uint8 *Src, uint8 *Dst, uint32 Length);
extern uint8 UQNumToStr(uint32 Num, uint8 QRes, uint8 QRound, uint8 *Str);

#if defined(MCU_F446)
extern float32 sqrt(float32 Number);
#endif

#endif /* UTILITIES_UTILITIES_H_ */

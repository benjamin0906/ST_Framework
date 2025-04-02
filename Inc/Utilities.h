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
extern uint32 DecStrToNum32(uint8 *str);
extern uint32 FloatToQ(uint8 *str, uint8 Q);
extern uint8 NumToHexStr(uint32 Num, uint8 *str);
extern void MemCpyRigth(const uint8 *const Src, uint8 *const Dst, uint32 Length);
extern uint8 UQNumToStr(uint32 Num, uint8 QRes, uint8 QRound, uint8 *Str);
extern void Delay(uint32 Msec);
extern void BubbleSort(uint32 *array, uint32 len);
extern uint8 FixPNumToStr(uint32 num, uint8 qRes, uint8 fractionalDigits, uint8 *const str);
extern uint8 memEq(uint8 *ptr1, uint8 *ptr2, uint8 size);

#if defined(MCU_F446)
extern float32 sqrt(float32 Number);
extern int64 multiplyArrays(int32 *Array1, int32 *Array2, uint32 length);
extern void memcpy_reverse_8bit(void *src, void *dst, uint32 size);
extern void memcpy_reverse_16bit(void *src, void *dst, uint32 size);
extern void memcpy_reverse_32bit(void *src, void *dst, uint32 size);
extern void memset_32bit(void *array, uint32 value, uint32 size);
#endif

extern void changeEndiannessArray(uint32 *array, uint32 length);

#define STRINGIZING(x) #x

#define saturateI32(inVar, outVar, satBit)      \
    do                                          \
    {                                           \
        asm("sbfx %0, %1, 0, " STRINGIZING(24)  \
            :"=r"(outVar)                       \
            :"r"(inVar)                         \
            :);                                 \
    }                                           \
    while(0);                                   \

#endif /* UTILITIES_UTILITIES_H_ */

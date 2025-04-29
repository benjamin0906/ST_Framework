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
extern uint8 DecStrToNum(uint8 *str, uint8 *num);
extern uint32 DecStrToNum32(uint8 *str);
extern uint32 FloatToQ(uint8 *str, uint8 Q);
extern uint8 NumToHexStr(uint32 Num, uint8 *str);
extern uint8 UQNumToStr(uint32 Num, uint8 QRes, uint8 QRound, uint8 *Str);
extern void Delay(uint32 Msec);
extern void BubbleSort(uint32 *array, uint32 len);
extern uint8 FixPNumToStr(uint32 num, uint8 qRes, uint8 fractionalDigits, uint8 *const str);
extern uint8 memEq(uint8 *ptr1, uint8 *ptr2, uint8 size);

/**
 * @brief   Converts string to uint8
 * @details This function converts two characters from a given string to a 1 byte value
 *          It does not matter is the characters are upper of lower case.
 *          If a character are not valid hex character, its value is skipped
 * @param [in] uint8* str       Array of the characters from which the uint8 value should be
 *                              converted
 * @retval uint8    the converted value
 */
extern uint8 HexStrToNum8(uint8 *str);

#if defined(MCU_F446)
extern float32 sqrt(float32 Number);
#endif
extern int64 multiplyArrays(int32 *Array1, int32 *Array2, uint32 length);

/**
 * @brief   memcpy function in reverse direction
 * @details This function copies data from the first argument to the second argument
 *          in length of the third argument. The function copies the values beginning
 *          at the end of the function
 * @param [in] void *src    - the source pointer from which the data is being copied
 *        [out] void *dst   - the destination pointer to which the data is being copied
 *        [in] uint32 size  - the amount of bytes to be copied
 * @retval none
 */
extern void memcpy_reverse(void *const src, void *const dst, uint32 size);
extern void memcpy_reverse_16bit(void *src, void *dst, uint32 size);
extern void memcpy_reverse_32bit(void *src, void *dst, uint32 size);
extern void memset_32bit(void *array, uint32 value, uint32 size);

extern uint32 strlen(const uint8* const str);

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

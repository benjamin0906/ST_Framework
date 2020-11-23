/*
 * Utilities.c
 *
 *  Created on: May 9, 2020
 *      Author: Bodnár Benjamin
 */

#include "types.h"
#include "main.h"

float32 Power(uint8 Power, float32 Number);
uint32 IsPassed(uint32 TimeStamp, uint32 Limit);
uint8 StrEq(const uint8 *str1,const uint8 *str2);

float32 Power(uint8 Power, float32 Number)
{
	uint8 looper;
	float32 ret = 1;
	for(looper = 0; looper<Power; looper++) ret *= Number;
	return ret;
}

uint32 IsPassed(uint32 TimeStamp, uint32 Limit)
{
	uint32 ret=0;
	uint32 CurrentTicks = GetTicks();
	uint32 PassedTime = CurrentTicks - TimeStamp;
	if(TimeStamp > CurrentTicks) PassedTime = ~PassedTime;
	if(PassedTime > Limit) ret=CurrentTicks;
	return ret;
}

uint8 StrEq(const uint8 *str1,const uint8 *str2)
{
	uint8 ret = 0;
	while((*str1 != 0) && (*str2 != 0) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	if((*str1 == 0) || (*str2 == 0)) ret = 1;
	return ret;
}

#if defined(MCU_F446)
__asm(	".globl sqrt			\n"
		".p2align 2				\n"
		".type sqrt, %function	\n"
		"sqrt:					\n"
		"VSQRT.F32 s0, s0		\n"
		"bx lr					\n");
#endif

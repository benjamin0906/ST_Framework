/*
 * Utilities.c
 *
 *  Created on: May 9, 2020
 *      Author: Bodnár Benjamin
 */

#include "types.h"

float32 Power(uint8 Power, float32 Number)
{
	uint8 looper;
	float32 ret = 1;
	for(looper = 0; looper<Power; looper++) ret *= Number;
	return ret;
}

__asm(	".globl sqrt			\n"
		".p2align 2				\n"
		".type sqrt, %function	\n"
		"sqrt:					\n"
		"VSQRT.F32 s0, s0		\n"
		"bx lr					\n");


/*
 * Utilities.c
 *
 *  Created on: May 9, 2020
 *      Author: Bodnár Benjamin
 */

#include "types.h"
#include "main.h"
#include "Dabler.h"

float32 Power(uint8 Power, float32 Number);
uint32 IsPassed(uint32 TimeStamp, uint32 Limit);
uint8 StrEq(const uint8 *str1,const uint8 *str2);
uint8 StrLen(const uint8 *const str);
uint8 NumToHexStr(uint32 Num, uint8 *str);
uint8 UQNumToStr(uint32 Num, uint8 QRes, uint8 QRound, uint8 *Str);
uint32 FloatToQ(uint8 *str, uint8 Q);

float32 Power(uint8 Power, float32 Number)
{
	uint8 looper;
	float32 ret = 1;
	for(looper = 0; looper<Power; looper++) ret *= Number;
	return ret;
}

uint32 PwrUint32(uint8 Power, uint32 Number)
{
	uint32 Num = 1;
	while(Power != 0)
	{
		Num *= Number;
		Power--;
	}
	return Num;
}

uint32 IsPassed(uint32 TimeStamp, uint32 Limit)
{
	uint32 ret=0;
	uint32 CurrentTicks = GetTicks();
	uint32 PassedTime = CurrentTicks - TimeStamp;
	if(TimeStamp > CurrentTicks) PassedTime = ~PassedTime;
	if(PassedTime >= Limit) ret=CurrentTicks;
	return ret;
}

uint8 StrEq(const uint8 *str1,const uint8 *str2)
{
	uint8 ret = 0;
	while((*str1 != 0) && (*str2 != 0) && (*str1 == *str2))
	{
		str1++;
		str2++;
		ret++;
	}
	//if((*str1 == 0) || (*str2 == 0)) ret = 1;
	return ret;
}

uint8 StrLen(const uint8 *const str)
{
	uint8 ret = 0;
	while(str[ret] != 0) ret++;
	return ret;
}

uint8 NumToHexStr(uint32 Num, uint8 *str)
{
	uint8 ret = 0;
	if(str != 0)
	{
		uint8 looper = 0;
		while(((Num >> 28) == 0) && (looper < 7))
		{
			Num <<= 4;
			looper++;
		}

		do
		{
			uint8 HexDigit = Num >> 28;
			if(HexDigit <= 9) HexDigit += '0';
			else HexDigit += '7';
			*str++ = HexDigit;
			Num <<= 4;
			ret++;
			looper++;
		}
		while((Num != 0) || (looper < 8));
		*str = 0;
	}
	return ret;
}

uint8 DecStrToNum32(uint8 *str, uint32 *num)
{
	uint8 ret = 0;
	if((str != 0) && (num != 0))
	{
		*num = 0;
		while((*str != 0) && (*str >= '0') && (*str <= '9'))
		{
			*num *= 10;
			*num += *str - '0';
			str++;
			ret++;
		}
	}
	return ret;
}

uint8 DecStrToNum(uint8 *str, uint8 *num)
{
	uint8 ret = 0;
	if((str != 0) && (num != 0))
	{
		*num = 0;
		uint8 len = StrLen(str);
		uint8 mult=1;
		do
		{
			len--;
			switch(*(str+len))
			{
			case '0':
				break;
			case '1':
				*num += mult*1;
				break;
			case '2':
				*num += mult*2;
				break;
			case '3':
				*num += mult*3;
				break;
			case '4':
				*num += mult*4;
				break;
			case '5':
				*num += mult*5;
				break;
			case '6':
				*num += mult*6;
				break;
			case '7':
				*num += mult*7;
				break;
			case '8':
				*num += mult*8;
				break;
			case '9':
				*num += mult*9;
				break;
			default:
				ret = 1;
			}
			mult *= 10;
		} while(len != 0);
	}
	else
	{
		ret = 1;
	}
	return ret;
}

uint32 FloatToQ(uint8 *str, uint8 Q)
{
	uint8 PointIndex;
	uint32 Cmpr = 5;
	uint32 Fract = 0;
	uint32 Num = 0;

	/* Getting the whole part */
	PointIndex = DecStrToNum32(str, &Num);

	/* Multiple it with the quotiens factor */
	Num <<= Q;

	/* Rebase string pointer to the start of the fraction part */
	str = &str[PointIndex+1];

	while(Q>0)
	{
		Q--;
		if(*str != 0)
		{
			Fract += *str - '0';
			str++;
		}
		if(Fract >= Cmpr)
		{
			Num += 1 << Q;
			Fract -= Cmpr;
		}
		Cmpr *= 5;
		Fract *= 10;
	}

	/* Rounding */
	if(Fract >= Cmpr) Num += 1;

	return Num;
}

/* Copies the data in length from the Src to the Dst
 * and first the end of the array will be filled
 *
 *        _ _ _ _ _ _ _ _
 * start |_|_|_|_|_|_|_|_| end
 *        | |         | |
 *        n (n-1) ... 2 1
 *        | |         | |
 *        _ _ _ _ _ _ _ _
 *       |_|_|_|_|_|_|_|_|
 *   */
void MemCpyRigth(uint8 *Src, uint8 *Dst, uint32 Length)
{
	while(Length != 0)
	{
		Length--;
		Dst[Length] = Src[Length];
	}
}

uint8 UQNumToStr(uint32 Num, uint8 QRes, uint8 QRound, uint8 *Str)
{
	uint32 WholePart = Num >> QRes;
	uint8 ret = Dabler(WholePart, Str);
	Str += ret;

	if(QRound > 0)
	{
		WholePart = 0;
		*Str++ = '.';
		ret++;

		uint8 Looper = QRound;

		uint32 Mask = 0xFFFFFFFF;
		Mask <<= 32 - QRes;
		Mask >>= 32 - QRes;

		Num &= Mask;

		while(Looper > 0)
		{
			Looper--;
			Num *= 10;
			uint8 NumToRound = Num >> (QRes-1);

			if(Looper == 0)
			{
				if((NumToRound & 1) != 0) NumToRound += 0x2;
			}

			WholePart *= 10;

			WholePart += NumToRound>>1;

			Num &= Mask;
		}
		int8 shift;

		uint8 Length = Dabler(WholePart, Str);

		MemCpyRigth(Str, Str+(QRound - Length), QRound);

		while(Length < QRound)
		{
			*Str++ = '0';
			Length++;
		}
		ret += Length;
	}
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

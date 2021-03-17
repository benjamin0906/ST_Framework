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
uint8 StrLen(const uint8 *const str);
uint8 NumToHexStr(uint16 Num, uint8 *StrBuf);
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

uint8 Dabler8Bit(uint8 value, uint8 *Digits)
{
    uint32 bcd = 0;
    uint8 DigitNum = 8;
    uint8 looper = 0;
    for(looper = 0; looper < 8; looper++)
    {
        if((bcd & 0xF) >= 5) bcd += 3;
        if((bcd & 0xF0) >= 0x50) bcd += 0x30;
        if((bcd & 0xF00) >= 0x500) bcd += 0x300;
        bcd<<=1;
        if((value&0x80) != 0) bcd |= 1;
        value <<= 1;

    }

    if((bcd&0xF0000000) == 0)
    {
        DigitNum--;
        if((bcd&0x0F000000) == 0)
        {
            DigitNum--;
            if((bcd&0x00F00000) == 0)
            {
                DigitNum--;
                if((bcd&0x000F0000) == 0)
                {
                    DigitNum--;
                    if((bcd&0x0000F000) == 0)
                    {
                        DigitNum--;
                        if((bcd&0x00000F00) == 0)
                        {
                            DigitNum--;
                            if((bcd&0x000000F0) == 0) DigitNum--;
                        }
                    }
                }
            }
        }
    }

    looper = 0;
    do
    {
        Digits[looper] = '0';
        switch (DigitNum)
        {
        case 8:
            Digits[looper] += bcd>>28;
            break;
        case 7:
            Digits[looper] += (bcd>>24)&0xF;
            break;
        case 6:
            Digits[looper] += (bcd>>20)&0xF;
            break;
        case 5:
            Digits[looper] += (bcd>>16)&0xF;
            break;
        case 4:
            Digits[looper] += (bcd>>12)&0xF;
            break;
        case 3:
            Digits[looper] += (bcd>>8)&0xF;
            break;
        case 2:
            Digits[looper] += (bcd>>4)&0xF;
            break;
        case 1:
            Digits[looper] += (bcd)&0xF;
            break;
        }
        looper++;
        DigitNum--;
    } while(DigitNum != 0);
    Digits[looper] = 0;

    return looper;
}

uint8 Dabler16Bit(uint16 value, uint8 *Digits)
{
    uint32 bcd = 0;
    uint8 DigitNum = 8;
    uint8 looper = 0;
    for(looper = 0; looper < 16; looper++)
    {
        if((bcd & 0xF) >= 5) bcd += 3;
        if((bcd & 0xF0) >= 0x50) bcd += 0x30;
        if((bcd & 0xF00) >= 0x500) bcd += 0x300;
        if((bcd & 0xF000) >= 0x5000) bcd += 0x3000;
        if((bcd & 0xF0000) >= 0x50000) bcd += 0x30000;
        if((bcd & 0xF00000) >= 0x500000) bcd += 0x300000;
        bcd<<=1;
        if((value&0x8000) != 0) bcd |= 1;
        value <<= 1;
    }

    if((bcd&0xF0000000) == 0)
    {
        DigitNum--;
        if((bcd&0x0F000000) == 0)
        {
            DigitNum--;
            if((bcd&0x00F00000) == 0)
            {
                DigitNum--;
                if((bcd&0x000F0000) == 0)
                {
                    DigitNum--;
                    if((bcd&0x0000F000) == 0)
                    {
                        DigitNum--;
                        if((bcd&0x00000F00) == 0)
                        {
                            DigitNum--;
                            if((bcd&0x000000F0) == 0) DigitNum--;
                        }
                    }
                }
            }
        }
    }

    looper = 0;
    do
    {
        Digits[looper] = '0';
        switch (DigitNum)
        {
        case 8:
            Digits[looper] += bcd>>28;
            break;
        case 7:
            Digits[looper] += (bcd>>24)&0xF;
            break;
        case 6:
            Digits[looper] += (bcd>>20)&0xF;
            break;
        case 5:
            Digits[looper] += (bcd>>16)&0xF;
            break;
        case 4:
            Digits[looper] += (bcd>>12)&0xF;
            break;
        case 3:
            Digits[looper] += (bcd>>8)&0xF;
            break;
        case 2:
            Digits[looper] += (bcd>>4)&0xF;
            break;
        case 1:
            Digits[looper] += (bcd)&0xF;
            break;
        }
        looper++;
        DigitNum--;
    } while(DigitNum != 0);
    Digits[looper] = 0;
    return looper;
}

uint8 NumToHexStr(uint16 Num, uint8 *StrBuf)
{
	int8 looper;
	uint8 Index = 0;
	for(looper = 12; looper >= 0; looper -= 4, Index++)
	{
		uint8 temp = Num>>looper;
		if(temp <= 9) StrBuf[Index] = '0'+temp;
		else if(temp <= 0xF) StrBuf[Index] = '7'+temp;
	}
	return Index;
}

uint8 DecStrToNum32(uint8 *str, uint32 *num)
{
	uint8 ret = 0;
	if((str != 0) && (num != 0))
	{
		uint8 mult=1;
		while((*str != 0) && (*str >= '0') && (*str <= '9'))
		{
			switch(*str)
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
				break;
			}
			mult *= 10;
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

	uint8 Length = 0;

	Length = Dabler16Bit(WholePart, Str);

	Str += Length - QRound;

	MemCpyRigth(Str, Str+1, QRound);

	*Str = '.';

	return Length+1;
}

#if defined(MCU_F446)
__asm(	".globl sqrt			\n"
		".p2align 2				\n"
		".type sqrt, %function	\n"
		"sqrt:					\n"
		"VSQRT.F32 s0, s0		\n"
		"bx lr					\n");
#endif

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

void Dabler8Bit(uint8 value, uint8 *Digits)
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
}

void Dabler16Bit(uint16 value, uint8 *Digits)
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
}

#if defined(MCU_F446)
__asm(	".globl sqrt			\n"
		".p2align 2				\n"
		".type sqrt, %function	\n"
		"sqrt:					\n"
		"VSQRT.F32 s0, s0		\n"
		"bx lr					\n");
#endif

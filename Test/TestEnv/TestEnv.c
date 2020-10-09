/*
 * TestEnv.c
 *
 *  Created on: 2020. okt. 2.
 *      Author: BodnarB
 */

#include "RCC_Types.h"
#include "Flash_Types.h"
#include "Pwr_Types.h"
#include "BasicTIM_Types.h"
#include "stdio.h"

int PassedTests;
int FailedTests;
dtRCC TestRCC;
dtFlash TestFlash;
dtPwr TestPwr;
#if defined(MCU_F410)
dtBasicTIM TestBasicTIM6;
#elif #elif defined(MCU_G070)
dtBasicTIM TestBasicTIM[2];
#endif
unsigned char PowerSupplyVoltage = 33;

void TestAssert_eq(int value1, int value2, char const* filename,int line, char const* function_name)
{
	if(value1 == value2)
	{
#ifndef SILENT
		printf("Test Passed: %s:%d %s()\n",filename,line, function_name);
#endif
		PassedTests++;
	}
	else
	{
		printf("Test failed: %s:%d %s(); %d, %d\n",filename,line, function_name, value1, value2);
		FailedTests++;
	}
}

void TestAssert_le(int value1, int value2, char const* filename,int line, char const* function_name)
{
	if(value1 <= value2)
	{
#ifndef SILENT
		printf("Test Passed: %s:%d %s()\n",filename,line, function_name);
#endif
		PassedTests++;
	}
	else
	{
		printf("Test failed: %s:%d %s(); %d, %d\n",filename,line, function_name, value1, value2);
		FailedTests++;
	}
}

void TestAssert_ge(int value1, int value2, char const* filename,int line, char const* function_name)
{
	if(value1 >= value2)
	{
#ifndef SILENT
		printf("Test Passed: %s:%d %s()\n",filename,line, function_name);
#endif
		PassedTests++;
	}
	else
	{
		printf("Test failed: %s:%d %s(); %d, %d\n",filename,line, function_name, value1, value2);
		FailedTests++;
	}
}

void MemClear(unsigned char *pointer, int size)
{
	int looper;
	for(looper = 0; looper < size; looper++)
	{
		pointer[looper] = 0;
	}
}

/*
 * TestEnv.c
 *
 *  Created on: 2020. okt. 2.
 *      Author: BodnarB
 */

#include "RCC_Types.h"
#include "Flash_Types.h"
#include "stdio.h"

int PassedTests;
int FailedTests;
dtRCC TestRCC;
dtFlash TestFlash;

void TestAssert(int value1, int value2, char const* filename,int line, char const* function_name)
{
	if(value1 == value2)
	{
		printf("Test Passed: %s:%d %s()\n",filename,line, function_name);
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

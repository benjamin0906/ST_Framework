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

void ASSERT(int value,char const* filename,int line, char const* function_name)
{
	if(value != 0)
	{
		printf("Test Passed: %s:%d %s()\r\n",filename,line, function_name);
		PassedTests++;
	}
	else
	{
		printf("Test failed: %s:%d %s()\r\n",filename,line, function_name);
		FailedTests++;
	}
}

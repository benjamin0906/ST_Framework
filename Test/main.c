/*
 ============================================================================
 Name        : asd.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "TestEnv.h"

extern void PrintSomething(void);
extern void RCC_TestCase_1(void);
extern void RCC_TestCase_2(void);
extern void RCC_TestCase_3(void);
extern void BasicTIM_Test(void);

int main(void)
{
	RCC_TestCase_1();
	RCC_TestCase_2();
	RCC_TestCase_3();
	BasicTIM_Test();
	printf("PASSED TESTS: %i\n", PassedTests);
	printf("FAILED TESTS: %i\n", FailedTests);
	return EXIT_SUCCESS;
}

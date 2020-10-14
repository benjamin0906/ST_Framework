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
#include "RCC_Test.h"
#include "GPIO_Test.h"
#include "BasicTIM_Test.h"

extern void BasicTIM_Test_TC1(void);

int main(void)
{
	RCC_Test();
	GPIO_Test();
	BasicTIM_Test();
	printf("PASSED TESTS: %u\n", PassedTests);
	printf("FAILED TESTS: %u\n", FailedTests);
	return EXIT_SUCCESS;
}

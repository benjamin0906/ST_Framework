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

extern void BasicTIM_Test(void);

int main(void)
{
	RCC_Test();
	//BasicTIM_Test();
	printf("PASSED TESTS: %u\n", PassedTests);
	printf("FAILED TESTS: %u\n", FailedTests);
	return EXIT_SUCCESS;
}

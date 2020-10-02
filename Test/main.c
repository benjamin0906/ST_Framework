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

int main(void) {
#ifdef MODULE_TEST
puts("mukodik!!");
#else
	puts("!!!Hello Worlddd!!!");
#endif
	//PrintSomething();
	RCC_TestCase_1();
	puts("!!!Hello World!!!");
	return EXIT_SUCCESS;
}

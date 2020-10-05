/*
 * TestEnv.h
 *
 *  Created on: 2020. okt. 2.
 *      Author: BodnarB
 */

#ifndef TEST_TESTENV_TESTENV_H_
#define TEST_TESTENV_TESTENV_H_

extern int PassedTests;
extern int FailedTests;
extern void TestAssert(int value1, int value2, char const* filename,int line, char const* function_name);
extern void MemClear(unsigned char *pointer, int size);

#define ASSERT(a,b) TestAssert(a,b,__FILE__, __LINE__, __func__)

#if defined(RCC_RCC_TYPES_H_) || defined(TEST_CASE)
#include "RCC_Types.h"
#include "RCC.h"
extern dtRCC TestRCC;
#endif
#if defined(FLASH_FLASH_TYPES_H_) || defined(TEST_CASE)
#include "Flash_Types.h"
extern dtFlash TestFlash;
#endif
#if defined(PWR_PWR_TYPES_H_) || defined(TEST_CASE)
#include "Pwr_Types.h"
dtPwr TestPwr;
#endif
#endif /* TEST_TESTENV_TESTENV_H_ */

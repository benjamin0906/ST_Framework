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
extern unsigned char PowerSupplyVoltage;
extern void TestAssert_eq(int value1, int value2, char const* filename,int line, char const* function_name);
extern void TestAssert_le(int value1, int value2, char const* filename,int line, char const* function_name);
extern void TestAssert_ge(int value1, int value2, char const* filename,int line, char const* function_name);
extern void MemClear(unsigned char *pointer, int size);

#define ASSERT_EQ(a,b) TestAssert_eq(a,b,__FILE__, __LINE__, __func__)
#define ASSERT_LE(a,b) TestAssert_le(a,b,__FILE__, __LINE__, __func__)
#define ASSERT_GE(a,b) TestAssert_ge(a,b,__FILE__, __LINE__, __func__)

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
extern dtPwr TestPwr;
#endif
#if defined(BASICTIM_BASICTIM_TYPES_H_) || defined(TEST_CASE)
#include "BasicTIM_Types.h"
#include "BasicTIM.h"
#if defined(MCU_F410)
extern dtBasicTIM TestBasicTIM6;
#elif defined(MCU_G070) || defined(MCU_L433)
extern dtBasicTIM TestBasicTIM6;
extern dtBasicTIM TestBasicTIM7;
#endif
#endif
#if defined(GPIO_GPIO_TYPES_H_) || defined(TEST_CASE_GPIO)
#include "GPIO_Types.h"
#include "GPIO.h"
extern dtGPIO		TestGPIOA;
extern dtGPIO		TestGPIOB;
extern dtGPIO		TestGPIOC;
extern dtGPIO		TestGPIOD;
extern dtGPIO		TestGPIOE;
extern dtGPIO		TestGPIOF;
extern dtGPIO		TestGPIOG;
extern dtGPIO		TestGPIOH;
#endif
#if defined(NVIC_NVIC_TYPES_H_) || defined(TEST_CASE)
#include "NVIC_Types.h"
extern dtISER		TestISER;
extern dtICER		TestICER;
extern dtISPR		TestISPR;
extern dtICPR		TestICPR;
extern dtIABR		TestIABR;
extern dtIPR		TestIPR;
#endif
#endif /* TEST_TESTENV_TESTENV_H_ */

/*
 * TestEnv.h
 *
 *  Created on: 2020. okt. 2.
 *      Author: BodnarB
 */

#ifndef TEST_TESTENV_TESTENV_H_
#define TEST_TESTENV_TESTENV_H_

extern void ASSERT(int value,char const* filename,int line, char const* function_name);

#define TEST_CHECK(a) ASSERT(a,__FILE__, __LINE__, __func__)

#ifdef RCC_RCC_TYPES_H_
extern dtRCC TestRCC;
#endif
#ifdef FLASH_FLASH_TYPES_H_
extern dtFlash TestFlash;
#endif

#endif /* TEST_TESTENV_TESTENV_H_ */

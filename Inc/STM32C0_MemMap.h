/*
 * STM32C0_MemMap.h
 *
 *  Created on: Sep 4, 2026
 *      Author: GitHub Copilot
 */

#ifndef INC_STM32C0_MEMMAP_H_
#define INC_STM32C0_MEMMAP_H_

#include "RegDefs/STM32C0_GPIO_regdef.h"
#include "RegDefs/STM32C0_TIM14_regdef.h"

#if defined(STM32C0)

#define GPIOA_BASE (0x50000000UL)
#define GPIOB_BASE (0x50000400UL)
#define GPIOC_BASE (0x50000800UL)
#define GPIOD_BASE (0x50000C00UL)
#define GPIOF_BASE (0x50001400UL)

#define TIM14_BASE (0x40002000UL)

#define GPIO_C0  ((volatile dtGPIO_C0 *const)GPIOA_BASE)
#define GPIOA_C0 (&GPIO_C0->GPIOA)
#define GPIOB_C0 (&GPIO_C0->GPIOB)
#define GPIOC_C0 (&GPIO_C0->GPIOC)
#define GPIOD_C0 (&GPIO_C0->GPIOD)
#define GPIOF_C0 (&GPIO_C0->GPIOF)

#define TIM14_C0 ((volatile dtTIM14_C0 *const)TIM14_BASE)

#endif

#endif /* INC_STM32C0_MEMMAP_H_ */
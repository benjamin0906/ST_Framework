/*
 * RCC.h
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef RCC_RCC_H_
#define RCC_RCC_H_

#include "types.h"

typedef enum
{
	RCC_GPIOA 	= 0,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOE,
	RCC_GPIOF,
	RCC_GPIOG,
	RCC_GPIOH 	= 7,
	RCC_CRC		= 12,
	RCC_BKPSRAMEN	= 18,
	RCC_DMA1	= 21,
	RCC_DMA2	= 22,
	RCC_RNG		= 31,
	RCC_TIM5	= 32,
	RCC_TIM6	= 33,
	RCC_LPTIM1	= 38,
	RCC_WWDG	= 40,
	RCC_SPI2	= 46,
	RCC_USART2	= 49,
	RCC_I2C1	= 53,
	RCC_I2C2	= 54,
	RCC_I2C4	= 56,
	RCC_PWR		= 60,
	RCC_DAC		= 61,
	RCC_TIM1	= 64,
	RCC_USART1	= 68,
	RCC_USART6	= 69,
	RCC_ADC1	= 72,
	RCC_SPI1	= 76,
	RCC_SYSCFG	= 78,
	RCC_TIM9	= 80,
	RCC_TIM11	= 82,
	RCC_SPI5	= 84,
} dtRCCClock;

typedef enum
{
	Enable = 0,
	Disable,
	LpEnable,
	LpDisable,
	Reset,
} dtRCCClockSets;

typedef enum
{
	APB1_Peripheral,
	APB1_Timer,
	APB2_Peripheral,
	APB2_Timer,
	AHB,
	Core,
} dtBus;

extern void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
extern void RCC_ClockInit(void);
extern uint32 RCC_GetClock(dtBus Bus);

#endif /* RCC_RCC_H_ */

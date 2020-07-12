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
#if defined(MCU_F410)
	RCC_BKPSRAMEN	= 18,
#endif
	RCC_DMA1	= 21,
	RCC_DMA2	= 22,
#if defined(MCU_F446)
	RCC_OTGHS	= 29,
#endif
#if defined(MCU_F410)
	RCC_RNG		= 31,
#endif
#if defined(MCU_F446)
	RCC_DCMI	= 32,
	RCC_OTGFS	= 39,
	RCC_FMC		= 64,
	RCC_QSPI	= 65,
	RCC_TIM2	= 128,
	RCC_TIM3	= 129,
	RCC_TIM4	= 130,
#endif
	RCC_TIM5	= 131,
	RCC_TIM6	= 132,
#if defined(MCU_F446)
	RCC_TIM7	= 133,
	RCC_TIM12	= 134,
	RCC_TIM13	= 135,
	RCC_TIM14	= 136,
#endif
#if defined(MCU_F410)
	RCC_LPTIM1	= 137,
#endif
	RCC_WWDG	= 139,
	RCC_SPI2	= 142,
#if defined(MCU_F446)
	RCC_SPI3	= 143,
	RCC_SPDIFRX = 144,
#endif
	RCC_USART2	= 145,
#if defined(MCU_F446)
	RCC_USART3	= 146,
	RCC_USART4	= 147,
	RCC_USART5	= 148,
#endif
	RCC_I2C1	= 149,
	RCC_I2C2	= 150,
#if defined(MCU_F446)
	RCC_I2C3	= 151,
#endif
#if defined(MCU_F410)
	RCC_I2C4	= 152,
#endif
#if defined(MCU_F446)
	RCC_FMPI2C1	= 153,
	RCC_CAN1	= 154,
	RCC_CAN2	= 155,
	RCC_CEC		= 156,
#endif
	RCC_PWR		= 157,
	RCC_DAC		= 155,
	RCC_TIM1	= 160,
#if defined(MCU_F446)
	RCC_TIM8	= 161,
#endif
	RCC_USART1	= 164,
	RCC_USART6	= 165,
	RCC_ADC1	= 168,
#if defined(MCU_F446)
	RCC_SDIO	= 171,
#endif
	RCC_SPI1	= 172,
#if defined(MCU_F446)
	RCC_SPI4	= 173,
#endif
	RCC_SYSCFG	= 174,
	RCC_TIM9	= 176,
	RCC_TIM11	= 178,
	//RCC_SPI5	= 84,
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

enum
{
	Crystal		= 0,
	Internal	= 1,
} eCrystalOrInternal;

enum
{
	APB_Presc1 = 0,
	APB_Presc2 = 1,
	APB_Presc4 = 2,
	APB_Presc8 = 3,
	APB_Presc16 = 4,
} eAPBPresc;

enum
{
	AHB_Presc1		= 0,
	AHB_Presc2		= 1,
	AHB_Presc4		= 2,
	AHB_Presc8		= 3,
	AHB_Presc16		= 4,
	AHB_Presc64		= 5,
	AHB_Presc128	= 6,
	AHB_Presc256	= 7,
	AHB_Presc512	= 8,
} eAHBPresc;

typedef struct
{
	uint32 Clock;
	uint32 CrystalOrInternal	:1;
	uint32 APB2_Presc			:3;	//max 90MHz
	uint32 APB1_Presc			:3;	//max 45MHz
	uint32 AHB_Presc			:4;
} dtRccInitConfig;

extern void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
extern void RCC_ClockSet(dtRccInitConfig Config);
extern uint32 RCC_GetClock(dtBus Bus);

#endif /* RCC_RCC_H_ */

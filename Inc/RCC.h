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
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_G070)
	RCC_GPIOA 	= 0,
#endif
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_G070)
	RCC_GPIOB	= 1,
#endif
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_G070)
	RCC_GPIOC	= 2,
#endif
#if defined(MCU_F446) || defined(MCU_G070)
	RCC_GPIOD	= 3,
#endif
#if defined(MCU_F446)
	RCC_GPIOE	= 4,
#endif
#if defined(MCU_F446) || defined(MCU_G070)
	RCC_GPIOF	= 5,
#endif
#if defined(MCU_F446)
	RCC_GPIOG	= 6,
#endif
#if defined(MCU_F410) || defined(MCU_F446)
	RCC_GPIOH 	= 7,
#endif
#if defined(MCU_F410) || defined(MCU_F446)
	RCC_CRC		= 12,
#endif
#if defined(MCU_F410) || defined(MCU_F446)
	RCC_DMA1	= 21,
#endif
#if defined(MCU_F410) || defined(MCU_F446)
	RCC_DMA2	= 22,
#endif
#if defined(MCU_F446)
	RCC_OTGHS	= 29,
#endif
#if defined(MCU_F410)
	RCC_RNG		= 31,
#endif
#if defined(MCU_F446)
	RCC_DCMI	= 32,
#elif defined(MCU_G070)
	RCC_DMA		= 32,
#endif
#if defined(MCU_G070)
	RCC_FLASH	= 40,
#endif
#if defined(MCU_G070)
	RCC_CRC		= 44,
#endif
#if defined(MCU_F446)
	RCC_FMC		= 64,
#endif
#if defined(MCU_F446)
	RCC_QSPI	= 65,
#elif defined(MCU_G070)
	RCC_TIM3	= 65,
#endif
#if defined(MCU_G070)
	RCC_TIM6	= 68,
#endif
#if defined(MCU_G070)
	RCC_TIM7	= 69,
#endif
#if defined(MCU_G070)
	RCC_SPI2	= 78,
#endif
#if defined(MCU_G070)
	RCC_USART2	= 81,
#endif
#if defined(MCU_G070)
	RCC_USART3	= 82,
#endif
#if defined(MCU_G070)
	RCC_USART4	= 83,
#endif
#if defined(MCU_G070)
	RCC_I2C1	= 85,
#endif
#if defined(MCU_G070)
	RCC_I2C2	= 86,
#endif
#if defined(MCU_G070)
	RCC_DBG		= 91,
#endif
#if defined(MCU_G070)
	RCC_PWR		= 92,
#endif
#if defined(MCU_G070)
	RCC_SYSCFG	= 96,
#endif
#if defined(MCU_G070)
	RCC_TIM1	= 107,
#endif
#if defined(MCU_G070)
	RCC_SPI1	= 108,
#endif
#if defined(MCU_G070)
	RCC_USART1	= 110,
#endif
#if defined(MCU_G070)
	RCC_TIM14	= 111,
#endif
#if defined(MCU_G070)
	RCC_TIM15	= 112,
#endif
#if defined(MCU_G070)
	RCC_TIM16	= 113,
#endif
#if defined(MCU_G070)
	RCC_TIM17	= 114,
#endif
#if defined(MCU_G070)
	RCC_ADC		= 116,
#endif
#if defined(MCU_F446)
	RCC_TIM2	= 128,
#endif
#if defined(MCU_F446)
	RCC_TIM3	= 129,
#endif
#if defined(MCU_F446)
	RCC_TIM4	= 130,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_TIM5	= 131,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_TIM6	= 132,
#endif
#if defined(MCU_F446)
	RCC_TIM7	= 133,
#endif
#if defined(MCU_F446)
	RCC_TIM12	= 134,
#endif
#if defined(MCU_F446)
	RCC_TIM13	= 135,
#endif
#if defined(MCU_F446)
	RCC_TIM14	= 136,
#endif
#if defined(MCU_F410) || defined(MCU_F410)
	RCC_LPTIM1	= 137,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_WWDG	= 139,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_SPI2	= 142,
#endif
#if defined(MCU_F446)
	RCC_SPI3	= 143,
#endif
#if defined(MCU_F446)
	RCC_SPDIFRX = 144,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_USART2	= 145,
#endif
#if defined(MCU_F446)
	RCC_USART3	= 146,
#endif
#if defined(MCU_F446)
	RCC_USART4	= 147,
#endif
#if defined(MCU_F446)
	RCC_USART5	= 148,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_I2C1	= 149,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_I2C2	= 150,
#endif
#if defined(MCU_F446)
	RCC_I2C3	= 151,
#endif
#if defined(MCU_F410)
	RCC_I2C4	= 152,
#elif defined(MCU_F446)
	RCC_FMPI2C1	= 152,
#endif
#if defined(MCU_F446)
	RCC_CAN1	= 153,
#endif
#if defined(MCU_F446)
	RCC_CAN2	= 154,
#endif
#if defined(MCU_F446)
	RCC_CEC		= 155,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_PWR		= 156,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_DAC		= 157,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_TIM1	= 160,
#endif
#if defined(MCU_F446)
	RCC_TIM8	= 161,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_USART1	= 164,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_USART6	= 165,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_ADC1	= 168,
#endif
#if defined(MCU_F446)
	RCC_SDIO	= 171,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_SPI1	= 172,
#endif
#if defined(MCU_F446)
	RCC_SPI4	= 173,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_SYSCFG	= 174,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_TIM9	= 176,
#endif
#if defined(MCU_F446)
	RCC_TIM10	= 177,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	RCC_TIM11	= 178,
#endif
#if defined(MCU_F410)
	RCC_SPI5	= 180,
#endif
#if defined(MCU_F446)
	RCC_SAI1	= 182,
#endif
#if defined(MCU_F446)
	RCC_SAI2	= 183,
#endif
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
#if defined(MCU_F446) || defined(MCU_F410)
	APB2_Peripheral,
	APB2_Timer,
#endif
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
#if defined(MCU_F446) || defined(MCU_F410)
	uint32 APB2_Presc			:3;	//max 90MHz
#endif
	uint32 APB1_Presc			:3;	//max 45MHz
	uint32 AHB_Presc			:4;
	uint32 CrystalClockFreq;
} dtRccInitConfig;

extern void RCC_ClockEnable(dtRCCClock Clock, dtRCCClockSets Value);
extern void RCC_ClockSet(dtRccInitConfig Config);
extern uint32 RCC_GetClock(dtBus Bus);

#endif /* RCC_RCC_H_ */

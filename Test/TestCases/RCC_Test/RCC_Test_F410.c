/*
 * RCC_TestCase_1.c
 *
 *  Created on: 2020. okt. 2.
 *      Author: BodnarB
 */
#define TEST_CASE
#include "TestEnv.h"

void RCC_TestCase_1(void);
void RCC_TestCase_2(void);
void RCC_TestCase_3(void);
int AHB_Calc(int clock);
int APB1_Per_Calc(int clock);
int APB1_Tim_Calc(int clock);
int APB2_Per_Calc(int clock);
int APB2_Tim_Calc(int clock);
void LatencyCheck(int clock);

/*
 * This test case tests the various enabling and disabling of the peripherals
 */
void RCC_TestCase_1(void)
{
	/********************************/
	/* Test of enabling peripherals */
	/********************************/
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOA, 0);
	RCC_ClockEnable(RCC_GPIOA, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOA, 1);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOB, 0);
	RCC_ClockEnable(RCC_GPIOB, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOB, 1);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOC, 0);
	RCC_ClockEnable(RCC_GPIOC, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOC, 1);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOH, 0);
	RCC_ClockEnable(RCC_GPIOH, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOH, 1);
	
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.CRC, 0);
	RCC_ClockEnable(RCC_CRC, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.CRC, 1);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA1, 0);
	RCC_ClockEnable(RCC_DMA1, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA1, 1);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA2, 0);
	RCC_ClockEnable(RCC_DMA2, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA2, 1);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.RNG, 0);
	RCC_ClockEnable(RCC_RNG, Enable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.RNG, 1);
	
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM5, 0);
	RCC_ClockEnable(RCC_TIM5, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM5, 1);
	
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM6, 0);
	RCC_ClockEnable(RCC_TIM6, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM6, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.LPTIM1, 0);
	RCC_ClockEnable(RCC_LPTIM1, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.LPTIM1, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.WWDG, 0);
	RCC_ClockEnable(RCC_WWDG, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.WWDG, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.SPI2, 0);
	RCC_ClockEnable(RCC_SPI2, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.SPI2, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.USART2, 0);
	RCC_ClockEnable(RCC_USART2, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.USART2, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C1, 0);
	RCC_ClockEnable(RCC_I2C1, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C1, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C2, 0);
	RCC_ClockEnable(RCC_I2C2, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C2, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C4, 0);
	RCC_ClockEnable(RCC_I2C4, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C4, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.PWR, 0);
	RCC_ClockEnable(RCC_PWR, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.PWR, 1);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.DAC, 0);
	RCC_ClockEnable(RCC_DAC, Enable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.DAC, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM1, 0);
	RCC_ClockEnable(RCC_TIM1, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM1, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART1, 0);
	RCC_ClockEnable(RCC_USART1, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART1, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART6, 0);
	RCC_ClockEnable(RCC_USART6, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART6, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.ADC1, 0);
	RCC_ClockEnable(RCC_ADC1, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.ADC1, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI1, 0);
	RCC_ClockEnable(RCC_SPI1, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI1, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SYSCFG, 0);
	RCC_ClockEnable(RCC_SYSCFG, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SYSCFG, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM9, 0);
	RCC_ClockEnable(RCC_TIM9, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM9, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM11, 0);
	RCC_ClockEnable(RCC_TIM11, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM11, 1);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI5, 0);
	RCC_ClockEnable(RCC_SPI5, Enable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI5, 1);

	
	/************************************/
	/* Test of disabling of peripherals */
	/************************************/
	
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOA, 1);
	RCC_ClockEnable(RCC_GPIOA, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOA, 0);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOB, 1);
	RCC_ClockEnable(RCC_GPIOB, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOB, 0);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOC, 1);
	RCC_ClockEnable(RCC_GPIOC, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOC, 0);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOH, 1);
	RCC_ClockEnable(RCC_GPIOH, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.GPIOH, 0);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.CRC, 1);
	RCC_ClockEnable(RCC_CRC, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.CRC, 0);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA1, 1);
	RCC_ClockEnable(RCC_DMA1, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA1, 0);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA2, 1);
	RCC_ClockEnable(RCC_DMA2, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.DMA2, 0);

	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.RNG, 1);
	RCC_ClockEnable(RCC_RNG, Disable);
	ASSERT_EQ(TestRCC.ENR.AHB1.Fields.RNG, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM5, 1);
	RCC_ClockEnable(RCC_TIM5, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM5, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM6, 1);
	RCC_ClockEnable(RCC_TIM6, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.TIM6, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.LPTIM1, 1);
	RCC_ClockEnable(RCC_LPTIM1, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.LPTIM1, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.WWDG, 1);
	RCC_ClockEnable(RCC_WWDG, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.WWDG, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.SPI2, 1);
	RCC_ClockEnable(RCC_SPI2, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.SPI2, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.USART2, 1);
	RCC_ClockEnable(RCC_USART2, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.USART2, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C1, 1);
	RCC_ClockEnable(RCC_I2C1, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C1, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C2, 1);
	RCC_ClockEnable(RCC_I2C2, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C2, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C4, 1);
	RCC_ClockEnable(RCC_I2C4, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.I2C4, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.PWR, 1);
	RCC_ClockEnable(RCC_PWR, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.PWR, 0);

	ASSERT_EQ(TestRCC.ENR.APB1.Fields.DAC, 1);
	RCC_ClockEnable(RCC_DAC, Disable);
	ASSERT_EQ(TestRCC.ENR.APB1.Fields.DAC, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM1, 1);
	RCC_ClockEnable(RCC_TIM1, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM1, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART1, 1);
	RCC_ClockEnable(RCC_USART1, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART1, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART6, 1);
	RCC_ClockEnable(RCC_USART6, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.USART6, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.ADC1, 1);
	RCC_ClockEnable(RCC_ADC1, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.ADC1, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI1, 1);
	RCC_ClockEnable(RCC_SPI1, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI1, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SYSCFG, 1);
	RCC_ClockEnable(RCC_SYSCFG, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SYSCFG, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM9, 1);
	RCC_ClockEnable(RCC_TIM9, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM9, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM11, 1);
	RCC_ClockEnable(RCC_TIM11, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.TIM11, 0);

	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI5, 1);
	RCC_ClockEnable(RCC_SPI5, Disable);
	ASSERT_EQ(TestRCC.ENR.APB2.Fields.SPI5, 0);

    /***********************/
	/* Test of LP enabling */
    /***********************/

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOA, 0);
	RCC_ClockEnable(RCC_GPIOA, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOA, 1);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOB, 0);
	RCC_ClockEnable(RCC_GPIOB, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOB, 1);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOC, 0);
	RCC_ClockEnable(RCC_GPIOC, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOC, 1);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOH, 0);
	RCC_ClockEnable(RCC_GPIOH, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOH, 1);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.CRC, 0);
	RCC_ClockEnable(RCC_CRC, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.CRC, 1);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA1, 0);
	RCC_ClockEnable(RCC_DMA1, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA1, 1);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA2, 0);
	RCC_ClockEnable(RCC_DMA2, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA2, 1);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.RNG, 0);
	RCC_ClockEnable(RCC_RNG, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.RNG, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM5, 0);
	RCC_ClockEnable(RCC_TIM5, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM5, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM6, 0);
	RCC_ClockEnable(RCC_TIM6, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM6, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.LPTIM1, 0);
	RCC_ClockEnable(RCC_LPTIM1, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.LPTIM1, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.WWDG, 0);
	RCC_ClockEnable(RCC_WWDG, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.WWDG, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.SPI2, 0);
	RCC_ClockEnable(RCC_SPI2, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.SPI2, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.USART2, 0);
	RCC_ClockEnable(RCC_USART2, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.USART2, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C1, 0);
	RCC_ClockEnable(RCC_I2C1, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C1, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C2, 0);
	RCC_ClockEnable(RCC_I2C2, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C2, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C4, 0);
	RCC_ClockEnable(RCC_I2C4, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C4, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.PWR, 0);
	RCC_ClockEnable(RCC_PWR, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.PWR, 1);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.DAC, 0);
	RCC_ClockEnable(RCC_DAC, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.DAC, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM1, 0);
	RCC_ClockEnable(RCC_TIM1, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM1, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART1, 0);
	RCC_ClockEnable(RCC_USART1, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART1, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART6, 0);
	RCC_ClockEnable(RCC_USART6, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART6, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.ADC1, 0);
	RCC_ClockEnable(RCC_ADC1, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.ADC1, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI1, 0);
	RCC_ClockEnable(RCC_SPI1, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI1, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SYSCFG, 0);
	RCC_ClockEnable(RCC_SYSCFG, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SYSCFG, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM9, 0);
	RCC_ClockEnable(RCC_TIM9, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM9, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM11, 0);
	RCC_ClockEnable(RCC_TIM11, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM11, 1);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI5, 0);
	RCC_ClockEnable(RCC_SPI5, LpEnable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI5, 1);
	
	/***********************/
	/* Test of LP disabling */
	/***********************/
	
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOA, 1);
	RCC_ClockEnable(RCC_GPIOA, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOA, 0);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOB, 1);
	RCC_ClockEnable(RCC_GPIOB, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOB, 0);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOC, 1);
	RCC_ClockEnable(RCC_GPIOC, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOC, 0);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOH, 1);
	RCC_ClockEnable(RCC_GPIOH, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.GPIOH, 0);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.CRC, 1);
	RCC_ClockEnable(RCC_CRC, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.CRC, 0);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA1, 1);
	RCC_ClockEnable(RCC_DMA1, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA1, 0);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA2, 1);
	RCC_ClockEnable(RCC_DMA2, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.DMA2, 0);

	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.RNG, 1);
	RCC_ClockEnable(RCC_RNG, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.AHB1.Fields.RNG, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM5, 1);
	RCC_ClockEnable(RCC_TIM5, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM5, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM6, 1);
	RCC_ClockEnable(RCC_TIM6, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.TIM6, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.LPTIM1, 1);
	RCC_ClockEnable(RCC_LPTIM1, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.LPTIM1, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.WWDG, 1);
	RCC_ClockEnable(RCC_WWDG, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.WWDG, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.SPI2, 1);
	RCC_ClockEnable(RCC_SPI2, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.SPI2, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.USART2, 1);
	RCC_ClockEnable(RCC_USART2, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.USART2, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C1, 1);
	RCC_ClockEnable(RCC_I2C1, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C1, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C2, 1);
	RCC_ClockEnable(RCC_I2C2, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C2, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C4, 1);
	RCC_ClockEnable(RCC_I2C4, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.I2C4, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.PWR, 1);
	RCC_ClockEnable(RCC_PWR, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.PWR, 0);

	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.DAC, 1);
	RCC_ClockEnable(RCC_DAC, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB1.Fields.DAC, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM1, 1);
	RCC_ClockEnable(RCC_TIM1, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM1, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART1, 1);
	RCC_ClockEnable(RCC_USART1, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART1, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART6, 1);
	RCC_ClockEnable(RCC_USART6, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.USART6, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.ADC1, 1);
	RCC_ClockEnable(RCC_ADC1, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.ADC1, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI1, 1);
	RCC_ClockEnable(RCC_SPI1, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI1, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SYSCFG, 1);
	RCC_ClockEnable(RCC_SYSCFG, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SYSCFG, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM9, 1);
	RCC_ClockEnable(RCC_TIM9, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM9, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM11, 1);
	RCC_ClockEnable(RCC_TIM11, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.TIM11, 0);

	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI5, 1);
	RCC_ClockEnable(RCC_SPI5, LpDisable);
	ASSERT_EQ(TestRCC.LPENR.APB2.Fields.SPI5, 0);

	/********************************/
	/* Test of reseting peripherals */
    /********************************/

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOA, 0);
	RCC_ClockEnable(RCC_GPIOA, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOA, 1);

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOB, 0);
	RCC_ClockEnable(RCC_GPIOB, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOB, 1);

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOC, 0);
	RCC_ClockEnable(RCC_GPIOC, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOC, 1);

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOH, 0);
	RCC_ClockEnable(RCC_GPIOH, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.GPIOH, 1);

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.CRC, 0);
	RCC_ClockEnable(RCC_CRC, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.CRC, 1);

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.DMA1, 0);
	RCC_ClockEnable(RCC_DMA1, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.DMA1, 1);

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.DMA2, 0);
	RCC_ClockEnable(RCC_DMA2, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.DMA2, 1);

	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.RNG, 0);
	RCC_ClockEnable(RCC_RNG, Reset);
	ASSERT_EQ(TestRCC.RSTR.AHB1.Fields.RNG, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.TIM5, 0);
	RCC_ClockEnable(RCC_TIM5, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.TIM5, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.TIM6, 0);
	RCC_ClockEnable(RCC_TIM6, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.TIM6, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.LPTIM1, 0);
	RCC_ClockEnable(RCC_LPTIM1, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.LPTIM1, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.WWDG, 0);
	RCC_ClockEnable(RCC_WWDG, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.WWDG, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.SPI2, 0);
	RCC_ClockEnable(RCC_SPI2, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.SPI2, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.USART2, 0);
	RCC_ClockEnable(RCC_USART2, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.USART2, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.I2C1, 0);
	RCC_ClockEnable(RCC_I2C1, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.I2C1, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.I2C2, 0);
	RCC_ClockEnable(RCC_I2C2, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.I2C2, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.I2C4, 0);
	RCC_ClockEnable(RCC_I2C4, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.I2C4, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.PWR, 0);
	RCC_ClockEnable(RCC_PWR, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.PWR, 1);

	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.DAC, 0);
	RCC_ClockEnable(RCC_DAC, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB1.Fields.DAC, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.TIM1, 0);
	RCC_ClockEnable(RCC_TIM1, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.TIM1, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.USART1, 0);
	RCC_ClockEnable(RCC_USART1, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.USART1, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.USART6, 0);
	RCC_ClockEnable(RCC_USART6, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.USART6, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.ADC1, 0);
	RCC_ClockEnable(RCC_ADC1, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.ADC1, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.SPI1, 0);
	RCC_ClockEnable(RCC_SPI1, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.SPI1, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.SYSCFG, 0);
	RCC_ClockEnable(RCC_SYSCFG, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.SYSCFG, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.TIM9, 0);
	RCC_ClockEnable(RCC_TIM9, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.TIM9, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.TIM11, 0);
	RCC_ClockEnable(RCC_TIM11, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.TIM11, 1);

	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.SPI5, 0);
	RCC_ClockEnable(RCC_SPI5, Reset);
	ASSERT_EQ(TestRCC.RSTR.APB2.Fields.SPI5, 1);
}

/*
 * This test case tests the clock configuration functionality
 */
void RCC_TestCase_2(void)
{
	uint32 CalculatedClock;
	dtRccInitConfig config;
	int looper;
	int looper2;

	for(PowerSupplyVoltage = 17; PowerSupplyVoltage <= 36; PowerSupplyVoltage++)
	{
		config.CrystalOrInternal = Internal;

		/* Test the PLL calculation with internal oscillator configuration */
		for(looper = 16000000; looper <= 100000000; looper += 4000000)
		{
			MemClear((unsigned char *)&TestRCC, sizeof(TestRCC));
			MemClear((unsigned char *)&TestFlash, sizeof(TestFlash));
			MemClear((unsigned char *)&TestPwr, sizeof(TestPwr));
			ASSERT_EQ(TestRCC.PLLCFGR.Fields.PLLSRC, 0);
			ASSERT_EQ(TestRCC.CR.Fields.PLLON, 0);
			ASSERT_EQ(TestRCC.CFGR.Fields.SW, 0);
			ASSERT_EQ(TestRCC.CR.Fields.PLLON, 0);
			ASSERT_EQ(TestPwr.CR.Fields.VOS, 0);
			ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 0);
			config.Clock = looper;
			RCC_ClockSet(config);

			/* Calculate the input frequency of the PLL */
			CalculatedClock = 16000000/(TestRCC.PLLCFGR.Fields.PLLM);

			/* Calculate the VCO frequency */
			CalculatedClock *= TestRCC.PLLCFGR.Fields.PLLN;

			/* Calculate the output frequency */
			CalculatedClock /= (TestRCC.PLLCFGR.Fields.PLLP*2+2);

			ASSERT_EQ(config.Clock, CalculatedClock);
			ASSERT_EQ(TestRCC.PLLCFGR.Fields.PLLSRC, 0);
			ASSERT_EQ(TestRCC.CR.Fields.PLLON, 1);
			ASSERT_EQ(TestRCC.CFGR.Fields.SW, 2);
			ASSERT_EQ(TestRCC.CR.Fields.PLLON, 1);
			if(config.Clock > 84000000)	ASSERT_EQ(TestPwr.CR.Fields.VOS, 3);
			else if(config.Clock > 64000000) ASSERT_EQ(TestPwr.CR.Fields.VOS, 2);
			else ASSERT_EQ(TestPwr.CR.Fields.VOS, 1);
			LatencyCheck(config.Clock);
		}

		/* Test the PLL calculation with external crystal oscillator configuration */
		config.CrystalOrInternal = Crystal;
		for(looper = 8000000; looper < 48000000; looper += 4000000)
		{
			config.CrystalClockFreq = looper;
			for(config.Clock = 16000000; config.Clock <= 100000000; config.Clock += 4000000)
			{
				MemClear((unsigned char *)&TestRCC, sizeof(TestRCC));
				ASSERT_EQ(TestRCC.PLLCFGR.Fields.PLLSRC, 0);
				ASSERT_EQ(TestRCC.CR.Fields.PLLON, 0);
				ASSERT_EQ(TestRCC.CFGR.Fields.SW, 0);
				ASSERT_EQ(TestRCC.CR.Fields.PLLON, 0);

				RCC_ClockSet(config);

				/* Calculate the input frequency of the PLL */
				CalculatedClock = config.CrystalClockFreq/(TestRCC.PLLCFGR.Fields.PLLM);

				/* Calculate the VCO frequency */
				CalculatedClock *= TestRCC.PLLCFGR.Fields.PLLN;

				/* Calculate the output frequency */
				CalculatedClock /= (TestRCC.PLLCFGR.Fields.PLLP*2+2);

				ASSERT_EQ(config.Clock, CalculatedClock);
				ASSERT_EQ(TestRCC.PLLCFGR.Fields.PLLSRC, 1);
				ASSERT_EQ(TestRCC.CR.Fields.PLLON, 1);
				ASSERT_EQ(TestRCC.CFGR.Fields.SW, 2);
				ASSERT_EQ(TestRCC.CR.Fields.PLLON, 1);
			}
		}
	}
}

/*
 * This test case test the clock getting functionality
 */
void RCC_TestCase_3(void)
{
	uint32 CalculatedClock;
	dtRccInitConfig config;
	int looper;
	int looper2;
	int looper3;
	config.CrystalOrInternal = Internal;

	for(config.APB2_Presc = 0, looper3 = 0; looper3 < 8; looper3++, config.APB2_Presc++)
	{
		for(config.APB1_Presc = 0, looper2 = 0; looper2 < 8; looper2++, config.APB1_Presc++)
		{
			for(config.AHB_Presc = 0, looper = 0; looper < 16; looper++, config.AHB_Presc++)
			{
				for(looper = 16000000; looper <= 100000000; looper += 4000000)
				{
					MemClear((unsigned char *)&TestRCC, sizeof(TestRCC));

					config.Clock = looper;
					RCC_ClockSet(config);

					/* Calculate the input frequency of the PLL */
					CalculatedClock = 16000000/(TestRCC.PLLCFGR.Fields.PLLM);

					/* Calculate the VCO frequency */
					CalculatedClock *= TestRCC.PLLCFGR.Fields.PLLN;

					/* Calculate the output frequency */
					CalculatedClock /= (TestRCC.PLLCFGR.Fields.PLLP*2+2);

					ASSERT_EQ(config.Clock, RCC_GetClock(Core));
					ASSERT_EQ(AHB_Calc(config.Clock), RCC_GetClock(AHB));
					ASSERT_EQ(APB1_Per_Calc(config.Clock),RCC_GetClock(APB1_Peripheral));
					ASSERT_EQ(APB2_Per_Calc(config.Clock),RCC_GetClock(APB2_Peripheral));
					ASSERT_EQ(APB1_Tim_Calc(config.Clock),RCC_GetClock(APB1_Timer));
					ASSERT_EQ(APB2_Tim_Calc(config.Clock),RCC_GetClock(APB2_Timer));
					ASSERT_EQ(config.Clock, CalculatedClock);
				}
			}
		}
	}
}

int AHB_Calc(int clock)
{
	int ret = clock;
	if(TestRCC.CFGR.Fields.HPRE & 0x8)
	{
		switch(TestRCC.CFGR.Fields.HPRE & 0x7)
		{
		case 0: ret /= 2; break;
		case 1: ret /= 4; break;
		case 2: ret /= 8; break;
		case 3: ret /= 16; break;
		case 4: ret /= 64; break;
		case 5: ret /= 128; break;
		case 6: ret /= 256; break;
		case 7: ret /= 512; break;
		}
	}
	return ret;
}

int APB1_Per_Calc(int clock)
{
	int ret = AHB_Calc(clock);
	if(TestRCC.CFGR.Fields.PPRE1 & 0x4)
	{
		switch(TestRCC.CFGR.Fields.PPRE1 & 0x3)
		{
		case 0: ret /= 2; break;
		case 1: ret /= 4; break;
		case 2: ret /= 8; break;
		case 3: ret /= 16; break;
		}
	}
	return ret;
}

int APB1_Tim_Calc(int clock)
{
	int ret = APB1_Per_Calc(clock);
	if((TestRCC.CFGR.Fields.PPRE1 & 0x4) != 0)
	{
		ret = APB1_Per_Calc(clock)*2;
	}
	return ret;
}

int APB2_Per_Calc(int clock)
{
	int ret = AHB_Calc(clock);
	if(TestRCC.CFGR.Fields.PPRE2 & 0x4)
	{
		switch(TestRCC.CFGR.Fields.PPRE2 & 0x3)
		{
		case 0: ret /= 2; break;
		case 1: ret /= 4; break;
		case 2: ret /= 8; break;
		case 3: ret /= 16; break;
		}
	}
	return ret;
}

int APB2_Tim_Calc(int clock)
{
	int ret = APB2_Per_Calc(clock);
	if((TestRCC.CFGR.Fields.PPRE2 & 0x4) != 0)
	{
		ret = APB2_Per_Calc(clock)*2;
	}
	return ret;
}

void LatencyCheck(int clock)
{
	if(TestPwr.CR.Fields.VOS == 1) ASSERT_LE(clock, 64000000);
	else if(TestPwr.CR.Fields.VOS == 2) ASSERT_LE(clock, 84000000);
	else if(TestPwr.CR.Fields.VOS == 3) ASSERT_LE(clock, 100000000);

	if(PowerSupplyVoltage >= 27)
	{
		if(clock > 90000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 3);
		else if(clock > 64000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 2);
		else if(clock > 30000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 1);
		else ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 0);
	}
	else if(PowerSupplyVoltage >= 24)
	{
		if(clock > 96000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 4);
		else if(clock > 72000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 3);
		else if(clock > 48000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 2);
		else if(clock > 24000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 1);
		else ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 0);
	}
	else if(PowerSupplyVoltage >= 21)
	{
		if(clock > 90000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 5);
		else if(clock > 72000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 4);
		else if(clock > 54000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 3);
		else if(clock > 36000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 2);
		else if(clock > 18000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 1);
		else ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 0);
	}
	else
	{
		if(clock > 96000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 6);
		else if(clock > 80000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 5);
		else if(clock > 64000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 4);
		else if(clock > 48000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 3);
		else if(clock > 32000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 2);
		else if(clock > 16000000) ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 1);
		else ASSERT_EQ(TestFlash.ACR.Fields.LATENCY, 0);
	}
}

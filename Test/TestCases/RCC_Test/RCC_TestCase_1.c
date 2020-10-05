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
int APB_Per_Calc(int clock);
int APB_Tim_Calc(int clock);
void LatencyCheck(int clock);

/*
 * This test case tests the various enabling and disabling of the peripherals
 */
void RCC_TestCase_1(void)
{
	/********************************/
	/* Test of enabling peripherals */
	/********************************/

	ASSERT(TestRCC.ENR.IOP.Fields.GPIOA, 0);
	RCC_ClockEnable(RCC_GPIOA, Enable);
	ASSERT(TestRCC.ENR.IOP.Fields.GPIOA, 1);

	ASSERT(TestRCC.ENR.IOP.Fields.GPIOB, 0);
	RCC_ClockEnable(RCC_GPIOB, Enable);
	ASSERT(TestRCC.ENR.IOP.Fields.GPIOB, 1);

	ASSERT(TestRCC.ENR.IOP.Fields.GPIOC, 0);
	RCC_ClockEnable(RCC_GPIOC, Enable);
	ASSERT(TestRCC.ENR.IOP.Fields.GPIOC, 1);

	ASSERT(TestRCC.ENR.IOP.Fields.GPIOD, 0);
	RCC_ClockEnable(RCC_GPIOD, Enable);
	ASSERT(TestRCC.ENR.IOP.Fields.GPIOD, 1);

	ASSERT(TestRCC.ENR.IOP.Fields.GPIOF, 0);
	RCC_ClockEnable(RCC_GPIOF, Enable);
	ASSERT(TestRCC.ENR.IOP.Fields.GPIOF, 1);
	
	ASSERT(TestRCC.ENR.AHB.Fields.DMA, 0);
	RCC_ClockEnable(RCC_DMA, Enable);
	ASSERT(TestRCC.ENR.AHB.Fields.DMA, 1);
	
	ASSERT(TestRCC.ENR.AHB.Fields.FLASH, 0);
	RCC_ClockEnable(RCC_FLASH, Enable);
	ASSERT(TestRCC.ENR.AHB.Fields.FLASH, 1);
	
	ASSERT(TestRCC.ENR.AHB.Fields.CRC, 0);
	RCC_ClockEnable(RCC_CRC, Enable);
	ASSERT(TestRCC.ENR.AHB.Fields.CRC, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.TIM3, 0);
	RCC_ClockEnable(RCC_TIM3, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.TIM3, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.TIM6, 0);
	RCC_ClockEnable(RCC_TIM6, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.TIM6, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.TIM7, 0);
	RCC_ClockEnable(RCC_TIM7, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.TIM7, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.SPI2, 0);
	RCC_ClockEnable(RCC_SPI2, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.SPI2, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.USART2, 0);
	RCC_ClockEnable(RCC_USART2, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.USART2, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.USART3, 0);
	RCC_ClockEnable(RCC_USART3, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.USART3, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.USART4, 0);
	RCC_ClockEnable(RCC_USART4, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.USART4, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.I2C1, 0);
	RCC_ClockEnable(RCC_I2C1, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.I2C1, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.I2C2, 0);
	RCC_ClockEnable(RCC_I2C2, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.I2C2, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.DBG, 0);
	RCC_ClockEnable(RCC_DBG, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.DBG, 1);
	
	ASSERT(TestRCC.ENR.APB1.Fields.PWR, 0);
	RCC_ClockEnable(RCC_PWR, Enable);
	ASSERT(TestRCC.ENR.APB1.Fields.PWR, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.SYSCFG, 0);
	RCC_ClockEnable(RCC_SYSCFG, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.SYSCFG, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.TIM1, 0);
	RCC_ClockEnable(RCC_TIM1, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.TIM1, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.SPI1, 0);
	RCC_ClockEnable(RCC_SPI1, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.SPI1, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.USART1, 0);
	RCC_ClockEnable(RCC_USART1, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.USART1, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.TIM14, 0);
	RCC_ClockEnable(RCC_TIM14, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.TIM14, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.TIM15, 0);
	RCC_ClockEnable(RCC_TIM15, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.TIM15, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.TIM16, 0);
	RCC_ClockEnable(RCC_TIM16, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.TIM16, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.TIM17, 0);
	RCC_ClockEnable(RCC_TIM17, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.TIM17, 1);
	
	ASSERT(TestRCC.ENR.APB2.Fields.ADC, 0);
	RCC_ClockEnable(RCC_ADC, Enable);
	ASSERT(TestRCC.ENR.APB2.Fields.ADC, 1);
	
	/************************************/
	/* Test of disabling of peripherals */
	/************************************/
	
	ASSERT(TestRCC.ENR.IOP.Fields.GPIOA, 1);
	RCC_ClockEnable(RCC_GPIOA, Disable);
	ASSERT(TestRCC.ENR.IOP.Fields.GPIOA, 0);

    ASSERT(TestRCC.ENR.IOP.Fields.GPIOB, 1);
    RCC_ClockEnable(RCC_GPIOB, Disable);
    ASSERT(TestRCC.ENR.IOP.Fields.GPIOB, 0);
    
    ASSERT(TestRCC.ENR.IOP.Fields.GPIOC, 1);
    RCC_ClockEnable(RCC_GPIOC, Disable);
    ASSERT(TestRCC.ENR.IOP.Fields.GPIOC, 0);
    
    ASSERT(TestRCC.ENR.IOP.Fields.GPIOD, 1);
    RCC_ClockEnable(RCC_GPIOD, Disable);
    ASSERT(TestRCC.ENR.IOP.Fields.GPIOD, 0);
    
    ASSERT(TestRCC.ENR.IOP.Fields.GPIOF, 1);
    RCC_ClockEnable(RCC_GPIOF, Disable);
    ASSERT(TestRCC.ENR.IOP.Fields.GPIOF, 0);
    
    ASSERT(TestRCC.ENR.AHB.Fields.DMA, 1);
    RCC_ClockEnable(RCC_DMA, Disable);
    ASSERT(TestRCC.ENR.AHB.Fields.DMA, 0);
    
    ASSERT(TestRCC.ENR.AHB.Fields.FLASH, 1);
    RCC_ClockEnable(RCC_FLASH, Disable);
    ASSERT(TestRCC.ENR.AHB.Fields.FLASH, 0);
    
    ASSERT(TestRCC.ENR.AHB.Fields.CRC, 1);
    RCC_ClockEnable(RCC_CRC, Disable);
    ASSERT(TestRCC.ENR.AHB.Fields.CRC, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.TIM3, 1);
    RCC_ClockEnable(RCC_TIM3, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.TIM3, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.TIM6, 1);
    RCC_ClockEnable(RCC_TIM6, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.TIM6, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.TIM7, 1);
    RCC_ClockEnable(RCC_TIM7, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.TIM7, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.SPI2, 1);
    RCC_ClockEnable(RCC_SPI2, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.SPI2, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.USART2, 1);
    RCC_ClockEnable(RCC_USART2, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.USART2, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.USART3, 1);
    RCC_ClockEnable(RCC_USART3, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.USART3, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.USART4, 1);
    RCC_ClockEnable(RCC_USART4, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.USART4, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.I2C1, 1);
    RCC_ClockEnable(RCC_I2C1, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.I2C1, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.I2C2, 1);
    RCC_ClockEnable(RCC_I2C2, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.I2C2, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.DBG, 1);
    RCC_ClockEnable(RCC_DBG, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.DBG, 0);
    
    ASSERT(TestRCC.ENR.APB1.Fields.PWR, 1);
    RCC_ClockEnable(RCC_PWR, Disable);
    ASSERT(TestRCC.ENR.APB1.Fields.PWR, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.SYSCFG, 1);
    RCC_ClockEnable(RCC_SYSCFG, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.SYSCFG, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.TIM1, 1);
    RCC_ClockEnable(RCC_TIM1, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.TIM1, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.SPI1, 1);
    RCC_ClockEnable(RCC_SPI1, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.SPI1, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.USART1, 1);
    RCC_ClockEnable(RCC_USART1, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.USART1, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.TIM14, 1);
    RCC_ClockEnable(RCC_TIM14, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.TIM14, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.TIM15, 1);
    RCC_ClockEnable(RCC_TIM15, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.TIM15, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.TIM16, 1);
    RCC_ClockEnable(RCC_TIM16, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.TIM16, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.TIM17, 1);
    RCC_ClockEnable(RCC_TIM17, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.TIM17, 0);
    
    ASSERT(TestRCC.ENR.APB2.Fields.ADC, 1);
    RCC_ClockEnable(RCC_ADC, Disable);
    ASSERT(TestRCC.ENR.APB2.Fields.ADC, 0);

    /***********************/
	/* Test of LP enabling */
    /***********************/

	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOA, 0);
	RCC_ClockEnable(RCC_GPIOA, LpEnable);
	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOA, 1);

	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOB, 0);
	RCC_ClockEnable(RCC_GPIOB, LpEnable);
	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOB, 1);

	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOC, 0);
	RCC_ClockEnable(RCC_GPIOC, LpEnable);
	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOC, 1);

	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOD, 0);
	RCC_ClockEnable(RCC_GPIOD, LpEnable);
	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOD, 1);

	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOF, 0);
	RCC_ClockEnable(RCC_GPIOF, LpEnable);
	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOF, 1);
	
	ASSERT(TestRCC.SMENR.AHB.Fields.DMA, 0);
	RCC_ClockEnable(RCC_DMA, LpEnable);
	ASSERT(TestRCC.SMENR.AHB.Fields.DMA, 1);
	
	ASSERT(TestRCC.SMENR.AHB.Fields.FLASH, 0);
	RCC_ClockEnable(RCC_FLASH, LpEnable);
	ASSERT(TestRCC.SMENR.AHB.Fields.FLASH, 1);
	
	ASSERT(TestRCC.SMENR.AHB.Fields.CRC, 0);
	RCC_ClockEnable(RCC_CRC, LpEnable);
	ASSERT(TestRCC.SMENR.AHB.Fields.CRC, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.TIM3, 0);
	RCC_ClockEnable(RCC_TIM3, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.TIM3, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.TIM6, 0);
	RCC_ClockEnable(RCC_TIM6, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.TIM6, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.TIM7, 0);
	RCC_ClockEnable(RCC_TIM7, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.TIM7, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.SPI2, 0);
	RCC_ClockEnable(RCC_SPI2, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.SPI2, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.USART2, 0);
	RCC_ClockEnable(RCC_USART2, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.USART2, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.USART3, 0);
	RCC_ClockEnable(RCC_USART3, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.USART3, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.USART4, 0);
	RCC_ClockEnable(RCC_USART4, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.USART4, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.I2C1, 0);
	RCC_ClockEnable(RCC_I2C1, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.I2C1, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.I2C2, 0);
	RCC_ClockEnable(RCC_I2C2, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.I2C2, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.DBG, 0);
	RCC_ClockEnable(RCC_DBG, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.DBG, 1);
	
	ASSERT(TestRCC.SMENR.APB1.Fields.PWR, 0);
	RCC_ClockEnable(RCC_PWR, LpEnable);
	ASSERT(TestRCC.SMENR.APB1.Fields.PWR, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.SYSCFG, 0);
	RCC_ClockEnable(RCC_SYSCFG, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.SYSCFG, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM1, 0);
	RCC_ClockEnable(RCC_TIM1, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM1, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.SPI1, 0);
	RCC_ClockEnable(RCC_SPI1, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.SPI1, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.USART1, 0);
	RCC_ClockEnable(RCC_USART1, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.USART1, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM14, 0);
	RCC_ClockEnable(RCC_TIM14, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM14, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM15, 0);
	RCC_ClockEnable(RCC_TIM15, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM15, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM16, 0);
	RCC_ClockEnable(RCC_TIM16, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM16, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM17, 0);
	RCC_ClockEnable(RCC_TIM17, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.TIM17, 1);
	
	ASSERT(TestRCC.SMENR.APB2.Fields.ADC, 0);
	RCC_ClockEnable(RCC_ADC, LpEnable);
	ASSERT(TestRCC.SMENR.APB2.Fields.ADC, 1);
	
	/***********************/
	/* Test of LP disabling */
	/***********************/
	
	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOA, 1);
	RCC_ClockEnable(RCC_GPIOA, LpDisable);
	ASSERT(TestRCC.SMENR.IOP.Fields.GPIOA, 0);

    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOB, 1);
    RCC_ClockEnable(RCC_GPIOB, LpDisable);
    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOB, 0);
    
    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOC, 1);
    RCC_ClockEnable(RCC_GPIOC, LpDisable);
    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOC, 0);
    
    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOD, 1);
    RCC_ClockEnable(RCC_GPIOD, LpDisable);
    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOD, 0);
    
    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOF, 1);
    RCC_ClockEnable(RCC_GPIOF, LpDisable);
    ASSERT(TestRCC.SMENR.IOP.Fields.GPIOF, 0);
    
    ASSERT(TestRCC.SMENR.AHB.Fields.DMA, 1);
    RCC_ClockEnable(RCC_DMA, LpDisable);
    ASSERT(TestRCC.SMENR.AHB.Fields.DMA, 0);
    
    ASSERT(TestRCC.SMENR.AHB.Fields.FLASH, 1);
    RCC_ClockEnable(RCC_FLASH, LpDisable);
    ASSERT(TestRCC.SMENR.AHB.Fields.FLASH, 0);
    
    ASSERT(TestRCC.SMENR.AHB.Fields.CRC, 1);
    RCC_ClockEnable(RCC_CRC, LpDisable);
    ASSERT(TestRCC.SMENR.AHB.Fields.CRC, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.TIM3, 1);
    RCC_ClockEnable(RCC_TIM3, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.TIM3, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.TIM6, 1);
    RCC_ClockEnable(RCC_TIM6, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.TIM6, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.TIM7, 1);
    RCC_ClockEnable(RCC_TIM7, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.TIM7, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.SPI2, 1);
    RCC_ClockEnable(RCC_SPI2, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.SPI2, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.USART2, 1);
    RCC_ClockEnable(RCC_USART2, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.USART2, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.USART3, 1);
    RCC_ClockEnable(RCC_USART3, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.USART3, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.USART4, 1);
    RCC_ClockEnable(RCC_USART4, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.USART4, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.I2C1, 1);
    RCC_ClockEnable(RCC_I2C1, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.I2C1, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.I2C2, 1);
    RCC_ClockEnable(RCC_I2C2, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.I2C2, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.DBG, 1);
    RCC_ClockEnable(RCC_DBG, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.DBG, 0);
    
    ASSERT(TestRCC.SMENR.APB1.Fields.PWR, 1);
    RCC_ClockEnable(RCC_PWR, LpDisable);
    ASSERT(TestRCC.SMENR.APB1.Fields.PWR, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.SYSCFG, 1);
    RCC_ClockEnable(RCC_SYSCFG, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.SYSCFG, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM1, 1);
    RCC_ClockEnable(RCC_TIM1, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM1, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.SPI1, 1);
    RCC_ClockEnable(RCC_SPI1, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.SPI1, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.USART1, 1);
    RCC_ClockEnable(RCC_USART1, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.USART1, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM14, 1);
    RCC_ClockEnable(RCC_TIM14, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM14, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM15, 1);
    RCC_ClockEnable(RCC_TIM15, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM15, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM16, 1);
    RCC_ClockEnable(RCC_TIM16, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM16, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM17, 1);
    RCC_ClockEnable(RCC_TIM17, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.TIM17, 0);
    
    ASSERT(TestRCC.SMENR.APB2.Fields.ADC, 1);
    RCC_ClockEnable(RCC_ADC, LpDisable);
    ASSERT(TestRCC.SMENR.APB2.Fields.ADC, 0);

	/********************************/
	/* Test of reseting peripherals */
    /********************************/

	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOA, 0);
	RCC_ClockEnable(RCC_GPIOA, Reset);
	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOA, 1);

	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOB, 0);
	RCC_ClockEnable(RCC_GPIOB, Reset);
	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOB, 1);

	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOC, 0);
	RCC_ClockEnable(RCC_GPIOC, Reset);
	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOC, 1);

	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOD, 0);
	RCC_ClockEnable(RCC_GPIOD, Reset);
	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOD, 1);

	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOF, 0);
	RCC_ClockEnable(RCC_GPIOF, Reset);
	ASSERT(TestRCC.RSTR.IOP.Fields.GPIOF, 1);
	
	ASSERT(TestRCC.RSTR.AHB.Fields.DMA, 0);
	RCC_ClockEnable(RCC_DMA, Reset);
	ASSERT(TestRCC.RSTR.AHB.Fields.DMA, 1);
	
	ASSERT(TestRCC.RSTR.AHB.Fields.FLASH, 0);
	RCC_ClockEnable(RCC_FLASH, Reset);
	ASSERT(TestRCC.RSTR.AHB.Fields.FLASH, 1);
	
	ASSERT(TestRCC.RSTR.AHB.Fields.CRC, 0);
	RCC_ClockEnable(RCC_CRC, Reset);
	ASSERT(TestRCC.RSTR.AHB.Fields.CRC, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.TIM3, 0);
	RCC_ClockEnable(RCC_TIM3, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.TIM3, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.TIM6, 0);
	RCC_ClockEnable(RCC_TIM6, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.TIM6, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.TIM7, 0);
	RCC_ClockEnable(RCC_TIM7, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.TIM7, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.SPI2, 0);
	RCC_ClockEnable(RCC_SPI2, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.SPI2, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.USART2, 0);
	RCC_ClockEnable(RCC_USART2, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.USART2, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.USART3, 0);
	RCC_ClockEnable(RCC_USART3, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.USART3, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.USART4, 0);
	RCC_ClockEnable(RCC_USART4, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.USART4, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.I2C1, 0);
	RCC_ClockEnable(RCC_I2C1, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.I2C1, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.I2C2, 0);
	RCC_ClockEnable(RCC_I2C2, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.I2C2, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.DBG, 0);
	RCC_ClockEnable(RCC_DBG, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.DBG, 1);
	
	ASSERT(TestRCC.RSTR.APB1.Fields.PWR, 0);
	RCC_ClockEnable(RCC_PWR, Reset);
	ASSERT(TestRCC.RSTR.APB1.Fields.PWR, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.SYSCFG, 0);
	RCC_ClockEnable(RCC_SYSCFG, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.SYSCFG, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM1, 0);
	RCC_ClockEnable(RCC_TIM1, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM1, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.SPI1, 0);
	RCC_ClockEnable(RCC_SPI1, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.SPI1, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.USART1, 0);
	RCC_ClockEnable(RCC_USART1, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.USART1, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM14, 0);
	RCC_ClockEnable(RCC_TIM14, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM14, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM15, 0);
	RCC_ClockEnable(RCC_TIM15, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM15, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM16, 0);
	RCC_ClockEnable(RCC_TIM16, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM16, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM17, 0);
	RCC_ClockEnable(RCC_TIM17, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.TIM17, 1);
	
	ASSERT(TestRCC.RSTR.APB2.Fields.ADC, 0);
	RCC_ClockEnable(RCC_ADC, Reset);
	ASSERT(TestRCC.RSTR.APB2.Fields.ADC, 1);
}

/*
 * This test case tests the clock configuration functionality
 */
void RCC_TestCase_2(void)
{
	uint32 CalculatedClock;
	dtRccInitConfig config;
	int looper;
	config.CrystalOrInternal = Internal;

	/* Test the PLL calculation with internal oscillator configuration */
	for(looper = 8000000; looper <= 64000000; looper += 8000000)
	{
		MemClear((unsigned char *)&TestRCC, sizeof(TestRCC));
		MemClear((unsigned char *)&TestFlash, sizeof(TestFlash));
		MemClear((unsigned char *)&TestPwr, sizeof(TestPwr));
		ASSERT(TestRCC.PLLCFGR.Fields.PLLSRC, 0);
		ASSERT(TestRCC.PLLCFGR.Fields.PLLREN, 0);
		ASSERT(TestRCC.CFGR.Fields.SW, 0);
		ASSERT(TestRCC.CR.Fields.PLLON, 0);
		ASSERT(TestPwr.CR.Fields.VOS, 0);
		ASSERT(TestFlash.ACR.Fields.LATENCY, 0);

		config.Clock = looper;
		RCC_ClockSet(config);

		/* Calculate the input frequency of the PLL */
		CalculatedClock = 16000000/(TestRCC.PLLCFGR.Fields.PLLM+1);

		/* Calculate the VCO frequency */
		CalculatedClock *= TestRCC.PLLCFGR.Fields.PLLN;

		/* Calculate the output frequency */
		CalculatedClock /= (TestRCC.PLLCFGR.Fields.PLLR+1);

		ASSERT(config.Clock, CalculatedClock);
		ASSERT(TestRCC.PLLCFGR.Fields.PLLSRC, 2);
		ASSERT(TestRCC.PLLCFGR.Fields.PLLREN, 1);
		ASSERT(TestRCC.CFGR.Fields.SW, 2);
		ASSERT(TestRCC.CR.Fields.PLLON, 1);
		if(config.Clock > 16000000)	ASSERT(TestPwr.CR.Fields.VOS, 1);
		else ASSERT(TestPwr.CR.Fields.VOS, 2);
		LatencyCheck(config.Clock);
	}

	/* Test the PLL calculation with external crystal oscillator configuration */
	config.CrystalOrInternal = Crystal;
	for(looper = 8000000; looper < 48000000; looper += 8000000)
	{
		config.CrystalClockFreq = looper;
		for(config.Clock = 8000000; config.Clock <= 64000000; config.Clock += 8000000)
		{
			MemClear((unsigned char *)&TestRCC, sizeof(TestRCC));
			ASSERT(TestRCC.PLLCFGR.Fields.PLLSRC, 0);
			ASSERT(TestRCC.PLLCFGR.Fields.PLLREN, 0);
			ASSERT(TestRCC.CFGR.Fields.SW, 0);
			ASSERT(TestRCC.CR.Fields.PLLON, 0);

			RCC_ClockSet(config);

			/* Calculate the input frequency of the PLL */
			CalculatedClock = config.CrystalClockFreq/(TestRCC.PLLCFGR.Fields.PLLM+1);

			/* Calculate the VCO frequency */
			CalculatedClock *= TestRCC.PLLCFGR.Fields.PLLN;

			/* Calculate the output frequency */
			CalculatedClock /= (TestRCC.PLLCFGR.Fields.PLLR+1);

			ASSERT(config.Clock, CalculatedClock);
			ASSERT(TestRCC.PLLCFGR.Fields.PLLSRC, 3);
			ASSERT(TestRCC.PLLCFGR.Fields.PLLREN, 1);
			ASSERT(TestRCC.CFGR.Fields.SW, 2);
			ASSERT(TestRCC.CR.Fields.PLLON, 1);
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
	config.CrystalOrInternal = Internal;

	for(config.APB1_Presc = 0, looper2 = 0; looper2 < 8; looper2++, config.APB1_Presc++)
	{
		for(config.AHB_Presc = 0, looper = 0; looper < 16; looper++, config.AHB_Presc++)
		{
			for(looper = 8000000; looper <= 64000000; looper += 8000000)
			{
				MemClear((unsigned char *)&TestRCC, sizeof(TestRCC));

				config.Clock = looper;
				RCC_ClockSet(config);

				/* Calculate the input frequency of the PLL */
				CalculatedClock = 16000000/(TestRCC.PLLCFGR.Fields.PLLM+1);

				/* Calculate the VCO frequency */
				CalculatedClock *= TestRCC.PLLCFGR.Fields.PLLN;

				/* Calculate the output frequency */
				CalculatedClock /= (TestRCC.PLLCFGR.Fields.PLLR+1);

				ASSERT(config.Clock, RCC_GetClock(Core));
				ASSERT(AHB_Calc(config.Clock), RCC_GetClock(AHB));
				ASSERT(APB_Per_Calc(config.Clock),RCC_GetClock(APB1_Peripheral));
				ASSERT(APB_Tim_Calc(config.Clock),RCC_GetClock(APB1_Timer));
				ASSERT(config.Clock, CalculatedClock);
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

int APB_Per_Calc(int clock)
{
	int ret = AHB_Calc(clock);
	if(TestRCC.CFGR.Fields.PPRE & 0x4)
	{
		switch(TestRCC.CFGR.Fields.PPRE & 0x3)
		{
		case 0: ret /= 2; break;
		case 1: ret /= 4; break;
		case 2: ret /= 8; break;
		case 3: ret /= 16; break;
		}
	}
	return ret;
}

int APB_Tim_Calc(int clock)
{
	int ret = APB_Per_Calc(clock);
	if((TestRCC.CFGR.Fields.PPRE & 0x4) != 0)
	{
		ret = APB_Per_Calc(clock)*2;
	}
	return ret;
}

void LatencyCheck(int clock)
{
	if(TestPwr.CR.Fields.VOS == 1)
	{
		if(clock <= 24000000) ASSERT(TestFlash.ACR.Fields.LATENCY, 0);
		else if(clock <= 48000000) ASSERT(TestFlash.ACR.Fields.LATENCY, 1);
		else if(clock <= 64000000) ASSERT(TestFlash.ACR.Fields.LATENCY, 2);
		else ASSERT(1, 0);
	}
	else if(TestPwr.CR.Fields.VOS == 2)
	{
		if(clock <= 8000000) ASSERT(TestFlash.ACR.Fields.LATENCY, 0);
		else if(clock <= 16000000) ASSERT(TestFlash.ACR.Fields.LATENCY, 1);
		else ASSERT(1, 0);
	}
}

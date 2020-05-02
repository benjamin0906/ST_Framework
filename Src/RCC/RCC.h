/*
 * RCC.h
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef RCC_RCC_H_
#define RCC_RCC_H_

#define RCC_DMA1	(0<<16|0)
#define RCC_DMA2	(0<<16|1)
#define RCC_FLASH	(0<<16|8)
#define RCC_CRC		(0<<16|12)
#define RCC_TSC		(0<<16|16)
#define RCC_DMA2D	(0<<16|17)

#define RCC_GPIOA	(1<<16|0)
#define RCC_GPIOB	(1<<16|1)
#define RCC_GPIOC	(1<<16|2)
#define RCC_GPIOD	(1<<16|3)
#define RCC_GPIOE	(1<<16|4)
#define RCC_GPIOF	(1<<16|5)
#define RCC_GPIOG	(1<<16|6)
#define RCC_GPIOH	(1<<16|7)
#define RCC_GPIOI	(1<<16|8)
#define RCC_OTGFS	(1<<16|12)
#define RCC_ADC		(1<<16|13)
#define RCC_DCMI	(1<<16|14)
#define RCC_AES		(1<<16|16)
#define RCC_HASH	(1<<16|17)
#define RCC_RNG		(1<<16|18)

#define RCC_FMC		(2<<16|0)
#define RCC_QSPI	(2<<16|8)

#define RCC_TIM2	(3<<16|0)
#define RCC_TIM3	(3<<16|1)
#define RCC_TIM4	(3<<16|2)
#define RCC_TIM5	(3<<16|3)
#define RCC_TIM6	(3<<16|4)
#define RCC_TIM7	(3<<16|5)
#define RCC_LCD		(3<<16|9)
#define RCC_RTCA	(3<<16|10)
#define RCC_WWDG	(3<<16|11)
#define RCC_SPI2	(3<<16|14)
#define RCC_SPI3	(3<<16|15)
#define RCC_USART2	(3<<16|17)
#define RCC_USART3	(3<<16|18)
#define RCC_UART4	(3<<16|19)
#define RCC_UART5	(3<<16|20)
#define RCC_I2C1	(3<<16|21)
#define RCC_I2C2	(3<<16|22)
#define RCC_I2C3	(3<<16|23)
#define RCC_CRS		(3<<16|24)
#define RCC_CAN1	(3<<16|25)
#define RCC_CAN2	(3<<16|26)
#define RCC_PWR		(3<<16|28)
#define RCC_DAC1	(3<<16|29)
#define RCC_OPAMP	(3<<16|30)
#define RCC_LPTIM1	(3<<16|31)

#define RCC_LPUART1	(4<<16|0)
#define RCC_I2C4	(4<<16|1)
#define RCC_SWPMI1	(4<<16|2)
#define RCC_LPTIM2	(4<<16|5)

#define RCC_SYSCFG	(5<<16|0)
#define RCC_FW		(5<<16|7)
#define RCC_SDMMC1	(5<<16|10)
#define RCC_TIM1	(5<<16|11)
#define RCC_SPI1	(5<<16|12)
#define RCC_TIM8	(5<<16|13)
#define RCC_USART1	(5<<16|14)
#define RCC_TIM15	(5<<16|16)
#define RCC_TIM16	(5<<16|17)
#define RCC_TIM17	(5<<16|18)
#define RCC_SAI1	(5<<16|21)
#define RCC_SAI2	(5<<16|22)
#define RCC_DFSDM1	(5<<16|24)

extern void RCC_ClockEnable(uint32 Peripheral);

#endif /* RCC_RCC_H_ */

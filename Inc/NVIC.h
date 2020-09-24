/*
 * NVIC.h
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#ifndef NVIC_NVIC_H_
#define NVIC_NVIC_H_

#include "types.h"

typedef enum
{
	IRQ_WWDG 			= 0,
	IRQ_PVD				= 1,
#if defined(MCU_F410)
	IRQ_EXTI21			= 2,
	IRQ_EXTI22			= 3,
#elif defined(MCU_F446)
	IRQ_TAMP_STAMP		= 2,
	IRQ_RTC_WKUP		= 3,
#endif
	IRQ_FLASH			= 4,
	IRQ_RCC				= 5,
	IRQ_EXTI0			= 6,
	IRQ_EXTI1			= 7,
	IRQ_EXTI2			= 8,
	IRQ_EXTI3			= 9,
	IRQ_EXTI4			= 10,
	IRQ_DMA1_Stream0	= 11,
	IRQ_DMA1_Stream1	= 12,
	IRQ_DMA1_Stream2	= 13,
	IRQ_DMA1_Stream3	= 14,
	IRQ_DMA1_Stream4	= 15,
	IRQ_DMA1_Stream5	= 16,
	IRQ_DMA1_Stream6	= 17,
	IRQ_ADC				= 18,
#if defined(MCU_F446)
	IRQ_CAN1_TX			= 19,
	IRQ_CAN1_RX0		= 20,
	IRQ_CAN1_RX1		= 21,
	IRQ_CAN1_SCE		= 22,
#endif
	IRQ_EXTI9_5 		= 23,
	IRQ_TIM1_BRK_TIM9	= 24,
#if defined(MCU_F410)
	IRQ_TIM1_UP			= 25,
#elif defined(MCU_F446)
	IRQ_TIM1_UP_TIM10	= 25,
#endif
	IRQ_TIM1_TRG_COM_TIM11	= 26,
	IRQ_TIM1_CC				= 27,
#if defined(MCU_F446)
	IRQ_TIM2				= 28,
	IRQ_TIM3				= 29,
	IRQ_TIM4				= 30,
#endif
	IRQ_I2C1_EV 			= 31,
	IRQ_I2C1_ER				= 32,
	IRQ_I2C2_EV				= 33,
	IRQ_I2C2_ER				= 34,
	IRQ_SPI1				= 35,
	IRQ_SPI2				= 36,
	IRQ_USART1				= 37,
	IRQ_USART2				= 38,
#if defined(MCU_F446)
	IRQ_USART3				= 39,
#endif
	IRQ_EXTI15_10			= 40,
#if defined(MCU_F410)
	IRQ_EXTI17_RTC_Alarm	= 41,
#elif defined(MCU_F446)
	IRQ_RTC_Alarm			= 41,
	IRQ_OTG_FS_WKUP			= 42,
	IRQ_TIM8_BRK_TIM12		= 43,
	IRQ_TIM8_UP_TIM13		= 44,
	IRQ_TIM8_TRG_COM_TIM14	= 45,
	IRQ_TIM8_CC				= 46,
#endif

	IRQ_DMA1_Stream7		= 47,
#if defined(MCU_F446)
	IRQ_FMC					= 48,
	IRQ_SDIO				= 49,
#endif

	IRQ_TIM5				= 50,
#if defined(MCU_F446)
	IRQ_SPI3				= 51,
	IRQ_UART4				= 52,
	IRQ_UART5				= 53,
#endif
	IRQ_TIM6_DAC 			= 54,
#if defined(MCU_F446)
	IRQ_TIM7				= 55,
#endif
	IRQ_DMA2_Stream0		= 56,
	IRQ_DMA2_Stream1		= 57,
	IRQ_DMA2_Stream2		= 58,
	IRQ_DMA2_Stream3		= 59,
	IRQ_DMA2_Stream4		= 60,
#if defined(MCU_F410)
	IRQ_EXTI19				= 62,
#endif
#if defined(MCU_F446)
	IRQ_CAN2_TX				= 63,
	IRQ_CAN2_RX0			= 64,
	IRQ_CAN2_RX1			= 65,
	IRQ_CAN2_SCE			= 66,
	IRQ_OTG_FS				= 67,
#endif
	IRQ_DMA2_Stream5		= 68,
	IRQ_DMA2_Stream6		= 69,
	IRQ_DMA2_Stream7		= 70,

} dtIRQs;

extern void NVIC_EnableIRQ(dtIRQs IRQ);
extern void NVIC_SetPriority(dtIRQs IRQ, uint8 IrqLevel);

#endif /* NVIC_NVIC_H_ */

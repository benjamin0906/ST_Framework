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
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_WWDG 			= 0,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_PVD				= 1,
#endif
#if defined(MCU_F410) || defined(MCU_F410)
	IRQ_EXTI21			= 2,
#elif defined(MCU_F446)
	IRQ_TAMP_STAMP		= 2,
#elif defined(MCU_G070) || defined(MCU_L433)
	IRQ_RTC_TAMP		= 2,
#endif
#if defined(MCU_F410) || defined(MCU_F410)
	IRQ_EXTI22			= 3,
#elif defined(MCU_F446) || defined(MCU_L433)
	IRQ_RTC_WKUP		= 3,
#elif defined(MCU_G070)
	IRQ_FLASH			= 3,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_FLASH			= 4,
#elif defined(MCU_G070)
	IRQ_RCC				= 4,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_RCC				= 5,
#elif defined(MCU_G070)
	IRQ_EXTI0_1			= 5,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_EXTI0			= 6,
#elif defined(MCU_G070)
	IRQ_EXTI2_3			= 6,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_EXTI1			= 7,
#elif defined(MCU_G070)
	IRQ_EXTI4_15		= 7,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_EXTI2			= 8,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_EXTI3			= 9,
#elif defined(MCU_G070)
	IRQ_DMA_Ch1			= 9,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_EXTI4			= 10,
#elif defined(MCU_G070)
	IRQ_DMA_Ch2_3		= 10,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream0	= 11,
#elif defined(MCU_G070)
	IRQ_DMA_Ch4_5_6_7	= 11,
#elif defined(MCU_L433)
	IRQ_DMA_CH1			= 11,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream1	= 12,
#elif defined(MCU_G070)
	IRQ_ADC				= 12,
#elif defined(MCU_L433)
	IRQ_DMA_CH2			= 12,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream2	= 13,
#elif defined(MCU_G070)
	IRQ_TIM1_BRK_UP_TRG	= 13,
#elif defined(MCU_L433)
	IRQ_DMA_CH3			= 13,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream3	= 14,
#elif defined(MCU_G070)
	IRQ_TIM1_CC			= 14,
#elif defined(MCU_L433)
	IRQ_DMA_CH4			= 14,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream4	= 15,
#elif defined(MCU_L433)
	IRQ_DMA_CH5			= 15,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream5	= 16,
#elif defined(MCU_G070)
	IRQ_TIM3			= 16,
#elif defined(MCU_L433)
	IRQ_DMA_CH6			= 16,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream6	= 17,
#elif defined(MCU_G070)
	IRQ_TIM6			= 17,
#elif defined(MCU_L433)
	IRQ_DMA_CH7			= 17,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_ADC				= 18,
#elif defined(MCU_G070)
	IRQ_TIM7			= 18,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_CAN1_TX			= 19,
#elif defined(MCU_G070)
	IRQ_TIM14			= 19,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_CAN1_RX0		= 20,
#elif defined(MCU_G070)
	IRQ_TIM15			= 20,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_CAN1_RX1		= 21,
#elif defined(MCU_G070)
	IRQ_TIM16			= 21,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_CAN1_SCE		= 22,
#elif defined(MCU_G070)
	IRQ_TIM17			= 22,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_EXTI9_5 		= 23,
#elif defined(MCU_G070)
	IRQ_I2C1			= 23,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_TIM1_BRK_TIM9	= 24,
#elif defined(MCU_G070)
	IRQ_I2C2			= 24,
#elif defined(MCU_L433)
	IRQ_TIM1_BRK_TIM15	= 24,
#endif
#if defined(MCU_F410)
	IRQ_TIM1_UP			= 25,
#elif defined(MCU_F446)
	IRQ_TIM1_UP_TIM10	= 25,
#elif defined(MCU_G070)
	IRQ_SPI1			= 25,
#elif defined(MCU_L433)
	IRQ_TIM1_UP_TIM16	= 25,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_TIM1_TRG_COM_TIM11	= 26,
#elif defined(MCU_G070)
	IRQ_SPI2				= 26,
#elif defined(MCU_L433)
	IRQ_TIM1_TRG_COM		= 26,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_TIM1_CC				= 27,
#elif defined(MCU_G070)
	IRQ_USART1				= 27,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_TIM2				= 28,
#elif defined(MCU_G070)
	IRQ_USART2				= 28,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_TIM3				= 29,
#elif defined(MCU_G070)
	IRQ_USART3_4			= 29,
#endif
#if defined(MCU_F446)
	IRQ_TIM4				= 30,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_I2C1_EV 			= 31,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_I2C1_ER				= 32,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_I2C2_EV				= 33,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_I2C2_ER				= 34,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_SPI1				= 35,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_SPI2				= 36,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_USART1				= 37,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_USART2				= 38,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_USART3				= 39,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_EXTI15_10			= 40,
#endif
#if defined(MCU_F410)
	IRQ_EXTI17_RTC_Alarm	= 41,
#elif defined(MCU_F446) || defined(MCU_L433)
	IRQ_RTC_Alarm			= 41,
#endif
#if defined(MCU_F446)
	IRQ_OTG_FS_WKUP			= 42,
#endif
#if defined(MCU_F446)
	IRQ_TIM8_BRK_TIM12		= 43,
#endif
#if defined(MCU_F446)
	IRQ_TIM8_UP_TIM13		= 44,
#endif
#if defined(MCU_F446)
	IRQ_TIM8_TRG_COM_TIM14	= 45,
#endif
#if defined(MCU_F446)
	IRQ_TIM8_CC				= 46,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA1_Stream7		= 47,
#endif
#if defined(MCU_F446)
	IRQ_FMC					= 48,
#endif
#if defined(MCU_F446)
	IRQ_SDIO				= 49,
#elif defined(MCU_L433)
	IRQ_SDMMC1				= 49,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_TIM5				= 50,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_SPI3				= 51,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_UART4				= 52,
#endif
#if defined(MCU_F446)
	IRQ_UART5				= 53,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_TIM6_DAC 			= 54,
#elif defined(MCU_L433)
	IRQ_TIM6_DACUNDER		= 54,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_TIM7				= 55,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream0		= 56,
#elif defined(MCU_L433)
	IRQ_DMA2_CH1			= 56,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream1		= 57,
#elif defined(MCU_L433)
	IRQ_DMA2_CH2			= 57,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream2		= 58,
#elif defined(MCU_L433)
	IRQ_DMA2_CH3			= 58,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream3		= 59,
#elif defined(MCU_L433)
	IRQ_DMA2_CH4			= 59,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream4		= 60,
#elif defined(MCU_L433)
	IRQ_DMA2_CH5			= 60,
#endif
#if defined(MCU_L433)
	IRQ_DFSDM1_FLT0			= 61,
#endif
#if defined(MCU_F410)
	IRQ_EXTI19				= 62,
#elif defined(MCU_L433)
	IRQ_DFSDM1_FLT1			= 62,
#endif
#if defined(MCU_F446)
	IRQ_CAN2_TX				= 63,
#endif
#if defined(MCU_F446)
	IRQ_CAN2_RX0			= 64,
#elif defined(MCU_L433)
	IRQ_COMP				= 64,
#endif
#if defined(MCU_F446)
	IRQ_CAN2_RX1			= 65,
#elif defined(MCU_L433)
	IRQ_LPTIM1				= 65,
#endif
#if defined(MCU_F446)
	IRQ_CAN2_SCE			= 66,
#elif defined(MCU_L433)
	IRQ_LPTIM2				= 66,
#endif
#if defined(MCU_F446)
	IRQ_OTG_FS				= 67,
#elif defined(MCU_L433)
	IRQ_USB_FS				= 67,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream5		= 68,
#elif defined(MCU_L433)
	IRQ_DMA2_CH6			= 68,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream6		= 69,
#elif defined(MCU_L433)
	IRQ_DMA2_CH7			= 69,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_DMA2_Stream7		= 70,
#elif defined(MCU_L433)
	IRQ_LPUART1				= 70,
#endif
#if defined(MCU_F446) || defined(MCU_F410)
	IRQ_USART6				= 71,
#elif defined(MCU_L433)
	IRQ_QUADSPI				= 71,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_I2C3_EV				= 72,
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	IRQ_I2C3_ER				= 73,
#endif
#if defined(MCU_F446)
	IRQ_OTG_HS_EP1_OUT		= 74,
#elif defined(MCU_L433)
	IRQ_SAI1				= 74,
#endif
#if defined(MCU_F446)
	IRQ_OTG_HS_EP1_IN		= 75,
#endif
#if defined(MCU_F446)
	IRQ_HS_WKUP				= 76,
#elif defined(MCU_F410)
	IRQ_EXTI20				= 76,
#elif defined(MCU_L433)
	IRQ_SWPMI1				= 76,
#endif
#if defined(MCU_F446)
	IRQ_OTG_HS				= 77,
#elif defined(MCU_L433)
	IRQ_TSC					= 77,
#endif
#if defined(MCU_F446)
	IRQ_DCMI				= 78,
#elif defined(MCU_L433)
	IRQ_LCD					= 78,
#endif
#if defined(MCU_L433)
	IRQ_AES					= 79,
#if defined(MCU_F410) || defined(MCU_L433)
	IRQ_RNG					= 80,
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433)
	IRQ_FPU					= 81,
#endif
#if defined(MCU_L433)
	IRQ_CRS					= 82,
#endif
#if defined(MCU_L433)
	IRQ_I2C4_EV				= 83,
#endif
#if defined(MCU_F446)
	IRQ_SPI4				= 84,
#elif defined(MCU_L433)
	IRQ_I2C4_ER				= 84,
#endif
#if defined(MCU_F410)
	IRQ_SPI5				= 85,
#endif
#if defined(MCU_F446)
	IRQ_SAI1				= 87,
#endif
#if defined(MCU_F446)
	IRQ_SAI2				= 91,
#endif
#if defined(MCU_F446)
	IRQ_QuadSPI				= 92,
#endif
#if defined(MCU_F446)
	IRQ_HDMI-CEC			= 93,
#endif
#if defined(MCU_F446)
	IRQ_SPDIF-Rx			= 94,
#endif
#if defined(MCU_F446)
	IRQ_FMPI2C1				= 95,
#elif defined(MCU_F410)
	IRQ_I2C4_EV				= 95,
#endif
#if defined(MCU_F446)
	IRQ_FMPI2C1_ER			= 96,
#endif

} dtIRQs;

extern void NVIC_EnableIRQ(dtIRQs IRQ);
extern void NVIC_SetPriority(dtIRQs IRQ, uint8 IrqLevel);

#endif /* NVIC_NVIC_H_ */

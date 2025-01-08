/*
 * DMAMUX.h
 *
 *  Created on: Jan 7, 2025
 *      Author: Benjamin
 */

#ifndef INC_DMAMUX_H_
#define INC_DMAMUX_H_

#if defined(MCU_G070)
typedef enum
{
	DmaMuxInput_ReqGen0 = 1,
	DmaMuxInput_ReqGen1,
	DmaMuxInput_ReqGen2,
	DmaMuxInput_ReqGen3,
	DmaMuxInput_ADC,
	DmaMuxInput_I2C1_RX = 10,
	DmaMuxInput_I2C1_TX,
	DmaMuxInput_I2C2_RX,
	DmaMuxInput_I2C2_TX,
	DmaMuxInput_SPI1_RX = 16,
	DmaMuxInput_SPI1_TX,
	DmaMuxInput_SPI2_RX,
	DmaMuxInput_SPI2_TX,
	DmaMuxInput_TIM1_CH1,
	DmaMuxInput_TIM1_CH2,
	DmaMuxInput_TIM1_CH3,
	DmaMuxInput_TIM1_CH4,
	DmaMuxInput_TIM1_TRIG_COM,
	DmaMuxInput_TIM1_UP,
	DmaMuxInput_TIM3_CH1 = 32,
	DmaMuxInput_TIM3_CH2,
	DmaMuxInput_TIM3_CH3,
	DmaMuxInput_TIM3_CH4,
	DmaMuxInput_TIM3_TRIG,
	DmaMuxInput_TIM3_UP,
	DmaMuxInput_TIM6_UP,
	DmaMuxInput_TIM7_UP,
	DmaMuxInput_TIM15_CH1,
	DmaMuxInput_TIM15_CH2,
	DmaMuxInput_TIM15_TRIG_COM,
	DmaMuxInput_TIM15_UP,
	DmaMuxInput_TIM16_CH1,
	DmaMuxInput_TIM16_COM,
	DmaMuxInput_TIM16_UP,
	DmaMuxInput_TIM17_CH1,
	DmaMuxInput_TIM17_COM,
	DmaMuxInput_TIM17_UP,
	DmaMuxInput_USART1_RX,
	DmaMuxInput_USART1_TX,
	DmaMuxInput_USART2_RX,
	DmaMuxInput_USART2_TX,
	DmaMuxInput_USART3_RX,
	DmaMuxInput_USART3_TX,
	DmaMuxInput_I2C3_RX = 62,
	DmaMuxInput_I2C3_TX,
	DmaMuxInput_SPI3_RX = 66,
	DmaMuxInput_SPI3_TX,
	DmaMuxInput_TIM4_CH1,
	DmaMuxInput_TIM4_CH2,
	DmaMuxInput_TIM4_CH3,
	DmaMuxInput_TIM4_CH4,
	DmaMuxInput_TIM4_TRIG,
	DmaMuxInput_TIM4_UP,
	DmaMuxInput_USART5_RX,
	DmaMuxInput_USART5_TX,
	DmaMuxInput_USART6_RX,
	DmaMuxInput_USART6_TX,

} dtMuxInput;

void DMAMUX_ChannelSimpleConfig(const uint8 channel, const dtMuxInput muxInput);

#endif

#endif /* INC_DMAMUX_H_ */

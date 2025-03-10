/*
 * GPIO.h
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "types.h"

typedef enum
{
#if defined(STM32U0) || defined(STM32L4)
	PortA_0 = 0,
	PortA_1,
	PortA_2,
	PortA_3,
	PortA_4,
	PortA_5,
	PortA_6,
	PortA_7,
	PortA_8,
	PortA_9,
	PortA_10,
	PortA_11,
	PortA_12,
	PortA_13,
	PortA_14,
	PortA_15,
#endif
#if defined(STM32U0) || defined(STM32L4)
	PortB_0 = 0x10,
	PortB_1,
	PortB_2,
	PortB_3,
	PortB_4,
	PortB_5,
	PortB_6,
	PortB_7,
	PortB_8,
	PortB_9,
	PortB_10,
	PortB_11,
	PortB_12,
	PortB_13,
	PortB_14,
	PortB_15,
#endif
#if defined(STM32U0) || defined(STM32L4)
	PortC_0 = 0x20,
	PortC_1,
	PortC_2,
	PortC_3,
	PortC_4,
	PortC_5,
	PortC_6,
	PortC_7,
	PortC_8,
	PortC_9,
	PortC_10,
	PortC_11,
	PortC_12,
	PortC_13,
	PortC_14,
	PortC_15,
#endif
#if defined(STM32U0) || defined(STM32L4)
	PortD_0 = 0x30,
	PortD_1,
	PortD_2,
	PortD_3,
	PortD_4,
	PortD_5,
	PortD_6,
	PortD_7,
	PortD_8,
	PortD_9,
	PortD_10,
	PortD_11,
	PortD_12,
	PortD_13,
	PortD_14,
	PortD_15,
#endif
#if defined(STM32U0) || defined(STM32L4)
	PortE_0 = 0x40,
	PortE_1,
	PortE_2,
	PortE_3,
	PortE_4,
	PortE_5,
	PortE_6,
	PortE_7,
	PortE_8,
	PortE_9,
	PortE_10,
	PortE_11,
	PortE_12,
	PortE_13,
	PortE_14,
	PortE_15,
#endif
#if defined(STM32U0) || defined(STM32L4)
	PortF_0 = 0x50,
	PortF_1,
	PortF_2,
	PortF_3,
	PortF_4,
	PortF_5,
	PortF_6,
	PortF_7,
	PortF_8,
	PortF_9,
	PortF_10,
	PortF_11,
	PortF_12,
	PortF_13,
	PortF_14,
	PortF_15,
#endif
#if defined(STM32L4)
	PortG_0 = 0x60,
	PortG_1,
	PortG_2,
	PortG_3,
	PortG_4,
	PortG_5,
	PortG_6,
	PortG_7,
	PortG_8,
	PortG_9,
	PortG_10,
	PortG_11,
	PortG_12,
	PortG_13,
	PortG_14,
	PortG_15,
#endif
#if defined(STM32L4)
	PortH_0 = 0x70,
	PortH_1,
	PortH_2,
	PortH_3,
	PortH_4,
	PortH_5,
	PortH_6,
	PortH_7,
	PortH_8,
	PortH_9,
	PortH_10,
	PortH_11,
	PortH_12,
	PortH_13,
	PortH_14,
	PortH_15,
#endif
} dtGPIOs;

enum eGPIO_MODE
{
	Input = 0,
	Output,
	Analog,
	Alt0,
	Alt1,
	Alt2,
	Alt3,
	Alt4,
	Alt5,
	Alt6,
	Alt7,
	Alt8,
	Alt9,
	Alt10,
	Alt11,
	Alt12,
	Alt13,
	Alt14,
	Alt15,
};

enum eGPIO_Type
{
	PushPull = 0,
	OpenDrain,
};

enum eGPIO_Speed
{
	Low = 0,
	Medium,
	High,
	VeryHigh,
};

enum eGPIO_Pulling
{
	NoPull = 0,
	PullUp,
	PullDown,
};

typedef struct
{
	uint32 Mode	    :6;
	uint32 Type     :1;
	uint32 Speed    :2;
	uint32 PUPD	    :2;
	uint32 DefState :1;
} dtGPIOConfig;

typedef enum
{
	Clear = 0,
	Set,
	Toggle,
} dtPortValue;

extern void GPIO_PinInit(dtGPIOs Gpio, const dtGPIOConfig Config);
extern void GPIO_PinDeinit(dtGPIOs Gpio);
extern void GPIO_Set(dtGPIOs Gpio, dtPortValue Value);
extern uint8 GPIO_Get(dtGPIOs Gpio);

#endif /* GPIO_GPIO_H_ */

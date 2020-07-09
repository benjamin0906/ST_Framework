/*
 * RCC_Types.h
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef RCC_RCC_TYPES_H_
#define RCC_RCC_TYPES_H_

#include "types.h"

#ifdef MCU_SOMETHING
typedef union
{
	struct
	{
		uint32 HSION	:1;
		uint32 HSIRDY	:1;
		uint32 			:1;
		uint32 HSITRIM	:5;
		uint32 HSICAL	:8;
		uint32 HSEON	:1;
		uint32 HSERDY	:1;
		uint32 HSEBYP	:1;
		uint32 CSSON	:1;
		uint32 			:4;
		uint32 PLLON	:1;
		uint32 PLLRDY	:1;
		uint32 			:6;
	} Fields;
	uint32 Word;
} dtCR;

typedef union
{
	struct
	{
		uint32 PLLM		:6;
		uint32 PLLN		:9;
		uint32 			:1;
		uint32 PLLP		:2;
		uint32 			:4;
		uint32 PLLSRC	:1;
		uint32 			:1;
		uint32 PLLQ		:4;
		uint32 PLLR		:3;
		uint32 			:1;
	} Fields;
	uint32 Word;
} dtPLLCFGR;

typedef union
{
	struct
	{
		uint32 SW		:2;
		uint32 SWS		:2;
		uint32 HRPE		:4;
		uint32 MCO1EN	:1;
		uint32 MCO2EN	:1;
		uint32 PPRE1	:3;
		uint32 PPRE2	:3;
		uint32 RTCPRE	:5;
		uint32 MCO1		:2;
		uint32 			:1;
		uint32 MCO1PRE	:3;
		uint32 MCO2PRE	:3;
		uint32 MCO2		:2;
	} Fields;
	uint32 Word;
} dtCFGR;

typedef union
{
	struct
	{
		uint32 LSIRDYF	:1;
		uint32 LSERDYF	:1;
		uint32 HSIRDYF	:1;
		uint32 HSERDYF	:1;
		uint32 PLLRDYF	:1;
		uint32 			:2;
		uint32 CSSF		:1;
		uint32 LSIRDYIE	:1;
		uint32 LSERDYIE	:1;
		uint32 HSIRDYIE	:1;
		uint32 HSERDYIE	:1;
		uint32 PLLRDYIE	:1;
		uint32 			:3;
		uint32 LSIRDYC	:1;
		uint32 LSERDYC	:1;
		uint32 HSIRDYC	:1;
		uint32 HSERDYC	:1;
		uint32 PLLRDYC	:1;
		uint32 			:2;
		uint32 CSSC		:1;
		uint32 			:8;
	} Fields;
	uint32 Word;
} dtCIR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	GPIOA	:1;
		uint32	GPIOB	:1;
		uint32	GPIOC	:1;
		uint32			:4;
		uint32	GPIOH	:1;
		uint32			:4;
		uint32	CRC		:1;
		uint32			:8;
		uint32	DMA1	:1;
		uint32	DMA2	:1;
		uint32			:8;
		uint32	RNG		:1;
	} Fields;
} dtAHB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32			:3;
		uint32	TIM5	:1;
		uint32	TIM6	:1;
		uint32			:4;
		uint32	LPTIM1	:1;
		uint32			:1;
		uint32	WWDG	:1;
		uint32			:2;
		uint32	SPI2	:1;
		uint32			:2;
		uint32	USART2	:1;
		uint32			:3;
		uint32	I2C1	:1;
		uint32	I2C2	:1;
		uint32			:1;
		uint32	I2C4	:1;
		uint32			:3;
		uint32	PWR		:1;
		uint32	DAC		:1;
		uint32			:2;
	} Fields;
} dtAPB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	TIM1	:1;
		uint32			:3;
		uint32	USART1	:1;
		uint32	USART6	:1;
		uint32			:2;
		uint32	ADC1	:1;
		uint32			:3;
		uint32	SPI1	:1;
		uint32			:1;
		uint32	SYSCFG	:1;
		uint32			:1;
		uint32	TIM9	:1;
		uint32			:1;
		uint32	TIM11	:1;
		uint32			:1;
		uint32	SPI5	:1;
		uint32			:11;
	} Fields;
} dtAPB2;

typedef struct
{
	dtAHB1 	AHB1;
	uint32 :32;
	uint32 :32;
	uint32 :32;
	dtAPB1	APB1;
	dtAPB2	APB2;
	uint32 :32;
	uint32 :32;
} dtBusGroup;

typedef struct
{
	dtCR CR;				//0x00
	dtPLLCFGR PLLCFGR;		//0x04
	dtCFGR CFGR;			//0x08
	dtCIR CIR;				//0x0C

	dtBusGroup RSTR;
	dtBusGroup ENR;
	dtBusGroup LPENR;

	uint32 BDRC;			//0x70
	uint32 CSR;				//0x74
	uint32 :32;				//0x78
	uint32 :32;				//0x7C
	uint32 SSCGR;			//0x80
	uint32 :32;				//0x84
	uint32 :32;				//0x88
	uint32 DCKCFGR;			//0x8C
	uint32 :32;				//0x90
	uint32 DCKCFGR2;		//0x94

} dtRCC;
#else
#ifdef MCU_F446
typedef union
{
	struct
	{
		uint32 HSION	:1;
		uint32 HSIRDY	:1;
		uint32 			:1;
		uint32 HSITRIM	:5;
		uint32 HSICAL	:8;
		uint32 HSEON	:1;
		uint32 HSERDY	:1;
		uint32 HSEBYP	:1;
		uint32 CSSON	:1;
		uint32 			:4;
		uint32 PLLON	:1;
		uint32 PLLRDY	:1;
		uint32 PLLI2SON	:1;
		uint32 PLLI2SRDY:1;
		uint32 PLLSAION	:1;
		uint32 PLLSAIRDY:1;
		uint32 			:2;
	} Fields;
	uint32 Word;
} dtCR;

typedef union
{
	struct
	{
		uint32 PLLM		:6;
		uint32 PLLN		:9;
		uint32 			:1;
		uint32 PLLP		:2;
		uint32 			:4;
		uint32 PLLSRC	:1;
		uint32 			:1;
		uint32 PLLQ		:4;
		uint32 PLLR		:3;
		uint32 			:1;
	} Fields;
	uint32 Word;
} dtPLLCFGR;

typedef union
{
	struct
	{
		uint32 SW		:2;
		uint32 SWS		:2;
		uint32 HRPE		:4;
		uint32 			:1;
		uint32 			:1;
		uint32 PPRE1	:3;
		uint32 PPRE2	:3;
		uint32 RTCPRE	:5;
		uint32 MCO1		:2;
		uint32 			:1;
		uint32 MCO1PRE	:3;
		uint32 MCO2PRE	:3;
		uint32 MCO2		:2;
	} Fields;
	uint32 Word;
} dtCFGR;

typedef union
{
	struct
	{
		uint32 LSIRDYF		:1;
		uint32 LSERDYF		:1;
		uint32 HSIRDYF		:1;
		uint32 HSERDYF		:1;
		uint32 PLLRDYF		:1;
		uint32 PLLI2SRDYF	:1;
		uint32 PLLSAIRDYF	:1;
		uint32 CSSF			:1;
		uint32 LSIRDYIE		:1;
		uint32 LSERDYIE		:1;
		uint32 HSIRDYIE		:1;
		uint32 HSERDYIE		:1;
		uint32 PLLRDYIE		:1;
		uint32 PLLI2SRDYIE	:1;
		uint32 PLLSAIRDYIE	:1;
		uint32 				:1;
		uint32 LSIRDYC		:1;
		uint32 LSERDYC		:1;
		uint32 HSIRDYC		:1;
		uint32 HSERDYC		:1;
		uint32 PLLRDYC		:1;
		uint32 PLLI2SRDYC	:1;
		uint32 PLLSAIRDYC	:1;
		uint32 CSSC			:1;
		uint32 				:8;
	} Fields;
	uint32 Word;
} dtCIR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	GPIOA	:1;
		uint32	GPIOB	:1;
		uint32	GPIOC	:1;
		uint32	GPIOD	:1;
		uint32	GPIOE	:1;
		uint32	GPIOF	:1;
		uint32	GPIOG	:1;
		uint32	GPIOH	:1;
		uint32			:4;
		uint32	CRC		:1;
		uint32			:5;
		uint32	BKPSRAM	:1;
		uint32			:2;
		uint32	DMA1	:1;
		uint32	DMA2	:1;
		uint32			:6;
		uint32	OTGH	:1;
		uint32	OTGHSULPI	:1;
		uint32			:1;
	} Fields;
} dtAHB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	DCMI	:1;
		uint32			:6;
		uint32	OTGFS	:1;
		uint32			:24;
	} Fields;
} dtAHB2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	FMC	:1;
		uint32	QSPI:1;
		uint32		:30;
	} Fields;
} dtAHB3;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	TIM2	:1;
		uint32	TIM3	:1;
		uint32	TIM4	:1;
		uint32	TIM5	:1;
		uint32	TIM6	:1;
		uint32	TIM7	:1;
		uint32	TIM12	:1;
		uint32	TIM13	:1;
		uint32	TIM14	:1;
		uint32			:2;
		uint32	WWDG	:1;
		uint32			:2;
		uint32	SPI2	:1;
		uint32	SPI3	:1;
		uint32	SPDIFRXRST:1;
		uint32	USART2	:1;
		uint32	USART3	:1;
		uint32	USART4	:1;
		uint32	USART5	:1;
		uint32	I2C1	:1;
		uint32	I2C2	:1;
		uint32	I2C3	:1;
		uint32	FMPI2C1	:1;
		uint32	CAN1	:1;
		uint32	CAN2	:1;
		uint32	CEC		:1;
		uint32	PWR		:1;
		uint32	DAC		:1;
		uint32			:2;
	} Fields;
} dtAPB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	TIM1	:1;
		uint32	TIM8	:1;
		uint32			:2;
		uint32	USART1	:1;
		uint32	USART6	:1;
		uint32			:2;
		uint32	ADC1	:1;
		uint32			:2;
		uint32 	SDIO	:1;
		uint32	SPI1	:1;
		uint32	SPI4	:1;
		uint32	SYSCFG	:1;
		uint32			:1;
		uint32	TIM9	:1;
		uint32	TIM10	:1;
		uint32	TIM11	:1;
		uint32			:3;
		uint32	SAI1	:1;
		uint32	SAI2	:1;
		uint32			:8;
	} Fields;
} dtAPB2;

typedef struct
{
	dtAHB1 	AHB1;
	dtAHB2 	AHB2;
	dtAHB3 	AHB3;
	uint32 :32;
	dtAPB1	APB1;
	dtAPB2	APB2;
	uint32 :32;
	uint32 :32;
} dtBusGroup;

typedef struct
{
	dtCR CR;				//0x00
	dtPLLCFGR PLLCFGR;		//0x04
	dtCFGR CFGR;			//0x08
	dtCIR CIR;				//0x0C

	dtBusGroup RSTR;
	dtBusGroup ENR;
	dtBusGroup LPENR;

	uint32 BDRC;			//0x70
	uint32 CSR;				//0x74
	uint32 :32;				//0x78
	uint32 :32;				//0x7C
	uint32 SSCGR;			//0x80
	uint32 PLLI2SCFGR;		//0x84
	uint32 PLLSAICFGR;		//0x88
	uint32 DCKCFGR;			//0x8C
	uint32 CKGATEENR;		//0x90
	uint32 DCKCFGR2;		//0x94

} dtRCC;
#endif
#endif

typedef enum
{
	Clear 	= 0,
	Set 	= 1,
} dtSetOrClear;

#endif /* RCC_RCC_TYPES_H_ */

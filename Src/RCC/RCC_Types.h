/*
 * RCC_Types.h
 *
 *  Created on: 2 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef RCC_RCC_TYPES_H_
#define RCC_RCC_TYPES_H_

#include "types.h"

#if defined(MCU_F410)
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
		uint32 HPRE		:4;
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
#elif defined(MCU_F446)
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
		uint32 HPRE		:4;
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
#elif defined(MCU_F415)
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
		uint32 			:4;
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
	} Fields;
	uint32 Word;
} dtPLLCFGR;

typedef union
{
	struct
	{
		uint32 SW		:2;
		uint32 SWS		:2;
		uint32 HPRE		:4;
		uint32 			:1;
		uint32 			:1;
		uint32 PPRE1	:3;
		uint32 PPRE2	:3;
		uint32 RTCPRE	:5;
		uint32 MCO1		:2;
		uint32 I2SSRC	:1;
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
		uint32 				:1;
		uint32 CSSF			:1;
		uint32 LSIRDYIE		:1;
		uint32 LSERDYIE		:1;
		uint32 HSIRDYIE		:1;
		uint32 HSERDYIE		:1;
		uint32 PLLRDYIE		:1;
		uint32 PLLI2SRDYIE	:1;
		uint32 				:1;
		uint32 				:1;
		uint32 LSIRDYC		:1;
		uint32 LSERDYC		:1;
		uint32 HSIRDYC		:1;
		uint32 HSERDYC		:1;
		uint32 PLLRDYC		:1;
		uint32 PLLI2SRDYC	:1;
		uint32 				:1;
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
		uint32	GPIOI	:1;
		uint32			:3;
		uint32	CRC		:1;
		uint32			:8;
		uint32	DMA1	:1;
		uint32	DMA2	:1;
		uint32			:2;
		uint32	ETHMAC	:1;
		uint32			:3;
		uint32	OTGHS	:1;
	} Fields;
} dtAHB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	DCMI	:1;
		uint32			:3;
		uint32	CRYP	:1;
		uint32	HSAH	:1;
		uint32	RNG		:1;
		uint32	OTGFS	:1;
		uint32			:24;
	} Fields;
} dtAHB2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	FSMC:1;
		uint32		:31;
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
		uint32			:1;
		uint32	USART2	:1;
		uint32	USART3	:1;
		uint32	USART4	:1;
		uint32	USART5	:1;
		uint32	I2C1	:1;
		uint32	I2C2	:1;
		uint32	I2C3	:1;
		uint32			:1;
		uint32	CAN1	:1;
		uint32	CAN2	:1;
		uint32			:1;
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
		uint32			:1;
		uint32	SYSCFG	:1;
		uint32			:1;
		uint32	TIM9	:1;
		uint32	TIM10	:1;
		uint32	TIM11	:1;
	} Fields;
} dtAPB2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 LSEON		:1;
		uint32 LSERDY		:1;
		uint32 LSEBYP		:1;
		uint32 				:5;
		uint32 RTC_SEL		:2;
		uint32 				:5;
		uint32 RTCEN		:1;
		uint32 BDRST		:1;
	} Fields;
} dtBDCR;

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

	dtBDCR BDCR;			//0x70
	uint32 CSR;				//0x74
	uint32 :32;				//0x78
	uint32 :32;				//0x7C
	uint32 SSCGR;			//0x80
	uint32 PLLI2SCFGR;		//0x84

} dtRCC;
#elif defined(MCU_G070) || defined(MCU_G071)
typedef union
{
	struct
	{
		uint32 			:8;
		uint32 HSION	:1;
		uint32 HSIKERON	:1;
		uint32 HSIRDY	:1;
		uint32 HSIDIV	:3;
		uint32 			:2;
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
		uint32 HSICAL	:8;
		uint32 HSITRIM	:7;
	} Fields;
	uint32 Word;
} dtICSCR;

typedef union
{
	struct
	{
		uint32 SW		:3;
		uint32 SWS		:3;
		uint32			:2;
		uint32 HPRE		:4;
		uint32 PPRE		:3;
		uint32 			:9;
		uint32 MCOSEL	:3;
		uint32 			:1;
		uint32 MCOPRE	:3;
	} Fields;
	uint32 Word;
} dtCFGR;

typedef union
{
	struct
	{
		uint32 PLLSRC	:2;
		uint32			:2;
		uint32 PLLM		:3;
		uint32			:1;
		uint32 PLLN		:7;
		uint32 			:1;
		uint32 PLLPEN	:1;
		uint32 PLLP		:5;
#if defined(MCU_G070)
		uint32 			:6;
#elif defined(MCU_G071)
		uint32			:2;
		uint32 PLLQEN	:1;
		uint32 PLLQ		:3;
#endif
		uint32 PLLREN	:1;
		uint32 PLLR		:3;
	} Fields;
	uint32 Word;
} dtPLLCFGR;

typedef union
{
	struct
	{
		uint32 LSIRDYIE		:1;
		uint32 LSERDYIE		:1;
		uint32				:1;
		uint32 HSIRDYIE		:1;
		uint32 HSERDYIE		:1;
		uint32 PLLRDYIE		:1;
	} Fields;
	uint32 Word;
} dtCIER;

typedef union
{
	struct
	{
		uint32 LSIRDYF		:1;
		uint32 LSERDYF		:1;
		uint32				:1;
		uint32 HSIRDYF		:1;
		uint32 HSERDYF		:1;
		uint32 PLLRDYF		:1;
		uint32				:2;
		uint32 CSSF			:1;
		uint32 LSECSSF		:1;
	} Fields;
	uint32 Word;
} dtCIFR;

typedef union
{
	struct
	{
		uint32 LSIRDYC		:1;
		uint32 LSERDYC		:1;
		uint32				:1;
		uint32 HSIRDYC		:1;
		uint32 HSERDYC		:1;
		uint32 PLLRDYC		:1;
		uint32				:2;
		uint32 CSSC			:1;
		uint32 LSECSSC		:1;
	} Fields;
	uint32 Word;
} dtCICR;

typedef union
{
	struct
	{
		uint32 GPIOA		:1;
		uint32 GPIOB		:1;
		uint32 GPIOC		:1;
		uint32 GPIOD		:1;
		uint32 				:1;
		uint32 GPIOF		:1;
	} Fields;
	uint32 Word;
} dtIOP;

typedef union
{
	struct
	{
		uint32 DMA			:1;
		uint32				:7;
		uint32 FLASH		:1;
		uint32				:3;
		uint32 CRC			:1;
#if defined(MCU_G071)
		uint32 				:3;
		uint32 AES			:1;
		uint32				:1;
		uint32 RNG			:1;
#endif
	} Fields;
	uint32 Word;
} dtAHB;

typedef union
{
	uint32 Word;
	struct
	{
#if defined(MCU_G070)
		uint32				:1;
#elif defined(MCU_G071)
		uint32 TIM2			:1;
#endif
		uint32 TIM3			:1;
		uint32 				:2;
		uint32 TIM6			:1;
		uint32 TIM7			:1;
		uint32 				:8;
		uint32 SPI2			:1;
		uint32 				:2;
		uint32 USART2		:1;
		uint32 USART3		:1;
		uint32 USART4		:1;
#if defined(MCU_G070)
		uint32 				:1;
#elif defined(MCU_G071)
		uint32 LPUART1		:1;
#endif
		uint32 I2C1			:1;
		uint32 I2C2			:1;
#if defined(MCU_G070)
		uint32 				:4;
#elif defined(MCU_G071)
		uint32				:1;
		uint32 CEC			:1;
		uint32 UCPD1		:1;
		uint32 UCPD2		:1;
#endif
		uint32 DBG			:1;
		uint32 PWR			:1;
#if defined(MCU_G071)
		uint32 DAC1			:1;
		uint32 LPTIM2		:1;
		uint32 LPTIM1		:1;
#endif
	} Fields;
} dtAPB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 SYSCFG		:1;
		uint32 				:10;
		uint32 TIM1			:1;
		uint32 SPI1			:1;
		uint32 				:1;
		uint32 USART1		:1;
		uint32 TIM14		:1;
		uint32 TIM15		:1;
		uint32 TIM16		:1;
		uint32 TIM17		:1;
		uint32 				:1;
		uint32 ADC			:1;
	} Fields;
} dtAPB2;

typedef struct
{
	dtIOP 	IOP;	//+0x00
	dtAHB	AHB;	//+0x04
	dtAPB1	APB1;	//+0x08
	dtAPB2	APB2;	//+0x0C
} dtBusGroup;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 USART1SEL	:2;
		uint32 USART2SEL	:2;
#if defined(MCU_G070)
		uint32 				:8;
#elif defined(MCU_G071)
		uint32				:2;
		uint32 CECSEL		:1;
		uint32				:3;
		uint32 LPUART1SEL	:2;
#endif
		uint32 I2C1SEL		:2;
		uint32 I2S1SEL		:2;
#if defined(MCU_G070)
		uint32 				:14;
#elif defined(MCU_G071)
		uint32				:2;
		uint32 LPTIM1SEL	:2;
		uint32 LPTIM2SEL	:2;
		uint32 TIM1SEL		:1;
		uint32				:1;
		uint32 TIM15SEL		:1;
		uint32				:1;
		uint32 RNGSEL		:2;
		uint32 RNGDIV		:2;
#endif
		uint32 ADCSEL		:2;
	} Fields;
} dtCCIPR;

typedef union
{
	uint32 Word;
	struct
	{

		uint32 LSEON		:1;
		uint32 LSERDY		:1;
		uint32 LSEBYP		:1;
		uint32 LSE_DRV		:2;
		uint32 LSECSSON		:1;
		uint32 LSECSSD		:1;
		uint32 				:1;
		uint32 RTC_SEL		:2;
		uint32 				:5;
		uint32 RTCEN		:1;
		uint32 BDRST		:1;
		uint32 				:7;
		uint32 LSCOEN		:1;
		uint32 LSCOSEL		:1;
	} Fields;
} dtBDCR;

typedef union
{
	uint32 Word;
	struct
	{

		uint32 LSION		:1;
		uint32 LSIRDY		:1;
		uint32 				:21;
		uint32 RMVF			:1;
		uint32 				:1;
		uint32 OBLRSTF		:1;
		uint32 PINRSTF		:1;
		uint32 PWRRSTF		:1;
		uint32 SFTRSTF		:1;
		uint32 IWDGRSTF		:1;
		uint32 WWDGRSTF		:1;
		uint32 LPWRRSTF		:1;
	} Fields;
} dtCSR;

typedef struct
{
	dtCR 		CR;			//0x00
	dtICSCR		ICSCR;		//0x04
	dtCFGR 		CFGR;		//0x08
	dtPLLCFGR 	PLLCFGR;	//0x0C
	uint32		:32;		//0x10
	uint32		:32;		//0x14
	dtCIER		CIER;		//0x18
	dtCIFR		CIFR;		//0x1C
	dtCICR		CICR;		//0x20
	dtBusGroup 	RSTR;		//0x24
	dtBusGroup 	ENR;		//0x34
	dtBusGroup 	SMENR;		//0x44
	dtCCIPR		CCIPR;		//0x54
	uint32		:32;		//0x58
	dtBDCR		BDCR;		//0x5C
	dtCSR		CSR;		//0x60

} dtRCC;
#elif defined(MCU_L433)
typedef union
{
	uint32 Word;
	struct
	{
		uint32	MSION		:1;
		uint32	MSIRDY		:1;
		uint32	MSIPLLEN	:1;
		uint32	MSIRGSEL	:1;
		uint32	MSIRANGE	:4;
		uint32	HSION		:1;
		uint32	HSIKERON	:1;
		uint32	HSIRDY		:1;
		uint32	HSIASFS		:1;
		uint32				:4;
		uint32	HSEON		:1;
		uint32	HSERDY		:1;
		uint32	HSEBYP		:1;
		uint32	CSSON		:1;
		uint32				:4;
		uint32	PLLON		:1;
		uint32	PLLRDY		:1;
		uint32	PLLSAI1ON	:1;
		uint32	PLLSAI1RDY	:1;
	} Fields;
} dtCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	MSI_CAL		:8;
		uint32	MSI_TRIM	:8;
		uint32	HSI_CAL		:8;
		uint32	HSI_TRIM	:8;
	} Fields;
} dtICSCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	SW			:2;
		uint32	SWS			:2;
		uint32	HPRE		:4;
		uint32	PPRE1		:3;
		uint32	PPRE2		:3;
		uint32				:1;
		uint32	STOP_WUCK	:1;
		uint32				:8;
		uint32	MCOSEL		:4;
		uint32	MCOPRE		:3;
	} Fields;
} dtCFGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	PLLSRC		:2;
		uint32				:2;
		uint32	PLLM		:3;
		uint32				:1;
		uint32	PLLN		:7;
		uint32				:1;
		uint32	PLLPEN		:1;
		uint32	PLLP		:1;
		uint32				:2;
		uint32	PLLQEN		:1;
		uint32	PLLQ		:2;
		uint32				:1;
		uint32	PLLREN		:1;
		uint32	PLLR		:2;
		uint32	PLLPDIV		:5;
	} Fields;
} dtPLLCFGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32				:8;
		uint32	PLLSAI1N	:7;
		uint32				:1;
		uint32	PLLSAI1PEN	:1;
		uint32	PLLSAI1P	:1;
		uint32				:2;
		uint32	PLLSAI1QEN	:1;
		uint32	PLLSAI1Q	:2;
		uint32				:1;
		uint32	PLLSAI1REN	:1;
		uint32	PLLSAI1R	:2;
		uint32	PLLSAI1PDIV	:5;
	} Fields;
} dtPLLSAI1CFGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSIRDYIE	:1;
		uint32	LSERDYIE	:1;
		uint32	MSIRDYIE	:1;
		uint32	HSIRDYIE	:1;
		uint32	HSERDYIE	:1;
		uint32	PLLRDYIE	:1;
		uint32	PLLSAI1RDYIE:1;
		uint32				:2;
		uint32	LSECSSIE	:1;
		uint32	HSI48RDYIE	:1;
	} Fields;
} dtCIER;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSIRDYF		:1;
		uint32	LSERDYF		:1;
		uint32	MSIRDYF		:1;
		uint32	HSIRDYF		:1;
		uint32	HSERDYF		:1;
		uint32	PLLRDYF		:1;
		uint32	PLLSAI1RDYF	:1;
		uint32				:1;
		uint32	CSSF		:1;
		uint32	LSECSSF		:1;
		uint32	HSI48RDYF	:1;
	} Fields;
} dtCIFR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSIRDYC		:1;
		uint32	LSERDYC		:1;
		uint32	MSIRDYC		:1;
		uint32	HSIRDYC		:1;
		uint32	HSERDYC		:1;
		uint32	PLLRDYC		:1;
		uint32	PLLSAI1RDYC	:1;
		uint32				:1;
		uint32	CSSC		:1;
		uint32	LSECSSC		:1;
		uint32	HSI48RDYC	:1;
	} Fields;
} dtCICR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	DMA1		:1;
		uint32	DMA2		:1;
		uint32				:6;
		uint32	FLASH		:1;
		uint32				:3;
		uint32	CRC			:1;
		uint32				:3;
		uint32	TSC			:1;
	} Fields;
} dtAHB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	GPIOA		:1;
		uint32	GPIOB		:1;
		uint32	GPIOC		:1;
		uint32	GPIOD		:1;
		uint32	GPIOE		:1;
		uint32				:2;
		uint32	GPIOH		:1;
		uint32				:5;
		uint32	ADC			:1;
		uint32				:2;
		uint32	AES			:1;
		uint32				:1;
		uint32	RNG			:1;
	} Fields;
} dtAHB2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32				:8;
		uint32	QSPI		:1;
	} Fields;
} dtAHB3;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	TIM2		:1;
		uint32	TIM3		:1;
		uint32				:2;
		uint32	TIM6		:1;
		uint32	TIM7		:1;
		uint32				:3;
		uint32	LCD			:1;
		uint32				:4;
		uint32	SPI2		:1;
		uint32	SPI3		:1;
		uint32				:1;
		uint32	USART2		:1;
		uint32	USART3		:1;
		uint32	USART4		:1;
		uint32				:1;
		uint32	I2C1		:1;
		uint32	I2C2		:1;
		uint32	I2C3		:1;
		uint32	CRS			:1;
		uint32	CAN1		:1;
		uint32	USBFS		:1;
		uint32				:1;
		uint32	PWR			:1;
		uint32	DAC1		:1;
		uint32	OPAMP		:1;
		uint32	LPTIM1		:1;
	} Fields;
} dtAPB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LPUART1		:1;
		uint32	I2C4		:1;
		uint32	SWPMI1		:1;
		uint32				:2;
		uint32	LPTIM2		:1;
	} Fields;
} dtAPB1_2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	SYSCFG		:1;
		uint32				:9;
		uint32	SDMMC1		:1;
		uint32	TIM1		:1;
		uint32	SPI1		:1;
		uint32				:1;
		uint32	USART1		:1;
		uint32				:1;
		uint32	TIM15		:1;
		uint32	TIM16		:1;
		uint32				:3;
		uint32	SAI1		:1;
		uint32				:2;
		uint32	DFSDM1		:1;
	} Fields;
} dtAPB2;

typedef struct
{
	uint32		:32;	//0x04
	dtAHB1		AHB1;	//0x08
	dtAHB2		AHB2;	//0x0C
	dtAHB3		AHB3;	//0x10
	uint32		:32;	//0x14
	dtAPB1		APB1;	//0x18
	dtAPB1_2	APB1_2;	//0x1C
	dtAPB2		APB2;	//0x20
} dtBusGroup;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	USART1SEL	:2;
		uint32	USART2SEL	:2;
		uint32	USART3SEL	:2;
		uint32	USART4SEL	:2;
		uint32				:2;
		uint32	LPUART1SEL	:2;
		uint32	I2C1SEL		:2;
		uint32	I2C2SEL		:2;
		uint32	I2C3SEL		:2;
		uint32	LPTIM1SEL	:2;
		uint32	LPTIM2SEL	:2;
		uint32	SAI1SEL		:2;
		uint32				:2;
		uint32	CLK48SEL	:2;
		uint32	ADCSEL		:2;
		uint32	SWPMI1SEL	:1;
		uint32				:1;
	} Fields;
} dtCCIPR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSEON		:1;
		uint32	LSERDY		:1;
		uint32	LSEBYP		:1;
		uint32	LSEDRV		:2;
		uint32	LSECSSON	:1;
		uint32	LSECSSD		:1;
		uint32	LSESYSDIS	:1;
		uint32	RTCSEL		:2;
		uint32				:5;
		uint32	RTCEN		:1;
		uint32	BDRST		:1;
		uint32				:7;
		uint32	LSCOEN		:1;
		uint32	LSCOSEL		:1;
	} Fields;
} dtBDCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSION		:1;
		uint32	LSIRDY		:1;
		uint32				:2;
		uint32	LSIPREDIV	:1;
		uint32				:3;
		uint32	MSISRANGE	:4;
		uint32				:11;
		uint32	RMVF		:1;
		uint32	FWRSTF		:1;
		uint32	OBLRSTF		:1;
		uint32	PINRSTF		:1;
		uint32	BORRSTF		:1;
		uint32	SFTRSTF		:1;
		uint32	IWWGRSTF	:1;
		uint32	WWDGRSTF	:1;
		uint32	LPWRRSTF	:1;
	} Fields;
} dtCSR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	HSI48ON		:1;
		uint32	HSI48RDY	:1;
		uint32				:5;
		uint32	HSI48CAL	:9;
	} Fields;
} dtCRRCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	I2C4SEL		:2;
	} Fields;
} dtCCIPR2;

typedef struct
{
	dtCR			CR;				//0x00
	dtICSCR			ICSCR;			//0x04
	dtCFGR			CFGR;			//0x08
	dtPLLCFGR		PLLCFGR;		//0x0C
	dtPLLSAI1CFGR	PLLSAI1CFGR;	//0x10
	uint32			:32;			//0x14
	dtCIER			CIER;			//0x18
	dtCIFR			CIFR;			//0x1C
	dtCICR			CICR;			//0x20
	dtBusGroup		RSTR;			//0x24
	dtBusGroup		ENR;
	dtBusGroup		SMENR;
	dtCCIPR			CCIPR;
	dtBDCR			BDCR;
	dtCSR			CSR;
	dtCRRCR			CRRCR;
	dtCCIPR2		CCIPR2;
} dtRCC;

/*typedef union
{
	uint32 Word;
	struct
	{
		uint32	:;
	} Fields;
} dt;*/
#elif defined(MCU_L476)
typedef union
{
	uint32 Word;
	struct
	{
		uint32	MSION		:1;
		uint32	MSIRDY		:1;
		uint32	MSIPLLEN	:1;
		uint32	MSIRGSEL	:1;
		uint32	MSIRANGE	:4;
		uint32	HSION		:1;
		uint32	HSIKERON	:1;
		uint32	HSIRDY		:1;
		uint32	HSIASFS		:1;
		uint32				:4;
		uint32	HSEON		:1;
		uint32	HSERDY		:1;
		uint32	HSEBYP		:1;
		uint32	CSSON		:1;
		uint32				:4;
		uint32	PLLON		:1;
		uint32	PLLRDY		:1;
		uint32	PLLSAI1ON	:1;
		uint32	PLLSAI1RDY	:1;
		uint32	PLLSAI2ON	:1;
		uint32	PLLSAI2RDY	:1;
	} Fields;
} dtCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	MSI_CAL		:8;
		uint32	MSI_TRIM	:8;
		uint32	HSI_CAL		:8;
		uint32	HSI_TRIM	:7;
	} Fields;
} dtICSCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	SW			:2;
		uint32	SWS			:2;
		uint32	HPRE		:4;
		uint32	PPRE1		:3;
		uint32	PPRE2		:3;
		uint32				:1;
		uint32	STOP_WUCK	:1;
		uint32				:8;
		uint32	MCOSEL		:4;
		uint32	MCOPRE		:3;
	} Fields;
} dtCFGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	PLLSRC		:2;
		uint32				:2;
		uint32	PLLM		:3;
		uint32				:1;
		uint32	PLLN		:7;
		uint32				:1;
		uint32	PLLPEN		:1;
		uint32	PLLP		:1;
		uint32				:2;
		uint32	PLLQEN		:1;
		uint32	PLLQ		:2;
		uint32				:1;
		uint32	PLLREN		:1;
		uint32	PLLR		:2;
		uint32	PLLPDIV		:5;
	} Fields;
} dtPLLCFGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32				:8;
		uint32	PLLSAI1N	:7;
		uint32				:1;
		uint32	PLLSAI1PEN	:1;
		uint32	PLLSAI1P	:1;
		uint32				:2;
		uint32	PLLSAI1QEN	:1;
		uint32	PLLSAI1Q	:2;
		uint32				:1;
		uint32	PLLSAI1REN	:1;
		uint32	PLLSAI1R	:2;
		uint32	PLLSAI1PDIV	:5;
	} Fields;
} dtPLLSAI1CFGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32				:8;
		uint32	PLLSAI2N	:7;
		uint32				:1;
		uint32	PLLSAI2PEN	:1;
		uint32	PLLSAI2P	:1;
		uint32				:2;
		uint32				:1;
		uint32				:2;
		uint32				:1;
		uint32	PLLSAI2REN	:1;
		uint32	PLLSAI2R	:2;
		uint32	PLLSAI2PDIV	:5;
	} Fields;
} dtPLLSAI2CFGR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSIRDYIE	:1;
		uint32	LSERDYIE	:1;
		uint32	MSIRDYIE	:1;
		uint32	HSIRDYIE	:1;
		uint32	HSERDYIE	:1;
		uint32	PLLRDYIE	:1;
		uint32	PLLSAI1RDYIE:1;
		uint32	PLLSAI2RDYIE:1;
		uint32				:1;
		uint32	LSECSSIE	:1;
		uint32	HSI48RDYIE	:1;
	} Fields;
} dtCIER;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSIRDYF		:1;
		uint32	LSERDYF		:1;
		uint32	MSIRDYF		:1;
		uint32	HSIRDYF		:1;
		uint32	HSERDYF		:1;
		uint32	PLLRDYF		:1;
		uint32	PLLSAI1RDYF	:1;
		uint32	PLLSAI2RDYF	:1;
		uint32	CSSF		:1;
		uint32	LSECSSF		:1;
		uint32	HSI48RDYF	:1;
	} Fields;
} dtCIFR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSIRDYC		:1;
		uint32	LSERDYC		:1;
		uint32	MSIRDYC		:1;
		uint32	HSIRDYC		:1;
		uint32	HSERDYC		:1;
		uint32	PLLRDYC		:1;
		uint32	PLLSAI1RDYC	:1;
		uint32	PLLSAI2RDYC	:1;
		uint32	CSSC		:1;
		uint32	LSECSSC		:1;
		uint32	HSI48RDYC	:1;
	} Fields;
} dtCICR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	DMA1		:1;
		uint32	DMA2		:1;
		uint32				:6;
		uint32	FLASH		:1;
		uint32				:3;
		uint32	CRC			:1;
		uint32				:3;
		uint32	TSC			:1;
		uint32	DMA2D		:1;
	} Fields;
} dtAHB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	GPIOA		:1;
		uint32	GPIOB		:1;
		uint32	GPIOC		:1;
		uint32	GPIOD		:1;
		uint32	GPIOE		:1;
		uint32	GPIOF		:1;
		uint32	GPIOG		:1;
		uint32	GPIOH		:1;
		uint32	GPIOI		:1;
		uint32				:3;
		uint32	OTGFS		:1;
		uint32	ADC			:1;
		uint32	DCMI		:1;
		uint32				:1;
		uint32	AES			:1;
		uint32	HASH		:1;
		uint32	RNG			:1;
	} Fields;
} dtAHB2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	FMC			:1;
		uint32				:7;
		uint32	QSPI		:1;
	} Fields;
} dtAHB3;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	TIM2		:1;
		uint32	TIM3		:1;
		uint32	TIM4		:1;
		uint32	TIM5		:1;
		uint32	TIM6		:1;
		uint32	TIM7		:1;
		uint32				:3;
		uint32	LCD			:1;
		uint32				:4;
		uint32	SPI2		:1;
		uint32	SPI3		:1;
		uint32				:1;
		uint32	USART2		:1;
		uint32	USART3		:1;
		uint32	USART4		:1;
		uint32	USART5		:1;
		uint32	I2C1		:1;
		uint32	I2C2		:1;
		uint32	I2C3		:1;
		uint32	CRS			:1;
		uint32	CAN1		:1;
		uint32	CAN2		:1;
		uint32				:1;
		uint32	PWR			:1;
		uint32	DAC1		:1;
		uint32	OPAMP		:1;
		uint32	LPTIM1		:1;
	} Fields;
} dtAPB1;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LPUART1		:1;
		uint32	I2C4		:1;
		uint32	SWPMI1		:1;
		uint32				:2;
		uint32	LPTIM2		:1;
	} Fields;
} dtAPB1_2;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	SYSCFG		:1;
		uint32				:9;
		uint32	SDMMC1		:1;
		uint32	TIM1		:1;
		uint32	SPI1		:1;
		uint32	TIM8		:1;
		uint32	USART1		:1;
		uint32				:1;
		uint32	TIM15		:1;
		uint32	TIM16		:1;
		uint32	TIM17		:1;
		uint32				:2;
		uint32	SAI1		:1;
		uint32	SAI2		:1;
		uint32				:1;
		uint32	DFSDM1		:1;
	} Fields;
} dtAPB2;

typedef struct
{
	uint32		:32;	//0x04
	dtAHB1		AHB1;	//0x08
	dtAHB2		AHB2;	//0x0C
	dtAHB3		AHB3;	//0x10
	uint32		:32;	//0x14
	dtAPB1		APB1;	//0x18
	dtAPB1_2	APB1_2;	//0x1C
	dtAPB2		APB2;	//0x20
} dtBusGroup;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	USART1SEL	:2;
		uint32	USART2SEL	:2;
		uint32	USART3SEL	:2;
		uint32	USART4SEL	:2;
		uint32	USART5SEL	:2;
		uint32	LPUART1SEL	:2;
		uint32	I2C1SEL		:2;
		uint32	I2C2SEL		:2;
		uint32	I2C3SEL		:2;
		uint32	LPTIM1SEL	:2;
		uint32	LPTIM2SEL	:2;
		uint32	SAI1SEL		:2;
		uint32	SAI2SEL		:2;
		uint32	CLK48SEL	:2;
		uint32	ADCSEL		:2;
		uint32	SWPMI1SEL	:1;
		uint32	DFSDM1SEL	:1;
	} Fields;
} dtCCIPR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSEON		:1;
		uint32	LSERDY		:1;
		uint32	LSEBYP		:1;
		uint32	LSEDRV		:2;
		uint32	LSECSSON	:1;
		uint32	LSECSSD		:1;
		uint32				:1;
		uint32	RTC_SEL		:2;
		uint32				:5;
		uint32	RTCEN		:1;
		uint32	BDRST		:1;
		uint32				:7;
		uint32	LSCOEN		:1;
		uint32	LSCOSEL		:1;
	} Fields;
} dtBDCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	LSION		:1;
		uint32	LSIRDY		:1;
		uint32				:2;
		uint32				:1;
		uint32				:3;
		uint32	MSISRANGE	:4;
		uint32				:11;
		uint32	RMVF		:1;
		uint32	FWRSTF		:1;
		uint32	OBLRSTF		:1;
		uint32	PINRSTF		:1;
		uint32	BORRSTF		:1;
		uint32	SFTRSTF		:1;
		uint32	IWWGRSTF	:1;
		uint32	WWDGRSTF	:1;
		uint32	LPWRRSTF	:1;
	} Fields;
} dtCSR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	HSI48ON		:1;
		uint32	HSI48RDY	:1;
		uint32				:5;
		uint32	HSI48CAL	:9;
	} Fields;
} dtCRRCR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32	I2C4SEL		:2;
	} Fields;
} dtCCIPR2;

typedef struct
{
	dtCR			CR;				//0x00
	dtICSCR			ICSCR;			//0x04
	dtCFGR			CFGR;			//0x08
	dtPLLCFGR		PLLCFGR;		//0x0C
	dtPLLSAI1CFGR	PLLSAI1CFGR;	//0x10
	dtPLLSAI2CFGR	PLLSAI2CFGR;	//0x14
	dtCIER			CIER;			//0x18
	dtCIFR			CIFR;			//0x1C
	dtCICR			CICR;			//0x20
	dtBusGroup		RSTR;			//0x24
	dtBusGroup		ENR;
	dtBusGroup		SMENR;
	dtCCIPR			CCIPR;
	dtBDCR			BDCR;
	dtCSR			CSR;
	dtCRRCR			CRRCR;
	dtCCIPR2		CCIPR2;
} dtRCC;
#endif

typedef enum
{
	Clock_Clear 	= 0,
	Clock_Set 	= 1,
} dtClockSetOrClear;

#endif /* RCC_RCC_TYPES_H_ */

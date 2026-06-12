/*
 * RCC_regdef.h
 *
 *  Created on: Mar 7, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_RCC_REGDEF_H_
#define INC_REGDEFS_RCC_REGDEF_H_

#include "RegDefs/regdef_helper.h"

#if defined(STM32U0)
typedef struct sRCC_CR_Bits
{
    uint32  MSION       :1;
    uint32  MSIRDY      :1;
    uint32  MSIPLLEN    :1;
    uint32  MSIRGSEL    :1;
    uint32  MSIRANGE    :4;
    uint32  HSION       :1;
    uint32  HSIKERON    :1;
    uint32  HSIRDY      :1;
    uint32  HSIASFS     :1;
    uint32              :4;
    uint32  HSEON       :1;
    uint32  HSERDY      :1;
    uint32  HSEBYP      :1;
    uint32  CSSON       :1;
    uint32              :4;
    uint32  PLLON       :1;
    uint32  PLLRDY      :1;
    uint32              :6;
} dtRCC_CR_Bits;

typedef struct sRCC_ICSCR_Bits
{
    uint32  MSI_CAL     :8;
    uint32  MSI_TRIM    :8;
    uint32  HSI_CAL     :8;
    uint32  HSI_TRIM    :7;
    uint32              :1;
} dtRCC_ICSCR_Bits;

typedef struct sRCC_CFGR_Bits
{
        uint32  SW          :3;
        uint32  SWS         :3;
        uint32              :2;
        uint32  HPRE        :4;
        uint32  PPRE        :3;
        uint32  STOP_WUCK   :1;
        uint32  MCO2SEL     :4;
        uint32  MCO2PRE     :4;
        uint32  MCOSEL      :4;
        uint32  MCOPRE      :4;
} dtRCC_CFGR_Bits;

typedef struct sRCC_PLLCFGR_Bits
{
    uint32  PLLSRC      :2;
    uint32              :2;
    uint32  PLLM        :3;
    uint32              :1;
    uint32  PLLN        :7;
    uint32              :1;
    uint32  PLLPEN      :1;
    uint32  PLLP        :5;
    uint32              :2;
    uint32  PLLQEN      :1;
    uint32  PLLQ        :3;
    uint32  PLLREN      :1;
    uint32  PLLR        :3;
} dtRCC_PLLCFGR_Bits;

typedef struct sRCC_CIER_Bits
{
    uint32  LSIRDYIE    :1;
    uint32  LSERDYIE    :1;
    uint32  MSIRDYIE    :1;
    uint32  HSIRDYIE    :1;
    uint32  HSERDYIE    :1;
    uint32  PLLRDYIE    :1;
    uint32              :1;
    uint32              :1;
    uint32              :1;
    uint32  LSECSSIE    :1;
    uint32  HSI48RDYIE  :1;
    uint32              :21;
} dtRCC_CIER_Bits;

typedef struct sRCC_CIFR_Bits
{
    uint32  LSIRDYF     :1;
    uint32  LSERDYF     :1;
    uint32  MSIRDYF     :1;
    uint32  HSIRDYF     :1;
    uint32  HSERDYF     :1;
    uint32  PLLRDYF     :1;
    uint32              :1;
    uint32              :1;
    uint32  CSSF        :1;
    uint32  LSECSSF     :1;
    uint32  HSI48RDYF   :1;
    uint32              :21;
} dtRCC_CIFR_Bits;

typedef struct sRCC_CICR_Bits
{
    uint32  LSIRDYC     :1;
    uint32  LSERDYC     :1;
    uint32  MSIRDYC     :1;
    uint32  HSIRDYC     :1;
    uint32  HSERDYC     :1;
    uint32  PLLRDYC     :1;
    uint32              :1;
    uint32              :1;
    uint32  CSSC        :1;
    uint32  LSECSSC     :1;
    uint32  HSI48RDYC   :1;
    uint32              :21;
} dtRCC_CICR_Bits;

typedef struct sRCC_AHB_Bits
{
    uint32  DMA1        :1;
    uint32  DMA2        :1;
    uint32              :6;
    uint32  FLASH       :1;
    uint32              :3;
    uint32  CRC         :1;
    uint32              :3;
    uint32  AES         :1;
    uint32              :1;
    uint32  RNG         :1;
    uint32              :5;
    uint32  TSC         :1;
    uint32              :7;
} dtRCC_AHB_Bits;

typedef struct sRCC_IOP_Bits
{
    uint32 GPIOA        :1;
    uint32 GPIOB        :1;
    uint32 GPIOC        :1;
    uint32 GPIOD        :1;
    uint32 GPIOE        :1;
    uint32 GPIOF        :1;
    uint32              :26;
} dtRCC_IOP_Bits;

typedef struct sRCC_APB1_Bits
{
    uint32  TIM2        :1;
    uint32  TIM3        :1;
    uint32              :2;
    uint32  TIM6        :1;
    uint32  TIM7        :1;
    uint32              :1;
    uint32 LPUART2      :1;
    uint32              :1;
    uint32  LCD         :1;
    uint32              :1;
    uint32              :1;
    uint32 LPUART3      :1;
    uint32 USB          :1;
    uint32 SPI2         :1;
    uint32 SPI3         :1;
    uint32 CRS          :1;
    uint32 USART2       :1;
    uint32 USART3       :1;
    uint32 USART4       :1;
    uint32 LPUART1      :1;
    uint32 I2C1         :1;
    uint32 I2C2         :1;
    uint32 I2C3         :1;
    uint32 OPAMP        :1;
    uint32 I2C4         :1;
    uint32 LPTIM3       :1;
    uint32              :1;
    uint32 PWR          :1;
    uint32 DAC1         :1;
    uint32 LPTIM2       :1;
    uint32 LPTIM1       :1;
} dtRCC_APB1_Bits;

typedef struct sRCC_APB2_Bits
{
    uint32  SYSCFG      :1;
    uint32              :10;
    uint32  TIM1        :1;
    uint32  SPI1        :1;
    uint32              :1;
    uint32  USART1      :1;
    uint32              :1;
    uint32  TIM15       :1;
    uint32  TIM16       :1;
    uint32              :1;
    uint32              :1;
    uint32  ADC         :1;
    uint32              :11;
} dtRCC_APB2_Bits;

typedef struct sRCC_CCIPR_Bits
{
    uint32 USART1SEL    :2;
    uint32 USART2SEL    :2;
    uint32              :2;
    uint32 LPUART3SEL   :2;
    uint32 LPUART2SEL   :2;
    uint32 LPUART1SEL   :2;
    uint32 I2C1SEL      :2;
    uint32              :2;
    uint32 I2C3SEL      :2;
    uint32 LPTIM1SEL    :2;
    uint32 LPTIM2SEL    :2;
    uint32 LPTIM3SEL    :2;
    uint32 TIM1SEL      :1;
    uint32 TIM15SEL     :1;
    uint32 CLK48SEL     :2;
    uint32 ADCSEL       :2;
    uint32              :2;
} dtRCC_CCIPR_Bits;

typedef struct sRCC_BDCR_Bits
{
    uint32  LSEON       :1;
    uint32  LSERDY      :1;
    uint32  LSEBYP      :1;
    uint32  LSEDRV      :2;
    uint32  LSECSSON    :1;
    uint32  LSECSSD     :1;
    uint32  LSESYSEN    :1;
    uint32  RTC_SEL     :2;
    uint32              :1;
    uint32  LSESYSRDY   :1;
    uint32              :1;
    uint32              :1;
    uint32              :1;
    uint32  RTCEN       :1;
    uint32  BDRST       :1;
    uint32              :7;
    uint32  LSCOEN      :1;
    uint32  LSCOSEL     :1;
    uint32              :6;
} dtRCC_BDCR_Bits;

typedef struct sRCC_CSR_Bits
{
    uint32  LSION       :1;
    uint32  LSIRDY      :1;
    uint32  LSIPREDIV   :1;
    uint32              :1;
    uint32              :1;
    uint32              :3;
    uint32  MSISRANGE   :4;
    uint32              :11;
    uint32  RMVF        :1;
    uint32              :1;
    uint32  OBLRSTF     :1;
    uint32  PINRSTF     :1;
    uint32  PWRRSTF     :1;
    uint32  SFTRSTF     :1;
    uint32  IWWGRSTF    :1;
    uint32  WWDGRSTF    :1;
    uint32  LPWRRSTF    :1;
} dtRCC_CSR_Bits;

typedef struct sRCC_CRRCR_Bits
{
    uint32  HSI48ON     :1;
    uint32  HSI48RDY    :1;
    uint32              :5;
    uint32  HSI48CAL    :9;
    uint32              :16;
} dtRCC_CRRCR_Bits;

REGDEF(RCC, CR)
REGDEF(RCC, ICSCR)
REGDEF(RCC, CFGR)
REGDEF(RCC, PLLCFGR)
REGDEF(RCC, CIER)
REGDEF(RCC, CIFR)
REGDEF(RCC, CICR)
REGDEF(RCC, AHB)
REGDEF(RCC, IOP)
REGDEF(RCC, APB1)
REGDEF(RCC, APB2)
REGDEF(RCC, CCIPR)
REGDEF(RCC, BDCR)
REGDEF(RCC, CSR)
REGDEF(RCC, CRRCR)

typedef struct sBusGroup
{
    uint32      :32;
    dtRCC_AHB   AHB;
    dtRCC_IOP   IOP;
    uint32      :32;
    uint32      :32;
    dtRCC_APB1  APB1;
    uint32      :32;
    dtRCC_APB2  APB2;
} dtBusGroup;

typedef struct sRCC
{
    dtRCC_CR        CR;
    dtRCC_ICSCR     ICSCR;
    dtRCC_CFGR      CFGR;
    dtRCC_PLLCFGR   PLLCFGR;
    uint32 :32;
    uint32 :32;
    dtRCC_CIER      CIER;
    dtRCC_CIFR      CIFR;
    dtRCC_CICR      CICR;
    dtBusGroup      RSTR;
    dtBusGroup      ENR;
    dtBusGroup      SMENR;
    uint32 :32;
    dtRCC_CCIPR     CCIPR;
    uint32 :32;
    dtRCC_BDCR      BDCR;
    dtRCC_CSR       CSR;
    dtRCC_CRRCR     CRRCR;
} dtRCC;

#elif defined(STM32L4)

typedef struct sRCC_CR_Bits
{
    uint32  MSION       :1;
    uint32  MSIRDY      :1;
    uint32  MSIPLLEN    :1;
    uint32  MSIRGSEL    :1;
    uint32  MSIRANGE    :4;
    uint32  HSION       :1;
    uint32  HSIKERON    :1;
    uint32  HSIRDY      :1;
    uint32  HSIASFS     :1;
    uint32              :4;
    uint32  HSEON       :1;
    uint32  HSERDY      :1;
    uint32  HSEBYP      :1;
    uint32  CSSON       :1;
    uint32              :4;
    uint32  PLLON       :1;
    uint32  PLLRDY      :1;
    uint32  PLLSAI1ON   :1;
    uint32  PLLSAI1RDY  :1;
    uint32  PLLSAI2ON   :1;
    uint32  PLLSAI2RDY  :1;
    uint32              :2;
} dtRCC_CR_Bits;

typedef struct sRCC_ICSCR_Bits
{
    uint32  MSI_CAL     :8;
    uint32  MSI_TRIM    :8;
    uint32  HSI_CAL     :8;
    uint32  HSI_TRIM    :7;
    uint32              :1;
} dtRCC_ICSCR_Bits;

typedef struct sRCC_CFGR_Bits
{
	uint32  SW          :2;
	uint32  SWS         :2;
	uint32  HPRE        :4;
	uint32  PPRE1       :3;
	uint32  PPRE2       :3;
	uint32              :1;
	uint32  STOP_WUCK   :1;
    uint32              :8;
	uint32  MCOSEL      :4;
	uint32  MCOPRE      :4;
} dtRCC_CFGR_Bits;

typedef struct sRCC_PLLCFGR_Bits
{
    uint32  PLLSRC      :2;
    uint32              :2;
    uint32  PLLM        :3;
    uint32              :1;
    uint32  PLLN        :7;
    uint32              :1;
    uint32  PLLPEN      :1;
    uint32  PLLP        :1;
    uint32              :2;
    uint32  PLLQEN      :1;
    uint32  PLLQ        :2;
    uint32              :1;
    uint32  PLLREN      :1;
    uint32  PLLR        :2;
    uint32 PLLPDIV      :5;
} dtRCC_PLLCFGR_Bits;

typedef struct sRCC_PLLSAI1CFGR_Bits
{
	uint32              :8;
	uint32 PLLSAIN      :1;
	uint32              :1;
	uint32 PLLSAIPEN    :1;
	uint32 PLLSAIP      :1;
	uint32              :2;
	uint32 PLLSAIQEN    :1;
	uint32 PLLSAIQ      :1;
	uint32              :1;
	uint32 PLLSAIREN    :1;
	uint32 PLLSAIR      :1;
	uint32 PLLSAIPDIV   :1;
} dtRCC_PLLSAI1CFGR_Bits;

typedef struct sRCC_PLLSAI2CFGR_Bits
{
	uint32              :8;
	uint32 PLLSAIN      :1;
	uint32              :1;
	uint32 PLLSAIPEN    :1;
	uint32 PLLSAIP      :1;
	uint32              :6;
	uint32 PLLSAIREN    :1;
	uint32 PLLSAIR      :1;
	uint32 PLLSAIPDIV   :1;
} dtRCC_PLLSAI2CFGR_Bits;

typedef struct sRCC_CIER_Bits
{
    uint32  LSIRDYIE    :1;
    uint32  LSERDYIE    :1;
    uint32  MSIRDYIE    :1;
    uint32  HSIRDYIE    :1;
    uint32  HSERDYIE    :1;
    uint32  PLLRDYIE    :1;
    uint32  PLLSAI1RDYIE:1;
    uint32  PLLSAI2RDYIE:1;
    uint32  CSSF        :1;
    uint32  LSECSSIE    :1;
    uint32  HSI48RDYIE  :1;
    uint32              :21;
} dtRCC_CIER_Bits;

typedef struct sRCC_CIFR_Bits
{
    uint32  LSIRDYF     :1;
    uint32  LSERDYF     :1;
    uint32  MSIRDYF     :1;
    uint32  HSIRDYF     :1;
    uint32  HSERDYF     :1;
    uint32  PLLRDYF     :1;
    uint32  PLLSAI1RDYF :1;
    uint32  PLLSAI2RDYF :1;
    uint32  CSSF        :1;
    uint32  LSECSSF     :1;
    uint32  HSI48RDYF   :1;
    uint32              :21;
} dtRCC_CIFR_Bits;

typedef struct sRCC_CICR_Bits
{
    uint32  LSIRDYC     :1;
    uint32  LSERDYC     :1;
    uint32  MSIRDYC     :1;
    uint32  HSIRDYC     :1;
    uint32  HSERDYC     :1;
    uint32  PLLRDYC     :1;
    uint32  PLLSAI1RDYC :1;
    uint32  PLLSAI2RDYC :1;
    uint32  CSSC        :1;
    uint32  LSECSSC     :1;
    uint32  HSI48RDYC   :1;
    uint32              :21;
} dtRCC_CICR_Bits;

typedef struct sRCC_AHB1_Bits
{
    uint32  DMA1        :1;
    uint32  DMA2        :1;
    uint32              :6;
    uint32  FLASH       :1;
    uint32              :3;
    uint32  CRC         :1;
    uint32              :3;
    uint32  TSC         :1;
    uint32  DMA2D       :1;
    uint32              :14;
} dtRCC_AHB1_Bits;

typedef struct sRCC_AHB2_Bits
{
    uint32  GPIOA       :1;
    uint32  GPIOB       :1;
    uint32  GPIOC       :1;
    uint32  GPIOD       :1;
    uint32  GPIOE       :1;
    uint32  GPIOF       :1;
    uint32  GPIOG       :1;
    uint32  GPIOH       :1;
    uint32  GPIOI       :1;
    uint32              :3;
    uint32 OTGFS        :1;
    uint32 ADC          :1;
    uint32 DCMI         :1;
    uint32              :1;
    uint32 AES          :1;
    uint32 HASH         :1;
    uint32 RNG          :1;
    uint32              :13;
} dtRCC_AHB2_Bits;

typedef struct sRCC_AHB3_Bits
{
    uint32 FMC          :1;
    uint32              :7;
    uint32 QSPI         :1;
    uint32              :23;
} dtRCC_AHB3_Bits;

typedef struct sRCC_APB1_1_Bits
{
    uint32  TIM2        :1;
    uint32  TIM3        :1;
    uint32  TIM4        :1;
    uint32  TIM5        :1;
    uint32  TIM6        :1;
    uint32  TIM7        :1;
    uint32              :3;
    uint32 LCD          :1;
    uint32              :4;
    uint32 SPI2         :1;
    uint32 SPI3         :1;
    uint32              :1;
    uint32 USART2       :1;
    uint32 USART3       :1;
    uint32 USART4       :1;
    uint32 USART5       :1;
    uint32 I2C1         :1;
    uint32 I2C2         :1;
    uint32 I2C3         :1;
    uint32 CRS          :1;
    uint32 CAN1         :1;
    uint32 CAN2         :1;
    uint32              :1;
    uint32 PWR          :1;
    uint32 DAC1         :1;
    uint32 OPAMP        :1;
    uint32 LPTIM1       :1;
} dtRCC_APB1_1_Bits;

typedef struct sRCC_APB1_2_Bits
{
    uint32  LPUART1     :1;
    uint32  I2C4        :1;
    uint32  SWPMI1      :1;
    uint32              :2;
    uint32  LPTIM2      :1;
    uint32              :26;
} dtRCC_APB1_2_Bits;

typedef struct sRCC_APB2_Bits
{
    uint32  SYSCFG      :1;
    uint32              :9;
    uint32  SDMMC1      :1;
    uint32  TIM1        :1;
    uint32  SPI1        :1;
    uint32 TIM8         :1;
    uint32 USART1       :1;
    uint32              :1;
    uint32  TIM15       :1;
    uint32  TIM16       :1;
    uint32  TIM17       :1;
    uint32              :2;
    uint32 SAI1         :1;
    uint32 SAI2         :1;
    uint32              :1;
    uint32 DFSDM1       :1;
    uint32              :7;
} dtRCC_APB2_Bits;

typedef struct sRCC_CCIPR_Bits
{
    uint32 USART1SEL    :2;
    uint32 USART2SEL    :2;
    uint32 USART3SEL    :2;
    uint32 USART4SEL    :2;
    uint32 USART5SEL    :2;
    uint32 LPUART1SEL   :2;
    uint32 I2C1SEL      :2;
    uint32 I2C2SEL      :2;
    uint32 I2C3SEL      :2;
    uint32 LPTIM1SEL    :2;
    uint32 LPTIM2SEL    :2;
    uint32 SAI1SEL      :2;
    uint32 SAI2SEL      :2;
    uint32 CLK48SEL     :2;
    uint32 ADCSEL       :2;
    uint32 SWPMI1SEL    :1;
    uint32 DFSDM1SEL    :1;
} dtRCC_CCIPR_Bits;

typedef struct sRCC_BDCR_Bits
{
    uint32  LSEON       :1;
    uint32  LSERDY      :1;
    uint32  LSEBYP      :1;
    uint32  LSEDRV      :2;
    uint32  LSECSSON    :1;
    uint32  LSECSSD     :1;
    uint32              :1;
    uint32  RTC_SEL     :2;
    uint32              :5;
    uint32  RTCEN       :1;
    uint32  BDRST       :1;
    uint32              :7;
    uint32  LSCOEN      :1;
    uint32  LSCOSEL     :1;
    uint32              :6;
} dtRCC_BDCR_Bits;

typedef struct sRCC_CSR_Bits
{
    uint32  LSION       :1;
    uint32  LSIRDY      :1;
    uint32              :6;
    uint32  MSISRANGE   :4;
    uint32              :11;
    uint32  RMVF        :1;
    uint32  FIREWALLFRSFT:1;
    uint32  OBLRSTF     :1;
    uint32  PINRSTF     :1;
    uint32  BORRSTF     :1;
    uint32  SFTRSTF     :1;
    uint32  IWWGRSTF    :1;
    uint32  WWDGRSTF    :1;
    uint32  LPWRRSTF    :1;
} dtRCC_CSR_Bits;

typedef struct sRCC_CRRCR_Bits
{
    uint32  HSI48ON     :1;
    uint32  HSI48RDY    :1;
    uint32              :5;
    uint32  HSI48CAL    :9;
    uint32              :16;
} dtRCC_CRRCR_Bits;

typedef struct sRCC_CCIPR2_Bits
{
	uint32 I2C4SEL  :2;
	uint32          :30;
} dtRCC_CCIPR2_Bits;

REGDEF(RCC, CR)
REGDEF(RCC, ICSCR)
REGDEF(RCC, CFGR)
REGDEF(RCC, PLLCFGR)
REGDEF(RCC, PLLSAI1CFGR)
REGDEF(RCC, PLLSAI2CFGR)
REGDEF(RCC, CIER)
REGDEF(RCC, CIFR)
REGDEF(RCC, CICR)
REGDEF(RCC, AHB1)
REGDEF(RCC, AHB2)
REGDEF(RCC, AHB3)
REGDEF(RCC, APB1_1)
REGDEF(RCC, APB1_2)
REGDEF(RCC, APB2)
REGDEF(RCC, CCIPR)
REGDEF(RCC, BDCR)
REGDEF(RCC, CSR)
REGDEF(RCC, CRRCR)
REGDEF(RCC, CCIPR2)

typedef struct sBusGroup
{
	uint32        :32;
    dtRCC_AHB1    AHB1;
    dtRCC_AHB2    AHB2;
    dtRCC_AHB3    AHB3;
    uint32        :32;
    dtRCC_APB1_1  APB1_1;
    dtRCC_APB1_2  APB1_2;
    dtRCC_APB2  APB2;
} dtBusGroup;

typedef struct sRCC
{
    dtRCC_CR            CR;
    dtRCC_ICSCR         ICSCR;
    dtRCC_CFGR          CFGR;
    dtRCC_PLLCFGR       PLLCFGR;
    dtRCC_PLLSAI1CFGR   PLLSAI1CFGR;
    dtRCC_PLLSAI2CFGR   PLLSAI2CFGR;
    dtRCC_CIER          CIER;
    dtRCC_CIFR          CIFR;
    dtRCC_CICR          CICR;
    dtBusGroup      RSTR;
    dtBusGroup      ENR;
    dtBusGroup      SMENR;
    uint32 :32;
    dtRCC_CCIPR     CCIPR;
    uint32 :32;
    dtRCC_BDCR      BDCR;
    dtRCC_CSR       CSR;
    dtRCC_CRRCR     CRRCR;
    dtRCC_CCIPR2     CRRCR2;
} dtRCC;

#endif

#endif /* INC_REGDEFS_RCC_REGDEF_H_ */

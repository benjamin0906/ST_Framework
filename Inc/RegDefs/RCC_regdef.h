/*
 * RCC_regdef.h
 *
 *  Created on: Mar 7, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_RCC_REGDEF_H_
#define INC_REGDEFS_RCC_REGDEF_H_

#include "RegDefs/regdef_helper.h"

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
    dtRCC_BDCR      BDCR;
    dtRCC_CSR       CSR;
    dtRCC_CRRCR     CRRCR;
} dtRCC;

#endif /* INC_REGDEFS_RCC_REGDEF_H_ */

/*
 * GPIO_regdef.h
 *
 *  Created on: Feb 28, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_GPIO_REGDEF_H_
#define INC_REGDEFS_GPIO_REGDEF_H_

#include "RegDefs/regdef_helper.h"
#include "types.h"

typedef struct sGPIO_MODER_Bits
{
    uint32 MODE0:2;
    uint32 MODE1:2;
    uint32 MODE2:2;
    uint32 MODE3:2;
    uint32 MODE4:2;
    uint32 MODE5:2;
    uint32 MODE6:2;
    uint32 MODE7:2;
    uint32 MODE8:2;
    uint32 MODE9:2;
    uint32 MODE10:2;
    uint32 MODE11:2;
    uint32 MODE12:2;
    uint32 MODE13:2;
    uint32 MODE14:2;
    uint32 MODE15:2;
} dtGPIO_MODER_Bits;

typedef struct sGPIO_OTYPER_Bits
{
    uint32 OT0  :1;
    uint32 OT1  :1;
    uint32 OT2  :1;
    uint32 OT3  :1;
    uint32 OT4  :1;
    uint32 OT5  :1;
    uint32 OT6  :1;
    uint32 OT7  :1;
    uint32 OT8  :1;
    uint32 OT9  :1;
    uint32 OT10 :1;
    uint32 OT11 :1;
    uint32 OT12 :1;
    uint32 OT13 :1;
    uint32 OT14 :1;
    uint32 OT15 :1;
    uint32      :16;
} dtGPIO_OTYPER_Bits;

typedef struct sGPIO_OSPEEDR_Bits
{
    uint32 OSPEED0:2;
    uint32 OSPEED1:2;
    uint32 OSPEED2:2;
    uint32 OSPEED3:2;
    uint32 OSPEED4:2;
    uint32 OSPEED5:2;
    uint32 OSPEED6:2;
    uint32 OSPEED7:2;
    uint32 OSPEED8:2;
    uint32 OSPEED9:2;
    uint32 OSPEED10:2;
    uint32 OSPEED11:2;
    uint32 OSPEED12:2;
    uint32 OSPEED13:2;
    uint32 OSPEED14:2;
    uint32 OSPEED15:2;
} dtGPIO_OSPEEDR_Bits;

typedef struct sGPIO_PUPDR_Bits
{
    uint32 PUPD0:2;
    uint32 PUPD1:2;
    uint32 PUPD2:2;
    uint32 PUPD3:2;
    uint32 PUPD4:2;
    uint32 PUPD5:2;
    uint32 PUPD6:2;
    uint32 PUPD7:2;
    uint32 PUPD8:2;
    uint32 PUPD9:2;
    uint32 PUPD10:2;
    uint32 PUPD11:2;
    uint32 PUPD12:2;
    uint32 PUPD13:2;
    uint32 PUPD14:2;
    uint32 PUPD15:2;
} dtGPIO_PUPDR_Bits;

typedef struct sGPIO_IDR_Bits
{
    uint32 ID0  :1;
    uint32 ID1  :1;
    uint32 ID2  :1;
    uint32 ID3  :1;
    uint32 ID4  :1;
    uint32 ID5  :1;
    uint32 ID6  :1;
    uint32 ID7  :1;
    uint32 ID8  :1;
    uint32 ID9  :1;
    uint32 ID10 :1;
    uint32 ID11 :1;
    uint32 ID12 :1;
    uint32 ID13 :1;
    uint32 ID14 :1;
    uint32 ID15 :1;
    uint32      :16;
} dtGPIO_IDR_Bits;

typedef struct sGPIO_ODR_Bits
{
    uint32 OD0  :1;
    uint32 OD1  :1;
    uint32 OD2  :1;
    uint32 OD3  :1;
    uint32 OD4  :1;
    uint32 OD5  :1;
    uint32 OD6  :1;
    uint32 OD7  :1;
    uint32 OD8  :1;
    uint32 OD9  :1;
    uint32 OD10 :1;
    uint32 OD11 :1;
    uint32 OD12 :1;
    uint32 OD13 :1;
    uint32 OD14 :1;
    uint32 OD15 :1;
    uint32      :16;
} dtGPIO_ODR_Bits;

typedef struct sGPIO_BSRR_Bits
{
    uint32 BS0  :1;
    uint32 BS1  :1;
    uint32 BS2  :1;
    uint32 BS3  :1;
    uint32 BS4  :1;
    uint32 BS5  :1;
    uint32 BS6  :1;
    uint32 BS7  :1;
    uint32 BS8  :1;
    uint32 BS9  :1;
    uint32 BS10 :1;
    uint32 BS11 :1;
    uint32 BS12 :1;
    uint32 BS13 :1;
    uint32 BS14 :1;
    uint32 BS15 :1;
    uint32 BR0  :1;
    uint32 BR1  :1;
    uint32 BR2  :1;
    uint32 BR3  :1;
    uint32 BR4  :1;
    uint32 BR5  :1;
    uint32 BR6  :1;
    uint32 BR7  :1;
    uint32 BR8  :1;
    uint32 BR9  :1;
    uint32 BR10 :1;
    uint32 BR11 :1;
    uint32 BR12 :1;
    uint32 BR13 :1;
    uint32 BR14 :1;
    uint32 BR15 :1;
} dtGPIO_BSRR_Bits;

typedef struct sGPIO_LCKR_Bits
{
    uint32 LCK0 :1;
    uint32 LCK1 :1;
    uint32 LCK2 :1;
    uint32 LCK3 :1;
    uint32 LCK4 :1;
    uint32 LCK5 :1;
    uint32 LCK6 :1;
    uint32 LCK7 :1;
    uint32 LCK8 :1;
    uint32 LCK9 :1;
    uint32 LCK10:1;
    uint32 LCK11:1;
    uint32 LCK12:1;
    uint32 LCK13:1;
    uint32 LCK14:1;
    uint32 LCK15:1;
    uint32 LCKK :1;
    uint32      :15;
} dtGPIO_LCKR_Bits;

typedef struct sGPIO_AFRL_Bits
{
    uint32 AFSEL0:4;
    uint32 AFSEL1:4;
    uint32 AFSEL2:4;
    uint32 AFSEL3:4;
    uint32 AFSEL4:4;
    uint32 AFSEL5:4;
    uint32 AFSEL6:4;
    uint32 AFSEL7:4;
} dtGPIO_AFRL_Bits;

typedef struct sGPIO_AFRH_Bits
{
    uint32 AFSEL8   :4;
    uint32 AFSEL9   :4;
    uint32 AFSEL10  :4;
    uint32 AFSEL11  :4;
    uint32 AFSEL12  :4;
    uint32 AFSEL13  :4;
    uint32 AFSEL14  :4;
    uint32 AFSEL15  :4;
} dtGPIO_AFRH_Bits;

typedef struct sGPIO_BRR_Bits
{
    uint32 BR0  :1;
    uint32 BR1  :1;
    uint32 BR2  :1;
    uint32 BR3  :1;
    uint32 BR4  :1;
    uint32 BR5  :1;
    uint32 BR6  :1;
    uint32 BR7  :1;
    uint32 BR8  :1;
    uint32 BR9  :1;
    uint32 BR10 :1;
    uint32 BR11 :1;
    uint32 BR12 :1;
    uint32 BR13 :1;
    uint32 BR14 :1;
    uint32 BR15 :1;
    uint32      :16;
} dtGPIO_BRR_Bits;

REGDEF(GPIO, MODER)
REGDEF(GPIO, OTYPER)
REGDEF(GPIO, OSPEEDR)
REGDEF(GPIO, PUPDR)
REGDEF(GPIO, IDR)
REGDEF(GPIO, ODR)
REGDEF(GPIO, BSRR)
REGDEF(GPIO, LCKR)
REGDEF(GPIO, AFRL)
REGDEF(GPIO, AFRH)
REGDEF(GPIO, BRR)

typedef struct sGPIOx
{
    dtGPIO_MODER    MODER;
    dtGPIO_OTYPER   OTYPER;
    dtGPIO_OSPEEDR  OSPEEDR;
    dtGPIO_PUPDR    PUPDR;
    dtGPIO_IDR      IDR;
    dtGPIO_ODR      ODR;
    dtGPIO_BSRR     BSRR;
    dtGPIO_LCKR     LCKR;
    dtGPIO_AFRL     AFRL;
    dtGPIO_AFRH     AFRH;
    dtGPIO_BRR      BRR;
    uint8           Padding[980];
} dtGPIOx;

typedef struct sGPIO
{
    dtGPIOx GPIOs[6];
} dtGPIO;

#endif /* INC_REGDEFS_GPIO_REGDEF_H_ */

/*
 * STM32C0_TIM14_regdef.h
 *
 *  Created on: Sep 4, 2026
 *      Author: GitHub Copilot
 */

#ifndef INC_REGDEFS_STM32C0_TIM14_REGDEF_H_
#define INC_REGDEFS_STM32C0_TIM14_REGDEF_H_

#include "types.h"
#include "RegDefs/regdef_helper.h"

typedef struct sTIM14_C0_CR1_Bits
{
    uint32 CEN      :1;
    uint32 UDIS     :1;
    uint32 URS      :1;
    uint32 OPM      :1;
    uint32          :3;
    uint32 ARPE     :1;
    uint32 CKD      :2;
    uint32          :1;
    uint32 UIFREMAP :1;
    uint32          :20;
} dtTIM14_C0_CR1_Bits;

typedef struct sTIM14_C0_CR2_Bits
{
    uint32          :4;
    uint32 MMS      :3;
    uint32          :25;
} dtTIM14_C0_CR2_Bits;

typedef struct sTIM14_C0_DIER_Bits
{
    uint32 UIE      :1;
    uint32 CC1IE    :1;
    uint32          :6;
    uint32 UDE      :1;
    uint32 CC1DE    :1;
    uint32          :4;
    uint32 TDE      :1;
    uint32          :17;
} dtTIM14_C0_DIER_Bits;

typedef struct sTIM14_C0_SR_Bits
{
    uint32 UIF      :1;
    uint32 CC1IF    :1;
    uint32          :7;
    uint32 CC1OF    :1;
    uint32          :22;
} dtTIM14_C0_SR_Bits;

typedef struct sTIM14_C0_EGR_Bits
{
    uint32 UG       :1;
    uint32 CC1G     :1;
    uint32          :4;
    uint32 TG       :1;
    uint32          :25;
} dtTIM14_C0_EGR_Bits;

typedef struct sTIM14_C0_CCMR1_Bits
{
    uint32 CC1S     :2;
    uint32 OC1FE    :1;
    uint32 OC1PE    :1;
    uint32 OC1M     :3;
    uint32 OC1CE    :1;
    uint32          :8;
    uint32 OC1M_3   :1;
    uint32          :15;
} dtTIM14_C0_CCMR1_Bits;

typedef struct sTIM14_C0_CCER_Bits
{
    uint32 CC1E     :1;
    uint32 CC1P     :1;
    uint32          :1;
    uint32 CC1NP    :1;
    uint32          :28;
} dtTIM14_C0_CCER_Bits;

typedef struct sTIM14_C0_CNT_Bits
{
    uint32 CNT      :16;
    uint32          :15;
    uint32 UIFCPY   :1;
} dtTIM14_C0_CNT_Bits;

typedef struct sTIM14_C0_PSC_Bits
{
    uint32 PSC      :16;
    uint32          :16;
} dtTIM14_C0_PSC_Bits;

typedef struct sTIM14_C0_ARR_Bits
{
    uint32 ARR      :16;
    uint32          :16;
} dtTIM14_C0_ARR_Bits;

typedef struct sTIM14_C0_CCR1_Bits
{
    uint32 CCR1     :16;
    uint32          :16;
} dtTIM14_C0_CCR1_Bits;

typedef struct sTIM14_C0_OR1_Bits
{
    uint32 TI1_RMP  :2;
    uint32          :30;
} dtTIM14_C0_OR1_Bits;

REGDEF(TIM14_C0, CR1)
REGDEF(TIM14_C0, CR2)
REGDEF(TIM14_C0, DIER)
REGDEF(TIM14_C0, SR)
REGDEF(TIM14_C0, EGR)
REGDEF(TIM14_C0, CCMR1)
REGDEF(TIM14_C0, CCER)
REGDEF(TIM14_C0, CNT)
REGDEF(TIM14_C0, PSC)
REGDEF(TIM14_C0, ARR)
REGDEF(TIM14_C0, CCR1)
REGDEF(TIM14_C0, OR1)

typedef struct sTIM14_C0
{
    dtTIM14_C0_CR1      CR1;        /* 0x00 */
    dtTIM14_C0_CR2      CR2;        /* 0x04 */
    uint32              Reserved0;  /* 0x08 */
    dtTIM14_C0_DIER     DIER;       /* 0x0C */
    dtTIM14_C0_SR       SR;         /* 0x10 */
    dtTIM14_C0_EGR      EGR;        /* 0x14 */
    dtTIM14_C0_CCMR1    CCMR1;      /* 0x18 */
    uint32              Reserved1;  /* 0x1C */
    dtTIM14_C0_CCER     CCER;       /* 0x20 */
    dtTIM14_C0_CNT      CNT;        /* 0x24 */
    dtTIM14_C0_PSC      PSC;        /* 0x28 */
    dtTIM14_C0_ARR      ARR;        /* 0x2C */
    uint32              Reserved2;  /* 0x30 */
    dtTIM14_C0_CCR1     CCR1;       /* 0x34 */
    uint32              Reserved3;  /* 0x38 */
    uint32              Reserved4;  /* 0x3C */
    uint32              Reserved5;  /* 0x40 */
    uint32              Reserved6;  /* 0x44 */
    uint32              Reserved7;  /* 0x48 */
    uint32              Reserved8;  /* 0x4C */
    dtTIM14_C0_OR1      OR1;        /* 0x50 */
    uint8               Padding[940];
} dtTIM14_C0;

#endif /* INC_REGDEFS_STM32C0_TIM14_REGDEF_H_ */
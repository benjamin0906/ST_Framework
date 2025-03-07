/*
 * TIM_6-7_regdef.h
 *
 *  Created on: Mar 7, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_TIM_6_7_REGDEF_H_
#define INC_REGDEFS_TIM_6_7_REGDEF_H_

#include "types.h"
#include "RegDefs/regdef_helper.h"

typedef struct sTIM6_7_CR1_Bits
{
    uint32 CEN      :1;
    uint32 UDIS     :1;
    uint32 URS      :1;
    uint32 OPM      :1;
    uint32          :3;
    uint32 ARPE     :1;
    uint32          :3;
    uint32 UIFREMA  :1;
    uint32          :20;
} dtTIM6_7_CR1_Bits;

typedef struct sTIM6_7_CR2_Bits
{
    uint32      :4;
    uint32 MMS  :3;
    uint32      :25;
} dtTIM6_7_CR2_Bits;

typedef struct sTIM6_7_DIER_Bits
{
    uint32 UIE  :1;
    uint32      :7;
    uint32 UDE  :1;
    uint32      :23;
} dtTIM6_7_DIER_Bits;

typedef struct sTIM6_7_SR_Bits
{
    uint32 UIF  :1;
    uint32      :31;
} dtTIM6_7_SR_Bits;

typedef struct sTIM6_7_EGR_Bits
{
    uint32 UG   :1;
    uint32      :31;
} dtTIM6_7_EGR_Bits;

typedef struct sTIM6_7_CNT_Bits
{
    uint32 CNT      :16;
    uint32          :15;
    uint32 UIFCPY   :1;
} dtTIM6_7_CNT_Bits;

typedef struct sTIM6_7_PSC_Bits
{
    uint32 PSC  :16;
    uint32      :16;
} dtTIM6_7_PSC_Bits;

typedef struct sTIM6_7_ARR_Bits
{
    uint32 ARR  :16;
    uint32      :16;
} dtTIM6_7_ARR_Bits;

REGDEF(TIM6_7, CR1)
REGDEF(TIM6_7, CR2)
REGDEF(TIM6_7, DIER)
REGDEF(TIM6_7, SR)
REGDEF(TIM6_7, EGR)
REGDEF(TIM6_7, CNT)
REGDEF(TIM6_7, PSC)
REGDEF(TIM6_7, ARR)

typedef struct sTIM6_7x
{
    dtTIM6_7_CR1    CR1;
    dtTIM6_7_CR2    CR2;
    uint32 :32;
    dtTIM6_7_DIER   DIER;
    dtTIM6_7_SR     SR;
    dtTIM6_7_EGR    EGR;
    uint32 :32;
    uint32 :32;
    uint32 :32;
    dtTIM6_7_CNT    CNT;
    dtTIM6_7_PSC    PSC;
    dtTIM6_7_ARR    ARR;
    uint8           Reserved[980];
} dtTIM6_7x;

typedef struct sTIM6_7
{
    dtTIM6_7x TIM6_7[2];
} dtTIM6_7;

#endif /* INC_REGDEFS_TIM_6_7_REGDEF_H_ */

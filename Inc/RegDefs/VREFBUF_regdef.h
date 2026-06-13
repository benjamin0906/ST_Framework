/*
 * VREFBUF_regdef.h
 *
 *  Created on: Jun 13, 2026
 *      Author: benjamin
 */

#ifndef INC_REGDEFS_VREFBUF_REGDEF_H_
#define INC_REGDEFS_VREFBUF_REGDEF_H_

#include "RegDefs/regdef_helper.h"

#if defined(STM32L4)

typedef struct sVREFBUF_CSR_Bits
{
    uint32 ENVR :1;
    uint32 HIZ  :1;
    uint32 VRS  :1;
    uint32 VRR  :1;
    uint32      :28;
}dtVREFBUF_CSR_Bits;

typedef struct sVREFBUF_CCR_Bits
{
    uint32 TRIM :6;
    uint32      :26;
}dtVREFBUF_CCR_Bits;

REGDEF(VREFBUF, CSR)
REGDEF(VREFBUF, CCR)

typedef struct sVREFBUF
{
    dtVREFBUF_CSR CSR;
    dtVREFBUF_CCR CCR;
} dtVREFBUF;

#endif /* defined(STM32L4) */

#endif /* INC_REGDEFS_VREFBUF_REGDEF_H_ */

/*
 * EXTI_regdef.h
 *
 *  Created on: Apr 13, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_EXTI_REGDEF_H_
#define INC_REGDEFS_EXTI_REGDEF_H_

#include "RegDefs/regdef_helper.h"

typedef struct sEXTI_Lines_Bits
{
    uint32 Lines    :21;
} dtEXTI_Lines_Bits;

REGDEF(EXTI, Lines)

typedef struct
{
    dtEXTI_Lines RSTR;   //0x00
    dtEXTI_Lines FTSR;   //0x04
    dtEXTI_Lines SWIER;  //0x08
    dtEXTI_Lines RPR;    //0x0C
    dtEXTI_Lines FPR;    //0x10
    uint8   Padding[76];    //91 bytes padding
} dtGenConfEvents;

typedef struct
{
    dtGenConfEvents GenConfEvents;
    uint8 ExtiCr[16];
    uint8 Padding[16];
    uint32 IMR1;
    uint32 EMR1;
    uint8 Padding2[8];
    uint32 IMR2;
    uint32 EMR2;
} dtEXTI;

#endif /* INC_REGDEFS_EXTI_REGDEF_H_ */

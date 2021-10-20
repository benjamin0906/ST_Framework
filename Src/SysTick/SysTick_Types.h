/*
 * SysTick_Types.h
 *
 *  Created on: 2021. okt. 20.
 *      Author: Benjamin
 */

#ifndef SRC_SYSTICK_SYSTICK_TYPES_H_
#define SRC_SYSTICK_SYSTICK_TYPES_H_

#include "types.h"

typedef union
{
    uint32 Word;
    struct
    {
        uint32 Enable       :1;
        uint32 Tickinit     :1;
        uint32 ClkSource    :1;
        uint32              :13;
        uint32 CountFlag    :1;
    } Fields;
} dtSYST_CSR;

typedef struct
{
    dtSYST_CSR  CSR;
    uint32      RVR;
    uint32      CVR;
    uint32      CALIB;
} dtSysTick;

#endif /* SRC_SYSTICK_SYSTICK_TYPES_H_ */

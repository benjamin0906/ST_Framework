/*
 * Core.c
 *
 *  Created on: 2021. márc. 25.
 *      Author: Benjamin
 */

#include "Core_Types.h"
#include "MemMap.h"

__asm(  ".globl CoreI_SetPsp            \n"
        ".p2align 2                     \n"
        ".type CoreI_SetPsp, %function  \n"
        "CoreI_SetPsp:                  \n"
        "msr.w PSP, r0                  \n"
        "isb                            \n"
        "bx lr                          \n");

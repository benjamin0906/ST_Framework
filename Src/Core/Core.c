/*
 * Core.c
 *
 *  Created on: 2021. márc. 25.
 *      Author: Benjamin
 */

#include "MemMap.h"
#include "FieldHelper.h"
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
__asm(  ".globl CoreI_SetPsp            \n"
        ".p2align 2                     \n"
        ".type CoreI_SetPsp, %function  \n"
        "CoreI_SetPsp:                  \n"
        "msr.w PSP, r0                  \n"
        "isb                            \n"
        "bx lr                          \n");

#endif

void Core_SystemReset(void)
{
    dtAIRCR temp = SCB->AIRCR;
    temp.Fields.SYSRESETREQ = 1;
    temp.Fields.VECTKEY = 0x05FA;
    SCB->AIRCR = temp;
    while(1);
}

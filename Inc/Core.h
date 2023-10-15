/*
 * Core.h
 *
 *  Created on: 2021. márc. 25.
 *      Author: Benjamin
 */

#ifndef INC_CORE_H_
#define INC_CORE_H_

#include "Core_Types.h"

#define UNFOLD(x)  #x
#define _UNFOLD(a) UNFOLD(a)

#define N_PRIV  1
#define SPSEL   2

#define CORE_TRIGGER_PENDSV()   asm("orr %1, %0, " _UNFOLD(CORE_ICSR_PENDSVSET_MASK) "\n"\
                                    : "=r" (SCB->ICSR) \
                                    :"r" (SCB->ICSR));

#define CORE_SET_CURRENT_STACK_TO_PSP()\
asm(    "mrs.w   r0, CONTROL\n" \
        "orr.w r0, r0, #"_UNFOLD(SPSEL)"\n"     \
        "msr.w CONTROL, r0\n");

#define CORE_SET_CURRENT_STACK_TO_MSP()\
asm(    "push {r0}\n"           \
        "mrs.w   r0, CONTROL\n" \
        "bic.w r0, r0, #"_UNFOLD(SPSEL)"\n"     \
        "msr.w CONTROL, r0\n"   \
        "pop {r0}");

#define CORE_CLEAR_PRIVILEGE()\
asm(    "push {r0}\n"           \
        "mrs.w   r0, CONTROL\n" \
        "orr.w r0, r0, #"_UNFOLD(N_PRIV)"\n"     \
        "msr.w CONTROL, r0\n"   \
        "pop {r0}");

#define CORE_SET_PSP(x)\
asm(    "push {r0}              \n"             \
        "mov r0, ""3""            \n"             \
        "msr.w PSP, r0\n"\
        "pop {r0}"\
);

extern void CoreI_SetPsp(uint32*);

#endif /* INC_CORE_H_ */

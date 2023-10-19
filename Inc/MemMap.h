/*
 * MemMap.h
 *
 *  Created on: 2022. okt. 29.
 *      Author: Benjamin
 */

#ifndef INC_MEMMAP_H_
#define INC_MEMMAP_H_

#include "types.h"
#include "MemMap_Types/NVIC_Types.h"
#include "MemMap_Types/SCB_Types.h"

/* defining the number of used priority bits */
#if defined(MCU_L476) | defined(MCU_F446)
#define NVIC_PRIO_BITS  4
#endif

extern dtISER *const ISER;
extern dtICER *const ICER;
extern dtISPR *const ISPR;
extern dtICPR *const ICPR;
extern dtIABR *const IABR;
extern dtIPR  *const IPR;

extern dtSCB  *const SCB;

#endif /* INC_MEMMAP_H_ */

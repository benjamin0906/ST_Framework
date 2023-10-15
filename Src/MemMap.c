/*
 * MemMap.c
 *
 *  Created on: 2023. okt. 15.
 *      Author: Benjamin
 */

#include "MemMap.h"

dtISER *const ISER = (dtISER*)0xE000E100;
dtICER *const ICER = (dtICER*)0xE000E180;
dtISPR *const ISPR = (dtISPR*)0xE000E200;
dtICPR *const ICPR = (dtICPR*)0xE000E280;
dtIABR *const IABR = (dtIABR*)0xE000E300;
dtIPR  *const IPR  = (dtIPR*)0xE000E400;

dtSCB  *const SCB  = (dtSCB*)0xE000ED00;

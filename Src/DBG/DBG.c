/*
 * DBG.c
 *
 *  Created on: 2021. ápr. 8.
 *      Author: Benjamin
 */

#include "DBG_Types.h"
#include "DBG.h"

/* The registers of the module can only be accessed by 32 bit operations */
static dtDBG *const DBG = (dtDBG*)(0x40015800);

void DBG_EnableDbg(dtDbgEnMod Mode)
{
	dtDBG_CR TempCr = {.Word = Mode<<1};
	DBG->DBG_CR = TempCr;
}

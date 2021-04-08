/*
 * DBG.h
 *
 *  Created on: 2021. ápr. 8.
 *      Author: Benjamin
 */

#ifndef INC_DBG_H_
#define INC_DBG_H_

#include "types.h"

typedef enum
{
	DBG_Mode_None,
	DBG_Mode_Stop,
	DBG_Mode_Standby,
	DBG_Mode_Both,
} dtDbgEnMod;

extern void DBG_EnableDbg(dtDbgEnMod Mode);

#endif /* INC_DBG_H_ */

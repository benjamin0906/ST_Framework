/*
 * Flash.h
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef FLASH_FLASH_H_
#define FLASH_FLASH_H_

#include "types.h"

typedef enum
{
	LatIsSet,
	LatFailed,
} dtSetLatRet;

extern dtSetLatRet Flash_SetLatency(uint32 clock, uint8 VoltageRange);

#endif /* FLASH_FLASH_H_ */

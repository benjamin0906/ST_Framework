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

#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_F415)
extern dtSetLatRet Flash_SetLatency(uint32 clock, uint8 VoltageRange);
#elif defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
dtSetLatRet Flash_SetLatency(uint32 clock);
#elif defined(STM32U0)
extern Std_ReturnType FLASH_SetLatency(uint8 latency);
#endif
#endif /* FLASH_FLASH_H_ */

/*
 * Flash.c
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#include "Flash_Types.h"
#include "Pwr.h"
#include "RCC.h"

static dtFLASH *const FLASH = (dtFLASH*)0x40022000;

uint32 Flash_SetLatency(void);


uint32 Flash_SetLatency(void)
{
	uint32 ret = 0;
	uint32 Latency = 0; 

	/*if(Pwr_GetVoltageRange() == Range_1)
	{
		if(ClockFreq <= 16000000) Latency = 0;
		else if(ClockFreq <= 32000000) Latency = 1;
		else if(ClockFreq <= 48000000) Latency = 2;
		else if(ClockFreq <= 64000000) Latency = 3;
		else if(ClockFreq <= 80000000) Latency = 4;
	}
	else
	{
		if(ClockFreq <= 6000000) Latency = 0;
		else if(ClockFreq <= 12000000) Latency = 1;
		else if(ClockFreq <= 18000000) Latency = 2;
		else if(ClockFreq <= 26000000) Latency = 3;
	}
	FLASH->ACR.Field.LATENCY = Latency;
	if(FLASH->ACR.Field.LATENCY != Latency) ret = 1;
	return ret;*/
}

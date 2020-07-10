/*
 * Flash.c
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#include "Flash_Types.h"
#include "Flash.h"

static dtFlash *const Flash = (dtFlash*)(0x40023C00);

dtSetLatRet Flash_SetLatency(uint32 clock, uint8 VoltageRange);

dtSetLatRet Flash_SetLatency(uint32 clock, uint8 VoltageRange)
{
	dtSetLatRet ret = LatIsSet;
	uint8 Latency = 0;
	if(VoltageRange >= 27)
	{
		if(clock >= 90000000) Latency = 3;
		else if(clock >= 64000000) Latency = 2;
		else if(clock >= 30000000) Latency = 1;
		else Latency = 0;
	}
	else if(VoltageRange >= 24)
	{
		if(clock >= 96000000) Latency = 4;
		else if(clock >= 72000000) Latency = 3;
		else if(clock >= 48000000) Latency = 2;
		else if(clock >= 24000000) Latency = 1;
		else Latency = 0;
	}
	else if(VoltageRange >= 21)
	{
		if(clock >= 90000000) Latency = 5;
		else if(clock >= 72000000) Latency = 4;
		else if(clock >= 54000000) Latency = 3;
		else if(clock >= 36000000) Latency = 2;
		else if(clock >= 18000000) Latency = 1;
		else Latency = 0;
	}
	else if(VoltageRange >= 24)
	{
		if(clock >= 96000000) Latency = 6;
		else if(clock >= 80000000) Latency = 5;
		else if(clock >= 64000000) Latency = 4;
		else if(clock >= 48000000) Latency = 3;
		else if(clock >= 32000000) Latency = 2;
		else if(clock >= 16000000) Latency = 1;
		else Latency = 0;
	}
	Flash->ACR.Fields.LATENCY = Latency;
	if(Flash->ACR.Fields.LATENCY != Latency) ret = LatFailed;
	return ret;
}

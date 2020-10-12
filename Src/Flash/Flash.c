/*
 * Flash.c
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#include "Flash_Types.h"
#include "Flash.h"
#include "Pwr.h"

#ifndef MODULE_TEST
#if defined(MCU_F446) || defined(MCU_F410)
static dtFlash *const Flash = (dtFlash*)(0x40023C00);
#elif defined(MCU_G070)
static dtFlash *const Flash = (dtFlash*)(0x40022000);
#endif
#else
#include "TestEnv.h"
static dtFlash *const Flash = (dtFlash*)&TestFlash;
#endif

#if defined(MCU_F410) || defined(MCU_F446)
dtSetLatRet Flash_SetLatency(uint32 clock, uint8 VoltageRange);
#elif defined(MCU_G070)
dtSetLatRet Flash_SetLatency(uint32 clock);
#endif

#if defined(MCU_F410) || defined(MCU_F446)
dtSetLatRet Flash_SetLatency(uint32 clock, uint8 VoltageRange)
{
	dtSetLatRet ret = LatIsSet;
	uint8 Latency = 0;
	if(VoltageRange >= 27)
	{
#if defined(MCU_F410)
		if(clock > 90000000) 		Latency = 3;
		else if(clock > 64000000) 	Latency = 2;
		else if(clock > 30000000) 	Latency = 1;
		else 						Latency = 0;
#elif defined(MCU_F446)
		if(clock >= 150000000) 		Latency = 5;
		else if(clock >= 120000000) Latency = 4;
		else if(clock >= 90000000) 	Latency = 3;
		else if(clock >= 60000000) 	Latency = 2;
		else if(clock >= 30000000) 	Latency = 1;
		else 						Latency = 0;
#endif
	}
	else if(VoltageRange >= 24)
	{
#if defined(MCU_F410)
		if(clock > 96000000) 		Latency = 4;
		else if(clock > 72000000) 	Latency = 3;
		else if(clock > 48000000) 	Latency = 2;
		else if(clock > 24000000) 	Latency = 1;
		else 						Latency = 0;
#elif defined(MCU_F446)
		if(clock >= 168000000) 		Latency = 7;
		else if(clock >= 144000000) Latency = 6;
		else if(clock >= 120000000) Latency = 5;
		else if(clock >= 96000000) 	Latency = 4;
		else if(clock >= 72000000) 	Latency = 3;
		else if(clock >= 48000000) 	Latency = 2;
		else if(clock >= 24000000) 	Latency = 1;
		else 						Latency = 0;
#endif
	}
	else if(VoltageRange >= 21)
	{
#if defined(MCU_F410)
		if(clock > 90000000) 		Latency = 5;
		else if(clock > 72000000) 	Latency = 4;
		else if(clock > 54000000) 	Latency = 3;
		else if(clock > 36000000) 	Latency = 2;
		else if(clock > 18000000) 	Latency = 1;
		else 						Latency = 0;
#elif defined(MCU_F446)
		if(clock >= 176000000) 		Latency = 8;
		else if(clock >= 154000000) Latency = 7;
		else if(clock >= 132000000) Latency = 6;
		else if(clock >= 110000000) Latency = 5;
		else if(clock >= 88000000) 	Latency = 4;
		else if(clock >= 66000000) 	Latency = 3;
		else if(clock >= 44000000) 	Latency = 2;
		else if(clock >= 22000000) 	Latency = 1;
		else 						Latency = 0;
#endif
	}
	else if(VoltageRange >= 17)
	{
#if defined(MCU_F410)
		if(clock > 96000000) 		Latency = 6;
		else if(clock > 80000000) 	Latency = 5;
		else if(clock > 64000000) 	Latency = 4;
		else if(clock > 48000000) 	Latency = 3;
		else if(clock > 32000000) 	Latency = 2;
		else if(clock > 16000000) 	Latency = 1;
		else 						Latency = 0;
#elif defined(MCU_F446)
		if(clock >= 160000000)		Latency = 8;
		else if(clock >= 140000000) Latency = 7;
		else if(clock >= 120000000) Latency = 6;
		else if(clock >= 100000000) Latency = 5;
		else if(clock >= 80000000) 	Latency = 4;
		else if(clock >= 60000000) 	Latency = 3;
		else if(clock >= 40000000) 	Latency = 2;
		else if(clock >= 20000000) 	Latency = 1;
		else 						Latency = 0;
#endif
	}
	Flash->ACR.Fields.LATENCY = Latency;
	if(Flash->ACR.Fields.LATENCY != Latency) ret = LatFailed;
	return ret;
}
#elif defined(MCU_G070)
dtSetLatRet Flash_SetLatency(uint32 clock)
{
	uint8 Latency = 2;
	dtSetLatRet ret = LatIsSet;
	if(Pwr_GetVos() == 1)
	{
		if(clock > 48000000) Latency = 2;
		else if(clock > 24000000) Latency = 1;
		else Latency = 0;
	}
	else
	{
		if(clock > 8000000) Latency = 1;
		else Latency = 0;
	}
	Flash->ACR.Fields.LATENCY = Latency;
	if(Flash->ACR.Fields.LATENCY != Latency) ret = LatFailed;
	return ret;
}
#endif

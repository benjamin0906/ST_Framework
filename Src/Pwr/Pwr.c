/*
 * Pwr.c
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#include "Pwr_Types.h"
#include "Pwr.h"
#include "Flash.h"

static dtPwr *const Pwr = (dtPwr*)(0x40007000);

void Pwr_SetVoltageRange(dtVoltScale Range);
dtVoltScale Pwr_GetVoltageRange(void);

void Pwr_SetVoltageRange(dtVoltScale Range)
{
	uint8 ReqRange;
	if(Range == Range_1) ReqRange = 1;
	else ReqRange = 2;

	if(Pwr->CR1.Field.VOS != ReqRange)
	{
		switch(ReqRange)
		{
		case 1:
			Pwr->CR1.Field.VOS = ReqRange;
			while(Pwr->SR2.Field.VOSF != 0);
			Flash_SetLatency();
			break;
		case 2:
			/* TODO: system frequency must be under 26MHz before switching range!!! */
			Flash_SetLatency();
			Pwr->CR1.Field.VOS = ReqRange;
			break;
		}
	}
}

dtVoltScale Pwr_GetVoltageRange(void)
{
	return (Pwr->CR1.Field.VOS == 1) ? Range_1 : Range_2;
}

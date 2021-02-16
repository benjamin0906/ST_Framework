/*
 * VREFBUF.c
 *
 *  Created on: 2021. febr. 16.
 *      Author: Benjamin
 */

#include "VREFBUF_Types.h"
#include "VREFBUF.h"

static dtVREFBUF *const VREFBUF	= (dtVREFBUF*)(0x40010030);

void VREFBUF_Set(dtVoltScale Config);
uint8 VREFBUF_Status(void);

void VREFBUF_Set(dtVoltScale Config)
{
	dtVrefBuf_CSR Temp = {.Word = 0};
	Temp.Fields.ENVR = 1;
	Temp.Fields.VRS = Config;
	Temp.Fields.HIZ = 0;
	VREFBUF->CSR = Temp;
}

uint8 VREFBUF_Status(void)
{
	return VREFBUF->CSR.Fields.VRR;
}

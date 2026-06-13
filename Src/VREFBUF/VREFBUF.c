/*
 * VREFBUF.c
 *
 *  Created on: 2021. febr. 16.
 *      Author: Benjamin
 */

#include "VREFBUF.h"
#include "RegDefs/VREFBUF_reg.h"

#if defined(STM32L4)
static volatile dtVREFBUF *const VREFBUF = MODULE_VREFBUF;

void VREFBUF_Set(dtVoltScale Config);
uint8 VREFBUF_Status(void);

void VREFBUF_Set(dtVoltScale Config)
{
	dtVREFBUF_CSR tCSR = {.U = 0};
	tCSR.B.ENVR = 1;
	tCSR.B.VRS = Config;
	tCSR.B.HIZ = 0;
	VREFBUF->CSR = tCSR;
}

uint8 VREFBUF_Status(void)
{
    dtVREFBUF_CSR tCSR = VREFBUF->CSR;
	return tCSR.B.VRR;
}
#endif /* defined(STM32L4) */

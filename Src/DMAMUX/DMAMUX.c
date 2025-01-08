/*
 * DMAMUX.c
 *
 *  Created on: Jan 7, 2025
 *      Author: Benjamin
 */

#include "DMAMUX_Types.h"
#include "DMAMUX.h"

#if defined(MCU_G070)
static dtDMA_MUX *const DMAMUX = (dtDMA_MUX*const) 0x40020800;

void DMAMUX_ChannelSimpleConfig(const uint8 channel, const dtMuxInput muxInput)
{
	dtDMAMUX_CxCR tCR = {.Word = 0};
	tCR.Fields.DMAREQ_ID = muxInput;
	DMAMUX->CxCR[channel] = tCR;
}
#endif

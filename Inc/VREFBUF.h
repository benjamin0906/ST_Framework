/*
 * VREFBUF.h
 *
 *  Created on: 2021. febr. 16.
 *      Author: Benjamin
 */

#ifndef INC_VREFBUF_H_
#define INC_VREFBUF_H_

#include "types.h"

typedef enum
{
	Vref_2048,
	Vref_2500,
} dtVoltScale;

extern void VREFBUF_Set(dtVoltScale Config);
extern uint8 VREFBUF_Status(void);

#endif /* INC_VREFBUF_H_ */

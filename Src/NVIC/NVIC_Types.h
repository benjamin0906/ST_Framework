/*
 * NVIC_Types.h
 *
 *  Created on: May 3, 2020
 *      Author: Bodnár Benjamin
 */

#ifndef NVIC_NVIC_TYPES_H_
#define NVIC_NVIC_TYPES_H_

#include "types.h"

typedef struct
{
	uint32 ISER[8];	//0x100
	uint32 Res1[24];//0x11C

	uint32 ICER[8];	//
	uint32 Res2[24];

	uint32 ISPR[8];
	uint32 Res3[24];

	uint32 ICPR[8];
	uint32 Res4[24];

	uint32 IABR[8];
	uint32 Res5[56];

	uint8 IPR[240];
	uint32 Res6[644];
	uint32 STIR;
} dtNVIC;

#endif /* NVIC_NVIC_TYPES_H_ */

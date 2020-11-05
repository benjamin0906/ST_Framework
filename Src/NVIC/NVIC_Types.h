/*
 * NVIC_Types.h
 *
 *  Created on: Jun 24, 2020
 *      Author: BodnarB
 */

#ifndef NVIC_NVIC_TYPES_H_
#define NVIC_NVIC_TYPES_H_

#include "types.h"

typedef struct
{
	uint32 ISER[8];
} dtISER;

typedef struct
{
	uint32 ICER[8];
} dtICER;

typedef struct
{
	uint32 ISPR[8];
} dtISPR;

typedef struct
{
	uint32 ICPR[8];
} dtICPR;

typedef struct
{
	uint32 IABR[8];
} dtIABR;

typedef struct
{
	uint8 ISER[240];
} dtIPR;

#endif /* NVIC_NVIC_TYPES_H_ */

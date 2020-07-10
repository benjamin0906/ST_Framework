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
	uint8 ISER[32];
} dtISER;

typedef struct
{
	uint8 ICER[32];
} dtICER;

typedef struct
{
	uint8 ISPR[32];
} dtISPR;

typedef struct
{
	uint8 ICPR[32];
} dtICPR;

typedef struct
{
	uint8 IABR[32];
} dtIABR;

typedef struct
{
	uint8 ISER[240];
} dtIPR;

#endif /* NVIC_NVIC_TYPES_H_ */

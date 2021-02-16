/*
 * VREFBUF_Types.h
 *
 *  Created on: 2021. febr. 16.
 *      Author: Benjamin
 */

#ifndef SRC_VREFBUF_VREFBUF_TYPES_H_
#define SRC_VREFBUF_VREFBUF_TYPES_H_

#include "types.h"

typedef union
{
	uint32 Word;
	struct
	{
		uint32 ENVR	:1;
		uint32 HIZ	:1;
		uint32 VRS	:1;
		uint32 VRR	:1;
	} Fields;
} dtVrefBuf_CSR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 TRIM	:6;
	} Fields;
} dtVrefBuf_CCR;

#endif /* SRC_VREFBUF_VREFBUF_TYPES_H_ */

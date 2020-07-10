/*
 * Flash_Types.h
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef FLASH_FLASH_TYPES_H_
#define FLASH_FLASH_TYPES_H_

#include "types.h"

#if defined(MCU_F410)
typedef union
{
	struct
	{
		uint32 LATENCY	:4;
		uint32			:4;
		uint32 PRFTEN	:1;
		uint32 ICEN		:1;
		uint32 DCEN		:1;
		uint32 ICRST	:1;
		uint32 DCRST	:1;
		uint32			:19;
	} Fields;
	uint32 Word;
} dtACR;

typedef union
{
	struct
	{
		uint32 KEYR		:32;
	} Fields;
	uint32 Word;
} dtKEYR;

typedef union
{
	struct
	{
		uint32 OPTKEYR	:32;
	} Fields;
	uint32 Word;
} dtOPTKEYR;

typedef union
{
	struct
	{
		uint32 EOP		:1;
		uint32 OPERR	:1;
		uint32 			:2;
		uint32 WRPERR	:1;
		uint32 PGAERR	:1;
		uint32 PGPERR	:1;
		uint32 PGSERR	:1;
		uint32 RDERR	:1;
		uint32 			:7;
		uint32 BSY		:1;
		uint32 			:15;
	} Fields;
	uint32 Word;
} dtSR;

typedef union
{
	struct
	{
		uint32 PG			:1;
		uint32 SER			:1;
		uint32 MER			:1;
		uint32 SNB			:4;
		uint32 				:1;
		uint32 PSIZE		:2;
		uint32 				:6;
		uint32 STRT			:1;
		uint32 				:7;
		uint32 EOPIE		:1;
		uint32 ERRIE		:1;
		uint32 				:5;
		uint32 LOCK			:1;
	} Fields;
	uint32 Word;
} dtCR;

typedef union
{
	struct
	{
		uint32 OPTLOCK		:1;
		uint32 OPTSTRT		:1;
		uint32 BOR_LEV		:2;
		uint32 				:1;
		uint32 WDG_SW		:1;
		uint32 nRST_STOP	:1;
		uint32 nRST_STDBY	:1;
		uint32 RDP			:8;
		uint32 nWRP			:5;
		uint32 				:10;
		uint32 SPRMOD		:1;
	}Fields;
	uint32 Word;
} dtOPTCR;

typedef struct
{
	dtACR ACR;
	dtKEYR KEY;
	dtOPTKEYR OPTKEYR;
	dtSR SR;
	dtCR CR;
	dtOPTCR OPTCR;
} dtFlash;
#elif defined(MCU_F446)
typedef union
{
	struct
	{
		uint32 LATENCY	:4;
		uint32			:4;
		uint32 PRFTEN	:1;
		uint32 ICEN		:1;
		uint32 DCEN		:1;
		uint32 ICRST	:1;
		uint32 DCRST	:1;
		uint32			:19;
	} Fields;
	uint32 Word;
} dtACR;

typedef union
{
	struct
	{
		uint32 KEYR		:32;
	} Fields;
	uint32 Word;
} dtKEYR;

typedef union
{
	struct
	{
		uint32 OPTKEYR	:32;
	} Fields;
	uint32 Word;
} dtOPTKEYR;

typedef union
{
	struct
	{
		uint32 EOP		:1;
		uint32 OPERR	:1;
		uint32 			:2;
		uint32 WRPERR	:1;
		uint32 PGAERR	:1;
		uint32 PGPERR	:1;
		uint32 PGSERR	:1;
		uint32 RDERR	:1;
		uint32 			:7;
		uint32 BSY		:1;
		uint32 			:15;
	} Fields;
	uint32 Word;
} dtSR;

typedef union
{
	struct
	{
		uint32 PG			:1;
		uint32 SER			:1;
		uint32 MER			:1;
		uint32 SNB			:4;
		uint32 				:1;
		uint32 PSIZE		:2;
		uint32 				:6;
		uint32 STRT			:1;
		uint32 				:7;
		uint32 EOPIE		:1;
		uint32 ERRIE		:1;
		uint32 				:5;
		uint32 LOCK			:1;
	} Fields;
	uint32 Word;
} dtCR;

typedef union
{
	struct
	{
		uint32 OPTLOCK		:1;
		uint32 OPTSTRT		:1;
		uint32 BOR_LEV		:2;
		uint32 				:1;
		uint32 WDG_SW		:1;
		uint32 nRST_STOP	:1;
		uint32 nRST_STDBY	:1;
		uint32 RDP			:8;
		uint32 nWRP			:8;
		uint32 				:7;
		uint32 SPRMOD		:1;
	}Fields;
	uint32 Word;
} dtOPTCR;

typedef struct
{
	dtACR ACR;
	dtKEYR KEY;
	dtOPTKEYR OPTKEYR;
	dtSR SR;
	dtCR CR;
	dtOPTCR OPTCR;
} dtFlash;
#endif

#endif /* FLASH_FLASH_TYPES_H_ */

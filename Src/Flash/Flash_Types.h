/*
 * Flash_Types.h
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef FLASH_FLASH_TYPES_H_
#define FLASH_FLASH_TYPES_H_

#include "types.h"

typedef union
{
	struct
	{
		uint32 LATENCY	:3;
		uint32			:5;
		uint32 PRFTEN	:1;
		uint32 ICEN		:1;
		uint32 DCEN		:1;
		uint32 ICRST	:1;
		uint32 DCRST	:1;
		uint32 RUN_PD	:1;
		uint32 SLEEP_PD	:1;
		uint32			:17;
	} Field;
	uint32 Word;
} dtACR;

typedef union
{
	struct
	{
		uint32 PDKEYR	:32;
	} Field;
	uint32 Word;
} dtPDKEYR;

typedef union
{
	struct
	{
		uint32 KEYR		:32;
	} Field;
	uint32 Word;
} dtKEYR;

typedef union
{
	struct
	{
		uint32 OPTKEYR	:32;
	} Field;
	uint32 Word;
} dtOPTKEYR;

typedef union
{
	struct
	{
		uint32 EOP		:1;
		uint32 OPERR	:1;
		uint32 			:1;
		uint32 PROGERR	:1;
		uint32 WRPERR	:1;
		uint32 PGAERR	:1;
		uint32 SIZERR	:1;
		uint32 PGSERR	:1;
		uint32 MISSERR	:1;
		uint32 FASTERR	:1;
		uint32 			:4;
		uint32 RDERR	:1;
		uint32 OPTVERR	:1;
		uint32 BSY		:1;
		uint32 			:15;
	} Field;
	uint32 Word;
} dtSR;

typedef union
{
	struct
	{
		uint32 PG			:1;
		uint32 PER			:1;
		uint32 MER1			:1;
		uint32 PNB			:8;
		uint32 BKER			:1;
		uint32 				:3;
		uint32 MER2			:1;
		uint32 STRT			:1;
		uint32 OPTSTRT		:1;
		uint32 FSTPG		:1;
		uint32 				:5;
		uint32 EOPIE		:1;
		uint32 ERRIE		:1;
		uint32 RDERRIE		:1;
		uint32 OBL_LAUNCH	:1;
		uint32 				:2;
		uint32 OPT_LOCK		:1;
		uint32 LOCK			:1;
	} Field;
	uint32 Word;
} dtCR;

typedef union
{
	struct
	{
		uint32 ADDR_ECC		:19;
		uint32 BK_ECC		:1;
		uint32 SYSF_ECC		:1;
		uint32 				:3;
		uint32 ECCCIE		:1;
		uint32 				:5;
		uint32 ECCC			:1;
		uint32 ECCD			:1;
	} Field;
	uint32 Word;
} dtECCR;

typedef union
{
	struct
	{
		uint32 RDP			:8;
		uint32 BOR_LEV		:3;
		uint32 				:1;
		uint32 nRST_STOP	:1;
		uint32 nRST_STDBY	:1;
		uint32 nRST_SHDW	:1;
		uint32 				:1;
		uint32 IWDG_SW		:1;
		uint32 IWDG_STOP	:1;
		uint32 IWDG_STDBY	:1;
		uint32 WWDG_SW		:1;
		uint32 BFB2			:1;
		uint32 DUAL_BANK	:1;
		uint32 				:1;
		uint32 nBOOT		:1;
		uint32 SRAM2_PE		:1;
		uint32 SRAM2_RST	:1;
		uint32 nSW_BOOT0	:1;
		uint32 nBOOT0		:1;
		uint32 				:4;
	} Field;
	uint32 Word;
} dtOPTR;

typedef union
{
	struct
	{
		uint32 PCROP1_STRT	:16;
	} Field;
	uint32 Word;
} dtPCROP1SR;

typedef union
{
	struct
	{
		uint32 PCROP1_END	:16;
		uint32 				:15;
		uint32 PCROP_RDP	:1;
	} Field;
	uint32 Word;
} dtPCROP1ER;

typedef union
{
	struct
	{
		uint32 WRP1A_STRT	:8;
		uint32 				:8;
		uint32 WRP1A_END	:8;
		uint32 				:8;
	} Field;
	uint32 Word;
} dtWRP1AR;

typedef union
{
	struct
	{
		uint32 WRP1B_STRT	:8;
		uint32 				:8;
		uint32 WRP1B_END	:8;
		uint32 				:8;
	} Field;
	uint32 Word;
} dtWRP1BR;

typedef union
{
	struct
	{
		uint32 PCROP2_STRT	:16;
		uint32 				:16;
	} Field;
	uint32 Word;
} dtPCROP2SR;

typedef union
{
	struct
	{
		uint32 PCROP2_END	:16;
		uint32 				:16;
	} Field;
	uint32 Word;
} dtPCROP2ER;

typedef union
{
	struct
	{
		uint32 WRP2A_STRT	:8;
		uint32 				:8;
		uint32 WRP2A_END	:8;
		uint32 				:8;
	} Field;
	uint32 Word;
} dtWRP2AR;

typedef union
{
	struct
	{
		uint32 WRP2B_STRT	:8;
		uint32 				:8;
		uint32 WRP2B_END	:8;
		uint32 				:8;
	} Field;
	uint32 Word;
} dtWRP2BR;

typedef struct
{
	dtACR		ACR;
	dtPDKEYR	PDKEYR;
	dtKEYR		KEYR;
	dtOPTKEYR	OPTKEYR;
	dtSR		SR;
	dtCR		CR;
	dtECCR		ECCR;
	dtOPTR		OPTR;
	dtPCROP1SR	PCROP1SR;
	dtPCROP1ER	PCROP1ER;
	dtWRP1AR	WRP1AR;
	dtWRP1BR	WRP1BR;
	dtPCROP2SR	PCROP2SR;
	dtPCROP2ER	PCROP2ER;
	dtWRP2AR	WRP2AR;
	dtWRP2BR	WRP2BR;
} dtFLASH;

#endif /* FLASH_FLASH_TYPES_H_ */

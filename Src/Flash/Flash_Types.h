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
} dtFlashCR;

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
} dtFlashCR;

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
#elif defined(MCU_G070) || defined(MCU_G071)
typedef union
{
	struct
	{
		uint32 LATENCY		:3;
		uint32				:5;
		uint32 PRFTEN		:1;
		uint32 ICEN			:1;
		uint32				:1;
		uint32 ICRST		:1;
		uint32				:4;
		uint32 EMPTY		:1;
#if defined(MCU_G071)
		uint32				:1;
		uint32 DBG_SWEN		:1;
#endif
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
		uint32 EOP			:1;
		uint32 OPERR		:1;
		uint32 				:1;
		uint32 PROGERR		:1;
		uint32 WRPERR		:1;
		uint32 PGAERR		:1;
		uint32 SIZERR		:1;
		uint32 PGSERR		:1;
		uint32 MISERR		:1;
		uint32 FASTERR		:1;
#if defined(MCU_G070)
		uint32 				:5;
#elif defined(MCU_G071)
		uint32				:4;
		uint32 RDERR		:1;
#endif
		uint32 OPTVERR		:1;
		uint32 BSY1			:1;
		uint32 				:1;
		uint32 CFGBSY		:1;
	} Fields;
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
		uint32 				:5;
		uint32 STRT			:1;
		uint32 OPTSTRT		:1;
		uint32 FSTPG		:1;
		uint32 				:5;
		uint32 EOPIE		:1;
		uint32 ERRIE		:1;
#if defined(MCU_G070)
		uint32 				:1;
#elif defined(MCU_G071)
		uint32 RDERRIE		:1;
#endif
		uint32 OBL_LAUNCH	:1;
#if defined(MCU_G070)
		uint32 				:2;
#elif defined(MCU_G071)
		uint32 SEC_PROT		:1;
		uint32				:1;
#endif
		uint32 OPTLOCK		:1;
		uint32 LOCK			:1;
	} Fields;
	uint32 Word;
} dtFlashCR;

typedef union
{
	struct
	{
		uint32 ADDR_ECC		:14;
		uint32 				:6;
		uint32 SYSF_ECC		:1;
		uint32 				:3;
		uint32 ECCCIE		:1;
		uint32 				:5;
		uint32 ECCC			:1;
		uint32 ECCD			:1;
	} Fields;
	uint32 Word;
} dtECCR;

typedef union
{
	struct
	{
		uint32 RDP			:8;
#if defined(MCU_G070)
		uint32 				:5;
#elif defined(MCU_G071)
		uint32 BOR_EN		:1;
		uint32 BORR_LEV		:2;
		uint32 BORF_LEV		:2;
#endif
		uint32 nRST_STOP	:1;
		uint32 nRST_STDBY	:1;
#if defined(MCU_G070)
		uint32 				:1;
#elif defined(MCU_G071)
		uint32 nRST_SHDW	:1;
#endif
		uint32 IWDG_SW		:1;
		uint32 IWDG_STOP	:1;
		uint32 IWDG_STBY	:1;
		uint32 WWDG_SW		:1;
		uint32 				:2;
		uint32 RAM_PARITY_CHECK:1;
		uint32 				:1;
		uint32 nBOOT_SEL	:1;
		uint32 nBOOT1		:1;
		uint32 nBOOT0		:1;
#if defined(MCU_G071)
		uint32 NRST_MODE	:2;
		uint32 IRHEN		:1;
#endif
	} Fields;
	uint32 Word;
} dtOPTR;

#if defined(MCU_G071)
typedef union
{
	struct
	{
		uint32 PCROP1A_STRT	:8;
	} Fields;
	uint32 Word;
} dtPCROP1ASR;

typedef union
{
	struct
	{
		uint32 PCROP1A_END	:8;
	} Fields;
	uint32 Word;
} dtPCROP1AER;

#endif

typedef union
{
	struct
	{
		uint32 WRP1A_STRT	:6;
		uint32				:10;
		uint32 WRP1A_END	:6;
	} Fields;
	uint32 Word;
} dtWRP1AR;

typedef union
{
	struct
	{
		uint32 WRP1B_STRT	:6;
		uint32				:10;
		uint32 WRP1B_END	:6;
	} Fields;
	uint32 Word;
} dtWRP1BR;

#if defined(MCU_G071)
typedef union
{
	struct
	{
		uint32 PCROP1B_STRT	:8;
	} Fields;
	uint32 Word;
} dtPCROP1BSR;

typedef union
{
	struct
	{
		uint32 PCROP1B_END	:8;
	} Fields;
	uint32 Word;
} dtPCROP1BER;

typedef union
{
	struct
	{
		uint32 SEC_SIZE		:7;
		uint32				:9;
		uint32 BOOT_LOCK	:1;
	} Fields;
	uint32 Word;
} dtSECR;

#endif
#elif defined(MCU_F415)
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
		uint32 			:8;
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
		uint32 				:6;
		uint32 LOCK			:1;
	} Fields;
	uint32 Word;
} dtFlashCR;

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
		uint32 nWRP			:12;
		uint32 				:4;
	}Fields;
	uint32 Word;
} dtOPTCR;
#elif defined(MCU_L476)
typedef union
{
	struct
	{
		uint32 LATENCY		:3;
		uint32				:5;
		uint32 PRFTEN		:1;
		uint32 ICEN			:1;
		uint32 DECEN		:1;
		uint32 ICRST		:1;
		uint32 DCRST		:1;
		uint32 RUN_PD		:1;
		uint32 SLEEP_PD		:1;
	} Fields;
	uint32 Word;
} dtACR;

typedef union
{
	struct
	{
		uint32 PDKEYR		:32;
	} Fields;
	uint32 Word;
} dtPDKEYR;

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
		uint32 EOP			:1;
		uint32 OPERR		:1;
		uint32 				:1;
		uint32 PROGERR		:1;
		uint32 WRPERR		:1;
		uint32 PGAERR		:1;
		uint32 SIZERR		:1;
		uint32 PGSERR		:1;
		uint32 MISERR		:1;
		uint32 FASTERR		:1;
		uint32				:4;
		uint32 RDERR		:1;
		uint32 OPTVERR		:1;
		uint32 BSY1			:1;
	} Fields;
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
		uint32 OPTLOCK		:1;
		uint32 LOCK			:1;
	} Fields;
	uint32 Word;
} dtFlashCR;

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
	} Fields;
	uint32 Word;
} dtECCR;

typedef union
{
	struct
	{
		uint32 RDP			:8;
		uint32 BOR_LEV		:2;
		uint32 				:1;
		uint32 nRST_STOP	:1;
		uint32 nRST_STDBY	:1;
		uint32 nRST_SHDW	:1;
		uint32 				:1;
		uint32 IWDG_SW		:1;
		uint32 IWDG_STOP	:1;
		uint32 IWDG_STBY	:1;
		uint32 WWDG_SW		:1;
		uint32 BFB2			:1;
		uint32 DUALBANK		:1;
		uint32 				:1;
		uint32 nBOOT1		:1;
		uint32 SRAM2_PE		:1;
		uint32 SRAM2_RST	:1;
		uint32 nSWBOOT0		:1;
		uint32 nBOOT0		:1;
	} Fields;
	uint32 Word;
} dtOPTR;

typedef union
{
	struct
	{
		uint32 PCROP1A_STRT	:8;
	} Fields;
	uint32 Word;
} dtPCROP1SR;

typedef union
{
	struct
	{
		uint32 PCROP1A_END	:8;
	} Fields;
	uint32 Word;
} dtPCROP1ER;


typedef union
{
	struct
	{
		uint32 WRP1A_STRT	:8;
		uint32				:8;
		uint32 WRP1A_END	:8;
	} Fields;
	uint32 Word;
} dtWRP1AR;

typedef union
{
	struct
	{
		uint32 WRP1B_STRT	:8;
		uint32				:8;
		uint32 WRP1B_END	:8;
	} Fields;
	uint32 Word;
} dtWRP1BR;
#endif


typedef struct
{
#if defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
	dtACR 		ACR;
#endif
#if defined(MCU_G070) || defined(MCU_G071)
	uint32		:32;
#elif defined(MCU_L476)
	dtPDKEYR	PDKEY;
#endif
#if defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
	dtKEYR 		KEY;
#endif
#if defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
	dtOPTKEYR 	OPTKEYR;
#endif
#if defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
	dtSR 		SR;
#endif
#if defined(MCU_F410) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F446) || defined(MCU_F415) || defined(MCU_L476)
	dtFlashCR 	CR;
#endif
#if defined(MCU_F446) || defined(MCU_F410) || defined(MCU_F415)
	dtOPTCR		OPTCR;
#endif
#if defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
	dtECCR		ECCR;
#endif
#if defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
	dtOPTR		OPTCR;
#endif
#if defined(MCU_G070)
	uint32		:32;
	uint32		:32;
#elif defined(MCU_G071)
	dtPCROP1ASR	PCROP1ASR;
	dtPCROP1AER	PCROP1AER;
#elif defined(MCU_L476)
	dtPCROP1SR	PCROP1ASR;
	dtPCROP1ER	PCROP1AER;
#endif
#if defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
	dtWRP1AR	WRP1AR;
#endif
#if defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
	dtWRP1BR	WRP1BR;
#endif
#if defined(MCU_G071)
	dtPCROP1BSR	PCROP1BSR;
	dtPCROP1BER PCROP1BER;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	uint32		:32;
	dtSECR		SECR;
#endif
} dtFlash;

#endif /* FLASH_FLASH_TYPES_H_ */

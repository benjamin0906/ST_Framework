/*
 * FLASH_regdef.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_FLASH_REGDEF_H_
#define INC_REGDEFS_FLASH_REGDEF_H_

#include "RegDefs/regdef_helper.h"

typedef struct sFLASH_ACR
{
	uint32 LATENCY  :3;
	uint32          :5;
	uint32 PRFTEN   :1;
	uint32 ICEN     :1;
	uint32          :1;
	uint32 ICRST    :1;
	uint32          :4;
	uint32 EMPTY    :1;
	uint32          :1;
	uint32 DBG_SWEN :1;
	uint32          :13;
} dtFLASH_ACR_Bits;

typedef struct sFLASH_KEYR
{
	uint32 KEYR     :32;
} dtFLASH_KEYR_Bits;

typedef struct sFLASH_OPTKEYR
{
	uint32 OPTKEY   :32;
} dtFLASH_OPTKEYR_Bits;

typedef struct sFLASH_SR
{
	uint32 EOP          :1;
	uint32 OPERR        :1;
	uint32              :1;
	uint32 PROGERR      :1;
	uint32 WRPERR       :1;
	uint32 PGAERR       :1;
	uint32 SIZERR       :1;
	uint32 PGSERR       :1;
	uint32 MISERR       :1;
	uint32 FASTERR      :1;
	uint32              :1;
	uint32 HDPOPTWERR   :1;
	uint32 OEMOPTWERR   :1;
	uint32              :2;
	uint32 OPTVERR      :1;
	uint32 BSY1         :1;
	uint32              :1;
	uint32 CFGBSY       :1;
	uint32              :1;
	uint32 OEM1LOCK     :1;
	uint32 OEM2LOCK     :1;
} dtFLASH_SR_Bits;

typedef struct sFLASH_CR
{
	uint32 PG           :1;
	uint32 PER          :1;
	uint32 MER1         :1;
	uint32 PNB          :1;
	uint32              :6;
	uint32 STRT         :1;
	uint32 OPTSTRT      :1;
	uint32 FSTPG        :1;
	uint32              :1;
	uint32 EOPIE        :1;
	uint32 ERRIE        :1;
	uint32              :1;
	uint32 OBL_LAUNCH   :1;
	uint32              :2;
	uint32 OPTLOCK      :1;
	uint32 LOCK         :1;
} dtFLASH_CR_Bits;

typedef struct sFLASH_ECCR
{
	uint32 ADDR_ECC     :14;
	uint32              :6;
	uint32 SYSF_ECC     :1;
	uint32              :3;
	uint32 ECCCIE       :1;
	uint32              :5;
	uint32 ECCC         :1;
	uint32 ECCD         :1;
} dtFLASH_ECCR_Bits;

typedef struct sFLASH_OPTR
{
    uint32 RDP                      :8;
    uint32 BOR_LEV                  :3;
    uint32                          :2;
    uint32 NRST_STOP                :1;
    uint32 NRST_STDBY               :1;
    uint32 NRST_SHDW                :1;
    uint32 IWDG_SW                  :1;
    uint32 IWDG_STOP                :1;
    uint32 IWDG_STBY                :1;
    uint32 WWDG_SW                  :1;
    uint32                          :1;
    uint32 BDRST                    :1;
    uint32 RAM_PARITY_CHECK         :1;
    uint32 BKPSRAM_HW_ERASE_DISABLE :1;
    uint32 NBOOT_SEL                :1;
    uint32 NBOOT1                   :1;
    uint32 NBOOT0                   :1;
    uint32 NRST_MODE                :2;
    uint32 IRHEN                    :1;
    uint32                          :2;
} dtFLASH_OPTR_Bits;

typedef struct sFLASH_WRP1AR
{
	uint32 WRP1A_STRT       :7;
    uint32                  :9;
    uint32 WRP1A_END        :4;
    uint32                  :12;
} dtFLASH_WRP1AR_Bits;

typedef struct sFLASH_WRP1BR
{
	uint32 WRP1B_STRT       :7;
    uint32                  :9;
    uint32 WRP1B_END        :4;
    uint32                  :12;
} dtFLASH_WRP1BR_Bits;

typedef struct sFLASH_SECR
{
	uint32 HDP1_PEND    :7;
    uint32              :9;
    uint32 BOOT_LOCK    :1;
    uint32              :7;
    uint32 HDP1EN       :8;
} dtFLASH_SECR_Bits;

typedef struct sFLASH_OEM1KEYR1
{
	uint32 OEM1KEY  :32;
} dtFLASH_OEM1KEYR1_Bits;

typedef struct sFLASH_OEM1KEYR2
{
	uint32 OEM1KEY  :32;
} dtFLASH_OEM1KEYR2_Bits;

typedef struct sFLASH_OEM1KEYR3
{
	uint32 OEM1KEY;
} dtFLASH_OEM1KEYR3_Bits;

typedef struct sFLASH_OEM1KEYR4
{
    uint32 OEM1KEY;
} dtFLASH_OEM1KEYR4_Bits;

typedef struct sFLASH_OEM2KEYR1
{
    uint32 OEM2KEY;
} dtFLASH_OEM2KEYR1_Bits;

typedef struct sFLASH_OEM2KEYR2
{
    uint32 OEM2KEY;
} dtFLASH_OEM2KEYR2_Bits;

typedef struct sFLASH_OEM2KEYR3
{
    uint32 OEM2KEY;
} dtFLASH_OEM2KEYR3_Bits;

typedef struct sFLASH_OEM2KEYR4
{
    uint32 OEM2KEY;
} dtFLASH_OEM2KEYR4_Bits;

typedef struct sFLASH_KEYSR
{
    uint32 OEM1KEYCRC   :8;
    uint32              :8;
    uint32 OEM2KEYCRC   :8;
    uint32              :8;
} dtFLASH_KEYSR_Bits;

typedef struct sFLASH_HDPCR
{
    uint32 HDP1_ACCDIS      :8;
    uint32                  :8;
    uint32 HDP1EXT_ACCDIS   :8;
    uint32                  :8;
} dtFLASH_HDPCR_Bits;


typedef struct sFLASH_HDPEXTR
{
    uint32 HDP1_EXT     :7;
    uint32              :25;
} dtFLASH_HDPEXTR_Bits;

REGDEF(FLASH, ACR);
REGDEF(FLASH, KEYR);
REGDEF(FLASH, OPTKEYR);
REGDEF(FLASH, SR);
REGDEF(FLASH, CR);
REGDEF(FLASH, ECCR);
REGDEF(FLASH, OPTR);
REGDEF(FLASH, WRP1AR);
REGDEF(FLASH, WRP1BR);
REGDEF(FLASH, SECR);
REGDEF(FLASH, OEM1KEYR1);
REGDEF(FLASH, OEM1KEYR2);
REGDEF(FLASH, OEM1KEYR3);
REGDEF(FLASH, OEM1KEYR4);
REGDEF(FLASH, OEM2KEYR1);
REGDEF(FLASH, OEM2KEYR2);
REGDEF(FLASH, OEM2KEYR3);
REGDEF(FLASH, OEM2KEYR4);
REGDEF(FLASH, KEYSR);
REGDEF(FLASH, HDPCR);
REGDEF(FLASH, HDPEXTR);

typedef struct sFLASH
{
    dtFLASH_ACR         ACR;        //0x00
    uint32 :32;                     //0x04
    dtFLASH_KEYR        KEYR;       //0x08
    dtFLASH_OPTKEYR     OPTKEYR;    //0x0C
    dtFLASH_SR          SR;         //0x10
    dtFLASH_CR          CR;         //0x14
    dtFLASH_ECCR        ECCR;       //0x18
    uint32 :32;                     //0x1C
    dtFLASH_OPTR        OPTR;       //0x20
    uint32 :32;                     //0x24
    uint32 :32;                     //0x28
    dtFLASH_WRP1AR      WRP1AR;     //0x2C
    dtFLASH_WRP1BR      WRP1BR;     //0x30
    uint32 :32;                     //0x34
    uint32 :32;                     //0x38
    uint32 :32;                     //0x3C
    uint32 :32;                     //0x40
    uint32 :32;                     //0x44
    uint32 :32;                     //0x48
    uint32 :32;                     //0x4C
    uint32 :32;                     //0x50
    uint32 :32;                     //0x54
    uint32 :32;                     //0x58
    uint32 :32;                     //0x5C
    uint32 :32;                     //0x60
    uint32 :32;                     //0x64
    uint32 :32;                     //0x68
    uint32 :32;                     //0x6C
    uint32 :32;                     //0x70
    uint32 :32;                     //0x74
    uint32 :32;                     //0x78
    uint32 :32;                     //0x7C
    dtFLASH_SECR        SECR;       //0x80
    uint32 :32;                     //0x84
    dtFLASH_OEM1KEYR1   OEM1KEYR1;  //0x88
    dtFLASH_OEM1KEYR2   OEM1KEYR2;  //0x8C
    dtFLASH_OEM1KEYR3   OEM1KEYR3;  //0x90
    dtFLASH_OEM1KEYR4   OEM1KEYR4;  //0x94
    dtFLASH_OEM2KEYR1   OEM2KEYR1;  //0x98
    dtFLASH_OEM2KEYR2   OEM2KEYR2;  //0x9C
    dtFLASH_OEM2KEYR3   OEM2KEYR3;  //0xA0
    dtFLASH_OEM2KEYR4   OEM2KEYR4;  //0xA4
    dtFLASH_KEYSR       KEYSR;      //0xA8
    dtFLASH_HDPCR       HDPCR;      //0xAC
    dtFLASH_HDPEXTR     HDPEXTR;    //0xB0
} dtFLASH;

#endif /* INC_REGDEFS_FLASH_REGDEF_H_ */

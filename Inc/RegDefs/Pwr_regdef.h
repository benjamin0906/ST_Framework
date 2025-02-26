/*
 * Pwr_regdef.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_PWR_REGDEF_H_
#define INC_REGDEFS_PWR_REGDEF_H_

#include "RegDefs/regdef_helper.h"

#if defined(STM32U0)

typedef struct sPWR_CR1_Bits
{
	uint32 LPMS         :3;
	uint32 FPD_STOP     :1;
	uint32 FPD_LPRUN    :1;
	uint32 FPD_LPSLP    :1;
	uint32              :2;
	uint32 DBP          :1;
	uint32 VOS          :2;
	uint32              :3;
	uint32 LPR          :1;
	uint32              :17;
} dtPWR_CR1_Bits;

typedef struct sPWR_CR2_Bits
{
	uint32 PVDE         :1;
	uint32 PLS          :3;
	uint32 PVME1        :1;
	uint32 PVME3        :1;
	uint32 PVME4        :1;
	uint32              :3;
	uint32 USV          :1;
	uint32              :21;
} dtPWR_CR2_Bits;

typedef struct sPWR_CR3_Bits
{
	uint32 EWUP1        :1;
	uint32 EWUP2        :1;
	uint32 EWUP3        :1;
	uint32 EWUP4        :1;
	uint32 EWUP5        :1;
	uint32              :1;
	uint32 EWUP7        :1;
	uint32              :1;
	uint32 RRS          :1;
	uint32 ENULP        :1;
	uint32 APC          :1;
	uint32              :4;
	uint32 EIWUL        :1;
	uint32              :16;
} dtPWR_CR3_Bits;

typedef struct sPWR_CR4_Bits
{
	uint32 WP1          :1;
	uint32 WP2          :1;
	uint32 WP3          :1;
	uint32 WP4          :1;
	uint32 WP5          :1;
	uint32              :1;
	uint32 WP7          :1;
	uint32              :1;
	uint32 VBE          :1;
	uint32 VBRS         :1;
	uint32              :22;
} dtPWR_CR4_Bits;

typedef struct sPWR_SR1_Bits
{
	uint32 WUF1         :1;
	uint32 WUF2         :1;
	uint32 WUF3         :1;
	uint32 WUF4         :1;
	uint32 WUF5         :1;
	uint32              :1;
	uint32 WUF7         :1;
	uint32              :1;
	uint32 SBF          :1;
	uint32 STOPF        :3;
	uint32              :3;
	uint32 WUFI         :1;
	uint32              :16;
} dtPWR_SR1_Bits;

typedef struct sPWR_SR2_Bits
{
	uint32              :7;
	uint32 FLASH_RDY    :1;
	uint32 REGLPS       :1;
	uint32 REGLPF       :1;
	uint32 VOSF         :1;
	uint32 PVDO         :1;
	uint32 PVMO1        :1;
	uint32              :1;
	uint32 PVMO3        :1;
	uint32 PVMO4        :1;
	uint32              :16;
} dtPWR_SR2_Bits;

typedef struct sPWR_SCR_Bits
{
	uint32 CWUF1        :1;
	uint32 CWUF2        :1;
	uint32 CWUF3        :1;
	uint32 CWUF4        :1;
	uint32 CWUF5        :1;
	uint32              :1;
	uint32 CWUF7        :1;
	uint32              :1;
	uint32 CSBF         :1;
	uint32              :23;
} dtPWR_SCR_Bits;

typedef struct sPWR_PUCRA_Bits
{
	uint32 PU0          :1;
	uint32 PU1          :1;
	uint32 PU2          :1;
	uint32 PU3          :1;
	uint32 PU4          :1;
	uint32 PU5          :1;
	uint32 PU6          :1;
	uint32 PU7          :1;
	uint32 PU8          :1;
	uint32 PU9          :1;
	uint32 PU10         :1;
	uint32 PU11         :1;
	uint32 PU12         :1;
	uint32 PU13         :1;
	uint32 PU14         :1;
	uint32 PU15         :1;
	uint32              :16;
} dtPWR_PUCRA_Bits;

typedef struct sPWR_PDCRA_Bits
{
	uint32 PD0          :1;
	uint32 PD1          :1;
	uint32 PD2          :1;
	uint32 PD3          :1;
	uint32 PD4          :1;
	uint32 PD5          :1;
	uint32 PD6          :1;
	uint32 PD7          :1;
	uint32 PD8          :1;
	uint32 PD9          :1;
	uint32 PD10         :1;
	uint32 PD11         :1;
	uint32 PD12         :1;
	uint32 PD13         :1;
	uint32 PD14         :1;
	uint32 PD15         :1;
	uint32              :16;
} dtPWR_PDCRA_Bits;

typedef struct sPWR_PUCRB_Bits
{
	uint32 PU0          :1;
	uint32 PU1          :1;
	uint32 PU2          :1;
	uint32 PU3          :1;
	uint32 PU4          :1;
	uint32 PU5          :1;
	uint32 PU6          :1;
	uint32 PU7          :1;
	uint32 PU8          :1;
	uint32 PU9          :1;
	uint32 PU10         :1;
	uint32 PU11         :1;
	uint32 PU12         :1;
	uint32 PU13         :1;
	uint32 PU14         :1;
	uint32 PU15         :1;
	uint32              :16;
} dtPWR_PUCRB_Bits;

typedef struct sPWR_PDCRB_Bits
{
	uint32 PD0          :1;
	uint32 PD1          :1;
	uint32 PD2          :1;
	uint32 PD3          :1;
	uint32 PD4          :1;
	uint32 PD5          :1;
	uint32 PD6          :1;
	uint32 PD7          :1;
	uint32 PD8          :1;
	uint32 PD9          :1;
	uint32 PD10         :1;
	uint32 PD11         :1;
	uint32 PD12         :1;
	uint32 PD13         :1;
	uint32 PD14         :1;
	uint32 PD15         :1;
	uint32              :16;
} dtPWR_PDCRB_Bits;

typedef struct sPWR_PUCRC_Bits
{
	uint32 PU0          :1;
	uint32 PU1          :1;
	uint32 PU2          :1;
	uint32 PU3          :1;
	uint32 PU4          :1;
	uint32 PU5          :1;
	uint32 PU6          :1;
	uint32 PU7          :1;
	uint32 PU8          :1;
	uint32 PU9          :1;
	uint32 PU10         :1;
	uint32 PU11         :1;
	uint32 PU12         :1;
	uint32 PU13         :1;
	uint32 PU14         :1;
	uint32 PU15         :1;
	uint32              :16;
} dtPWR_PUCRC_Bits;

typedef struct sPWR_PDCRC_Bits
{
	uint32 PD0          :1;
	uint32 PD1          :1;
	uint32 PD2          :1;
	uint32 PD3          :1;
	uint32 PD4          :1;
	uint32 PD5          :1;
	uint32 PD6          :1;
	uint32 PD7          :1;
	uint32 PD8          :1;
	uint32 PD9          :1;
	uint32 PD10         :1;
	uint32 PD11         :1;
	uint32 PD12         :1;
	uint32 PD13         :1;
	uint32 PD14         :1;
	uint32 PD15         :1;
	uint32              :16;
} dtPWR_PDCRC_Bits;

typedef struct sPWR_PUCRD_Bits
{
	uint32 PU0          :1;
	uint32 PU1          :1;
	uint32 PU2          :1;
	uint32 PU3          :1;
	uint32 PU4          :1;
	uint32 PU5          :1;
	uint32 PU6          :1;
	uint32              :1;
	uint32 PU8          :1;
	uint32 PU9          :1;
	uint32 PU10         :1;
	uint32 PU11         :1;
	uint32 PU12         :1;
	uint32 PU13         :1;
	uint32              :18;
} dtPWR_PUCRD_Bits;

typedef struct sPWR_PDCRD_Bits
{
	uint32 PD0          :1;
	uint32 PD1          :1;
	uint32 PD2          :1;
	uint32 PD3          :1;
	uint32 PD4          :1;
	uint32 PD5          :1;
	uint32 PD6          :1;
	uint32              :1;
	uint32 PD8          :1;
	uint32 PD9          :1;
	uint32 PD10         :1;
	uint32 PD11         :1;
	uint32 PD12         :1;
	uint32 PD13         :1;
	uint32              :18;
} dtPWR_PDCRD_Bits;

typedef struct sPWR_PUCRE_Bits
{
	uint32              :3;
	uint32 PU3          :1;
	uint32              :3;
	uint32 PU7          :1;
	uint32 PU8          :1;
	uint32 PU9          :1;
	uint32              :22;
} dtPWR_PUCRE_Bits;

typedef struct sPWR_PDCRE_Bits
{
	uint32              :3;
	uint32 PD3          :1;
	uint32              :3;
	uint32 PD7          :1;
	uint32 PD8          :1;
	uint32 PD9          :1;
	uint32              :22;
} dtPWR_PDCRE_Bits;

typedef struct sPWR_PUCRF_Bits
{
	uint32 PU0          :1;
	uint32 PU1          :1;
	uint32 PU2          :1;
	uint32 PU3          :1;
	uint32              :28;
} dtPWR_PUCRF_Bits;

typedef struct sPWR_PDCRF_Bits
{
	uint32 PD0          :1;
	uint32 PD1          :1;
	uint32 PD2          :1;
	uint32 PD3          :1;
	uint32              :28;
} dtPWR_PDCRF_Bits;

REGDEF(PWR,CR1)
REGDEF(PWR,CR2)
REGDEF(PWR,CR3)
REGDEF(PWR,CR4)
REGDEF(PWR,SR1)
REGDEF(PWR,SR2)
REGDEF(PWR,SCR)
REGDEF(PWR,PUCRA)
REGDEF(PWR,PDCRA)
REGDEF(PWR,PUCRB)
REGDEF(PWR,PDCRB)
REGDEF(PWR,PUCRC)
REGDEF(PWR,PDCRC)
REGDEF(PWR,PUCRD)
REGDEF(PWR,PDCRD)
REGDEF(PWR,PUCRE)
REGDEF(PWR,PDCRE)
REGDEF(PWR,PUCRF)
REGDEF(PWR,PDCRF)

typedef struct sPWR
{
	dtPWR_CR1 CR1;
	dtPWR_CR2 CR2;
	dtPWR_CR3 CR3;
	dtPWR_CR4 CR4;
	dtPWR_SR1 SR1;
	dtPWR_SR2 SR2;
	dtPWR_SCR SCR;
	uint32 :32;
	dtPWR_PUCRA PUCRA;
	dtPWR_PDCRA PDCRA;
	dtPWR_PUCRB PUCRB;
	dtPWR_PDCRB PDCRB;
	dtPWR_PUCRC PUCRC;
	dtPWR_PDCRC PDCRC;
	dtPWR_PUCRD PUCRD;
	dtPWR_PDCRD PDCRD;
	dtPWR_PUCRE PUCRE;
	dtPWR_PDCRE PDCRE;
	dtPWR_PUCRF PUCRF;
	dtPWR_PDCRF PDCRF;
} dtPWR;
#endif

#endif /* INC_REGDEFS_PWR_REGDEF_H_ */

/*
 * SysCfg_Types.h
 *
 *  Created on: 2021. febr. 16.
 *      Author: Benjamin
 */

#ifndef SRC_SYSCFG_SYSCFG_TYPES_H_
#define SRC_SYSCFG_SYSCFG_TYPES_H_

#include "types.h"

#if defined(MCU_L433)
typedef struct
{
	uint32 Word;
	struct
	{
		uint32 MEM_MODE			:2;
		uint32 					:1;
		uint32 PA11_RMP			:1;
		uint32 PA12_RMP			:1;
		uint32 IR_POL			:1;
		uint32 IR_MOD			:2;
		uint32 BOOSTEN			:1;
		uint32 					:7;
		uint32 I2C_PB6_FMP		:1;
		uint32 I2C_PB7_FMP		:1;
		uint32 I2C_PB8_FMP		:1;
		uint32 I2C_PB9_FMP		:1;
		uint32 I2C1_FMP			:1;
		uint32 I2C2_FMP			:1;
		uint32 I2C_PA9_FMP		:1;
		uint32 I2C_PA10_FMP		:1;
	} Fields;
} dtSysCgf_Cfgr1;

typedef struct
{
	uint32 Word;
	struct
	{
		uint32 LOCUP_LOCK		:1;
		uint32 SRAM_PARITY_LOCK	:1;
		uint32 PVD_LOCK			:1;
		uint32 ECC_LOCK			:1;
		uint32 					:4;
		uint32 SRAM_PEF			:1;
	} Fields;
} dtSysCgf_Cfgr2;

typedef struct
{
	uint32 Word;
	struct
	{
		uint32 WWDG	:1;
	} Fields;
} SYSCFG_ITLINE0;

#elif defined(MCU_F446)

typedef union
{
    uint32 Word;
    struct
    {
        uint32 MEM_MODE :3;
        uint32          :7;
        uint32 SWP_FMC  :2;
    };
} dtSysCfg_MEMRMP;

typedef union
{
    uint32 Word;
    struct
    {
        uint32          :16;
        uint32 ADC1CD2  :1;
        uint32 ADC2CD2  :1;
        uint32 ADC3CD2  :1;
    };
} dtSysCfg_PMC;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 EXTIx0    :4;
        uint32 EXTIx1    :4;
        uint32 EXTIx2    :4;
        uint32 EXTIx3    :4;
    };
} dtSysCfg_EXTICRx;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 CMP_PD   :1;
        uint32          :6;
        uint32 READY    :1;
    };
} dtSysCfg_CMPCR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 FMPI2C1_SCL   :1;
        uint32 FMPI2C1_SDA   :6;
    };
} dtSysCfg_CFGR;

typedef struct
{
    dtSysCfg_MEMRMP MEMRMP;
    dtSysCfg_PMC PMC;
    dtSysCfg_EXTICRx EXTICR1;
    dtSysCfg_EXTICRx EXTICR2;
    dtSysCfg_EXTICRx EXTICR3;
    dtSysCfg_EXTICRx EXTICR4;
    dtSysCfg_CMPCR CMPCR;
    dtSysCfg_CFGR CFGR;
} dtSysCfg;

#endif

#endif /* SRC_SYSCFG_SYSCFG_TYPES_H_ */

/*
 * SysCfg_Types.h
 *
 *  Created on: 2021. febr. 16.
 *      Author: Benjamin
 */

#ifndef SRC_SYSCFG_SYSCFG_TYPES_H_
#define SRC_SYSCFG_SYSCFG_TYPES_H_

#include "types.h"

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

#endif /* SRC_SYSCFG_SYSCFG_TYPES_H_ */

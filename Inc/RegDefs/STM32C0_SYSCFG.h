/*
 * STM32C0_SYSCFG.h
 *
 *  Created on: 2026. okt. 20.
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_STM32C0_SYSCFG_H_
#define INC_REGDEFS_STM32C0_SYSCFG_H_

#include "RegDefs/regdef_helper.h"
#include "types.h"

typedef struct sSYSCFG_CFGR1_Bits
{
    uint32 MEM_MODE         :2;
    uint32                  :1;
    uint32 PA11_RMP         :1;
    uint32 PA12_RMP         :1;
    uint32 IR_POL           :1;
    uint32 IR_MOD           :2;
    uint32                  :8;
    uint32 I2C_PB6_FMP      :1;
    uint32 I2C_PB7_FMP      :1;
    uint32 I2C_PB8_FMP      :1;
    uint32 I2C_PB9_FMP      :1;
    uint32 I2C1_FMP         :1;
    uint32 I2C2_FMP         :1;
    uint32 I2C_PA9_FMP      :1;
    uint32 I2C_PA10_FMP     :1;
    uint32 I2C_PA14_FMP     :1;
} dtSYSCFG_CFGR1_Bits;

REGDEF(SYSCFG, CFGR1)

typedef struct sSYSCFG
{
    dtSYSCFG_CFGR1 CFGR1;
} dtSYSCFG;

#endif /* INC_REGDEFS_STM32C0_SYSCFG_H_ */

/*
 * SysCfg.h
 *
 *  Created on: 2023. febr. 5.
 *      Author: Benjamin
 */

#ifndef INC_SYSCFG_H_
#define INC_SYSCFG_H_

#if defined(MCU_L433)
typedef enum
{
    ExtiPort_A,
    ExtiPort_B,
    ExtiPort_C,
    ExtiPort_D,
    ExtiPort_E,
    ExtiPort_F,
    ExtiPort_G,
} dtSysCfgExtiConf;

extern void ISysCfg_SetExti(uint8 ExtiNum, dtSysCfgExtiConf ExtiConf);

#elif defined(STM32C0)

typedef enum eRemaps
{
    SYSCFG_RMP_PA11,
    SYSCFG_RMP_PA12,
} dtRemaps;

extern void SYSCFG_Remap(dtRemaps remap_pin, uint8 enable);

#endif
#endif /* INC_SYSCFG_H_ */

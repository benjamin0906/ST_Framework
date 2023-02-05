/*
 * SysCfg.h
 *
 *  Created on: 2023. febr. 5.
 *      Author: Benjamin
 */

#ifndef INC_SYSCFG_H_
#define INC_SYSCFG_H_

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

#endif /* INC_SYSCFG_H_ */

/*
 * Pwr.h
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#ifndef PWR_PWR_H_
#define PWR_PWR_H_

#include "types.h"

#if defined(MCU_G070) || defined(MCU_G071) || defined(MCU_L476)
typedef enum
{
	Pwr_LPM_Stop0,
	Pwr_LPM_Stop1,
	Pwr_LPM_Standby		= 0x3,
	Pwr_LPM_Shutdown	= 0x4,
} dtLowPwrModes;
#elif defined(STM32U0)
typedef enum
{
	Pwr_LPM_Stop0       = 0x0,
	Pwr_LPM_Stop1,
	Pwr_LPM_Stop2,
	Pwr_LPM_Standby,
	Pwr_LPM_Shutdown,
} dtLowPwrModes;

extern void Pwr_SetVos(uint8 mode);
extern uint8 Pwr_GetVos(void);

#elif defined(STM32C0)

typedef enum eLpModes
{
	Pwr_LPM_Stop 	= 0x0,
	Pwr_LPM_Standby = 0x3,
	Pwr_LPM_Shutdown,
} dtLowPwrModes;

extern void Pwr_LowPowerMode(dtLowPwrModes Mode);

#endif

#endif /* PWR_PWR_H_ */

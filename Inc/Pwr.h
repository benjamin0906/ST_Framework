/*
 * Pwr.h
 *
 *  Created on: 2020. jún. 25.
 *      Author: BodnarB
 */

#ifndef PWR_PWR_H_
#define PWR_PWR_H_

#include "types.h"

typedef enum
{
	Pwr_LPM_Stop0,
	Pwr_LPM_Stop1,
	Pwr_LPM_Standby		= 0x3,
	Pwr_LPM_Shutdown	= 0x4,
} dtLowPwrModes;

extern void Pwr_SetVos(uint8 mode);
extern uint8 Pwr_GetVos(void);
extern void Pwr_LowPowerMode(dtLowPwrModes Mode);

#endif /* PWR_PWR_H_ */

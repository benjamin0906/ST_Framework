/*
 * Pwr.h
 *
 *  Created on: 4 May 2020
 *      Author: Bodnár Benjamin
 */

#ifndef PWR_PWR_H_
#define PWR_PWR_H_

typedef enum
{
	Range_1,
	Range_2,
} dtVoltScale;

extern void Pwr_SetVoltageRange(dtVoltScale Range);
extern dtVoltScale Pwr_GetVoltageRange(void);

#endif /* PWR_PWR_H_ */

/*
 * ADC.h
 *
 *  Created on: 2021. febr. 15.
 *      Author: Benjamin
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "types.h"

typedef struct
{
	uint32 AutoOff		:1;
	uint32 WaitMode		:1;
	uint32 ContMode		:1;
	uint32 OverRun		:1;
	uint32 LeftAlign	:1;
	uint32 Resolution	:2;
	uint32 ClkMode		:2;
	uint32 OverSample	:3;
	uint32 SMP1			:3;
	uint32 SMP2			:3;
	uint32 SMPSEL		:19;
	uint32 CHSEL		:16;

} dtAdcConfig;

extern void ADC_Init(dtAdcConfig Config);

#endif /* INC_ADC_H_ */

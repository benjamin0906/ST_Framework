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
	uint32 OVSEn		:1;
	uint32 OVS			:3;
	uint32 OVSShift		:3;
	uint32 SMP1			:3;
	uint32 SMP2			:3;
	uint32 ClkDiv		:4;

} dtAdcConfig;

typedef enum
{
	ADC_Ch0	= 0,
	ADC_Ch1,
	ADC_Ch2,
	ADC_Ch3,
	ADC_Ch4,
	ADC_Ch5,
	ADC_Ch6,
	ADC_Ch7,
	ADC_Ch8,
	ADC_Ch9,
	ADC_Ch10,
	ADC_Ch11,
	ADC_Ch12,
	ADC_Ch13,
	ADC_Ch14,
	ADC_Ch15,
	ADC_Ch16,
	ADC_Ch17,
	ADC_Ch18,
} dtAdcCh;

typedef enum
{
	ADC_SMP1,
	ADC_SMP2,
} dtAdcSmp;

extern void ADC_Init(dtAdcConfig Config);
extern void ADC_SetChConfig(dtAdcCh Ch, dtAdcSmp Smp);
extern uint8 ADC_CheckChConfig(void);
extern void ADC_StartConversation(void);
extern uint8 ADC_ReadData(uint16 *Data);
extern uint8 ADC_CalibProcess(void);

#endif /* INC_ADC_H_ */

/*
 * ADC.h
 *
 *  Created on: 2021. febr. 15.
 *      Author: Benjamin
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "types.h"

typedef enum
{
	ADCTrigMode_Sw,
	ADCTrigMode_FallingEdge,
	ADCTrigMode_RisingEdge,
	ADCTrigMode_FallingAndRisingEdge,
} dtADCTrigMode;

typedef struct
{
	/* auto power relation mode, 0: on, 1 off (always powered) */
	uint32 AutoOff		:1;

	/* 1: next conversation start only after reading the previous result */
	uint32 WaitMode		:1;

	/* 0: single conversation mode; 1: continuous mode */
	uint32 ContMode		:1;

	/* 0: old result is kept if overran, 1: new result is kept if overran */
	uint32 OverRun		:1;

	uint32 LeftAlign	:1;

	/* 0b00: 12 bits
	 * 0b01: 10 bits
	 * 0b10: 8 bits
	 * 0b11: 6 bits
	 */
	uint32 Resolution	:2;

	uint32 ClkMode		:2;
	uint32 OVSEn		:1;
	uint32 OVS			:3;
	uint32 OVSShift		:3;
	uint32 SMP1			:3;
	uint32 SMP2			:3;
	uint32 ClkDiv		:4;
	uint32 Interrupt	:2;
	uint32 ExtTrigger	:3;
	uint32 ExtEn        :1;
	uint32 DmaEn        :1;
	uint32 DmaCircMode  :1;
} dtAdcConfig;

typedef struct
{
	uint8 dmaCircMode :1;
	uint8 dmaEnable :1;
} dtDmaSettings;

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

typedef enum
{
	AdcEnabled,
	AdcDisabled,
} dtAdcState;

typedef enum
{
	AdcSwTrig,
	AdcRisingEdgeTrig,
	AdcFallingEdgeTrig,
	AdcBothEdgeTrig,
} dtAdcExtTrigMode;

extern void ADC_Init(dtAdcConfig Config);
extern void ADC_DmaSet(dtDmaSettings setting);
extern void ADC_SetChConfig(dtAdcCh Ch, dtAdcSmp Smp);
extern uint8 ADC_CheckChConfig(void);
extern void ADC_StartConversation(void);
extern void ADC_StopConversion(void);
extern uint8 ADC_ReadData(uint16 *Data);
extern uint8 ADC_CalibProcess(void);
extern void ADC_SetDataHandler(void (*Handler)(uint16));
extern void ADC_SetSequence(uint8 Order, dtAdcCh Ch);
extern void ADC_ConfSequence(void);
extern uint8 ADC_IsAdcReady(void);
extern void ADC_Enable(void);
extern void ADC_Disable(void);
extern void ADC_SetExtTrigMode(dtAdcExtTrigMode TrigMode);
extern uint8 ADC_IsSeqComplete(void);
extern uint8 ADC_IsAdcStopped(void);
extern uint32* ADC_DataPtr(void);

#endif /* INC_ADC_H_ */

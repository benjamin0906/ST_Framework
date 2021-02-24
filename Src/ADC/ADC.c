/*
 * ADC.c
 *
 *  Created on: 2021. febr. 15.
 *      Author: Benjamin
 */

#include "ADC_Types.h"
#include "ADC.h"

static dtADC *const ADC = (dtADC*)(0x40012400);

void ADC_Init(dtAdcConfig Config);
void ADC_SetChConfig(dtAdcCh Ch, dtAdcSmp Smp);
uint8 ADC_CheckChConfig(void);
void ADC_StartConversation(void);
uint8 ADC_ReadData(uint16 *Data);
uint8 ADC_CalibProcess(void);

void ADC_Init(dtAdcConfig Config)
{
	ADC->CR.Word = 0;

	dtADC_CR TempCr = {.Word = 0};
	dtADC_CFGR1 TempCfgr1 = {.Word = 0};
	dtADC_CFGR2 TempCfgr2 = {.Word = 0};
	dtADC_SMPR TempSmpr = {.Word = 0};
	dtADC_CHSELR TempChselr = {.Word = 0};
	dtADC_CCR TempCcr = {.Word = 0x400000};

	TempCr.Fields.ADVREGEN = 1;
	TempCr.Fields.ADEN = 1;

	TempCfgr1.Fields.AUTOFF = Config.AutoOff;
	TempCfgr1.Fields.WAIT = Config.WaitMode;
	TempCfgr1.Fields.CONT = Config.ContMode;
	TempCfgr1.Fields.OVRMOD = Config.OverRun;
	TempCfgr1.Fields.ALIGN = Config.LeftAlign;
	TempCfgr1.Fields.RES = Config.Resolution;

	TempCfgr2.Fields.CKMODE = Config.ClkMode;
	TempCfgr2.Fields.OVSR = Config.OVS;
	TempCfgr2.Fields.OVSS = Config.OVSShift;
	TempCfgr2.Fields.OVSE = Config.OVSEn;
	TempCfgr2.Fields.TOVS = 0;

	TempSmpr.Fields.SMP1 = Config.SMP1;
	TempSmpr.Fields.SMP2 = Config.SMP2;

	ADC->ISR.Fields.ADRDY = 1;

	if(Config.ClkMode == 0)
	{
		TempCcr.Fields.PRESC = Config.ClkDiv;
	}
	TempCcr.Fields.VREFEN = 1;

	ADC->CFGR1 = TempCfgr1;
	ADC->CFGR2 = TempCfgr2;
	ADC->SMPR = TempSmpr;
	ADC->CHSELR = TempChselr;
	ADC->CR = TempCr;
	ADC->CCR = TempCcr;

	while(ADC->ISR.Fields.ADRDY == 0);
}

void ADC_SetChConfig(dtAdcCh Ch, dtAdcSmp Smp)
{
	dtADC_SMPR TempSmpr = ADC->SMPR;
	dtADC_CHSELR TempChselr = ADC->CHSELR;

	TempSmpr.Fields.SMPSEL = 0;
	TempSmpr.Word |= 1<<(Ch+8);

	TempChselr.Word = 1<<Ch;

	ADC->SMPR = TempSmpr;
	ADC->CHSELR = TempChselr;
}

/* Checks if the channel config has been written successfully */
uint8 ADC_CheckChConfig(void)
{
	uint8 ret = ADC->ISR.Fields.CCRDY;
	if(ret != 0) ADC->ISR.Fields.CCRDY = 1;
	return ret;
}

void ADC_StartConversation(void)
{
	ADC->CR.Fields.ADSTART = 1;
}

uint8 ADC_ReadData(uint16 *Data)
{
	uint8 ret = 0;
	if(ADC->ISR.Fields.EOC != 0)
	{
		if(Data != 0) *Data = ADC->DR.Fields.Data;
		ADC->ISR.Fields.EOC = 1;
		ret = 1;
	}
	return ret;
}

uint8 ADC_CalibProcess(void)
{
	uint8 ret = 0;
	if((ADC->CR.Fields.ADEN == 1) || (ADC->CR.Fields.ADVREGEN == 0))
	{
		/* ADC is not yet ready for calibration */
		dtADC_CR Temp = ADC->CR;
		Temp.Fields.ADDIS = 1;
		Temp.Fields.ADVREGEN = 1;
		ADC->CR = Temp;
	}
	else if((ADC->ISR.Fields.EOCAL == 0) && (ADC->CR.Fields.ADCAL == 0))
	{
		/* Calibration is not running and has not yet been done */
		dtADC_CR Temp = ADC->CR;
		Temp.Fields.ADCAL = 1;
		ADC->CR = Temp;
	}
	else if(ADC->ISR.Fields.EOCAL != 0)
	{
		/* Calibration is done, clear the flag*/
		dtADC_ISR TempISR = {.Word = 0};
		TempISR.Fields.EOCAL = 1;
		ADC->ISR = TempISR;

		dtADC_CR Temp = ADC->CR;
		Temp.Fields.ADEN = 1;
		Temp.Fields.ADVREGEN = 1;
		ADC->CR = Temp;

		ret = 1;
	}
	return ret;

}

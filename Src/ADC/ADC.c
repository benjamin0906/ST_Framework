/*
 * ADC.c
 *
 *  Created on: 2021. febr. 15.
 *      Author: Benjamin
 */

#include "ADC_Types.h"
#include "ADC.h"

static dtADC *const ADC = (dtADC*)(0x40012400);

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
	TempCfgr2.Fields.OVSR = Config.OverSample;
	TempCfgr2.Fields.TOVS = 0;
	TempCfgr2.Fields.OVSE = 1;
	TempSmpr.Fields.SMP1 = Config.SMP1;
	TempSmpr.Fields.SMP2 = Config.SMP2;
	TempSmpr.Fields.SMPSEL = Config.SMPSEL;
	TempChselr.ModeZero_Fields.CHSEL = Config.CHSEL;

	ADC->ISR.Fields.ADRDY = 1;

	ADC->CFGR1 = TempCfgr1;
	ADC->CFGR2 = TempCfgr2;
	ADC->SMPR = TempSmpr;
	ADC->CHSELR = TempChselr;
	ADC->CR = TempCr;
	ADC->CCR = TempCcr;

	while(ADC->ISR.Fields.ADRDY == 0);

	while(1)
	{
		ADC->CR.Fields.ADSTART = 1;
		while(ADC->ISR.Fields.EOC == 0);
		ADC->ISR.Fields.EOC = 1;
	}

}

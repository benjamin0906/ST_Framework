/*
 * ADC.c
 *
 *  Created on: 2021. febr. 15.
 *      Author: Benjamin
 */

#include "ADC_Types.h"
#include "ADC.h"
#include "NVIC.h"
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
static dtADC *const ADC = (dtADC*)(0x40012400);
static void (*DataHandler)(uint16);

#define CLEAR_CCRDY() \
	do \
	{\
		dtADC_ISR tIsr = {.Word = 0};\
		tIsr.Fields.CCRDY = 1;\
		ADC->ISR = tIsr;\
	}\
	while(0);

void ADC_Init(dtAdcConfig Config);
void ADC_SetChConfig(dtAdcCh Ch, dtAdcSmp Smp);
uint8 ADC_CheckChConfig(void);
void ADC_StartConversation(void);
uint8 ADC_ReadData(uint16 *Data);
uint8 ADC_CalibProcess(void);
void ADC_SetDataHandler(void (*Handler)(uint16));
void ADC_SetSequence(uint8 Order, dtAdcCh Ch);
void ADC_ConfSequence(void);
uint8 ADC_IsSeqComplete(void);

void ADC_Init(dtAdcConfig Config)
{
	ADC->CR.Word = 0;

	dtADC_CR TempCr = {.Word = 0};
	dtADC_CFGR1 TempCfgr1 = {.Word = 0};
	dtADC_CFGR2 TempCfgr2 = {.Word = 0};
	dtADC_SMPR TempSmpr = {.Word = 0};
	dtADC_CHSELR TempChselr = {.Word = 0};
	dtADC_CCR TempCcr = {.Word = 0x400000};
	dtADC_IER TempIER = {.Word = 0};

	TempCr.Fields.ADVREGEN = 1;
	TempCr.Fields.ADEN = 1;

	TempCfgr1.Fields.AUTOFF = Config.AutoOff;
	TempCfgr1.Fields.WAIT = Config.WaitMode;
	TempCfgr1.Fields.CONT = Config.ContMode;
	TempCfgr1.Fields.OVRMOD = Config.OverRun;
	TempCfgr1.Fields.ALIGN = Config.LeftAlign;
	TempCfgr1.Fields.RES = Config.Resolution;
	TempCfgr1.Fields.EXTSEL = Config.ExtTrigger;

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

	/* If interrupt is used, the SW shall set the corresponding bits in the interrupt enable register
	 * and shall enable the ADC interrupt */
	if(Config.Interrupt != 0)
	{
		TempIER.Fields.CCRDYIE = Config.Interrupt&0x1;
		TempIER.Fields.EOCIE = (Config.Interrupt>>1)&0x1;
		NVIC_EnableIRQ(IRQ_ADC);
	}
	CLEAR_CCRDY();
	ADC->IER = TempIER;
	ADC->CFGR1 = TempCfgr1;
	ADC->CFGR2 = TempCfgr2;
	ADC->SMPR = TempSmpr;
	ADC->CHSELR = TempChselr;
	ADC->CR = TempCr;
	ADC->CCR = TempCcr;
}

dtAdcState ADC_IsAdcReady(void)
{
	if((ADC->CR.Fields.ADDIS == 0)  && (ADC->CR.Fields.ADEN != 0) && (ADC->ISR.Fields.ADRDY != 0)) return AdcEnabled;
	return AdcDisabled;
}

void ADC_Enable(void)
{
	dtADC_CR TempCr = ADC->CR;
	TempCr.Fields.ADEN = 1;
	ADC->CR = TempCr;
}

void ADC_Disable(void)
{
	/* First clearing the ADCRDY flag, then set the disable flag */
	dtADC_CR TempCr = ADC->CR;
	dtADC_ISR TempIsr = ADC->ISR;
	TempIsr.Fields.ADRDY = 1;
	TempCr.Fields.ADDIS = 1;
	ADC->ISR = TempIsr;
	ADC->CR = TempCr;
}

/* @param Ch:
 *  */
void ADC_SetChConfig(dtAdcCh Ch, dtAdcSmp Smp)
{
	dtADC_SMPR TempSmpr = ADC->SMPR;
	dtADC_CHSELR TempChselr = ADC->CHSELR;

	CLEAR_CCRDY();

	TempSmpr.Fields.SMPSEL |= (Smp)<<(Ch);

	TempChselr.ModeZero_Fields.CHSEL |= 1<<Ch;

	ADC->SMPR = TempSmpr;
	ADC->CHSELR = TempChselr;
	while(ADC->ISR.Fields.CCRDY != 1);
}

void ADC_SetSequence(uint8 Order, dtAdcCh Ch)
{
	ADC->ISR.Word |= 0x2000;
	dtADC_CHSELR TempChselr = ADC->CHSELR;
	TempChselr.Word |= Ch<<(Order*4);
	ADC->CHSELR = TempChselr;
}
void ADC_ConfSequence(void)
{
	dtADC_CFGR1 TempCfgr1 = ADC->CFGR1;
	TempCfgr1.Fields.CHSELRMOD = 1;
	ADC->CFGR1 = TempCfgr1;
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
	dtADC_CR TempCr = ADC->CR;
	dtADC_ISR tIsr = {.Word = 0};
	tIsr.Fields.EOC = 1;
	tIsr.Fields.EOS = 1;
	TempCr.Fields.ADSTART = 1;

	ADC->ISR = tIsr;
	ADC->CR = TempCr;
}

void ADC_StopConversion(void)
{
	dtADC_CR TempCr = ADC->CR;
	TempCr.Fields.ADSTP = 1;
	ADC->CR = TempCr;
}

uint8 ADC_IsAdcStopped(void)
{
	return (ADC->CR.Fields.ADSTART == 0);
}

void ADC_SetExtTrigMode(dtAdcExtTrigMode TrigMode)
{
	dtADC_CFGR1 TempCfgr1 = ADC->CFGR1;
	TempCfgr1.Fields.EXTEN = TrigMode;
	ADC->CFGR1 = TempCfgr1;
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
		if(ADC->ISR.Fields.EOCAL == 0)
		{
			/* ADC is not yet ready for calibration */
			dtADC_CR Temp = ADC->CR;
			Temp.Fields.ADDIS = 1;
			Temp.Fields.ADVREGEN = 1;
			ADC->CR = Temp;

			/* Clear ADC ready flag */
			ADC->ISR.Word |= 1;
		}
		else if(ADC->ISR.Fields.ADRDY != 0)
		{
			/* Calibration is done, ADC has been enabled and it is ready to operate */
			dtADC_ISR TempISR = {.Word = 0};
			TempISR.Fields.EOCAL = 1;
			ADC->ISR = TempISR;
			ret = 1;
		}
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
		/* Calibration is done, enable ADC but waiting is needed until ADC is ready */
		dtADC_CR Temp = ADC->CR;
		Temp.Fields.ADEN = 1;
		Temp.Fields.ADVREGEN = 0;
		ADC->CR = Temp;
	}
	return ret;

}

uint8 ADC_IsSeqComplete(void)
{
	return ADC->ISR.Fields.EOS;
}

void ADC_SetDataHandler(void (*Handler)(uint16))
{
	DataHandler = Handler;
}
#if defined(MCU_G070)
void ADC_IRQHandler(void)
#else
void ADC_COMP_IRQHandler(void)
#endif
{
	dtADC_ISR ClearFlag = {.Word = 0};
	if(ADC->ISR.Fields.CCRDY != 0)
	{
		/* Channel configuration is ready, conversion is needed */
		ADC->CR.Fields.ADSTART = 1;
		ClearFlag.Fields.CCRDY = 1;
	}
	else if(ADC->ISR.Fields.EOC != 0)
	{
		/* Conversion is ready */
		uint16 Data = ADC->DR.Fields.Data;
		if(DataHandler != 0) DataHandler(Data);
		//ClearFlag.Fields.EOC = 1;
	}

	/* Clearing the flag which caused the interrupt */
	ADC->ISR = ClearFlag;
}
#else
#warning "NO CPU IS DEFINED"
#endif

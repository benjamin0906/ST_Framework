/*
 * ADC.c
 *
 *  Created on: 2021. febr. 15.
 *      Author: Benjamin
 */

#include "ADC.h"
#include "NVIC.h"
#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415)
#include "ADC_Types.h"
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
void ADC_DmaSet(dtDmaSettings setting);
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
	TempCfgr1.Fields.EXTEN = Config.ExtEn;
	TempCfgr1.Fields.DMACFG = Config.DmaCircMode;
	TempCfgr1.Fields.DMAEN = Config.DmaEn;

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

void ADC_DmaSet(dtDmaSettings setting)
{
	dtADC_CFGR1 TempCfgr1 = ADC->CFGR1;
	dtADC_CR TempCr = ADC->CR;

	/* Stopping the ADC to set the DMA bits */
	TempCr.Fields.ADSTP = 1;
	ADC->CR = TempCr;
	while(ADC->CR.Fields.ADSTART != 0);

	TempCfgr1.Fields.DMACFG = setting.dmaCircMode;
	TempCfgr1.Fields.DMAEN = setting.dmaEnable;
	ADC->CFGR1 = TempCfgr1;
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

uint32* ADC_DataPtr(void)
{
	return &ADC->DR.Word;
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
#elif defined(STM32L4)

#include "RegDefs/ADC_reg.h"
#include "GPIO.h"

static volatile dtADC *const ADC = MODULE_ADC;
static uint16 *Results[16];
static uint8 ResultIndex;

void ADC_Init(const dtAdcConfig *const Config)
{
    uint16 i = 0;
    dtADC_CR tCR = ADC->ADC1.CR;
    dtADC_CFGR tCFGR = ADC->ADC1.CFGR;
    dtADC_SQR1 tSQR1 = ADC->ADC1.SQR1;
    dtADC_SQR2 tSQR2 = ADC->ADC1.SQR2;
    dtADC_SQR3 tSQR3 = ADC->ADC1.SQR3;
    dtADC_SQR4 tSQR4 = ADC->ADC1.SQR4;
    dtADC_SMPR1 tSMPR1 = {.U = 0};
    dtADC_SMPR2 tSMPR2 = {.U = 0};
    dtADC_IER tIER = {.U = 0};
    dtADC_CCR tCCR = {.U = 0};

    /* Clock setting */
    tCCR.B.PRESC = Config->Prescaler;
    ADC->COMMON.CCR = tCCR;

    /* Calibration procedure */
    tCR.B.ADEN = 0;
    tCR.B.ADCALDIF = 0;
    tCR.B.DEEPPWD = 0;
    ADC->ADC1.CR = tCR;
    tCR.B.ADVREGEN = 1;
    ADC->ADC1.CR = tCR;
    while(i < 50000) i++;
    tCR.B.ADCAL = 1;
    ADC->ADC1.CR = tCR;
    do
    {
        tCR = ADC->ADC1.CR;
    } while(tCR.B.ADCAL != 0);

    /* ADC module initialization */
    tCFGR.B.CONT = Config->Continuos;
    tCFGR.B.OVRMOD = Config->Overrun;
    tCFGR.B.EXTEN = Config->TriggerMode;
    tCFGR.B.EXTSEL = Config->ExtTrigEvent;
    tCFGR.B.ALIGN = Config->LeftAlignment;
    tCFGR.B.RES = Config->Resolution;

    /* ADC sequence initialization */
    tSQR1.U = 0;
    tSQR2.U = 0;
    tSQR3.U = 0;
    tSQR4.U = 0;
    int8 chNum = 0;
    for(i = 0; i < 16; i++)
    {
        if(Config->Sequence[i].Result != 0)
        {
            /* Channel IDs */
            if(chNum < 4)
            {
                tSQR1.U |= (Config->Sequence[i].ChannelNum << (6 + 6 * chNum));
            }
            else if(chNum < 9)
            {
                tSQR2.U |= (Config->Sequence[i].ChannelNum << (6 * (chNum - 4)));
            }
            else if(chNum < 14)
            {
                tSQR3.U |= (Config->Sequence[i].ChannelNum << (6 * (chNum - 9)));
            }
            else
            {
                tSQR2.U |= (Config->Sequence[i].ChannelNum << (6 * (chNum - 14)));
            }

            /* Sample times */
            if(chNum < 10)
            {
                tSMPR1.U |= (Config->Sequence[i].SamplingTime << (3 * chNum));
            }
            else
            {
                tSMPR2.U |= (Config->Sequence[i].SamplingTime << (3 * (chNum - 10)));
            }

            /* Saving result pointer */
            Results[chNum] = Config->Sequence[i].Result;

            chNum++;
        }
    }
    tSQR1.B.L = chNum - 1;

    ADC->ADC1.ISR.U = 0xFFFFFFFF; //Clearing all of the pending flags
    tIER.B.EOC = 1;
    tIER.B.EOS = 1;
    ADC->ADC1.IER = tIER;
    NVIC_EnableIRQ(IRQ_ADC);

    tCR.B.ADEN = 1;

    ADC->ADC1.SMPR1 = tSMPR1;
    ADC->ADC1.SMPR2 = tSMPR2;
    ADC->ADC1.SQR1 = tSQR1;
    ADC->ADC1.SQR2 = tSQR2;
    ADC->ADC1.SQR3 = tSQR3;
    ADC->ADC1.SQR4 = tSQR4;
    ADC->ADC1.CFGR = tCFGR;
    ADC->ADC1.CR = tCR;
}

void ADC_Trigger(void)
{
    dtADC_CR tCR = ADC->ADC1.CR;
    if((tCR.B.ADEN != 0) && (tCR.B.ADSTART == 0))
    {
        tCR.B.ADSTART = 1;
        ADC->ADC1.CR = tCR;
    }
}

void ADC1_2_IRQHandler(void)
{
    dtADC_ISR tISR = ADC->ADC1.ISR;
    dtADC_IER tIER = ADC->ADC1.IER;
    if((tISR.U & tIER.U) != 0)
    {
        if(tISR.B.EOC != 0)
        {
            dtADC_DR tDR = ADC->ADC1.DR;
            //*Results[ResultIndex++] = tDR.B.RDATA;
            *Results[ResultIndex] = tDR.B.RDATA;
            ResultIndex++;
        }
        if(tISR.B.EOS != 0)
        {
            ResultIndex = 0;

            GPIO_Set(PortB_3, Clear);
        }
        ADC->ADC1.ISR.U = tISR.U;
    }
}
#else
#warning "NO CPU IS DEFINED"
#endif

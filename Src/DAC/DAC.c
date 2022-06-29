/*
 * DAC.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Benjamin
 */

#include "DAC_Types.h"
#include "DAC.h"

static dtDAC *const DAC = (dtDAC*)0x40007400;

void DAC_Init(dtDACConf Config);

void DAC_Init(dtDACConf Config)
{
    dtDAC_CR TempCR = DAC->CR;
    dtDAC_MCR TempMCR = DAC->MCR;

    if(Config.Channel == Dac_Channel1)
    {
        TempCR.Word &= 0xFFFF0000;
        DAC->CR = TempCR;
        TempCR.Word |= ((uint32)Config.Trigger) << 2;
        TempCR.Word |= ((uint32)Config.Wave) << 6;
        TempCR.Fields.EN1 = 1;
        TempMCR.Fields.MODE1 = Config.Mode;
        DAC->MCR = TempMCR;
        DAC->CR = TempCR;
    }
    else
    {
        TempCR.Word &= 0x0000FFFF;
        DAC->CR = TempCR;
        TempCR.Word |= ((uint32)Config.Trigger) << 18;
        TempCR.Word |= ((uint32)Config.Wave) << 22;
        TempCR.Fields.EN2 = 1;
        TempMCR.Fields.MODE2 = Config.Mode;
        DAC->MCR = TempMCR;
        DAC->CR = TempCR;
    }
}

void DAC_Set(dtDAC_SetCh Ch, uint16 Value)
{
    uint32 *DacOut = &DAC->DHR12R1.Word;
    DacOut += Ch;
    *DacOut = Value;
}

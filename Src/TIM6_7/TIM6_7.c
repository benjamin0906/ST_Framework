/*
 * TIM6_7.c
 *
 *  Created on: Mar 7, 2025
 *      Author: Benjamin
 */

#include "RegDefs/TIM6_7_reg.h"
#include "TIM6_7.h"
#if defined(STM32U0)
static dtTIM6_7 *const TIM6_7 = MODULE_TIM6_7;
#endif

void TIM6_7_Config(dtTIM6_7_ID id, dtTim67Config *const config);
void TIM6_7_Start(dtTIM6_7_ID id);
void TIM6_7_Stop(dtTIM6_7_ID id);

void TIM6_7_Config(dtTIM6_7_ID id, dtTim67Config *const config)
{
    dtTIM6_7_CR1 tCR1 = {.U = 0};
    dtTIM6_7_CR2 tCR2 = {.U = 0};
    dtTIM6_7_PSC tPSC = {.U = 0};
    dtTIM6_7_ARR tARR = {.U = 0};
    dtTIM6_7_DIER tDIER = {.U = 0};

    tCR1.B.ARPE = config->ARPreload;
    tCR1.B.OPM = config->OnePulse;
    tCR1.B.URS = config->UpdateSource;
    tCR1.B.UDIS = config->UpdateDisable;
    tCR1.B.CEN = config->Enable;
    tCR2.B.MMS = config->MasterMode;
    tPSC.B.PSC = config->Prescaler;
    tARR.B.ARR = config->AutoReload;

    tDIER.B.UDE = config->DmaTrig;
    tDIER.B.UIE = config->IsrGenEn;

    TIM6_7->TIM6_7[id].CR1.U = 0;
    TIM6_7->TIM6_7[id].DIER = tDIER;
    TIM6_7->TIM6_7[id].ARR = tARR;
    TIM6_7->TIM6_7[id].PSC = tPSC;
    TIM6_7->TIM6_7[id].CR2 = tCR2;
    TIM6_7->TIM6_7[id].CR1 = tCR1;

}

void TIM6_7_Start(dtTIM6_7_ID id)
{
    dtTIM6_7_CR1 tCR1 = TIM6_7->TIM6_7[id].CR1;
    tCR1.B.CEN = 1;
    TIM6_7->TIM6_7[id].CNT.U = 0;
    TIM6_7->TIM6_7[id].CR1 = tCR1;
}

void TIM6_7_Stop(dtTIM6_7_ID id)
{
    dtTIM6_7_CR1 tCR1 = TIM6_7->TIM6_7[id].CR1;
    tCR1.B.CEN = 0;
    TIM6_7->TIM6_7[id].CR1 = tCR1;
}

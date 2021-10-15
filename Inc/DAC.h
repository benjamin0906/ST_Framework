/*
 * DAC.h
 *
 *  Created on: 2021. okt. 15.
 *      Author: Benjamin
 */

#ifndef INC_DAC_H_
#define INC_DAC_H_

#include "types.h"

enum eTrigger
{
    Dac_Trigger_Disabled    = 0,
    Dac_Trigger_TIM6        = 0x01,
    Dac_Trigger_TIM8        = 0x03,
    Dac_Trigger_TIM7        = 0x11,
    Dac_Trigger_TIM5        = 0x13,
    Dac_Trigger_TIM2        = 0x21,
    Dac_Trigger_TIM4        = 0x23,
    Dac_Trigger_EXTI9       = 0x31,
    Dac_Trigger_Sw          = 0x33,
};

enum eWave
{
    Dac_Wave_Disabled   = 0,
    Dac_Wave_Noise      = 1,
    Dac_Wave_Triangle   = 2,
};

enum eChannel
{
    Dac_Channel1,
    Dac_Channel2,
};

typedef struct
{
    uint16 Channel  :1;
    uint16 Trigger  :4;
    uint16 Wave     :2;
    uint16 Mode     :3;
} dtDACConf;

extern void DAC_Init(dtDACConf Config);

#endif /* INC_DAC_H_ */

/*
 * GPIO_C0.h
 *
 *  Created on: Sep 4, 2026
 *      Author: GitHub Copilot
 */

#ifndef INC_GPIO_C0_H_
#define INC_GPIO_C0_H_

typedef enum
{

    PortA_0 = 0,
    PortA_1,
    PortA_2,
    PortA_3,
    PortA_4,
    PortA_5,
    PortA_6,
    PortA_7,
    PortA_8,
    PortA_9,
    PortA_10,
    PortA_11,
    PortA_12,
    PortA_13,
    PortA_14,
    PortA_15,

    PortB_0 = 0x10,
    PortB_1,
    PortB_2,
    PortB_3,
    PortB_4,
    PortB_5,
    PortB_6,
    PortB_7,
    PortB_8,
    PortB_9,
    PortB_10,
    PortB_11,
    PortB_12,
    PortB_13,
    PortB_14,
    PortB_15,

    PortC_0 = 0x20,
    PortC_1,
    PortC_2,
    PortC_3,
    PortC_4,
    PortC_5,
    PortC_6,
    PortC_7,
    PortC_8,
    PortC_9,
    PortC_10,
    PortC_11,
    PortC_12,
    PortC_13,
    PortC_14,
    PortC_15,

    PortD_0 = 0x30,
    PortD_1,
    PortD_2,
    PortD_3,
    PortD_4,
    PortD_5,
    PortD_6,
    PortD_7,
    PortD_8,
    PortD_9,
    PortD_10,
    PortD_11,
    PortD_12,
    PortD_13,
    PortD_14,
    PortD_15,

    PortF_0 = 0x50,
    PortF_1,
    PortF_2,
    PortF_3,
    PortF_4,
    PortF_5,
    PortF_6,
    PortF_7,
    PortF_8,
    PortF_9,
    PortF_10,
    PortF_11,
    PortF_12,
    PortF_13,
    PortF_14,
    PortF_15
} dtGPIOs_C0;

#endif /* INC_GPIO_C0_H_ */
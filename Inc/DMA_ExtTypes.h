/*
 * DMA_ExtTypes.h
 *
 *  Created on: 2022. jún. 28.
 *      Author: Benjamin
 */

#ifndef SRC_DMA_DMA_EXTTYPES_H_
#define SRC_DMA_DMA_EXTTYPES_H_

#include "types.h"

typedef union
{
    struct
    {
        uint32 EN       :1;
        uint32 DMEIE    :1;
        uint32 TEIE     :1;
        uint32 HTIE     :1;
        uint32 TCIE     :1;
        uint32 PFCTRL   :1;
        uint32 DIR      :2;
        uint32 CIRC     :1;
        uint32 PINC     :1;
        uint32 MINC     :1;
        uint32 PSIZE    :2;
        uint32 MSIZE    :2;
        uint32 PINCOS   :1;
        uint32 PL       :2;
        uint32 DBM      :1;
        uint32 CT       :1;
        uint32          :1;
        uint32 PBURST   :2;
        uint32 MBURST   :2;
        uint32 CHSEL    :3;
    } Field;
    uint32 Word;
} dtDMA_S0CR;

#endif /* SRC_DMA_DMA_EXTTYPES_H_ */

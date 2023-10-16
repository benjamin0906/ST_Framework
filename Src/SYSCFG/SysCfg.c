/*
 * SysCfg.c
 *
 *  Created on: 2023. febr. 5.
 *      Author: Benjamin
 */
#include "SysCfg_Types.h"
#include "SysCfg.h"

#if defined(MCU_L433)
static dtSysCfg* const SysCfg = (dtSysCfg*)(0x40013800);

void ISysCfg_SetExti(uint8 ExtiNum, dtSysCfgExtiConf ExtiConf);

void ISysCfg_SetExti(uint8 ExtiNum, dtSysCfgExtiConf ExtiConf)
{
    dtSysCfg_EXTICRx *tPtr= &SysCfg->EXTICR1;
    tPtr += ExtiNum >> 2;
    switch(ExtiNum % 4)
    {
        case 0:
            tPtr->EXTIx0 = ExtiConf;
            break;
        case 1:
            tPtr->EXTIx1 = ExtiConf;
            break;
        case 2:
            tPtr->EXTIx2 = ExtiConf;
            break;
        case 3:
            tPtr->EXTIx3 = ExtiConf;
            break;
    }
}
#endif

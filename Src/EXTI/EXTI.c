/*
 * EXTI.c
 *
 *  Created on: 2021. ápr. 3.
 *      Author: Benjamin
 */

#include "EXTI_Types.h"
#include "EXTI.h"

#if defined(MCU_G070)
static dtEXTI *const EXTI = (dtEXTI*)0x40021800;

void EXTI_LineSet(dtEXTILines Line, dtEXTIEdge EdgeType, dtEXTIPort PortType, dtEXTIMask ExtiMasks);
uint8 EXTI_RisingPending(dtEXTILines Line);
uint8 EXTI_FallingPending(dtEXTILines Line);
void EXTI_ClearPending(dtEXTILines Line);

void EXTI_LineSet(dtEXTILines Line, dtEXTIEdge EdgeType, dtEXTIPort PortType, dtEXTIMask ExtiMasks)
{
	if((Line != 20) && (Line != 22) && (Line != 24))
	{
		if(Line <= EXTI_COMP2_Out)
		{
			uint32 Mask = 1 << Line;
			Mask = ~Mask;

			/* Zeroing the line by default, it will set only if the EdgeType is not EXTI_NoEdge */
			EXTI->GenConfEvents.RSTR.Fields.Lines &= Mask;
			EXTI->GenConfEvents.FTSR.Fields.Lines &= Mask;
			Mask = ~Mask;
			if((EdgeType == EXTI_RisingEdge) || (EdgeType == EXTI_BothEdge)) EXTI->GenConfEvents.RSTR.Fields.Lines |= Mask;
			if((EdgeType == EXTI_FallingEdge) || (EdgeType == EXTI_BothEdge)) EXTI->GenConfEvents.FTSR.Fields.Lines |= Mask;
		}

		/* Set the used port to the GPIO EXTI line if the Line is one of them */
		if(Line <= EXTI_Exti15) EXTI->ExtiCr[Line] = PortType;

		if(Line <= EXTI_LSE_CSS)
		{
			uint32 Mask = 1 << Line;
			Mask = ~Mask;
			EXTI->EMR1 &= Mask;
			EXTI->IMR1 &= Mask;
			Mask = ~Mask;
			if((ExtiMasks == EXTI_EventMask) || (ExtiMasks == EXTI_BothMask))
				{
				uint32 *a = &EXTI->EMR1;
				*a |= Mask;
				EXTI->EMR1 |= Mask;
				}
			if((ExtiMasks == EXTI_InterruptMask) || (ExtiMasks == EXTI_BothMask)) EXTI->IMR1 |= Mask;
		}
		else
		{
			uint32 Mask = 1 << (Line-32);
			Mask = ~Mask;
			EXTI->EMR2 &= Mask;
			EXTI->IMR2 &= Mask;
			Mask = ~Mask;
			if((ExtiMasks == EXTI_EventMask) || (ExtiMasks == EXTI_BothMask)) EXTI->EMR2 |= Mask;
			if((ExtiMasks == EXTI_InterruptMask) || (ExtiMasks == EXTI_BothMask)) EXTI->IMR2 |= Mask;
		}
	}
}


/* The pending registers are only set if not only the event but the interrupt generation of the line is set.
 * So if only the event generation has been set the pending registers will be empty */
uint8 EXTI_RisingPending(dtEXTILines Line)
{
	return (EXTI->GenConfEvents.RPR.Word & (1<<Line)) != 0;
}

/* The pending registers are only set if not only the event but the interrupt generation of the line is set.
 * So if only the event generation has been set the pending registers will be empty */
uint8 EXTI_FallingPending(dtEXTILines Line)
{
	return (EXTI->GenConfEvents.FPR.Word & (1<<Line)) != 0;
}

/* Clears both rising and falling flag */
void EXTI_ClearPending(dtEXTILines Line)
{
	EXTI->GenConfEvents.FPR.Word |= (1 << Line);
	EXTI->GenConfEvents.RPR.Word |= (1 << Line);
}

#elif defined(MCU_F446)

#endif

static dtEXTI *const EXTI = (dtEXTI*) {0x40013C00};
static void (*IrqHandlers[23])(void);

#define CLEAR_PENDING(line) EXTI->PR |= 1 << line

void IExti_Config(uint8 ExtiLine, dtExtiConfig Config, void (*IrqHandler)(void));
void IExti_ClearPending(uint8 ExtiLine);

void IExti_Config(uint8 ExtiLine, dtExtiConfig Config, void (*IrqHandler)(void))
{
    EXTI->IMR &= ~(1<<ExtiLine);
    EXTI->EMR &= ~(1<<ExtiLine);
    EXTI->RTSR &= ~(1<<ExtiLine);
    EXTI->FTSR &= ~(1<<ExtiLine);

    EXTI->IMR &= ~(Config.InterruptMask<<ExtiLine);
    EXTI->EMR &= ~(Config.EventMask<<ExtiLine);
    EXTI->RTSR &= ~(Config.RisingEdgeTrigger<<ExtiLine);
    EXTI->FTSR &= ~(Config.FallingEdgeTrigger<<ExtiLine);

    if(IrqHandler != 0)
    {
        IrqHandlers[ExtiLine] = IrqHandler;
    }

    EXTI->PR |= 1 << ExtiLine;
}

void IExti_ClearPending(uint8 ExtiLine)
{
    CLEAR_PENDING(ExtiLine);
}

void EXTI0_IRQHandler(void)
{
    IrqHandlers[0]();
    CLEAR_PENDING(0);
}

void EXTI1_IRQHandler(void)
{
    IrqHandlers[1]();
    CLEAR_PENDING(1);
}

void EXTI2_IRQHandler(void)
{
    IrqHandlers[2]();
    CLEAR_PENDING(2);
}

void EXTI3_IRQHandler(void)
{
    IrqHandlers[3]();
    CLEAR_PENDING(3);
}

void EXTI4_IRQHandler(void)
{
    IrqHandlers[4]();
    CLEAR_PENDING(4);
}

void EXTI9_5_IRQHandler(void)
{

}

void EXTI15_10_IRQHandler(void)
{

}

void PVD_IRQHandler(void)
{

}

void TAMP_STAMP_IRQHandler(void)
{

}

void RTC_WKUP_IRQHandler(void)
{

}


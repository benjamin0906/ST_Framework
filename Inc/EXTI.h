/*
 * EXTI.h
 *
 *  Created on: 2021. ápr. 3.
 *      Author: Benjamin
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#if defined(MCU_G070)
typedef enum
{
	EXTI_Exti0,
	EXTI_Exti1,
	EXTI_Exti2,
	EXTI_Exti3,
	EXTI_Exti4,
	EXTI_Exti5,
	EXTI_Exti6,
	EXTI_Exti7,
	EXTI_Exti8,
	EXTI_Exti9,
	EXTI_Exti10,
	EXTI_Exti11,
	EXTI_Exti12,
	EXTI_Exti13,
	EXTI_Exti14,
	EXTI_Exti15,
	EXTI_PVD_Out,
	EXTI_COMP1_Out,
	EXTI_COMP2_Out,
	EXTI_RTC,
	EXTI_TAMP 			= 21,
	EXTI_I2C1_Wake		= 23,
	EXTI_USART1_Wake 	= 25,
	EXTI_USART2_Wake,
	EXTI_CEC_Wake,
	EXTI_LPUART1_Wake,
	EXTI_LPTIM1,
	EXTI_LPTIM2,
	EXTI_LSE_CSS,
	EXTI_UCPD1_Wake,
	EXTI_UCPD2_Wake,
} dtEXTILines;

typedef enum
{
	EXTI_NoEdge,
	EXTI_RisingEdge,
	EXTI_FallingEdge,
	EXTI_BothEdge,
} dtEXTIEdge;

typedef enum
{
	EXTI_PortA,
	EXTI_PortB,
	EXTI_PortC,
	EXTI_PortD,
	EXTI_PortF	= 0x05,
} dtEXTIPort;

typedef enum
{
	EXTI_NoMask,
	EXTI_EventMask,
	EXTI_InterruptMask,
	EXTI_BothMask,
} dtEXTIMask;

extern void EXTI_LineSet(dtEXTILines Line, dtEXTIEdge EdgeType, dtEXTIPort PortType, dtEXTIMask ExtiMasks);
extern uint8 EXTI_RisingPending(dtEXTILines Line);
extern uint8 EXTI_FallingPending(dtEXTILines Line);
extern void EXTI_ClearPending(dtEXTILines Line);

#endif

#endif /* INC_EXTI_H_ */

/*
 * USART_reg.h
 *
 *  Created on: Mar 10, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_USART_REG_H_
#define INC_REGDEFS_USART_REG_H_

#include "RegDefs/USART_regdef.h"

#if defined(STM32U0)

#define MODULE_USART1 ((dtUSARTx*)0x40013800)
#define MODULE_USART2 ((dtUSARTx*)0x40004400)
#define MODULE_USART3 ((dtUSARTx*)0x40004800)
#define MODULE_USART4 ((dtUSARTx*)0x40004C00)

#endif

#endif /* INC_REGDEFS_USART_REG_H_ */

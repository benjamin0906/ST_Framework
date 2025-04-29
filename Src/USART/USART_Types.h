/*
 * USART_Types.h
 *
 *  Created on: 2020. sep. 8.
 *      Author: BodnarB
 */
 
#ifndef USART_USART_TYPES_H_
#define USART_USART_TYPES_H_

#include "types.h"
#include "config.h"

typedef struct
{
    uint8 *txFifo;
    uint8 TxReadIndex;
    uint8 TxWriteIndex;
    uint8 *rxFifo;
    uint8 RxWriteIndex;
    uint8 RxReadIndex;
} dtUSARTxData;

#define CR1_BIT_TXFNFIE	0x80

#define USART_CR1_SET_BIT(Instance, Bit) 	\
		dtUSART_CR1 Temp = USART[Instance]->CR1;	\
		Temp.U |= Bit;					\
		USART[Instance]->CR1 = Temp;

#define USART_CR1_CLEAR_BIT(Instance, Bit) 	\
		dtUSART_CR1 Temp = USART[Instance]->CR1;	\
		Temp.U &= ~Bit;					\
		USART[Instance]->CR1 = Temp;

#endif /* USART_USART_TYPES_H_ */

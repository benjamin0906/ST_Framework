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

#if defined(USART1_TX_FIFO_SIZE) && defined(USART1_RX_FIFO_SIZE)
typedef struct
{
	uint8 TxFiFo[USART1_TX_FIFO_SIZE+1];
	uint8 TxReadIndex;
	uint8 TxWriteIndex;
	uint8 RxFiFo[USART1_RX_FIFO_SIZE+1];
	uint8 RxWriteIndex;
	uint8 RxReadIndex;
} dtUSART1Data;
#endif

#if defined(USART2_TX_FIFO_SIZE) && defined(USART2_RX_FIFO_SIZE)
typedef struct
{
	uint8 TxFiFo[USART2_TX_FIFO_SIZE+1];
	uint8 TxReadIndex;
	uint8 TxWriteIndex;
	uint8 RxFiFo[USART2_RX_FIFO_SIZE+1];
	uint8 RxWriteIndex;
	uint8 RxReadIndex;
} dtUSART2Data;
#endif

#if defined(USART3_TX_FIFO_SIZE) && defined(USART3_RX_FIFO_SIZE)
typedef struct
{
	uint8 TxFiFo[USART3_TX_FIFO_SIZE+1];
	uint8 TxReadIndex;
	uint8 TxWriteIndex;
	uint8 RxFiFo[USART3_RX_FIFO_SIZE+1];
	uint8 RxWriteIndex;
	uint8 RxReadIndex;
} dtUSART3Data;
#endif

#if defined(USART4_TX_FIFO_SIZE) && defined(USART4_RX_FIFO_SIZE)
typedef struct
{
	uint8 TxFiFo[USART4_TX_FIFO_SIZE+1];
	uint8 TxReadIndex;
	uint8 TxWriteIndex;
	uint8 RxFiFo[USART4_RX_FIFO_SIZE+1];
	uint8 RxWriteIndex;
	uint8 RxReadIndex;
} dtUSART4Data;
#endif

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

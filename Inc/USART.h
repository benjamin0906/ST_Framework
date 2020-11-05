/*
 * USART.h
 *
 *  Created on: Nov 5, 2020
 *      Author: BodnarB
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "types.h"

typedef enum
{
	USART1,
	USART2,
	USART3,
	USART4,
} dtUSARTInstance;

enum eParity
{
	None,
	Even,
	Odd,
};

enum eStopBits
{
	One,
	Half,
	Two,
	OneHalf,
};

typedef struct
{
	uint16	Baud;
	uint8	Parity		:2;
	uint8	StopBits	:2;
} dtUSARTConfig;

extern void USART_Init(dtUSARTInstance Instance, dtUSARTConfig Config);

#endif /* INC_USART_H_ */

/*
 * GPIO.h
 *
 *  Created on: May 1, 2020
 *      Author: Bodnár Benjamin
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "types.h"

#define PORT_A			0
#define PORT_B			1
#define PORT_C			2
#define GPIO_ANALOG		0
#define GPIO_INPUT		1
#define GPIO_OUTPUT		2
#define GPIO_ALT0		3
#define GPIO_ALT1		4
#define GPIO_ALT2		5
#define GPIO_ALT3		6
#define GPIO_ALT4		7
#define GPIO_ALT5		8
#define GPIO_ALT6		9
#define GPIO_ALT7		10
#define GPIO_ALT8		11
#define GPIO_ALT9		12
#define GPIO_ALT10		13
#define GPIO_ALT11		14
#define GPIO_ALT12		15
#define GPIO_ALT13		16
#define GPIO_ALT14		17
#define GPIO_ALT15		18
#define GPIO_OTYPE_OD	1<<5
#define GPIO_OTYPE_PP	2<<5
#define GPIO_OSPEED_LS	1<<7
#define GPIO_OSPEED_MS	2<<7
#define GPIO_OSPEED_HS	3<<7
#define GPIO_OSPEED_VHS	4<<7
#define GPIO_PULL_NO	1<<10
#define GPIO_PULL_U		2<<10
#define GPIO_PULL_D		3<<10
#define GPIO_ASC_0		1<<12
#define GPIO_ASC_1		2<<12
#define GPIO_ASC_2		3<<12
#define GPIO_ASC_3		4<<12
#define GPIO_ASC_4		5<<12
#define GPIO_ASC_5		6<<12
#define GPIO_ASC_6		7<<12
#define GPIO_ASC_7		8<<12
#define GPIO_ASC_8		9<<12
#define GPIO_ASC_9		10<<12
#define GPIO_ASC_10		11<<12
#define GPIO_ASC_11		12<<12
#define GPIO_ASC_12		13<<12
#define GPIO_ASC_13		14<<12
#define GPIO_ASC_14		15<<12
#define GPIO_ASC_15		16<<12

extern void GPIO_Set(uint8 port, uint8 pin, uint32 settings);
extern void GPIO_Write(uint8 port, uint8 pin, uint8 value);
extern uint8 GPIO_Read(uint8 port, uint8 pin);
extern void GPIO_Toggle(uint8 port, uint8 pin);

#endif /* GPIO_GPIO_H_ */

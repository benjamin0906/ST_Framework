/*
 * I2C.c
 *
 *  Created on: 2020. okt. 16.
 *      Author: BodnarB
 */

#include "I2C_Types.h"
#include "I2C.h"

void I2C_Init(dtI2cConfig condig);
void I2C_Start(dtI2cSessionType SessionType, uint8* RegisterAddress, uint8 RegisterLength, uint8* Data, uint8 DataLength);

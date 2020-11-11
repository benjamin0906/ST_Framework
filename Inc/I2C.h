/*
 * I2C.h
 *
 *  Created on: 2020. okt. 16.
 *      Author: BodnarB
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "types.h"

typedef enum
{
	I2C1,
	I2C2,
} dtI2CInstance;

typedef enum
{
	I2C_Write,
	I2C_Read,
} dtI2cSessionType;

typedef struct
{
	uint32	TimingReg;
	uint8	AnalogFilter	:1;
} dtI2cConfig;

typedef enum
{
	Busy,
	Error,
	Done,
} dtI2cSessionResult;

extern void I2C_Init(dtI2CInstance Instance, dtI2cConfig config);
extern void I2C_Start(dtI2cSessionType SessionType, uint8 SlaveAdd, uint8* RegisterAddress, uint8 RegisterLength, uint8* Data, uint8 DataLength);
extern dtI2cSessionResult I2C_Result(void);

#endif /* INC_I2C_H_ */

/*
 * SPI.h
 *
 *  Created on: 11 Jul 2020
 *      Author: Bodnár Benjamin
 */

#ifndef ST_FRAMEWORK_SRC_SPI_SPI_H_
#define ST_FRAMEWORK_SRC_SPI_SPI_H_

#include "types.h"
#include "GPIO.h"

enum
{
	SpiDiv2 = 0,
	SpiDiv4,
	SpiDiv8,
	SpiDiv16,
	SpiDiv32,
	SpiDiv64,
	SpiDiv128,
	SpiDiv256,
} eClockDiv;

enum
{
	Size8Bit	= 0,
	Size16Bit,
} eDataSize;

enum
{
	Msb			= 0,
	Lsb,
} eLsbOrMsb;

typedef enum
{
	SpiIdle,
	SpiInProgress,
} dtSpStatus;

typedef struct
{
	uint32 ClockDiv	:3;
	uint32 DataSize	:1;
	uint32 LsbOrMsb	:1;
	uint32 CPOL		:1;
	uint32 CHPA		:1;
	uint32 Instance	:3;
	dtGPIOs ChipSelectPin;
} dtSpiConf;

extern void SPI_Init(dtSpiConf Config);
extern void SPI_Send(uint8 Instance, uint32 *TxBuff, uint32 *RxBuff, uint32 Length);
extern dtSpStatus SPI_Status(uint8 Instance);

#endif /* ST_FRAMEWORK_SRC_SPI_SPI_H_ */

/*
 * SPI_Types.h
 *
 *  Created on: 2020. júl. 3.
 *      Author: BodnarB
 */

#ifndef SPI_SPI_TYPES_H_
#define SPI_SPI_TYPES_H_

#include "types.h"

typedef union
{
	struct
	{
		uint32 CPHA	:1;
		uint32 CPOL	:1;
		uint32 MSTR	:1;
		uint32 BR	:3;
		uint32 SPE	:1;
		uint32 LSBFIRST	:1;
		uint32 SSI		:1;
		uint32 SSM		:1;
		uint32 RXONLY	:1;
		uint32 DFF		:1;
		uint32 CRCNEXT	:1;
		uint32 CRCEN	:1;
		uint32 BIDIOE	:1;
		uint32 BIDIMODE	:1;
	} Fields;
	uint32 Word;
} dtCR1;

typedef union
{
	struct
	{
		uint32 RXDMAEN	:1;
		uint32 TXDMAEN	:1;
		uint32 SSOE		:1;
		uint32 			:1;
		uint32 FRF		:1;
		uint32 ERRIE	:1;
		uint32 RXNEIE	:1;
		uint32 TXEIE	:1;
	} Fields;
	uint32 Word;
} dtCR2;

typedef union
{
	struct
	{
		uint32 RXNE		:1;
		uint32 TXE		:1;
		uint32 CHSIDE	:1;
		uint32 UDR		:1;
		uint32 CRCERR	:1;
		uint32 MODF		:1;
		uint32 OVR		:1;
		uint32 BSY		:1;
		uint32 FRE		:1;
	} Fields;
	uint32 Word;
} dtSR;


typedef union
{
	struct
	{
		uint32 CHLEN	:1;
		uint32 DATLEN	:1;
		uint32 CKPOL	:1;
		uint32 I2SSTD	:1;
		uint32 			:1;
		uint32 PCMSYNC	:1;
		uint32 I2SCFG	:1;
		uint32 I2SE		:1;
		uint32 I2SMOD	:1;
		uint32 ASTREN	:1;
	} Fields;
	uint32 Word;
} dtI2SCFGR;

typedef union
{
	struct
	{
		uint32 I2SDIV	:8;
		uint32 ODD		:1;
		uint32 MCKOE	:1;
	} Fields;
	uint32 Word;
} dtI2SPR;

typedef struct
{
	dtCR1	CR1;
	dtCR2	CR2;
	dtSR	SR;
	uint16	DR;
	uint16	:16;
	uint16	CRCPOLY;
	uint16	:16;
	uint16	RxCRC;
	uint16	:16;
	uint16	TxCRC;
	uint16	:16;
	dtI2SCFGR	I2SCFGR;
	dtI2SPR	I2SPR;
} dtSPI_I2S;

#endif /* SPI_SPI_TYPES_H_ */

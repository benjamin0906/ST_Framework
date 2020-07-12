/*
 * SPI.c
 *
 *  Created on: 2020. júl. 3.
 *      Author: BodnarB
 */

#include "SPI_Types.h"
#include "SPI.h"

#if defined(MCU_F410) | defined(MCU_F446)
static dtSPI_I2S *const SPI1 = (dtSPI_I2S*)(0x40013000);
#endif
#if defined(MCU_F410) | defined(MCU_F446)
static dtSPI_I2S *const SPI2 = (dtSPI_I2S*)(0x40003800);
#endif
#if defined(MCU_F446)
static dtSPI_I2S *const SPI3 = (dtSPI_I2S*)(0x40003C00);
#endif
#if defined(MCU_F446)
static dtSPI_I2S *const SPI4 = (dtSPI_I2S*)(0x40013400);
#endif
#if defined(MCU_F410)
static dtSPI_I2S *const SPI5 = (dtSPI_I2S*)(0x40015000);
#endif

void SPI_Init(dtSpiConf Config)
{
	dtSPI_I2S *Instance = 0;
	switch(Config.Instance)
	{
	case 1:
		Instance = SPI1;
		break;
	case 2:
		Instance = SPI2;
		break;
	case 3:
		Instance = SPI3;
		break;
	case 4:
		Instance = SPI4;
		break;
#if defined(MCU_F410)
	case 5:
		Instance = SPI5;
		break;
#endif
	}

	dtCR1 Cr1Temp = {.Word = 0};
	dtCR2 Cr2Temp = {.Word = 0};

	Cr1Temp.Fields.BR = Config.ClockDiv;
	Cr1Temp.Fields.LSBFIRST = Config.LsbOrMsb;
	Cr1Temp.Fields.DFF = Config.DataSize;
	Cr1Temp.Fields.CPHA = Config.CHPA;
	Cr1Temp.Fields.CPOL = Config.CPOL;
	Cr1Temp.Fields.MSTR = 1;
	Cr1Temp.Fields.SPE = 1;

	Cr2Temp.Fields.FRF = 1;

	Instance->CR2 = Cr2Temp;
	Instance->CR1 = Cr1Temp;
	Instance->DR = 0x65;
}

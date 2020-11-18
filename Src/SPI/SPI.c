/*
 * SPI.c
 *
 *  Created on: 2020. júl. 3.
 *      Author: BodnarB
 */

#include "SPI_Types.h"

#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071)
static dtSPI_I2S *const SPI1 = (dtSPI_I2S*)(0x40013000);
static dtSpiData SPI1Data;
#endif
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071)
static dtSPI_I2S *const SPI2 = (dtSPI_I2S*)(0x40003800);
static dtSpiData SPI2Data;
#endif
#if defined(MCU_F446) || defined(MCU_L433)
static dtSPI_I2S *const SPI3 = (dtSPI_I2S*)(0x40003C00);
static dtSpiData SPI3Data;
#endif
#if defined(MCU_F446)
static dtSPI_I2S *const SPI4 = (dtSPI_I2S*)(0x40013400);
static dtSpiData SPI4Data;
#endif
#if defined(MCU_F410)
static dtSPI_I2S *const SPI5 = (dtSPI_I2S*)(0x40015000);
static dtSpiData SPI5Data;
#endif

void SPI_Init(dtSpiConf Config);
void SPI_Send(uint8 Instance, uint32 *TxBuff, uint32 *RxBuff, uint32 Length);
dtSpiData* GetDataOfInstance(uint8 instance);
dtSPI_I2S* GetSpiInstance(uint8 instance);

dtSpiData* GetDataOfInstance(uint8 instance)
{
	dtSpiData *ret = 0;
	switch(instance)
	{
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071)
	case 1:
		ret = &SPI1Data;
		break;
#endif
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071)
	case 2:
		ret = &SPI2Data;
		break;
#endif
#if defined(MCU_F446) || defined(MCU_L433)
	case 3:
		ret = &SPI3Data;
		break;
#endif
#if defined(MCU_F446)
	case 4:
		ret = &SPI4Data;
		break;
#endif
#if defined(MCU_F410)
	case 5:
		ret = &SPI5Data;
		break;
#endif
	}
	return ret;
}

dtSPI_I2S* GetSpiInstance(uint8 instance)
{
	dtSPI_I2S *ret = 0;
	switch(instance)
	{
	case 1:
		ret = SPI1;
		break;
	case 2:
		ret = SPI2;
		break;
#if defined(MCU_F446)
	case 3:
		ret = SPI3;
		break;
#endif
#if defined(MCU_F446)
	case 4:
		ret = SPI4;
		break;
#endif
#if defined(MCU_F410)
	case 5:
		ret = SPI5;
		break;
#endif
	}
	return ret;
}

void SPI_Init(dtSpiConf Config)
{
	dtSPI_I2S *Instance = GetSpiInstance(Config.Instance);

	dtCR1 Cr1Temp = {.Word = 0};
	dtCR2 Cr2Temp = {.Word = 0};

	Cr1Temp.Fields.BR = Config.ClockDiv;
	Cr1Temp.Fields.LSBFIRST = Config.LsbOrMsb;
#if defined(MCU_F446)
	Cr1Temp.Fields.DFF = Config.DataSize;
#endif
	Cr1Temp.Fields.CPHA = Config.CHPA;
	Cr1Temp.Fields.CPOL = Config.CPOL;
	Cr1Temp.Fields.MSTR = 1;
	Cr1Temp.Fields.SPE = 1;
	Cr1Temp.Fields.SSM = 1;
	Cr1Temp.Fields.SSI = 1;


	Cr2Temp.Fields.FRF = 0;
	Cr2Temp.Fields.RXNEIE =1;

	Instance->CR2 = Cr2Temp;
	Instance->CR1 = Cr1Temp;

	GetDataOfInstance(Config.Instance)->ChipSelectPin = Config.ChipSelectPin;
	GPIO_Set(GetDataOfInstance(Config.Instance)->ChipSelectPin, Set);
}

void SPI_Send(uint8 Instance, uint32 *TxBuff, uint32 *RxBuff, uint32 Length)
{
	GPIO_Set(GetDataOfInstance(Instance)->ChipSelectPin, Clear);
	dtSpiData *DataInstance = GetDataOfInstance(Instance);
	DataInstance->Status 			= SpiInProgress;
	DataInstance->TransferLength 	= Length;
	DataInstance->TxBuffPointer 	= TxBuff;
	DataInstance->RxBuffPointer 	= RxBuff;
	DataInstance->Indexer			= 0;
	GetSpiInstance(Instance)->DR	= DataInstance->TxBuffPointer[DataInstance->Indexer++]>>16;
}

dtSpStatus SPI_Status(uint8 Instance)
{
	return GetDataOfInstance(Instance)->Status;
}

#if defined(MCU_F410) || defined(MCU_F446) ||  defined(MCU_G071)
void SPI1_IRQHandler(void)
{
	dtSpiData *DataInstance = GetDataOfInstance(1);
	dtSPI_I2S *Instance = GetSpiInstance(1);
	uint32 BuffIndex = DataInstance->Indexer>>1;
	if((DataInstance->Indexer & 1) != 0) DataInstance->RxBuffPointer[BuffIndex] = Instance->DR<<16;
	else DataInstance->RxBuffPointer[BuffIndex-1] |= Instance->DR;
	if(BuffIndex < DataInstance->TransferLength)
	{
		if((DataInstance->Indexer & 1) != 0) Instance->DR = (uint16)DataInstance->TxBuffPointer[BuffIndex];
		else Instance->DR = (uint16)DataInstance->TxBuffPointer[BuffIndex]>>16;
		DataInstance->Indexer++;
	}
	else
	{
		GPIO_Set(GetDataOfInstance(1)->ChipSelectPin, Set);
		GetDataOfInstance(1)->Status = SpiIdle;
	}
}
#endif

#if defined(MCU_F410) | defined(MCU_F446) ||  defined(MCU_G071)
void SPI2_IRQHandler(void)
{

}
#endif

#if defined(MCU_F446)
void SPI3_IRQHandler(void)
{
	dtSpiData *DataInstance = GetDataOfInstance(3);
	dtSPI_I2S *Instance = GetSpiInstance(3);
	uint32 BuffIndex = DataInstance->Indexer>>1;
	if((DataInstance->Indexer & 1) != 0) DataInstance->RxBuffPointer[BuffIndex] = Instance->DR<<16;
	else DataInstance->RxBuffPointer[BuffIndex] |= Instance->DR;
	if(BuffIndex < DataInstance->TransferLength)
	{
		if((DataInstance->Indexer & 1) != 0) Instance->DR = (uint16)DataInstance->TxBuffPointer[BuffIndex];
		else Instance->DR = (uint16)DataInstance->TxBuffPointer[BuffIndex]>>16;
		DataInstance->Indexer++;
	}
	else
	{
		GPIO_Set(GetDataOfInstance(3)->ChipSelectPin, Set);
		GetDataOfInstance(3)->Status = SpiIdle;
	}
}
#endif

#if defined(MCU_F446)
void SPI4_IRQHandler(void)
{

}
#endif

#if defined(MCU_F410)
void SPI5_IRQHandler(void)
{

}
#endif

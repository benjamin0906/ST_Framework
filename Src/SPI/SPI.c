/*
 * SPI.c
 *
 *  Created on: 2020. júl. 3.
 *      Author: BodnarB
 */

#include "SPI_Types.h"
#include "DMA.h"
#include "Utilities.h"
#include "NVIC.h"
#include "config.h"

#if defined(MCU_F446) || defined(MCU_G070) || defined(MCU_F410) || defined(MCU_L433) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
static dtSPI_I2S *const SPI1 = (dtSPI_I2S*)(0x40013000);
static dtSpiData SPI1Data;
#endif
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
static dtSPI_I2S *const SPI2 = (dtSPI_I2S*)(0x40003800);
static dtSpiData SPI2Data;
#endif
#if defined(MCU_F446) || defined(MCU_L433) || defined(MCU_F415) || defined(MCU_L476)
static dtSPI_I2S *const SPI3 = (dtSPI_I2S*)(0x40003C00);
static dtSpiData SPI3Data;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
static dtSPI_I2S *const SPI4 = (dtSPI_I2S*)(0x40013400);
static dtSpiData SPI4Data;
#endif
#if defined(MCU_F410) || defined(MCU_F415)
static dtSPI_I2S *const SPI5 = (dtSPI_I2S*)(0x40015000);
static dtSpiData SPI5Data;
#endif
#if defined(MCU_F415)
static dtSPI_I2S *const SPI6 = (dtSPI_I2S*)(0x40015400);
static dtSpiData SPI6Data;
#endif


#if SPI_USAGE_MODE == DMA_MODE

#if defined(SPI_1) && (SPI_1 == STD_ON)
#if SPI_1_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi1DmaTxBuffer[SPI_1_DMA_TX_BUFFER_SIZE];
#elif SPI_1_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi1DmaTxBuffer[SPI_1_DMA_TX_BUFFER_SIZE];
#elif SPI_1_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi1DmaTxBuffer[SPI_1_DMA_TX_BUFFER_SIZE];
#endif
#if SPI_1_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi1DmaRxBuffer[SPI_1_DMA_RX_BUFFER_SIZE];
#elif SPI_1_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi1DmaRxBuffer[SPI_1_DMA_RX_BUFFER_SIZE];
#elif SPI_1_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi1DmaRxBuffer[SPI_1_DMA_RX_BUFFER_SIZE];
#endif
void SPI1_DmaIrqHandler(uint8 Flags, uint32 NumofData);
#endif

#if defined(SPI_2) && SPI_2 == STD_ON
#if SPI_2_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi2DmaTxBuffer[SPI_2_DMA_TX_BUFFER_SIZE];
#elif SPI_2_TX_DMA_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi2DmaTxBuffer[SPI_2_DMA_TX_BUFFER_SIZE];
#elif SPI_2_TX_DMA_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi2DmaTxBuffer[SPI_2_DMA_TX_BUFFER_SIZE];
#endif
#if SPI_2_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi2DmaRxBuffer[SPI_2_DMA_RX_BUFFER_SIZE];
#elif SPI_2_RX_DMA_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi2DmaRxBuffer[SPI_2_DMA_RX_BUFFER_SIZE];
#elif SPI_2_RX_DMA_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi2DmaRxBuffer[SPI_2_DMA_RX_BUFFER_SIZE];
#endif
void SPI2_DmaIrqHandler(uint8 Flags, uint32 NumofData);
#endif

#if defined(SPI_3) && SPI_3 == STD_ON
#if SPI_3_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi3DmaTxBuffer[SPI_3_DMA_TX_BUFFER_SIZE] = {0x11223344, 0x55667788};
#elif SPI_3_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi3DmaTxBuffer[SPI_3_DMA_TX_BUFFER_SIZE];
#elif SPI_3_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi3DmaTxBuffer[SPI_3_DMA_TX_BUFFER_SIZE];
#endif
#if SPI_3_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi3DmaRxBuffer[SPI_3_DMA_RX_BUFFER_SIZE];
#elif SPI_3_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi3DmaRxBuffer[SPI_3_DMA_RX_BUFFER_SIZE];
#elif SPI_3_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi3DmaRxBuffer[SPI_3_DMA_RX_BUFFER_SIZE];
#endif
void SPI3_DmaIrqHandler(uint8 Flags, uint32 NumofData);
#endif

#if defined(SPI_4) && SPI_4 == STD_ON
#if SPI_4_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi4DmaTxBuffer[SPI_4_DMA_TX_BUFFER_SIZE];
#elif SPI_4_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi4DmaTxBuffer[SPI_4_DMA_TX_BUFFER_SIZE];
#elif SPI_4_DMA_TX_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi4DmaTxBuffer[SPI_4_DMA_TX_BUFFER_SIZE];
#endif
#if SPI_4_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_32_BIT
uint32 Spi4DmaRxBuffer[SPI_4_DMA_RX_BUFFER_SIZE];
#elif SPI_4_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_16_BIT
uint16 Spi4DmaRxBuffer[SPI_4_DMA_RX_BUFFER_SIZE];
#elif SPI_4_DMA_RX_BUFFER_WIDTH == DATA_WIDTH_8_BIT
uint8 Spi4DmaRxBuffer[SPI_4_DMA_RX_BUFFER_SIZE];
#endif
void SPI4_DmaIrqHandler(uint8 Flags, uint32 NumofData);
#endif

#endif

void ISPI_Init(dtSpiConf Config);
dtSpStatus ISPI_GetStatus(uint8 Instance);
dtSpiData* GetDataOfInstance(uint8 instance);
dtSPI_I2S* GetSpiInstance(uint8 instance);

dtSpiData* GetDataOfInstance(uint8 instance)
{
	dtSpiData *ret = 0;
	switch(instance)
	{
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F415)
	case 1:
		ret = &SPI1Data;
		break;
#endif
#if defined(MCU_F410) || defined(MCU_F446) || defined(MCU_L433) || defined(MCU_G070) || defined(MCU_G071) || defined(MCU_F415)
	case 2:
		ret = &SPI2Data;
		break;
#endif
#if defined(MCU_F446) || defined(MCU_L433) || defined(MCU_F415)
	case 3:
		ret = &SPI3Data;
		break;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
	case 4:
		ret = &SPI4Data;
		break;
#endif
#if defined(MCU_F410) || defined(MCU_F415)
	case 5:
		ret = &SPI5Data;
		break;
#endif
#if defined(MCU_F415)
	case 6:
		ret = &SPI6Data;
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
#if defined(MCU_F446) || defined(MCU_F415)
	case 3:
		ret = SPI3;
		break;
#endif
#if defined(MCU_F446) || defined(MCU_F415)
	case 4:
		ret = SPI4;
		break;
#endif
#if defined(MCU_F410) || defined(MCU_F415)
	case 5:
		ret = SPI5;
		break;
#endif
#if defined(MCU_F415)
	case 6:
		ret = SPI6;
		break;
#endif
	}
	return ret;
}

#if SPI_USAGE_MODE == IRQ_MODE

void SPI_Init(dtSpiConf Config)
{
	dtSPI_I2S *Instance = GetSpiInstance(Config.Instance);

	dtCR1 Cr1Temp = {.Word = 0};
	dtCR2 Cr2Temp = {.Word = 0};

	Cr1Temp.Fields.BR = Config.ClockDiv;
	Cr1Temp.Fields.LSBFIRST = Config.LsbOrMsb;
#if defined(MCU_F446) || defined(MCU_F415)
	Cr1Temp.Fields.DFF = Config.DataSize;
#elif defined(MCU_G071)
	Cr2Temp.Fields.DS = 7;
	Cr2Temp.Fields.FRXTH = 1;
	if(Config.DataSize == Size16Bit)
	{
		Cr2Temp.Fields.FRXTH = 0;
		Cr2Temp.Fields.DS = 15;
	}
#endif
	Cr1Temp.Fields.CPHA = Config.CHPA;
	Cr1Temp.Fields.CPOL = Config.CPOL;
	Cr1Temp.Fields.MSTR = 1;
	Cr1Temp.Fields.SPE = 1;
	Cr1Temp.Fields.SSM = 1;
	Cr1Temp.Fields.SSI = 1;


	Cr2Temp.Fields.FRF = 0;
	Cr2Temp.Fields.RXNEIE =1;
#if defined(SPI_USAGE_MODE) && (SPI_USAGE_MODE == DMA_MODE)
	Cr2Temp.Fields.TXDMAEN = Config.TXDMA;
    Cr2Temp.Fields.RXDMAEN = Config.RXDMA;
#endif

	Instance->CR2 = Cr2Temp;
	Instance->CR1 = Cr1Temp;

	GetDataOfInstance(Config.Instance)->ChipSelectPin = Config.ChipSelectPin;
	GPIO_Set(GetDataOfInstance(Config.Instance)->ChipSelectPin, Set);
}

#elif SPI_USAGE_MODE == DMA_MODE
void dummy(void)
{

}
void ISPI_Init(dtSpiConf Config)
{
    dtSPI_I2S *Instance = GetSpiInstance(Config.Instance);

    dtCR1 Cr1Temp = {.Word = 0};
    dtCR2 Cr2Temp = {.Word = 0};
    dtDmaConfig DmaCfg;

    Cr1Temp.Fields.BR = Config.ClockDiv;
    Cr1Temp.Fields.LSBFIRST = Config.LsbOrMsb;
#if defined(MCU_F446) || defined(MCU_F415)
    Cr1Temp.Fields.DFF = Config.DataSize;
#elif defined(MCU_G071)
    Cr2Temp.Fields.DS = 7;
    Cr2Temp.Fields.FRXTH = 1;
    if(Config.DataSize == Size16Bit)
    {
        Cr2Temp.Fields.FRXTH = 0;
        Cr2Temp.Fields.DS = 15;
    }
#endif
    Cr1Temp.Fields.CPHA = Config.CHPA;
    Cr1Temp.Fields.CPOL = Config.CPOL;
    Cr1Temp.Fields.MSTR = 1;
    Cr1Temp.Fields.SPE = 1;
    Cr1Temp.Fields.SSM = 1;
    Cr1Temp.Fields.SSI = 1;


    Cr2Temp.Fields.FRF = 0;
    Cr2Temp.Fields.RXNEIE = 0;
    Cr2Temp.Fields.TXEIE = 0;
#if SPI_USAGE_MODE == DMA_MODE
    Cr2Temp.Fields.TXDMAEN = 1;
    Cr2Temp.Fields.RXDMAEN = 1;
#endif
    Instance->CR2 = Cr2Temp;
    Instance->CR1 = Cr1Temp;

    GetDataOfInstance(Config.Instance)->ChipSelectPin = Config.ChipSelectPin;
    GPIO_Set(GetDataOfInstance(Config.Instance)->ChipSelectPin, Set);

    DmaCfg.Mem1Ptr              = 0;
    DmaCfg.Priority             = 3;//very high
    DmaCfg.MemoryDataSize       = 0;//byte
    DmaCfg.PeripheralDataSize   = 0;//byte
    DmaCfg.MemAddrInc           = 1;
    DmaCfg.PerAddrInc           = 0;
    DmaCfg.CircularMode         = 0;
    DmaCfg.TransferDirection    = 1;

    switch(Config.Instance)
    {
#if SPI_1 == STD_ON
        case 1:
            /* Tx stream */
            DmaCfg.Instance         = SPI_1_DMA_TX_INSTANCE;
            DmaCfg.Stream           = SPI_1_DMA_TX_STREAM;
            DmaCfg.Mem0Ptr          = Spi1DmaTxBuffer;
            DmaCfg.PerPtr           = &SPI1->DR;
            DmaCfg.RequestChannel   = SPI_1_DMA_TX_REQ_CH;
            IDMA_Config(&DmaCfg, 0);

            /* Rx stream */
            DmaCfg.TransferDirection    = 0;
            DmaCfg.Instance         = SPI_1_DMA_RX_INSTANCE;
            DmaCfg.Stream           = SPI_1_DMA_RX_STREAM;
            DmaCfg.Mem0Ptr          = Spi1DmaRxBuffer;
            DmaCfg.RequestChannel   = SPI_1_DMA_RX_REQ_CH;
            IDMA_Config(&DmaCfg, SPI1_DmaIrqHandler);
            break;
#endif
#if SPI_2 == STD_ON
        case 2:
            DmaCfg.Instance         = SPI_2_DMA_TX_INSTANCE;
            DmaCfg.Stream           = SPI_2_DMA_TX_STREAM;
            DmaCfg.Mem0Ptr          = Spi2DmaTxBuffer;
            DmaCfg.PerPtr           = &SPI2->DR;
            DmaCfg.RequestChannel   = SPI_2_DMA_TX_REQ_CH;
            IDMA_Config(&DmaCfg, 0);

            /* Rx stream */
            DmaCfg.TransferDirection    = 0;
            DmaCfg.Instance         = SPI_2_DMA_RX_INSTANCE;
            DmaCfg.Stream           = SPI_2_DMA_RX_STREAM;
            DmaCfg.Mem0Ptr          = Spi1DmaRxBuffer;
            DmaCfg.RequestChannel   = SPI_2_DMA_RX_REQ_CH;
            IDMA_Config(&DmaCfg, SPI2_DmaIrqHandler);
            break;
#endif
#if SPI_3 == STD_ON
        case 3:
            DmaCfg.Instance         = SPI_3_DMA_TX_INSTANCE;
            DmaCfg.Stream           = SPI_3_DMA_TX_STREAM;
            DmaCfg.Mem0Ptr          = Spi3DmaTxBuffer;
            DmaCfg.PerPtr           = &SPI3->DR;
            DmaCfg.RequestChannel   = SPI_3_DMA_TX_REQ_CH;
            IDMA_Config(&DmaCfg, 0);

            /* Rx stream */
            DmaCfg.TransferDirection    = 0;
            DmaCfg.Instance         = SPI_3_DMA_RX_INSTANCE;
            DmaCfg.Stream           = SPI_3_DMA_RX_STREAM;
            DmaCfg.Mem0Ptr          = Spi3DmaRxBuffer;
            DmaCfg.RequestChannel   = SPI_3_DMA_RX_REQ_CH;
            IDMA_Config(&DmaCfg, SPI3_DmaIrqHandler);
            break;
#endif
#if SPI_4 == STD_ON
        case 4:
            DmaCfg.Instance         = SPI_4_DMA_TX_INSTANCE;
            DmaCfg.Stream           = SPI_4_DMA_TX_STREAM;
            DmaCfg.Mem0Ptr          = Spi4DmaTxBuffer;
            DmaCfg.PerPtr           = &SPI4->DR;
            DmaCfg.RequestChannel   = SPI_4_DMA_TX_REQ_CH;
            IDMA_Config(&DmaCfg, 0);

            /* Rx stream */
            DmaCfg.TransferDirection    = 0;
            DmaCfg.Instance         = SPI_4_DMA_RX_INSTANCE;
            DmaCfg.Stream           = SPI_4_DMA_RX_STREAM;
            DmaCfg.Mem0Ptr          = Spi4DmaRxBuffer;
            DmaCfg.RequestChannel   = SPI_4_DMA_RX_REQ_CH;
            IDMA_Config(&DmaCfg, SPI4_DmaIrqHandler);
            break;
#endif
        default:
            break;
    }
}
#endif
void ISPI_Send(uint8 Instance, uint8 *TxBuff, uint16 TxLength)
{
    GetDataOfInstance(Instance)->Status = SpiInProgress;
    GPIO_Set(GetDataOfInstance(Instance)->ChipSelectPin, Clear);
    switch(Instance)
    {
#if defined(SPI_1) && (SPI_1 == STD_ON)
        case 1:
            if(TxBuff != 0) memcpy_reverse_8bit(TxBuff, Spi1DmaTxBuffer, TxLength);
            else memset_32bit(Spi1DmaTxBuffer, 0, TxLength);
            DMA_Start(SPI_1_DMA_RX_INSTANCE, SPI_1_DMA_RX_STREAM, TxLength);
            DMA_Start(SPI_1_DMA_TX_INSTANCE, SPI_1_DMA_TX_STREAM, TxLength);
            break;
#endif
#if defined(SPI_2) && (SPI_2 == STD_ON)
        case 2:
            if(TxBuff != 0) memcpy_reverse_8bit(TxBuff, Spi2DmaTxBuffer, TxLength);
            else memset_32bit(Spi2DmaTxBuffer, 0, TxLength);
            DMA_Start(SPI_2_DMA_RX_INSTANCE, SPI_2_DMA_RX_STREAM, TxLength);
            DMA_Start(SPI_2_DMA_TX_INSTANCE, SPI_2_DMA_TX_STREAM, TxLength);
            break;
#endif
#if defined(SPI_3) && (SPI_3 == STD_ON)
        case 3:
            if(TxBuff != 0) memcpy_reverse_8bit(TxBuff, Spi3DmaTxBuffer, TxLength);
            else memset_32bit(Spi3DmaTxBuffer, 0, TxLength);
            DMA_Start(SPI_3_DMA_RX_INSTANCE, SPI_3_DMA_RX_STREAM, TxLength);
            DMA_Start(SPI_3_DMA_TX_INSTANCE, SPI_3_DMA_TX_STREAM, TxLength);
            break;
#endif
#if defined(SPI_4) && (SPI_4 == STD_ON)
        case 4:
            if(TxBuff != 0) memcpy_reverse_8bit(TxBuff, Spi4DmaTxBuffer, TxLength);
            else memset_32bit(Spi4DmaTxBuffer, 0, TxLength);
            DMA_Start(SPI_4_DMA_RX_INSTANCE, SPI_4_DMA_RX_STREAM, TxLength);
            DMA_Start(SPI_4_DMA_TX_INSTANCE, SPI_4_DMA_TX_STREAM, TxLength);
            break;
#endif
        default:
            break;
    }
}

Std_ReturnType ISPI_GetData(uint8 Instance, uint8 *RxBuff, uint16 RxLength)
{
    Std_ReturnType ret = E_NOT_OK;
    if((RxBuff != 0) && (GetDataOfInstance(Instance)->Status == SpiDataAvailable))
    {
        GetDataOfInstance(Instance)->Status = SpiIdle;
        ret = E_OK;
        switch(Instance)
        {
    #if defined(SPI_1) && (SPI_1 == STD_ON)
            case 1:
                memcpy_reverse_8bit(Spi1DmaRxBuffer, RxBuff, RxLength);
                break;
    #endif
    #if defined(SPI_2) && (SPI_2 == STD_ON)
            case 2:
                memcpy_reverse_8bit(Spi2DmaRxBuffer, RxBuff, RxLength);
                break;
    #endif
    #if defined(SPI_3) && (SPI_3 == STD_ON)
            case 3:
                memcpy_reverse_8bit(Spi3DmaRxBuffer, RxBuff, RxLength);
                break;
    #endif
    #if defined(SPI_4) && (SPI_4 == STD_ON)
            case 4:
                memcpy_reverse_8bit(Spi4DmaRxBuffer, RxBuff, RxLength);
                break;
    #endif
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}

dtSpStatus ISPI_GetStatus(uint8 Instance)
{
	return GetDataOfInstance(Instance)->Status;
}

#if defined(MCU_F410) || defined(MCU_F446) ||  defined(MCU_G071) || defined(MCU_F415)
void SPI1_IRQHandler(void)
{
	dtSpiData *DataInstance = GetDataOfInstance(1);
	dtSPI_I2S *Instance = GetSpiInstance(1);
	uint8 temp = Instance->DR.DR8;
	if(DataInstance->Offset == 0)
	{
		if((DataInstance->RxBuffPointer != 0) && (DataInstance->RxLength != 0))
		{
			*DataInstance->RxBuffPointer = temp;
			DataInstance->RxBuffPointer++;
			DataInstance->RxLength--;
		}
	}
	else DataInstance->Offset--;

	if((DataInstance->TxBuffPointer != 0) && (DataInstance->TxLength != 0))
	{
		Instance->DR.DR8 = *DataInstance->TxBuffPointer;
		DataInstance->TxBuffPointer++;
		DataInstance->TxLength--;
	}
	else if((DataInstance->Offset == 0) && DataInstance->RxLength == 0)
	{
		GPIO_Set(GetDataOfInstance(1)->ChipSelectPin, Set);
		GetDataOfInstance(1)->Status = SpiIdle;
	}
	else
	{
		Instance->DR.DR8 = 0;
	}
}
#endif

#if SPI_USAGE_MODE == DMA_MODE

uint32 prev;

#if SPI_1 == STD_ON
void SPI1_DmaIrqHandler(uint8 Flags, uint32 NumofData)
{
    GPIO_Set(GetDataOfInstance(1)->ChipSelectPin, Set);
    GetDataOfInstance(1)->Status = SpiDataAvailable;
}
#endif

#if SPI_2 == STD_ON
void SPI2_DmaIrqHandler(uint8 Flags, uint32 NumofData)
{

}
#endif

#if SPI_3 == STD_ON
void SPI3_DmaIrqHandler(uint8 Flags, uint32 NumofData)
{
    GPIO_Set(GetDataOfInstance(3)->ChipSelectPin, Set);
    GetDataOfInstance(3)->Status = SpiDataAvailable;
}
#endif

#if SPI_4 == STD_ON
void SPI4_DmaIrqHandler(uint8 Flags, uint32 NumofData)
{

}
#endif
#endif

#if defined(MCU_F410) | defined(MCU_F446) ||  defined(MCU_G071) || defined(MCU_F415)
void SPI2_IRQHandler(void)
{

}
#endif

#if defined(MCU_F446) || defined(MCU_F415)
void SPI3_IRQHandler(void)
{
#if SPI_USAGE_MODE == IRQ_MODE
    dtSpiData *DataInstance = GetDataOfInstance(3);
    dtSPI_I2S *Instance = GetSpiInstance(3);
    uint8 temp = Instance->DR.DR8;
    if(DataInstance->Offset == 0)
    {
        if((DataInstance->RxBuffPointer != 0) && (DataInstance->RxLength != 0))
        {
            *DataInstance->RxBuffPointer = temp;
            DataInstance->RxBuffPointer++;
            DataInstance->RxLength--;
        }
    }
    else DataInstance->Offset--;

    if((DataInstance->TxBuffPointer != 0) && (DataInstance->TxLength != 0))
    {
        Instance->DR.DR8 = *DataInstance->TxBuffPointer;
        DataInstance->TxBuffPointer++;
        DataInstance->TxLength--;
    }
    else if((DataInstance->Offset == 0) && DataInstance->RxLength == 0)
    {
        GPIO_Set(GetDataOfInstance(3)->ChipSelectPin, Set);
        GetDataOfInstance(3)->Status = SpiIdle;
    }
    else
    {
        Instance->DR.DR8 = 0;
    }
#elif SPI_USAGE_MODE == DMA_MODE
    GPIO_Set(GetDataOfInstance(3)->ChipSelectPin, Set);
#endif
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
#else
#warning "NO CPU IS DEFINED"
#endif

#ifndef _STM32C0_SPI_REGDEF_H_
#define _STM32C0_SPI_REGDEF_H_

#include "RegDefs/regdef_helper.h"
#include "types.h"

typedef struct sSPI_CR1_Bits
{
    uint16 CPHA     :1;
    uint16 CPOL     :1;
    uint16 MSTR     :1;
    uint16 BR       :3;
    uint16 SPE      :1;
    uint16 LSBFIRST :1;
    uint16 SSI      :1;
    uint16 SSM      :1;
    uint16 RXONLY   :1;
    uint16 CRCL     :1;
    uint16 CRCNEXT  :1;
    uint16 CRCEN    :1;
    uint16 BIDIOE   :1;
    uint16 BIDIMODE :1;
} dtSPI_CR1_Bits;

typedef struct sSPI_CR2_Bits
{
    uint16 RXDMAEN  :1;
    uint16 TXDMAEN  :1;
    uint16 SSOE     :1;
    uint16 NSSP     :1;
    uint16 FRF      :1;
    uint16 ERRIE    :1;
    uint16 RXNEIE   :1;
    uint16 TXEIE    :1;
    uint16 DS       :4;
    uint16 FRXTH    :1;
    uint16 LDMA_RX  :1;
    uint16 LDMA_TX  :1;
    uint16          :1;
} dtSPI_CR2_Bits;

typedef struct sSPI_SR_Bits
{
    uint16 RXNE     :1;
    uint16 TXE      :1;
    uint16 CHSIDE   :1;
    uint16 UDR      :1;
    uint16 CRCERR   :1;
    uint16 MODF     :1;
    uint16 OVR      :1;
    uint16 BSY      :1;
    uint16 FRE      :1;
    uint16 FRLVL    :2;
    uint16 FTLVL    :2;
    uint16          :3;
} dtSPI_SR_Bits;

typedef struct sSPI_I2SCFGR_Bits
{
    uint16 CHLEN    :1;
    uint16 DATLEN   :2;
    uint16 CKPOL    :1;
    uint16 I2SSTD   :2;
    uint16          :1;
    uint16 PCMSYNC  :1;
    uint16 I2SCFG   :2;
    uint16 I2SE     :1;
    uint16 I2SMOD   :1;
    uint16 ASTRTEN  :1;
    uint16          :3;
} dtSPI_I2SCFGR_Bits;

typedef struct sSPI_I2SPR_Bits
{
    uint16 I2SDIV   :8;
    uint16 ODD      :1;
    uint16 MCKOE    :1;
    uint16          :6;
} dtSPI_I2SPR_Bits;

REGDEF_16(SPI, CR1)
REGDEF_16(SPI, CR2)
REGDEF_16(SPI, SR)
REGDEF_16(SPI, I2SCFGR)
REGDEF_16(SPI, I2SPR)

typedef struct sSPI
{
    dtSPI_CR1 CR1;
    uint16 :16;
    dtSPI_CR2 CR2;
    uint16 :16;
    dtSPI_SR SR;
    uint16 :16;
    uint16 DR;
    uint16 :16;
    uint16 CRCPOLY;
    uint16 :16;
    uint16 RXCRC;
    uint16 :16;
    uint16 TXCRC;
    uint16 :16;
    dtSPI_I2SCFGR I2SCFGR;
    uint16 :16;
    dtSPI_I2SPR I2SPR;
    uint16 :16;
} dtSPI;



#endif /* _STM32C0_SPI_REGDEF_H_ */

/*
 * STM32C0_I2C_regdef.h
 *
 *  Created on: Sep 4, 2026
 *      Author: GitHub Copilot
 */

#ifndef INC_REGDEFS_STM32C0_I2C_REGDEF_H_
#define INC_REGDEFS_STM32C0_I2C_REGDEF_H_

#include "RegDefs/regdef_helper.h"
#include "types.h"

typedef struct sI2C_C0_CR1_Bits
{
    uint32 PE        :1;
    uint32 TXIE      :1;
    uint32 RXIE      :1;
    uint32 ADDRIE    :1;
    uint32 NACKIE    :1;
    uint32 STOPIE    :1;
    uint32 TCIE      :1;
    uint32 ERRIE     :1;
    uint32 DNF       :4;
    uint32 ANFOFF    :1;
    uint32           :1;
    uint32 TXDMAEN   :1;
    uint32 RXDMAEN   :1;
    uint32 SBC       :1;
    uint32 NOSTRETCH :1;
    uint32 WUPEN     :1;
    uint32 GCEN      :1;
    uint32 SMBHEN    :1;
    uint32 SMBDEN    :1;
    uint32 ALERTEN   :1;
    uint32 PECEN     :1;
    uint32           :8;
} dtI2C_C0_CR1_Bits;

typedef struct sI2C_C0_CR2_Bits
{
    uint32 SADD      :10;
    uint32 RD_WRN    :1;
    uint32 ADD10     :1;
    uint32 HEAD10R   :1;
    uint32 START     :1;
    uint32 STOP      :1;
    uint32 NACK      :1;
    uint32 NBYTES    :8;
    uint32 RELOAD    :1;
    uint32 AUTOEND   :1;
    uint32 PECBYTE   :1;
    uint32           :5;
} dtI2C_C0_CR2_Bits;

typedef struct sI2C_C0_OAR1_Bits
{
    uint32 OA1       :10;
    uint32 OA1MODE   :1;
    uint32           :4;
    uint32 OA1EN     :1;
    uint32           :16;
} dtI2C_C0_OAR1_Bits;

typedef struct sI2C_C0_OAR2_Bits
{
    uint32           :1;
    uint32 OA2       :7;
    uint32 OA2MSK    :3;
    uint32           :4;
    uint32 OA2EN     :1;
    uint32           :16;
} dtI2C_C0_OAR2_Bits;

typedef struct sI2C_C0_TIMINGR_Bits
{
    uint32 SCLL      :8;
    uint32 SCLH      :8;
    uint32 SDADEL    :4;
    uint32 SCLDEL    :4;
    uint32           :4;
    uint32 PRESC     :4;
} dtI2C_C0_TIMINGR_Bits;

typedef struct sI2C_C0_TIMEOUTR_Bits
{
    uint32 TIMEOUTA  :12;
    uint32 TIDLE     :1;
    uint32           :2;
    uint32 TIMOUTEN  :1;
    uint32 TIMEOUTB  :12;
    uint32           :3;
    uint32 TEXTEN    :1;
} dtI2C_C0_TIMEOUTR_Bits;

typedef struct sI2C_C0_ISR_Bits
{
    uint32 TXE       :1;
    uint32 TXIS      :1;
    uint32 RXNE      :1;
    uint32 ADDR      :1;
    uint32 NACKF     :1;
    uint32 STOPF     :1;
    uint32 TC        :1;
    uint32 TCR       :1;
    uint32 BERR      :1;
    uint32 ARLO      :1;
    uint32 OVR       :1;
    uint32 PECERR    :1;
    uint32 TIMEOUT   :1;
    uint32 ALERT     :1;
    uint32           :1;
    uint32 BUSY      :1;
    uint32 DIR       :1;
    uint32 ADDCODE   :7;
    uint32           :8;
} dtI2C_C0_ISR_Bits;

typedef struct sI2C_C0_ICR_Bits
{
    uint32           :3;
    uint32 ADDRCF    :1;
    uint32 NACKCF    :1;
    uint32 STOPCF    :1;
    uint32           :2;
    uint32 BERRCF    :1;
    uint32 ARLOCF    :1;
    uint32 OVRCF     :1;
    uint32 PECCF     :1;
    uint32 TIMOUTCF  :1;
    uint32 ALERTCF   :1;
    uint32           :18;
} dtI2C_C0_ICR_Bits;

typedef struct sI2C_C0_PECR_Bits
{
    uint32 PEC       :8;
    uint32           :24;
} dtI2C_C0_PECR_Bits;

typedef struct sI2C_C0_RXDR_Bits
{
    uint32 RXDATA    :8;
    uint32           :24;
} dtI2C_C0_RXDR_Bits;

typedef struct sI2C_C0_TXDR_Bits
{
    uint32 TXDATA    :8;
    uint32           :24;
} dtI2C_C0_TXDR_Bits;

REGDEF(I2C_C0, CR1)
REGDEF(I2C_C0, CR2)
REGDEF(I2C_C0, OAR1)
REGDEF(I2C_C0, OAR2)
REGDEF(I2C_C0, TIMINGR)
REGDEF(I2C_C0, TIMEOUTR)
REGDEF(I2C_C0, ISR)
REGDEF(I2C_C0, ICR)
REGDEF(I2C_C0, PECR)
REGDEF(I2C_C0, RXDR)
REGDEF(I2C_C0, TXDR)

typedef struct sI2C_C0
{
    dtI2C_C0_CR1       CR1;
    dtI2C_C0_CR2       CR2;
    dtI2C_C0_OAR1      OAR1;
    dtI2C_C0_OAR2      OAR2;
    dtI2C_C0_TIMINGR   TIMINGR;
    dtI2C_C0_TIMEOUTR  TIMEOUTR;
    dtI2C_C0_ISR       ISR;
    dtI2C_C0_ICR       ICR;
    dtI2C_C0_PECR      PECR;
    dtI2C_C0_RXDR      RXDR;
    dtI2C_C0_TXDR      TXDR;
    uint8              Padding[980];
} dtI2C_C0;

typedef struct sI2C_C0_Map
{
    dtI2C_C0 I2C1;
    dtI2C_C0 I2C2;
} dtI2C_C0_Map;

#endif /* INC_REGDEFS_STM32C0_I2C_REGDEF_H_ */
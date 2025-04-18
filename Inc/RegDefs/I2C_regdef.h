/*
 * I2C_regdef.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_I2C_REGDEF_H_
#define INC_REGDEFS_I2C_REGDEF_H_

#include "RegDefs/regdef_helper.h"

typedef struct sI2C_CR1_Bits
{
    uint32 PE       :1;
    uint32 TXIE     :1;
    uint32 RXIE     :1;
    uint32 ADDRIE   :1;
    uint32 NACKIE   :1;
    uint32 STOPIE   :1;
    uint32 TCIE     :1;
    uint32 ERRIE    :1;
    uint32 DNF      :4;
    uint32 ANFOFF   :1;
    uint32          :1;
    uint32 TXDMAEN  :1;
    uint32 RXDMAEN  :1;
    uint32 SBC      :1;
    uint32 NOSTRETCH:1;
    uint32 WUPEN    :1;
    uint32 GCEN     :1;
    uint32          :4;
    uint32 FMP      :1;
    uint32          :5;
    uint32 ADDRACLR :1;
    uint32 STOPFACLR:1;
} dtI2C_CR1_Bits;

typedef struct sI2C_CR2_Bits
{
    uint32 SADD     :10;
    uint32 RD_WRN   :1;
    uint32 ADD10    :1;
    uint32 HEAD10R  :1;
    uint32 START    :1;
    uint32 STOP     :1;
    uint32 NACK     :1;
    uint32 NBYTES   :8;
    uint32 RELOAD   :1;
    uint32 AUTOEND  :1;
    uint32          :6;
} dtI2C_CR2_Bits;

typedef struct sI2C_OAR1_Bits
{
    uint32 OA1      :10;
    uint32 OA1MODE  :1;
    uint32          :4;
    uint32 OA1EN    :1;
    uint32          :16;
} dtI2C_OAR1_Bits;

typedef struct sI2C_OAR2_Bits
{
    uint32          :1;
    uint32 OA2      :7;
    uint32 OA2MSK   :3;
    uint32          :4;
    uint32 OA2EN    :1;
    uint32          :16;
} dtI2C_OAR2_Bits;

typedef struct sI2C_TIMINGR_Bits
{
    uint32 SCLL     :8;
    uint32 SCLH     :8;
    uint32 SDADEL   :4;
    uint32 SCLDEL   :4;
    uint32          :4;
    uint32 PRESC    :4;
} dtI2C_TIMINGR_Bits;

typedef struct sI2C_ISR_Bits
{
    uint32 TXE      :1;
    uint32 TXIS     :1;
    uint32 RXNE     :1;
    uint32 ADDR     :1;
    uint32 NACKF    :1;
    uint32 STOPF    :1;
    uint32 TC       :1;
    uint32 TCR      :1;
    uint32 BERR     :1;
    uint32 ARLO     :1;
    uint32 OVR      :1;
    uint32          :1;
    uint32          :1;
    uint32          :1;
    uint32          :1;
    uint32 BUSY     :1;
    uint32 DIR      :1;
    uint32 ADDCODE  :7;
    uint32          :8;
} dtI2C_ISR_Bits;

typedef struct sI2C_ICR_Bits
{
    uint32          :3;
    uint32 ADDRCF   :1;
    uint32 NACKCF   :1;
    uint32 STOPCF   :1;
    uint32          :2;
    uint32 BERRCF   :1;
    uint32 ARLOCF   :1;
    uint32 OVRCF    :1;
    uint32          :21;
} dtI2C_ICR_Bits;

typedef struct sI2C_RXDR_Bits
{
    uint32 RXDATA      :8;
} dtI2C_RXDR_Bits;

typedef struct sI2C_TXDR_Bits
{
    uint32 TXDATA   :8;
} dtI2C_TXDR_Bits;

REGDEF(I2C, CR1);
REGDEF(I2C, CR2);
REGDEF(I2C, OAR1);
REGDEF(I2C, OAR2);
REGDEF(I2C, TIMINGR);
REGDEF(I2C, ISR);
REGDEF(I2C, ICR);
REGDEF(I2C, RXDR);
REGDEF(I2C, TXDR);

typedef struct sI2C
{
    dtI2C_CR1       CR1;
    dtI2C_CR2       CR2;
    dtI2C_OAR1      OAR1;
    dtI2C_OAR2      OAR2;
    dtI2C_TIMINGR   TIMINGR;
    uint32          :32;
    dtI2C_ISR       ISR;
    dtI2C_ICR       ICR;
    uint32          :32;
    dtI2C_RXDR      RXDR;
    dtI2C_TXDR      TXDR;
} dtI2C;

#endif /* INC_REGDEFS_I2C_REGDEF_H_ */

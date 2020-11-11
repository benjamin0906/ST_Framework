/*
 * I2C_Types.h
 *
 *  Created on: 2020. okt. 16.
 *      Author: BodnarB
 */

#include "types.h"

typedef union
{
	struct
	{
		uint32 PE		:1;
		uint32 TXIE		:1;
		uint32 RXIE		:1;
		uint32 ADDRIE	:1;
		uint32 NACKIE	:1;
		uint32 STOPIE	:1;
		uint32 TCIE		:1;
		uint32 ERRIE	:1;
		uint32 DNF		:4;
		uint32 ANFOFF	:1;
		uint32 			:1;
		uint32 TXDMAEN	:1;
		uint32 RXDMAEN	:1;
		uint32 SBC		:1;
		uint32 NOSTRETCH:1;
		uint32 WUPEN	:1;
		uint32 GCEN		:1;
		uint32 SMBHEN	:1;
		uint32 SMBDEN	:1;
		uint32 ALERTEN	:1;
		uint32 PECEN	:1;
	} Fields;
	uint32 Word;
} dtCR1;

typedef union
{
	struct
	{
		uint32 SADD		:10;
		uint32 RD_WRN	:1;
		uint32 ADD10	:1;
		uint32 HEAD10R	:1;
		uint32 START	:1;
		uint32 STOP		:1;
		uint32 NACK		:1;
		uint32 NBYTES	:8;
		uint32 RELOAD	:1;
		uint32 AUTOEND	:1;
		uint32 PECBYTE	:1;
	} Fields;
	uint32 Word;
} dtCR2;

typedef union
{
	struct
	{
		uint32 OA1		:7;
		uint32 OA1MODE	:3;
		uint32 			:4;
		uint32 OA1EN	:1;
	} Fields;
	uint32 Word;
} dtOAR1;

typedef union
{
	struct
	{
		uint32 OA2		:7;
		uint32 OA2MSK	:3;
		uint32 			:4;
		uint32 OA2EN	:1;
	} Fields;
	uint32 Word;
} dtOAR2;

typedef union
{
	struct
	{
		uint32 SCLL		:8;
		uint32 SCLH		:8;
		uint32 SDADEL	:4;
		uint32 SCLDEL	:4;
		uint32 			:4;
		uint32 PRESC	:4;
	} Fields;
	uint32 Word;
} dtTIMINGR;

typedef union
{
	struct
	{
		uint32 TIMEOUTA	:12;
		uint32 TIDLE	:1;
		uint32			:2;
		uint32 TIMOUTEN	:1;
		uint32 TIMEOUTB	:12;
		uint32			:3;
		uint32 TEXTEN	:1;
	} Fields;
	uint32 Word;
} dtTIMEOUTR;

typedef union
{
	struct
	{
		uint32 TXE		:1;
		uint32 TXIS		:1;
		uint32 RXNE		:1;
		uint32 ADDR		:1;
		uint32 NACKF	:1;
		uint32 STOPF	:1;
		uint32 TC		:1;
		uint32 TCR		:1;
		uint32 BERR		:1;
		uint32 ARLO		:1;
		uint32 OVR		:1;
		uint32 PECERR	:1;
		uint32 TIMEOUT	:1;
		uint32 ALERT	:1;
		uint32 			:1;
		uint32 BUSY		:1;
		uint32 DIR		:1;
		uint32 ADDCODE	:7;
	} Fields;
	uint32 Word;
} dtISR;

typedef union
{
	struct
	{
		uint32 			:3;
		uint32 ADDRCF	:1;
		uint32 NACKCF	:1;
		uint32 STOPCF	:1;
		uint32 			:2;
		uint32 BERRCF	:1;
		uint32 ARLOCF	:1;
		uint32 OVRCF	:1;
		uint32 PECCF	:1;
		uint32 TIMOUTCF	:1;
		uint32 ALERTCF	:1;
	} Fields;
	uint32 Word;
} dtICR;

typedef union
{
	struct
	{
		uint32 PEC		:8;
	} Fields;
	uint32 Word;
} dtPECR;

typedef union
{
	struct
	{
		uint32 RXDATA	:8;
	} Fields;
	uint32 Word;
} dtRXDR;

typedef union
{
	struct
	{
		uint32 TXDATA	:8;
	} Fields;
	uint32 Word;
} dtTXDR;

typedef struct
{
	dtCR1		CR1;
	dtCR2		CR2;
	dtOAR1		OAR1;
	dtOAR2		OAR2;
	dtTIMINGR	TIMINGR;
	dtTIMEOUTR	TIMEOUTR;
	dtISR		ISR;
	dtICR		ICR;
	dtPECR		PECR;
	dtRXDR		RXDR;
	dtTXDR		TXDR;
} dtI2C;

#define SET_SLAVE_ADDRESS(x)	I2C[1]->CR2.Fields.SADD = x
#define SET_TRANSFER_SIZE(Instance, Size)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.NBYTES = Size;\
	I2C[Instance]->CR2 = temp; \
}

#define GENERATE_STOP(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.STOP = 1;\
	I2C[Instance]->CR2 = temp; \
}

#define GENERATE_START(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.START = 1;\
	I2C[Instance]->CR2 = temp; \
}

#define DISABLE_RELOAD(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.RELOAD = 0;\
	I2C[Instance]->CR2 = temp; \
}

#define ENABLE_RELOAD(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.RELOAD = 1;\
	I2C[Instance]->CR2 = temp; \
}

#define SET_AUTO_ENABLE(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.AUTOEND = 1;\
	I2C[Instance]->CR2 = temp; \
}

#define CLEAR_AUTO_ENABLE(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.AUTOEND = 0;\
	I2C[Instance]->CR2 = temp; \
}

#define CLEAR_STOP_FLAG(Instance)	\
{\
	dtICR temp = I2C[Instance]->ICR;\
	temp.Fields.STOPCF = 1;\
	I2C[Instance]->ICR = temp; \
}

#define CLEAR_NACK_FLAG(Instance)	\
{\
	dtICR temp = I2C[Instance]->ICR;\
	temp.Fields.NACKCF = 1;\
	I2C[Instance]->ICR = temp; \
}

#define SET_READ_TRANSFER_REQ(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.RD_WRN = 1;\
	I2C[Instance]->CR2 = temp; \
}

#define SET_WRITE_TRANSFER_REQ(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.RD_WRN = 0;\
	I2C[Instance]->CR2 = temp; \
}

#define SET_7BIT_ADDRESS_MODE(Instance)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.HEAD10R = 1;\
	I2C[Instance]->CR2 = temp; \
}

#define SET_SLAVE_ADDRESS(Instance, x)	\
{\
	dtCR2 temp = I2C[Instance]->CR2;\
	temp.Fields.SADD = x<<1;\
	I2C[Instance]->CR2 = temp; \
}

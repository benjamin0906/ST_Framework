/*
 * RTC_Types.h
 *
 *  Created on: 2021. febr. 10.
 *      Author: Benjamin
 */

#ifndef SRC_RTC_RTC_TYPES_H_
#define SRC_RTC_RTC_TYPES_H_

#include "types.h"

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SU	:4;
		uint32 ST	:3;
		uint32 		:1;
		uint32 MNU	:4;
		uint32 MNT	:3;
		uint32 		:1;
		uint32 HU	:4;
		uint32 HT	:2;
		uint32 PM	:1;
	} Fields;
} dtRTC_TR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 DU	:4;
		uint32 DT	:2;
		uint32 		:2;
		uint32 MU	:4;
		uint32 MT	:1;
		uint32 WDU	:3;
		uint32 YU	:4;
		uint32 YT	:4;
	} Fields;
} dtRTC_DR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SS	:16;
	} Fields;
} dtRTC_SSR;
#endif

#if defined(MCU_G071)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 ALRAWF	:1;
		uint32 ALRBWF	:1;
		uint32 WUTWF	:1;
		uint32 SHPF		:1;
		uint32 INITS	:1;
		uint32 RSF		:1;
		uint32 INITF	:1;
		uint32 INIT		:1;
		uint32 			:8;
		uint32 RECALPF	:1;
	} Fields;
} dtRTC_ICSR;
#endif

#if defined(MCU_F415) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 ALRAWF	:1;
		uint32 ALRBWF	:1;
		uint32 WUTWF	:1;
		uint32 SHPF		:1;
		uint32 INITS	:1;
		uint32 RSF		:1;
		uint32 INITF	:1;
		uint32 INIT		:1;
		uint32 ALRAF	:1;
		uint32 ALRBF	:1;
		uint32 WUTF		:1;
		uint32 TSF		:1;
		uint32 TSOVF	:1;
		uint32 TAMP1F	:1;
		uint32 TAMP2F	:1;
	} Fields;
} dtRTC_ISR;
#elif defined(MCU_L476)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 ALRAWF	:1;
		uint32 ALRBWF	:1;
		uint32 WUTWF	:1;
		uint32 SHPF		:1;
		uint32 INITS	:1;
		uint32 RSF		:1;
		uint32 INITF	:1;
		uint32 INIT		:1;
		uint32 ALRAF	:1;
		uint32 ALRBF	:1;
		uint32 WUTF		:1;
		uint32 TSF		:1;
		uint32 TSOVF	:1;
		uint32 TAMP1F	:1;
		uint32 TAMP2F	:1;
		uint32 TAMP3F	:1;
		uint32 RECALPF	:1;
		uint32 ITSF		:1;
	} Fields;
} dtRTC_ISR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 PREDIV_S	:15;
		uint32 			:1;
		uint32 PREDIV_A	:7;
	} Fields;
} dtRTC_PRER;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 WUT	:16;
	} Fields;
} dtRTC_WUTR;
#endif

#if defined(MCU_G071)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 WUCKSEL			:3;
		uint32 TS_EDGE			:1;
		uint32 REFCK_ON			:1;
		uint32 BYP_SHAD			:1;
		uint32 FMT				:1;
		uint32 					:1;
		uint32 ALRAE			:1;
		uint32 ALRBE			:1;
		uint32 WUTE				:1;
		uint32 TSE				:1;
		uint32 ALRA_IE			:1;
		uint32 ALRB_IE			:1;
		uint32 WUTIE			:1;
		uint32 TSIE				:1;
		uint32 ADD1H			:1;
		uint32 SUB1H			:1;
		uint32 BKP				:1;
		uint32 COSEL			:1;
		uint32 POL				:1;
		uint32 OSEL				:2;
		uint32 COE				:1;
		uint32 ITSE				:1;
		uint32 TAMP_TS			:1;
		uint32 TAMP_OE			:1;
		uint32 					:2;
		uint32 TAMP_ALRM_PU		:1;
		uint32 TAMP_ALRM_TYPE	:1;
		uint32 OUT2EN			:1;
	} Fields;
} dtRTC_CR;
#elif defined(MCU_F415) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 WUCKSEL			:3;
		uint32 TS_EDGE			:1;
		uint32 REFCK_ON			:1;
		uint32 BYP_SHAD			:1;
		uint32 FMT				:1;
		uint32 DCE				:1;
		uint32 ALRAE			:1;
		uint32 ALRBE			:1;
		uint32 WUTE				:1;
		uint32 TSE				:1;
		uint32 ALRA_IE			:1;
		uint32 ALRB_IE			:1;
		uint32 WUTIE			:1;
		uint32 TSIE				:1;
		uint32 ADD1H			:1;
		uint32 SUB1H			:1;
		uint32 BKP				:1;
		uint32 COSEL			:1;
		uint32 POL				:1;
		uint32 OSEL				:2;
		uint32 COE				:1;
	} Fields;
} dtRTC_CR;
#elif defined(MCU_L476)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 WUCKSEL			:3;
		uint32 TS_EDGE			:1;
		uint32 REFCK_ON			:1;
		uint32 BYP_SHAD			:1;
		uint32 FMT				:1;
		uint32 					:1;
		uint32 ALRAE			:1;
		uint32 ALRBE			:1;
		uint32 WUTE				:1;
		uint32 TSE				:1;
		uint32 ALRA_IE			:1;
		uint32 ALRB_IE			:1;
		uint32 WUTIE			:1;
		uint32 TSIE				:1;
		uint32 ADD1H			:1;
		uint32 SUB1H			:1;
		uint32 BKP				:1;
		uint32 COSEL			:1;
		uint32 POL				:1;
		uint32 OSEL				:2;
		uint32 COE				:1;
		uint32 ITSE				:1;
	} Fields;
} dtRTC_CR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 KEY	:8;
	} Fields;
} dtRTC_WPR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 CALM		:9;
		uint32 			:4;
		uint32 CALW16	:1;
		uint32 CALW8	:1;
		uint32 CALP		:1;
	} Fields;
} dtRTC_CALR;
#endif

#if defined(MCU_F415) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 DC		:5;
		uint32 			:2;
		uint32 DCS		:1;
	} Fields;
} dtRTC_CALIBR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SUBFS	:15;
		uint32 			:16;
		uint32 ADD1S	:1;
	} Fields;
} dtRTC_SHIFTR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SU	:4;
		uint32 ST	:3;
		uint32 		:1;
		uint32 MNU	:4;
		uint32 MNT	:3;
		uint32 		:1;
		uint32 HU	:4;
		uint32 HT	:2;
		uint32 PM	:1;
	} Fields;
} dtRTC_TSTR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 DU	:4;
		uint32 DT	:2;
		uint32 		:2;
		uint32 MU	:4;
		uint32 MT	:1;
		uint32 WDU	:3;
	} Fields;
} dtRTC_TSDR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SS	:16;
	} Fields;
} dtRTC_TSSSR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SU		:4;
		uint32 ST		:3;
		uint32 MSK1		:1;
		uint32 MNU		:4;
		uint32 MNT		:3;
		uint32 MSK2		:1;
		uint32 HU		:4;
		uint32 HT		:2;
		uint32 PM		:1;
		uint32 MSK3		:1;
		uint32 DU		:4;
		uint32 DT		:2;
		uint32 WDSEL	:1;
		uint32 MSK4		:1;
	} Fields;
} dtRTC_ALRMAR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SS		:15;
		uint32 			:9;
		uint32 MASKSS	:4;
	} Fields;
} dtRTC_ALRMASSR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SU		:4;
		uint32 ST		:3;
		uint32 MSK1		:1;
		uint32 MNU		:4;
		uint32 MNT		:3;
		uint32 MSK2		:1;
		uint32 HU		:4;
		uint32 HT		:2;
		uint32 PM		:1;
		uint32 MSK3		:1;
		uint32 DU		:4;
		uint32 DT		:2;
		uint32 WDSEL	:1;
		uint32 MSK4		:1;
	} Fields;
} dtRTC_ALRMBR;
#endif

#if defined(MCU_G071) || defined(MCU_F415) || defined(MCU_L476) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 SS		:15;
		uint32 			:9;
		uint32 MASKSS	:4;
	} Fields;
} dtRTC_ALRMBSSR;
#endif

#if defined(MCU_G071)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 ALRAF	:1;
		uint32 ALRBF	:1;
		uint32 WUTF		:1;
		uint32 TSF		:1;
		uint32 TSOVF	:1;
		uint32 ITSF		:1;
	} Fields;
} dtRTC_SR;
#endif

#if defined(MCU_G071)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 ALRAMF	:1;
		uint32 ALRBMF	:1;
		uint32 WUTMF	:1;
		uint32 TSMF		:1;
		uint32 TSOVMF	:1;
		uint32 ITSMF	:1;
	} Fields;
} dtRTC_MISR;
#endif

#if defined(MCU_G071)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 CALRAF	:1;
		uint32 CALRBF	:1;
		uint32 CWUTF	:1;
		uint32 CTSF		:1;
		uint32 CTSOVF	:1;
		uint32 CITSF	:1;
	} Fields;
} dtRTC_SCR;
#endif

#if defined(MCU_F415) || defined(MCU_F446)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 TAMP1E		:1;
		uint32 TAMP1ETRG	:1;
		uint32 TAMPIE		:1;
		uint32 TAMP2E		:1;
		uint32 TAMP2TRG		:1;
		uint32				:2;
		uint32 TAMPTS		:3;
		uint32 TAMPFREQ		:3;
		uint32 TAMPFLT		:2;
		uint32 TAMPPRCH		:2;
		uint32 TAMPPUDIS	:1;
		uint32 TAMP1INSEL	:1;
		uint32 TSINSEL		:1;
		uint32 ALARMOUTTYPE	:1;
	} Fields;
} dtRTC_TAFCR;
#endif

#if defined(MCU_L476)
typedef union
{
	uint32 Word;
	struct
	{
		uint32 TAMP1E		:1;
		uint32 TAMP1ETRG	:1;
		uint32 TAMPIE		:1;
		uint32 TAMP2E		:1;
		uint32 TAMP2TRG		:1;
		uint32 TAMP3E		:1;
		uint32 TAMP3TRG		:1;
		uint32 TAMPTS		:3;
		uint32 TAMPFREQ		:3;
		uint32 TAMPFLT		:2;
		uint32 TAMPPRCH		:2;
		uint32 TAMPPUDIS	:1;
		uint32 TAMP1IE		:1;
		uint32 TAMP1NOERASE		:1;
		uint32 TAMP1MF	:1;
		uint32 TAMP2IE	:1;
		uint32 TAMP2NOERASE	:1;
		uint32 TAMP2MF	:1;
		uint32 TAMP3IE	:1;
		uint32 TAMP3NOERASE	:1;
		uint32 TAMP3MF	:1;
	} Fields;
} dtRTC_TAMPCR;
#endif

#if defined(MCU_G071)
typedef struct
{
	dtRTC_TR		TR;			//0x00
	dtRTC_DR		DR;			//0x04
	dtRTC_SSR		SSR;		//0x08
	dtRTC_ICSR		ICSR;		//0x0C
	dtRTC_PRER		PRER;		//0x10
	dtRTC_WUTR		WUTR;		//0x14
	dtRTC_CR		CR;			//0x18
	uint32			:32;		//0x1C
	uint32			:32;		//0x20
	dtRTC_WPR		WPR;		//0x24
	dtRTC_CALR		CALR;		//0x28
	dtRTC_SHIFTR 	SHIFTR;		//0x2C
	dtRTC_TSTR		TSTR;		//0x30
	dtRTC_TSDR		TSDR;		//0x34
	dtRTC_TSSSR		TSSSR;		//0x38
	uint32			:32;		//0x3C
	dtRTC_ALRMAR	ALRMAR;		//0x40
	dtRTC_ALRMASSR	ALRMASSR;	//0x44
	dtRTC_ALRMBR	ALRMBR;		//0x48
	dtRTC_ALRMBSSR	ALRMBSSR;	//0x4C
	dtRTC_SR		SR;			//0x50
	dtRTC_MISR 		MISR;		//0x54
	uint32			:32;		//0x58
	dtRTC_SCR		SCR;		//0x5C
} dtRTC;
#elif defined(MCU_F415) || defined(MCU_F446)
typedef struct
{
	dtRTC_TR		TR;			//0x00
	dtRTC_DR		DR;			//0x04
	dtRTC_CR		CR;			//0x08
	dtRTC_ISR		ISR;		//0x0C
	dtRTC_PRER		PRER;		//0x10
	dtRTC_WUTR		WUTR;		//0x14
	dtRTC_CALIBR	CALIBR;		//0x18
	dtRTC_ALRMAR	ALRMAR;		//0x1C
	dtRTC_ALRMBR	ALRMBR;		//0x20
	dtRTC_WPR		WPR;		//0x24
	dtRTC_SSR		SSR;		//0x28
	dtRTC_SHIFTR	SHIFTR;		//0x2C
	dtRTC_TSTR		TSTR;		//0x30
	uint32			:32;		//0x34
	dtRTC_TSSSR		TSSSR;		//0x38
	dtRTC_CALR		CALR;		//0x3C
	dtRTC_TAFCR		TAFCR;		//0x40
	dtRTC_ALRMASSR	ALRMASSR;	//0x44
	dtRTC_ALRMBSSR	ALRMBSSR;	//0x48
	uint32			:32;		//0x4C
} dtRTC;
#elif defined(MCU_L476)
typedef struct
{
	dtRTC_TR		TR;			//0x00
	dtRTC_DR		DR;			//0x04
	dtRTC_CR		CR;			//0x08
	dtRTC_ISR		ISR;		//0x0C
	dtRTC_PRER		PRER;		//0x10
	dtRTC_WUTR		WUTR;		//0x14
	uint32			:32;		//0x18
	dtRTC_ALRMAR	ALRMAR;		//0x1C
	dtRTC_ALRMBR	ALRMBR;		//0x20
	dtRTC_WPR		WPR;		//0x24
	dtRTC_SSR		SSR;		//0x28
	dtRTC_SHIFTR	SHIFTR;		//0x2C
	dtRTC_TSTR		TSTR;		//0x30
	dtRTC_TSDR		TSDR;		//0x34
	dtRTC_TSSSR		TSSSR;		//0x38
	dtRTC_CALR		CALR;		//0x3C
	dtRTC_TAMPCR	TAMPCR;		//0x40
	dtRTC_ALRMASSR	ALRMASSR;	//0x44
	dtRTC_ALRMBSSR	ALRMBSSR;	//0x48
	uint32			OR;		//0x4C
} dtRTC;
#endif

#endif /* SRC_RTC_RTC_TYPES_H_ */

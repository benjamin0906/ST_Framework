/*
 * RTC_regdef.h
 *
 *  Created on: Apr 13, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_RTC_REGDEF_H_
#define INC_REGDEFS_RTC_REGDEF_H_

#include "RegDefs/regdef_helper.h"

typedef struct sRTC_TR_Bits
{
    uint32 SU   :4;
    uint32 ST   :3;
    uint32      :1;
    uint32 MNU  :4;
    uint32 MNT  :3;
    uint32      :1;
    uint32 HU   :4;
    uint32 HT   :2;
    uint32 PM   :1;
} dtRTC_TR_Bits;

typedef struct sRTC_DR_Bits
{
    uint32 DU   :4;
    uint32 DT   :2;
    uint32      :2;
    uint32 MU   :4;
    uint32 MT   :1;
    uint32 WDU  :3;
    uint32 YU   :4;
    uint32 YT   :4;
} dtRTC_DR_Bits;

typedef struct sRTC_SSR_Bits
{
    uint32 SS   :32;
} dtRTC_SSR_Bits;

typedef struct sRTC_ICSR_Bits
{
    uint32          :1;
    uint32          :1;
    uint32 WUTWF    :1;
    uint32 SHPF     :1;
    uint32 INITS    :1;
    uint32 RSF      :1;
    uint32 INITF    :1;
    uint32 INIT     :1;
    uint32 BIN      :2;
    uint32 BCDU     :3;
    uint32          :3;
    uint32 RECALPF  :1;
} dtRTC_ICSR_Bits;

typedef struct sRTC_PRER_Bits
{
    uint32 PREDIV_S :15;
    uint32          :1;
    uint32 PREDIV_A :7;
    uint32          :9;
} dtRTC_PRER_Bits;

typedef struct sRTC_WUTR_Bits
{
    uint32 WUT      :16;
    uint32 WUTOCLR  :16;
} dtRTC_WUTR_Bits;

typedef struct sRTC_CR_Bits
{
    uint32 WUCKSEL          :3;
    uint32 TS_EDGE          :1;
    uint32 REFCK_ON         :1;
    uint32 BYP_SHAD         :1;
    uint32 FMT              :1;
    uint32 SSRUIE           :1;
    uint32 ALRAE            :1;
    uint32 ALRBE            :1;
    uint32 WUTE             :1;
    uint32 TSE              :1;
    uint32 ALRA_IE          :1;
    uint32 ALRB_IE          :1;
    uint32 WUTIE            :1;
    uint32 TSIE             :1;
    uint32 ADD1H            :1;
    uint32 SUB1H            :1;
    uint32 BKP              :1;
    uint32 COSEL            :1;
    uint32 POL              :1;
    uint32 OSEL             :2;
    uint32 COE              :1;
    uint32 ITSE             :1;
    uint32 TAMP_TS          :1;
    uint32 TAMP_OE          :1;
    uint32 ALRAFCLR         :1;
    uint32 ALRBFCLR         :1;
    uint32 TAMP_ALRM_PU     :1;
    uint32 TAMP_ALRM_TYPE   :1;
    uint32 OUT2EN           :1;
} dtRTC_CR_Bits;

typedef struct sRTC_WPR_Bits
{
    uint32 KEY  :8;
} dtRTC_WPR_Bits;

typedef struct sRTC_CALR_Bits
{
    uint32 CALM     :9;
    uint32          :3;
    uint32 LPCAL    :1;
    uint32 CALW16   :1;
    uint32 CALW8    :1;
    uint32 CALP     :1;
} dtRTC_CALR_Bits;

typedef struct sRTC_SHIFTR_Bits
{
    uint32 SUBFS    :15;
    uint32          :16;
    uint32 ADD1S    :1;
} dtRTC_SHIFTR_Bits;

typedef struct sRTC_TSTR_Bits
{
    uint32 SU   :4;
    uint32 ST   :3;
    uint32      :1;
    uint32 MNU  :4;
    uint32 MNT  :3;
    uint32      :1;
    uint32 HU   :4;
    uint32 HT   :2;
    uint32 PM   :1;
} dtRTC_TSTR_Bits;

typedef struct sRTC_TSDR_Bits
{
    uint32 DU   :4;
    uint32 DT   :2;
    uint32      :2;
    uint32 MU   :4;
    uint32 MT   :1;
    uint32 WDU  :3;
} dtRTC_TSDR_Bits;

typedef struct sRTC_TSSSR_Bits
{
    uint32 SS   :32;
} dtRTC_TSSSR_Bits;

typedef struct sRTC_ALRMAR_Bits
{
    uint32 SU       :4;
    uint32 ST       :3;
    uint32 MSK1     :1;
    uint32 MNU      :4;
    uint32 MNT      :3;
    uint32 MSK2     :1;
    uint32 HU       :4;
    uint32 HT       :2;
    uint32 PM       :1;
    uint32 MSK3     :1;
    uint32 DU       :4;
    uint32 DT       :2;
    uint32 WDSEL    :1;
    uint32 MSK4     :1;
} dtRTC_ALRMAR_Bits;

typedef struct sRTC_ALRMASSR_Bits
{
    uint32 SS       :15;
    uint32          :9;
    uint32 MASKSS   :6;
    uint32          :1;
    uint32 SSCLR    :1;
} dtRTC_ALRMASSR_Bits;

typedef struct sRTC_ALRMBR_Bits
{
    uint32 SU       :4;
    uint32 ST       :3;
    uint32 MSK1     :1;
    uint32 MNU      :4;
    uint32 MNT      :3;
    uint32 MSK2     :1;
    uint32 HU       :4;
    uint32 HT       :2;
    uint32 PM       :1;
    uint32 MSK3     :1;
    uint32 DU       :4;
    uint32 DT       :2;
    uint32 WDSEL    :1;
    uint32 MSK4     :1;
} dtRTC_ALRMBR_Bits;

typedef struct sRTC_ALRMBSSR_Bits
{
    uint32 SS       :15;
    uint32          :9;
    uint32 MASKSS   :6;
    uint32          :1;
    uint32 SSCLR    :1;
} dtRTC_ALRMBSSR_Bits;

typedef struct sRTC_SR_Bits
{
    uint32 ALRAF    :1;
    uint32 ALRBF    :1;
    uint32 WUTF     :1;
    uint32 TSF      :1;
    uint32 TSOVF    :1;
    uint32 ITSF     :1;
    uint32 SSRUF    :1;
} dtRTC_SR_Bits;

typedef struct sRTC_MISR_Bits
{
    uint32 ALRAMF   :1;
    uint32 ALRBMF   :1;
    uint32 WUTMF    :1;
    uint32 TSMF     :1;
    uint32 TSOVMF   :1;
    uint32 ITSMF    :1;
    uint32 SSRUMF   :1;
} dtRTC_MISR_Bits;

typedef struct sRTC_SCR_Bits
{
    uint32 CALRAF   :1;
    uint32 CALRBF   :1;
    uint32 CWUTF    :1;
    uint32 CTSF     :1;
    uint32 CTSOVF   :1;
    uint32 CITSF    :1;
    uint32 CSSRUF   :1;
} dtRTC_SCR_Bits;

typedef struct sRTC_ALRABINR_Bits
{
    uint32 SS;
} dtRTC_ALRABINR_Bits;

typedef struct sRTC_ALRBBINR_Bits
{
    uint32 SS;
} dtRTC_ALRBBINR_Bits;

REGDEF(RTC, TR)
REGDEF(RTC, DR)
REGDEF(RTC, SSR)
REGDEF(RTC, ICSR)
REGDEF(RTC, PRER)
REGDEF(RTC, WUTR)
REGDEF(RTC, CR)
REGDEF(RTC, WPR)
REGDEF(RTC, CALR)
REGDEF(RTC, SHIFTR)
REGDEF(RTC, TSTR)
REGDEF(RTC, TSDR)
REGDEF(RTC, TSSSR)
REGDEF(RTC, ALRMAR)
REGDEF(RTC, ALRMASSR)
REGDEF(RTC, ALRMBR)
REGDEF(RTC, ALRMBSSR)
REGDEF(RTC, SR)
REGDEF(RTC, MISR)
REGDEF(RTC, SCR)
REGDEF(RTC, ALRABINR)
REGDEF(RTC, ALRBBINR)

typedef struct sRTC
{
    dtRTC_TR        TR;
    dtRTC_DR        DR;
    dtRTC_SSR       SSR;
    dtRTC_ICSR      ICSR;
    dtRTC_PRER      PRER;
    dtRTC_WUTR      WUTR;
    dtRTC_CR        CR;
    uint32 :32;
    uint32 :32;
    dtRTC_WPR       WPR;
    dtRTC_CALR      CALR;
    dtRTC_SHIFTR    SHIFTR;
    dtRTC_TSTR      TSTR;
    dtRTC_TSDR      TSDR;
    dtRTC_TSSSR     TSSSR;
    uint32 :32;
    dtRTC_ALRMAR    ALRMAR;
    dtRTC_ALRMASSR  ALRMASSR;
    dtRTC_ALRMBR    ALRMBR;
    dtRTC_ALRMBSSR  ALRMBSSR;
    dtRTC_SR        SR;
    dtRTC_MISR      MISR;
    uint32 :32;
    dtRTC_SCR       SCR;
    uint32 :32;
    uint32 :32;
    uint32 :32;
    uint32 :32;
    dtRTC_ALRABINR  ALRABINR;
    dtRTC_ALRBBINR  ALRBBINR;
} dtRTC;


#endif /* INC_REGDEFS_RTC_REGDEF_H_ */

#ifndef _ADC_REGDEF_H_
#define _ADC_REGDEF_H_

#include "RegDefs/regdef_helper.h"

#if defined(STM32L4)
typedef struct sADC_ISR_Bits
{
	uint32 ADRDY    :1;
	uint32 EOSMP    :1;
	uint32 EOC      :1;
	uint32 EOS      :1;
	uint32 OVR      :1;
	uint32 JEOC     :1;
	uint32 JEOS     :1;
	uint32 AWD1     :1;
	uint32 AWD2     :1;
	uint32 AWD3     :1;
	uint32 JQOVF    :1;
	uint32          :21;
} dtADC_ISR_Bits;

typedef struct sADC_IER_Bits
{
	uint32 ADRDY    :1;
	uint32 EOSMP    :1;
	uint32 EOC      :1;
	uint32 EOS      :1;
	uint32 OVR      :1;
	uint32 JEOC     :1;
	uint32 JEOS     :1;
	uint32 AWD1     :1;
	uint32 AWD2     :1;
	uint32 AWD3     :1;
	uint32 JQOVF    :1;
	uint32          :21;
} dtADC_IER_Bits;

typedef struct sADC_CR_Bits
{
	uint32 ADEN     :1;
	uint32 ADDIS    :1;
	uint32 ADSTART  :1;
	uint32 JADSTART :1;
	uint32 ADSTP    :1;
	uint32 JADSTP   :1;
	uint32          :22;
	uint32 ADVREGEN :1;
	uint32 DEEPPWD  :1;
	uint32 ADCALDIF :1;
	uint32 ADCAL    :1;
} dtADC_CR_Bits;

typedef struct sADC_CFGR_Bits
{
	uint32 DMAEN    :1;
	uint32 DMACFG   :1;
	uint32 DFSDMCFG :1;
	uint32 RES      :2;
	uint32 ALIGN    :1;
	uint32 EXTSEL   :4;
	uint32 EXTEN    :2;
	uint32 OVRMOD   :1;
	uint32 CONT     :1;
	uint32 AUTDLY   :1;
	uint32          :1;
	uint32 DISCEN   :1;
	uint32 DISCNUM  :3;
	uint32 JDISCEN  :1;
	uint32 JQM      :1;
	uint32 AWD1SGL  :1;
	uint32 AWD1EN   :1;
	uint32 JAWD1EN  :1;
	uint32 JAUTO    :1;
	uint32 AWD1CH   :1;
	uint32 JQDIS    :1;
} dtADC_CFGR_Bits;

typedef struct sADC_CFGR2_Bits
{
	uint32 ROVSE    :1;
	uint32 JOVSE    :1;
	uint32 OVSR     :3;
	uint32 OVSS     :4;
	uint32 TROVS    :1;
	uint32 ROVSM    :1;
	uint32          :21;
} dtADC_CFGR2_Bits;

typedef struct sADC_SMPR1_Bits
{
	uint32 SMP0     :1;
	uint32 SMP1     :1;
	uint32 SMP2     :1;
	uint32 SMP3     :1;
	uint32 SMP4     :1;
	uint32 SMP5     :1;
	uint32 SMP6     :1;
	uint32 SMP7     :1;
	uint32 SMP8     :1;
	uint32 SMP9     :1;
	uint32          :1;
	uint32 SMPPLUS  :1;
} dtADC_SMPR1_Bits;

typedef struct sADC_SMPR2_Bits
{
	uint32 SMP10     :1;
	uint32 SMP11     :1;
	uint32 SMP12     :1;
	uint32 SMP13     :1;
	uint32 SMP14     :1;
	uint32 SMP15     :1;
	uint32 SMP16     :1;
	uint32 SMP17     :1;
	uint32 SMP18     :1;
	uint32          :5;
} dtADC_SMPR2_Bits;

typedef struct sADC_TR1_Bits
{
	uint32 LT1 :12;
	uint32     :4;
	uint32 HT1 :12;
	uint32     :4;
} dtADC_TR1_Bits;

typedef struct sADC_TR2_Bits
{
	uint32 LT2 :8;
	uint32     :8;
	uint32 HT2 :8;
	uint32     :8;
} dtADC_TR2_Bits;

typedef struct sADC_TR3_Bits
{
	uint32 LT3 :8;
	uint32     :8;
	uint32 HT3 :8;
	uint32     :8;
} dtADC_TR3_Bits;

typedef struct sADC_SQR1_Bits
{
	uint32 L  :4;
	uint32    :2;
	uint32 SQ1:5;
	uint32    :1;
	uint32 SQ5:5;
	uint32    :1;
	uint32 SQ3:5;
	uint32    :1;
	uint32 SQ4:5;
	uint32    :3;
} dtADC_SQR1_Bits;

typedef struct sADC_SQR2_Bits
{
	uint32 SQ5:5;
	uint32    :1;
	uint32 SQ6:5;
	uint32    :1;
	uint32 SQ7:5;
	uint32    :1;
	uint32 SQ8:5;
	uint32    :1;
	uint32 SQ9:5;
	uint32    :3;
} dtADC_SQR2_Bits;

typedef struct sADC_SQR3_Bits
{
	uint32 SQ10 :5;
	uint32      :1;
	uint32 SQ11 :5;
	uint32      :1;
	uint32 SQ12 :5;
	uint32      :1;
	uint32 SQ13 :5;
	uint32      :1;
	uint32 SQ14 :5;
	uint32      :3;
} dtADC_SQR3_Bits;

typedef struct sADC_SQR4_Bits
{
	uint32 SQ15 :5;
	uint32      :1;
	uint32 SQ16 :5;
	uint32      :1;
	uint32      :20;
} dtADC_SQR4_Bits;

typedef struct sADC_DR_Bits
{
	uint32 RDATA:16;
    uint32      :16;
} dtADC_DR_Bits;

typedef struct sADC_JSQR_Bits
{
	uint32 JL       :2;
    uint32 JEXTSEL  :4;
    uint32 JEXTEN   :2;
    uint32 JSQ1     :5;
    uint32          :1;
    uint32 JSQ2     :5;
    uint32          :1;
    uint32 JSQ3     :5;
    uint32          :1;
    uint32 JSQ4     :5;
    uint32          :1;
} dtADC_JSQR_Bits;

typedef struct sADC_OFR_Bits
{
	uint32 OFFSET   :12;
    uint32          :14;
    uint32 OFFSET_CH:5;
    uint32 OFFSET_EN:1;
} dtADC_OFR_Bits;

typedef struct sADC_JDR_Bits
{
	uint32 JDATA    :16;
    uint32          :16;
} dtADC_JDR_Bits;

typedef struct sADC_AWD2CR_Bits
{
	uint32 AWD2CH   :16;
    uint32          :16;
} dtADC_AWD2CR_Bits;

typedef struct sADC_AWD3CR_Bits
{
	uint32 AWD3CH   :16;
    uint32          :16;
} dtADC_AWD3CR_Bits;

typedef struct sADC_DIFSEL_Bits
{
	uint32 DIFSEL   :19;
    uint32          :13;
} dtADC_DIFSEL_Bits;

typedef struct sADC_CALFACT_Bits
{
	uint32 CALFACT_S    :7;
    uint32              :9;
    uint32 CALFACT_D    :7;
    uint32              :9;
} dtADC_CALFACT_Bits;

typedef struct sADC_CSR_Bits
{
    uint32 ADRDY_MST    :1;
    uint32 EOSMP_MST    :1;
    uint32 EOC_MST      :1;
    uint32 EOS_MST      :1;
    uint32 OVR_MST      :1;
    uint32 JEOC_MST     :1;
    uint32 JEOS_MST     :1;
    uint32 AWD1_MST     :1;
    uint32 AWD2_MST     :1;
    uint32 AWD3_MST     :1;
    uint32 JQOVF_MST    :1;
    uint32              :5;
    uint32 ADRDY_SLV    :1;
    uint32 EOSMP_SLV    :1;
    uint32 EOC_SLV      :1;
    uint32 EOS_SLV      :1;
    uint32 OVR_SLV      :1;
    uint32 JEOC_SLV     :1;
    uint32 JEOS_SLV     :1;
    uint32 AWD1_SLV     :1;
    uint32 AWD2_SLV     :1;
    uint32 AWD3_SLV     :1;
    uint32 JQOVF_SLV    :1;
    uint32              :5;
} dtADC_CSR_Bits;

typedef struct sADC_CCR_Bits
{
    uint32 DUAL     :5;
    uint32          :3;
    uint32 DELAY    :4;
    uint32          :1;
    uint32 DMACFG   :1;
    uint32 MDMA     :2;
    uint32 CKMODE   :2;
    uint32 PRESC    :4;
    uint32 VREFEN   :1;
    uint32 CH17SEL  :1;
    uint32 CH18SEL  :1;
    uint32          :7;
} dtADC_CCR_Bits;

typedef struct sADC_CDR_Bits
{
    uint32 RDATA_MST    :16;
    uint32 RDATA_SLV    :16;
} dtADC_CDR_Bits;

REGDEF(ADC,ISR)
REGDEF(ADC,IER)
REGDEF(ADC,CR)
REGDEF(ADC,CFGR)
REGDEF(ADC,CFGR2)
REGDEF(ADC,SMPR1)
REGDEF(ADC,SMPR2)
REGDEF(ADC,TR1)
REGDEF(ADC,TR2)
REGDEF(ADC,TR3)
REGDEF(ADC,SQR1)
REGDEF(ADC,SQR2)
REGDEF(ADC,SQR3)
REGDEF(ADC,SQR4)
REGDEF(ADC,DR)
REGDEF(ADC,JSQR)
REGDEF(ADC,OFR)
REGDEF(ADC,JDR)
REGDEF(ADC,AWD2CR)
REGDEF(ADC,AWD3CR)
REGDEF(ADC,DIFSEL)
REGDEF(ADC,CALFACT)
REGDEF(ADC,CSR)
REGDEF(ADC,CCR)
REGDEF(ADC,CDR)

typedef struct sADC1
{
    dtADC_ISR   ISR;    //0x00
    dtADC_IER   IER;    //0x04
    dtADC_CR    CR;     //0x08
    dtADC_CFGR  CFGR;   //0x0C
    dtADC_CFGR2 CFGR2;  //0x10
    dtADC_SMPR1 SMPR1;  //0x14
    dtADC_SMPR2 SMPR2;  //0x18
    uint32      :32;    //0x1C
    dtADC_TR1   TR1;    //0x20
    dtADC_TR2   TR2;    //0x24
    dtADC_TR3   TR3;    //0x28
    uint32      :32;    //0x2C
    dtADC_SQR1  SQR1;   //0x30
    dtADC_SQR2  SQR2;   //0x34
    dtADC_SQR3  SQR3;   //0x38
    dtADC_SQR4  SQR4;   //0x3C
    dtADC_DR    DR;     //0x40
    uint32      :32;    //0x44
    uint32      :32;    //0x48
    dtADC_JSQR  JSQR;   //0x4C
    uint32      :32;    //0x50
    uint32      :32;    //0x54
    uint32      :32;    //0x58
    uint32      :32;    //0x5C
    dtADC_OFR   OFR1;   //0x60
    dtADC_OFR   OFR2;   //0x64
    dtADC_OFR   OFR3;   //0x68
    dtADC_OFR   OFR4;   //0x6C
    uint32      :32;    //0x70
    uint32      :32;    //0x74
    uint32      :32;    //0x78
    uint32      :32;    //0x7C
    dtADC_JDR   JDR1;   //0x80
    dtADC_JDR   JDR2;   //0x84
    dtADC_JDR   JDR3;   //0x88
    dtADC_JDR   JDR4;   //0x8C
    uint32      :32;    //0x90
    uint32      :32;    //0x94
    uint32      :32;    //0x98
    uint32      :32;    //0x9C
    dtADC_AWD2CR    AWD2CR; //0xA0
    dtADC_AWD3CR    AWD3CR; //0xA4
    uint32      :32;        //0xA8
    uint32      :32;        //0xAC
    dtADC_DIFSEL    DIFSEL; //0xB0
    dtADC_CALFACT   CALFACT;//0xB4
} dtADC1;

typedef struct sADC_COM
{
    dtADC_CSR CSR;
    uint32 :32;
    dtADC_CCR CCR;
    dtADC_CDR CDR;
} dtADC_COM;

typedef struct sADC
{
    dtADC1 ADC1;
    uint8 Padding1[0x48];
    uint8 ADC2[0xB8];
    uint8 Padding2[0x48];
    uint8 ADC3[0xB8];
    uint8 Padding3[0x48];
    dtADC_COM COMMON;
} dtADC;
#endif /* defined(STM32L4) */

#endif /* _ADC_REGDEF_H_ */

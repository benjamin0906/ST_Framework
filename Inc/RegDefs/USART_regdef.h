/*
 * USART_regdef.h
 *
 *  Created on: Mar 4, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_USART_REGDEF_H_
#define INC_REGDEFS_USART_REGDEF_H_

#include "RegDefs/regdef_helper.h"

typedef struct sUSART_CR1_Bits
{
    uint32 UE       :1;
    uint32 UESM     :1;
    uint32 RE       :1;
    uint32 TE       :1;
    uint32 IDLEIE   :1;
    uint32 RXFNEIE  :1;
    uint32 TCIE     :1;
    uint32 TXFNFIE  :1;
    uint32 PEIE     :1;
    uint32 PS       :1;
    uint32 PCE      :1;
    uint32 WAKE     :1;
    uint32 M0       :1;
    uint32 MME      :1;
    uint32 CMIE     :1;
    uint32 OVER8    :1;
    uint32 DEDT     :5;
    uint32 DEAT     :5;
    uint32 RTOIE    :1;
    uint32 EOBIE    :1;
    uint32 M1       :1;
    uint32 FIFOEN   :1;
    uint32 TXFEIE   :1;
    uint32 RXFFIE   :1;
} dtUSART_CR1_Bits;

typedef struct sUSART_CR2_Bits
{
    uint32 SLVEN    :1;
    uint32          :2;
    uint32 DIS_NSS  :1;
    uint32 ADDM7    :1;
    uint32 LBDL     :1;
    uint32 LBDIE    :1;
    uint32          :1;
    uint32 LBCL     :1;
    uint32 CPHA     :1;
    uint32 CPOL     :1;
    uint32 CLKEN    :1;
    uint32 STOP     :2;
    uint32 LINEN    :1;
    uint32 SWAP     :1;
    uint32 RXINV    :1;
    uint32 TXINV    :1;
    uint32 DATAINV  :1;
    uint32 MSBFIRST :1;
    uint32 ABREN    :1;
    uint32 ABRMOD   :2;
    uint32 RTOEN    :1;
    uint32 ADD      :8;
} dtUSART_CR2_Bits;

typedef struct sUSART_CR3_Bits
{
    uint32 EIE      :1;
    uint32 IREN     :1;
    uint32 IRLP     :1;
    uint32 HDSEL    :1;
    uint32 NACK     :1;
    uint32 SCEN     :1;
    uint32 DMAR     :1;
    uint32 DMAT     :1;
    uint32 RTSE     :1;
    uint32 CTSE     :1;
    uint32 CTSIE    :1;
    uint32 ONEBIT   :1;
    uint32 OVRDIS   :1;
    uint32 DDRE     :1;
    uint32 DEM      :1;
    uint32 DEP      :1;
    uint32          :1;
    uint32 SCARCNT  :3;
    uint32 WUS      :2;
    uint32 WUFIE    :1;
    uint32 TXFTIE   :1;
    uint32 TCBGTIE  :1;
    uint32 RXFTCFG  :3;
    uint32 RXFTIE   :1;
    uint32 TXFTCFG  :3;
} dtUSART_CR3_Bits;

typedef struct sUSART_BRR_Bits
{
    uint32 BRR  :16;
    uint32      :16;
} dtUSART_BRR_Bits;

typedef struct sUSART_GTPR_Bits
{
    uint32 PSC  :8;
    uint32 GT   :8;
    uint32      :16;
} dtUSART_GTPR_Bits;

typedef struct sUSART_RTOR_Bits
{
    uint32 RTO  :24;
    uint32 BLEN :8;
} dtUSART_RTOR_Bits;

typedef struct sUSART_RQR_Bits
{
    uint32 ABRRQ    :1;
    uint32 SBKRQ    :1;
    uint32 MMRQ     :1;
    uint32 RXFRQ    :1;
    uint32 TXFRQ    :1;
    uint32          :27;
} dtUSART_RQR_Bits;

typedef struct sUSART_ISR_Bits
{
    uint32 PE       :1;
    uint32 FE       :1;
    uint32 NE       :1;
    uint32 ORE      :1;
    uint32 IDLE     :1;
    uint32 RXFNE    :1;
    uint32 TC       :1;
    uint32 TXFNF    :1;
    uint32 LBDF     :1;
    uint32 CTSIF    :1;
    uint32 CTS      :1;
    uint32 RTOF     :1;
    uint32 EOBF     :1;
    uint32 UDR      :1;
    uint32 ABRE     :1;
    uint32 ABRF     :1;
    uint32 BUSY     :1;
    uint32 CMF      :1;
    uint32 SBKF     :1;
    uint32 RWU      :1;
    uint32 WUF      :1;
    uint32 TEACK    :1;
    uint32 REACK    :1;
    uint32 TXFE     :1;
    uint32 RXFF     :1;
    uint32 TCBGT    :1;
    uint32 RXFT     :1;
    uint32 TXFT     :1;
    uint32          :4;
} dtUSART_ISR_Bits;

typedef struct sUSART_ICR_Bits
{
        uint32 PECF     :1;
        uint32 FECF     :1;
        uint32 NECF     :1;
        uint32 ORECF    :1;
        uint32 IDLECF   :1;
        uint32 TXFECF   :1;
        uint32 TCCF     :1;
        uint32 TCBGTCF  :1;
        uint32 LBDCF    :1;
        uint32 CTSCF    :1;
        uint32          :1;
        uint32 RTOCF    :1;
        uint32 EOBCF    :1;
        uint32 UDRCF    :1;
        uint32          :3;
        uint32 CMCF     :1;
        uint32          :2;
        uint32 WUCF     :1;
        uint32          :11;
} dtUSART_ICR_Bits;

typedef struct sUSART_RDR_Bits
{
    uint32 RDR  :9;
    uint32      :23;
} dtUSART_RDR_Bits;

typedef struct sUSART_TDR_Bits
{
    uint32 TDR  :9;
    uint32      :23;
} dtUSART_TDR_Bits;

typedef struct sUSART_PRESC_Bits
{
    uint32 PRESCALER    :4;
    uint32              :28;
} dtUSART_PRESC_Bits;

REGDEF(USART, CR1)
REGDEF(USART, CR2)
REGDEF(USART, CR3)
REGDEF(USART, BRR)
REGDEF(USART, GTPR)
REGDEF(USART, RTOR)
REGDEF(USART, RQR)
REGDEF(USART, ISR)
REGDEF(USART, ICR)
REGDEF(USART, RDR)
REGDEF(USART, TDR)
REGDEF(USART, PRESC)

typedef struct sUSART
{
    dtUSART_CR1     CR1;
    dtUSART_CR2     CR2;
    dtUSART_CR3     CR3;
    dtUSART_BRR     BRR;
    dtUSART_GTPR    GTPR;
    dtUSART_RTOR    RTOR;
    dtUSART_RQR     RQR;
    dtUSART_ISR     ISR;
    dtUSART_ICR     ICR;
    dtUSART_RDR     RDR;
    dtUSART_TDR     TDR;
    dtUSART_PRESC   PRESC;
} dtUSARTx;

#endif /* INC_REGDEFS_USART_REGDEF_H_ */

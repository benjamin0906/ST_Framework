/*
 * SCB_Types.h
 *
 *  Created on: 2023. okt. 19.
 *      Author: Benjamin
 */

#ifndef INC_MEMMAP_TYPES_SCB_TYPES_H_
#define INC_MEMMAP_TYPES_SCB_TYPES_H_

typedef union
{
    uint32 Word;
    struct
    {
        uint32 VECTACTIVE   :CORE_ICSR_VECTACTIVE_WIDTH;    //8-0
        uint32              :1;                             //9
        uint32              :1;                             //10
        uint32 RETTOBASE    :CORE_ICSR_RETTOBASE_WIDTH;     //11
        uint32 VECTPENDING  :CORE_ICSR_VECTPENDING_WIDTH;   //20-12
        uint32              :1;                             //21
        uint32 ISRPENDING   :CORE_ICSR_ISRPENDING_WIDTH;    //22
        uint32 ISRPREEMPT   :CORE_ICSR_ISRPREEMPT_WIDTH;    //23
        uint32              :1;                             //24
        uint32 PENDSTCLR    :CORE_ICSR_PENDSTCLR_WIDTH;     //25
        uint32 PENDSTSET    :CORE_ICSR_PENDSTSET_WIDTH;     //26
        uint32 PENDSVCLR    :CORE_ICSR_PENDSVCLR_WIDTH;     //27
        uint32 PENDSVSET    :CORE_ICSR_PENDSVSET_WIDTH;     //28
        uint32              :1;                             //29
        uint32              :1;                             //30
        uint32 NMIPENDSET   :CORE_ICSR_NMIPENDSET_WIDTH;    //31
    } Field;
} dtICSR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 VECTRESET    :1;
        uint32 VECTCLRACTIVE:1;
        uint32 SYSRESETREQ  :1;
        uint32              :5;
        uint32 PRIGROUP     :3;
        uint32              :4;
        uint32 ENDIANNESS   :1;
        uint32 VECTKEY      :16;
    } Fields;
} dtAIRCR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32              :1;
        uint32 SLEEPONEXIT  :1;
        uint32 SLEEPDEEP    :1;
        uint32              :1;
        uint32 SEVONPEND    :1;
        uint32              :27;
    } Fields;
} dtSCR;

typedef struct
{
    uint32  CPUID;  //0x00
    dtICSR  ICSR;   //0x04
    uint32 :32;     //0x08
    dtAIRCR AIRCR;  //0x0C
    dtSCR   SCR;    //0x10
    uint32  CCR;    //0x14
    uint32  SHPR[3];//0x18..0x20
} dtSCB;

#endif /* INC_MEMMAP_TYPES_SCB_TYPES_H_ */

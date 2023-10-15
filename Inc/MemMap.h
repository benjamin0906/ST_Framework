/*
 * MemMap.h
 *
 *  Created on: 2022. okt. 29.
 *      Author: Benjamin
 */

#ifndef INC_MEMMAP_H_
#define INC_MEMMAP_H_

#include "types.h"

/* defining the number of used priority bits */
#if defined(MCU_L476) | defined(MCU_F446)
#define NVIC_PRIO_BITS  4
#endif

/* NVIC typedef definitions */

typedef struct
{
    uint32 ISER[8];
} dtISER;

typedef struct
{
    uint32 ICER[8];
} dtICER;

typedef struct
{
    uint32 ISPR[8];
} dtISPR;

typedef struct
{
    uint32 ICPR[8];
} dtICPR;

typedef struct
{
    uint32 IABR[8];
} dtIABR;

typedef struct
{
    uint8 PRI[240];
} dtIPR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32          :31;
        uint32 PRIMASK  :1;
    } Fields;
} dtPRIMASK;


/* Core type definitions */

#define CORE_ICSR_NMIPENDSET_WIDTH  1
#define CORE_ICSR_PENDSVSET_WIDTH   1
#define CORE_ICSR_PENDSVCLR_WIDTH   1
#define CORE_ICSR_PENDSTSET_WIDTH   1
#define CORE_ICSR_PENDSTCLR_WIDTH   1
#define CORE_ICSR_ISRPREEMPT_WIDTH  1
#define CORE_ICSR_ISRPENDING_WIDTH  1
#define CORE_ICSR_VECTPENDING_WIDTH 9
#define CORE_ICSR_RETTOBASE_WIDTH   1
#define CORE_ICSR_VECTACTIVE_WIDTH  9

#define CORE_ICSR_NMIPENDSET_PLACE  31
#define CORE_ICSR_PENDSVSET_PLACE   28
#define CORE_ICSR_PENDSVCLR_PLACE   27
#define CORE_ICSR_PENDSTSET_PLACE   26
#define CORE_ICSR_PENDSTCLR_PLACE   25
#define CORE_ICSR_ISRPREEMPT_PLACE  23
#define CORE_ICSR_ISRPENDING_PLACE  22
#define CORE_ICSR_VECTPENDING_PLACE 12
#define CORE_ICSR_RETTOBASE_PLACE   11
#define CORE_ICSR_VECTACTIVE_PLACE  0

#define CORE_ICSR_NMIPENDSET_MASK  (1)<<CORE_ICSR_NMIPENDSET_PLACE
#define CORE_ICSR_PENDSVSET_MASK   (1)<<CORE_ICSR_PENDSVSET_PLACE
#define CORE_ICSR_PENDSVCLR_MASK   (1)<<CORE_ICSR_PENDSVCLR_PLACE
#define CORE_ICSR_PENDSTSET_MASK   (1)<<CORE_ICSR_PENDSTSET_PLACE
#define CORE_ICSR_PENDSTCLR_MASK   (1)<<CORE_ICSR_PENDSTCLR_PLACE
#define CORE_ICSR_ISRPREEMPT_MASK  (1)<<CORE_ICSR_ISRPREEMPT_PLACE
#define CORE_ICSR_ISRPENDING_MASK  (1)<<CORE_ICSR_ISRPENDING_PLACE
#define CORE_ICSR_VECTPENDING_MASK (0x1FF)<<CORE_ICSR_VECTPENDING_PLACE
#define CORE_ICSR_RETTOBASE_MASK   (1)<<CORE_ICSR_RETTOBASE_PLACE
#define CORE_ICSR_VECTACTIVE_MASK  (0x1FF)<<CORE_ICSR_VECTACTIVE_PLACE

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
    uint32  AIRCR;  //0x0C
    dtSCR   SCR;    //0x10
    uint32  CCR;    //0x14
    uint32  SHPR[3];//0x18..0x20
} dtSCB;

extern dtISER *const ISER;
extern dtICER *const ICER;
extern dtISPR *const ISPR;
extern dtICPR *const ICPR;
extern dtIABR *const IABR;
extern dtIPR  *const IPR;

extern dtSCB  *const SCB;

#endif /* INC_MEMMAP_H_ */

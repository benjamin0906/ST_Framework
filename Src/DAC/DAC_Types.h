/*
 * DAC_Types.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Benjamin
 */

#ifndef SRC_DAC_DAC_TYPES_H_
#define SRC_DAC_DAC_TYPES_H_

#include "types.h"

typedef union
{
	uint32 Word;
	struct
	{
		uint32 EN1		:1;
		uint32          :1;
		uint32 TEN1		:1;
		uint32 TSEL     :3;
		uint32 WAVE1    :2;
		uint32 MAMP1    :4;
		uint32 DMAEN1   :1;
		uint32 DMAUDRIE1:1;
		uint32 CEN1     :1;
		uint32          :1;
		uint32 EN2      :1;
		uint32          :1;
		uint32 TEN2     :1;
		uint32 TSEL2    :3;
		uint32 WAVE2    :2;
		uint32 MAMP2    :4;
		uint32 DMAEN2   :1;
		uint32 DMAUDRIE2:1;
		uint32 CEN2     :1;
	} Fields;
} dtDAC_CR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 SWTRIG1  :1;
        uint32 SWTRIG2  :1;
	} Fields;
} dtDAC_SWTRGR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC1DHR :12;
    } Fields;
} dtDAC_DHR12R1;

typedef union
{
    uint32 Word;
    struct
    {
        uint32          :4;
        uint32 DACC1DHR :12;
    } Fields;
} dtDAC_DHR12L1;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC1DHR :8;
    } Fields;
} dtDAC_DHR8R1;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC2DHR :12;
    } Fields;
} dtDAC_DHR12R2;

typedef union
{
    uint32 Word;
    struct
    {
        uint32          :4;
        uint32 DACC2DHR :12;
    } Fields;
} dtDAC_DHR12L2;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC2DHR :8;
    } Fields;
} dtDAC_DHR8R2;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC1DHR :12;
        uint32          :4;
        uint32 DACC2DHR :12;
    } Fields;
} dtDAC_DHR12RD;

typedef union
{
    uint32 Word;
    struct
    {
        uint32          :4;
        uint32 DACC1DHR :12;
        uint32          :4;
        uint32 DACC2DHR :12;
    } Fields;
} dtDAC_DHR12LD;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC1DHR :8;
        uint32 DACC2DHR :8;
    } Fields;
} dtDAC_DHR8RD;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC1DOR :12;
    } Fields;
} dtDAC_DOR1;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 DACC2DOR :12;
    } Fields;
} dtDAC_DOR2;

typedef union
{
    uint32 Word;
    struct
    {
        uint32          :13;
        uint32 DMAUDR1  :1;
        uint32 CAL_FLAG1:1;
        uint32 BWST1    :1;
        uint32          :13;
        uint32 DMAUDR2  :1;
        uint32 CAL_FLAG2:1;
        uint32 BWST2    :1;
    } Fields;
} dtDAC_SR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 OTRIM1   :5;
        uint32          :11;
        uint32 OTRIM2   :5;
        uint32          :11;
    } Fields;
} dtDAC_CCR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 MODE1    :3;
        uint32          :13;
        uint32 MODE2    :3;
    } Fields;
} dtDAC_MCR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 TSAMPLE1 :10;
    } Fields;
} dtDAC_SHSR1;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 TSAMPLE2 :10;
    } Fields;
} dtDAC_SHSR2;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 THOLD1   :10;
        uint32          :6;
        uint32 THOLD2   :10;
    } Fields;
} dtDAC_SHHR;

typedef union
{
    uint32 Word;
    struct
    {
        uint32 TREFRESH1    :8;
        uint32              :8;
        uint32 TREFRESH2    :8;
    } Fields;
} dtDAC_SHRR;

typedef struct
{
    dtDAC_DAC_CR    DAC_CR; //00
    dtDAC_SWTRGR    SWTRGR; //04
    dtDAC_DHR12R1   DHR12R1;//08
    dtDAC_DHR12L1   DHR12L1;//0C
    dtDAC_DHR8R1    DHR8R1; //10
    dtDAC_DHR12R2   DHR12R2;//14
    dtDAC_DHR12L2   DHR12L2;//18
    dtDAC_DHR8R2    DHR8R2; //1C
    dtDAC_DHR12RD   DHR12RD;//20
    dtDAC_DHR12LD   DHR12LD;//24
    dtDAC_DHR8RD    DHR8RD; //28
    dtDAC_DOR1  DOR1;
    dtDAC_DOR2  DOR2;
    dtDAC_SR    SR;
    dtDAC_CCR   CCR;
    dtDAC_MCR   MCR;
    dtDAC_SHSR1 SHSR1;
    dtDAC_SHSR2 SHSR2;
    dtDAC_SHHR  SHHR;
    dtDAC_SHRR  SHRR;
} dtDAC;

#endif /* SRC_DAC_DAC_TYPES_H_ */

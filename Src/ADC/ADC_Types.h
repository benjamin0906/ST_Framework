/*
 * ADC_Types.h
 *
 *  Created on: 2021. febr. 14.
 *      Author: Benjamin
 */

#ifndef SRC_ADC_ADC_TYPES_H_
#define SRC_ADC_ADC_TYPES_H_

#include "types.h"

typedef union
{
	uint32 Word;
	struct
	{
		uint32 ADRDY	:1;
		uint32 EOSMP	:1;
		uint32 EOC		:1;
		uint32 EOS		:1;
		uint32 OVR		:1;
		uint32 			:2;
		uint32 AWD1		:1;
		uint32 AWD2		:1;
		uint32 AWD3		:1;
		uint32 			:1;
		uint32 EOCAL	:1;
		uint32 			:1;
		uint32 CCRDY	:1;
	} Fields;
} dtADC_ISR;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 ADRDYIE	:1;
		uint32 EOSMPIE	:1;
		uint32 EOCIE	:1;
		uint32 EOSIE	:1;
		uint32 OVRIE	:1;
		uint32 			:2;
		uint32 AWD1IE	:1;
		uint32 AWD2IE	:1;
		uint32 AWD3IE	:1;
		uint32 			:1;
		uint32 EOCALIE	:1;
		uint32 			:1;
		uint32 CCRDYIE	:1;
	} Fields;
} dtADC_IER;

typedef union
{
	uint32 Word;
	struct
	{
		uint32 ADEN		:1;
		uint32 ADDIS	:1;
		uint32 ADSTART	:1;
		uint32 			:1;
		uint32 ADSTP	:1;
		uint32 			:23;
		uint32 ADVREGEN	:1;
		uint32 			:2;
		uint32 ADCAL	:1;
	} Fields;
} dtADC_CR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_CFGR1;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_CFGR2;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_SMPR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_AWD1TR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_AWD2TR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_CHSELR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_AWD3TR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_DR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_AWD2CR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_AWD3CR;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_CALFACT;

typedef union
{
	uint32 Word;
	struct
	{

	} Fields;
} dtADC_CCR;

#endif /* SRC_ADC_ADC_TYPES_H_ */

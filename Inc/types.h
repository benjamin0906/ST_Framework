/*
 * types.h
 *
 *  Created on: May 1, 2020
 *      Author: Bodnár Benjamin
 */

#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned long long 	uint64;
typedef unsigned long		uint32;
typedef unsigned short		uint16;
typedef unsigned char		uint8;
typedef signed long 		int32;
typedef signed short		int16;
typedef signed char			int8;

typedef float				float32;

/* This structure stores the members of a time in BCD */
typedef struct
{
	uint32 HourTens		:4;
	uint32 HourUnits	:4;
	uint32 MinTens		:4;
	uint32 MinUnits		:4;
	uint32 SecTens		:4;
	uint32 SecUnits		:4;
} dtTime;

#endif /* TYPES_H_ */

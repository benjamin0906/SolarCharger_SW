/* 
 * File:   Timer0_Types.h
 * Author: Bodnár Benjamin
 *
 * Created on 12 August 2020, 17:13
 */

#ifndef TIMER0_TYPES_H
#define	TIMER0_TYPES_H

#include "types.h"

typedef union
{
	uint8 Byte;
	struct
	{
		uint8 T0OUTPS	:4;
		uint8 T016BIT	:1;
		uint8 T0OUT		:1;
		uint8			:1;
		uint8 T0EN		:1;
	}Fields;
} dtT0CON0;

typedef union
{
	uint8 Byte;
	struct
	{
		uint8 T0CKPS	:4;
		uint8 T0ASYNC	:1;
		uint8 T0CS		:3;
	}Fields;
} dtT0CON1;

typedef union
{
	uint16 TMR0;
	struct
	{
		uint8 TMR0L;
		uint8 TMR0H;
	} Fields;
} dtTMR;

#endif	/* TIMER0_TYPES_H */


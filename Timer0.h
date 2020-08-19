/* 
 * File:   Timer0.h
 * Author: Bodnár Benjamin
 *
 * Created on 12 August 2020, 17:13
 */

#ifndef TIMER0_H
#define	TIMER0_H

#include "types.h"

typedef struct
{
    uint8 TimerBit  :1;
    uint8 Postscaler:4;
    uint8 ClockSrc  :3;
    uint8 Prescaler :4;
} dtTimer0Config;

enum eTimerBit
{
    EightBitTimer   = 0,
    SixteenBitTimer,
};

enum ePostscaler
{
    PostScale_1     = 0,
    PostScale_2,
    PostScale_3,
    PostScale_4,
    PostScale_5,
    PostScale_6,
    PostScale_7,
    PostScale_8,
    PostScale_9,
    PostScale_10,
    PostScale_11,
    PostScale_12,
    PostScale_13,
    PostScale_14,
    PostScale_15,
    PostScale_16,
};

enum eClockSrc
{
    Src_T0CKIPPS        = 0,
    Src_T0CKIPPS_inv,
    Src_FoscDivFour,
    Src_HFINTOSC,
    Src_LFINTOSC,
    Src_MFINTOSC,
    Src_SOSC,
    Src_CLC1_out,
};

enum ePrescaler
{
    Prescaler_1     = 0,
    Prescaler_2,
    Prescaler_4,
    Prescaler_8,
    Prescaler_16,
    Prescaler_32,
    Prescaler_64,
    Prescaler_128,
    Prescaler_256,
    Prescaler_512,
    Prescaler_1024,
    Prescaler_2048,
    Prescaler_4096,
    Prescaler_8192,
    Prescaler_16384,
    Prescaler_32768,
};

extern void Timer0_Init(dtTimer0Config Config ,uint16 TMR);
extern uint8 Timer0_Set(uint8 value);

#endif	/* TIMER0_H */


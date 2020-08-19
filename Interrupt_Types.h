/* 
 * File:   Interrupt_Types.h
 * Author: Bodnár Benjamin
 *
 * Created on 07 August 2020, 19:55
 */

#ifndef INTERRUPT_TYPES_H
#define	INTERRUPT_TYPES_H

#include "types.h"

typedef struct
{
    uint8 INTEDG:1;
    uint8       :5;
    uint8 PEIE  :1;
    uint8 GIE   :1;
}dtINTCON;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 INTE      :1;
        uint8           :3;
        uint8 IOCIE     :1;
        uint8 TMR0IE    :1;
        uint8           :2;
    }Fields;
} dtPIE0;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 INTE      :1;
        uint8           :3;
        uint8 IOCIE     :1;
        uint8 TMR0IE    :1;
        uint8           :2;
    }Fields;
} dtPIR0;

#endif	/* INTERRUPT_TYPES_H */


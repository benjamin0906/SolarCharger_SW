/* 
 * File:   ADC_Types.h
 * Author: Bodnár Benjamin
 *
 * Created on 27 July 2020, 19:03
 */

#ifndef ADC_TYPES_H
#define	ADC_TYPES_H

#include "types.h"

typedef union
{
    struct
    {
        uint8   GO      :1;
        uint8           :1;
        uint8   FRM     :1;
        uint8           :1;
        uint8   CS      :1;
        uint8           :1;
        uint8   CONT    :1;
        uint8   ON      :1;
    } Fields;
    uint8 Byte;
} dtADCCON0;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 DSEN  :1;
        uint8       :4;
        uint8 GPOL  :1;
        uint8 IPEN  :1;
        uint8 PPOL  :1;
    } Fields;
} dtADCCON1;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 MD    :3;
        uint8 ACLR  :1;
        uint8 CRS   :3;
        uint8 PSIS  :1;
    } Fields;
} dtADCCON2;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 TMD   :3;
        uint8 SOI   :1;
        uint8 CALC  :3;
    } Fields;
} dtADCCON3;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 STAT  :3;
        uint8       :1;
        uint8 MATH  :1;
        uint8 LTHR  :1;
        uint8 UTHR  :1;
        uint8 OV    :1;
    } Fields;
} dtADSTAT;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 PREF  :2;
        uint8       :2;
        uint8 NREF  :1;
        uint8       :3;
    } Fields;
} dtADREF;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 CPRDY :1;
        uint8       :6;
        uint8 CPON  :1;
    } Fields;
} dtADCPCON0;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 PCH   :6;
        uint8       :2;
    } Fields;
} dtADPCH;

typedef union
{
    uint16 Word;
    struct
    {
        uint8 ACQL;
        uint8 ACQH  :5;
        uint8       :3;
    } Fields;
} dtADACQ;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 CAP   :5;
        uint8       :3;
    } Fields;
} dtADCAP;

typedef union
{
    uint16 Word;
    struct
    {
        uint8 PREL;
        uint8 PREH  :5;
        uint8      :3;
    };
} dtADPRE;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 CS    :6;
        uint8       :2;
    } Fields;
} dtADCLK;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 ACT   :5;
        uint8       :3;
    } Fields;
} dtADACT;

typedef struct
{
    uint16 ACCL;
    uint8 ACCH  :2;
    uint8       :6;
} dtADACC;

#endif	/* ADC_TYPES_H */


/* 
 * File:   FCR_Types.h
 * Author: Bodnár Benjamin
 *
 * Created on 04 August 2020, 18:47
 */

#ifndef FCR_TYPES_H
#define	FCR_TYPES_H

#include "types.h"

typedef struct
{
    uint8 ADFVR :2;
    uint8 CDAFVR:2;
    uint8 TSRNG :1;
    uint8 TSEN  :1;
    uint8 FVRRDY:1;
    uint8 FVREN :1;
} dtFVRCON;

#endif	/* FCR_TYPES_H */


/* 
 * File:   Interrupt.h
 * Author: Bodnár Benjamin
 *
 * Created on 12 August 2020, 17:41
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include "types.h"

extern void Interrupt_Init(void (*Handler)(void));

#endif	/* INTERRUPT_H */


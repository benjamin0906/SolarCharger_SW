/*
 * File:   main.c
 * Author: Bodnár Benjamin
 *
 * Created on 25 July 2020, 17:39
 */


#include <xc.h>

void main(void) 
{
    TRISC = 0;
    LATC = 0x55;
    while(1);
    return;
}

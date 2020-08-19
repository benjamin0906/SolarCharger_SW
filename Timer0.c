#include "Timer0_Types.h"
#include "Timer0.h"

static dtTMR 	*const TMR0 	= (dtTMR*)(0x59C);
static dtT0CON0 *const T0CON0 	= (dtT0CON0*)(0x59E);
static dtT0CON1 *const T0CON1 	= (dtT0CON1*)(0x59F);

void Timer0_Init(dtTimer0Config Config ,uint16 TMR);
uint8 Timer0_Set(uint8 value);

void Timer0_Init(dtTimer0Config Config ,uint16 TMR)
{
    T0CON0->Fields.T0EN = 0;
    T0CON1->Fields.T0CKPS = Config.Prescaler;
    T0CON1->Fields.T0CS = Config.ClockSrc;
    T0CON1->Fields.T0ASYNC = 1;
    T0CON0->Fields.T016BIT = Config.TimerBit;
    T0CON0->Fields.T0OUTPS = Config.Postscaler;
    if(T0CON0->Fields.T016BIT == 0) TMR0->TMR0 = TMR<<8;
    else TMR0->TMR0 = TMR;
    T0CON0->Fields.T0EN = 1;
}

uint8 Timer0_Set(uint8 value)
{
    TMR0->Fields.TMR0H = value;
}
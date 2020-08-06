#include "types.h"

static uint16 *const TMR0 = (uint16*)(0x59C);
static uint8 *const T0CON0 = (uint8*)(0x59E);
static uint8 *const T0CON1 = (uint8*)(0x59F);

void Timer0_Init(void);
uint8 Timer0_Set(uint8 value);

void Timer0_Init(void)
{
    *TMR0 = 250;
    *T0CON0 = 0x89;
}

uint8 Timer0_Set(uint8 value)
{
    *TMR0 = value;
}
#include "Interrupt_Types.h"

static dtINTCON *const INTCON   = (dtINTCON*)(0x00B);
static dtPIE0   *const PIE0     = (dtPIE0*)(0x716);
static dtPIR0   *const PIR0     = (dtPIR0*)(0x70C);
static void (*IntHandler)(void);

void Interrupt_Init(void (*Handler)(void));

__interrupt() void ISRHandler(void)
{
    PIR0->Fields.TMR0IE = 0;
    if(IntHandler != 0) IntHandler();
}

void Interrupt_Init(void (*Handler)(void))
{
    INTCON->PEIE = 1;
    INTCON->GIE = 1;
    IntHandler = Handler;
    PIE0->Fields.TMR0IE = 1;
}

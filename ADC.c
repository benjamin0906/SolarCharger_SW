
#include "ADC_Types.h"


static uint16       *ADLTH      = (uint16*)(0x8C);
static uint16       *ADUTH      = (uint16*)(0x8E);
static uint16       *ADERR      = (uint16*)(0x90);
static uint16       *ADSTPT     = (uint16*)(0x92);
static uint16       *ADFLTR     = (uint16*)(0x94);
static dtADACC      *ADACC      = (dtADACC*)(0x96);
static uint8        *ADCNT      = (uint8*)(0x99);
static uint8        *ADRPT      = (uint8*)(0x9A);
static uint16       *ADPREV     = (uint16*)(0x9B);
static uint16       *ADRES      = (uint16*)(0x9D);
static dtADPCH      *ADPCH      = (dtADPCH*)(0x9F);
struct dtADACQ      *ADACQ      = (dtADACQ*)(0x10C);
static dtADCAP      *ADCAP      = (dtADCAP*)(0x10E);
static dtADPRE      *ADPRE      = (dtADPRE*)(0x10F);
static dtADCCON0    *ADCCON0    = (dtADCCON0*)(0x111);
static dtADCCON1    *ADCCON1    = (dtADCCON1*)(0x112);
static dtADCCON2    *ADCCON2    = (dtADCCON2*)(0x113);
static dtADCCON3    *ADCCON3    = (dtADCCON3*)(0x114);
static dtADSTAT     *ADSTAT     = (dtADSTAT*)(0x115);
static dtADREF      *ADREF      = (dtADREF*)(0x116);
static dtADACT      *ADACT      = (dtADACT*)(0x117);
static dtADCLK      *ADCLK      = (dtADCLK*)(0x118);
static dtADCPCON0   *ADCPCON0   = (dtADCPCON0*)(0x29F);

void ADC_Init(void);
void ADC_StartConversion(void);
uint8 ADC_ConversionReady(void);
uint16 ADC_GetValue(void);

void ADC_Init(void)
{
    ADCCON0->Fields.FRM = 1;
    ADCCON0->Fields.CS = 1;
    ADCCON0->Fields.ON = 1;
    ADREF->Fields.NREF = 0;
    ADREF->Fields.PREF = 3;
    ADPCH->Fields.PCH = 0x3F;//FVR2
    ADPCH->Fields.PCH = 0x3E;//FVR1
    ADPCH->Fields.PCH = 0x15;//RC5
    ADPCH->Fields.PCH = 0x01;//RC5
    
}

void ADC_StartConversion(void)
{
    ADCCON0->Fields.GO = 1;
}

uint8 ADC_ConversionReady(void)
{
    return ADCCON0->Fields.GO == 0;
}

uint16 ADC_GetValue(void)
{
    return *ADRES;
}
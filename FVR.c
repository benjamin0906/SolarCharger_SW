#include "FVR_Types.h"

static dtFVRCON *const FVRCON = (dtFVRCON*)(0x90C);

void FVR_Init(void);

void FVR_Init(void)
{
    FVRCON->ADFVR = 1;
    FVRCON->CDAFVR =0;
    FVRCON->TSRNG = 0;
    FVRCON->TSEN = 0;
    FVRCON->FVREN = 1;
    while(FVRCON->FVRRDY == 0);
}
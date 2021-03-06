#include "Ports_Types.h"
#include "Ports.h"

static uint8 *const LATs[3] = {(uint8*)0x18, (uint8*)0x19, (uint8*)0x1A};
static uint8 *const TRISs[3]= {(uint8*)0x12, (uint8*)0x13, (uint8*)0x14};
static uint8 *const PORTs[3]= {(uint8*)0x0C, (uint8*)0x0D, (uint8*)0x0E};
static uint8 *const ANSELs[3]= {(uint8*)0x1F38, (uint8*)0x1F43, (uint8*)0x1F4E};


const dtGPIO PINA0  = {0x0,0x0};
const dtGPIO PINA1  = {0x0,0x1};
const dtGPIO PINA2  = {0x0,0x2};
const dtGPIO PINA3  = {0x0,0x3};
const dtGPIO PINA4  = {0x0,0x4};
const dtGPIO PINA5  = {0x0,0x5};
const dtGPIO PINA6  = {0x0,0x6};
const dtGPIO PINA7  = {0x0,0x7};
const dtGPIO PINB0  = {0x1,0x0};
const dtGPIO PINB1  = {0x1,0x1};
const dtGPIO PINB2  = {0x1,0x2};
const dtGPIO PINB3  = {0x1,0x3};
const dtGPIO PINB4  = {0x1,0x4};
const dtGPIO PINB5  = {0x1,0x5};
const dtGPIO PINB6  = {0x1,0x6};
const dtGPIO PINB7  = {0x1,0x7};
const dtGPIO PINC0  = {0x2,0x0};
const dtGPIO PINC1  = {0x2,0x1};
const dtGPIO PINC2  = {0x2,0x2};
const dtGPIO PINC3  = {0x2,0x3};
const dtGPIO PINC4  = {0x2,0x4};
const dtGPIO PINC5  = {0x2,0x5};
const dtGPIO PINC6  = {0x2,0x6};
const dtGPIO PINC7  = {0x2,0x7};

const dtGPIO PIND0  = {0x3,0x0};
const dtGPIO PIND1  = {0x3,0x1};
const dtGPIO PIND2  = {0x3,0x2};
const dtGPIO PIND3  = {0x3,0x3};
const dtGPIO PIND4  = {0x3,0x4};

const dtGPIO PINE0  = {0x4,0x0};
const dtGPIO PINE1  = {0x4,0x1};

void GpioOut(dtGPIO GPIO, uint8 State);
uint8 GpioIn(dtGPIO GPIO);
void GpioToggle(dtGPIO GPIO);
void GpioDir(dtGPIO GPIO, uint8 Dir);

void GpioOut(dtGPIO GPIO, uint8 State)
{
    if(State != 0)
    {
        /* If the pin should be high one will ORing to the register */
        *LATs[GPIO.Port] |= 1<<GPIO.Pin;
    }
    else
    {
        /* If the pin should be low the desired bit will be set to null. */
        *LATs[GPIO.Port] &= ~(1<<GPIO.Pin);
    }
}

void GpioDir(dtGPIO GPIO, uint8 Dir)
{
	if((Dir == 2) || (Dir == 1))
	{
		*TRISs[GPIO.Port] |= 1<<GPIO.Pin;
		if(Dir == 2) *ANSELs[GPIO.Port] |= 1<<GPIO.Pin;
	}
    else
    {
        /* If the pin should be input one will ORing to the register */
        *TRISs[GPIO.Port] &= ~(1<<GPIO.Pin);
    }
}

void GpioToggle(dtGPIO GPIO)
{
    if((*PORTs[GPIO.Port] & (1<<GPIO.Pin)) != 0) *LATs[GPIO.Port] &= ~(1<<GPIO.Pin);
    else *LATs[GPIO.Port] |= (1<<GPIO.Pin);
}

uint8 GpioIn(dtGPIO GPIO)
{
    uint8 ret = 0;
    if((*PORTs[GPIO.Port] & (1<<GPIO.Pin)) != 0) ret = 1;
    return ret;
}
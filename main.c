/*
 * File:   main.c
 * Author: Bodnár Benjamin
 *
 * Created on 25 July 2020, 17:39
 */

#include "types.h"
#include "Ports.h"
#include "FVR.h"
#include "Timer0.h"
#include "Interrupt.h"

typedef enum
{
	SetLeds,
	ClearLeds,
} dtIdleSm;

// CONFIG1
#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits (Oscillator not enabled)
#pragma config RSTOSC = EXT1X   // Power-up default value for COSC bits (EXTOSC operating per FEXTOSC bits)
#pragma config CLKOUTEN = OFF   // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)
//#pragma config DEBUG = OFF

// CONFIG2
#pragma config MCLRE = ON       // Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTS = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN = ON       // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 2.45V)
#pragma config ZCDDIS = OFF     // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4
#pragma config BBSIZE = BB512   // Boot Block Size Selection bits (512 words boot block size)
#pragma config BBEN = OFF       // Boot Block Enable bit (Boot Block disabled)
#pragma config SAFEN = OFF      // SAF Enable bit (SAF disabled)
#pragma config WRTAPP = OFF     // Application Block Write Protection bit (Application Block not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not write protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration Register not write protected)
#pragma config WRTD = OFF       // Data EEPROM write protection bit (Data EEPROM NOT write protected)
#pragma config WRTSAF = OFF     // Storage Area Flash Write Protection bit (SAF not write protected)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)

// CONFIG5
#pragma config CP = OFF         // UserNVM Program memory code protection bit (UserNVM code protection disabled)

#define EIGHTYTREE_PERC_VALUE   3699
#define SIXTYSIX_PERC_VALUE    3538
#define FIFTY_PERC_VALUE   3423
#define THIRTYTREE_PERC_VALUE   3245
#define SIXTEEN_PERC_VALUE   3283

extern void ADC_Init(void);
extern void ADC_StartConversion(void);
extern uint8 ADC_ConversionReady(void);
extern uint16 ADC_GetValue(void);

dtIdleSm IdleState;
uint8 TimerValue = 100;
void IdleStateMachine(void)
{
	switch(IdleState)
	{
		case SetLeds:
		{
			uint16 value = ADC_GetValue();
			ADC_StartConversion();
            TimerValue = 100;
			if(value >= EIGHTYTREE_PERC_VALUE) GpioOut(PINC4,1);
			else GpioOut(PINC4,0);
			if(value >= SIXTYSIX_PERC_VALUE) GpioOut(PINC3,1);
			else GpioOut(PINC3,0);
			if(value >= FIFTY_PERC_VALUE) GpioOut(PINC2,1);
			else GpioOut(PINC2,0);
			if(value >= THIRTYTREE_PERC_VALUE) GpioOut(PINC1,1);
			else GpioOut(PINC1,0);
			GpioOut(PINC0,1);
			if(value < SIXTEEN_PERC_VALUE) TimerValue = 25;
			IdleState = ClearLeds;
            Timer0_Set(2);
		}
		break;
		case ClearLeds:
		GpioOut(PINC0,0);
		GpioOut(PINC1,0);
		GpioOut(PINC2,0);
		GpioOut(PINC3,0);
		GpioOut(PINC4,0);
        IdleState = SetLeds;
        Timer0_Set(TimerValue);
		break;
	}
}

void main(void) 
{
    uint16 value = 0;
    (*((uint8*)0x88D)) = 0x60;
    GpioDir(PINA1,2);
    GpioDir(PINC5,2);
    GpioDir(PINC0,0);
    GpioDir(PINC1,0);
    GpioDir(PINC2,0);
    GpioDir(PINC3,0);
    GpioDir(PINC4,0);
    
    GpioOut(PINC0,0);
    GpioOut(PINC1,0);
    GpioOut(PINC2,0);
    GpioOut(PINC3,0);
    GpioOut(PINC4,0);
    FVR_Init();
    ADC_Init();
    ADC_StartConversion();
    {
        dtTimer0Config config = {.ClockSrc = Src_LFINTOSC, .Postscaler = PostScale_10, .Prescaler = Prescaler_64, .TimerBit = EightBitTimer};
        Timer0_Init(config, 10);
    }
    Interrupt_Init(&IdleStateMachine);
    while(1)
    {
        asm("SLEEP");
    }
    return;
}

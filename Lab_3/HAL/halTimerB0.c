#include <msp430.h>
#include "halTimerB0.h"

void halTimerB0Init(void)
{
    //TB0CCR0 = 24999; // SMCLKFreq 2.5MHz * 0,01 s = 25000 (-1)

    TB0CCR0 = TB0CCR0_VALUE;
    TB0EX0 = TBIDEX__8; // Divider expansion
    TB0CCTL0 = CCIE; // Capture/compare interrupt enable

    TB0CTL = TBSSEL__SMCLK | ID__8 | MC__UP | TBCLR; //SMCLK als Quelle, Input divider, Up-Mode, Timer_B clear
}

#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void)
{
    //if (TB0CCTL0 & CCIFG) //Interrupt-Flag is up?
    //{
        P8OUT ^= BIT0; //Toggle --> XOR --> Zustand LCD-Hinterbeleuchtung invertieren (Hintergrundbeleuchtung bei jedem Aufruf ein- und ausgeschaltet wird)
    //}
}

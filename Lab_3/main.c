#include <msp430.h> 
#include "halGeneral.h"
#include "halGpio.h"

#define RUN_TESTS                   // auskommentieren für den Normalbetrieb

#ifdef RUN_TESTS
#include "testHalGeneral.h"
#endif

extern volatile ButtonCom CCButton;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    halInit();

#ifdef RUN_TESTS
    halInitTest();
#endif

    while (1)
    {
//        if (CCButton.active == 1)
//        {
//            if (CCButton.button == START_BUTTON)
//            {
//                P8OUT |= BIT0;
//            }
//            else if (CCButton.button == STOP_BUTTON)
//            {
//                P8OUT &= ~BIT0;
//            }
//
//            CCButton.active = 0; //Flag löschen
//        }
    }

    //return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    // Überprüfen, ob das erwartete Flag gesetzt ist
    if (P1IFG & START_BUTTON)
    {
        // → gewünschte Reaktion (z. B. Flag setzen, Aktion auslösen)
        CCButton.active=1;
        CCButton.button=START_BUTTON;

        // Interrupt-Flag löschen
        P1IFG &= ~START_BUTTON;
    }

    if (P1IFG & STOP_BUTTON)
        {

        CCButton.active=1;
        CCButton.button=STOP_BUTTON;

        P1IFG &= ~STOP_BUTTON;
        }
}

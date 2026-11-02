#include <msp430.h>
#include "halUCS.h"

void halUCSInit(void)//Der Oszillator XT2 wird aktiviert, Fehlerflags werden gelöscht, und die Systemtakte (MCLK, SMCLK) werden auf die Quarzquelle umgelegt. Der korrekte Betrieb wird durch Abfrage der Fault-Flags abgesichert.
    {
        UCSCTL6 &= ~XT2OFF;             // XT2 einschalten
        UCSCTL3 |= SELREF_2;            // FLL Referenz = REFO
        UCSCTL4 |= SELA_2;              // ACLK = REFO

        // Warten bis Fehlerflags gelöscht sind
        while (SFRIFG1 & OFIFG)
        {
            UCSCTL7 &= ~(XT2OFFG + DCOFFG + XT1HFOFFG + XT1LFOFFG);
            SFRIFG1 &= ~OFIFG;
        }

        UCSCTL6 &= ~XT2DRIVE_3;         // Drive-Strength-Feld löschen
        UCSCTL6 |=  XT2DRIVE_2;         // und nach dem Anlauf reduziert setzen

        UCSCTL4 |= SELS__XT2CLK;        // SMCLK = XT2
        UCSCTL4 |= SELM__XT2CLK;        // MCLK  = XT2

        UCSCTL5 |= DIVS_3;              // SMCLK Divider /8
    }

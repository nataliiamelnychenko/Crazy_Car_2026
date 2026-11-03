#include <msp430.h>
#include "halUCS.h"

void halUCSInit(void)//Oszi XT2 aktiviert, Fehlerflags gelöscht, Systemtakte MCLK, SMCLK auf die Quarzquelle umgelegt, korrekte Betrieb durch Abfrage der Fault-Flags abgesichert.
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

#include <msp430.h>
#include "halGpio.h"

extern volatile ButtonCom CCButton;

void halGpioInit(void) {


//Richtung aller beschalteten Pins gemäß ihrer Funktion setzen:
P1DIR &= ~(RPM_SENSOR | RPM_SENSOR_DIR | START_BUTTON | STOP_BUTTON);
P1DIR |= I2C_INT_MOTION;


//Ausgänge initial mit definiertem Pegel belegen:
P1OUT &= ~I2C_INT_MOTION;


//Pull-Ups/-Downs für Eingänge aktivieren:
P1REN |= (START_BUTTON | STOP_BUTTON);//aktivieren
P1OUT |= (START_BUTTON | STOP_BUTTON);//auswählen - 1 für Steigende Flanke


//Unbenutzte Pins als digitale Ausgänge(P1DIR) mit Low-Pegel(P1OUT) konfigurieren (mit Ground verbunden):
P1DIR |= (BIT0 | BIT1 | BIT2);
P1OUT &= ~(BIT0 | BIT1 | BIT2);

//Activierung Interrupts für Start- und Stopptaste:
P1IES |= (START_BUTTON | STOP_BUTTON); //Interrupt Edge Selekt, 3.3-->0 falling edge
P1IFG &= ~(START_BUTTON | STOP_BUTTON); //Interrupt Flag löschen
P1IE |= (START_BUTTON | STOP_BUTTON); //Interrupt aktivieren

//für LCD_BL:
P8DIR |= (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7); //Ausgang (1)
P8OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7); //deaktiviert(0)

}

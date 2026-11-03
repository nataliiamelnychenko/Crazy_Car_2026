#ifndef HALTIMERB0_H
#define HALTIMERB0_H

#include "halUCS.h"

#define TIMER_FREQU (2*2) //2 mal pro periode im 2Hz Takt
#define DIVIDER 32 //8*4
#define TB0CCR0_VALUE ((SMCLK_FREQU/DIVIDER/TIMER_FREQU)-1) //19530

void halTimerB0Init();

#endif

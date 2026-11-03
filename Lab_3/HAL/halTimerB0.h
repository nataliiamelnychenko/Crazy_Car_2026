#ifndef HALTIMERB0_H
#define HALTIMERB0_H

#include "halUCS.h"

#define TIMER_FREQU (2*2) //2 mal pro periode im 2Hz Takt
#define DIVIDER 64 //8*8
#define TB0CCR0_VALUE ((SMCLK_FREQU/DIVIDER/TIMER_FREQU)-1) //19530

#ifndef TBSSEL
#define TBSSEL              TBSSEL_3
#endif

#ifndef MC
#define MC                  MC_3
#endif

#ifndef ID
#define ID                  ID_3
#endif

#ifndef TBIDEX
#define TBIDEX              TBIDEX_7
#endif

#define TimerB0SetDesTime   TB0CCR0_VALUE

void halTimerB0Init();

#endif

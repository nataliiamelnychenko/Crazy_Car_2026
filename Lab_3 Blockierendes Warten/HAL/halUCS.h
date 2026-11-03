#ifndef HALUCS_H
#define HALUCS_H

#include <stdint.h>

#define XTAL_FREQU   20000000
#define MCLK_FREQU   20000000
#define SMCLK_FREQU   2500000

void halUCSInit();
void delayMsBlocked(unsigned int ms);

#endif

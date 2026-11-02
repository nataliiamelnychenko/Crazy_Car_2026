#include "halGeneral.h"
#include "halPMM.h"
#include "halWdt.h"
#include "halGpio.h"
#include "halUCS.h"

volatile ButtonCom CCButton;

void halInit(){

    halWdtInit();
    HAL_PMM_Init();
    halGpioInit();
    halUCSInit();
    halTimerB0Init();
    __enable_interrupt();
}

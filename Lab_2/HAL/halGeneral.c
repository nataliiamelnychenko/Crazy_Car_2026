#include "halGeneral.h"
#include "halPMM.h"
#include "halWdt.h"
#include "halGpio.h"

volatile ButtonCom CCButton;

void halInit(){

    halWdtInit();
    HAL_PMM_Init();
    halGpioInit();
    __enable_interrupt();
}

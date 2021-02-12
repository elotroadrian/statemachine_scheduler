#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "header.h"


unsigned int uiLedSet = 0;


int main(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();

    __NVIC_EnableIRQ(59);

    while(1)
    {
        switch(uiLedSet)
        {
        	case 1:
        		vfnClearLeds();
        		vfnSetBlueLed();
        		break;
        	case 2:
        		vfnClearLeds();
        		vfnSetRedLed();
        		break;
        	case 3:
        		vfnClearLeds();
        		vfnSetGreenLed();
        		break;
        	case 4:
        		vfnClearLeds();
        		vfnSetYellowLed();
        		break;
        	case 5:
        		vfnClearLeds();
        		vfnSetPurpleLed();
        		break;
        	case 6:
        		vfnClearLeds();
        		vfnSetCyanLed();
        		break;
        	default:
        		vfnClearLeds();
        		break;

        }
    }

}

void PORTA_IRQHandler()
{
	uiLedSet++;
}



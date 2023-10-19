#include "xgpio.h"
#include "xparameters.h"
#include <stdio.h>
#include <stdlib.h>

void delay(int dly) {
    int i, j;
    for (i = 0; i < dly; i++) {
        for (j = 0; j < 0xffff; j++) {
            ;
        }
    }
}

int main() {
    XGpio LED_XGpio, SW_XGpio;
    int LED_num = 0b00000000;
    int SW_num = 0b00000000;
    u32 dir;

    XGpio_Initialize(&LED_XGpio, XPAR_AXI_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&LED_XGpio, 1, 0);
    dir = XGpio_GetDataDirection(&LED_XGpio, 1);
    printf("led1:%x\n", dir);

    XGpio_Initialize(&SW_XGpio, XPAR_AXI_GPIO_1_DEVICE_ID);
    XGpio_SetDataDirection(&SW_XGpio, 1, 1);
    dir = XGpio_GetDataDirection(&SW_XGpio, 1);
    printf("sw1:%x\n", dir);

    printf("Start!!!");

    while (1) {
        SW_num = XGpio_DiscreteRead(&SW_XGpio, 1);
        LED_num = SW_num + 1;
        XGpio_DiscreteWrite(&LED_XGpio, 1, LED_num);

        delay(200);
    }

    return 0;
}

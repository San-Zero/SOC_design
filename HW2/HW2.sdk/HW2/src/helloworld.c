#include <stdio.h>
#include <stdlib.h>
#include "xparameters.h"		// �Ѽƶ�.
#include "xgpio.h"	// ²��PS��PL��GPIO�ާ@����Ʈw.

// �����.
void delay(int dly)
{
    int i, j;
    for (i = 0; i < dly; i++) {
    	for (j = 0; j < 0xffff; j++) {
    		;
        }
    }
}

// �D�{��.
int main()
{
    XGpio LED_XGpio;		// �ŧi�@��GPIO�Ϊ����c.
    int LED_num = 0b00000000;	// �ŧi�@���ܼ�,���B��μȦs��.
    int SW_num = 0b00000000;

    XGpio_Initialize(&LED_XGpio, XPAR_AXI_GPIO_0_DEVICE_ID);	// ��l��LED_XGpio.
    XGpio_SetDataDirection(&LED_XGpio, 1, 0);		// �]�m�q�D.

    printf("Start!!!");

    while(1) {
    	printf("LED_num = 0x%x\n", LED_num);

    	XGpio_DiscreteWrite(&LED_XGpio, 1, LED_num);		// LED_XGpio�q�D,�eLED_num�ȶi�h.


    	LED_num = LED_num + 1;		// LED_num�ܼƤϬ�.

    	delay(200);


    }

    return 0;
}

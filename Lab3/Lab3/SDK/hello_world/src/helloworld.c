/*
 * Copyright (c) 2009-2012 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xgpio.h"

void print(char *str);

int main()
{
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_8BIT_DEVICE_ID);
	XGpio_SetDataDirection(&led, 1, ~0x01);
	XGpio_DiscreteWrite(&led, 1, 0x00);
	init_platform();
	GOTO:
    print("Enter two numbers: ");
    
    char past_delim = 0;
    int a = 0;
    int b = 0;
    char str[256];
    gets(str);
    
    int i;
    for (i = 0; ; i++) {
        char c = str[i];
        if (c == 0) {
        	continue;
        }
        else if (c >= '0' && c <= '9') {
            if (past_delim == 0) {
                a *= 10;
                a += c - '0';
            }
            else {
                b *= 10;
                b += c - '0';
            }
        }
        else if (c == ' ') {
            past_delim = 1;
        }
        else if (c == '\n' || c == '\r') {
            break;
        } else {
            print("\r\nEnter two numbers: ");
        }
    }
    int product = a*b;
    if(product > 100)
    {
  	  XGpio_DiscreteWrite(&led, 1, 0x01);
    } else {
    	XGpio_DiscreteWrite(&led, 1, 0x00);
    }
    xil_printf("%d\n", product);
    goto GOTO;
    return 0;
}

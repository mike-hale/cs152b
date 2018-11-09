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

#define ONE_BIT 0x0001
#define TWO_BIT 0x0002
#define THREE_BIT 0x0004

void print(char *str);
int check_numpad(XGpio* numpad);

int main()
{
XGpio numpad;
XGpio switch_input;

XGpio_Initialize(&numpad, XPAR_XPS_GPIO_0_DEVICE_ID);
XGpio_SetDataDirection(&numpad, 1, 0xF0);

XGpio_Initialize(&switch_input, XPAR_DIP_SWITCHES_8BIT_DEVICE_ID);
init_platform();

char player_1 = 0;
char player_2 = 0;
int keypad = 0;
int serial = 0;
char serial_string[32];

while (1) {
	xil_printf("Would you like to play a game? ;)\r\n");
	keypad = -1;
	serial = -1;

	while(keypad == -1) {
		keypad = check_numpad(&numpad);
		if (keypad & ONE_BIT) {
			keypad = 1;
		} else if (keypad & TWO_BIT) {
			keypad = 2;
		} else if (keypad & THREE_BIT) {
			keypad = 3;
		} else {
			keypad = -1;
		}
	}
	xil_printf("Registered keypad input\r\n");
	BACK_TO_SERIAL:
	gets(serial_string);
	serial = serial_string[0] - '0';
	if (serial > 3 || serial < 1) {
		xil_printf("Invalid serial input, re-enter choice\r\n");
		goto BACK_TO_SERIAL;
	}

	char* serial_selection = serial == 1 ? "rock" : serial == 2 ? "paper" : "scissors";
	char* keypad_selection = keypad == 1 ? "rock" : keypad == 2 ? "paper" : "scissors";

	if (serial - keypad == 1 || serial - keypad == -2) {
		xil_printf("Console won! %s > %s\r\n", serial_selection, keypad_selection);
	} else if (serial - keypad == 0) {
		xil_printf("Its a Tie! %s = %s\r\n", serial_selection, keypad_selection);
	} else {
		xil_printf("Keypad won! %s < %s\r\n", serial_selection, keypad_selection);
	}
}

return 0;
}

int check_numpad(XGpio* numpad) {
	int ret = 0;
	int i;
	for (i = 0; i < 4; i++) {
		int mask = 1 << i;
		XGpio_DiscreteWrite(numpad, 1, mask);
		int row = (0xF0 & XGpio_DiscreteRead(numpad, 1)) >> 4;
		ret |= (row << (i*4));
	}
	return ret;
}

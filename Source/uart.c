#include "uart.h"

void uart_init() {
	ASIMR0 = TX0M | ISRM0;

	// 9600 baud?
	BRGCR0 = 0x4a;
}

void uart_tx(char* msg, int len) {
	int i = 0; 
	for (i; i < len; i++) {
		TXSR = msg[i];
	}
}
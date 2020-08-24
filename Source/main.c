#include <hms800.h>

#include "uart.h"
#include "lcd.h"

void delay(int n_loops) {
	int i = 0;
	for (i; i < n_loops; i++){
		asm("nop");
	}
}

void clock_init() {
	// 8MHz internal oscilator?
	SCMR = 0x0;
}

int main(void) {
	clock_init();
	uart_init();

	char msg[] = "Hello\n";

	for (;;) {
		uart_tx(msg, 6);
		delay(0x7f);
	}

/*
	lcd_init();

	for (;;) {
		int seg = SEG0;
		for (seg; seg < SEG35; seg++) {
			seg = 0xf;
			delay(0x7f);
	
			seg = 0x0;
			delay(0x7f);
		}
	}
*/
	return 0;
}
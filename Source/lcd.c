#include "lcd.h"

void lcd_subclock_enable() {
	LCR |= SCKD;
}

void lcd_subclock_disable() {
	LCR &= ~SCKD;
}

void lcd_18_duty() {
	LCR &= ~LCDD0;
}

void lcd_14_duty() {
	LCR |= LCDD0;
}

void lcd_clock_128hz() {
	LCR |= 3;
}

void lcd_clock_256hz() {
	LCR &= ~3;
	LCR |= 2;
}

void lcd_clock_512hz() {
	LCR &= ~3;
	LCR |= 1;
}

void lcd_clock_1024hz() {
	LCR &= ~3;
}

void lcd_enable() {
	LCR |= LCDEN;
}

void lcd_disable() {
	LCR &= ~LCDEN;
}

void lcd_init() {
	LCR = (1 << 6) | (1 << 3);

	lcd_subclock_enable();
	lcd_18_duty();
	lcd_clock_128hz();
	lcd_enable();
}

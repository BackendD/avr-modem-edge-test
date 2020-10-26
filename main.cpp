#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include <avr-modem.h>
#include <util/delay.h>

void onReceive(char *message) {
	lcd_gotoxy(0, 1);
	lcd_puts(message);
}

int main(void) {

	sei();

	AvrModem avrModem = AvrModem();

	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	lcd_clrscr();

	lcd_puts("Ready:");

	avrModem.listen(onReceive);

	while (1) {
		_delay_ms(50);
		PORTD &= ~(1 << 7);
		_delay_ms(950);
		PORTD |= (1 << 7);
	}
}

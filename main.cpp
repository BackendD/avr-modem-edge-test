#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"

int main(void) {

	sei();

	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	lcd_clrscr();

	while(1) {

	}
}


#include "ultrasonic.h"
#include "lcd.h"
#include <avr/io.h>
#include "gpio.h"
#include "common_macros.h"

int main(void) {
	uint16 Distance=0;
	SET_BIT(SREG, 7);
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance=");
	while(1){

		Distance=Ultrasonic_readDistance();
		LCD_moveCursor(0, 9);
		if (Distance>99){
			LCD_intgerToString(Distance);
			LCD_displayString("cm");
		}
		else {
			LCD_intgerToString(Distance);
			LCD_displayCharacter(' ');
			LCD_displayString("cm");
		}
	}

}

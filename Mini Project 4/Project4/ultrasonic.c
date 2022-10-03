/*
 * ultrasonic.c
 *
 *  Created on: Mar 3, 2022
 *      Author: hends
 */

#include "icu.h"
#include "gpio.h"
#include "util/delay.h"
#include "ultrasonic.h"
/*     FUNCTIONS DEFINITIONS   */

uint8 EdgeCount = 0;
uint16 Time = 0;
uint16 Distance = 0;

void Ultrasonic_init(void) {
	Icu_ConfigType Icu_Config = { F_CPU_8, RISING }; //Configuration Structure
	Icu_init(&Icu_Config);  // Initialization of ICU Driver
	Icu_setCallBack(&Ultrasonic_edgeProcessing); //Set Call Back Function
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT); //Trigger Pin Output

}

void Ultrasonic_Trigger(void) {
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH); // to send the pulse for 10us
	_delay_us(10);
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void) {
	Ultrasonic_Trigger();
	EdgeCount=0;
		Distance= ((float) (Time/58.8)+2);

	return Distance;

}

void Ultrasonic_edgeProcessing(void) {
	EdgeCount++;
	if (EdgeCount == 1) {
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	if (EdgeCount == 2) {
		Time = Icu_getInputCaptureValue();
		Icu_setEdgeDetectionType(RISING);
		Icu_clearTimerValue();
	}

}




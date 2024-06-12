/*
 * brazo.c
 *
 * Created: 11/06/2024 9:50:42 a. m.
 * Author : juan-
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "serial/serial.h"
#include "servo/servo.h"
#include "adc/joystick.h"

int main(void)
{
	unsigned char instruccion;
    usart_init();
	servo_init();
	adc_init();
    while (1) 
    {
		usart_send('H');
		adc_lecture(0);
		servo_set_angle(pin_codo, 90);
    }
}


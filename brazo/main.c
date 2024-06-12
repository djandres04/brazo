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


	

extern uint8_t instruccion=0;

ISR(USART0_RX_vect)
{
	instruccion = UDR0;
}


int main(void)
{
    usart_init();
	servo_init();
    while (1) 
    {
    }
}


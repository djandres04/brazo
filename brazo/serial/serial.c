/*
 * serial.c
 *
 * Created: 11/06/2024 9:53:38 a. m.
 *  Author: juan-
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void usart_init(void){
	UCSR0B = (1 << TXEN0) | (1<<RXEN0)|(1<<RXCIE0);;
	UCSR0C = (1 << UCSZ01)| (1 << UCSZ00);
	UBRR0L = 103;
}

void usart_send(unsigned char ch){
	while( !(UCSR0A & (1<<UDRE0) ) );
	UDR0 = ch;
}
void usart_string(char *str) {
	while (*str) {
		usart_send(*str++);
	}
}

/*
 * serial.c
 *
 * Created: 11/06/2024 9:53:38 a. m.
 *  Author: juan-
 */ 

#include <avr/io.h>
#include "serial.h"

/**
 * Inicializa la comunicación serie USART0
 * 
 * Configura el USART0 para que esté habilitado, con velocidad de 9600 bps
 * y formato de datos de 8 bits, 1 stop bit y sin paridad.
 */
void usart_init(void){
    // Habilita la transmisión y recepción
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    
    // Configura el formato de datos: 8 bits, 1 stop bit, sin paridad
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    
    // Configura la velocidad de baudios: 9600 bps
    UBRR0L = 103; // Valor calculado para 9600 bps con un reloj de 16 MHz
}

/**
 * Envía un carácter por la comunicación serie USART0
 * 
 * @param ch Carácter a enviar
 */
void usart_send(unsigned char ch){
    // Espera a que el buffer de transmisión esté vacío
    while( !(UCSR0A & (1 << UDRE0)) );
    
    // Envía el carácter
    UDR0 = ch;
}

/**
 * Envía una cadena de caracteres por la comunicación serie USART0
 * 
 * @param str Cadena de caracteres a enviar
 */
void usart_string(char *str) {
    // Envía cada carácter de la cadena
    while (*str) {
        usart_send(*str++);
    }
}

/**
 * Recibe un carácter por la comunicación serie USART0
 * 
 * @return Carácter recibido
 */
unsigned char usart_receive(void){
    // Espera a que haya un carácter disponible en el buffer de recepción
    while( !(UCSR0A & (1 << RXC0)) );
    
    // Lee el carácter recibido
    return UDR0;
}

/*
 * serial.h
 *
 * Created: 11/06/2024 9:53:29 a. m.
 *  Author: juan-
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

void usart_init(void);
void usart_send(unsigned char ch);
void usart_string(char *str);


#endif /* SERIAL_H_ */
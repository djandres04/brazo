/*
 * servo.c
 *
 * Created: 11/06/2024 6:54:48 p. m.
 *  Author: juan-
 */ 
#include <avr/io.h>
#include "servo.h"

// Definiciones de los parámetros del PWM
#define SERVO_MIN 1000  // 1 ms
#define SERVO_MAX 2000  // 2 ms

void servo_init() {
	// Configurar los pines como salida
	DDRB |= (1 << pin_codo) | (1 << pin_hombro) | (1 << pin_pinza);
	DDRD |= (1 << pin_base);

	// Configurar el Timer1 en modo Fast PWM con TOP=ICR1
	TCCR1A |= (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler = 8

	// Establecer el valor TOP para obtener un periodo de 20 ms
	ICR1 = 20000; // 16 MHz / (8 * (1 + 20000)) = 100 Hz

	// Inicializar los valores del pulso en el medio (1.5 ms)
	OCR1A = 1500;
	OCR1B = 1500;

	// Configurar el Timer2 en modo Fast PWM
	TCCR2A |= (1 << WGM21) | (1 << WGM20) | (1 << COM2A1);
	TCCR2B |= (1 << CS22) | (1 << CS20); // Prescaler = 1024

	// Inicializar el valor del pulso en el medio (1.5 ms)
	OCR2A = 150;

	// Configurar el Timer0 en modo Fast PWM
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0B1);
	TCCR0B |= (1 << CS01) | (1 << CS00); // Prescaler = 64

	// Inicializar el valor del pulso en el medio (1.5 ms)
	OCR0B = 150;
}

void servo_set_angle(uint8_t channel, uint8_t angle) {
	if (angle > 180) {
		angle = 180;
	}

	// Mapear el ángulo (0-180) al rango del PWM (1000-2000)
	uint16_t pulse_width = SERVO_MIN + ((SERVO_MAX - SERVO_MIN) * angle) / 180;

	// Convertir el ancho del pulso a la escala de Timer0 y Timer2
	uint8_t ocr_value = pulse_width / 10;

	switch (channel) {
		case 0:
		OCR0B = ocr_value;  // Timer0 (PD5)
		break;
		case 1:
		OCR1A = pulse_width;  // Timer1 (PB1)
		break;
		case 2:
		OCR1B = pulse_width;  // Timer1 (PB2)
		break;
		case 3:
		OCR2A = ocr_value;  // Timer2 (PB3)
		break;
		default:
		break;
	}
}
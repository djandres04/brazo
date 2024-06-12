/*
 * joystick.c
 *
 * Created: 11/06/2024 9:13:05 p. m.
 *  Author: juan-
 */ 

#include <avr/io.h>
#include "joystick.h"


/**
 * Inicializa el ADC del ATmega328p
 * 
 * Configura el ADC para que esté habilitado, seleccione la fuente de reloj 
 * interna (ck) dividida entre 128 y configure la referencia de voltaje 
 * como AVCC (el voltaje de alimentación del microcontrolador)
 */
void adc_init(void){
    ADCSRA = 0x87; // Habilita el ADC y selecciona la fuente de reloj ck/128
    ADMUX = 0b01000000; // Configura la referencia de voltaje como AVCC y 
                         // datos de derecha a izquierda
}

/**
 * Lee el valor del ADC en el canal seleccionado
 * 
 * @param channel Canal a leer (CHANNEL_PC0 para PC0, CHANNEL_PC1 para PC1)
 * @return Valor leído del ADC (0-1023)
 */
uint16_t adc_lecture(uint8_t channel){
    uint16_t temp; // Variable para almacenar el valor leído
    
    // Selecciona el canal a leer
    if(channel == CHANNEL_PC0){
        // Selecciona el canal PC0 (JRX)
        ADMUX = 0b01000000;
    } else if(channel == CHANNEL_PC1){
        // Selecciona el canal PC1 (JRY)
        ADMUX = 0b01000001;
    }
    
    // Inicia la conversión ADC
    ADCSRA |= (1 << ADSC);
    
    // Espera a que la conversión termine
    while((ADCSRA & (1 << ADIF)) == 0);
    
    // Borra el flag de fin de conversión
    ADCSRA |= (1 << ADIF);
    
    // Lee el valor del ADC
    temp = ADCL | (ADCH << 8);
    
    return temp;
}
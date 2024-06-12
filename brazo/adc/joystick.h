/*
 * joystick.h
 *
 * Created: 11/06/2024 9:13:13 p. m.
 *  Author: juan-
 */ 


#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#define CHANNEL_PC0 0
#define CHANNEL_PC1 1

void adc_init(void);
uint16_t adc_lecture(uint8_t channel);


#endif /* JOYSTICK_H_ */
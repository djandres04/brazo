/*
 * servo.h
 *
 * Created: 11/06/2024 6:55:01 p. m.
 *  Author: juan-
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#define pin_base PORTD5
#define pin_codo PORTB1
#define pin_hombro PORTB2
#define pin_pinza PORTB3

void servo_init();
void servo_set_angle(uint8_t channel, uint8_t angle);

#endif /* SERVO_H_ */
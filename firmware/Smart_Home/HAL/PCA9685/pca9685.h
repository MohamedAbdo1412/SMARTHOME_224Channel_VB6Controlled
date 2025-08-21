#ifndef PCA9685_H
#define PCA9685_H

#include <avr/io.h>
#define SERVO_MIN 204
#define SERVO_MAX 410
void PCA9685_Init(uint8_t addr);
void PCA9685_SetPWMFreq(uint8_t addr, float freq);
void PCA9685_SetPWM(uint8_t addr, uint8_t channel, uint16_t on, uint16_t off);
void PCA9685_SetServoAngle(uint8_t addr, uint8_t channel, float angle) ;
#endif

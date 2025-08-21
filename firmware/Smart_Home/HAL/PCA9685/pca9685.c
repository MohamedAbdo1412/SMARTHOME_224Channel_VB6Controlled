#include "../../MCAL/I2C/i2c.h"
#include "pca9685.h"
#include "../DataKeeper/DataKeeper.h"
void PCA9685_Init(uint8_t addr) {
    I2C_Start();
    I2C_Write(addr<<1);
    I2C_Write(0x00); // MODE1
    I2C_Write(0x20); // Auto-increment enabled
    I2C_Stop();
}

void PCA9685_SetPWMFreq(uint8_t addr, float freq) {
    float prescaleval = 25000000.0;
    prescaleval /= 4096.0;
    prescaleval /= freq;
    prescaleval -= 1.0;
    uint8_t prescale = (uint8_t)(prescaleval + 0.5);

    I2C_Start();
    I2C_Write(addr<<1);
    I2C_Write(0x00);
    I2C_Write(0x10); // sleep
    I2C_Stop();

    I2C_Start();
    I2C_Write(addr<<1);
    I2C_Write(0xFE); // prescale register
    I2C_Write(prescale);
    I2C_Stop();

    I2C_Start();
    I2C_Write(addr<<1);
    I2C_Write(0x00);
    I2C_Write(0x20); // restart
    I2C_Stop();
}

void PCA9685_SetPWM(uint8_t addr, uint8_t channel, uint16_t on, uint16_t off) {
    I2C_Start();
    I2C_Write(addr<<1);
    I2C_Write(0x06 + 4*channel);
    I2C_Write(on & 0xFF);
    I2C_Write(on >> 8);
    I2C_Write(off & 0xFF);
    I2C_Write(off >> 8);
    I2C_Stop();
}

void PCA9685_SetServoAngle(uint8_t addr, uint8_t channel, float angle) {
	channel--;
    if (angle < -90.0f) angle = -90.0f;
    if (angle > 90.0f)  angle = 90.0f;

    float scale = (SERVO_MAX - SERVO_MIN) / 180.0f;
    uint16_t pulse = (uint16_t)(SERVO_MIN + (angle + 90.0f) * scale + 0.5f); // +0.5 للتقريب
    PCA9685_SetPWM(addr, channel, 0, pulse);
    if(addr == 0x40){DataKeeper[channel].servoAngleA = angle;}
    else if(addr == 0x41)  {DataKeeper[channel].servoAngleB =angle;}
}

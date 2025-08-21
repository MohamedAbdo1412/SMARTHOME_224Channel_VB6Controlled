#include <avr/io.h>
#include <util/twi.h>

void I2C_Init(unsigned long scl_freq) {
    TWSR = 0x00;
    TWBR = ((F_CPU/scl_freq)-16)/2;
}

void I2C_Start(void) {
    TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
    while (!(TWCR & (1<<TWINT)));
}

void I2C_Stop(void) {
    TWCR = (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
}

void I2C_Write(uint8_t data) {
    TWDR = data;
    TWCR = (1<<TWEN)|(1<<TWINT);
    while (!(TWCR & (1<<TWINT)));
}

uint8_t I2C_Read(uint8_t ack) {
    TWCR = (1<<TWEN)|(1<<TWINT)|(ack<<TWEA);
    while (!(TWCR & (1<<TWINT)));
    return TWDR;
}

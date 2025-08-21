/*
 * PIN_priv.h
 *
 *  Created on: Jul 29, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef PIN_PRIV_H_
#define PIN_PRIV_H_

#define DIO_GROUP_A         (0U)
#define DIO_GROUP_B         (1U)
#define DIO_GROUP_C         (2U)
#define DIO_GROUP_D         (3U)


#define PORTA    *((volatile u8*)0x3B)
#define  DDRA    *((volatile u8*)0x3A)
#define  PINA    *((volatile u8*)0x39)

#define PORTB    *((volatile u8*)0x38)
#define  DDRB    *((volatile u8*)0x37)
#define  PINB    *((volatile u8*)0x36)

#define PORTC    *((volatile u8*)0x35)
#define  DDRC    *((volatile u8*)0x34)
#define  PINC    *((volatile u8*)0x33)

#define PORTD    *((volatile u8*)0x32)
#define  DDRD    *((volatile u8*)0x31)
#define  PIND    *((volatile u8*)0x30)



#endif /* PIN_PRIV_H_ */

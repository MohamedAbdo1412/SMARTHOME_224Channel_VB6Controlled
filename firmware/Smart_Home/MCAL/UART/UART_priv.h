/*
 * UART_priv.h
 *
 *  Created on: Aug 8, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_UART_UART_PRIV_H_
#define MCAL_UART_UART_PRIV_H_

#define NORMAL            (2U)
#define DOUBLE            (1U)


#define UBRR_BUAD(buadrate)        ((UART_FREQ_CPU/ (UART_SPEED_MODE * 8UL * buadrate)) - 1UL)


/* UART_priv.h */
/* Bit positions in UCSRA */
#define RXC     7   // Receive Complete
#define UDRE    5   // Data Register Empty

/* Bit positions in UCSRB */
#define RXEN    4   // Receiver Enable
#define TXEN    3   // Transmitter Enable

#endif /* MCAL_UART_UART_PRIV_H_ */

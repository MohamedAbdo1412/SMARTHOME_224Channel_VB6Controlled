/*
 * UART_int.h
 *
 *  Created on: Aug 8, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void UART_vidInit(void);

void UART_vidSend(u8 u8Data);

u8 UART_u8Receive(void);
void UART_vidSendString(const char *str);
void UART_vidReceiveStringUntilNewline(char *buffer, u8 maxLen);
#endif /* MCAL_UART_UART_INT_H_ */

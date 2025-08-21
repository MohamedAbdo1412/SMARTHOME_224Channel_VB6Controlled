#include <avr/io.h>
#include "../../LIB/stdTypes.h"
#include "UART_config.h"
#include "UART_priv.h"
#include "UART_int.h"

void UART_vidInit(void)
{
    u8 u8UCSRC = 0;

    // Select UCSRC register (URSEL=1)
    u8UCSRC |= (1 << URSEL);

    // Data size (default: 8 bits)
#if UART_DATA_BITS == 5
    // UCSZ1=0, UCSZ0=0
#elif UART_DATA_BITS == 6
    u8UCSRC |= (1 << UCSZ0);
#elif UART_DATA_BITS == 7
    u8UCSRC |= (1 << UCSZ1);
#elif UART_DATA_BITS == 8
    u8UCSRC |= (1 << UCSZ1) | (1 << UCSZ0);
#elif UART_DATA_BITS == 9
    u8UCSRC |= (1 << UCSZ1) | (1 << UCSZ0);
    UCSRB |= (1 << UCSZ2);
#else
#error "Invalid UART_DATA_BITS value"
#endif

    // Stop bits
#if UART_STOP_BITS == 1
    u8UCSRC &= ~(1 << USBS); // 1 stop bit
#elif UART_STOP_BITS == 2
    u8UCSRC |= (1 << USBS);  // 2 stop bits
#else
#error "Invalid UART_STOP_BITS value"
#endif

    // Parity
#if UART_PARITY == 0
    u8UCSRC &= ~((1 << UPM1) | (1 << UPM0)); // None
#elif UART_PARITY == 1
    u8UCSRC |= (1 << UPM0);                  // Odd
#elif UART_PARITY == 2
    u8UCSRC |= (1 << UPM1);                  // Even
#else
#error "Invalid UART_PARITY value"
#endif

    // Apply UCSRC settings
    UCSRC = u8UCSRC;

    // Baud rate
#if UART_DOUBLE_SPEED == 1
    UCSRA |= (1 << U2X); // Enable double speed
    u16 u16UBRR = (F_CPU / (8UL * UART_BAUDRATE)) - 1;
#else
    UCSRA &= ~(1 << U2X); // Normal speed
    u16 u16UBRR = (F_CPU / (16UL * UART_BAUDRATE)) - 1;
#endif
    UBRRL = (u8)u16UBRR;
    UBRRH = (u8)(u16UBRR >> 8);

    // Enable TX and RX
    UCSRB |= (1 << TXEN) | (1 << RXEN);
}

void UART_vidSend(u8 u8Data)
{
    // Wait until transmit buffer is empty
    while (!(UCSRA & (1 << UDRE)));
    // Put data into buffer
    UDR = u8Data;
}

void UART_vidSendString(const char *str)
{
    while (*str)
    {
        UART_vidSend(*str++);
    }
}

u8 UART_u8Receive(void)
{
    // Wait until data is received
    while (!(UCSRA & (1 << RXC)));
    // Get and return received data
    return UDR;
}

void UART_vidReceiveStringUntilNewline(char *buffer, u8 maxLen)
{
    // Clear buffer first
    for (u8 j = 0; j < maxLen; j++)
    {
        buffer[j] = '\0';
    }

    char c;
    u8 i = 0;

    do
    {
        c = UART_u8Receive();   // blocking wait for next char
        if (i < maxLen - 1)     // leave space for null terminator
        {
            buffer[i++] = c;
        }
    } while (c != '\n' && i < maxLen - 1);

    // Replace newline with end of string
    if (i > 0 && buffer[i - 1] == '\n')
    {
        buffer[i - 1] = '\0';
    }
    else
    {
        buffer[i] = '\0';
    }
}

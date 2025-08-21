/*
 * GIE_prog.c
 *
 *  Created on: Aug 2, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#include "../../LIB/stdTypes.h"


// #define SREG    *((volatile u8*)0x5F)

void GIE_vidEnable(void)
{
    // SREG|=(1<<7);
    __asm__("sei");
}

void GIE_vidDisable(void)
{
    __asm__("cli");
    // SREG&=~(1<<7);
}

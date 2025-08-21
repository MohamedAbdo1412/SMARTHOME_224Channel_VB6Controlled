/*
 * PIN_int.h
 *
 *  Created on: Jul 29, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef PIN_INT_H_
#define PIN_INT_H_
#include "../../LIB/PrimitiveTypes.h"
void PIN_vidSetMode(u8 u8PinNum , u8 u8Mode);

void PIN_vidSetValue(u8 u8PinNum , u8 u8Value);

void PIN_vidTogValue(u8 u8PinNum);

BOOL PIN_bGetValue(u8 u8PinNum);


// GROUP A 0-> 7 
#define PA0                 (0U)
#define PA1                 (1U)
#define PA2                 (2U)
#define PA3                 (3U)
#define PA4                 (4U)
#define PA5                 (5U)
#define PA6                 (6U)
#define PA7                 (7U)

// GROUP B 8-> 15 
#define PB0                 (8U)
#define PB1                 (9U)
#define PB2                 (10U)
#define PB3                 (11U)
#define PB4                 (12U)
#define PB5                 (13U)
#define PB6                 (14U)
#define PB7                 (15U)

// GROUP C 16-> 23 
#define PC0                 (16U)
#define PC1                 (17U)
#define PC2                 (18U)
#define PC3                 (19U)
#define PC4                 (20U)
#define PC5                 (21U)
#define PC6                 (22U)
#define PC7                 (23U)

// GROUP D 24-> 31 
#define PD0                 (24U)
#define PD1                 (25U)
#define PD2                 (26U)
#define PD3                 (27U)
#define PD4                 (28U)
#define PD5                 (29U)
#define PD6                 (30U)
#define PD7                 (31U)

#define PORTC    *((volatile u8*)0x35)


#define INPUT_FLOAT         (0b00U)  //0 //bit 0 for PORT , bit 1 for DDR
#define INPUT_PULLUP        (0b01U)  //1 //bit 0 for PORT , bit 1 for DDR

#define OUTPUT_LOW          (0b10U)  //2 //bit 0 for PORT , bit 1 for DDR
#define OUTPUT_HIGH         (0b11U)  //3 //bit 0 for PORT , bit 1 for DDR

#define LOW                 (0U)
#define HIGH                (1U)

#endif /* PIN_INT_H_ */

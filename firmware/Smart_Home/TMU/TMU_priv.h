/*
 * TMU_priv.h
 *
 *  Created on: Aug 5, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TMU_TMU_PRIV_H_
#define TMU_TMU_PRIV_H_
#define NULL	               ((void *) 0x0000U)
typedef struct _Task_TCB_
{
    void(*pfunTask)(void);
    u16 u16Periodicity;
}TCB_t;


#define TMU_TIMER0            (22U)
#define TMU_TIMER1            (33U)
#define TMU_TIMER2            (55U)


//general
#define TIMSK               *((volatile u8*)0x59)
#define TIFR                *((volatile u8*)0x58)
//Timer0
#define TCCR0               *((volatile u8*)0x53)
#define TCNT0               *((volatile u8*)0x52)
#define OCR0                *((volatile u8*)0x5C)
//Timer1
#define TCCR1A	        	*((volatile u8*)0x4F)
#define TCCR1B	        	*((volatile u8*)0x4E)
#define TCNT1H	        	*((volatile u8*)0x4D)
#define TCNT1L	        	*((volatile u8*)0x4C)
#define OCR1AH	        	*((volatile u8*)0x4B)
#define OCR1AL	        	*((volatile u8*)0x4A)
#define OCR1BH	        	*((volatile u8*)0x49)
#define OCR1BL	        	*((volatile u8*)0x48)
//Timer2
#define TCCR2               *((volatile u8*)0x45)
#define TCNT2               *((volatile u8*)0x44)
#define OCR2                *((volatile u8*)0x43)




#endif /* TMU_TMU_PRIV_H_ */

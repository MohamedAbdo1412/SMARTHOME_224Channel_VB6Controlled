/*
 * Timer_priv.h
 *
 *  Created on: Aug 4, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_TIMER0_TIMER_PRIV_H_
#define MCAL_TIMER0_TIMER_PRIV_H_
#define NULL	               ((void *) 0x0000U)
#define TCCR0            *((volatile u8*)0x53)
#define TCNT0            *((volatile u8*)0x52)
#define OCR0             *((volatile u8*)0x5C)
#define TIMSK            *((volatile u8*)0x59)
#define TIFR             *((volatile u8*)0x58)



#define PRES_STOP          (0U)
#define PRES_1             (1U)
#define PRES_8             (2U)
#define PRES_64            (3U)
#define PRES_256           (4U)
#define PRES_1024          (5U)   
#define PRES_T0_FALL       (6U)
#define PRES_T0_RISE       (7U)


#define INTERRUPT       (12U)
#define POLLING         (42U)

#define CTC               (19U)
#define OVF               (9U)

#endif /* MCAL_TIMER0_TIMER_PRIV_H_ */

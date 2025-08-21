/*
 * Timer_int.h
 *
 *  Created on: Aug 4, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_TIMER0_TIMER_INT_H_
#define MCAL_TIMER0_TIMER_INT_H_

void Timer_vidInit(void);

void Timer_vidSychDelay(u32 u32MilliSeconds);

void Timer_vidAsychDelay(void(*pfunAppFun)(void) , u32 u32MilliSeconds);

void Timer_vidCallBack(void(*pfunAppFun)(void));

#endif /* MCAL_TIMER0_TIMER_INT_H_ */

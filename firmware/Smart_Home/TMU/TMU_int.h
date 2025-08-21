/*
 * TMU_int.h
 *
 *  Created on: Aug 5, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TMU_TMU_INT_H_
#define TMU_TMU_INT_H_

void TMU_vidInit(void);

void TMU_vidCreateTask(void(*pfunTask)(void) , u8 u8Priority , u16 u16Periodicity);

void TMU_vidStartScheduler(void);

#endif /* TMU_TMU_INT_H_ */

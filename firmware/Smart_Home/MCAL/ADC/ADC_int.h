/*
 * ADC_int.h
 *
 *  Created on: Aug 3, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

void ADC_vidInit(void);

u16 ADC_u16GetRead(u8 u8ADCChannel);

BOOL ADC_bGetInterruptRead(u8 u8ADCChannel, u16 * pu16ADCRead);

void ADC_vidCallback(void(*pfunAppFun)(void));

#endif /* MCAL_ADC_ADC_INT_H_ */

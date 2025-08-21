/*
 * ADC_priv.h
 *
 *  Created on: Aug 3, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_
#define NULL	               ((void *) 0x0000U)
#define ADC_AREF       (0U)
#define ADC_AVCC       (1U)
#define ADC_INTERNAL   (3U)

#define PRES_2         (1U)
#define PRES_4         (2U)
#define PRES_8         (3U)
#define PRES_16        (4U)
#define PRES_32        (5U)
#define PRES_64        (6U)
#define PRES_128       (7U) 

#define POLLING          (0U)
#define RIGHT_ADJ        (0U)
#define SINGLE_MODE      (0U)


#define ADMUX       *((volatile u8*)0x27)
#define ADCSRA      *((volatile u8*)0x26)
#define ADCH        *((volatile u8*)0x25)
#define ADCL        *((volatile u8*)0x24)

#endif /* MCAL_ADC_ADC_PRIV_H_ */

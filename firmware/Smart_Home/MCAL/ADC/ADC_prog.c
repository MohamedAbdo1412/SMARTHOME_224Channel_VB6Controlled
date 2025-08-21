/*
 * ADC_prog.c
 *
 *  Created on: Aug 3, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#include "../../LIB/stdTypes.h"

#include "ADC_config.h"
#include "ADC_int.h"
#include "ADC_priv.h"

static void (*LOC_pfunIsrFun)(void) = NULL;

static BOOL LOC_bIsInteruptOccured = FALSE;
static BOOL LOC_bOneTimeAccess = FALSE;
static u16 LOC_u16ADCValue = 0U;


void ADC_vidInit(void)
{
    ADMUX &=~(0b11 << 6);
    #if ADC_VREF == ADC_AVCC
        ADMUX |= (ADC_AVCC <<6);
    #endif

    ADCSRA &=~ (0b111 << 0);
    #if ADC_PRESCALER == PRES_16
        ADCSRA |= (ADC_PRESCALER << 0);
    #endif

    ADMUX &=~(1<<5); // right
    ADCSRA &=~(1<<3); // polling
    ADCSRA &=~(1<<5); // single

    ADCSRA |= (1<<7);
}

u16 ADC_u16GetRead(u8 u8ADCChannel)
{
    u16 u16ADCReading = 0xFFFFU;
    if (u8ADCChannel <= 31)
    {
        // select channel
        ADMUX &= ~(0b11111 << 0);
        ADMUX |= (u8ADCChannel <<0);
        //start conversion
        ADCSRA |= (1<<6);
        //wait for flag rising
        while(((ADCSRA>>4)&1) == 0);
        // reading DATA registers low&high
        u16ADCReading = ADCL;
        u16ADCReading |= (((u16)ADCH)  << 8);
        // clear flag
        ADCSRA |= (1<<4);
    }
    return u16ADCReading;
}

BOOL ADC_bGetInterruptRead(u8 u8ADCChannel, u16 * pu16ADCRead)
{
    if ((u8ADCChannel <= 31) && (LOC_bOneTimeAccess == FALSE))
    {
        LOC_bOneTimeAccess = TRUE;
        LOC_bIsInteruptOccured = FALSE;
        ADMUX &=~(0x1f<<0);
        ADMUX |= (u8ADCChannel<<0);

        ADCSRA |= (1<<3);
        ADCSRA |= (1<<6);
    }
    else
    {
        if (LOC_bIsInteruptOccured == TRUE)
        {
            LOC_bOneTimeAccess = FALSE;
            *pu16ADCRead=LOC_u16ADCValue;
        }
    }
    return  LOC_bIsInteruptOccured;
}

void ADC_vidCallback(void(*pfunAppFun)(void))
{
    if (pfunAppFun != NULL)
    {
        LOC_pfunIsrFun = pfunAppFun;
    }
}



void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
    LOC_bIsInteruptOccured = TRUE;
    LOC_u16ADCValue = ADCL;
    LOC_u16ADCValue |= (((u16)ADCH) << 8);

    if (LOC_pfunIsrFun != NULL)
    {
        LOC_pfunIsrFun();
    }
}

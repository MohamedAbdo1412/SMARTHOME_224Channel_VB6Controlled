/*
 * Timer_prog.c
 *
 *  Created on: Aug 4, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#include "../../LIB/stdTypes.h"

#include "Timer_config.h"
#include "Timer_priv.h"
#include "Timer_int.h"

static u32 LOC_u32OvfCounts = 0UL;
static u32 LOC_u32Counter   = 0UL;
static u8  LOC_u8Preload    = 0U;

static void(*LOC_pfunAsychAppFun)(void) = NULL;

void Timer_vidInit(void)
{
#if TIMER0_PRES>= PRES_STOP && TIMER0_PRES <= PRES_T0_RISE
    TCCR0 &=~ (7<<0);
    TCCR0 |= (TIMER0_PRES << 0);
#endif

#if TIMER0_MODE == OVF
    TCCR0 &=~(1<<3);
    TCCR0 &=~(1<<6);
#endif

#if TIMER0_INTERRPT  ==    INTERRUPT 
    TIMSK |= (1<<0);
    #endif    
}

void Timer_vidSychDelay(u32 u32MilliSeconds)
{
    TIMSK &=~(1<<0);
    
    u64 u64Counts = (u32MilliSeconds * 16000LLU)/8;
    u32 u32OvfCounts = (u64Counts + 255LLU) / 256LLU;
    u8 u8Preload = 256U - (u64Counts % 256LLU);
    TCNT0 = u8Preload;
    u32 u32Counter=0;
    while (u32Counter++ < u32OvfCounts)
    {
        while(((TIFR>>0)&1) == 0);
        TIFR |= (1<<0);
    }
}

void Timer_vidAsychDelay(void(*pfunAppFun)(void) , u32 u32MilliSeconds)
{
    if (pfunAppFun != NULL)
    {
        TIMSK |= (1<<0);
        u64 u64Counts = (u32MilliSeconds * 16000LLU)/8;
        LOC_u32OvfCounts = (u64Counts + 255LLU) / 256LLU;
        LOC_u8Preload = 256U - (u64Counts % 256LLU);
        TCNT0 = LOC_u8Preload;
        LOC_pfunAsychAppFun = pfunAppFun;
        LOC_u32Counter = LOC_u32OvfCounts;
    }
}



void __vector_11 (void)__attribute__((signal));
void __vector_11 (void)
{
    if (LOC_pfunAsychAppFun != NULL)
    {
        LOC_u32Counter--;
        if(! LOC_u32Counter)
        {
            LOC_pfunAsychAppFun();
            LOC_u32Counter = LOC_u32OvfCounts;
            TCNT0 = LOC_u8Preload;
        }
    }
}

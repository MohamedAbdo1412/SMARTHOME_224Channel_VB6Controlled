/*
 * TMU_prog.c
 *
 *  Created on: Aug 5, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#include "../LIB/stdTypes.h"

#include "TMU_config.h"
#include "TMU_priv.h"
#include "TMU_int.h"

#if TMU_TIMER_CHANNEL == TMU_TIMER0 || TMU_TIMER_CHANNEL == TMU_TIMER2
    static u32 LOC_u32OvfCounts = 0UL;
    static u32 LOC_u32ISRCounter   = 0UL;
    static u8  LOC_u8Preload    = 0U;
#endif

#if TMU_MAX_TASK_NUM >= 1U && TMU_MAX_TASK_NUM <= 10U
    static TCB_t LOC_astrTasks[TMU_MAX_TASK_NUM];
    u32 LOC_u32OSTicksCounter;
#else
#error TMU max number of tasks must be between [ 1 : 10 ]
#endif

void TMU_vidInit(void)
{  
    #if TMU_TIMER_CHANNEL == TMU_TIMER0
        #if TMU_OS_TICK >= 1U && TMU_OS_TICK <= 200U
            TCCR0 = 0x03; // 64-pres , ovf , oc0 pin disconnected
            
            u32 u32Counts = (TMU_OS_TICK * TMU_CPU_FREQ)/(64UL);

            LOC_u32OvfCounts = (u32Counts + 255LLU) / 256LLU;

            LOC_u8Preload = 256U - (u32Counts % 256LLU);
            
            TCNT0 = LOC_u8Preload;

            LOC_u32ISRCounter = LOC_u32OvfCounts;

            TIMSK |= (1<<0);
        #else
            #error TMU OS tick must be between [ 1 : 200 ] msec
        #endif
    #elif TMU_TIMER_CHANNEL == TMU_TIMER1
        #if TMU_OS_TICK >= 1U && TMU_OS_TICK <= 200U
            TCCR1A = 0U;
            TCCR1B = 0x0B; // ctc on ocr1a , disconnected all pins
            TCNT1L = 0U;
            TCNT1H = 0U;

            u32 u32Counts = (TMU_OS_TICK * TMU_CPU_FREQ)/(64UL);

            OCR1AH = (u8) (u32Counts >> 8U);
            OCR1AL = (u8) (u32Counts);

            TIMSK |= (1<<4);    
        #else
            #error TMU OS tick must be between [ 1 : 200 ] msec
        #endif
    #elif TMU_TIMER_CHANNEL == TMU_TIMER2
        #if TMU_OS_TICK >= 1U && TMU_OS_TICK <= 200U
            TCCR2 = 0x04; // 64-pres , ovf , oc0 pin disconnected
            
            u32 u32Counts = (TMU_OS_TICK * TMU_CPU_FREQ)/(64UL);

            LOC_u32OvfCounts = (u32Counts + 255LLU) / 256LLU;

            LOC_u8Preload = 256U - (u32Counts % 256LLU);
            
            TCNT2 = LOC_u8Preload;

            LOC_u32ISRCounter = LOC_u32OvfCounts;

            TIMSK |= (1<<6);
        #else
            #error TMU OS tick must be between [ 1 : 200 ] msec
        #endif
    #else
        #error TMU timer channel configuration is wrong [TMU_TIMER0 - TMU_TIMER1 - TMU_TIMER2]
    #endif
}


void TMU_vidCreateTask(void(*pfunTask)(void) , u8 u8Priority , u16 u16Periodicity)
{
    if (u8Priority < TMU_MAX_TASK_NUM)
    {
        LOC_astrTasks[u8Priority].pfunTask = pfunTask;
        LOC_astrTasks[u8Priority].u16Periodicity = u16Periodicity;
    }
}

void TMU_vidStartScheduler(void)
{
    u32 u32PrevOsTicksCounts = 0UL;
    __asm__("sei");
    while(1)
    {
        if (LOC_u32OSTicksCounter > u32PrevOsTicksCounts)
        {
            u32PrevOsTicksCounts = LOC_u32OSTicksCounter;
            // 0 lowest, max-1 highest
            // for (s8 u8Priority = TMU_MAX_TASK_NUM-1 ; u8Priority >= 0; u8Priority--)
            // 0 highest, max-1 lowest
            for (u8 u8Priority = 0; u8Priority < TMU_MAX_TASK_NUM; u8Priority++)
            {
                if ((LOC_astrTasks[u8Priority].pfunTask != NULL) &&
                ((LOC_u32OSTicksCounter % LOC_astrTasks[u8Priority].u16Periodicity) == 0U))
                {
                    LOC_astrTasks[u8Priority].pfunTask();
                }
            }
        }
    }
}




#if TMU_TIMER_CHANNEL == TMU_TIMER0
    void __vector_11(void)__attribute__((signal));
    void __vector_11(void)
    {
        LOC_u32ISRCounter--;
        if (! LOC_u32ISRCounter)
        {
            // run scheduler
            LOC_u32OSTicksCounter++;

            LOC_u32ISRCounter = LOC_u32OvfCounts;
            TCNT0 = LOC_u8Preload;
        }
    }
#elif TMU_TIMER_CHANNEL == TMU_TIMER1
    void __vector_7(void)__attribute__((signal));
    void __vector_7(void)
    {
        // run scheduler
        LOC_u32OSTicksCounter++;
    }
#elif TMU_TIMER_CHANNEL == TMU_TIMER2
    void __vector_5(void)__attribute__((signal));
    void __vector_5(void)
    {
        LOC_u32ISRCounter--;
        if (! LOC_u32ISRCounter)
        {
            // run scheduler
            LOC_u32OSTicksCounter++;

            LOC_u32ISRCounter = LOC_u32OvfCounts;
            TCNT2 = LOC_u8Preload;
        }
    }
#endif

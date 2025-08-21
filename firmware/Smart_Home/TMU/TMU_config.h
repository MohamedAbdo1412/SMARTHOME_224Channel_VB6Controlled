/*
 * TMU_config.h
 *
 *  Created on: Aug 5, 2025
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TMU_TMU_CONFIG_H_
#define TMU_TMU_CONFIG_H_

// 1ms : 200 ms
#define TMU_OS_TICK                (5U)

// in KHz
#define TMU_CPU_FREQ               (16000UL) 

//  TMU_TIMER0 - TMU_TIMER1 - TMU_TIMER2
#define TMU_TIMER_CHANNEL          TMU_TIMER2  

// max tasks num is 10
#define TMU_MAX_TASK_NUM           (10U) 

#endif /* TMU_TMU_CONFIG_H_ */

/*
 * sensorsch.h
 *
 *  Created on: Aug 19, 2025
 *      Author: DELL
 */

#ifndef HAL_SENSORS_CHANNELS_SENSORSCH_H_
#define HAL_SENSORS_CHANNELS_SENSORSCH_H_

#define MULTI_TEMP 1U
#define MULTI_SENSORS 2U
#define MULTI_SENSORS_EN PD3
#define MULTI_TEMP_EN PD7
#define ROOM_SELECT_A PB0
#define ROOM_SELECT_B PB1
#define ROOM_SELECT_C PB2
#define ROOM_SELECT_D PB3
#define CHANNEL_SELECT_A PB4
#define CHANNEL_SELECT_B PB5
#define CHANNEL_SELECT_C PB6
#define FLAME_CHANNEL 1U
#define GAS_CHANNEL 2U
#define PIR_CHANNEL 3U
#define TEMP_CHANNEL 4U
#include "../../LIB/PrimitiveTypes.h"



#define TEMP_NO_SENSOR_THRESHOLD 7U
#define ONOFF_SENSOR_THRESHOLD 200U
void SENSORS_vidInit(void);
void SENSORS_vidUpdateTemp(u8 Room);
void SENSORS_vidUpdateFlame(u8 Room);
void SENSORS_vidUpdateGas(u8 Room);
void SENSORS_vidUpdatePir(u8 Room);

#endif /* HAL_SENSORS_CHANNELS_SENSORSCH_H_ */

/*
 * onoffch.h
 *
 *  Created on: Aug 18, 2025
 *      Author: DELL
 */

#ifndef HAL_ON_OFF_CHANNELS_ONOFFCH_H_
#define HAL_ON_OFF_CHANNELS_ONOFFCH_H_
#define ROOM_SELECT_A PB0
#define ROOM_SELECT_B PB1
#define ROOM_SELECT_C PB2
#define ROOM_SELECT_D PB3
#define CHANNEL_SELECT_A PB4
#define CHANNEL_SELECT_B PB5
#define CHANNEL_SELECT_C PB6
#define MULTI_CONTROL PD2
#define MULTI_CONTROL_EN PD4
#define LE PD6
#define MR PB7

#define ON 1U
#define OFF 0U

void vidChannelInit(void);
void vidChannelOn(u8 u8RoomNum ,u8 u8ChannelNum);
void vidChannelOff(u8 u8RoomNum ,u8 u8ChannelNum);
void vidChannelToggle(u8 u8RoomNum ,u8 u8ChannelNum);

#endif /* HAL_ON_OFF_CHANNELS_ONOFFCH_H_ */

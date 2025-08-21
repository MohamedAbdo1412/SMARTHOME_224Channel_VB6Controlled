/*
 * onoffch.c

 *
 *  Created on: Aug 18, 2025
 *      Author: DELL
 */
#include "avr/delay.h"
#include "../../LIB/PrimitiveTypes.h"
#include "../../MCAL/PIN/PIN_int.h"
#include "onoffch.h"
#include "../DataKeeper/DataKeeper.h"



void vidChannelInit(void){
	Rooms_Init(DataKeeper , 16);
	PIN_vidSetMode(ROOM_SELECT_A , OUTPUT_LOW);
	PIN_vidSetMode(ROOM_SELECT_B , OUTPUT_LOW);
	PIN_vidSetMode(ROOM_SELECT_C , OUTPUT_LOW);
	PIN_vidSetMode(ROOM_SELECT_D , OUTPUT_LOW);
	PIN_vidSetMode(CHANNEL_SELECT_A , OUTPUT_LOW);
	PIN_vidSetMode(CHANNEL_SELECT_B , OUTPUT_LOW);
	PIN_vidSetMode(CHANNEL_SELECT_C , OUTPUT_LOW);
	PIN_vidSetMode(MULTI_CONTROL , OUTPUT_HIGH);
	PIN_vidSetMode(MULTI_CONTROL_EN , OUTPUT_HIGH);
	PIN_vidSetMode(LE , OUTPUT_HIGH);
	PIN_vidSetMode(MR , OUTPUT_HIGH);
	_delay_ms(1);
}
void vidChannelOn(u8 u8RoomNum ,u8 u8ChannelNum){
	u8RoomNum--;
	u8ChannelNum--;
	PIN_vidSetValue(ROOM_SELECT_A ,(u8RoomNum>>0) & 1);
	PIN_vidSetValue(ROOM_SELECT_B ,(u8RoomNum>>1) & 1);
	PIN_vidSetValue(ROOM_SELECT_C ,(u8RoomNum>>2) & 1);
	PIN_vidSetValue(ROOM_SELECT_D ,(u8RoomNum>>3) & 1);
	PIN_vidSetValue(CHANNEL_SELECT_A , (u8ChannelNum>>0) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_B , (u8ChannelNum>>1) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_C , (u8ChannelNum>>2) & 1 );
	PIN_vidSetValue(MULTI_CONTROL , HIGH);
	PIN_vidSetValue(MULTI_CONTROL_EN , LOW);
	PIN_vidSetValue(LE , LOW);
	PIN_vidSetValue(LE , HIGH);
	PIN_vidSetValue(MULTI_CONTROL_EN , HIGH);
	DataKeeper[u8RoomNum].channelBits |= (1 << u8ChannelNum); // Setting Bit
}
void vidChannelOff(u8 u8RoomNum ,u8 u8ChannelNum){
	u8RoomNum--;
	u8ChannelNum--;
	PIN_vidSetValue(ROOM_SELECT_A ,(u8RoomNum>>0) & 1);
	PIN_vidSetValue(ROOM_SELECT_B ,(u8RoomNum>>1) & 1);
	PIN_vidSetValue(ROOM_SELECT_C ,(u8RoomNum>>2) & 1);
	PIN_vidSetValue(ROOM_SELECT_D ,(u8RoomNum>>3) & 1);
	PIN_vidSetValue(CHANNEL_SELECT_A , (u8ChannelNum>>0) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_B , (u8ChannelNum>>1) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_C , (u8ChannelNum>>2) & 1 );
	PIN_vidSetValue(MULTI_CONTROL , LOW);
	PIN_vidSetValue(MULTI_CONTROL_EN , LOW);
	PIN_vidSetValue(LE , LOW);
	PIN_vidSetValue(LE , HIGH);
	PIN_vidSetValue(MULTI_CONTROL_EN , HIGH);
	DataKeeper[u8RoomNum].channelBits &= ~(1 << u8ChannelNum); // Clearing Bit
}
void vidChannelToggle(u8 u8RoomNum ,u8 u8ChannelNum){
	u8RoomNum--;
	u8ChannelNum--;
	u8 bitVal = (DataKeeper[u8RoomNum].channelBits >> u8ChannelNum) & 1;
	if(bitVal == ON){
		vidChannelOff(u8RoomNum+1 ,u8ChannelNum+1);
	}else if(bitVal== OFF){
		vidChannelOn(u8RoomNum+1 ,u8ChannelNum+1);
	}

}

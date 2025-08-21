/*
 * sensorsch.c

 *
 *  Created on: Aug 19, 2025
 *      Author: DELL
 */
#include "util/delay.h"
#include "sensorsch.h"
#include "../../LIB/PrimitiveTypes.h"
#include "../DataKeeper/DataKeeper.h"
#include "../../MCAL/PIN/PIN_int.h"
#include "../../MCAL/ADC/ADC_int.h"

void SENSORS_vidInit(void){
	PIN_vidSetMode(MULTI_SENSORS_EN,OUTPUT_HIGH);
	PIN_vidSetMode(MULTI_TEMP_EN,OUTPUT_HIGH);
}
void SENSORS_vidUpdateTemp(u8 Room){
	PIN_vidSetValue(MULTI_TEMP_EN,LOW);
	PIN_vidSetValue(ROOM_SELECT_A ,(Room>>0) & 1);
	PIN_vidSetValue(ROOM_SELECT_B ,(Room>>1) & 1);
	PIN_vidSetValue(ROOM_SELECT_C ,(Room>>2) & 1);
	PIN_vidSetValue(ROOM_SELECT_D ,(Room>>3) & 1);
	u16 u16ADCRead = ADC_u16GetRead(MULTI_TEMP);
	float tempC = ((float)u16ADCRead / 1023.0f) * 5.0f * 100.0f;
	if(tempC < TEMP_NO_SENSOR_THRESHOLD) tempC = 0;  	//THRESHOLD FOR NO POWER
	DataKeeper[Room].sensors[0] = (u8)tempC;
	PIN_vidSetValue(MULTI_TEMP_EN,HIGH);
}

void SENSORS_vidUpdateFlame(u8 Room){
	PIN_vidSetValue(MULTI_SENSORS_EN,LOW);
	PIN_vidSetValue(ROOM_SELECT_A ,(Room>>0) & 1);
	PIN_vidSetValue(ROOM_SELECT_B ,(Room>>1) & 1);
	PIN_vidSetValue(ROOM_SELECT_C ,(Room>>2) & 1);
	PIN_vidSetValue(ROOM_SELECT_D ,(Room>>3) & 1);
	PIN_vidSetValue(CHANNEL_SELECT_A , (FLAME_CHANNEL>>0) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_B , (FLAME_CHANNEL>>1) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_C , (FLAME_CHANNEL>>2) & 1 );
	u16 u16ADCRead = ADC_u16GetRead(2);
	if(u16ADCRead > ONOFF_SENSOR_THRESHOLD ){
		DataKeeper[Room].sensors[1] = 1;
	}else{
		DataKeeper[Room].sensors[1] = 0;
	}
	PIN_vidSetValue(MULTI_SENSORS_EN,HIGH);
}

void SENSORS_vidUpdateGas(u8 Room){
	PIN_vidSetValue(MULTI_SENSORS_EN,LOW);
	PIN_vidSetValue(ROOM_SELECT_A ,(Room>>0) & 1);
	PIN_vidSetValue(ROOM_SELECT_B ,(Room>>1) & 1);
	PIN_vidSetValue(ROOM_SELECT_C ,(Room>>2) & 1);
	PIN_vidSetValue(ROOM_SELECT_D ,(Room>>3) & 1);
	PIN_vidSetValue(CHANNEL_SELECT_A , (GAS_CHANNEL>>0) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_B , (GAS_CHANNEL>>1) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_C , (GAS_CHANNEL>>2) & 1 );
	u16 u16ADCRead = ADC_u16GetRead(MULTI_SENSORS);
	if(u16ADCRead > ONOFF_SENSOR_THRESHOLD ){
		DataKeeper[Room].sensors[2] = 1;
	}else{
		DataKeeper[Room].sensors[2] = 0;
	}
	PIN_vidSetValue(MULTI_SENSORS_EN,HIGH);
}
void SENSORS_vidUpdatePir(u8 Room){
	PIN_vidSetValue(MULTI_SENSORS_EN,LOW);
	PIN_vidSetValue(ROOM_SELECT_A ,(Room>>0) & 1);
	PIN_vidSetValue(ROOM_SELECT_B ,(Room>>1) & 1);
	PIN_vidSetValue(ROOM_SELECT_C ,(Room>>2) & 1);
	PIN_vidSetValue(ROOM_SELECT_D ,(Room>>3) & 1);
	PIN_vidSetValue(CHANNEL_SELECT_A , (PIR_CHANNEL>>0) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_B , (PIR_CHANNEL>>1) & 1 );
	PIN_vidSetValue(CHANNEL_SELECT_C , (PIR_CHANNEL>>2) & 1 );
	u16 u16ADCRead = ADC_u16GetRead(MULTI_SENSORS);
	if(u16ADCRead > ONOFF_SENSOR_THRESHOLD ){
		DataKeeper[Room].sensors[3] = 1;
	}else{
		DataKeeper[Room].sensors[3] = 0;
	}
	PIN_vidSetValue(MULTI_SENSORS_EN,HIGH);
}

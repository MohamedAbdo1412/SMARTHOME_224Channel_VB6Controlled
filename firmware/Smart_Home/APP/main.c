/**************************************************************************************
 *  Project   : 224 Channels Smart Home
 *  File      : <main.c>
 *  Author    : <Mohamed Abdelhamid> (VB6 PC Control + MCU Firmware)
 *  Email     : <trapcloud8@gmail.com>
 *  GitHub    : <https://github.com/MohamedAbdo1412>
 *  Version   : v0.1.0
 *  Date      : <2025/08/21>
 *
 *  Description:
 *      - 16 rooms × 14 channels/room = 224 channels
 *      - 8 ON/OFF relays, 2 PWM servos, 4 sensors (Temp, PIR, Gas, Flame) per room
 *      - PC control via VB6 over UART
 *
 *  Target MCU : <ATmega32 / ESP32 / ...>
 *  Toolchain  : <AVR-GCC / Eclipse>
 *  Clock      : <F_CPU 16000000Hz>
 *
 *  Interfaces :
 *      - UART: PC (VB6) <-> Atmega32
 *      - PWM : Servo drivers (2 per room)
 *      - ADC : Sensor inputs (Temp/Gas/Flame as applicable)
 *
 *  Notes:
 *      - AREF tied to <REFERENCE>
 *      - Matrix addressing nets: X0..X13, LE_X0..LE_X13, etc.
 *
 *  License   : MIT (see LICENSE file)
 *
 *  Change Log:
 *      - v0.1.0: Initial commit, room/channel scaffolding.
 **************************************************************************************/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../LIB/PrimitiveTypes.h"
#include "avr/delay.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/Timer0/Timer_int.h"
#include "../MCAL/PIN/PIN_int.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/I2C/i2c.h"
#include "../HAL/PCA9685/pca9685.h"
#include "../TMU/TMU_int.h"
#include "../HAL/ON_OFF_CHANNELS/onoffch.h"
#include "../HAL/DataKeeper/DataKeeper.h"
#include "../HAL/SENSORS_CHANNELS/sensorsch.h"


#define SERVO_CHANNEL_A_PIN 0x40
#define SERVO_CHANNEL_B_PIN 0x41
#define I2C_FREQ 100000
#define PWM_FREQ 50






char ReceiveBuffer[15];
int roomIndex=0;
char Response[30];

void byteToBinaryStr(uint8_t val, char *str) {
    for (int i = 7; i >= 0; i--) {
        str[7 - i] = (val & (1 << i)) ? '1' : '0';
    }
    str[8] = '\0';
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// parseUPT Function ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int parseUPT(const char *str) {
    if (str == NULL) return -1;
    if (strncmp(str, "UPT", 3) != 0) return -1;

    int room = atoi(str + 3);
    if (room < 1 || room > 16) return -1;

    return room;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// parseSEN Function ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int parseSEN(const char *str) {
    if (str == NULL) return -1;
    if (strncmp(str, "SEN", 3) != 0) return -1;

    int room = atoi(str + 3);
    if (room < 1 || room > 16) return -1;

    return room;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////
// parseTOG Function Made By ChatGPT ////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct {
    int room;
    int channel;
} TOG_Info;

TOG_Info parseTOG(const char *str) {
    TOG_Info info;
    char roomStr[3];
    char chStr[2];

    if (strncmp(str, "TOG", 3) != 0) {

        info.room = -1;
        info.channel = -1;
        return info;
    }

    strncpy(roomStr, str + 3, 2);
    roomStr[2] = '\0';

    strncpy(chStr, str + 5, 1);
    chStr[1] = '\0';

    info.room = atoi(roomStr);
    info.channel = atoi(chStr);

    return info;
}











/////////////////////////////////////////////////////////////////////////////////////////////////////////
// parseSER Function Made By ChatGPT ////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct {
    int room;
    int channel;
    int value;
} SER_Info;

SER_Info parseSER(const char *str) {
    SER_Info info;
    char roomStr[3];
    char chStr[2];
    char signStr[2];
    char valStr[3];

    if (strncmp(str, "SER", 3) != 0) {
        info.room = -1;
        info.channel = -1;
        info.value = 0;
        return info;
    }

    // Room → اول رقمين بعد "SER"
    strncpy(roomStr, str + 3, 2);
    roomStr[2] = '\0';

    // Channel → الرقم التالت بعد "SER"
    strncpy(chStr, str + 5, 1);
    chStr[1] = '\0';

    // Sign → الرقم الرابع بعد "SER" (0=positive, 1=negative)
    strncpy(signStr, str + 6, 1);
    signStr[1] = '\0';

    // آخر رقمين → القيمة
    strncpy(valStr, str + 7, 2);
    valStr[2] = '\0';

    info.room = atoi(roomStr);
    info.channel = atoi(chStr);
    info.value = atoi(valStr);

    // طبق الإشارة (sign)
    if (atoi(signStr) == 1) {
        info.value = -info.value;
    }

    return info;
}






/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Sensors Refreshes  ///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void RefreshSensors(void){
	SENSORS_vidUpdateTemp(roomIndex);
	SENSORS_vidUpdateFlame(roomIndex);
	SENSORS_vidUpdateGas(roomIndex);
	SENSORS_vidUpdatePir(roomIndex);
}



void RefreshSensors_Init(void){
	for(int i=0 ; i<16 ; i++){
		SENSORS_vidUpdateFlame(i);
		SENSORS_vidUpdateGas(i);
		SENSORS_vidUpdatePir(i);
		SENSORS_vidUpdateTemp(i);

	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Response Refreshes ///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


void RefreshResponse(void){
		u8 channelMask = DataKeeper[roomIndex].channelBits; // replace with your logic per room
	    u8 temp   = DataKeeper[roomIndex].sensors[0];
	    u8 flame  = DataKeeper[roomIndex].sensors[1];
	    u8 gas    = DataKeeper[roomIndex].sensors[2];
	    u8 pir    = DataKeeper[roomIndex].sensors[3];

	    int servoA = DataKeeper[roomIndex].servoAngleA;
	    int servoB = DataKeeper[roomIndex].servoAngleB;

	    char servoASign = (servoA < 0) ? '1' : '0';
	    char servoBSign = (servoB < 0) ? '1' : '0';

	    if(servoA < 0) servoA = -servoA;
	    if(servoB < 0) servoB = -servoB;

	    // Build the string
	    char maskStr[9];
	    byteToBinaryStr(channelMask, maskStr);

	    sprintf(Response, "RES%s%02d%d%d%d%c%02d%c%02d\r\n",
	            maskStr,          // هنا بدل %08d
	            temp, flame, gas, pir,
	            servoASign, servoA,
	            servoBSign, servoB);

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Task_ParseUART(void){
    static char line[24];
        UART_vidReceiveStringUntilNewline(line, sizeof(line));;
            if(strncmp(line, "UPT",3)==0) {
                roomIndex = parseUPT(line)-1;
                UART_vidSendString(Response);
            } else if(strncmp(line,"SER",3)==0) {
                SER_Info SER = parseSER(line);
                uint8_t ch = (SER.channel==0)?SERVO_CHANNEL_A_PIN:SERVO_CHANNEL_B_PIN;
                PCA9685_SetServoAngle(ch, SER.room, SER.value);
            } else if(strncmp(line,"TOG",3)==0) {
                TOG_Info TOG = parseTOG(line);
                vidChannelToggle(TOG.room, TOG.channel);
            } else if(strncmp(line,"SEN",3)==0) {
            	roomIndex = parseSEN(line)-1;
            	RefreshSensors();
            } else if(strncmp(line,"BUZ",3)==0) {
            	PIN_vidSetValue(PD5 , HIGH);
            }
}






int main(void) {
	GIE_vidEnable();
	vidChannelInit();
	ADC_vidInit();
	SENSORS_vidInit();

	UART_vidInit();
	I2C_Init(I2C_FREQ);

	PCA9685_Init(SERVO_CHANNEL_A_PIN);
	PCA9685_Init(SERVO_CHANNEL_B_PIN);

	PCA9685_SetPWMFreq(SERVO_CHANNEL_A_PIN, PWM_FREQ);
	PCA9685_SetPWMFreq(SERVO_CHANNEL_B_PIN, PWM_FREQ);

	RefreshSensors_Init();
	while(1){
		Task_ParseUART();
		RefreshResponse();
	}
}

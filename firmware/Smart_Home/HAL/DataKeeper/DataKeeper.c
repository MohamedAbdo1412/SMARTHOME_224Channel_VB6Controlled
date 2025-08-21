/*
 * DataKeeper.c
 *
 *  Created on: Aug 19, 2025
 *      Author: DELL
 */
#include "../../LIB/PrimitiveTypes.h"
#include "DataKeeper.h"

RoomData DataKeeper[16];

void Rooms_Init(RoomData *data, u8 size){
    for(u8 i=0; i<size; i++){
        data[i].channelBits = 0;
        for(u8 j=0; j<4; j++){
            data[i].sensors[j] = 0;  // مثلاً -1 يعني "غير مستخدم"
        }
        data[i].servoAngleA = 0;
        data[i].servoAngleB = 0;
    }
}

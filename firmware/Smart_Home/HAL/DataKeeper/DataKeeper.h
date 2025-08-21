/*
 * DataKeeper.h
 *
 *  Created on: Aug 19, 2025
 *      Author: DELL
 */

#ifndef HAL_DATAKEEPER_DATAKEEPER_H_
#define HAL_DATAKEEPER_DATAKEEPER_H_
#include "../../LIB/PrimitiveTypes.h"

typedef struct {
    u8 channelBits;
    s8  sensors[4];
    float  servoAngleA;
    float  servoAngleB;
} RoomData;

extern RoomData DataKeeper[16];

void Rooms_Init(RoomData *data, u8 size);

#endif /* HAL_DATAKEEPER_DATAKEEPER_H_ */

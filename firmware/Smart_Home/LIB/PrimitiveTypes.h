/*
 * PrimitiveTypes.h
 *
 *  Created on: May 22, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#ifndef PRIMITIVETYPES_H_
#define PRIMITIVETYPES_H_


/*****************************************************************/
/******      Solid Definition Of Booleans and NULL       *********/
/*****************************************************************/
typedef enum __Boolean__       {   FALSE=0U   ,   TRUE=1U   }bool;

/*****************************************************************/
/*****************************************************************/


/*****************************************************************/
/***********     Mathematic Constants Definition    **************/
/*****************************************************************/
#define PI                    ((double)3.14159265358979323846)
/*****************************************************************/


/*****************************************************************/
/***********     Bit Mathematics Marco Functions    **************/
/*****************************************************************/
#define SET_BIT(var,bitNo)          ((var) |=  ((1U) << (bitNo)))
#define CLR_BIT(var,bitNo)          ((var) &= ~((1U) << (bitNo)))
#define TOG_BIT(var,bitNo)          ((var) ^=  ((1U) << (bitNo)))

#define GET_BIT(var,bitNo)          (((var)  >>  (bitNo))  &  1U)

#define ASSIGN_BIT(var,bitNo,val)   ((var) &=~((1U) << (bitNo)));\
                                    ((var) |= ((val) << (bitNo)))
/*****************************************************************/
/*****************************************************************/


/*****************************************************************/
/******   New type definitions of Primitive Data Types   *********/
/*****************************************************************/
typedef      unsigned char                         BOOL ;
typedef      unsigned char                         u8   ;
typedef      signed char                           s8   ;
typedef      unsigned short                        u16  ;
typedef      signed short                          s16  ;
typedef      unsigned long                         u32  ;
typedef      signed long                           s32  ;
typedef      unsigned long long                    u64  ;
typedef      signed long long                      s64  ;
/*****************************************************************/
/*****************************************************************/


#endif /* PRIMITIVETYPES_H_ */

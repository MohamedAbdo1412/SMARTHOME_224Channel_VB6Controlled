/*
 * PIN_prog.c
 *
 *  Created on: Jul 29, 2025
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../LIB/PrimitiveTypes.h"
#include "PIN_priv.h"
#include "PIN_config.h"
#include "PIN_int.h"


void PIN_vidSetMode(u8 u8PinNum , u8 u8Mode)
{
    if ((u8PinNum >= PA0) && (u8PinNum <= PD7) && 
        (u8Mode >= INPUT_FLOAT) && (u8Mode <= OUTPUT_HIGH))
    {
        // A 0-7 , B 8-15 , C 16-23 , D 24-31
        u8 u8GroupID = u8PinNum / 8U;
        u8 u8BitNum  = u8PinNum % 8U;
        u8 u8Direction = ((u8Mode>>1) &1); //get //bit 0 for PORT , bit 1 for DDR
        u8 u8Value     = ((u8Mode>>0) &1); //get //bit 0 for PORT , bit 1 for DDR

        switch (u8GroupID)
        {
            case DIO_GROUP_A:
            {
                DDRA &=~(1U << u8BitNum);
                DDRA |= (u8Direction << u8BitNum);

                PORTA &=~(1U << u8BitNum);
                PORTA |= (u8Value << u8BitNum);
                break;
            }    
            case DIO_GROUP_B:
            {
                DDRB &=~(1U << u8BitNum);
                DDRB |= (u8Direction << u8BitNum);
        
                PORTB &=~(1U << u8BitNum);
                PORTB |= (u8Value << u8BitNum);
                break;
            }    
            case DIO_GROUP_C:
            {
                DDRC &=~(1U << u8BitNum);
                DDRC |= (u8Direction << u8BitNum);
        
                PORTC &=~(1U << u8BitNum);
                PORTC |= (u8Value << u8BitNum);
                break;
            }    
            case DIO_GROUP_D:
            {
                DDRD &=~(1U << u8BitNum);
                DDRD |= (u8Direction << u8BitNum);
        
                PORTD &=~(1U << u8BitNum);
                PORTD |= (u8Value << u8BitNum);
                break;
            }    
            default:
                break;
        }
    }
}

void PIN_vidSetValue(u8 u8PinNum , u8 u8Value)
{
    if ((u8PinNum >= PA0) && (u8PinNum <= PD7) && 
    (u8Value >= LOW) && (u8Value <= HIGH))
    {
        // A 0-7 , B 8-15 , C 16-23 , D 24-31
        u8 u8GroupID = u8PinNum / 8U;
        u8 u8BitNum  = u8PinNum % 8U;
        switch (u8GroupID)
        {
            case DIO_GROUP_A:
            {
                // if (u8Value == LOW)
                //     PORTA &=~(1<< u8BitNum);
                // else
                //     PORTA |= (1<< u8BitNum);
                
                PORTA = (u8Value == LOW)? (PORTA &(~(1<<u8BitNum))) : (PORTA | (1<<u8BitNum));
                break;
            }    
            case DIO_GROUP_B:
            {
                PORTB = (u8Value == LOW)? (PORTB &(~(1<<u8BitNum))) : (PORTB | (1<<u8BitNum));
                break;
            }    
            case DIO_GROUP_C:
            {
                PORTC = (u8Value == LOW)? (PORTC &(~(1<<u8BitNum))) : (PORTC | (1<<u8BitNum));
                break;
            }    
            case DIO_GROUP_D:
            {
                PORTD = (u8Value == LOW)? (PORTD &(~(1<<u8BitNum))) : (PORTD | (1<<u8BitNum));
                break;
            }    
            default:
            break;
        }
    }
}

void PIN_vidTogValue(u8 u8PinNum)
{
    if ((u8PinNum >= PA0) && (u8PinNum <= PD7))
    {
        // A 0-7 , B 8-15 , C 16-23 , D 24-31
        u8 u8GroupID = u8PinNum / 8U;
        u8 u8BitNum  = u8PinNum % 8U;
        switch (u8GroupID)
        {
            case DIO_GROUP_A:
            {
                PORTA ^= (1<<u8BitNum);
                break;
            }    
            case DIO_GROUP_B:
            {
                PORTB ^= (1<<u8BitNum);
                break;
            }    
            case DIO_GROUP_C:
            {
                PORTC ^= (1<<u8BitNum);
                break;
            }    
            case DIO_GROUP_D:
            {
                PORTD ^= (1<<u8BitNum);
                break;
            }    
            default:
            break;
        }

    }
}

BOOL PIN_bGetValue(u8 u8PinNum)
{
    BOOL bPinValue = 0xFFU;
    if ((u8PinNum >= PA0) && (u8PinNum <= PD7))
    {
        // A 0-7 , B 8-15 , C 16-23 , D 24-31
        u8 u8GroupID = u8PinNum / 8U;
        u8 u8BitNum  = u8PinNum % 8U;
        switch (u8GroupID)
        {
            case DIO_GROUP_A:
            {
                bPinValue = ((PINA>>u8BitNum) & 1);
                break;
            }    
            case DIO_GROUP_B:
            {
                bPinValue = ((PINB>>u8BitNum) & 1);
                break;
            }    
            case DIO_GROUP_C:
            {
                bPinValue = ((PINC>>u8BitNum) & 1);
                break;
            }    
            case DIO_GROUP_D:
            {
                bPinValue = ((PIND>>u8BitNum) & 1);
                break;
            }    
            default:
            break;
        }
    }
    return bPinValue;
}

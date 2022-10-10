/*
 * DIO_prog.c
 *
 *  Created on: Sep 16, 2022
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_vWritePinDirection(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8Dir)
{
	if(A_u8Dir == DIO_OUTPUT)
	{
		switch(A_u8PortId)
		{
			case DIO_PORTA:	SET_BIT(DDRA,A_u8PinNo); break;
			case DIO_PORTB:	SET_BIT(DDRB,A_u8PinNo); break;
			case DIO_PORTC:	SET_BIT(DDRC,A_u8PinNo); break;
			case DIO_PORTD:	SET_BIT(DDRD,A_u8PinNo); break;
		}
	}else if(A_u8Dir == DIO_INPUT)
	{
		switch(A_u8PortId)
		{
			case DIO_PORTA:	CLR_BIT(DDRA,A_u8PinNo); break;
			case DIO_PORTB:	CLR_BIT(DDRB,A_u8PinNo); break;
			case DIO_PORTC:	CLR_BIT(DDRC,A_u8PinNo); break;
			case DIO_PORTD:	CLR_BIT(DDRD,A_u8PinNo); break;
		}
	}

}

void DIO_vWritePinValue(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8Value)
{
	if(A_u8Value == DIO_HIGH)
	{
		switch(A_u8PortId)
		{
			case DIO_PORTA:	SET_BIT(PORTA,A_u8PinNo); break;
			case DIO_PORTB:	SET_BIT(PORTB,A_u8PinNo); break;
			case DIO_PORTC:	SET_BIT(PORTC,A_u8PinNo); break;
			case DIO_PORTD:	SET_BIT(PORTD,A_u8PinNo); break;
		}
	}else if(A_u8Value == DIO_LOW)
	{
		switch(A_u8PortId)
		{
			case DIO_PORTA:	CLR_BIT(PORTA,A_u8PinNo); break;
			case DIO_PORTB:	CLR_BIT(PORTB,A_u8PinNo); break;
			case DIO_PORTC:	CLR_BIT(PORTC,A_u8PinNo); break;
			case DIO_PORTD:	CLR_BIT(PORTD,A_u8PinNo); break;
		}
	}
}

u8 DIO_u8ReadPinValue(u8 A_u8PortId, u8 A_u8PinNo)
{
	u8 L_u8PinValue = 0; //L =>local
	switch(A_u8PortId)
	{
		case DIO_PORTA:	L_u8PinValue = GET_BIT(PINA,A_u8PinNo);	break;
		case DIO_PORTB:	L_u8PinValue = GET_BIT(PINB,A_u8PinNo);	break;
		case DIO_PORTC:	L_u8PinValue = GET_BIT(PINC,A_u8PinNo);	break;
		case DIO_PORTD:	L_u8PinValue = GET_BIT(PIND,A_u8PinNo);	break;
	}
	return L_u8PinValue;
}
void DIO_vTogglePin(u8 A_u8PortId, u8 A_u8PinNo)
{
	switch(A_u8PortId)
	{
		case DIO_PORTA:	TOG_BIT(PORTA,A_u8PinNo); break;
		case DIO_PORTB:	TOG_BIT(PORTB,A_u8PinNo); break;
		case DIO_PORTC:	TOG_BIT(PORTC,A_u8PinNo); break;
		case DIO_PORTD:	TOG_BIT(PORTD,A_u8PinNo); break;
	}
}


void DIO_vWritePortDirection(u8 A_u8PortId,  u8 A_u8Dir)
{
	switch(A_u8PortId)
	{
		case DIO_PORTA: DDRA = A_u8Dir;	break;
		case DIO_PORTB:	DDRB = A_u8Dir;	break;
		case DIO_PORTC:	DDRD = A_u8Dir;	break;
		case DIO_PORTD:	DDRD = A_u8Dir;	break;
	}
}

void DIO_vWritePortValue(u8 A_u8PortId, u8 A_u8Value)
{
	switch(A_u8PortId)
	{
		case DIO_PORTA: PORTA = A_u8Value;	break;
		case DIO_PORTB:	PORTB = A_u8Value;	break;
		case DIO_PORTC:	PORTC = A_u8Value;	break;
		case DIO_PORTD:	PORTD = A_u8Value;	break;
	}
}

u8 DIO_u8ReadPortValue(u8 A_u8PortId)
{
	u8 L_u8PortValue = 0;
	switch(A_u8PortId)
	{
		case DIO_PORTA: L_u8PortValue= PORTA ;	break;
		case DIO_PORTB:	L_u8PortValue= PORTB ;	break;
		case DIO_PORTC:	L_u8PortValue= PORTC ;	break;
		case DIO_PORTD:	L_u8PortValue= PORTD ;	break;
	}
	return L_u8PortValue;
}

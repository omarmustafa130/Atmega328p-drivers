#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_private.h"


#include <util/delay.h>
void HKeypad_voidInit(Keypad_t* K){
	
	for(u8 i = 0; i < K->Rows; i++){
		MGPIO_voidSetPinDirection(K->RowPorts[i],K->RowPins[i],GPIO_INPUT_PULLUP);
	}
	
	for(u8 i = 0; i < K->Columns; i++){
		MGPIO_voidSetPinDirection(K->ColumnPorts[i],K->ColumnPins[i],GPIO_OUTPUT);
	}
	PKeypad_voidDisableColumns(K);
	
}

u8 HKeypad_u8GetKey(Keypad_t* K){
	//Variable to hold the pressed key value
	u8 Local_u8PressedKey = 0;
	//variables to hold timeout, or 1 in case of blocking == 0
	u32 Local_u32Timeout = K->Blocking == 0?	1:K->Blocking;
	
	while(Local_u32Timeout){
		for(u8 i = 0; i < K->Columns; i++){
			PKeypad_voidEnableColumn(K,i);
			u8 RowsValue = PKeypad_u8ReadRows(K);
			u8 ZeroIndex = PKeypad_u8GetZeroIndex(RowsValue,K->Rows);
			if(ZeroIndex != 255){
				Local_u8PressedKey = *((K->Map)+ZeroIndex*(K->Columns)+i);	
				break;
			}
		}
		if (Local_u8PressedKey != 0)
			break;
		if(K->Blocking != 0)
			Local_u32Timeout--;
		
	}
	
	
	return Local_u8PressedKey;
}

u8 PKeypad_u8GetZeroIndex(u8 Value, u8 Max){
	
	u8 Local_u8Index = 255;
	for(u8 i = 0; i < Max ; i++)
		Local_u8Index = GET_BIT(Value,i) == 0? i:Local_u8Index;
	return Local_u8Index;
}


u8 PKeypad_u8ReadRows(Keypad_t* K){
	

	volatile u8 Local_u8Value = 0;
	
	for(u8 i = 0; i < K->Rows; i++){
		u8 RowValue = (MGPIO_u8GetPinValue(K->RowPorts[i],K->RowPins[i]) << i);
		Local_u8Value = Local_u8Value | RowValue;
	}
	return Local_u8Value;
}


void PKeypad_voidEnableColumn(Keypad_t* K, u8 Colomn){
	PKeypad_voidDisableColumns(K);
	MGPIO_voidSetPinValue(K->ColumnPorts[Colomn],K->ColumnPins[Colomn],GPIO_LOW);
	
}

void PKeypad_voidDisableColumns(Keypad_t* K){
	for(u8 i = 0;i < K->Columns; i++)
		MGPIO_voidSetPinValue(K->ColumnPorts[i],K->ColumnPins[i],GPIO_HIGH);

}



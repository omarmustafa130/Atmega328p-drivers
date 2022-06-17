#ifndef KEYPAD_PRIVATE_H
#define KEYPAD_PRIVATE_H

u8 PKeypad_u8GetZeroIndex(u8 Value, u8 Max);

u8 PKeypad_u8ReadRows(Keypad_t* K);

void PKeypad_voidEnableColumn(Keypad_t* K, u8 Colomn);

void PKeypad_voidDisableColumns(Keypad_t* K);

#endif


#pragma once
#include "LCD.h"

#define L_SIZE 1
#define MASK 0xFF
#define MODE 1


FT_STATUS lcdWriteNibble(FT_HANDLE* handle, BYTE value, bool rs) {
	FT_STATUS estatus;
	DWORD byteSent = 0;
	char b[L_SIZE];
	b[0] = ((value << 4) & 0xF0);
	if (rs)
		b[0] |= LCD_RS_ON;
	else
		b[0] &= LCD_RS_OFF;
	estatus = FT_Write(*handle, b, L_SIZE, &byteSent);
	if (estatus == FT_OK)
	{
		Sleep(1);
		b[0] |= LCD_E_ON;
		estatus = FT_Write(*handle, b, L_SIZE, &byteSent);
		if (estatus == FT_OK) {
			Sleep(10);
			b[0] &= LCD_E_OFF;
			estatus = FT_Write(*handle, b, L_SIZE, &byteSent);
			if (estatus == FT_OK) {
				Sleep(1);
			}
		}
	}
	return estatus;
}

FT_STATUS lcdWriteByte(FT_HANDLE* handle, BYTE value, bool rs) {
	FT_STATUS estatus = lcdWriteNibble(handle, value >> 4, rs);
	if (estatus == FT_OK) {
		estatus= lcdWriteNibble(handle, value, rs);
	}
	return estatus;
}

void lcdWriteIR(FT_HANDLE* deviceHandler, BYTE value) {
	lcdWriteByte(deviceHandler, value, false);
}

void lcdWriteDR(FT_HANDLE* deviceHandler, BYTE value) {
	lcdWriteByte(deviceHandler, value, true);
}

FT_HANDLE* deviceHandler_lcdInit(int iDevice){
	FT_HANDLE* temp = new FT_HANDLE;
	bool error = false;
	if (FT_Open(iDevice, temp) != FT_OK)
		error = true;
	if (lcdWriteNibble(temp, 0x03, false) != FT_OK)
		error = true;
	Sleep(5);
	if (lcdWriteNibble(temp, 0x03, false) != FT_OK)
		error = true;
	Sleep(1);
	if (lcdWriteNibble(temp, 0x03, false) != FT_OK)
		error = true;
	Sleep(1);
	if (lcdWriteNibble(temp, 0x02, false) != FT_OK)
		error = true;
	Sleep(1);
	if (lcdWriteByte(temp, 0x03, false) != FT_OK)
		error = true;
	if (lcdWriteByte(temp, FUNC_2LINE, false) != FT_OK)
		error = true;
	if (lcdWriteByte(temp, DISPLAY_ALL_ON, false) != FT_OK)
		error = true;
	if (lcdWriteByte(temp, ENTRY_MODE_SET_I, false) != FT_OK)
		error = true;
	if (error)
		delete temp;
	return temp;
}

void closeLCD(FT_HANDLE* deviceHandler) {
	lcdWriteIR(deviceHandler, DISPLAY_ALL_OFF);
	FT_Close(deviceHandler);
	delete deviceHandler;
}
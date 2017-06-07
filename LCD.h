#pragma once
#include "ftd2xx.h"
#include "bajo.h"
#include <ctime>
#include <iostream>
#include <string>

FT_STATUS lcdWriteNibble(FT_HANDLE* handle, BYTE value, bool rs);
FT_STATUS lcdWriteByte(FT_HANDLE* handle, BYTE value, bool rs);
void lcdWriteIR(FT_HANDLE* deviceHandler, BYTE value);
void lcdWriteDR(FT_HANDLE* deviceHandler, BYTE value);
FT_HANDLE* deviceHandler_lcdInit(int iDevice);
void closeLCD(FT_HANDLE* deviceHandler);
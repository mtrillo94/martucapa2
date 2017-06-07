#include "basicLCD.h"

using namespace std;

basicLCD::basicLCD() {
	cadd = 1;
	for (int i = 0; (i < 255) && ((handle=deviceHandler_lcdInit(i)) != NULL); i++)
		if (i == 254)
			cout << "no se encontro el display" << endl;
	return;
}

basicLCD::~basicLCD() {
	closeLCD(handle);
}

bool basicLCD::lcdInitOk(){
	if (estatus != FT_OK)
		return false;
	return true;
}

FT_STATUS basicLCD::lcdGetError() {
	return estatus;
}

bool basicLCD::lcdClear() {
	cursorPosition pos;
	lcdWriteIR(handle, DISP_CLEAR);
	pos.column = 0;
	pos.row = 0;
	lcdSetCursorPosition(pos);
	return true;
}

bool basicLCD::lcdClearToEOL() {
	cursorPosition pos = lcdGetCursorPosition();
	for (int i = 0; i < DISP_LENGTH - pos.column; i++)
		lcdWriteDR(handle,' ');
	return true;
}

basicLCD& basicLCD::operator<<(const unsigned char c) {
	if ((c >= 0x20 && c <= 0x7F) || (c >= 0xA0 && c <= 0xFF))
		lcdWriteDR(handle, c);
	else
		lcdWriteDR(handle, ' ');
	Sleep(10);
	return *this;
}

basicLCD& basicLCD::operator<<(const unsigned char * c) {
	for (int i = 0; c[i] != '\0'; i++)
		*this << c[i];
	return *this;
}

basicLCD& basicLCD::operator<<(string c) {
	for (int i = 0; i<c.size(); i++)
		*this << c[i];
	return *this;
}

bool basicLCD::lcdMoveCursorUp() {
	cursorPosition pos = lcdGetCursorPosition();
	pos.row = 0;
	lcdSetCursorPosition(pos);
	return true;
}

bool basicLCD::lcdMoveCursorDown() {
	cursorPosition pos = lcdGetCursorPosition();
	pos.row = 1;
	lcdSetCursorPosition(pos);
	return true;
}

bool basicLCD::lcdMoveCursorRight()
{
	cursorPosition pos = lcdGetCursorPosition();
	if (pos.column < 15)
		pos.column++;
	else if (pos.row == 0)
	{
		pos.row = 1;
		pos.column = 0;
	}
	lcdSetCursorPosition(pos);
	return true;
}

bool basicLCD::lcdMoveCursorLeft()
{
	cursorPosition pos = lcdGetCursorPosition();
	if (pos.column > 0)
		pos.column--;
	else if (pos.row == 1)
	{
		pos.row = 0;
		pos.column = 15;
	}
	lcdSetCursorPosition(pos);
	return true;
}

bool basicLCD::lcdSetCursorPosition(const cursorPosition pos)
{
	if (pos.column < 0 || pos.column >15 || pos.row < 0 || pos.row >1)
		return false;
	else
	{
		cadd=((16 * pos.row) + pos.column) + 1;
		lcdUpdateCursor();
		return true;
	}
}

cursorPosition basicLCD::lcdGetCursorPosition() {
	cursorPosition pos;
	if (cadd > 16)
		pos.row = 1;
	else
		pos.row = 0;
	pos.column = cadd - (pos.row * 16) - 1;
	return pos;
}

void basicLCD::lcdUpdateCursor() {
	unsigned int row, column;

	if ((cadd - 1) < 16)
		row = 0;
	else
		row = 1;
	column = ((cadd - 1) - (row * 16));
	lcdWriteIR(handle, SET_ADDRESS(column, row));
}
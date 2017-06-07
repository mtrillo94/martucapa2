#pragma once
#include "LCD.h"

#define DISP_LENGTH 15

typedef struct { 
	int row;  
	int column; 
}cursorPosition;

class basicLCD {
public:
	basicLCD();
	~basicLCD();
	bool lcdInitOk();
	FT_STATUS lcdGetError();
	bool lcdClear();
	bool lcdClearToEOL();
	basicLCD& operator<<(const unsigned char c);
	basicLCD& operator<<(string c);
	basicLCD& operator<<(const unsigned char * c);
	bool lcdMoveCursorUp();
	bool lcdMoveCursorDown();
	bool lcdMoveCursorRight();
	bool lcdMoveCursorLeft();
	bool lcdSetCursorPosition(const cursorPosition pos);
	cursorPosition lcdGetCursorPosition();

protected:
	int cadd;
	void lcdUpdateCursor();
	FT_HANDLE* handle;
	FT_STATUS estatus;
};

class martucapa:public basicLCD {

};

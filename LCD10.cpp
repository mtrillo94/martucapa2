#include "LCD10.h"

using namespace std;

void LCD10::scroll(string s,unsigned int j) {
	string s1;
	cursorPosition pos;
	pos.row = 1;
	pos.column = 0;
	basicLCD* b = this;
	b->lcdSetCursorPosition(pos);
	b->lcdClearToEOL();
	for (int i = 0; i < 16 || i < j; i++) 
		s1.push_back(s[s.size() - j - i]);
	basicLCD* b = this;
	*b << s1;
}
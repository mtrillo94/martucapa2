#pragma once
#include "basicLCD.h"
#include <allegro5\allegro.h>


using namespace std;

class LCD10 :public basicLCD {
public:
	void scroll(string s,unsigned int j);
};

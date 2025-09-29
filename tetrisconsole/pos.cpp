#include <string>
#include <iostream>
#include "pos.h"

//this handles all input and some output. I will be potentially moving things to drawing.cpp later.

static HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos{ 10,10 };
std::string snake = "o";

static short Down() {
	position(snake, 0, 1);
	return 0;
}

static short Up() {
	position(snake, 0, -1);
	return 0;
}

static short Right() {
	position(snake, 2, 0);
	return 0;
}

static short Left() {
	position(snake, -2, 0);
	return 0;
}

INPUT_RECORD input() {
	//storing the input
	INPUT_RECORD inputRecord;
	DWORD eventsRead;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inputRecord, 1, &eventsRead);
	return inputRecord;
}


void input_handle() {
	INPUT_RECORD rec = input();
	KEY_EVENT_RECORD key = rec.Event.KeyEvent;
	if (key.bKeyDown) {

		switch (key.wVirtualKeyCode) {

		case 38:
			Up();//up
			break;
		case 40: //down
			Down();
			break;
		case 37: //left
			Left();
			break;
		case 39: //right
			Right();
			break;
		}
	}
}



short position(std::string text, short dx, short dy) {
	pos.X += dx;
	pos.Y += dy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << text << std::flush;
	return 0;
}

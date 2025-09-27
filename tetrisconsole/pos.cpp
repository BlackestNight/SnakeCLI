#include <string>
#include <iostream>
#include "pos.h"

static HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos{ 10,10 };

INPUT_RECORD input() {
	//storing the input
	INPUT_RECORD inputRecord;
	DWORD eventsRead;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inputRecord, 1, &eventsRead);
	return inputRecord;
}


short position(std::string text, short dx, short dy) {
	pos.X += dx;
	pos.Y += dy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << text << std::flush;
	return 0;
}

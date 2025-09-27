// tetrisconsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <thread>
#include <iostream>
#include <Windows.h>
#include "pos.h"

using namespace std;


string snake = "{}";

void color(WORD attr) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);

}

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
	 position(snake, -2,0);
	 return 0;
}

int main()
{
	color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	bool gameOver = false; //for testing right now

	while (gameOver == false) {
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

}





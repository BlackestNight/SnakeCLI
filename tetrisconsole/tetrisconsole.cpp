// tetrisconsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <thread>
#include <iostream>
#include <Windows.h>
#include "pos.h"

using namespace std;


string snake = "o";

void color(WORD attr) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}

int Drawing() {

}

int main()
{
	color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	bool gameOver = false; //for testing right now

	while (gameOver == false) {
		input_handle();

	}

}





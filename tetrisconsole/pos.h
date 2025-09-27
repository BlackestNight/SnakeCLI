#pragma once
#include <Windows.h>
#include <string>
#ifndef POS_H



extern COORD pos; //declartion of pos variable

INPUT_RECORD input();

short position(std::string text, short dx, short dy);


#endif // !POS_H
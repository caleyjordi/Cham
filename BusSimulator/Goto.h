#pragma once
#include "pch.h"


static const void GotoXY(short X, short Y)
{
	COORD Position = { X * 2,Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}
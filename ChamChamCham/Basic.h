#pragma once
#include "pch.h"
static enum class HandType {
	Left,
	Middle,
	Right,
	Out
};

static const void GotoXY(short X, short Y)
{
	COORD Position = { X * 2,Y * 2 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}
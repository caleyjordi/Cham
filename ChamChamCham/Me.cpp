#include "pch.h"
#include "Me.h"

Me::Me()
{
}


Me::~Me()
{
}

HandType Me::GetChar()
{
	char ch;
	enum {
		x = 0,
		y = 6
	};
	GotoXY(x, y);
	cout << "A : Left         D : Right" << endl<< "Other : Middle   Q : End" << endl;
	cin >> ch;

	switch (ch)
	{
	case 'A' :
	case 'a' :
		Hand = HandType::Left;
		break;
	case 'd' :
	case 'D' :
		Hand = HandType::Right;
		break;
	case 'q':
	case 'Q':
		Hand = HandType::Out;
		break;
	default :
		Hand = HandType::Middle;
		break;

	}
	return Hand;
}

HandType Me::GetHand()
{
	return Hand;
}

#include "pch.h"
#include "Enemy.h"

void Enemy::Update(const HandType a_Hand)
{
	Face = RandomFace();
	if (Face == a_Hand) { Victory = true; }
	else { Victory = false; }
}

void Enemy::ChamRender()
{
	enum
	{
		ChamXY=3,
	};
	system("cls");
	GotoXY(ChamXY, ChamXY);
	cout << "��!";
	Sleep(500);
	system("cls");
	Sleep(500);
	GotoXY(ChamXY, ChamXY);
	cout << "��!";
	Sleep(500);
	system("cls");
	Sleep(500);
	GotoXY(ChamXY, ChamXY);
	cout << "��!";
	Sleep(500);
	system("cls");
}

void Enemy::Render(const HandType a_Hand)
{
	enum {
		FaceY = 0,
		LeftFace = 0,
		MiddleFace = 3,
		RightFace = 6,
		HandY = 2,
		XZero = 0,
		ScoreX = 10,
		ScoreY = 1,
		VictoryY = 4,
	};
	
	if (Face == HandType::Left){
		GotoXY(LeftFace, FaceY); 
		cout << "��";
	}
	else if (Face == HandType::Middle) {
		GotoXY(MiddleFace, FaceY); 
		cout << "��"; 
	}
	else if (Face == HandType::Right) {
		GotoXY(RightFace, FaceY); 
		cout << "��";
	}
	GotoXY(MiddleFace, HandY);
	if (a_Hand == HandType::Left) { cout << "��"; }
	else if(a_Hand == HandType::Middle){ cout << "��"; }
	else { cout << "��"; }

	GotoXY(XZero, VictoryY);
	if (Victory) { cout << "Victory!!" << endl << "Score + 1"; Score++; }
	else { cout << "Defeat TT" << endl << "                        "; }

	GotoXY(ScoreX, ScoreY);
	cout << "Score : " << Score << "          ";
	GotoXY(XZero, XZero);
}

HandType Enemy::RandomFace()
{
	srand(time(NULL));
	enum {
		Left = 0,
		Middle,
	};
	switch (rand() %3)
	{
	case Left:
		return HandType::Left;
	case Middle:
		return HandType::Middle;
	default:
		return HandType::Right;
	}
}

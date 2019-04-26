// ChamChamCham.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Enemy.h"
#include "Me.h"
int main()
{
	Enemy EnemyOne;
	Me MeOne;
	while (MeOne.GetChar() != HandType::Out)
	{
		EnemyOne.ChamRender();
		EnemyOne.Update(MeOne.GetHand());
		EnemyOne.Render(MeOne.GetHand());
	}
	return 0;
}

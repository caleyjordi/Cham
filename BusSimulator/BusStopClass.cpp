#include "pch.h"
#include "BusStopClass.h"
#include "Goto.h"

BusStopClass::~BusStopClass()
{
	if(m_nHead != nullptr)
	{
		BusStop *Temp = m_nHead->Link;
		for (; m_nHead != nullptr;)
		{
			delete m_nHead;
			m_nHead = Temp;
			Temp = m_nHead->Link;
		}
	}
}

void BusStopClass::AddBusStop()
{
	int Time;
	char Name[BusFullName];
	cout << "걸릴 시간을 입력하시오 : ";
	cin >> Time;
	cout << "정류장의 이름을 입력하시오 : ";
	cin >> Name;
	system("cls");
	AddBusStop(Time, Name);
}

void BusStopClass::AddBusStop(int a_Time, const char *a_Name)
{
	//갯수를 넘어가면 리턴
	if (m_nBusStopCount >= m_nMaxBusStop){return;}
	//같은 이름 있을시 리턴
	if (CheckName(a_Name) != -1) { return ; }
	BusStop *Temp = m_nHead;

	BusStop *NewStop = new BusStop;
	strcpy_s(NewStop->Name, a_Name);
	NewStop->Time = a_Time;

	if (Temp == nullptr) { m_nHead = NewStop; }
	else { 
		for (; Temp->Link != m_nHead; Temp = Temp->Link); 
		Temp->Link = NewStop; 
	}

	NewStop->Link = m_nHead;
	m_nBusStopCount++;
}

void BusStopClass::BusMove()
{
	//시계방향으로 돌도록 해놨습니다.
	//1->8->7->6->5->4->3->2->1
	/*예를 1 2 3
		   8   4
		   7 6 5
	그래서 렌더에서도 표시 해놨습니다.
	*/
	BusStop *temp = m_nHead;
	bool First = temp->BusOnThisStop;
	for (; temp->Link != m_nHead; temp = temp->Link) {
			temp->BusOnThisStop = temp->Link->BusOnThisStop;
	}
	temp->BusOnThisStop = First;
}

void BusStopClass::Update()
{
	BusMove();
}

void BusStopClass::Render(int Number)
{
	//assert를 안쓰고 끝낼려면
	//if (Number < 0 || Number > m_nBusStopCount) { return; }
	assert(Number >= 0 && Number <= m_nBusStopCount);
	system("cls");
	ScreenDraw();
	GotoXY(1, 1);
	if (BusCaculator(Number) == 0)
	{
		cout << "버스가 도착했습니다.";
		return;
	}
	
	cout << BusCaculator(Number)<< "전";
	GotoXY(1, 2);
	cout << TimeCaculator(Number) <<" 분 남았습니다.    ";
	GotoXY(1, 3);
	cout << "                      ";
	GotoXY(1, 3);
	cout << BusStopName(Number) << " 정류장";

	GotoXY(0, 10);
	FullName();
}

int BusStopClass::TimeCaculator(int Number)
{
	int sum = 0;
	BusStop *temp = m_nHead;
	for (int i = 0; i < Number; i++) { temp = temp->Link; }
	for (; temp->BusOnThisStop == false; temp = temp->Link) { sum += temp->Time; }
	return sum;
}

int BusStopClass::BusCaculator(int Number)
{
	int sum = 0;
	BusStop *temp = m_nHead;
	for (int i = 0; i < Number; i++) { temp = temp->Link; }
	for (; temp->BusOnThisStop == false; temp = temp->Link) { sum ++; }
	return sum;
}

char *BusStopClass::BusStopName(int Number)
{
	BusStop *temp = m_nHead;
	for (int i = 0; i < Number; i++) { temp = temp->Link; }
	for (; temp->BusOnThisStop == false; temp = temp->Link);
	return temp->Name;
}

void BusStopClass::SetBusNumber(int Number)
{
	//만약에 이름 없으면 assert에 걸려서 에러나고
	//버스카운트 숫자보다 높으면 에러납니다.
	assert(Number >= 0 && Number <= m_nBusStopCount);
	//assert를 안쓰고 끝낼려면
	//if (Number < 0 || Number > m_nBusStopCount) { return; }
	for (int i = 0; i < BusMaxCount; i++)
	{
		if (BusCount[BusMaxCount] <= 0 || BusCount[BusMaxCount] >= m_nBusStopCount)
		{
			BusCount[i] = Number;
			break;
		}
		if (i == BusMaxCount - 1){	return;	}
	}
	BusStop *Temp = m_nHead;
	for (int i = 0; i < Number; i++) {
		Temp = Temp->Link;
	}
	Temp->BusOnThisStop = true;
}

void BusStopClass::ScreenDraw()
{
	cout << "┌────────────────────────┐" << endl;
	cout << "│                        │" << endl;
	cout << "│                        │" << endl;
	cout << "│                        │" << endl;
	cout << "└────────────────────────┘" << endl;
}

int BusStopClass::CheckName(const char *CompareName)
{
	BusStop *Temp = m_nHead;
	for (int i = 0;i<m_nBusStopCount; i++)
	{
		if (strcmp(Temp->Name, CompareName) == 0){return i;}
		Temp = m_nHead->Link;
	}
	//만약에 없는 이름이 없는 경우에도 오류가 안나게 할려면
	/*
	return 0;
	*/
	return -1;
}

void BusStopClass::FullName()
{
	BusStop *Temp = m_nHead;
	do
	{
		cout << Temp->Name << "정류장 -> ";
		Temp = Temp->Link;
	} while (Temp != m_nHead);
	cout << Temp->Name << "정류장";
}

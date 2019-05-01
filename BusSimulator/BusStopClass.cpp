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
	cout << "�ɸ� �ð��� �Է��Ͻÿ� : ";
	cin >> Time;
	cout << "�������� �̸��� �Է��Ͻÿ� : ";
	cin >> Name;
	system("cls");
	AddBusStop(Time, Name);
}

void BusStopClass::AddBusStop(int a_Time, const char *a_Name)
{
	//������ �Ѿ�� ����
	if (m_nBusStopCount >= m_nMaxBusStop){return;}
	//���� �̸� ������ ����
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
	//�ð�������� ������ �س����ϴ�.
	//1->8->7->6->5->4->3->2->1
	/*���� 1 2 3
		   8   4
		   7 6 5
	�׷��� ���������� ǥ�� �س����ϴ�.
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
	//assert�� �Ⱦ��� ��������
	//if (Number < 0 || Number > m_nBusStopCount) { return; }
	assert(Number >= 0 && Number <= m_nBusStopCount);
	system("cls");
	ScreenDraw();
	GotoXY(1, 1);
	if (BusCaculator(Number) == 0)
	{
		cout << "������ �����߽��ϴ�.";
		return;
	}
	
	cout << BusCaculator(Number)<< "��";
	GotoXY(1, 2);
	cout << TimeCaculator(Number) <<" �� ���ҽ��ϴ�.    ";
	GotoXY(1, 3);
	cout << "                      ";
	GotoXY(1, 3);
	cout << BusStopName(Number) << " ������";

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
	//���࿡ �̸� ������ assert�� �ɷ��� ��������
	//����ī��Ʈ ���ں��� ������ �������ϴ�.
	assert(Number >= 0 && Number <= m_nBusStopCount);
	//assert�� �Ⱦ��� ��������
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
	cout << "����������������������������������������������������" << endl;
	cout << "��                        ��" << endl;
	cout << "��                        ��" << endl;
	cout << "��                        ��" << endl;
	cout << "����������������������������������������������������" << endl;
}

int BusStopClass::CheckName(const char *CompareName)
{
	BusStop *Temp = m_nHead;
	for (int i = 0;i<m_nBusStopCount; i++)
	{
		if (strcmp(Temp->Name, CompareName) == 0){return i;}
		Temp = m_nHead->Link;
	}
	//���࿡ ���� �̸��� ���� ��쿡�� ������ �ȳ��� �ҷ���
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
		cout << Temp->Name << "������ -> ";
		Temp = Temp->Link;
	} while (Temp != m_nHead);
	cout << Temp->Name << "������";
}

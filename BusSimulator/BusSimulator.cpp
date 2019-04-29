
#include "pch.h"
#include "BusStopClass.h"
#include "Goto.h"
int main()
{
	BusStopClass BusStop(8);
	char a[BusStopClass::BusFullName];

	/*
	//버스 정류장 정보 입력해두기
	BusStop.AddBusStop(1, "A");
	BusStop.AddBusStop(2, "B");
	BusStop.AddBusStop(3, "C");
	BusStop.AddBusStop(4, "D");
	BusStop.AddBusStop(5, "E");
	BusStop.AddBusStop(5, "F");
	BusStop.AddBusStop(1, "G");
	BusStop.AddBusStop(1, "H");
	BusStop.AddBusStop(1, "I");
	BusStop.AddBusStop(1, "J");

	*/
	//버스 정류장 정보 입력받기
	//갯수는 마음대로
	for (int i = 0; i < 5; i++)
	{ BusStop.AddBusStop();}
	//버스 정류장 설정
	BusStop.SetBusNumber(3);
	while (1)
	{
		BusStop.Update();
		GotoXY(0, 6);
		cout << "현재 있는 정류장의 이름을 입력해주십시오 : ";
		cin >> a;
		BusStop.Render(BusStop.CheckName(a));
		
	}
}

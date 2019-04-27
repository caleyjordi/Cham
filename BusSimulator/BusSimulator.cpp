
#include "pch.h"
#include "BusStopClass.h"
#include "Goto.h"
int main()
{
	BusStopClass B1(8);
	int a;
	B1.AddBusStop(1,"A");
	B1.AddBusStop(2, "B");
	B1.AddBusStop(3, "C");
	B1.AddBusStop(4, "D");
	B1.AddBusStop(5, "E");
	B1.AddBusStop(5, "F");
	B1.AddBusStop(1, "G");
	B1.SetBusNumber(3);

	while (1)
	{
		B1.Update();
		GotoXY(0, 6);
		cin >> a;
		B1.Render(a);
	}
}

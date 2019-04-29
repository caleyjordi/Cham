#pragma once
class BusStopClass
{

public: //index;
	enum {
		BusFullName = 10,
		BusMaxCount = 3,
		BusStopMax = 10,
	};
	BusStopClass(unsigned int a_MaxBusNumber) : m_nMaxBusStop(a_MaxBusNumber) { assert(a_MaxBusNumber < BusStopMax); };
	~BusStopClass();

	void BusMove();
	void Update();
	void Render(int Number);
	int TimeCaculator(int Number);
	int BusCaculator(int Number);
	char *BusStopName(int Number);
	void SetBusNumber(int Number);
	void ScreenDraw();
	int CheckName(const char *CompareName);
	void FullName();
private:  

	int m_nMaxBusStop;
	int m_nBusStopCount = 0;
	int BusCount[BusMaxCount];


public: // Circle Queue System
	void AddBusStop();
	void AddBusStop(int a_Time, const char *a_Name);
private:
	struct BusStop {
		int Time;
		BusStop *Link = nullptr;
		char Name[BusFullName];
		bool BusOn = false;
	};
	BusStop *m_nHead = nullptr;

};


#pragma once
class Time
{
public:
	Time(int seconds);
	Time(int minutes, int seconds);
	Time(int hours, int minutes, int seconds);

	void Print();
	int GetHours();
	int GetMinutes();
	int GetSeconds();

	void AddHours(int hours);
	void AddMinutes(int minutes);
	void AddSeconds(int seconds);
private:
	int m_Seconds;
};


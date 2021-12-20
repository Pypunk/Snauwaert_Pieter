#include "pch.h"
#include <iostream>
#include "Time.h"

Time::Time(int seconds)
	:m_Seconds{seconds}
{
}

Time::Time(int minutes, int seconds)
	:m_Seconds{(minutes*60)+seconds}
{
}

Time::Time(int hours, int minutes, int seconds)
	:m_Seconds((hours*3600)+(minutes*60)+seconds)
{
}

void Time::Print()
{
	std::cout << GetHours() << ":" << GetMinutes() << ":" << GetSeconds();
}

int Time::GetHours()
{
	int seconds{ m_Seconds };
	return seconds / 3600;
}

int Time::GetMinutes()
{
	int seconds{ m_Seconds };
	seconds -= GetHours() * 3600;
	return seconds / 60;
}

int Time::GetSeconds()
{
	int seconds{ m_Seconds };
	seconds -= GetHours() * 3600;
	seconds -= GetMinutes() * 60;
	return seconds;
}

void Time::AddHours(int hours)
{
	m_Seconds += hours * 3600;
}

void Time::AddMinutes(int minutes)
{
	m_Seconds += minutes * 60;
}

void Time::AddSeconds(int seconds)
{
	m_Seconds += seconds;
}

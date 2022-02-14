#pragma once
#include <string>
void DoSquareTests();

class player
{
public:
	player(const std::string& name, int lives);
	~player();

	void PrintInfo();
	void AddPoints(const int newPoints);
private:
	std::string GetInfo();

	std::string m_Name;
	int m_Score;
	int m_Lives;
};


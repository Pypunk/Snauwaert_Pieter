#include "pch.h"
#include <iostream>
#include "player.h"

player::player(const std::string& name, int lives)
	:m_Name{name}
	,m_Lives{lives}
	,m_Score{0}
{
}

player::~player()
{
	std::cout << "I am being deleted!\n";
}

void player::PrintInfo()
{
	std::cout << GetInfo() << std::endl;
}

void player::AddPoints(const int newPoints)
{
	m_Score = newPoints;
}

std::string player::GetInfo()
{
	return std::string("Hi my name is " + m_Name
		+ ", I have " + std::to_string(m_Lives) + " lives and i have " + std::to_string(m_Score) + " points.");
}

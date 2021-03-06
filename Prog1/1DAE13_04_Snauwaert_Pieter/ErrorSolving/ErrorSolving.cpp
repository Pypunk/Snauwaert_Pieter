#include "pch.h"
#include <iostream>
#include <ctime>
#include <string> 

#pragma region Function declarations

// Function declarations
void DetermineSkill();
void GetColorCodes();
void Wait();

#pragma endregion Function declarations


int main()
{
	std::cout << "== ErrorSolving - Snauwaert, Pieter - 1DAE13 ==\n";
	// rand seed
	srand(int(time(nullptr)));

	DetermineSkill();
	GetColorCodes();
	Wait();
}

#pragma region Function definitions
// Function definitions
void GetColorCodes()
{
	std::cout << "\n-- GetColorCodes function --\n";
	enum class ColorCodes
	{
		Magenta,
		Yellow,
		Cyan,
		Stop
	};
	const std::string menu{ "\nMake your choice\n1.Magenta\n2.Yellow\n3.Cyan\n?" };
	int choice{};
	std::cout << menu;
	std::cin >> choice;
	switch (choice)
	{
	case int(ColorCodes::Magenta):
		std::cout << "Magenta 0xFF00FF\n";
		break;
	case int(ColorCodes::Yellow):
		std::cout << "Yellow 0xFFFF00\n";
		break;
	case int(ColorCodes::Cyan):
		std::cout << "Cyan 0x00FFFF\n";
		break;
	case int(ColorCodes::Stop):
		std::cout << "Wrong choice\n";
		break;
	}

	std::cin.ignore();
}


void DetermineSkill()
{
	std::cout << "\n-- DetermineSkill function --\n";

	int years{};
	std::cout << "Your years of experience ? ";
	std::cin >> years;
	std::string level{};
	if (years < 5)
	{
		level = "Junior level";
	}
	if (years < 10)
	{
		level = "Intermediate level";
	}
	else
	{
		level = "Senior level";
	}
	std::cout << level << std::endl;

	std::cin.ignore();
}

void Wait()
{
	std::cout << "Press ENTER to quit";
	std::cin.get();
}
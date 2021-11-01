// IterationBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Snauwaert Pieter 1DAE13


#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>



void IsEvenNumbers();
void ConvertExamScores();
void GuessRandom();
void PrintTrig();
void PrintAscii();
int main()
{ 
	srand(int(time(nullptr)));
	IsEvenNumbers();
	//ConvertExamScores();
	GuessRandom();
	PrintTrig();
	PrintAscii();
	std::cin.get();
}
void IsEvenNumbers()
{
	int number{2};
	std::cout << "-- Even Numbers --\n";
	while (!(number % 2) && number < 25)
	{
		std::cout << number << " ";
		number+=2;
	}
	number = 2;
	std::cout << std::endl;
	do
	{
		std::cout << number << " ";
		number += 2;
	} while (!(number % 2) && number < 25);
	std::cout << std::endl;
	for (int i{2}; !(i % 2) && i < 25; i += 2)
	{
		std::cout << i << " ";
	}
}

void ConvertExamScores()
{
	std::cout << "\n-- Exams scores --\n";
	int score{};
	int aPlus{};
	int a{};
	int b{};
	int c{};
	int d{};
	int e{};
	int fX{};
	int f{};
	int total{};
	std::string enteredScores{};
	while (score >= 0)
	{
		std::cout << "nScore[0, 20] ? ";
		std::cin >> score;
		std::cin.ignore();
		if (score > 20 || score < 0)
		{
			std::cout << "Wrong Score!\n";
		}
		else
		{
			total += score;
			enteredScores += std::to_string(score) + " ";
		}
		if (score <= 20 && score > 17)
		{
			aPlus++;
		}
		else if (score < 18 && score > 15)
		{
			a++;
		}
		else if (score < 16 && score > 14)
		{
			b++;
		}
		else if (score < 15 && score > 12)
		{
			c++;
		}
		else if (score < 13 && score > 10)
		{
			d++;
		}
		else if (score < 11 && score > 9)
		{
			e++;
		}
		else if (score < 10 && score > 7)
		{
			fX++;
		}
		else if (score < 8)
		{
			f++;
		}
	}
	if (score < 0)
	{
		std::cout << "A+: " << aPlus << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		std::cout << "C: " << c << std::endl;
		std::cout << "D: " << d << std::endl;
		std::cout << "E: " << e << std::endl;
		std::cout << "FX: " << fX << std::endl;
		std::cout << "F: " << f << std::endl;
		std::cout << "Total score: " << total << std::endl;
		std::cout << enteredScores << std::endl;
	}
}

void GuessRandom()
{
	std::cout << "-- Guess number --\n";
	int nrToGuess{};
	std::cout << "Number to guess? ";
	std::cin >> nrToGuess;
	std::cin.ignore();
	int randNr{};
	int counter{};
	while (randNr != nrToGuess)
	{
		if (nrToGuess < 0)
		{
			std::cout << "This s a wrong number, number to guess? ";
			std::cin >> nrToGuess;
			std::cin.ignore();
		}
		else
		{
			randNr = rand();
			counter++;
		}
	}
	std::cout << "Number found after " << counter << " guesses\n";
}

void PrintTrig()
{
	int angle{};
	const int width{ 10 };
	std::cout << "\n-- Trigonometry --\n";
	std::cout << std::setw(width) << "Degrees";
	std::cout << std::setw(width) << "Radians";
	std::cout << std::setw(width) << "Cosine";
	std::cout << std::setw(width) << "Sine\n";
	while (angle <= 180)
	{
		std::cout << std::setw(width);
		std::cout << angle;
		std::cout << std::setw(width);
		std::cout << std::setprecision(2);
		std::cout << angle* M_PI/180;
		std::cout << std::setw(width);
		std::cout << cos(angle);
		std::cout << std::setw(width);
		std::cout << sin(angle);
		std::cout << std::endl;
		angle += 10;
	}
}

void PrintAscii()
{
	std::cout << "-- ASCII table --\n";
	char character{ 'a' };
	const int charOffset{ 13 };
	const int width{ 5 };
	while (character <= 'm')
	{
		std::cout << std::setw(width);
		std::cout << character;
		std::cout << std::setw(width);
		std::cout << int(character);
		std::cout << std::setw(width);
		std::cout << char(character + charOffset);
		std::cout << std::setw(width);
		std::cout << int(character + charOffset) << std::endl;
		character++;
	}
}

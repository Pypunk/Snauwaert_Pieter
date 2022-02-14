// Variables3Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
void sizeOfVariables();
void RepresentInts();
void PrintOverflow();
void DoBinaryOperations();
int main()
{
	sizeOfVariables();
	RepresentInts();
	PrintOverflow();
	DoBinaryOperations();
	std::cin.ignore();
	std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void sizeOfVariables()
{
	bool sizeOfBool{};
	int sizeOfInt{};
	float sizeOfFloat{};
	double sizeOfDouble{};
	std::cout << sizeof(sizeOfBool) << " " << sizeof(sizeOfInt) << " " << sizeof(sizeOfFloat) << " " << sizeof(sizeOfDouble) << "\n";

}

void RepresentInts()
{
	int dec{ 12 };
	int bin{ 0b1100 };
	int hex{ 0xC };
}

void PrintOverflow()
{
	int maxSigned{ 2147483647 };
	int minSigned{ -2147483648 };
	unsigned int maxUnsigned{ 4294967295 };
	unsigned int minUnsigned{ 0 };

	std::cout << maxSigned + 1 << std::endl;
	std::cout << minSigned - 1 << std::endl;
	std::cout << maxUnsigned + 1 << std::endl;
	std::cout << minUnsigned - 1 << std::endl;
}

void DoBinaryOperations()
{
	unsigned int var1{ 3 };
	unsigned int var2{ 5 };
	unsigned int result{ var1 & var2 };
	std::cout << result << std::endl;
	result = var1 | var2;
	std::cout << result << std::endl;

	int number{};
	std::cout << "Number to check which bits are set? ";
	std::cin >> number;
	result = (number & (1LL << 0));
	std::cout << "1st bit " << result << std::endl;
	result = (number & (1LL << 1));
	std::cout << "2nd bit " << result << std::endl;
	result = (number & (1LL << 2));
	std::cout << "3rd bit " << result << std::endl;
	result = (number & (1LL << 3));
	std::cout << "4th bit " << result << std::endl;

	std::cout << "Number to set 3rd bit in? ";
	std::cin >> number;
	result = ((1LL << 2) | number);
	std::cout << "This number with 3rd bit set " << result << std::endl;

	unsigned int number2{ 2048 };
	number2 = number2 >> 1;
	std::cout << number2 << std::endl;

	number2 = 4448;
	result = ((1LL << 8) & number2)/256;
	std::cout << "the bit representing 256 is " << result << std::endl;

	number2 = 2048;
	number2 = number2 << 1;
	std::cout << number2 << std::endl;

	unsigned int general{ 0 };
	general -= 1;
	general = general >> 4;
}

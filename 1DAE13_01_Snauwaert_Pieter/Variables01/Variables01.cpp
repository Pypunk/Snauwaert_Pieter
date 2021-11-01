// Variables01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int i1{1};
	char c1{'a'};
	bool b1{true};
	float f1{23.8f};
	double d1{23.976};
	std::cout << "'" << i1 << " " << c1 << " " << b1 << " " << f1 << " " << d1 << "'\n";

	i1 = 1;
	c1 = 'd';
	b1 = false;
	f1 = 98.56f;
	d1 = 23.975;
	std::cout << "'" << i1 << " " << c1 << " " << b1 << " " << f1 << " " << d1 << "'\n";

	std::cout << "new int value:";
	std::cin >> i1;
	std::cout << "new char value:";
	std::cin >> c1;
	std::cout << "new bool value:";
	std::cin >> b1;
	std::cout << "new float value:";
	std::cin >> f1;
	std::cout << "new double value:";
	std::cin >> d1;

	std::cout << "'" << i1 << " " << c1 << " " << b1 << " " << f1 << " " << d1 << "'\n";

	int intResult{ i1 + 5 };
	char charResult{ c1 + 1 };
	float floatResult{ f1 + 65.35f };

	int intMultiply{ i1 * 5 };
	char charMultiply{ c1 * 5 };
	float floatMultiply{ f1 * 8 };
	
	int bigInt{ 89 };
	int smallInt{ 12 };
	
	int intDevide{ bigInt / smallInt };
	char charDevide{ c1 / 8 };
	float floatDevide{ f1 / 6 };

	std::cin.ignore(1);
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

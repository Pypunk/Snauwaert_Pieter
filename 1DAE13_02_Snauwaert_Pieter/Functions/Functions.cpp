#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
void TestOneParFunctions();
void TestTwoParFunctions();
int main( )
{
	// 1. Show my data
	std::cout << "My name is Snauwaert, Pieter" << std::endl;
	std::cout << "I am in group 1DAE13" << std::endl << std::endl;

	// 2. Show my student history
	std::cout << "Name of my high school: OLV. Hemelvaart" << std::endl;
	std::cout << "In the last year I had 2 hours math a week" << std::endl << std::endl;
	
	TestOneParFunctions();
	TestTwoParFunctions();

	// Wait
	std::cout << "Push ENTER to quit\n";
	std::cin.get( );

	return 0;
}

void TestOneParFunctions()
{
	double angle{ 0.0 };
	std::cout << "Use existing functions with 1 parameter\n";
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;
	angle += M_PI / 4;
	std::cout << "Use existing functions with 1 parameter\n";
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;
	angle += M_PI / 4;
	std::cout << "Use existing functions with 1 parameter\n";
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;
	angle += M_PI / 4;
	std::cout << "Use existing functions with 1 parameter\n";
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;
	angle += M_PI / 4;
	std::cout << "Use existing functions with 1 parameter\n";
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;
}

void TestTwoParFunctions()
{
	int para1{ 2 };
	int para2{ 8 };
	double result{ pow(para1,para2) };

	para1 = 3;
	para2 = 4;
	result = sqrt(pow(para1,2)+pow(para2,2));
	std::cout << "if the short sides are " << para1 << " and " << para2 << " then the hypothenuse should be: " << result << std::endl;

}

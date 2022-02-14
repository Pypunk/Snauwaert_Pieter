// Applications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath> 
#include <iostream>

int main()
{
	std::cout << "RGBA in [0, 255]? ";
	float r{}, g{}, b{}, a{};
	std::cin >> r >> g >> b >> a;
	std::cout << "RGBA in [0.0f,1.0f]\n";
	r /= 255.f;
	g /= 255.f;
	b /= 255.f;
	a /= 255.f;
	std::cout << r << '\n' << g << '\n' << b << '\n' << a << '\n';
	std::cout << std::endl;
	
	std::cout << "Distance in km? ";
	float km{};
	std::cin >> km;
	float m{ km * 1000 };
	float cm{ km * 100000 };
	std::cout << m << " meters, " << cm << " cm\n";
	std::cout << std::endl;

	std::cout << "Angle in radians? ";
	float rad{};
	std::cin >> rad;
	float degrees{(rad*180)/float(M_PI)};
	std::cout << degrees << " degrees\n";
	std::cout << std::endl;

	std::cout << "Angle in degrees? ";
	float degrees2{};
	std::cin >> degrees2;
	float rad2{ float(degrees2 * M_PI) / 180 };
	std::cout << rad2 << " radians\n";
	std::cout << std::endl;

	std::cout << "Seconds of one rotation? ";
	float sec{};
	std::cin >> sec;
	float velocity{ 360 / sec };
	std::cout << velocity << " degrees/seconds\n";
	std::cout << std::endl;


	std::cout << "Speed (km/h)? ";
	float speed{};
	std::cin >> speed;
	std::cout << "Elapsed Time (minutes)? ";
	float minutes{};
	std::cin >> minutes;
	speed /= 60;
	std::cout << speed * minutes*1000 << " metres\n";
	std::cout << std::endl;

	float acceleration{ 9.8f };
	std::cout << "Seconds? ";
	int seconds{};
	std::cin >> seconds;
	float velocity2{ acceleration * seconds };
	std::cout << "Velocity " << velocity2 << " m/s\n";
	std::cout << std::endl;

	std::cout << "Radius of circle? ";
	float radius{};
	std::cin >> radius;
	float circum{ 2 * radius * float(M_PI) };
	float area{ radius * radius * float( M_PI) };
	std::cout << "Circumference: " << circum << "\nArea: " << area << "\n";
	std::cout << std::endl;

	std::cout << "Width and height? ";
	float width{};
	float height{};
	std::cin >> width >> height;
	float circum2{ 2 * width + 2 * height };
	float area2{ width * height };
	std::cout << "Circumference:" << circum2 << "\nArea " << area2 << '\n';
	std::cout << std::endl;

	std::cout << "Base and height? ";
	float base{};
	float height2{};
	std::cin >> base >> height2;
	float area3{ (base * height2)/2 };
	std::cout << "Area: " << area3 << "\n";
	std::cout << std::endl;

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

// ClassesBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include "Square.h"
#include "Time.h"
void DoSquareTests();
void DoTimeTests();

int main()
{
    std::cout << "Hello World!\n";
    DoSquareTests();
    DoTimeTests();
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

void DoSquareTests()
{
    Square* pSquare1{ new Square{50} };
    pSquare1->Print();
    std::cout << std::endl;
    Square* pSquare2{ new Square{50,10,10} };
    pSquare2->Print();
    pSquare2->SetSize(20);
    pSquare2->Print();

    delete pSquare1;
    pSquare1 = nullptr;
    delete pSquare2;
    pSquare2 = nullptr;
}

void DoTimeTests()
{
    std::cout << "---Creating Time objects---\n";

    int seconds{ 200 };
    std::cout << "pTimeSeconds has:" << seconds << " seconds\n";
    Time* pTimeSeconds{ new Time{seconds} };
    std::cout << "after puting those values in the Time class and printing them:\n";
    pTimeSeconds->Print();
    std::cout << std::endl;

    seconds = 250;
    int minutes{ 60 };
    std::cout << "pTimeMinutes has: " << minutes << " minutes and " << seconds << " seconds\n";
    Time* pTimeMinutes{ new Time{minutes,seconds} };
    std::cout << "after puting those values in the Time class and printing them:\n";
    pTimeMinutes->Print();
    std::cout << std::endl;

    int hours{ 23 };
    minutes = 16;
    seconds = 20;

    std::cout << "pTimeHours has: " << hours << " hours, " << minutes << " minutes and " << seconds << " seconds\n";
    Time* pTimeHours{ new Time{hours,minutes,seconds} };
    std::cout << "after puting those values in the Time class and printing them:\n";
    pTimeHours->Print();
    std::cout << std::endl;

    delete pTimeSeconds;
    pTimeSeconds = nullptr;
    delete pTimeMinutes;
    pTimeMinutes = nullptr;
    delete pTimeHours;
    pTimeHours = nullptr;
}

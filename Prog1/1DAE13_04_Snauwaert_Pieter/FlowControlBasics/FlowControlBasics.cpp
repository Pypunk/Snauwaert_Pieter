// FlowControlBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "structs.h"

void PrintTruthTable();
void CompareTwoNumbers();
void CalculatePrice();
void ConvertDayNumber();
void CheckLeapYear();
void ConvertSeconds();
void UseActorState();
void UsePoint2f();
int main()
{
    srand(int(time(nullptr)));
    PrintTruthTable();
    CompareTwoNumbers();
    CalculatePrice();
   ConvertDayNumber();
    CheckLeapYear();
    ConvertSeconds();
    UseActorState();
    UsePoint2f();
    std::cin.get();
}

void PrintTruthTable()
{
    const bool trueBool{ 1 };
    const bool falseBool{ 0 };

    std::cout << "-- Print truth table --\n";
    std::cout << "Logical binary AND-operator\n";
    std::cout << "True && true is ";
    std::cout << std::boolalpha << (trueBool && trueBool) << std::endl;
    std::cout << "True && false is ";
    std::cout << std::boolalpha << (trueBool && falseBool) << std::endl;
    std::cout << "False && false is ";
    std::cout << std::boolalpha << (falseBool && falseBool) << std::endl;
    std::cout << "False && true is ";
    std::cout << std::boolalpha << (falseBool && trueBool) << std::endl;

    std::cout << "Logical binary OR-operator\n";
    std::cout << "True || true ";
    std::cout << std::boolalpha << (trueBool || trueBool) << std::endl;
    std::cout << "True || false ";
    std::cout << std::boolalpha << (trueBool || falseBool) << std::endl;
    std::cout << "False || true ";
    std::cout << std::boolalpha << (falseBool || trueBool) << std::endl;
    std::cout << "False || false ";
    std::cout << std::boolalpha << (falseBool || falseBool) << std::endl;
    
    std::cout << "Logical unary NOT-operator\n";
    std::cout << "!true is " << std::boolalpha << !trueBool << std::endl;
    std::cout << "!false is " << std::boolalpha << !falseBool << std::endl;
}

void CompareTwoNumbers()
{
    const int randNr1{ rand() % 11 };
    std::cout << "First number is " << randNr1 << std::endl;
    const int randNr2{ rand() % 11 };
    std::cout << "Second number is " << randNr2 << std::endl;
    if (randNr2 > randNr1)
    {
        std::cout << "Second number is larger than first one\n";
    }
}

void CalculatePrice()
{
    int ballPoints{};
    float totalPrice{};
    const float underTwentyPrice{4.00f};
    const float underFiftyPrice{ underTwentyPrice - 0.50f };
    const float underHundredPrice{ underFiftyPrice - 0.25f };
    const float aboveHundredPrice{ underHundredPrice - 0.15f };
    std::cout << "-- Calculate Price --\n";
    std::cout << "Nr of ballpoints? ";
    std::cin >> ballPoints;
    std::cin.ignore();
    if (ballPoints < 20)
    {
        totalPrice = ballPoints * underTwentyPrice;
        std::cout << "Total price is " << totalPrice << std::endl;
    }
    if (ballPoints > 20 && ballPoints < 50)
    {
        totalPrice = ballPoints * underFiftyPrice;
        std::cout << "Total price is " << totalPrice << std::endl;
    }
    if (ballPoints > 50 && ballPoints < 100)
    {
        totalPrice = ballPoints * underHundredPrice;
        std::cout << "Total price is " << totalPrice << std::endl;
    }
    if (ballPoints > 100)
    {
        totalPrice = ballPoints * aboveHundredPrice;
        std::cout << "Total price is " << totalPrice << std::endl;
    }
}

void ConvertDayNumber()
{
    int day{};
    std::cout << "Day number [1, 7]? ";
    std::cin >> day;
    std::cin.ignore();
    if (day == 1)
    {
        std::cout << "Start of the week\n";
    }
    else if (day > 1 && day < 5)
    {
        std::cout << "Middle of the week\n";
    }
    else if (day == 5)
    {
        std::cout << "Nearly Weekend\n";
    }
    else if (day > 5 && day < 8)
    {
        std::cout << "Weekend\n";
    }
    else if (day > 7)
    {
        std::cout << "Wrong Day Number\n";
    }
    switch (day)
    {
    case 1:
        std::cout << "Monday\n";
        break;
    case 2:
        std::cout << "Tuesday\n";
        break;
    case 3:
        std::cout << "Wednesday\n";
        break;
    case 4:
        std::cout << "Thursday\n";
        break;
    case 5:
        std::cout << "Friday\n";
        break;
    case 6:
        std::cout << "Saturday\n";
        break;
    case 7:
        std::cout << "Sunday\n";
        break;
    }
}

void CheckLeapYear()
{
    int year{};
    std::cout << "-- Check leap year --\n";
    std::cout << "Year? ";
    std::cin >> year;
    std::cin.ignore();
    std::cout << year << ":";
    if (!(year % 4))
    {
        if (!(year % 100))
        {
            if (!(year % 400))
            {
                std::cout << " 29\n";
            }
            else
            {
                std::cout << " 28\n";
            }
        }
        else
        {
            std::cout << " 29\n";
        }
    }
    else 
    {
        std::cout << " 28\n";
    }
}

void ConvertSeconds()
{
    int seconds{};
    const int daysInSecs{ 86400 };
    const int hoursInSecs{ 3600 };
    const int minutesInSecs{ 60 };
    std::cout << "-- Convert Seconds --\n";
    std::cout << "Number of seconds? ";
    std::cin >> seconds;
    std::cin.ignore();
    const int days{ seconds / daysInSecs };
    seconds -= days * daysInSecs;
    std::cout << days << " days\n";
    const int hours{ seconds / hoursInSecs };
    seconds -= hours * hoursInSecs;
    std::cout << hours << " hours\n";
    const int minutes{ seconds / minutesInSecs };
    seconds -= minutes * minutesInSecs;
    std::cout << minutes << " minutes\n";
    std::cout << seconds << " seconds\n";
}

void UseActorState()
{
    std::cout << "-- Define and use ActorState --\n";
    enum class ActorState 
    {
        running,
        flying,
        falling
    };
    ActorState state{ ActorState::running };
    switch (state)
    {
    case ActorState::running:
        std::cout << "running\n";
        break;
    case ActorState::flying:
        std::cout << "flying\n";
        break;
    case ActorState::falling:
        std::cout << "falling\n";
    }

    const int actorStateInt{ rand() % 4 };
    state = ActorState(actorStateInt);
    switch (state)
    {
    case ActorState::running:
        std::cout << "running\n";
        break;
    case ActorState::flying:
        std::cout << "flying\n";
        break;
    case ActorState::falling:
        std::cout << "falling\n";
    }
}

void UsePoint2f()
{
    Point2f p1;
    Point2f p2{};
    Point2f p3{ 26,25 };
    std::cout << "-- Define and use Point2f --\n";
    std::cout << "Values after definition\n";
    std::cout << "p2: [" << p2.x << ", " << p2.y << "]\n";
    std::cout << "p3: [" << p3.x << ", " << p3.y << "]\n";

    std::cout << "Values after changing the members\n";
    p1.x = 20;
    p1.y = 3;
    p2.x = 30;
    p2.y = 40;
    p3.x = 27;
    p3.y = 24;
    std::cout << "p1: [" << p1.x << ", " << p1.y << "]\n";
    std::cout << "p2: [" << p2.x << ", " << p2.y << "]\n";
    std::cout << "p3: [" << p3.x << ", " << p3.y << "]\n";
}

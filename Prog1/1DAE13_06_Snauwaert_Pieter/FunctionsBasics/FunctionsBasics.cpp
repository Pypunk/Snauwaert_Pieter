// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1DAE13 Pieter Snauwaert

#include "pch.h"
#include <iostream>
#include <chrono>
#include "structs.h"

int Sum(int a, int b);
void PrintInt(int value, char delimiter);
void PrintChar(char value, char delimiter);
void PrintFloat(float value, char delimiter);
void Print(int value, char delimiter);
int Multiply(int a, int b);
int GetModulo(int value, int devision);
void PrintNumbers(int start, int end);
void CalcElapsedTime(int start, int end);
void PrintMessage(int spaces = 0);
bool IsEven(int value);
bool IsLeapYear(int year);
int GetRand(int min, int max);
float GetRand(float min, float max);
float GetDistance(Point2f point1, Point2f point2);
float GetDistance(float p1x, float p1y, float p2x, float p2y);

void TestSum();
void TestPrint();
void TestMultiply();
void TestModulo();
void TestPrintNumbers();
void TestCalcElapsedTime();
void TestPrintMessage();
void TestIsEven();
void TestIsLeapYear();
void TestGetIntRand();
void TestGetFloatRand();
void TestGetDistance();
void TestCalcCosSin();

int main()
{
    srand(int(time(NULL)));
    //TestSum();
    //TestPrint();
    //TestMultiply();
    //TestModulo();
    //TestPrintNumbers();
    //TestCalcElapsedTime();
    //TestPrintMessage();
    TestIsEven();
    TestIsLeapYear();
    //TestGetIntRand();
    //TestGetFloatRand();
    TestGetDistance();
}


//functions
int Sum(int a, int b)
{
    return a + b;
}

void PrintInt( int value, char delimiter )
{
std::cout << value << delimiter;
}

void PrintChar(char value, char delimiter )
{
std::cout << value << delimiter;
}

void PrintFloat(float value, char delimiter )
{
std::cout << value << delimiter;
}

void Print(int value, char delimiter)
{
    std::cout << value << delimiter;
}

int Multiply(int a, int b)
{
    return a * b;
}

int GetModulo(int value, int devision)
{
    return value - ((value/devision)*devision);
}

void PrintNumbers(int start, int end)
{
    for (start; start <= end; start++)
    {
        std::cout << start << " ";
    }
}

void CalcElapsedTime(int start, int end)
{
    std::chrono::steady_clock::time_point startTime{std::chrono::steady_clock::now()};
    PrintNumbers(start, end);
    std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };
    std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };
    std::cout << "\nThis print task took " << elapsedTime.count() << "miliseconds\n";
}

void PrintMessage(int spaces)
{
    for (int i{}; i < spaces; ++i)
    {
        std::cout << " ";
    }
    if (spaces <= 0)
    {
        std::cout << "No indentation specified\n";
    }
    else
    {
        std::cout << spaces << " spaces identation specified\n";
    }
}

bool IsEven(int value)
{
    return !(value % 2);
}

bool IsLeapYear(int year)
{
    if (!(year % 4))
    {
        if (!(year % 100))
        {
            if (!(year % 400))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int GetRand(int min, int max)
{
    return ((rand() % int(max)) + min);
}

float GetRand(float min, float max)
{
    return ((rand() % int(max*100)) + min*100)/100;
}

float GetDistance(Point2f point1, Point2f point2)
{
    return sqrt(pow(point2.x-point1.x,2) + pow(point2.y-point1.y,2));
}

float GetDistance(float p1x, float p1y, float p2x, float p2y)
{
    return sqrt(pow(p2x - p1x, 2) + pow(p2y - p1y, 2));
}


//test functions
void TestSum()
{
    int number1{ 12 }, number2{ 54 }, result{};
    result = Sum(number1, number2);
}

void TestPrint( )
{
//PrintChar( 'a', ',' );
Print('a', ',');
//PrintInt( 20, ',' );
Print(20, ',');
//PrintFloat( 20.0f, ',' );
Print(20.0f, ',');
std::cout << std::endl;
}

void TestMultiply()
{
    std::cout << "-- Function that calculates the product of 2 integers --\n";
    int value1{}; int value2{}, value3{}, value4{};
    std::cout << "2 numbers to multiply?";
    std::cin >> value1 >> value2;
    std::cout << value1 << " * " << value2 << " = " << Multiply(value1, value2) << std::endl;
    std::cout << "4 numbers to multiply?";
    std::cin >> value1 >> value2 >> value3 >> value4;
    std::cout << value1 << " * " << value2 << " * " << value3 << " * " << value4 << " = " << Multiply(value1, value2) * Multiply(value3, value4) << std::endl;
}

void TestModulo()
{
    int result{};
    std::cout << " -- Get Modulo --\n";
    result = GetModulo(250, 24);
    std::cout << "250 % 24 = " << result << std::endl;
}

void TestPrintNumbers()
{
    int start{};
    int end{};
    start = 10;
    end = 20;
    std::cout << "\n-- Function that prints the integers in a given interval --\n";
    std::cout << "Interval [" << start << ", " << end << "]\n";
    PrintNumbers(start, end);
    std::cout << std::endl;
    start = 90;
    end = 115;
    std::cout << "Interval [" << start << ", " << end << "]\n";
    PrintNumbers(start, end);
    std::cout << std::endl;
}

void TestCalcElapsedTime()
{
    int start{}, end{};
    std::cout << "\n-- Function that counts the time of a printing task --\n";
    start = 0;
    end = 30;
    std::cout << "Interval [" << start << ", " << end << "]\n";
    CalcElapsedTime(start, end);
    end = 400;
    std::cout << "Interval [" << start << ", " << end << "]\n";
    CalcElapsedTime(start, end);
}

void TestPrintMessage()
{
    std::cout << "-- Function that prints an indented message --\n";
    PrintMessage();
    PrintMessage(2);
    PrintMessage(4);
}

void TestIsEven()
{
    std::cout << "-- Function that checks weither a number is even --\n";
    int number{ 41 };
    if (IsEven(number))
    {
        std::cout << number << " is even\n";
    }
    else
    {
        std::cout << number << "is odd\n";
    }
    number = 18467;
    if (IsEven(number))
    {
        std::cout << number << " is even\n";
    }
    else
    {
        std::cout << number << " is odd\n";
    }    number = 6334;
    IsEven(number);
    if (IsEven(number))
    {
        std::cout << number << " is even\n";
    }
    else
    {
        std::cout << number << " is odd\n";
    }    IsEven(number);
    number = 19169;
    if (IsEven(number))
    {
        std::cout << number << " is even\n";
    }
    else
    {
        std::cout << number << " is odd\n";
    }
}

void TestIsLeapYear()
{
    int year{};
    std::cout << "-- Function that checks wether year is leap --\n";
    while (year != -1)
    {
        std::cin >> year;
        if (IsLeapYear(year))
        {
            std::cout << year << " has 29 days\n";
        }
        else
        {
            std::cout << year << " has 28 days\n";
        }
    }
}

void TestGetIntRand()
{
    int min{}, max{};
    std::cout << "-- Function that generates a random number in a given interger interval --\n";
    min = 1;
    max = 6;
    std::cout << "In [" << min << ", " << max << "] ";
    std::cout << GetRand(min, max) << std::endl;
    min = 10;
    max = 20;
    std::cout << "In [" << min << ", " << max << "] ";
    std::cout << GetRand(min, max) << std::endl;
    min = -5;
    max = 0;
    std::cout << "In [" << min << ", " << max << "] ";
    std::cout << GetRand(max, min) << std::endl;
}

void TestGetFloatRand()
{
    float min{}, max{};
    std::cout << "-- Function that generates a random number in a given float interval --\n";
    min = 0.f;
    max = 3.14159f;
    std::cout << "In [" << min << ", " << max << "] ";
    std::cout << GetRand(min, max) << std::endl;
    min = -2;
    max = 3;
    std::cout << "In [" << min << ", " << max << "] ";
    std::cout << GetRand(min, max) << std::endl;
}

void TestGetDistance()
{
    std::cout << "-- Function that calculates distance between 2 points --\n";
    Point2f p1{ 0.41,184.67 }, p2{ 63.34,256.00 };
    std::cout << "Distance between [" << p1.x << ", " << p1.y << "] and [" << p2.x << ", " << p2.y << "]\n";
    std::cout << "Calling one version: " << GetDistance(p1, p2) << std::endl;
    std::cout << "Calling the other version: " << GetDistance(p1.x, p1.y, p2.x, p2.y) << std::endl;
}

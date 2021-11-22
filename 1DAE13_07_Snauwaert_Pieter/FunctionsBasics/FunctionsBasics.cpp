// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath> 
#include <iostream>

void CalcCosSin(float angle, float& cosResult, float& sinResult);
void TestCalcCosSin();
float GetRand(float min, float max);
int main()
{

}

void CalcCosSin(float angle, float& cosResult, float& sinResult)
{
    cosResult = cosf(angle);
    sinResult = sinf(angle);
}
void TestCalcCosSin()
{
    float angle{};
    angle = GetRand(0, 2 * M_PI);
    float rad{ (angle * float(M_PI)) / 180 };
    float cosResult{};
    float sinResult{};
    CalcCosSin(angle, cosResult, sinResult);
    std::cout << rad << " " << cosResult << " " << sinResult << std::endl;
    std::cin.get();
}
float GetRand(float min, float max)
{
    return ((rand() % int(max * 100)) + min * 100) / 100;
}

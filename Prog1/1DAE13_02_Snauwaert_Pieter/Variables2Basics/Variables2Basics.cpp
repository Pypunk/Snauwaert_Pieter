// Variables2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

void IsEven();
void GenerateRandNumbers();
void Typecasting();
void PrefixAndPostfix();
void ExploreStrings();
int main()
{
    srand(int(time(nullptr)));
    std::cout << "Hello World!\n";
    IsEven();
    GenerateRandNumbers();
    Typecasting();
    PrefixAndPostfix();
    ExploreStrings();

    std::cin.ignore();
    std::cin.get();
}

void IsEven()
{
    int number{};
    std::cout << "Type in a number:";
    std::cin >> number;
    std::cout << "remainder is " << number % 2 << std::endl;
}

void GenerateRandNumbers()
{
    int randomIntNr{};
    float randomFloatNr{};
    randomIntNr = rand() % 51;
    std::cout << randomIntNr << std::endl;

    randomIntNr = rand() % 70+10;
    std::cout << randomIntNr << std::endl;

    randomIntNr = rand() % 40-20;
    std::cout << randomIntNr << std::endl;

    randomIntNr = rand() % 4 - 2;
    std::cout << randomIntNr << std::endl;

    randomFloatNr = (rand() % 500+500.f) / 100.f;
    std::cout << randomFloatNr << std::endl;

    randomFloatNr = (rand() % 1000 - 500.f) / 100.f;
    std::cout << randomFloatNr << std::endl;
}

void Typecasting()
{
    char letter{};
    float floatVar{};
    std::cout << "Letter? ";
    std::cin >> letter;
    std::cout << "Letter " << letter << ", ASCII value " << int(letter) << std::endl;

    letter = 'a' + rand() % 26;
    std::cout << "Random letter " << letter << ", ASCII value " << int(letter) << std::endl;

    floatVar = 5.44f;
    std::cout << floatVar << ", rounded: " << round(floatVar) << ", int cast: " << int(floatVar) << std::endl;
    floatVar = 5.45f;
    std::cout << floatVar << ", rounded: " << round(floatVar) << ", int cast: " << int(floatVar) << std::endl;
    floatVar = 5.51f;
    std::cout << floatVar << ", rounded: " << round(floatVar) << ", int cast: " << int(floatVar) << std::endl;
    
    floatVar = float(1920.f / 1080.f);
    std::cout << "The aspect ratio of full HD (1920x1080) is " << floatVar << std::endl;
}

void PrefixAndPostfix()
{
    int i{10};
    int j{ ++i };
    std::cout << "i: " << i << ", j: " << j << std::endl;

    int k{ 10 };
    int l{ k++ };
    std::cout << "k: " << k << ", l: " << l << std::endl;
}

void ExploreStrings()
{
    std::string string;
    std::cout << string;

    string = "I am a string literal";
    std::cout << string << std::endl;
    string = "I am a new string literal";
    std::cout << string << std::endl;
    std::cout << "Enter a new string literal" << std::endl;
    std::cin >> string;
    std::cout << string << std::endl;

    std::string concatenation;
    std::string firstWord;
    std::string secondWord;
    std::cout << "First word? ";
    std::cin >> firstWord;
    std::cout << "Second Word? ";
    std::cin >> secondWord;
    concatenation = firstWord + secondWord;
    std::cout << concatenation << std::endl;

    std::cout << "Concatenation of string literal + string type variable" << std::endl;
    std::string stringVar{"test"};
    concatenation = "string" + stringVar;
    std::cout << concatenation << std::endl;

    std::cout << "Concatenation of char variable + string type variable" << std::endl;
    char charVar{ 'a' };
    concatenation = charVar + stringVar;
    std::cout << concatenation << std::endl;

    std::cout << "Concatenation of char literal + string type variable" << std::endl;
    concatenation = 'b' + stringVar;
    std::cout << concatenation << std::endl;

    std::string numbersLog{};
    int enteredNR{};
    std::cout << "Enter an integer value: ";
    std::cin >> enteredNR;
    numbersLog += std::to_string(enteredNR);
    numbersLog += " ";
    std::cout << "Enter an integer value: ";
    std::cin >> enteredNR;
    numbersLog += std::to_string(enteredNR);
    numbersLog += " ";
    std::cout << "Enter an integer value: ";
    std::cin >> enteredNR;
    numbersLog += std::to_string(enteredNR);
    std::cout << "Log of entered numbers: " << numbersLog << std::endl;

    std::string nr1String{"3"};
    std::string nr2String{"3.1415"};
    std::cout << "One string contains " << nr1String << std::endl;
    std::cout << "Other string contains " << nr2String << std::endl;
    std::cout << "Adding strings " << nr1String + nr2String << std::endl;
    int nr1{ std::stoi(nr1String) };
    float nr2{ std::stof(nr2String) };
    std::cout << "Adding numbers " << nr1 + nr2 << std::endl;
}



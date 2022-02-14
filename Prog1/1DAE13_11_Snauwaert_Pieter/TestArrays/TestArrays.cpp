#include "pch.h"
#include <iostream>
#include "Time.h"

void MakeTimeArray();

int main()
{
    std::cout << "Hello World!\n";
    MakeTimeArray();
}

void MakeTimeArray()
{
    srand(time(nullptr));
    const int amountOfElements{ 4 };
    Time* pTime[amountOfElements]{ nullptr };
    for (int i{}; i < amountOfElements; ++i)
    {
        pTime[i] = new Time{rand()};
    }

    for (int i{}; i < amountOfElements; ++i)
    {
        std::cout << "element " << i + 1 << ": ";
        pTime[i]->Print();
        std::cout << std::endl;
    }

    for (int i{}; i < amountOfElements; ++i)
    {
        pTime[i]->AddSeconds(rand());
    }

    std::cout << std::endl;

    for (int i{}; i < amountOfElements; ++i)
    {
        std::cout << "element " << i + 1 << ": ";
        pTime[i]->Print();
        std::cout << std::endl;
    }

    for (int i{}; i < amountOfElements; ++i)
    {
        delete pTime[i];
        pTime[i] = nullptr;
    }

    std::cin.get();
}

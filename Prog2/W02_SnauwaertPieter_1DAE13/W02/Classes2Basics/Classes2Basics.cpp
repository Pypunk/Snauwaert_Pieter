// Classes2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Square.h"
#include "Time.h"
#include "Container.h"
void TestSquares();
void CompareTimes(const Time* t1, const Time* t2);
bool IsEqual(const Time* t1, const Time* t2);
void PrintInstanceCtr(const std::string& message);
void TestArrays();
void TestContainer();
void PrintContainer(const Container* pContainer);
int main()
{
    TestSquares();
    
    std::cout << std::endl;
    Time* t1{ new Time{20,30,11} };
    Time* t2{ new Time{20,30,11} };
    CompareTimes(t1, t2);
    delete t2;
    t2 = nullptr;
    t2 = new Time{ 40,40,7 };
    CompareTimes(t1, t2);
    delete t1;
    t1 = nullptr;
    delete t2;
    t2 = nullptr;
    std::cout << std::endl;

    std::cout << "---Instance counter tests---\n";
    PrintInstanceCtr("Before calling TestArrays");
    TestArrays();
    PrintInstanceCtr("After calling TestArrays");

    TestContainer();
    std::cin.get();
}


void TestSquares()
{
    Square square{10};
    square.Print();

    square = Square{ 10,20,30 };
    square.Print();
}

void CompareTimes(const Time* t1, const Time* t2)
{
    if (IsEqual(t1, t2))
    {
        std::cout << "They are equal\n";
    }
    else
    {
        std::cout << "They are not equal\n";
    }
}

bool IsEqual(const Time* t1, const Time* t2)
{
    std::cout << "--> Comparing 2 Time objects\n";
    t1->Print();
    t2->Print();
    if (t1->GetSeconds() == t2->GetSeconds() )
    {
        if (t1->GetMinutes() == t2->GetMinutes())
        {
            if (t1->GetHours() == t2->GetHours())
            {
                return true;
            }
        }
    }
    return false;
}

void PrintInstanceCtr(const std::string& message)
{
    std::cout << message << " ->  Nr of Time objects: " << Time::GetNrInstances() << std::endl << std::endl;
}

void TestArrays()
{
    const int amountOfTimeObjects{4};
    Time* t1[amountOfTimeObjects]{};
    PrintInstanceCtr("After defining the array of 4 Time object pointers");
    for (int i{}; i < amountOfTimeObjects; ++i)
    {
        t1[i] = new Time{ 5698 };
    }
    PrintInstanceCtr("After creating the 4 Time objects");
    for (int i{}; i < amountOfTimeObjects; ++i)
    {
        delete t1[i];
        t1[i] = nullptr;
    }
    PrintInstanceCtr("After deleting the 4 Time objects");

    Time t2[]{ Time{4},Time{985},Time{98587},Time{587} };
    PrintInstanceCtr("After defining the array of 4 Time objects");
}

void TestContainer()
{
    std::cout << "\n-- Container tests --\n";
    // Define a Container object
    const int cap{ 5 };
    std::cout << "Create container with capacity of " << cap << " elements\n";
    Container* pContainer{ new Container{cap} };
    PrintContainer(pContainer);

    // Add some values to the container
    int actNr{ 0 };
    std::cout << "\nPush back of " << (cap - 1) << " elements\n";
    for (int idx{ 1 }; idx < cap; ++idx)
    {
        pContainer->PushBack(rand() % 21);
        ++actNr;
    }
    PrintContainer(pContainer);

    std::cout << "\nChange the value of the elements (using Set)\n";
    for (int idx{ 0 }; idx < actNr; ++idx)
    {
        pContainer->Set(idx, rand() % 21);
    }
    PrintContainer(pContainer);

    std::cout << "\nPush back another " << (cap - 1) << " elements\n";
    for (int i{ 1 }; i < cap; ++i)
    {
        pContainer->PushBack(rand() % 21);
        ++actNr;
    }
    PrintContainer(pContainer);
    delete pContainer;
}

void PrintContainer(const Container* pContainer)
{
    std::cout << "-- Print container --\n";
    std::cout << "   Capacity: " << pContainer->Capacity() << std::endl;
    std::cout << "   Size: " << pContainer->Size() << std::endl;
    std::cout << "   Get the elements (using Get and Size)\n   ";
    for (int idx{ 0 }; idx < pContainer->Size(); ++idx)
    {
        std::cout << pContainer->Get(idx) << " ";
    }
    std::cout << std::endl;
}
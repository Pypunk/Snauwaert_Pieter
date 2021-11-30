// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
int Count( int* pNumbers, int nrToCount, int size );
void TestCount();
int MinElement(int* pNumbers, int size);
int MaxElement(int* pNumbers, int size);
void TestMinMax();
void Swap(int* pNumbers,int idx1, int idx2);
void TestSwap();
void Shuffle(int* pNumbers, int size, int amount);
void TestShuffle();
void BubbleSort(int* pNumbers, int size);
int GetRandInt(int min, int max);
int main()
{
    srand(int(time(nullptr)));
    TestCount();
    TestMinMax();
    TestSwap();
    TestShuffle();
    std::cout << "\n-- Test of Bubblesort functions --\n";
    int arrayToSort[]{ -10,1,10,3,4,-10,-2,-5,5,6 };
    std::cout << "Before sort\n";
    for (int i{}; i < sizeof(arrayToSort) / sizeof(int); ++i)
    {
        std::cout << arrayToSort[i] << " ";
    }
    std::cout << std::endl;
    BubbleSort(arrayToSort, sizeof(arrayToSort) / sizeof(int));
    std::cout << "After sort\n";
    for (int i{}; i < sizeof(arrayToSort) / sizeof(int); ++i)
    {
        std::cout << arrayToSort[i] << " ";
    }
    std::cout << std::endl;
    int arrayToSort2[]{ 3,-2,3,0,-3,-4,2,-5,-3,-1,-2,-5,3,3 };
    std::cout << "\nBefore sort\n";
    for (int i{}; i < sizeof(arrayToSort2) / sizeof(int); ++i)
    {
        std::cout << arrayToSort2[i] << " ";
    }
    std::cout << std::endl;
    BubbleSort(arrayToSort2, sizeof(arrayToSort2) / sizeof(int));
    std::cout << "After sort\n";
    for (int i{}; i < sizeof(arrayToSort2) / sizeof(int); ++i)
    {
        std::cout << arrayToSort2[i] << " ";
    }

    std::cin.get();
}

int Count(int* pNumbers, int nrToCount, int size)
{
    int counter{};
    for (int i{}; i < size; ++i)
    {
        if (pNumbers[i] == nrToCount)
        {
            counter++;
        }
    }
    return counter;
}

void TestCount()
{
    int arrayToCount[]{ 7,-3,9,-8,3,0,-7,1,9,8 };
    std::cout << "-- Test of Count function --\n";
    int size{ sizeof(arrayToCount) / sizeof(int) };
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToCount[i] << " ";
    }
    std::cout << std::endl;
    int nrToCount{ 2 };
    int nrCounted{ Count(arrayToCount, nrToCount, size) };
    std::cout << nrToCount << " occurs " << nrCounted << " times in the array\n\n";

    int arrayToCount2[]{ -4,-1,2,0,-3,0,2,4,2,0,0,-5,-1,1 };
    size = sizeof(arrayToCount2) / sizeof(int);
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToCount2[i] << " ";
    }
    std::cout << std::endl;
    nrToCount = 1;
    nrCounted = Count(arrayToCount2, nrToCount, size);
    std::cout << nrToCount << " occurs " << nrCounted << " times in the array\n\n";
}

int MinElement(int* pNumbers, int size)
{
    int min{ pNumbers[size-1] };
    for (int i{}; i < size; ++i)
    {
        if (pNumbers[i] < min)
        {
            min = pNumbers[i];
        }
    }
    return min;
}

int MaxElement(int* pNumbers, int size)
{
    int max{ pNumbers[size - 1] };
    for (int i{}; i < size; ++i)
    {
        if (pNumbers[i] > max)
        {
            max = pNumbers[i];
        }
    }
    return max;
}

void TestMinMax()
{
    int arrayToMinMax[]{ -4,2,5,5,3,2,-7,-7,3,3 };
    int size{ sizeof(arrayToMinMax) / sizeof(int) };
    std::cout << "-- Test of MinElement and MaxElement functions --\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToMinMax[i] << " ";
    }
    std::cout << std::endl;
    std::cout << MinElement(arrayToMinMax, size) << " is the smallest value in this array\n";
    std::cout << MaxElement(arrayToMinMax, size) << " is the largest value in this array\n\n";
    int arrayToMinMax2[]{ -2,0,0,3,0,0,-5,-5,1,-3,-5,-4,3,3 };
    size = sizeof(arrayToMinMax2) / sizeof(int);
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToMinMax2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << MinElement(arrayToMinMax2, size) << " is the smallest value in this array\n";
    std::cout << MaxElement(arrayToMinMax2, size) << " is the largest value in this array\n";
}

void Swap(int* pNumbers, int idx1, int idx2)
{
    const int temp{ pNumbers[idx1-1] };
    pNumbers[idx1-1] = pNumbers[idx2-1];
    pNumbers[idx2-1] = temp;
}

void TestSwap()
{
    std::cout << "-- Test of Swap Function --\n";
    int arrayToSwap[]{ 1,10,-10,-8,5,5,-9,10,5,-7 };
    int size{ sizeof(arrayToSwap) / sizeof(int) };
    std::cout << "Before swapping\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToSwap[i] << " ";
    }
    std::cout << std::endl;
    Swap(arrayToSwap, 1, size);
    std::cout << "After swapping the first and the last element\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToSwap[i] << " ";
    }
    std::cout << std::endl;
    int arrayToSwap2[]{ -2,3,2,-4,0,3,0,-4,-3,0,-4,-5,4,-2 };
    size = sizeof(arrayToSwap2) / sizeof(int);
    std::cout << "Before swapping\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToSwap2[i] << " ";
    }
    std::cout << std::endl;
    Swap(arrayToSwap2, 2, size - 1);
    std::cout << "After swapping the second and the second last element\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToSwap2[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

void Shuffle(int* pNumbers, int size, int amount)
{
    for (int i{}; i < amount; ++i)
    {
        int idx1{ GetRandInt(1,size) };
        int idx2{ GetRandInt(1,size) };
        if (idx1 == idx2)
        {
            idx2 = GetRandInt(1, size);
        }
        Swap(pNumbers, idx1, idx2);
    }
}

void TestShuffle()
{
    std::cout << "-- Test of Shuffle function --\n";
    int arrayToShuffle[]{ -2,1,4,-10,-5,6,-10,3,5,10 };
    int size{ sizeof(arrayToShuffle) / sizeof(int) };
    std::cout << "Before Shuffling\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToShuffle[i] << " ";
    }
    std::cout << std::endl;
    Shuffle(arrayToShuffle, size, 10);
    std::cout << "After shuffling 10 times\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToShuffle[i] << " ";
    }
    std::cout << std::endl;

    int arrayToShuffle2[]{ -1,3,3,3,-3,3,-3,-5,0,-2,-2,-5,-4,2 };
    size = sizeof(arrayToShuffle2) / sizeof(int);
    std::cout << "\nBefore Shuffling\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToShuffle2[i] << " ";
    }
    std::cout << std::endl;
    Shuffle(arrayToShuffle2, size, 20);
    std::cout << "After shuffling 20 times\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToShuffle2[i] << " ";
    }
    std::cout << std::endl;

    int arrayToShuffle3[]{ 1,2,3,4,5,6,7,8,9,10 };
    size = sizeof(arrayToShuffle3) / sizeof(int);
    std::cout << "\nBefore Shuffling\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToShuffle3[i] << " ";
    }
    std::cout << std::endl;
    Shuffle(arrayToShuffle3, size, 50);
    std::cout << "After shuffling 50 times\n";
    for (int i{}; i < size; ++i)
    {
        std::cout << arrayToShuffle3[i] << " ";
    }
    std::cout << std::endl;
}

void BubbleSort(int* pNumbers, int size)
{
    for (int i{}; i < size; ++i)
    {
        if (i + 1 < size)
        {
            if (pNumbers[i] > pNumbers[i + 1])
            {
                Swap(pNumbers, i + 1, i + 2);
            }
        }
    }
    size--;
    if (size >= 0)
    {
        BubbleSort(pNumbers, size);
    }
}

int GetRandInt(int min, int max)
{
    return ((rand() % int(max)) + min);
}

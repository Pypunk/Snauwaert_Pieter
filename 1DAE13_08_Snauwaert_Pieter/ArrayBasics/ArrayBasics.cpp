// ArrayBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "structs.h"

void AccessingElements(int* pNumbers, int size);
void SizeOfArrays(int* pNumbers, int size);
void MemoryAdressOfArrays(int* pNumbers, int size);
void PrintElements(int* pNumbers, int size);
void PrintElements(int* pNumbers, int startIdx, int endIdx);
void CreateArray2D();
int GetIndex(int rowIdx, int colIdx, int nrCols);

int main()
{
	int array1[5]{};
	int array2[]{ 10,20,30,40,50 };
	int array3[5]{ 5,10,15,20,25 };
	const int size{ sizeof(array1) / sizeof(int) };
	AccessingElements(array3, size);
	std::cout << std::endl;
	SizeOfArrays(array2, size);
	std::cout << std::endl;
	MemoryAdressOfArrays(array3, size);

	std::cout << "\n-- Passing an array to a function, PrintElements --\n";
	PrintElements(array1, size);
	PrintElements(array2, size);
	PrintElements(array3, size);

	std::cout << "-- Passing a range of elements --\n";
	PrintElements(array2, 1, 3);

	CreateArray2D();
	std::cin.get();
}

void AccessingElements(int* pNumbers, int size)
{
	std::cout << "-- Accessing elements --\n";
	std::cout << "First Element: " << pNumbers[0] << std::endl;
	std::cout << "Last Element: " << pNumbers[size-1] << std::endl;
	std::cout << "\nIterating over the elements\n";
	for (int i{}; i < size; ++i)
	{
		std::cout << pNumbers[i] << " ";
	}
}

void SizeOfArrays(int* pNumbers, int size)
{
	std::cout << "\n-- Size of arrays --\n";
	std::cout << "2nd array\n";
	std::cout << "nr of bytes: " << sizeof(pNumbers) << std::endl;
	std::cout << "size of one element: " << sizeof(pNumbers[0]) << std::endl;
	std::cout << "nr of elements: " << size << std::endl;
	for (int i{}; i < size; ++i)
	{
		std::cout << pNumbers[i] << " ";
	}
}

void MemoryAdressOfArrays(int* pNumbers, int size)
{
	std::cout << "\n-- The elements occupy consecutive memory locations --\n";
	std::cout << "Array of int types\n";
	for (int i{}; i < size; ++i)
	{
		std::cout << "Address of element with index " << i << " is " << &pNumbers[i] << std::endl;
	}
	std::cout << std::endl << std::endl;

	Point2f pointsArray[5]{};
	std::cout << "Array of Point2f types\n";
	for (int i{}; i < size; ++i)
	{
		std::cout << "Address of element with index " << i << " is " << &pointsArray[i] << std::endl;
	}
	std::cout << std::endl;
}

void PrintElements(int* pNumbers, int size)
{
	for (int i{}; i < size; ++i)
	{
		std::cout << pNumbers[i] << " ";
	}
	std::cout << std::endl;
}

void PrintElements(int* pNumbers, int startIdx, int endIdx)
{
	for (int i{ startIdx }; i <= endIdx; ++i)
	{
		std::cout << pNumbers[i] << " ";
	}
	std::cout << std::endl;
}

void CreateArray2D()
{
	std::cout << "\n-- 2D arrays --\n";
	const int size{ 20 };
	int array2D[size]{};
	const int cols{ 5 };
	const int rows{ 4 };
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			array2D[GetIndex(i, j, cols)] = (i+1) * 10 + j+1;
		}
	}
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			std::cout << array2D[GetIndex(i, j, cols)] << " ";
		}
		std::cout << std::endl;
	}
}

int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	return rowIdx * nrCols + colIdx;
}

// StringBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

void PrintStringProperties(const std::string& string);
void MakeCString(const std::string& string);
void UseArrayOperatorAndAt(const std::string& string);
void FindStringInString(const std::string& string, const std::string& stringToFind);
void ReverseFindStringInString(const std::string& string, const std::string& stringToFind);
void ReplaceInString(std::string& string, const std::string& stringToFind, const std::string& replaceString);
void EraseInString(std::string& toEraseIn, const std::string& toErase);
int main()
{
	std::string testString{ "Reveille was over at the military school,and the three boys on the end of the line nearest the mess hall walked slowly toward the broad steps of the big brick building ahead.They differed greatly in type, but of this they were unconscious, for all were deep in thought."};
	std::cout << "-- Explore string class --\n";
	std::cout << testString << std::endl;
	PrintStringProperties(testString);
	std::cout << std::endl;
	MakeCString(testString);
	std::cout << std::endl;
	UseArrayOperatorAndAt(testString);
	std::cout << std::endl;

	std::string stringToFind{};
	std::cout << "The string to search for in the above text? ";
	std::cin >> stringToFind;
	FindStringInString(testString, stringToFind);
	std::cout << std::endl;

	std::cout << "The string to search for in the above text? ";
	std::cin >> stringToFind;
	ReverseFindStringInString(testString, stringToFind);
	std::cout << std::endl;

	std::cout << "The string you want to replace * by? ";
	std::cin >> stringToFind;
	std::string replaceString{ '*' };
	ReplaceInString(testString, stringToFind, replaceString);
	std::cout << testString << std::endl << std::endl;

	std::cout << "The string you want to erase? ";
	std::cin >> stringToFind;
	EraseInString(testString, stringToFind);
	size_t position{ 0 };
	std::cout << testString << std::endl;
	PrintStringProperties(testString);


	std::cin.ignore();
	std::cin.get();

}

void PrintStringProperties(const std::string& string)
{
	std::cout << "Length of the string is: " << string.length() << std::endl;
	std::cout << "Size of the string is: " << string.size() << std::endl;
	std::cout << "Capacity of the string is: " << string.capacity() << std::endl;
}

void MakeCString(const std::string& string)
{
	const char* testChar{ string.c_str() };
	std::string copy{};
	for (size_t i{}; i < string.size(); i++)
	{
		copy += testChar[i];
		copy += '_';
	}
	std::cout << copy << std::endl;
}

void UseArrayOperatorAndAt(const std::string& string)
{
	std::cout << "First character using []: " << string[0] << std::endl;
	std::cout << "Last Character using []: " << string[string.size() - 1] << std::endl;
	std::cout << "First character using at: " << string.at(0) << std::endl;
	std::cout << "Last character using at: " << string.at(string.size() - 1) << std::endl;
}

void FindStringInString(const std::string& string, const std::string& stringToFind)
{
	size_t position{ 0 };
	do
	{
		position = string.find(stringToFind, position);
		if (position != std::string::npos)
		{
			std::cout << position << " ";
			++position;
		}
	} while (position != std::string::npos);
	std::cout << std::endl;
}

void ReverseFindStringInString(const std::string& string, const std::string& stringToFind)
{
	size_t position{ string.size()-1 };
	do
	{
		position = string.rfind(stringToFind, position);
		if (position != std::string::npos)
		{
			std::cout << position << " ";
			--position;
		}
	} while (position != std::string::npos);
	std::cout << std::endl;
}

void ReplaceInString(std::string& string, const std::string& stringToFind, const std::string& replaceString)
{
	size_t position{ 0 };
	do
	{
		position = string.find(stringToFind, position);
		if (position != std::string::npos)
		{
			string.replace(position, stringToFind.size(), replaceString);
			position++;
		}
	} while (position != std::string::npos);
}

void EraseInString(std::string& toEraseIn, const std::string& toErase)
{
	size_t position{};
	do
	{
		position = toEraseIn.find(toErase, position);
		if (position != std::string::npos)
		{
			toEraseIn.erase(position, toErase.size());
			position++;
		}
	} while (position != std::string::npos);
}

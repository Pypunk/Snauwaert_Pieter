#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
void EraseInString(std::string& toEraseIn, const std::string& toErase);
void ReplaceInString(std::string& string, const std::string& stringToFind, const std::string& replaceString);

int main()
{
    std::string readFilename{ "Resources/SoftwareQuotesInput.txt" };
    std::string writeFileName{ "Resources/SoftwareQuotesOutput.txt" };

    std::ifstream is{ readFilename };
    if (!is) std::cerr << "Error opening the file: " << readFilename << ".\n";

    std::stringstream ss{};

    std::string printString{};

    while (std::getline(is, printString,'.'))
    {
        ss << printString << ".\n\n";
    }

    printString = ss.str();
    EraseInString(printString, "\n");
    ReplaceInString(printString, ",", ", ");

    std::cout << printString;

    std::ofstream ofs{ writeFileName };
    if (!ofs) std::cerr << "Error opening the file: " << writeFileName << ".\n";
    ofs << printString;
    std::cin.get();
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

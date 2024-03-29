#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include "Player.h"
#include <iomanip>
#include <set> 
#include <map>
#include <algorithm>

struct City
{
	explicit City(std::string name, int population) :name{ name }, population{ population } {};
	std::string name;
	int population;
};

void TestPair();
void TestSetOfIntegers();
void TestSetOfPlayers();
void TestMultiset();
void TestMapOfGameRankings();
void TestMapOfCities();
void TestMultimap();

#pragma region HelperDeclarations
void PrintNumbers(const std::vector<int>& numbers);
void PrintNumber(int nr);
std::ostream& operator<<(std::ostream& out, const City& city);
void PrintCityPair(const std::pair<std::string, City> & p);
#pragma endregion

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	std::cout << std::boolalpha;

	// Explore the ordered associative containers
	TestPair( );

	TestSetOfIntegers( );
	TestSetOfPlayers( );

	TestMultiset( );
	
	TestMapOfGameRankings( );
	TestMapOfCities( );
	
	TestMultimap( );

	// Wait
	std::cout << "\nPush ENTER to continue";
	std::cin.get();

	return 0;
}

void TestPair()
{
	std::cout << "\n--> TestPair\n";
	// We will consider following pairs [gameName, rating] e.g.
	//    ["Andromeda",73.62f]
	//    ["World of Warcraft",91.89f]

	std::cout << "There are many ways to create a pair\n";
	// TODO: 1a. Create 2 std::pair<std::string, float> type objects pair1 and pair2
	// - pair1: Using the 2 arg constructor
	
	std::pair<std::string, float> pair1{ "Andromeda",73.62f };
	// - pair2: Using the result of std::make_pair as argument of the pair constructor
	const std::string string{ "World of Warcraft" };
	const float f{ 91.89f };
	std::pair<std::string, float> pair2{ std::make_pair(string, f) };

	std::cout << "\nThere are 2 ways to get the values of a pair\n";
	// TODO: 1b. Print the  pairs on the console
	// - One using first, second member
	std::cout << "Using the .first and .second on pair1: .first = " << pair1.first << ", .second = " << pair1.second << std::endl;
	// - The other using std::get<0> and std::get<1>
	std::cout << "Using the std::get<> on pair2: std::get<0> = " << std::get<0>(pair2) << ", std::get<1> = " << std::get<1>(pair2) << std::endl;
	std::cout << std::endl;
}

void TestSetOfIntegers()
{
	std::cout << "--> TestSetOfInts\n";
	// TODO: 2a. Create an empty set of integer type elements
	std::set<int> set1{};
	// TODO: 2b. Using the insert function of the set, add the multiples of value 10 in [10, 100] 
	int value{ 0 };
	while (value <= 100)
	{
		set1.insert(value);
		value += 10;
	}
	// TODO: 2c. Print the numbers using a ranged based for-loop, 
	//  You can use the  given function 'PrintNumber'
	for (const int& i : set1)
	{
		PrintNumber(i);
	}
	std::cout << std::endl;
	// TODO: 2d. Insert a number that is already in the set (e.g. the first number) 
	set1.insert(10);
	// TODO: 2e. Insert a number that is not yet in the set (e.g. the first number + 5)
	set1.insert(15);
	// TODO: 2f. Erase an element choose e.g. value 10 using this member function: size_type erase( const key_type& key );
	// and then print the value of the return value of calling this erase function: it is the number of elements removed
	std::cout << "Removing the number 10 " << set1.erase(10) << " times" << std::endl;
	// TODO: 2g. Erase this element again in the same way and print the result again
	for (const int& i : set1)
	{
		PrintNumber(i);
	}
	std::cout << std::endl;
	// TODO: 2h. Loop over the elements and erase the ones that are divisible by 3,
	restart: for (const int& i : set1)
	{
		if (i % 3 == 0)
		{
			set1.erase(i);
			goto restart;
		}
	}
	for (const int& i : set1)
	{
		PrintNumber(i);
	}
}

void TestSetOfPlayers()
{
	std::cout << "\n--> Set of Player objects\n";
	// TODO: 3a. Change Player::operator< function,
	// should be printed from low to high score
	std::set<Player> players;
	players.insert({
		Player{ "Devolder", "Warre", 1000 },
		Player{ "De schoenmaker", "An", 10 },
		Player{ "Janssens","Bart", 20 },
		Player{ "Janssens","Xavier", 30 } });	
	for (const Player& p : players)
	{
		std::cout << p << std::endl;
	}
}

void TestMultiset()
{
	std::cout << "\n--> Multiset of integer numbers\n";
	std::vector<int> numbersSrc{ 10,20,30,40 };
	std::cout << "These are the elements of the vector used as source: ";
	PrintNumbers(numbersSrc);

	// TODO: 4a. Create a multiset of integers using its constructor that takes iterators of the vector numbersSrc
	//       Then print the elements of the multiset using for_each
	std::multiset<int> ms1{ numbersSrc.begin(),numbersSrc.end() };
	std::for_each(ms1.begin(), ms1.end(), PrintNumber);

	const int value{ 50 };
	const int nrTimes{ 3 };
	std::cout << "\nInserting " << nrTimes << " times the value " << value << "\n";
	// TODO: 4b. Insert the same value multiple times 
	for (int i{}; i < nrTimes; ++i)
	{
		ms1.insert(value);
	}

	std::cout << "Verify that the multiset contains " << nrTimes << " times the value " << value << "\n";
	std::cout << "These are the elements of the multiset: ";
	// TODO: 4c. Print all the multiset elements
	std::for_each(ms1.begin(), ms1.end(), PrintNumber);

	std::cout << "\nErase the value " << value << " that occurs multiple times in the multiset\n";
	// TODO: 4d. Call erase using this same value, and print the returned value (number of erased elements)
	ms1.erase(value);
	std::cout << "Verify that the multiset doesn't contain the value " << value << " anymore\n";
	// TODO: 4e. Print all the multiset elements
	std::for_each(ms1.begin(), ms1.end(), PrintNumber);
}

void TestMapOfGameRankings()
{
	std::cout << "\n--> Map of Game rankings (key is name of game, value is the score)\n";
	// Ratings from http://www.gamerankings.com/pc/index.html

	std::cout << "\n--> How to create a map and adding elements to it";
	// TODO: 5a. Create a map, key is the name of a game, value is the score
	// Don't specify a compare function, in which case the operator< of std:string (key) is used

	std::map<std::string, float> map1{};
	// Some values
	// "League of Legends", 79.16f
	// "Andromeda", 73.62f
	// "Final Fantasy XIV", 78.54f
	// "World of Warcraft", 91.89f
	// "Grand Theft Auto", 94.39f
	// "Wild Hunt", 92.11f
	// "The Sims 3", 86.61f
	// "Fallout 4", 85.60f
	// "Grand Theft Auto: San Andreas", 91.94f
	// TODO: 5b. Add elements in 3 different ways, you can use the above data 
	// - Using the [] operator
	map1["League of Legends"] = 79.16f;
	// - Using the insert function
	map1.insert(std::make_pair("Andromeda", 73.62f));
	map1.insert(std::make_pair("Final Fantasy XIV", 78.54f));
	// - Using the emplace function
	map1.emplace("World of Warcraft", 91.89f);
	// TODO: 5c. Print the elements of the map using a ranged-based for loop
	std::cout << "\nThese are the elements of the map after adding elements in 3 different ways\n";
	for (const std::pair<std::string, float>& i : map1)
	{
		std::cout << "GameName: " << i.first << std::endl;
		std::cout << "Rating: " << i.second << std::endl;
	}

	std::cout << "\n--> How to change the content of a map";
	std::cout << "\nRemove an element using erase(key)";
	// TODO: 5d. Remove an element using erase(key)
	map1.erase("Andromeda");
	std::cout << "\nAdd an element with an already existing key but another value and check what happens\n";
	// No duplicate keys in map
	// TODO: 5e. Add an element with an already existing key and check what happens
	// - Using the [] operator
	map1["Final Fantasy XIV"] = 87.54f;
	// - Using the insert function
	map1.insert(std::make_pair("League of Legends", 79.54f));
	// - Using the emplace function
	map1.emplace("World of Warcraft", 98.5f);
	
	// TODO: 5f. Print the elements of the map using a ranged-based for loop
	std::cout << "\nThese are the elements of the map after these change operations\n";
	for (const std::pair<std::string, float>& i : map1)
	{
		std::cout << "GameName: " << i.first << std::endl;
		std::cout << "Rating: " << i.second << std::endl;
	}
	std::cout << "\n--> How to get the value of an element";
	std::cout << "\nGet the score of an existing game in 3 different ways and print the scores\n";
	// TODO: 5g. Get the score of a game in 3 different ways and print the 3 scores
	// - using []
	std::cout << map1["League of Legends"] << std::endl;
	// - using at
	std::cout << map1.at("World of Warcraft") << std::endl;
	// - using find
	std::cout << map1.find("Final Fantasy XIV")->second;

	std::cout << "\nGet the score of a not existing game in 3 different ways\n";
	// TODO: 5h. Get the score of a game in 3 different ways
	// but this time use a not existing key
	// Use this sequence:
	// - using at
	//std::cout << map1.at("Minecraft") << std::endl;
	// - using find
	//std::cout << map1.find("Portal 2")->second << std::endl;
	// - using []
	std::cout << map1["God Of War"] << std::endl;
	// Two of these result in an exception, one creates a new element, print the score of this element

	// TODO: 5i. And print the elements 
	std::cout << "\nThese are the elements of the map after getting some scores\n";

	std::cout << "\n--> How to change the key of an element";
	std::cout << "\nRename one of the games";
	// TODO: 5j. Rename one of the games, e.g. "Final Fantasy XIV" into "Final Fantasy"
	// You have to do this in 2 steps: 
	// - First create a new element "Final Fantasy" and copy the value of  "Final Fantasy XIV" into it
	// - Then delete "Final Fantasy XIV" using erase
	map1["Final Fantasy"] = map1["Final Fantasy XIV"];
	map1.erase("Final Fantasy XIV");

	std::cout << "\nThese are the elements of the map after changing 'Final Fantasy XIV' into 'Final Fantasy'\n";
	// TODO: 5l. Print the elements
	for (const std::pair<std::string, float>& i : map1)
	{
		std::cout << "GameName: " << i.first << std::endl;
		std::cout << "Rating: " << i.second << std::endl;
	}
}


void TestMapOfCities()
{
	std::cout << "\n--> Cities map, key is the name of a city, value is the City object\n";
	// TODO: 6a. Define this map, give it the name citiesMap

	std::cout << "\nInsert the cities from a given vector of City objects into the map using a loop\n";
	std::vector<City>  citiesSrc{
		City("Aalst",84000) ,
		City("Kortrijk",76000) ,
		City("Gent",255000) ,
		City("Antwerpen", 504000) ,
		City("Namen",111000) ,
		City("Hasselt",77000) ,
	};
	// TODO: 6b. Print the elements of citiesSrc vector
	for (City i : citiesSrc)
	{
		std::cout << i.name << " " << i.population << std::endl;
	}
	// TODO: 6c. Insert the cities from citiesSrc into the map using a loop
	std::map<std::string, City> citiesMap{};
	for (City i : citiesSrc)
	{
		citiesMap.insert(std::make_pair(i.name, i));
	}
	std::cout << "\nThese are the elements of the map after the insert operation\n";
	// TODO: 6d. Print the elements of the map using a range base for loop
	// Use a helper function PrintCityPair
	for (std::pair<std::string, City> i : citiesMap)
	{
		PrintCityPair(i);
	}
	// TODO: 6e. Uncommenting next code line of leads to a compiler error, why?
	// You don't need to solve this error, you just have to know why it results in an error
	//std::cout << citiesMap["Namen"].population << "\n";
}

void TestMultimap()
{
	std::cout << "\n--> Multimap for an English - Dutch dictionary\n";
	//TODO: 7a. Define an English - Dutch dictionary using a multimap 
	// It contains <std::string, std::string> pairs
	std::multimap<std::string, std::string> dictionary{};

	std::cout << "\nInsert elements from a source container (vector) into the multimap\n";
	std::vector<std::pair<std::string, std::string>> translations{
		{ "strange", "vreemd" },
	{ "date", "datum" },
	{ "smart", "heftig" },
	{ "right", "juist" },
	{ "smart", "bijdehand" },
	{ "strange", "onbekend" },
	{ "date", "dadel" },
	{ "right", "rechts" },
	{ "date", "afspraak" },
	};

	std::cout << "These are the elements of the vector:\n";
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << std::setw(10) << "English" << "Dutch";
	std::cout << std::setfill('-') << std::setw(20) << '\n';
	std::cout << std::setfill(' ') << '\n';
	// TODO:7b. Print the elements of translations vector
	for (std::pair<std::string, std::string> i : translations)
	{
		std::cout << i.first << " - " << i.second << std::endl;
	}

	// TODO: 7c. Add the elements from  the translations vector above. 
	for (std::pair<std::string, std::string> i : translations)
	{
		dictionary.insert(i);
	}

	std::cout << "\nThese are the elements of the multimap after the insert operation\n";
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << std::setw(10) << "English" << "Dutch";
	std::cout << std::setfill('-') << std::setw(20) << '\n';
	std::cout << std::setfill(' ') << '\n';
	// TODO: 7d. Print all the elements
	for (std::pair<std::string, std::string> i : dictionary)
	{
		std::cout << i.first << " - " << i.second << std::endl;
	}
	// In which order are they printed ?

	std::cout << "\nErase the elements with a specific key";
	const std::string wordEng{ "right" };
	// TODO: 7e. Erase all the values of elements having the key "right"
	dictionary.erase(wordEng);
	std::cout << "\nThese are the elements of the multimap after the erase operation\n";
	// TODO: 7f. Print all the elements
	for (std::pair<std::string, std::string> i : dictionary)
	{
		std::cout << i.first << " - " << i.second << std::endl;
	}
}

#pragma region HelperDefinitions
void PrintNumbers(const std::vector<int>& numbers)
{
	for (int nr : numbers)
	{
		std::cout << nr << " ";
	}
	std::cout << '\n';
}

void PrintNumber(int nr)
{
	std::cout << nr << " ";
}

std::ostream& operator<<(std::ostream& out, const City& city)
{
	out << city.name << " (" << city.population << ")";
	return out;
}

void PrintCityPair(const std::pair<std::string, City> & p)
{
	std::cout << p.second << '\n';
}
#pragma endregion

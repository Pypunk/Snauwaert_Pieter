#include "pch.h"
#include <iostream>
#include "player.h"

void PrintPlayer(player* pPlayer);

int main()
{
	player* pPlayer{ nullptr };
	pPlayer = new player{ "Tim",9 };

	PrintPlayer(pPlayer);
	pPlayer->AddPoints(500);

	PrintPlayer(pPlayer);

	delete pPlayer;
	pPlayer = nullptr;
	std::cout << std::to_string(int(pPlayer)) << std::endl;

	std::cin.get();
}

void PrintPlayer(player* pPlayer)
{
	if (pPlayer)
	{
		pPlayer->PrintInfo();
	}
}

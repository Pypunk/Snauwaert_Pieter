#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Weapon.h"
#include "Enemy.h"
#include "PickUp.h"

Game::Game()
{

}
Game::~Game()
{
	for (GameObject* ptr : m_pGameOjects)
	{
		delete ptr;
	}
	m_pGameOjects.clear();
}

void Game::AddEnemy()
{
	m_pGameOjects.push_back(new Enemy());
}

void Game::AddPickUp()
{
	m_pGameOjects.push_back(new PickUp());
}

void Game::AddWeapon()
{
	m_pGameOjects.push_back(new Weapon());
}

void Game::ReportAll() const
{
	int seqNr{ 0 };

	std::cout << "--> All Game objects\n";
	for (GameObject* ptr : m_pGameOjects)
	{
		std::cout << ptr->ToString() << "\n";
	}
}

void Game::ReportEnemies() const
{
	std::cout << "--> Enemies using dynamic_cast\n";
	for (GameObject* ptr : m_pGameOjects)
	{
		Enemy* enemy{ dynamic_cast<Enemy*>(ptr) };
		std::cout << enemy->ToString() << "\n";
	}
	std::cout << "--> Enemies using typeid\n";
	for (GameObject* ptr : m_pGameOjects)
	{
		if (typeid(*ptr) == typeid(Enemy))
		{
			std::cout << ptr->ToString() << "\n";
		}
	}
}
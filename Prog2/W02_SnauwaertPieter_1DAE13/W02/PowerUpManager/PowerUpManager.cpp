#include "pch.h"
#include "PowerUpManager.h"

PowerUpManager::PowerUpManager()
	:m_pItems{}
{
}

PowerUpManager::~PowerUpManager()
{
	for (PowerUp* i : m_pItems)
	{
		delete i;
		i = nullptr;
	}
}

PowerUp* PowerUpManager::AddItem(const Point2f& center, PowerUp::Type type)
{
	PowerUp* newPowerUp{ new PowerUp{center,type} };
	m_pItems.push_back(newPowerUp);
	return newPowerUp;
}

void PowerUpManager::Update(float elapsedSec)
{
	for (PowerUp* i : m_pItems)
	{
		i->Update(elapsedSec);
	}
}

void PowerUpManager::Draw() const
{
	for (PowerUp* i : m_pItems)
	{
		i->Draw();
	}
}

size_t PowerUpManager::Size() const
{
	return m_pItems.size();
}

bool PowerUpManager::HitItem(const Rectf& rect)
{
	for (int i{}; i < m_pItems.size(); ++i)
	{
		if (m_pItems[i]->IsOverlapping(rect))
		{
			delete m_pItems[i];
			m_pItems[i] = nullptr;
			m_pItems.erase(m_pItems.begin() + i);
			return true;
		}
	}
	return false;
}

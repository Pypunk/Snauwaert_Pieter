#include "pch.h"
#include "PowerUpManager.h"
#include "utils.h"

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
			SwapWithLast(m_pItems, i);
			delete m_pItems[m_pItems.size() - 1];
			m_pItems[m_pItems.size() - 1] = nullptr;
			m_pItems.pop_back();
			return true;
		}
	}
	return false;
}

void PowerUpManager::SwapWithLast(std::vector<PowerUp*>& powerUpsToSwap, int idx1)
{
	PowerUp* temp{ powerUpsToSwap[idx1] };
	powerUpsToSwap[idx1] = powerUpsToSwap[powerUpsToSwap.size() - 1];
	powerUpsToSwap[powerUpsToSwap.size()-1] = temp;
}

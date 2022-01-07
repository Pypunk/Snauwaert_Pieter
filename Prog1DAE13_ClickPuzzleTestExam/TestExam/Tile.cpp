#include "pch.h"		
#include "Tile.h"
#include "utils.h"

Tile::Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals)
	:m_Shape{ dstRect }
	, m_AmountOfAnimals{ nrAnimals }
	, m_Texture{}
	,m_IsActive{false}
	,m_CurrentAnimal{0}
{
	TextureFromFile(textPath, m_Texture);
}

Tile::~Tile()
{
	DeleteTexture(m_Texture);
}

void Tile::Draw()
{
	Rectf srcRect{};
	srcRect.width = m_Texture.width / m_AmountOfAnimals;
	srcRect.height = srcRect.width;
	srcRect.bottom = srcRect.width;
	srcRect.left = m_CurrentAnimal * srcRect.height;
	DrawTexture(m_Texture, m_Shape, srcRect);
	if (m_IsActive)
	{
		const float width{ m_Shape.width / 4.f };
		const float height{ m_Shape.height / 4.f };
		m_HitRegionLeft = Rectf{ m_Shape.left,m_Shape.bottom,width,height };
		m_HitRegionRight = Rectf{ m_Shape.left + m_Shape.width - width,m_Shape.bottom,width,height };
		SetColor(1.f, 1.f, 1.f, 0.2f);
		FillRect(m_Shape);
		SetColor(1, 0, 0, 1);
		DrawRect(m_HitRegionLeft);
		DrawRect(m_HitRegionRight);
	}
}

void Tile::CheckActivation(const Point2f& pos)
{
	m_IsActive = IsPointInRect(pos, m_Shape);
}

bool Tile::CheckHit(const Point2f& pos)
{
	if (IsPointInRect(pos, m_HitRegionLeft))
	{
		m_CurrentAnimal--;
		if (m_CurrentAnimal < 0)
		{
			m_CurrentAnimal = 5;
		}
		return true;
	}
	if (IsPointInRect(pos, m_HitRegionRight))
	{
		m_CurrentAnimal++;
		if (m_CurrentAnimal > 5)
		{
			m_CurrentAnimal = 0;
		}
		return true;
	}
	return false;
}

int Tile::GetCurrentAnimal()
{
	return m_CurrentAnimal;
}

void Tile::Deactivate()
{
	m_IsActive = false;
}

void Tile::Randomize()
{
	m_CurrentAnimal = GetRand(0, m_AmountOfAnimals-1);
}

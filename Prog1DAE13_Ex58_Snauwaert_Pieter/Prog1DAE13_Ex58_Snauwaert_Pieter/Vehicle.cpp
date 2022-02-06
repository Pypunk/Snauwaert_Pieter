#include "pch.h"
#include "Vehicle.h"
#include "utils.h"

Vehicle::Vehicle(int id)
	:m_MaxSpeed{200}
	,m_MinSpeed{20}
	,m_Position{0.f,0.f}
	,m_IsActive{true}
	,m_Speed{}
{
	std::string textureString{ "Resources/car-truck" };
	textureString += std::to_string(id) + ".bmp";
	TextureFromFile(textureString, m_Texture);
}

void Vehicle::Reset()
{
	m_Position.x = 0.f;
	m_Speed = float(GetRand(m_MinSpeed,m_MaxSpeed));
}

Vehicle::~Vehicle()
{
	DeleteTexture(m_Texture);
}

void Vehicle::Update(float elapsedSec, float windowWidth)
{
	if (m_IsActive)
	{
		m_Position.x += m_Speed * elapsedSec;
		if (m_Position.x > windowWidth)
		{
			SetRandomCar();
			m_Position.x = -GetRand(0.f,m_Texture.width);
		}
	}
}

void Vehicle::Draw()
{
	DrawTexture(m_Texture, m_Position);
}

bool Vehicle::IsIntersecting(const Point2f& pt)
{
	Rectf shape{ m_Position.x,m_Position.y,m_Texture.width,m_Texture.height };
	return (IsPointInRect(pt, shape));
}

void Vehicle::SetActive(bool isActive)
{
	m_IsActive = isActive;
}

void Vehicle::SetRandomCar()
{
	DeleteTexture(m_Texture);
	std::string textureString{ "Resources/car-truck" };
	textureString += std::to_string(GetRand(1, 5)) + ".bmp";
	TextureFromFile(textureString, m_Texture);
}

void Vehicle::SetYPos(float posY)
{
	m_Position.y = posY;
}

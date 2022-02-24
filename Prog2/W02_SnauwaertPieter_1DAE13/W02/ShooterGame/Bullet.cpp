#include "pch.h"
#include "Bullet.h"
#include "utils.h"
#include "Enemy.h"
#include "Texture.h"

Bullet::Bullet()
	:m_Center{}
	, m_Width{}
	, m_Height{}
	, m_Velocity{}
	, m_Boundaries{}
	, m_IsActivated{false}

{
	m_pTexture = new Texture{ "Resources/Rocket.png" };
}

Bullet::Bullet(float width, float height)
	:m_Center{}
	, m_Width{width}
	, m_Height{height}
	, m_Velocity{}
	, m_Boundaries{}
	, m_IsActivated{false}
{
	m_pTexture = new Texture{ "Resources/Rocket.png" };
}

Bullet::~Bullet()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Bullet::Draw() const
{
	Rectf shape{};
	shape.left = m_Center.x - m_Width / 2.f;
	shape.bottom = m_Center.y - m_Height / 2.f;
	shape.width = m_Width*0.5f;
	shape.height = m_Height*0.5f;
	if (m_IsActivated)
	{
		m_pTexture->Draw(shape);
	}
}

void Bullet::Update(float elapsedSec, Enemy** pEnemies, int numEnemies)
{
	if (m_IsActivated)
	{
		m_Center.y += m_Velocity.y * elapsedSec;
		m_Center.x += m_Velocity.x * elapsedSec;
	}
	CheckBoundaries();
	CheckEnemiesHit(pEnemies, numEnemies);
}

void Bullet::Shoot(const Point2f& center, const Vector2f& velocity)
{
	if (!m_IsActivated)
	{
		m_Center = center;
		m_Velocity = velocity;
		m_IsActivated = true;
	}
}

void Bullet::SetDimensions(float width, float height)
{
	m_Width = width;
	m_Height = height;
}

void Bullet::SetBoundaries(const Rectf& boundaries)
{
	m_Boundaries = boundaries;
}

void Bullet::CheckBoundaries()
{
	Rectf shape{};
	shape.left = m_Center.x - m_Width / 2.f;
	shape.bottom = m_Center.y - m_Height / 2.f;
	shape.width = m_Width * 0.5f;
	shape.height = m_Height * 0.5f;
	if (!utils::IsOverlapping(shape, m_Boundaries))
	{
		m_IsActivated = false;
	}
}

void Bullet::CheckEnemiesHit(Enemy** pEnemies, int numEnemies)
{
	Rectf shape{};
	shape.left = m_Center.x - m_Width / 2.f;
	shape.bottom = m_Center.y - m_Height / 2.f;
	shape.width = m_Width * 0.5f;
	shape.height = m_Height * 0.5f;
	if (m_IsActivated)
	{
		for (int i{}; i < numEnemies; ++i)
		{
			if (pEnemies[i]->DoHitTest(shape))
			{
				if (pEnemies[i]->IsDead())
				{
					m_IsActivated = false;
				}
			}
		}
	}
}

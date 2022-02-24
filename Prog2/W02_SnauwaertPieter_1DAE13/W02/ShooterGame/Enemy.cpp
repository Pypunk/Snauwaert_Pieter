#include "pch.h"
#include "Enemy.h"
#include "utils.h"
#include "Texture.h"

Enemy::Enemy()
	:m_Center{}
	, m_Height{}
	, m_Width{}
	,m_IsDead{false}
	,m_MoveSec{3}
	,m_CurrentSec{0}
{
	m_pTexture = new Texture{ "Resources/EnemySpaceship.png" };
}

Enemy::Enemy(const Point2f& center, float width, float height)
	:m_Center{center}
	,m_Width{width}
	,m_Height{height}
	,m_IsDead{false}
	,m_MoveSec{3}
	,m_CurrentSec{0}
{
	m_pTexture = new Texture{ "Resources/EnemySpaceship.png" };
}

Enemy::~Enemy()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Enemy::Update(float elapsedSec)
{
	m_CurrentSec += elapsedSec;
	if (m_MoveSec <= m_CurrentSec)
	{
		m_Center.y -= m_Height;
		m_CurrentSec = 0.f;
	}
}

void Enemy::Draw() const
{
	Rectf shape{};
	shape.left = m_Center.x - m_Width / 2.f;
	shape.bottom = m_Center.y - m_Height / 2.f;
	shape.width = m_Width;
	shape.height = m_Height;
	if (!m_IsDead)
	{
		m_pTexture->Draw(shape);
	}
}

bool Enemy::DoHitTest(const Rectf& other)
{
	Rectf shape{};
	shape.left = m_Center.x - m_Width / 2.f;
	shape.bottom = m_Center.y - m_Height / 2.f;
	shape.width = m_Width;
	shape.height = m_Height;
	if (!m_IsDead)
	{
		if (utils::IsOverlapping(shape, other))
		{
			m_IsDead = true;
			return true;
		}
	}
	return false;
}

void Enemy::SetCenter(const Point2f& center)
{
	m_Center = center;
}

void Enemy::SetDimensions(float width, float height)
{
	m_Width = width;
	m_Height = height;
}

bool Enemy::IsDead() const
{
	return m_IsDead;
}

#include "pch.h"
#include "Avatar.h"
#include "Bullet.h"
#include "utils.h"
#include "Texture.h"

Avatar::Avatar()
	:m_Center{}
	, m_Width{}
	, m_Height{}
	, m_Boundaries{}
	, m_Speed{}
	, m_pBullet{ new Bullet{0,0} }
{
	m_pTexture = new Texture{ "Resources/Spaceship.png" };
}

Avatar::Avatar(const Point2f& center, float width, float height)
	:m_Center{center}
	,m_Width{width}
	,m_Height{height}
	, m_Boundaries{}
	,m_Speed{200.f}
	, m_pBullet{ new Bullet{width / 2.f,height} }
{
	m_pTexture = new Texture{ "Resources/Spaceship.png" };
}

Avatar::~Avatar()
{
	delete m_pTexture;
	m_pTexture = nullptr;
	delete m_pBullet;
	m_pBullet = nullptr;
}

void Avatar::Update(float elapsedSec, Enemy** pEnemies, int numEnemies)
{
	HandleMoveKeyState(elapsedSec);
	Clamp();
	m_pBullet->Update(elapsedSec, pEnemies, numEnemies);
}

void Avatar::Draw() const
{
	Rectf shape{};
	shape.left = m_Center.x - m_Width / 2.f;
	shape.bottom = m_Center.y - m_Height / 2.f;
	shape.width = m_Width;
	shape.height = m_Height;
	m_pBullet->Draw();
	m_pTexture->Draw(shape);
}

void Avatar::SetCenter(const Point2f& center)
{
	m_Center = center;
}

void Avatar::SetDimensions(float width, float height)
{
	m_Height = height;
	m_Width = width;
}

void Avatar::SetBoundaries(const Rectf& boundaries)
{
	m_Boundaries = boundaries;
	m_pBullet->SetBoundaries(boundaries);
}

void Avatar::Clamp()
{
	if (m_Center.x+m_Width/2.f >= m_Boundaries.width)
	{
		m_Center.x = m_Boundaries.width-m_Width/2.f;
	}
	if (m_Center.x-m_Width/2.f <= m_Boundaries.left)
	{
		m_Center.x = m_Boundaries.left + m_Width / 2.f;
	}
}

void Avatar::HandleMoveKeyState(float elapsedSec)
{
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		m_Center.x += m_Speed * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_LEFT])
	{
		m_Center.x -= m_Speed * elapsedSec;
	}
}

void Avatar::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_UP:
		m_pBullet->Shoot(m_Center, Vector2f{ 0,500.f });
		break;
	}
}

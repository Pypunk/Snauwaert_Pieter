#include "pch.h"
#include "Character.h"
#include "utils.h"
#include <vector>
#include "Level.h"
#include "Sprite.h"
using namespace utils;

Character::Character(const Point2f& position)
	:m_Shape{position.x,position.y,50,40}
	,m_Gravity{-9.81f}
	,m_Velocity{}
	,m_IsJumping{false}
	,m_JumpSpeed{400.f}
	,m_HorSpeed{100.f}
	, m_pSprite{ new Sprite{"Resources/Kirby.png",11,2,1/10.f,2.f}}
	,m_State{ActorState::idle}
	,m_Left{false}
{
}

Character::~Character()
{
	delete m_pSprite;
	m_pSprite = nullptr;
}

void Character::Draw() const
{
	DrawRect(m_Shape);
	m_pSprite->Draw(Point2f{ m_Shape.left,m_Shape.bottom-7.f });
}

void Character::Update(float elapsedSec, const Level& level)
{
	m_Velocity.y += m_Gravity * elapsedSec;
	m_Shape.bottom += m_Velocity.y;
	if (level.IsOnGround(m_Shape))
	{
		m_IsJumping = false;
		m_State = ActorState::idle;
	}
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if (pStates[SDL_SCANCODE_LEFT])
	{
		m_Shape.left -= m_HorSpeed * elapsedSec;
		m_State = ActorState::moving;
		m_Left = true;
	}
	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_Shape.left += m_HorSpeed * elapsedSec;
		m_State = ActorState::moving;
		m_Left = false;
	}
	if (pStates[SDL_SCANCODE_SPACE])
	{
		if (level.IsOnGround(m_Shape))
		{
			m_IsJumping = true;
		}
	}
	Jump(elapsedSec, level);
	switch (m_State)
	{
	case Character::ActorState::moving:
		m_pSprite->Update(elapsedSec);
		m_pSprite->SetCurrentRow(1);
		break;
	case Character::ActorState::jumping:
		m_pSprite->SetCurrentRow(2);
		m_pSprite->ToggleOff();
		break;
	case Character::ActorState::idle:
		m_pSprite->SetCurrentRow(1);
		m_pSprite->ToggleOff();
		break;
	default:
		break;
	}
	m_pSprite->SetLeft(m_Left);
}

Rectf& Character::GetShape()
{
	return m_Shape;
}

Vector2f& Character::GetVelocity()
{
	return m_Velocity;
}

void Character::Jump(float elapsedSec, const Level& level)
{
	if (m_IsJumping)
	{
		m_State = ActorState::jumping;
		m_Shape.bottom += m_JumpSpeed * elapsedSec;
	}
}

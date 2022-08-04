#include "pch.h"
#include "Avatar.h"
#include "utils.h"
#include "Level.h"
#include "Sprite.h"

Avatar::Avatar()
	:m_IsJumping{false}
	,m_pSprite{new Sprite{"resources/Images/AvatarSheet.png",10,11,1/10.f,1}}
	, m_SpritePart{}
{
}

Avatar::~Avatar()
{
	delete m_pSprite;
}

void Avatar::Draw() const
{
	Color4f waitColor{1,1,0,1};
	Color4f moveColor{ 1,0,0,1 };
	Color4f transformColor{ 0,0,1,1 };
	switch (m_State)
	{
	case Avatar::ActorState::waiting:
		utils::SetColor(waitColor);
		break;
	case Avatar::ActorState::moving:
		utils::SetColor(moveColor);
		break;
	case Avatar::ActorState::tranforming:
		utils::SetColor(transformColor);
		break;
	default:
		break;
	}
	m_pSprite->Draw(m_Shape);
}

void Avatar::Update(float elapsedSec, const Level& level)
{
	if (m_State != ActorState::tranforming)
	{
		Move(elapsedSec, level);
		level.HandleCollision(m_Shape, m_Velocity);
		Jump(elapsedSec);
	}
	else
	{
		Transform(elapsedSec);
	}
	m_pSprite->Update(elapsedSec);
}

Rectf Avatar::GetShape() const
{
	return m_Shape;
}

void Avatar::PowerUpHit()
{
	m_State = ActorState::tranforming;
}

void Avatar::Move(float elapsedSec, const Level& level)
{
	m_Velocity.y += m_Acceleration.y * elapsedSec;
	m_Shape.bottom += m_Velocity.y;
	if (level.IsOnGround(m_Shape))
	{
		m_IsJumping = false;
		m_pSprite->SetRow(m_SpritePart+1);
		m_State = ActorState::waiting;
	}
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_LEFT])
	{
		if (m_State != ActorState::tranforming)
		{
			m_Shape.left -= m_HorSpeed * elapsedSec;
			m_pSprite->SetRow(m_SpritePart+2);
			m_pSprite->Flip(true);
			m_State = ActorState::moving;
		}
	}
	if (pStates[SDL_SCANCODE_RIGHT])
	{
		if (m_State != ActorState::tranforming)
		{
			m_Shape.left += m_HorSpeed * elapsedSec;
			m_pSprite->SetRow(m_SpritePart+2);
			m_pSprite->Flip(false);
			m_State = ActorState::moving;
		}
	}
	if (pStates[SDL_SCANCODE_UP])
	{
		if (level.IsOnGround(m_Shape))
		{
			m_IsJumping = true;
			m_State = ActorState::moving;
		}
	}
}

void Avatar::Jump(float elapsedSec)
{
	if (m_IsJumping)
	{
		m_Shape.bottom += m_JumpSpeed * elapsedSec;
	}
}

void Avatar::Transform(float elapsedSec)
{
	m_AccuTransformSec += elapsedSec;
	m_pSprite->SetRow(m_SpritePart+3);
	m_Velocity.y = 0.f;
	m_IsJumping = false;
	if (m_MaxTransformSec <= m_AccuTransformSec)
	{
		m_AccuTransformSec = 0.f;
		m_SpritePart += 3;
		m_State = ActorState::moving;
	}
}

#include "pch.h"
#include "Avatar.h"
#include "utils.h"
#include "Level.h"

Avatar::Avatar()
	:m_IsJumping{false}
{
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
	utils::FillRect(m_Shape);
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
}

Rectf& Avatar::GetShape()
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
	m_Shape.bottom += m_Velocity.y * elapsedSec;
	if (level.IsOnGround(m_Shape))
	{
		m_IsJumping = false;
		m_State = ActorState::waiting;
	}
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_LEFT])
	{
		if (m_State != ActorState::tranforming)
		{
			m_Shape.left -= m_HorSpeed * elapsedSec;
			m_State = ActorState::moving;
		}
	}
	if (pStates[SDL_SCANCODE_RIGHT])
	{
		if (m_State != ActorState::tranforming)
		{
			m_Shape.left += m_HorSpeed * elapsedSec;
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
	if (m_MaxTransformSec <= m_AccuTransformSec)
	{
		m_AccuTransformSec = 0.f;
		m_State = ActorState::moving;
	}
}

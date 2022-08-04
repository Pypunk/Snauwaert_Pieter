#pragma once
#include "Vector2f.h"
class Level;
class Avatar
{
public:
	Avatar();
	void Draw() const;
	void Update(float elapsedSec, const Level& level);

	Rectf& GetShape();
	void PowerUpHit();
private:
	enum class ActorState
	{
		waiting,
		moving,
		tranforming
	};
	ActorState m_State{ActorState::moving};
	Rectf m_Shape{50,280,36,97};
	float m_HorSpeed{ 200.f };
	float m_JumpSpeed{ 600.f };
	Vector2f m_Velocity{};
	Vector2f m_Acceleration{ 0.f,-981.f };
	float m_AccuTransformSec{};
	float m_MaxTransformSec{ 1.f };
	int m_Power{};
	bool m_IsJumping;

	void Move(float elapsedSec, const Level& level);
	void Jump(float elapsedSec);
	void Transform(float elapsedSec);
};


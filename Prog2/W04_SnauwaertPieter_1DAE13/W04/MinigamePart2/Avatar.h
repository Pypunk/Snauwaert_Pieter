#pragma once
#include "Vector2f.h"
class Level;
class Sprite;
class Avatar
{
public:
	Avatar();
	~Avatar();
	void Draw() const;
	void Update(float elapsedSec, const Level& level);

	Rectf GetShape() const;
	void PowerUpHit();
private:
	enum class ActorState
	{
		waiting,
		moving,
		tranforming
	};
	ActorState m_State{ActorState::moving};
	Rectf m_Shape{300,280,72,97};
	float m_HorSpeed{ 200.f };
	float m_JumpSpeed{ 600.f };
	int m_SpritePart;
	Vector2f m_Velocity{};
	Vector2f m_Acceleration{ 0.f,-9.81f };
	float m_AccuTransformSec{};
	float m_MaxTransformSec{ 1.f };
	int m_Power{};
	bool m_IsJumping;
	Sprite* m_pSprite;

	void Move(float elapsedSec, const Level& level);
	void Jump(float elapsedSec);
	void Transform(float elapsedSec);
};


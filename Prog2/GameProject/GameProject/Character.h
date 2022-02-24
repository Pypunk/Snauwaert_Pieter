#pragma once
#include "Vector2f.h"
#include <vector>
class Level;
class Sprite;
class Character
{
public:
	Character(const Point2f& position);
	~Character();

	void Draw() const;
	void Update(float elapsedSec, const Level& level);

	Rectf& GetShape();
	Vector2f& GetVelocity();
private:
	enum class ActorState
	{
		moving,
		jumping,
		idle
	};
	ActorState m_State;
	Rectf m_Shape;
	Vector2f m_Velocity;
	Sprite* m_pSprite;
	float m_HorSpeed;
	float m_JumpSpeed;
	float m_Gravity;
	bool m_IsJumping;
	bool m_Left;

	void Jump(float elapsedSec, const Level& level);
};


#pragma once
#include "utils.h"
#include "Vector2f.h"
class Texture;
class Platform
{
public:
	Platform(const Point2f& bottomLeft);
	~Platform();
	void Draw() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity);
	bool IsOnGround(const Rectf& actorshape);
private:
	Rectf m_Shape;
	Texture* m_pTexture;
};


#pragma once
#include <vector>
#include "Vector2f.h"
class Level
{
public:
	Level();
	void Draw() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity);
	bool IsOnGround(const Rectf& actorShape) const;
private:
	std::vector<Point2f> m_Vertices;
};


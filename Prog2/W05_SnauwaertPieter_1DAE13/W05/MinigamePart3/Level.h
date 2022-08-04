#pragma once
#include <vector>
#include "Vector2f.h"
class Texture;
class Platform;
class Level
{
public:
	Level();
	~Level();
	void DrawBackground() const;
	void DrawForeground() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape) const;
	bool HasReachedEnd(const Rectf& actorShape) const;
private:
	std::vector<std::vector<Point2f>> m_Vertices;
	Texture* m_pBackgroundTexture;
	Texture* m_pFenceTexture;
	Texture* m_pEndSignTexture;
	Point2f m_FenceBottomLeft;
	Rectf m_EndSignShape;
	Platform* m_pPlatform;
};


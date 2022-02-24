#include "pch.h"
#include "Level.h"
#include "utils.h"

Level::Level()
{
	m_Vertices.push_back(Point2f{ 0,10 });
	m_Vertices.push_back(Point2f{ 846,100 });
	m_Vertices.push_back(Point2f{ 1248,105 });
	m_Vertices.push_back(Point2f{ 1697,150 });
	m_Vertices.push_back(Point2f{ 2000,100 });
}

void Level::Draw() const
{
	utils::DrawPolygon(m_Vertices);
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity)
{
	Point2f rayp1{ actorShape.left + actorShape.width / 2.f,actorShape.bottom + actorShape.height };
	Point2f rayp2{ actorShape.left + actorShape.width / 2.f,actorShape.bottom };
	utils::HitInfo hit{};
	if (utils::Raycast(m_Vertices, rayp1, rayp2, hit))
	{
		actorShape.bottom = hit.intersectPoint.y;
		actorVelocity.y = 0.f;
	}
}

bool Level::IsOnGround(const Rectf& actorShape) const
{
	Point2f rayp1{ actorShape.left + actorShape.width / 2.f,actorShape.bottom + actorShape.height };
	Point2f rayp2{ actorShape.left + actorShape.width / 2.f,actorShape.bottom-1.f };
	utils::HitInfo hit{};
	return (utils::Raycast(m_Vertices, rayp1, rayp2, hit));
}

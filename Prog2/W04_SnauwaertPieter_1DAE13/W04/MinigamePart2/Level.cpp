#include "pch.h"
#include "Level.h"
#include "utils.h"
#include "Texture.h"
#include "SVGParser.h"

Level::Level()
	:m_pBackgroundTexture{new Texture{"resources/Images/background.png"}}
	,m_pFenceTexture{new Texture{"resources/Images/fence.png"}}
{
	SVGParser::GetVerticesFromSvgFile("resources/Images/level.svg", m_Vertices);
}

Level::~Level()
{
	delete m_pBackgroundTexture;
	delete m_pFenceTexture;
}

void Level::DrawBackground() const
{
	m_pBackgroundTexture->Draw();
}

void Level::DrawForeground() const
{
	m_pFenceTexture->Draw(Point2f{ 200,190 });
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const
{
	Point2f rayp1{ actorShape.left + actorShape.width / 2.f,actorShape.bottom + actorShape.height };
	Point2f rayp2{ actorShape.left + actorShape.width / 2.f,actorShape.bottom };
	utils::HitInfo hit{};
	for (std::vector<Point2f> i : m_Vertices)
	{
		if (utils::Raycast(i, rayp1, rayp2, hit))
		{
			actorShape.bottom = hit.intersectPoint.y;
			actorVelocity.y = 0.f;
		}
	}
}

bool Level::IsOnGround(const Rectf& actorShape) const
{
	Point2f rayp1{ actorShape.left + actorShape.width / 2.f,actorShape.bottom + actorShape.height };
	Point2f rayp2{ actorShape.left + actorShape.width / 2.f,actorShape.bottom-1.f };
	utils::HitInfo hit{};
	for (std::vector<Point2f> i : m_Vertices)
	{
		return (utils::Raycast(i, rayp1, rayp2, hit));
	}
	return false;
}

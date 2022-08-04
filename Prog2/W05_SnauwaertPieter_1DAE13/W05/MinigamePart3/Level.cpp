#include "pch.h"
#include "Level.h"
#include "utils.h"
#include "Texture.h"
#include "SVGParser.h"
#include "Platform.h"

Level::Level()
	:m_pBackgroundTexture{new Texture{"resources/Images/background.png"}}
	,m_pFenceTexture{new Texture{"resources/Images/fence.png"}}
	,m_pPlatform{new Platform{Point2f{100.f,300.f}}}
	,m_pEndSignTexture{new Texture{"Resources/Images/EndSign.png"}}
	,m_EndSignShape{730,224,0,0}
{
	SVGParser::GetVerticesFromSvgFile("resources/Images/level.svg", m_Vertices);
	m_EndSignShape.width = m_pEndSignTexture->GetWidth();
	m_EndSignShape.height = m_pEndSignTexture->GetHeight();
}

Level::~Level()
{
	delete m_pBackgroundTexture;
	delete m_pFenceTexture;
	delete m_pPlatform;
	delete m_pEndSignTexture;
}

void Level::DrawBackground() const
{
	m_pBackgroundTexture->Draw();
	m_pEndSignTexture->Draw(m_EndSignShape);
}

void Level::DrawForeground() const
{
	m_pFenceTexture->Draw(Point2f{ 200,190 });
	m_pPlatform->Draw();
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
	m_pPlatform->HandleCollision(actorShape, actorVelocity);
}

bool Level::IsOnGround(const Rectf& actorShape) const
{
	Point2f rayp1{ actorShape.left + actorShape.width / 2.f,actorShape.bottom + actorShape.height };
	Point2f rayp2{ actorShape.left + actorShape.width / 2.f,actorShape.bottom-1.f };
	utils::HitInfo hit{};
	for (std::vector<Point2f> i : m_Vertices)
	{
		if (utils::Raycast(i, rayp1, rayp2, hit))
		{
			return true;
		}
		if (m_pPlatform->IsOnGround(actorShape))
		{
			return true;
		}
	}
	return false;
}

bool Level::HasReachedEnd(const Rectf& actorShape) const
{
	return utils::IsOverlapping(actorShape,m_EndSignShape);
}

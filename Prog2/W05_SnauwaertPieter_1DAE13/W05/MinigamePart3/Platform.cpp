#include "pch.h"
#include "Platform.h"
#include "Texture.h"

Platform::Platform(const Point2f& bottomLeft)
	:m_pTexture{new Texture{"Resources/Images/platform.png"}}
	,m_Shape{bottomLeft.x,bottomLeft.y,0,0}
{
	m_Shape.width = m_pTexture->GetWidth();
	m_Shape.height = m_pTexture->GetHeight();
}

Platform::~Platform()
{
	delete m_pTexture;
}



void Platform::Draw() const
{
	m_pTexture->Draw(m_Shape);
}

void Platform::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity)
{
	if (utils::IsOverlapping(actorShape, m_Shape) && actorShape.bottom >= m_Shape.bottom)
	{
		actorShape.bottom = m_Shape.bottom+m_Shape.height;
		actorVelocity.y = 0.f;
	}
}

bool Platform::IsOnGround(const Rectf& actorshape)
{
	return utils::IsOverlapping(actorshape, m_Shape);
}

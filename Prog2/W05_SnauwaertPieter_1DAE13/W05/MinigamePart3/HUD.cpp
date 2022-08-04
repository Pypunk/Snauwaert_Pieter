#include "pch.h"
#include "HUD.h"
#include "Texture.h"

HUD::HUD(const Point2f& topLeft, int totalPowerUps)
	:m_TotalPowerUps{totalPowerUps}
	, m_HitPowerUps{}
	, m_pLeftTexture{ new Texture{"Resources/Images/HudLeft.png"} }
	, m_pRightTexture{ new Texture{"Resources/Images/HudRight.png"} }
	, m_pPowerUpTexture{ new Texture{"Resources/Images/HudPowerUp.png"} }
	, m_BottomLeft{ topLeft }
{
	m_BottomLeft.y -= m_pPowerUpTexture->GetHeight();
}

HUD::~HUD()
{
	delete m_pLeftTexture;
	delete m_pPowerUpTexture;
	delete m_pRightTexture;
}

void HUD::Draw() const
{
	Point2f position{ m_BottomLeft.x + m_pLeftTexture->GetWidth(),m_BottomLeft.y };
	for (int i{}; i < m_TotalPowerUps; ++i)
	{
		m_pPowerUpTexture->Draw(position, Rectf{ m_pPowerUpTexture->GetWidth() / 2.f,0,m_pPowerUpTexture->GetWidth() / 2.f,m_pPowerUpTexture->GetHeight() });
		position.x += m_pPowerUpTexture->GetWidth() / 2.f;
	}
	position = Point2f{ m_BottomLeft.x + m_pLeftTexture->GetWidth(),m_BottomLeft.y };
	for (int i{}; i < m_HitPowerUps; ++i)
	{
		m_pPowerUpTexture->Draw(position, Rectf{ 0,0,m_pPowerUpTexture->GetWidth() / 2.f,m_pPowerUpTexture->GetHeight()});
		position.x += m_pPowerUpTexture->GetWidth() / 2.f;
	}
	m_pLeftTexture->Draw(m_BottomLeft);
	m_pRightTexture->Draw(Point2f{ m_BottomLeft.x + m_pLeftTexture->GetWidth() + (m_pPowerUpTexture->GetWidth()/2.f * m_TotalPowerUps),m_BottomLeft.y });
}

void HUD::PowerUpHit()
{
	m_HitPowerUps++;
}

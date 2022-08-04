#include "pch.h"
#include "PowerUp.h"
#include "Texture.h"
#include "utils.h"

PowerUp::PowerUp(const Point2f& center, PowerUp::Type type)
	:m_Type{type}
	,m_RotSpeed{100.f}
	, m_Angle{}
	, m_pTexture{ new Texture{"Resources/Images/PowerUp.png"} }
	,m_Shape{center,0}
{
	m_Shape.radius = m_pTexture->GetWidth() / 2.f;
}

PowerUp::~PowerUp()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void PowerUp::Update(float elapsedSec)
{
	m_TextClip.left = 0.f;
	m_TextClip.width = m_pTexture->GetWidth();
	m_TextClip.height = m_pTexture->GetHeight() / 2.f;
	m_Angle += m_RotSpeed * elapsedSec;
	switch (m_Type)
	{
	case Type::brown:
		m_TextClip.bottom = 0.f;
		break;
	case Type::green:
		m_TextClip.bottom = m_pTexture->GetHeight() / 2.f;
		break;
	}
}

void PowerUp::Draw() const
{
	glPushMatrix();
	glTranslatef(m_Shape.center.x, m_Shape.center.y, 0.f);
	glRotatef(m_Angle, 0, 0, 1);
	switch (m_Type)
	{
	case Type::brown:
		m_pTexture->Draw(Point2f{ -utils::GetMiddle(m_TextClip).x,-utils::GetMiddle(m_TextClip).y }, m_TextClip);
		break;
	case Type::green:
		m_pTexture->Draw(Point2f{ -utils::GetMiddle(m_TextClip).x,-(utils::GetMiddle(m_TextClip).y-m_TextClip.height) }, m_TextClip);
		break;
	}
	glPopMatrix();
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	return utils::IsOverlapping(rect, m_Shape);
}

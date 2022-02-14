#include "pch.h"
#include "Light.h"
#include "utils.h"

Light::Light(const Rectf& rect, const Color4f& color)
	:m_Rect{rect}
	,m_IsOn{false}
	,m_Color{color}
{
}

void Light::Draw()
{
	const Color4f onColor{ m_Color };
	const Color4f offColor{ 0.4f,0.4f,0.4f,1.f };
	if (m_IsOn)
	{
		SetColor(onColor);
	}
	else
	{
		SetColor(offColor);
	}
	FillRect(m_Rect);
	SetColor(1, 1, 1, 1);
	DrawRect(m_Rect);
}

bool Light::IsHit(const Point2f& pos)
{
	if (IsPointInRect(pos, m_Rect))
	{
		m_IsOn = !m_IsOn;
		return true;
	}
	return false;
}

bool Light::IsOn()
{
	return m_IsOn;
}

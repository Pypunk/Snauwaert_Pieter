#include "pch.h"
#include "DaeEllipse.h"
#include "utils.h"
#include <iostream>

DaeEllipse::DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillColor)
	:m_Center{ center }
	, m_RadX{ radX }
	, m_RadY{ radY }
	, m_FillColor{ fillColor }
	, m_Area{ radX * radY * g_Pi }
	, m_IsActive{ false }
{
}

void DaeEllipse::Draw()
{
	Ellipsef ellipse{ m_Center,m_RadX,m_RadY };
	if (m_IsActive)
	{
		SetColor(m_FillColor);
		FillEllipse(ellipse);
	}
	else
	{
		Color4f transparentColor{ m_FillColor.r,m_FillColor.g,m_FillColor.b,0.7f };
		SetColor(transparentColor);
		FillEllipse(ellipse);
	}
}

void DaeEllipse::ActivateTest(const Point2f& pos)
{
	Ellipsef ellipse{ m_Center,m_RadX,m_RadY };
	if (IsPointInEllipse(pos, ellipse))
	{
		m_IsActive = true;
		std::cout << "Area of activated DaeEllipse: " << m_Area << std::endl;
	}
	else
	{
		m_IsActive = false;
	}
}

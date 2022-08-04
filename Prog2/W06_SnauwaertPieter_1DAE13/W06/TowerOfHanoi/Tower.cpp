#include "pch.h"
#include "Tower.h"
#include "utils.h"

Tower::Tower(const Point2f& position, float size)
	:m_BottomRect{position.x,position.y,size,25.f}
	,m_TowerRect{position.x+size/2.f-12.5f,position.y,25.f,size+size/2.f}
	,m_Size{size}
	,m_IsMouseOnTop{false}
{
}

void Tower::IsMouseOnTop(const Point2f& mousePos)
{
	Rectf rect{ m_BottomRect.left,m_BottomRect.bottom,m_Size,m_Size };
	m_IsMouseOnTop = (utils::IsPointInRect(mousePos, rect));
}

void Tower::Draw() const
{
	const Color4f white{ 0.5f,0.5f,0.5f,1 };
	const Color4f black{ 0,0,0,1 };
	utils::SetColor(white);
	utils::FillRect(m_TowerRect);
	utils::FillRect(m_BottomRect);
	utils::SetColor(black);
	utils::DrawRect(m_TowerRect);
	utils::DrawRect(m_BottomRect);
	const Rectf rect{ m_BottomRect.left,m_BottomRect.bottom,m_Size,m_Size+m_Size/2.f };
	const Color4f transBlack{ 0,0,0,0.5f };
	if (m_IsMouseOnTop)
	{
		utils::SetColor(transBlack);
		utils::FillRect(rect);
	}
}

float Tower::GetSize() const
{
	return m_Size;
}

Rectf Tower::GetRect() const
{
	return Rectf{ m_BottomRect.left,m_BottomRect.bottom,m_Size,m_Size + m_Size / 2.f };
}

Rectf Tower::GetBottomRect() const
{
	return m_BottomRect;
}

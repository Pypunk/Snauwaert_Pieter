#include "pch.h"
#include "Disk.h"
#include "utils.h"
#include "Tower.h"

Disk::Disk(const Point2f& position, float width, float height)
	:m_Rect{position.x,position.y,width,height}
	, m_IsClicked{false}
{
}

void Disk::Draw(const Color4f& color, const Point2f& mousePos)
{
	utils::SetColor(color);
	utils::FillRect(m_Rect);
	utils::SetColor(Color4f{ 0,0,0,1 });
	utils::DrawRect(m_Rect);
	if (m_IsClicked)
	{
		m_Rect.left = mousePos.x - m_Rect.width / 2.f;
		m_Rect.bottom = mousePos.y - m_Rect.height / 2.f;
	}
}

void Disk::ToggleClicked(const Point2f& mousePos)
{
	m_IsClicked = utils::IsPointInRect(mousePos, m_Rect);
}

void Disk::Release(const Tower* tower)
{
	if (m_IsClicked)
	{
		if (utils::IsOverlapping(m_Rect, tower->GetRect()))
		{
			m_Rect.left = tower->GetBottomRect().left + tower->GetBottomRect().width / 2.f - m_Rect.width / 2.f;
			m_Rect.bottom = tower->GetBottomRect().bottom + tower->GetBottomRect().height;
			m_IsClicked = false;
		}
	}
}

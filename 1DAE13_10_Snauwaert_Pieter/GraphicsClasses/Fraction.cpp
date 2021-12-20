#include "pch.h"
#include "Fraction.h"
#include "utils.h"

Fraction::Fraction(int numerator, int denominator)
	:m_Numerator{numerator}
	,m_Denominator{denominator}
{
}

void Fraction::Draw(const Point2f& position, float size)
{
	Point2f currentPosition{ position };
	for (int i{}; i < m_Numerator; ++i)
	{
		Rectf currentRect{ currentPosition.x,currentPosition.y,size,size };
		SetColor(0, 0, 1, 1);
		FillRect(currentRect);
		currentPosition.x += size;
	}
	currentPosition.x = position.x;
	for (int i{}; i < m_Denominator; ++i)
	{
		Rectf currentRect{ currentPosition.x,currentPosition.y,size,size };
		SetColor(1, 1, 1, 1);
		DrawRect(currentRect);
		currentPosition.x += size;
	}
}

float Fraction::GetValue()
{
	return float(m_Numerator) / float(m_Denominator);
}

#include "pch.h"		
#include "DaeEllipse.h"
#include "utils.h"
#include <string>
#include <iostream>

DaeEllipse::DaeEllipse(const Point2f& center, float width, float height, const Color4f& color, bool isFilled)
	:DaeShape{ center,width,height,color }
	, m_IsFilled{ isFilled }
{
}

DaeEllipse::~DaeEllipse()
{
}

void DaeEllipse::Draw( ) const
{
	utils::SetColor( m_Color );
	if ( m_IsFilled )
	{
		utils::FillEllipse( m_Center, m_Width / 2, m_Height / 2 );
	}
	else
	{
		utils::DrawEllipse( m_Center, m_Width / 2, m_Height / 2 );
	}
}

std::string DaeEllipse::ToString() const
{
	std::string properties{ "DaeEllipse\n" };
	properties += PropertiesToString();
	std::string str{ '"' };
	std::string boolString{};
	if (m_IsFilled)
	{
		boolString = "true";
	}
	else
	{
		boolString = "false";
	}
	properties += DaeShape::PropertiesToString();
	properties += "   IsFilled=" + str + boolString + str + "\n";
	return properties;
}

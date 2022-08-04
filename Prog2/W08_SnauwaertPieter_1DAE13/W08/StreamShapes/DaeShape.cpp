#include "pch.h"
#include "DaeShape.h"
#include <string>
#include <iomanip>

DaeShape::DaeShape(const Point2f& center, float width, float height, const Color4f& color)
	:m_Center{center}
	,m_Width{width}
	,m_Height{height}
	,m_Color{color}
{
}

DaeShape::~DaeShape()
{
}

void DaeShape::Translate(const Vector2f& tr)
{
	m_Center += tr;
}

std::string DaeShape::PropertiesToString() const
{
	std::string properties;
	std::string str{ '"' };
	properties += "   Center=" + str + std::to_string(int(m_Center.x)) + "," + std::to_string(int(m_Center.y)) + str + "\n";
	properties += "   Width=" + str + std::to_string(int(m_Width)) + str + "\n";
	properties += "   Height=" + str + std::to_string(int(m_Height)) + str + "\n";
	properties += "   Color=" + str + std::to_string(m_Color.r) + "," + std::to_string(m_Color.g) + "," + std::to_string(m_Color.b) + "," + std::to_string(m_Color.a) + str + "\n";
	return properties;
}

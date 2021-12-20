#include "pch.h"
#include <iostream>
#include "Square.h"

Square::Square(float size)
	:m_Size{size}
	,m_Left{0}
	,m_Bottom{0}
{
}

Square::Square(float size, float left, float bottom)
	:m_Size{size}
	,m_Left{left}
	,m_Bottom{bottom}
{
}

Square::~Square()
{
	std::cout << "Square destructor: release the resources\n";
}

void Square::Print()
{
	std::cout << "Left: " << m_Left << ", bottom: " << m_Bottom << std::endl;
	std::cout << "Size: " << m_Size << std::endl;
	std::cout << "Perimeter: " << GetPerimeter() << std::endl;
	std::cout << "Area: " << GetArea() << std::endl;
}

void Square::Translate(float deltaLeft, float deltaBottom)
{
	m_Left += deltaLeft;
	m_Bottom += deltaBottom;
}

void Square::SetSize(float newSize)
{
	m_Size = newSize;
}

float Square::GetArea()
{
	return m_Size*m_Size;
}

float Square::GetPerimeter()
{
	return m_Size * 4;
}

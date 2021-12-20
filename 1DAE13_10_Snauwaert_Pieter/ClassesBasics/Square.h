#pragma once
class Square
{
public:
	Square(float size);
	Square(float size, float left, float bottom);
	~Square();

	void Print();
	void Translate(float deltaLeft, float deltaBottom);
	void SetSize(float newSize);
	float GetArea();
	float GetPerimeter();
private:
	float m_Left;
	float m_Bottom;
	float m_Size;
};


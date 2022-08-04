#pragma once
class Tower
{
public:
	Tower(const Point2f& position, float size);
	void IsMouseOnTop(const Point2f& mousePos);
	void Draw() const;

	float GetSize() const;
	Rectf GetRect() const;
	Rectf GetBottomRect() const;
private:
	Rectf m_BottomRect;
	Rectf m_TowerRect;
	float m_Size;
	bool m_IsMouseOnTop;
};


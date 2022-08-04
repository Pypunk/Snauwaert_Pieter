#pragma once
class Tower;
class Disk
{
public:
	Disk(const Point2f& position, float width, float height);
	void Draw(const Color4f& color, const Point2f& mousePos);
	void ToggleClicked(const Point2f& mousePos);
	void Release(const Tower* tower);
private:
	Rectf m_Rect;
	bool m_IsClicked;
};


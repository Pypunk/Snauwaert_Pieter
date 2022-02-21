#pragma once
#include <vector>
class TrafficLight
{
public:
	TrafficLight(const Point2f& pos);
	void DoHitTest(const Point2f& point);
	void Update(float elapsedSec);
	void Draw() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	enum class State
	{
		green,
		orange,
		red,
		off
	};
	State m_State;
	Point2f m_Position;
	float m_AccumulatedSec;
	std::vector<Circlef>m_Lights;
	Rectf m_Armature;
};


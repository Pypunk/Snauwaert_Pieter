#include "pch.h"
#include "TrafficLight.h"
#include "utils.h"

TrafficLight::TrafficLight(const Point2f& pos)
	:m_State{State::off}
	,m_AccumulatedSec{0.f}
	,m_Armature{pos.x,pos.y,75,225}
	,m_Position{pos}
{
	Point2f centerPoint{ m_Position.x+m_Armature.width/2.f,m_Position.y + m_Armature.width/2.f };
	const float radius{ 30.f };
	for (int i{}; i < 3; ++i)
	{
		m_Lights.push_back(Circlef{ centerPoint,radius });
		centerPoint.y += m_Armature.height / 3.f;
	}
}

void TrafficLight::DoHitTest(const Point2f& point)
{
	bool isInlight{ false };
	if (utils::IsPointInCircle(point, m_Lights[0]))
	{
		m_AccumulatedSec = 0.f;
		m_State = State::green;
		isInlight = true;
	}
	if (utils::IsPointInCircle(point, m_Lights[1]))
	{
		m_AccumulatedSec = 0.f;
		m_State = State::orange;
		isInlight = true;
	}
	if (utils::IsPointInCircle(point, m_Lights[2]))
	{
		m_AccumulatedSec = 0.f;
		m_State = State::red;
		isInlight = true;
	}
	if (utils::IsPointInRect(point, m_Armature) && !isInlight)
	{
		m_State = State::off;
	}
}

void TrafficLight::Update(float elapsedSec)
{
	switch (m_State)
	{
	case TrafficLight::State::green:
		m_AccumulatedSec += elapsedSec;
		if (4 <= m_AccumulatedSec)
		{
			m_AccumulatedSec = 0.f;
			m_State = State::orange;
		}
		break;
	case TrafficLight::State::orange:
		m_AccumulatedSec += elapsedSec;
		if (1 <= m_AccumulatedSec)
		{
			m_AccumulatedSec = 0.f;
			m_State = State::red;
		}
		break;
	case TrafficLight::State::red:
		m_AccumulatedSec += elapsedSec;
		if (4 <= m_AccumulatedSec)
		{
			m_AccumulatedSec = 0.f;
			m_State = State::green;
		}
		break;
	}
}

void TrafficLight::Draw() const
{
	utils::SetColor(Color4f{ 0,0,0,1 });
	utils::FillRect(m_Armature);
	utils::SetColor(Color4f{ 0.5f,0.5f,0.5f,1.f });
	for (Circlef i : m_Lights)
	{
		utils::FillCircle(i);
	}
	Circlef light{};
	switch (m_State)
	{
	case TrafficLight::State::green:
		utils::SetColor(Color4f{ 0,1,0,1 });
		light = m_Lights[0];
		break;
	case TrafficLight::State::orange:
		utils::SetColor(Color4f{ 1.f,0.5f,0.f,1.f });
		light = m_Lights[1];
		break;
	case TrafficLight::State::red:
		utils::SetColor(Color4f{ 1,0,0,1 });
		light = m_Lights[2];
		break;
	case TrafficLight::State::off:
		light = Circlef{ 0,0,0 };
		break;
	}
	utils::FillCircle(light);
}

float TrafficLight::GetWidth() const
{
	return m_Armature.width;
}

float TrafficLight::GetHeight() const
{
	return m_Armature.height;
}

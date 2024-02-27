#include "pch.h"
#include "TrafficLight.h"
#include "utils.h"
#include <iostream>

//Sebastien Rojas Castillo - 1DAE15

TrafficLight::TrafficLight(const Point2f& pos):
	m_AccumulatedSec{}
,	m_Height		{240}
,	m_Width			{80}
,	m_CurrentState	{State::off}
,	m_LastState		{State::green}
,	m_Position		{pos}
,	m_Black			{Color4f {0,0,0,1}}
,	m_Gray			{Color4f {0.5f,0.5f,0.5f,1}}

{

}

void TrafficLight::DoHitTest(const Point2f& pos)
{
	Rectf body{ m_Position.x,m_Position.y,m_Width,m_Height };
	if (utils::IsPointInRect(pos,body))
	{
		std::cout << "clicked";
		State temp{};
		temp = m_CurrentState;
		m_CurrentState	= m_LastState;
		m_LastState		= temp;
	}
}
	
void TrafficLight::Update(float elapsedSec)
{
	m_AccumulatedSec += elapsedSec;

	switch (m_CurrentState)
	{
	case TrafficLight::State::green:
		if (m_AccumulatedSec >= 4) {
			m_CurrentState = TrafficLight::State::orange;
			m_AccumulatedSec = 0;
		}
		break;
	case TrafficLight::State::orange:
		if (m_AccumulatedSec >= 1) {
			m_CurrentState = TrafficLight::State::red;
			m_AccumulatedSec = 0;
		}
		break;
	case TrafficLight::State::red:
		if (m_AccumulatedSec >= 4) {
			m_CurrentState = TrafficLight::State::green;
			m_AccumulatedSec = 0;
		}
		break;
	default:
		break;
	}

}

void TrafficLight::Draw() const
{
	DrawNoLight();

	switch (m_CurrentState)
	{
	case TrafficLight::State::green:
		DrawGreenLight();
		break;
	case TrafficLight::State::orange:
		DrawOrangeLight();
		break;
	case TrafficLight::State::red:
		DrawRedLight();
		break;
	default:
		break;
	}
}

float TrafficLight::GetWidth()			const
{
	return m_Width;
}

float TrafficLight::GetHeight()			const
{
	return m_Height;

}

void TrafficLight::DrawRedLight()		const
{
	Point2f center{ m_Position.x + (m_Width / 2),m_Position.y + (m_Height / 6) + ((m_Height / 6) * (4)) };
	float radius{ (m_Width / 2) - 10 };
	
	utils::SetColor(Color4f{ 1,0,0,1 });
	
	utils::FillEllipse(center, radius, radius);
}

void TrafficLight::DrawOrangeLight()	const
{
	Point2f center{ m_Position.x + (m_Width / 2),m_Position.y + (m_Height / 6) + ((m_Height / 6) * (2)) };
	float radius{ (m_Width / 2) - 10 };

	utils::SetColor(Color4f{ 1,0.5f,0,1 });

	utils::FillEllipse(center, radius, radius);
}
void TrafficLight::DrawGreenLight()		const
{
	Point2f center{ m_Position.x + (m_Width / 2),m_Position.y + (m_Height / 6) };
	float radius{ (m_Width / 2) - 10 };

	utils::SetColor(Color4f{ 0,1,0,1 });

	utils::FillEllipse(center, radius, radius);
}

void TrafficLight::DrawNoLight()		const
{
	utils::SetColor(m_Black);
	utils::FillRect(m_Position, m_Width, m_Height);
	
	utils::SetColor(m_Gray);
	for (int i{ 0 }; i < 3;  i++)
	{
		Point2f center{ m_Position.x + (m_Width / 2),m_Position.y + (m_Height / 6) + ((m_Height / 6) * (2 * i)) };
		float radius{ (m_Width / 2) - 10 };
		utils::FillEllipse(center, radius, radius);
	}
}
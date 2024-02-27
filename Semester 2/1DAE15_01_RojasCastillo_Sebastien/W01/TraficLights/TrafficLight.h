#pragma once

//Sebastien Rojas Castillo - 1DAE15

class TrafficLight
{
public:
	enum class State
	{
		green,
		orange,
		red,
		off
	};

	TrafficLight(const Point2f& pos);
	void DoHitTest(const Point2f& pos);
	void Update(float elapsedSec);
	void Draw() const;
	float GetWidth() const;
	float GetHeight() const;
	
private:
	State m_CurrentState;
	State m_LastState;

	Point2f m_Position;
	float m_AccumulatedSec;
	float m_Width;
	float m_Height;

	Color4f m_Black;
	Color4f m_Gray;


	void DrawRedLight()		const;
	void DrawOrangeLight()  const;
	void DrawGreenLight()	const;
	void DrawNoLight()		const;

};


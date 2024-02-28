#pragma once
class Avatar
{
public:
	Avatar();
	Avatar(const Point2f& center, float width, float height, const Rectf& fieldBoundaries);

	void MoveLeft(float elapsedSec);
	void MoveRight(float elapsedSec);

	void Draw() const;

	void SetCenter(const Point2f& center);
	void SetDimentions(float width, float height);
	void SetFieldBoundaries(const Rectf& boundaries);

private:

	void Clamp();
	Rectf GetBounds;

	Point2f m_Center;
	float m_Width;
	float m_Height;
	float m_Speed;
	Rectf m_FieldBoundaries;
};


#pragma once
// Sebastien Rojas Castillo - 1DAE15


class Enemy
{
public:
	Enemy();
	Enemy(const Point2f& center, float width, float height);

	void Draw() const;
	void SetCenter(const Point2f& center);
	void SetDimentions(float width, float height);

	bool DoHitTest(const Rectf& other);
	bool IsDead() const;

private:

	Rectf GetBounds() const;

	Point2f m_Center;
	float	m_Width;
	float	m_Height;
	bool	m_IsDead;
};


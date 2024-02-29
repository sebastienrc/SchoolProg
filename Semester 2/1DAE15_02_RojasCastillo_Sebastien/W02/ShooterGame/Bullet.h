#pragma once
#include "Vector2f.h"
#include "vector"

// Sebastien Rojas Castillo - 1DAE15

class Enemy;

class Bullet
{
public:
	Bullet();
	Bullet(float width, float height, const Rectf& fieldBoundaries);

	void Draw() const;

	void Update(float elapsedSec, std::vector <Enemy*>& enemies);
	void Shoot(const Point2f& center,const Vector2f& velocity);

	void SetDimentions(float width, float height);
	void SetFieldBoundaries(const Rectf& boundaries);

private:

	Point2f		m_Center;
	float		m_Width;
	float		m_Height;
	Vector2f	m_Velocity;
	Rectf		m_FieldBoundaries;
	bool		m_IsActivated;

	Rectf	GetBounds() const;
	void	CheckBoundaries();
	void	CheckEnemiesHit(std::vector<Enemy*>& enemies);

};


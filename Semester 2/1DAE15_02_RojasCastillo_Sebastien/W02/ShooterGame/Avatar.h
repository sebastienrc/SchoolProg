#pragma once
#include "vector"
class Bullet;
class Enemy;

// Sebastien Rojas Castillo - 1DAE15


class Avatar
{
public:
	Avatar();
	Avatar(const Point2f& center, float width, float height, const Rectf& fieldBoundaries);

	~Avatar();

	void MoveLeft(float elapsedSec);
	void MoveRight(float elapsedSec);

	void Draw() const;
	void Update(float elapsedSec,std::vector<Enemy*>& enemies);

	void SetCenter(const Point2f& center);
	void SetDimentions(float width, float height);
	void SetFieldBoundaries(const Rectf& boundaries);

	void Shoot();

private:

	void Clamp();
	Rectf GetBounds() const;

	Point2f m_Center;
	float m_Width;
	float m_Height;
	float m_Speed;
	Rectf m_FieldBoundaries;

	Bullet* m_pBullet;
};


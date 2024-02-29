#include "pch.h"
#include "Bullet.h"
#include "utils.h"
#include "Enemy.h"
// Sebastien Rojas Castillo - 1DAE15


Bullet::Bullet():
	m_Center			{}
,	m_Width				{}
,	m_Height			{}
,	m_Velocity			{}
,	m_FieldBoundaries	{}
,	m_IsActivated		{false}
{
}

Bullet::Bullet(float width, float height, const Rectf& fieldBoundaries):
	m_Center			{}
,	m_Width				{width}
,	m_Height			{height}
,	m_Velocity			{}
,	m_FieldBoundaries	{fieldBoundaries}
,	m_IsActivated		{false}
{
}

void Bullet::Draw() const
{
	Color4f red{ 1,0,0,1 };
	utils::SetColor(red);

	if(m_IsActivated)
	utils::FillRect(GetBounds());
}

void Bullet::Shoot(const Point2f& center, const Vector2f& velocity)
{
	if (!m_IsActivated)
	{
		m_IsActivated = true;
		m_Center = center;
		m_Velocity = velocity;
	}
}

void Bullet::CheckBoundaries()
{
	Rectf body{ m_Center.x - (m_Width / 2), m_Center.y - (m_Height / 2),m_Width,m_Height };

	if (!utils::IsOverlapping(body, m_FieldBoundaries))
		m_IsActivated = false;
}

void Bullet::Update(float elapsedSec, std::vector <Enemy*>& enemies)
{
	if (m_IsActivated)
	{
		CheckBoundaries();
		m_Center += m_Velocity * elapsedSec;
		CheckEnemiesHit(enemies);
	}
}

void Bullet::SetDimentions(float width, float height)
{
	m_Width		= width;
	m_Height	= height;
}

void Bullet::SetFieldBoundaries(const Rectf& boundaries)
{
	m_FieldBoundaries = boundaries;
}


Rectf Bullet::GetBounds() const
{
	Rectf bounds{ m_Center.x - (m_Width / 2), m_Center.y - (m_Height / 2), m_Width, m_Height };
	
	return bounds;
}

void Bullet::CheckEnemiesHit(std::vector<Enemy*>& enemies)
{
	for (size_t i{ 0 }; i < enemies.size(); i++)
	{
		if (enemies[i]->DoHitTest(GetBounds())) {
			m_IsActivated = false;
		}
			
	}
}
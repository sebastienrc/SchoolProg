#include "pch.h"
#include "Enemy.h"
#include "utils.h"


Enemy::Enemy(const Point2f& center, float width, float height):
	m_Center	{center}
,	m_Width		{width}
,	m_Height	{height}
,	m_IsDead	{false}
{


}


Rectf Enemy::GetBounds() const
{
	Rectf bounds{ m_Center.x - (m_Width / 2), m_Center.y - (m_Height / 2), m_Width, m_Height };


	return bounds;
}


void Enemy::Draw() const
{
	utils::SetColor(Color4f{ 1,0,0,1 });
	if(!m_IsDead)
	utils::DrawRect(GetBounds());

}

void Enemy::SetCenter(const Point2f& center)
{
	m_Center	= center;
}

void Enemy::SetDimentions(float width, float height)
{
	m_Width		= width;
	m_Height	= height; 

}

bool Enemy::DoHitTest(const Rectf& other)
{
	if (utils::IsOverlapping(GetBounds(), other))
	{
		m_IsDead = true;
		return true;
	}
	return false;
}

bool Enemy::IsDead() const
{
	return m_IsDead;
}
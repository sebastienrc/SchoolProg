#include "pch.h"
#include "Avatar.h"
#include "Bullet.h"
#include "utils.h"
#include "Enemy.h"
// Sebastien Rojas Castillo - 1DAE15

Avatar::Avatar():
	m_Center			{}
,	m_Width				{}
,	m_Height			{}
,	m_Speed				{20.f}
,	m_FieldBoundaries	{}
,	m_pBullet			{new Bullet{10.f,20.f,m_FieldBoundaries}}
{

}

Avatar::Avatar(const Point2f& center, float width, float height, const Rectf& fieldBoundaries):
	m_Center			{center}
,	m_Width				{width}
,	m_Height			{height}
,	m_Speed				{20.f}
,	m_FieldBoundaries	{fieldBoundaries}
,	m_pBullet			{new Bullet{10.f,20.f,m_FieldBoundaries}}
{
}

Avatar::~Avatar()
{
	delete m_pBullet;
}

void Avatar::MoveLeft(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	Clamp();
	if (pStates[SDL_SCANCODE_LEFT])
		m_Center.x -= m_Speed * elapsedSec;
}

void Avatar::MoveRight(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	Clamp();
	if (pStates[SDL_SCANCODE_RIGHT])
		m_Center.x += m_Speed * elapsedSec;

}

void Avatar::SetCenter(const Point2f& center)
{
	m_Center	= center;

}

void Avatar::SetDimentions(float width, float height)
{

	m_Width		= width;
	m_Height	= height; 

}

void Avatar::SetFieldBoundaries(const Rectf& boundaries)
{

	m_FieldBoundaries = boundaries;

}


void Avatar::Clamp()
{

	if (GetBounds().left < m_FieldBoundaries.left)
	{
		m_Center.x = m_FieldBoundaries.left + (m_Width / 2);
	}
	else if (GetBounds().left + m_Width > m_FieldBoundaries.left + m_FieldBoundaries.width)
	{
		m_Center.x = m_FieldBoundaries.left + m_FieldBoundaries.width - (m_Width / 2);
	}

}


void Avatar::Draw() const
{
	Color4f yellow{ 1,1,0,1 };
	
	utils::SetColor(yellow);
	utils::DrawRect(GetBounds(), 2);
	m_pBullet->Draw();
}

Rectf Avatar::GetBounds() const
{
	Rectf bounds{ m_Center.x - (m_Width / 2), m_Center.y - (m_Height / 2), m_Width, m_Height };

	return bounds;
}

void Avatar::Shoot()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_UP])
	{
		m_pBullet->Shoot(m_Center, Vector2f{ 0.f,100.f });
	}

}

void Avatar::Update(float elapsedSec, std::vector<Enemy*>& enemies)
{
	m_pBullet->Update(elapsedSec,enemies);
}
#include "pch.h"
#include "Avatar.h"


Avatar::Avatar():
	m_Center			{}
,	m_Width				{}
,	m_Height			{}
,	m_Speed				{}
,	m_FieldBoundaries	{}
{

}

Avatar::Avatar(const Point2f& center, float width, float height, const Rectf& fieldBoundaries):
	m_Center			{center}
,	m_Width				{width}
,	m_Height			{height}
,	m_Speed				{}
,	m_FieldBoundaries	{fieldBoundaries}
{



}

void Avatar::MoveLeft(float elapsedSec)
{

}
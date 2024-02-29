#include "pch.h"
#include "PowerUp.h"

#include "Texture.h"
#include "utils.h"

// Sebastien Rojas Castillo - 1DAE15

PowerUp::PowerUp(const Point2f& center, Type type)
:	m_Type{type}
,	m_pTexture{nullptr}
,	m_RotSpeed{360.f}
,	m_Shape{}
,	m_TextClip {}
,	m_Angle	{}
{
	m_pTexture	= new Texture{ "PowerUp.png" };
	m_TextClip	= Rectf{0, (m_pTexture->GetHeight() / 2) * int(m_Type)
						,m_pTexture->GetWidth(), m_pTexture->GetHeight() / 2};
	m_Shape = Circlef{ center , m_pTexture->GetWidth() / 2 };
}

PowerUp::~PowerUp()
{
	delete m_pTexture;
}

void PowerUp::Update(float elapsedSec)
{
	m_Angle += m_RotSpeed * elapsedSec;
}

void PowerUp::Draw() const
{
	glPushMatrix();
	{
		glTranslatef(m_Shape.center.x, m_Shape.center.y, 0);
		glRotatef(m_Angle, 0, 0, 1);
		m_pTexture->Draw(Point2f{-m_Shape.radius,-m_Shape.radius}, m_TextClip);
	}
	glPopMatrix();
	
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	return utils::IsOverlapping(rect, m_Shape);
}
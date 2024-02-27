#include "pch.h"
#include "Card.h"
#include "Texture.h"
#include <sstream>
#include <iostream>

//Sebastien Rojas Castillo - 1DAE15

const int Card::m_MinRank{ 1 };
const int Card::m_MaxRank{ 13 };

Card::Card(Suit suit, int rank, float angle, const Circlef& circle):
	m_pTexture{nullptr}
,	m_Suit{suit}
,	m_Rank{rank}
,	m_Height{}
,	m_Width{}
,	m_Angle{angle}
,	m_RotSpeed	{150.f}
,	m_Shape		{circle}
{

	if (rank >= m_MinRank && rank <= m_MaxRank)
	{

		m_pTexture = new Texture{ GetImagePath(suit, rank) };
		m_Height = m_pTexture->GetHeight();
		m_Width = m_pTexture->GetWidth();

	}
	else
		std::cout << "Error! Rank not in range, Try again\n";
}

Card::~Card()
{
	delete m_pTexture;
	m_pTexture = nullptr;
	std::cout << "Destructor executed";
}

void Card::Update(float elapsedSec)
{
	m_Angle += m_RotSpeed * elapsedSec;
}



std::string Card::GetImagePath(Suit suit, int rank) const
{
	int cardNumber{};
	cardNumber = (int(suit) * 100) + rank;

	std::stringstream buffer;

	buffer << "Cards/" << cardNumber << ".png";

	return buffer.str();
}

float Card::GetWidth() const
{
	return m_Width;
}

float Card::GetHeight() const
{
	return m_Height;
}
void Card::Draw() const
{
	Rectf srcRect{ 0,m_Height,m_Width,m_Height };

	glPushMatrix();
	{
		glTranslatef(m_Shape.radius, m_Shape.radius, 0);
		glScalef(0.5f, 0.5f, 1);
		glRotatef(m_Angle, 0, 0, 1);
		m_pTexture->Draw(Rectf {m_Shape.radius,0,m_Width,m_Height}, srcRect);
	}
	glPopMatrix();
}
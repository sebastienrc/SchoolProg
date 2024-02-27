#pragma once
class Texture;
//Sebastien Rojas Castillo - 1DAE15

class Card final
{
public:
	enum class Suit
	{
		clubs = 1,
		diamonds = 2,
		hearts = 3,
		spades = 4
	};

	explicit Card( Suit suit, int rank,float angle, const Circlef& circle );
	~Card();
	void Draw() const; // const member functions is new, will be explained in the theory

	static const int m_MinRank;
	static const int m_MaxRank;

	void Update(float ElapsedSec);

	float GetWidth()const ;// const member functions is new, will be explained in the theory
	float GetHeight()const ;// const member functions is new, will be explained in the theory
private:
	float m_Width;
	float m_Height;
	const Texture *m_pTexture;
	const Suit m_Suit;
	const int m_Rank;

	Circlef m_Shape;
	float m_Angle;
	float m_RotSpeed;

	std::string GetImagePath(Suit suit, int rank) const;// const member functions is new, will be explained in the theory
};
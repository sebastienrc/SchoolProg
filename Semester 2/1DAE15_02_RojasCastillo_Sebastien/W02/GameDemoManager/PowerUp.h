#pragma once

// Sebastien Rojas Castillo - 1DAE15

class Texture;


class PowerUp
{
public:
	enum class Type
	{
		green = 1
	,	brown = 2
	};




	PowerUp(const Point2f& center, Type type);
	~PowerUp();
	void Update(float elapsedSec);
	void Draw() const;
	bool IsOverlapping(const Rectf& rect) const;

private:
	const Type m_Type;
	Circlef m_Shape;
	const Texture* m_pTexture;
	Rectf m_TextClip;
	float m_Angle;
	const float m_RotSpeed;



};


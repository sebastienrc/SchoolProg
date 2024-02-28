#pragma once
#include "PowerUp.h"
#include "vector"


class PowerUpManager
{
public:
	PowerUpManager();
	~PowerUpManager();

	void AddItem(Point2f centePos, PowerUp::Type type);
	void AddItem(float centerX, float centerY, PowerUp::Type type);

	void Draw() const;
	void Update(float elapsedSec);
	size_t Size() const;
	int IsHit(const Rectf& rect) ;
	void RemoveItem(int idx);

private:

	std::vector <PowerUp*> m_PowerUps;

};


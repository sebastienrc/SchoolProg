#include "pch.h"
#include "PowerUpManager.h"



PowerUpManager::PowerUpManager():
m_PowerUps {}
{

}

PowerUpManager::~PowerUpManager()
{
	for (size_t i{}; i < Size(); i++)
	{
		delete m_PowerUps[i];
		m_PowerUps[i] = nullptr;
	}
	m_PowerUps.clear();
}

void PowerUpManager::AddItem(Point2f centerPos, PowerUp::Type type)
{
	PowerUp* pAddedPowerUp{ };

	m_PowerUps.push_back(new PowerUp{ centerPos,type });
	//return pAddedPowerUp;
}


void PowerUpManager::AddItem(float centerX,float centerY, PowerUp::Type type)
{
	PowerUp* pAddedPowerUp{ new PowerUp{Point2f{centerX,centerY},type}};

	m_PowerUps.push_back(pAddedPowerUp);
	//return pAddedPowerUp;
}

void PowerUpManager::Draw() const
{
	for (size_t i{}; i < Size(); i++)
	{
		m_PowerUps[i]->Draw();
	}
}

void PowerUpManager::Update(float elapsedSec)
{
	for (size_t i{ 0 }; i < Size(); i++)
	{
		m_PowerUps[i]->Update(elapsedSec);
	}

}



size_t PowerUpManager::Size() const
{
	return m_PowerUps.size();
}

int PowerUpManager::IsHit(const Rectf& rect) 
{
	for (size_t i{ 0 }; i < Size(); i++)
	{
		if (m_PowerUps[i]->IsOverlapping(rect)) {
			return i;
		}
	}
	return -1;
}

void PowerUpManager::RemoveItem(int idx)
{
		if (idx > -1) {
			delete m_PowerUps[idx];
			m_PowerUps[idx] = m_PowerUps.back();
			m_PowerUps.pop_back();
		}
}
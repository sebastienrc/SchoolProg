#include "pch.h"
#include "Container.h"

#include "iostream"

// Sebastien Rojas Castillo - 1DAE15


Container::Container(int capacity):
	m_Capacity	{capacity}
,	m_Size		{0}
,	m_pDynArray	{new int[m_Capacity]}
{


}

Container::~Container() {
	delete[] m_pDynArray;
	m_pDynArray = nullptr;
	std::cout << "deleted array";
	
}

int Container::Size() const
{
	return m_Size;
}

int Container::Capacity() const
{
	return m_Capacity;
}

int Container::Get(int idx) const
{
	return m_pDynArray[idx];

}

void Container::Set(int idx, int newValue)
{
	m_pDynArray[idx] = newValue;
}


void Container::PushBack(int element)
{
	m_pDynArray[m_Size] = element;
	m_Size++;

	if (m_Size >= m_Capacity)
		Reserve((m_Size * 2) + 1);
}


void Container::Reserve(int newCapacity)
{
	int* pTempArray{ new int[newCapacity] };

	for (int i{ 0 }; i < m_Capacity; i++)
	{
		pTempArray[i] = m_pDynArray[i];
	}

	m_pDynArray = pTempArray;
	m_Capacity = newCapacity;
	pTempArray = nullptr;
}


#pragma once

// Sebastien Rojas Castillo - 1DAE15

class Container
{
public:
	Container(int capacity = 10);
	~Container();

	int Size() const;
	int Capacity() const;
	int Get(int idx) const;
	void Set(int idx, int newValue);
	void PushBack(int element);

private:
	int m_Size;
	int m_Capacity;
	int* m_pDynArray;
	
	
	void Reserve(int newCapacity);	



};


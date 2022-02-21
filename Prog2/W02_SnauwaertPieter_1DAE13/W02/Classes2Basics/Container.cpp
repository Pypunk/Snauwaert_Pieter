#include "pch.h"
#include "Container.h"

Container::Container(int capacity)
	:m_Capacity{capacity}
	, m_Size{}
{
	m_pElement = new int[m_Capacity];
}

Container::~Container()
{
	delete m_pElement;
	m_pElement = nullptr;
}

int Container::Size() const
{
	return m_Size;
}

int Container::Capacity() const
{
	return m_Capacity;
}

int Container::Get(int index) const
{
	return m_pElement[index];
}

void Container::Set(int index, int newValue)
{
	m_pElement[index] = newValue;
}

void Container::PushBack(int element)
{
	m_pElement[m_Size] = element;
	m_Size++;
	if (m_Size == m_Capacity)
	{
		int newCapacity{ m_Capacity * 2 + 1 };
		Reserve(newCapacity);
	}
}

void Container::Reserve(int newCapacity)
{
	if (newCapacity >= m_Capacity)
	{
		int* resized{ new int[newCapacity] };
		for (int i{}; i < m_Size; ++i)
		{
			resized[i] = m_pElement[i];
		}
		delete[] m_pElement;
		m_pElement = resized;
		m_Capacity = newCapacity;
	}
}

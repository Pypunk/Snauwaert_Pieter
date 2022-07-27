#include "pch.h"
#include "Health.h"

Health::Health( int value) 
	: m_Value{value}
{
}
int Health::GetValue( ) const
{
	return m_Value;
}

Health& Health::operator+=(int value)
{
	// // O: insert return statement here
	this->m_Value += value;
	return *this;
}

Health& Health::operator-=(int value)
{
	this->m_Value -= value;
	return *this;
}

Health operator+(int value, const Health& health)
{
	return Health(value + health.m_Value);
}

Health operator-(int value, const Health& health)
{
	return Health(value - health.m_Value);
}

Health operator+(const Health& health, int value)
{
	return Health(health.m_Value + value);
}

Health operator-(const Health& health, int value)
{
	return Health(health.m_Value - value);
}

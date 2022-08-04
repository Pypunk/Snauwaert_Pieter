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

Health& Health::operator+=(const int value)
{
	// // O: insert return statement here
	this->m_Value += value;
	return *this;
}

Health& Health::operator-=(const int value)
{
	this->m_Value -= value;
	return *this;
}

Health operator+(const int value, const Health& health)
{
	return Health(value + health.GetValue());
}

Health operator-(const int value, const Health& health)
{
	return Health(value - health.GetValue());
}

Health operator+(const Health& health, const int value)
{
	return Health(health.GetValue() + value);
}

Health operator-(const Health& health, const int value)
{
	return Health(health.GetValue() - value);
}

#pragma once

class Health final
{
public:
	Health( int value); 
	int GetValue( ) const;
	Health& operator+=(const int value);
	Health& operator-=(const int value);
private:
	int m_Value;
};
Health operator+(const int value, const Health& health);
Health operator-(const int value, const Health& health);
Health operator+(const Health& health, const int value);
Health operator-(const Health& health, const int value);

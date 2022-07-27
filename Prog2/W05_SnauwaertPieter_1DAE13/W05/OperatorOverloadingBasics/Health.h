#pragma once

class Health final
{
public:
	Health( int value); 
	int GetValue( ) const;
	Health& operator+=(int value);
	Health& operator-=(int value);
	friend Health operator+(int value, const Health& health);
	friend Health operator-(int value, const Health& health);
	friend Health operator+(const Health& health, int value);
	friend Health operator-(const Health& health, int value);
private:
	int m_Value;
};

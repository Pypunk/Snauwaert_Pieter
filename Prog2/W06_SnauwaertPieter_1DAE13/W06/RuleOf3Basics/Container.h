#pragma once

class Container final
{
public:
	Container( int capacity = 10); 
	~Container( );
	Container( const Container& other );
	Container& operator=( const Container& other );
	int& operator[](const int index);
	int operator[](const int index) const;

	int Size( ) const;
	int Capacity( ) const;
	int Get( int index ) const;
	void Set( int index, int value );
	void PushBack( int element );

private:
	int m_Size;
	int m_Capacity;
	int *m_pElement;

	void Reserve( int newCapacity );
};

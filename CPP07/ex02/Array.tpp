#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <iostream>

/*** constructor ***/
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

/*** parameterized constructor ***/
/*
**	Allocate memory for 'n' elements
*/
template <typename T>
Array<T>::Array( unsigned int n ) : _size(n)
{
	_elements = new T[_size];
}

/*** copy constructor ***/
template <typename T>
Array<T>::Array( const Array& other ) : _elements(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			this->_elements[i] = other._elements[i];
	}
}

/*** assignment operator ***/
template <typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
	if (this != &other)
	{
		delete[] _elements;
		_size = other._size;
		if (_size > 0)
		{
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				this->_elements[i] = other._elements[i];
		}
		else
			this->_elements = NULL;
	}
	return *this;
}

/*** destructor ***/
template <typename T>
Array<T>::~Array() { delete[] _elements; }

/*** getter ***/
template <typename T>
unsigned int	Array<T>::size( void ) const { return _size; }

/*** subscript operator override ***/
template <typename T>
T& Array<T>::operator[]( unsigned int index )
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _elements[index];
}

template <typename T>
const T& Array<T>::operator[]( unsigned int index ) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _elements[index];
}

#endif

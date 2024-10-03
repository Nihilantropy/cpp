#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
public:
	/*** constructor ***/
	Array();
	/*** parameterized constructor ***/
	Array( unsigned int n );
	/*** copy constructor ***/
	Array( const Array& other );
	/*** assignment operator ***/
	Array& operator=( const Array& other );
	/*** destructor ***/
	~Array();

	/*** getter ***/
	unsigned int	size( void ) const;

	/*** subscript operator override ***/
	T& operator[]( unsigned int index );
	const T& operator[]( unsigned int index ) const;


private:
	T*				_elements;
	unsigned int	_size;
};

/* Include the implementation file */
#include "Array.tpp"

#endif

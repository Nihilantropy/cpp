#include "Fixed.h"

/*** costructor ***/
Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default costructor called" << std::endl;
}

/*** copy costructor ***/
Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy costructor called" << std::endl;
	*this = other;
}

/*** assignment operator ***/
Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedValue = other.getRawBits();
	return *this;
}

/*** destructor ***/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*** getter method to extract the private data value ***/
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedValue;
}

/*** setter method to set the private data value ***/
void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedValue = raw;
}

#include "../include/Fixed.h"

// Default constructor to initialize the value at 0
Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor to make *this object a copy of other object
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// assignment operator to make this object data, euqals to other object data
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedValue = other._fixedValue;
	}
	return *this;
}

// getter method to extract the private data value
int		Fixed::getRawBits( void ) const { return _fixedValue; }

// setter method to set the private data value
void	Fixed::setRawBits( int const raw ) { _fixedValue = raw; }

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


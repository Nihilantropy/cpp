#include "../include/Fixed.h"

// Default constructor to initialize the value at 0
Fixed::Fixed() : _fixedValue(0) { std::cout << "Default constructor called" << std::endl; }

/*	Parameter Constructor int
		Takes const int as a parameter
		shift left with << to convert value into a fixed-point
*/ 
Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	_fixedValue = value << _fractValue;
}

/*	Parameter Constructor float
		that takes const float as a parameter
		Uses roundf to multiply for 256 and round up the value
*/ 
Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	_fixedValue = roundf(value * (1 << _fractValue));
}

// Copy constructor to make *this object a copy of other object
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Assignement operator to make this object data, euqals to other object data
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedValue = other.getRawBits();
	return *this;
}

// getter method to extract the private data value
int		Fixed::getRawBits( void ) const { return _fixedValue; }

// setter method to set the private data value
void	Fixed::setRawBits( int const raw ) { _fixedValue = raw; }

/*	toFloat;
		convert the fixed value into a float with a left shift
*/
float	Fixed::toFloat( void ) const { return ((float)_fixedValue / (1 << _fractValue)); }

/*	toInt;
		convert the fixed value into an int with a right shift
*/
int		Fixed::toInt( void ) const { return ((int)_fixedValue >> _fractValue); }

//	Insert (<<) operator overload
std::ostream&	operator<<( std::ostream& out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

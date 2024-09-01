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

/***  comparison operators ***/

bool	Fixed::operator>( const Fixed& other ) const { return (this->_fixedValue > other._fixedValue); }

bool	Fixed::operator>=( const Fixed& other ) const { return (this->_fixedValue >= other._fixedValue); }

bool	Fixed::operator<( const Fixed& other ) const { return (this->_fixedValue < other._fixedValue); }

bool	Fixed::operator<=( const Fixed& other ) const { return (this->_fixedValue <= other._fixedValue); }

bool	Fixed::operator==( const Fixed& other ) const { return (this->_fixedValue == other._fixedValue); }

bool	Fixed::operator!=( const Fixed& other ) const { return (this->_fixedValue != other._fixedValue); }

/*** arithmetic operators ***/

Fixed	Fixed::operator+( const Fixed& other ) const
{
	Fixed	result;

	result._fixedValue = this->_fixedValue + other._fixedValue;
	return result;
}

Fixed	Fixed::operator-( const Fixed& other ) const
{
	Fixed	result;

	result._fixedValue = this->_fixedValue - other._fixedValue;
	return result;
}

Fixed	Fixed::operator*( const Fixed& other ) const
{
	Fixed	result;

	result._fixedValue = (this->_fixedValue * other._fixedValue) >> _fractValue;
	return result;
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	Fixed	result;

	result._fixedValue = (this->_fixedValue << _fractValue) / other._fixedValue;
	return result;
}

/*** increment/decrement operators ***/

// pre-increment
Fixed&	Fixed::operator++( void )
{
	this->_fixedValue += 1;
	return *this;
}

// post-increment
Fixed	Fixed::operator++( int )
{
	Fixed	temp = *this;

	this->_fixedValue += 1;
	return temp;
}

// pre-decrement
Fixed&	Fixed::operator--( void )
{
	this->_fixedValue -= 1;
	return *this;
}

// post-decrement
Fixed	Fixed::operator--( int )
{
	Fixed	temp = *this;

	this->_fixedValue -= 1;
	return temp;
}

/*** min/max methods ***/

// return a non const reference to the min
Fixed&		Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

// return a const reference to the min
const Fixed&		Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

// return a non const reference to the max
Fixed&		Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

// return a const reference to the max
const Fixed&		Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

//	Insert (<<) operator overload
std::ostream&	operator<<( std::ostream& out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

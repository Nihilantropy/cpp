#include "Fixed.h"

/*** Default costructor to initialize the value at 0 ***/
Fixed::Fixed() : _fixedValue(0) { std::cout << "Default costructor called" << std::endl; }

/*	Parameter Costructor int
**	Takes const int as a parameter
**	shift left with << to convert value into a fixed-point
*/ 
Fixed::Fixed( const int value )
{
	std::cout << "Int costructor called" << std::endl;
	_fixedValue = value << _fractValue;
}

/*	Parameter Costructor float
**	that takes const float as a parameter
**	Uses roundf to multiply for 256 and round up the value
*/ 
Fixed::Fixed( const float value )
{
	std::cout << "Float costructor called" << std::endl;
	_fixedValue = roundf(value * (1 << _fractValue));
}

/*** Copy costructor to make *this object a copy of other object ***/
Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy costructor called" << std::endl;
	*this = other;
}

/*** assignment operator to make this object data, euqals to other object data ***/
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedValue = other.getRawBits();
	return *this;
}

/*** destructor ***/
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*** getter ***/
int		Fixed::getRawBits( void ) const
{
	return _fixedValue;
}

/*** setter ***/
void	Fixed::setRawBits( int const raw )
{
	_fixedValue = raw;
}

/*	toFloat:
**	convert the fixed value into a float with a left shift
*/
float	Fixed::toFloat( void ) const { return ((float)_fixedValue / (1 << _fractValue)); }

/*	toInt:
**	convert the fixed value into an int with a right shift
*/
int		Fixed::toInt( void ) const { return ((int)_fixedValue >> _fractValue); }

/*** '<<' operator overload ***/
std::ostream&	operator<<( std::ostream& out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return out;
}

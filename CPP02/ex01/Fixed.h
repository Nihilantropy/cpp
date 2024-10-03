#ifndef FIXED_H
#define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
public:
	/*** constructor ***/
	Fixed();
	/*** constructor with int parameter ***/
	Fixed( const int );
	/*** constructor with float parameter ***/
	Fixed( const float );
	/*** copy constructor ***/
	Fixed( const Fixed& other );
	/*** assignment operator ***/
	Fixed& operator=( const Fixed& other );
	/*** destructor ***/
	~Fixed();

	/*** getter ***/
	int		getRawBits( void ) const;
	/*** setter ***/
	void	setRawBits( int const raw );

	/*** public methods ***/
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_fixedValue;
	static const int	_fractValue = 8;
};

/*** '<<' operator overload ***/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

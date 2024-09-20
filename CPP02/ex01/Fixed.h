#ifndef FIXED_H
#define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
public:
	/*** costructor ***/
	Fixed();
	/*** costructor with int parameter ***/
	Fixed( const int );
	/*** costructor with float parameter ***/
	Fixed( const float );
	/*** copy costructor ***/
	Fixed(const Fixed&);
	/*** assignment operator ***/
	Fixed& operator=(const Fixed&);
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

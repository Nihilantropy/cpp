#ifndef FIXED_H
#define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed( const int );
	Fixed ( const float);
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_fixedValue;
	static const int	_fractValue = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

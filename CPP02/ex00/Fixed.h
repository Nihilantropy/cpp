#ifndef FIXED_H
#define FIXED_H

# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_fixedValue;
	static const int	_fractValue = 8;
};

#endif

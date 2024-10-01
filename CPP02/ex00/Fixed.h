#ifndef FIXED_H
#define FIXED_H

# include <iostream>

class Fixed
{
public:
	/*** costructor ***/
	Fixed();
	/*** copy costructor ***/
	Fixed( const Fixed& other );
	/*** assignment operator ***/
	Fixed& operator=( const Fixed& other );
	/*** destructor ***/
	~Fixed();

	/*** getter ***/
	int		getRawBits( void ) const;
	/*** setter ***/
	void			setRawBits( int const raw );

private:
	int					_fixedValue;
	static const int	_fractValue = 8;
};

#endif

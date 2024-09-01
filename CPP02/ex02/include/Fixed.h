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

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	bool	operator>( const Fixed& other ) const;
	bool	operator<( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;

	Fixed	operator+( const Fixed& other ) const;
	Fixed	operator-( const Fixed& other ) const;
	Fixed	operator*( const Fixed& other ) const;
	Fixed	operator/( const Fixed& other ) const;

	Fixed&	operator++( void );
	Fixed	operator++(int);
	Fixed&	operator--( void );
	Fixed	operator--(int);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);


private:
	int					_fixedValue;
	static const int	_fractValue = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

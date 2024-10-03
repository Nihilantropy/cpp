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
	Fixed( const Fixed& );
	/*** assignment operator ***/
	Fixed& operator=( const Fixed& );
	/*** destructor ***/
	~Fixed();

	/*** getter ***/
	int		getRawBits( void ) const;
	/*** setter ***/
	void	setRawBits( int const raw );

	/*** public methods ***/
	float	toFloat( void ) const;
	int		toInt( void ) const;

	/*** comparison operators ***/
	bool	operator>( const Fixed& other ) const;
	bool	operator<( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;

	/*** arithmetic operators ***/
	Fixed	operator+( const Fixed& other ) const;
	Fixed	operator-( const Fixed& other ) const;
	Fixed	operator*( const Fixed& other ) const;
	Fixed	operator/( const Fixed& other ) const;

	/*** increment/decrement operators ***/
	Fixed&	operator++( void );
	Fixed	operator++(int);
	Fixed&	operator--( void );
	Fixed	operator--(int);

	/*** min/max methods ***/
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);


private:
	int					_fixedValue;
	static const int	_fractValue = 8;
};

/*** '<<' operator overload ***/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
